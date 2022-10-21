using SpineControllerVersion;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Projectile : MonoBehaviour
{
    private Unit parentUnit;
    private Transform target;

    public SoundScriptableObject RangedAttackSoundSO;
    
    public float projectileSpeed;
    private int projectileDir;

    private string targetTag;

    // Start is called before the first frame update
    void Start()
    {
        parentUnit = transform.parent.GetComponent<Unit>();

        if (parentUnit.gameObject.CompareTag(GameManager.Instance.ENEMY_TAG))
            targetTag = GameManager.Instance.PLAYER_TAG;
        else
            targetTag = GameManager.Instance.ENEMY_TAG;

        target = parentUnit.target.gameObject.transform;

        transform.parent = null;
        
        projectileDir = parentUnit.transform.position.x - target.transform.position.x < 0 ? 1 : -1;
        projectileDir = parentUnit.transform.localScale.x > 0 ? 1 : -1;

    }

    void FixedUpdate()
    {
        transform.position = new Vector3(transform.position.x + ((int)projectileDir * projectileSpeed) * Time.deltaTime, transform.position.y, transform.position.z);
    }

    void OnTriggerEnter2D(Collider2D collision)
    {
        Debug.Log("works");
        if (collision != null)
        {
            // hits the target
            if (collision.gameObject.CompareTag(targetTag))
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