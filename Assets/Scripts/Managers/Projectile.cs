using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class Projectile : MonoBehaviour
    {
        public Action RangedAttack;
        public float speed;
        [HideInInspector] public int projectileDir;
        [HideInInspector] public string targetTag;
        // Start is called before the first frame update
        void Start()
        {
            
        }

        // Update is called once per frame
        void Update()
        {

        }
        void FixedUpdate()
        {
            transform.position = new Vector3(transform.position.x + ((int)projectileDir * speed) * Time.deltaTime, transform.position.y, transform.position.z);
        }

        void OnTriggerEnter2D(Collider2D collision)
        {
            if(collision != null)
            {
                // hits the target
                if (collision.gameObject.CompareTag(targetTag))
                {
                    RangedAttack.hitSoundEffect.PlayRandomSoundEffect();

                    collision.GetComponent<Unit>().TakeDamage(RangedAttack);
                    /*gameObject.transform.parent = collision.gameObject.transform;
                    GetComponent<BoxCollider2D>().enabled = false;
                    speed = 0;*/

                    Destroy(gameObject);
                }
            }
        }
    } 
}
