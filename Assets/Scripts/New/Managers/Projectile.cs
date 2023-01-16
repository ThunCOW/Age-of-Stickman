using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Projectile : MonoBehaviour
{
    [SerializeField] Rigidbody2D rb2d;
    [SerializeField] BoxCollider2D boxcol2d;
    private Unit parentUnit;

    [Space]
    public ProjectileType projectileType;
    public SoundScriptableObject RangedAttackSoundSO;
    
    public float projectileSpeed;
    private int projectileDir;

    List<string> targetTags;

    bool falling = false;

    [HideInInspector] public CloseCombatAnimation projectileAttack;
    [HideInInspector] public SpineAttachment projectileAttachment;

    // Start is called before the first frame update
    void Start()
    {
        parentUnit = transform.parent.GetComponent<Unit>();

        targetTags = Unit.CompareTags(parentUnit.gameObject, GameManager.ENEMY_TAGS) ? GameManager.ALLY_TAGS : GameManager.ENEMY_TAGS;
        
        transform.parent = null;
        
        projectileDir = parentUnit.transform.localScale.x > 0 ? 1 : -1;

        rb2d.velocity = new Vector3(projectileDir * projectileSpeed, 0, 0);
    }

    void Update()
    {
            
    }

    void FixedUpdate()
    {
        if (falling)
        {
            //float rot = Vector3.Angle(transform.position, rb2d.velocity);

            //rb2d.rotation = rot;

            float angle = Mathf.Atan2(rb2d.velocity.y, rb2d.velocity.x) * Mathf.Rad2Deg;
            
            transform.rotation = Quaternion.AngleAxis(angle + 90, Vector3.forward);
        }
    }

    public bool ProjectileDamage(Unit target, out bool isDestroyed)
    {
        float softDamage = Random.Range(0, parentUnit.Damage / 2) + Random.Range(0, parentUnit.Damage / 2);
        int damageDealt = (int)(softDamage * Random.Range(1, projectileAttack.DamageMultiplierMax));

        if (projectileAttack.DamageMultiplierMax == 0)
            Debug.LogError("DAMAGE MULTIPLIER OF ANIMATION IS NOT SET!");

        if (projectileType == ProjectileType.Arrow)
        {
            isDestroyed = true;
            return target.unitController.TakeDamage(projectileAttack, damageDealt, parentUnit, projectileDir, true);
        }
        else if(projectileType == ProjectileType.Spear)
        {
            if (target.unitController.isBoss)
            {
                isDestroyed = true;
                return target.unitController.TakeDamage(projectileAttack, target.HealthMax / Random.Range(5, 8), parentUnit, projectileDir, false, projectileAttachment);
            }
            else
            {
                int spearSwordLevelDif = GameManager.Instance.SwordUpgradeLevel - GameManager.Instance.SpearUpgradeLevel;
                if (spearSwordLevelDif > 0)
                {
                    // i can make spear bounce and shake and fall but whatever. (isDestroyed was for it)
                }
                isDestroyed = true;
                return target.unitController.TakeDamage(projectileAttack, target.HealthMax, parentUnit, projectileDir, false, projectileAttachment);
            }
        }
        else
        {
            isDestroyed = true;
            return target.unitController.TakeDamage(projectileAttack, damageDealt, parentUnit, projectileDir, false, projectileAttachment);
        }
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision != null)
        {
            // hits the target
            if (Unit.CompareTags(collision.gameObject, targetTags))
            {

                Unit enemyUnit = collision.GetComponent<Unit>();

                bool isDestroyed;
                if(ProjectileDamage(enemyUnit, out isDestroyed))
                {
                    boxcol2d.enabled = false;
                    // Hit connected, can delete the arrow
                    if(isDestroyed)
                    {
                        Destroy(gameObject);
                    }
                    else
                    {
                        // spear not destroyed, its gonna fall
                    }
                    return;
                }

                if (projectileType == ProjectileType.ShortSpear)
                {
                    SpearRicoche();
                    //Destroy(gameObject);
                }
                else
                {
                    falling = true;
                    ArrowRicoche();
                }
            }
            if(collision.gameObject.layer == 8)         // 8 = Ground layer
            {
                if (projectileType == ProjectileType.Arrow)
                    StartCoroutine(ArrowFall());
                else
                {
                    falling = false;

                    rb2d.bodyType = RigidbodyType2D.Static;
                }
            }
        }
    }

    private void ArrowRicoche()
    {
        gameObject.layer = 6;                                       // I set it to blood's layer here

        projectileSpeed = 0;

        rb2d.velocity = Vector2.zero;
        rb2d.bodyType = RigidbodyType2D.Dynamic;

        float degree;
        if (projectileDir == 1)
            degree = Random.Range(15, 60);
        else
            degree = 180 - Random.Range(15, 60);

        float degreeToRad = degree * Mathf.Deg2Rad;
        Vector2 radToVec2 = new Vector2(Mathf.Cos(degreeToRad), Mathf.Sin(degreeToRad));

        rb2d.AddForce(radToVec2 * Random.Range(300, 500));
    }

    private void SpearRicoche()
    {
        gameObject.layer = 6;

        projectileSpeed = 0;

        rb2d.velocity = Vector2.zero;
        rb2d.bodyType = RigidbodyType2D.Dynamic;
    }

    private void SpearBlock()
    {

    }

    IEnumerator ArrowFall()
    {
        transform.GetChild(1).gameObject.SetActive(false);

        yield return new WaitForSeconds(Random.Range(0, 0.15f));

        falling = false;

        rb2d.bodyType = RigidbodyType2D.Static;

        //rb2d.velocity = Vector2.zero;
    }

}
public enum ProjectileType
{
    Arrow,
    Spear,
    ShortSpear,
}
