using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Projectile : MonoBehaviour
{
    private Unit parentUnit;

    public SoundScriptableObject RangedAttackSoundSO;
    
    public float projectileSpeed;
    private int projectileDir;

    List<string> targetTags;

    // Start is called before the first frame update
    void Start()
    {
        parentUnit = transform.parent.GetComponent<Unit>();

        targetTags = Unit.CompareTags(parentUnit.gameObject, GameManager.ENEMY_TAGS) ? GameManager.ALLY_TAGS : GameManager.ENEMY_TAGS;
        
        transform.parent = null;
        
        projectileDir = parentUnit.transform.localScale.x > 0 ? 1 : -1;

    }

    void FixedUpdate()
    {
        transform.position = new Vector3(transform.position.x + ((int)projectileDir * projectileSpeed) * Time.deltaTime, transform.position.y, transform.position.z);
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision != null)
        {
            // hits the target
            if (Unit.CompareTags(collision.gameObject, targetTags))
            {
                //RangedAttackSoundSO.hitSoundEffect.PlayRandomSoundEffect();
                
                parentUnit.unitController.ProjectileDamage();

                //collision.GetComponent<Unit_Old>().TakeDamage(RangedAttack);
                /*gameObject.transform.parent = collision.gameObject.transform;
                GetComponent<BoxCollider2D>().enabled = false;
                speed = 0;*/

                Destroy(gameObject);
            }
        }
    }
}
