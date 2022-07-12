using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum DeathType{
    Body1,
    Body2,
    Head1,
    Head2,
    SpearThrow1,
    SpearThrow2
}

public class TempChar : MonoBehaviour
{
    [Header("Character Stats")]
    [SerializeField] protected int MaxHealth;
    [SerializeField] protected int Health;
    [SerializeField] protected int Damage;
    [SerializeField] protected float PushDistance;

    [Header("Character Animation")]
    public Animator charAnimator = null;
    
    // Start is called before the first frame update
    protected virtual void Start()
    {
        canMove = true;
        Health = MaxHealth;
    }

    [Header("Character Movement")]
    protected bool isMoving;
    [HideInInspector] public bool isAnimationDirectionLocked = false;
    [HideInInspector] public bool lockMovement = false;
    [HideInInspector] public bool canMove = false;
    public float speed;
    [HideInInspector] public float multiplier = 1;
    [HideInInspector] public int direction = 0;
    // Update is called once per frame
    void Update()
    {
        if(Health > 0)
        {
            if(_stunned)
            {
                Pushed();
            }
            else
            {
                DetectClosestEnemy();

                //if(!lockMovement)
                    MovementControls();
                
                WeaponControls();

                //if(canMove)
                //    transform.Translate(Vector3.right * direction * speed * multiplier * Time.deltaTime);
            }
        }
    }

    void FixedUpdate()
    {
        if(canMove)
            transform.position = new Vector3(transform.position.x + (direction * speed * multiplier) * Time.deltaTime, transform.position.y, transform.position.z);
    } 

    protected bool movingForward;
    private void MovementControls()
    {
        if(Input.GetKey(KeyCode.D))
        {
            if(!isAnimationDirectionLocked) 
            {
                direction = 1;

                if(target == null)
                {
                    //transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                }
            }

            charAnimator.SetBool("Walking", true);
            
            isMoving = true;

            if(transform.localScale.x > 0)
                movingForward = true;
            else
                movingForward = false;
        }
        else if(Input.GetKey(KeyCode.A))
        {
            if(!isAnimationDirectionLocked)
            {
                direction = -1;

                if(target == null)
                {
                    //transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                }
                else
                {

                }
            }

            charAnimator.SetBool("Walking", true);

            isMoving = true;

            if(transform.localScale.x < 0)
                movingForward = true;
            else
                movingForward = false;
        }
        else
        {
            if(!isAnimationDirectionLocked) direction = 0;
            charAnimator.SetBool("Walking", false);

            isMoving = false;
        }
    }

    protected DeathType damageType = DeathType.Body1;
    void WeaponControls()
    {
        if(Input.GetKey(KeyCode.T))
        {
            charAnimator.SetTrigger("Swap");
        }
        if(Input.GetKey(KeyCode.O))
        {
            charAnimator.SetTrigger("Throw");
            damageType = DeathType.SpearThrow1;
        }

        if(Input.GetKeyDown("space"))
        {
            //isAttackAnimPlaying = true;
            if(isMoving && movingForward)
            {
                int randNumber = Random.Range(1, 3);

                if(randNumber == 1)
                {
                    charAnimator.SetTrigger("Walk_Attack_" + 1);
                    damageType = DeathType.Head1;
                }
                if(randNumber == 2)
                {
                    charAnimator.SetTrigger("Walk_Attack_" + 2);
                    damageType = DeathType.Head1;
                }
            }
            else
            {
                int randNumber = Random.Range(1, 3);

                if(randNumber == 1)
                {
                    charAnimator.SetTrigger("Idle_Attack_" + 1);
                    damageType = DeathType.Body1;
                }
                if(randNumber == 2)
                {
                    charAnimator.SetTrigger("Idle_Attack_" + 2);
                    damageType = DeathType.Body2;
                }
            }
        }
    }

    protected float oldPosX;
    protected void TakeDamage(int damage, DeathType deathType)
    {
        Health -= damage;
        if(Health <= 0)
        {
            GetComponent<BoxCollider2D>().enabled = false;
            if(deathType == DeathType.Body1)
            {
                charAnimator.SetTrigger("Death_Body1");
            }
            else if(deathType == DeathType.Body2)
            {
                charAnimator.SetTrigger("Death_Body2");
            }
            else if(deathType == DeathType.Head1)
            {
                charAnimator.SetTrigger("Death_Head1");
            }
            else if(deathType == DeathType.SpearThrow1)
            {
                charAnimator.SetTrigger("Death_SpearThrow1");
            }
        }
        else
        {
            charAnimator.SetTrigger("Hurt_1");
        }
    }

    protected bool _stunned;
    public virtual bool stunned{
        set
        {
            _stunned = value;
            oldPosX = transform.position.x;
            
            if(_stunned == true)
            {
                int dir = 1;
                if(transform.localScale.x > 0)
                    dir = -1;
                
                transform.position = new Vector2(transform.position.x + PushDistance * dir, transform.position.y);
            }
        }
        get{return _stunned;}
    }

    protected void Pushed()
    {
        /*
        + attacker - defender
        - +
        sola gidicek 
        direction pozitif 
        push distance negatif olur
        oldPosX sola kayar
        Abs oldPosX transformdan X pozitifken küçük, X negatifken büyük olur, büyük küçük bakamayız
        Normal karşılaştırmada transform her zaman küçülür, oldPosX + pushDis den küçük olunca true olure

        + -
        direction negatif
        push distance pozitif
        oldPosX sağa kayar
        Normal karşılaştırmada transform büyür, geçünce true olur
        >>>Eğer direction ile çarparsak direction burda negatif olduğundan sağlar

        */
        /*int dir = 1;
        if(transform.localScale.x < 0)
            dir = -1;

        //Debug.Log(transform.position.x * dir + " checlk " + dir * oldPosX + (PushDistance * -dir) + " OLDPOSX = " + oldPosX + " PUISHDIS = " + PushDistance);
        
        if(transform.position.x * dir >= dir * (oldPosX + (PushDistance * -dir)))
        {
            Debug.Log("enters now");
            //transform.Translate(Vector3.right * -dir * 100 * multiplier * Time.deltaTime);
        }*/
    }

    [SerializeField] protected bool vers1;
    [SerializeField] protected GameObject slashParticle = null;
    [SerializeField] protected GameObject[] bloodSplash = null;
    public void DealDamage()
    {
        if(target != null)
        {
            if(vers1)
            {
                Vector2 pos = new Vector2(target.transform.position.x, target.transform.position.y - 0.1f);
                GameObject spawned = Instantiate(slashParticle, pos, slashParticle.transform.rotation) as GameObject;
                
                if(transform.position.x > target.transform.position.x)
                    spawned.transform.localScale = new Vector3(-1, 1, 1);

            }
            else{
                int x = Random.Range(1, 11);
                if(x > 3)
                {
                    Vector2 pos = new Vector2(target.transform.position.x, target.transform.position.y - 0.1f);
                    GameObject spawned = Instantiate(slashParticle, pos, slashParticle.transform.rotation) as GameObject;
                    
                    if(transform.position.x > target.transform.position.x)
                        spawned.transform.localScale = new Vector3(-1, 1, 1);

                    StartCoroutine(gravityZero(spawned));
                }
                else
                {
                    Vector2 pos = new Vector2(target.transform.position.x, target.transform.position.y - 0.1f);
                    GameObject spawned = Instantiate(bloodSplash[x - 1], pos, bloodSplash[x - 1].transform.rotation) as GameObject;

                    if(transform.position.x > target.transform.position.x)
                        spawned.transform.localScale = new Vector3(-1, 1, 1);
                }
            }
            target.GetComponent<TempChar>().TakeDamage(Damage, damageType);
        }
    }
    
    protected IEnumerator gravityZero(GameObject spawned)
    {
        yield return new WaitForSeconds(0.25f);
        spawned.GetComponent<ParticleSystem>().gravityModifier = 0;
    }

    [Header("Enemy Information")]
    [SerializeField] protected GameObject target = null;
    protected float detectResetTime = 0.15f;
    protected float detectReset = 0.15f;
    [SerializeField] protected LayerMask targetLayer;
    protected void DetectClosestEnemy()
    {
        detectReset -= Time.deltaTime;
        if(detectReset <= 0)
        {
            Vector2 boxScale = new Vector2(16, transform.localScale.y);
            Collider2D[] hitColliders = Physics2D.OverlapBoxAll(transform.position, boxScale, transform.rotation.eulerAngles.z, targetLayer);
            float closestX = 5000;
            Vector3 curPos = transform.position;
            
            if(hitColliders.Length == 0)
                target = null;
            for (int i = 0; i < hitColliders.Length; i++)
            {
                if (closestX > Mathf.Abs(transform.position.x - hitColliders[i].transform.position.x))
                {
                    target = hitColliders[i].transform.gameObject;
                    closestX = Mathf.Abs(transform.position.x - hitColliders[i].transform.position.x);
                }
            }

            if(target == null)
            {
                transform.localScale = new Vector3(1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
            }
            else
            {
                if(transform.position.x < target.transform.position.x)
                {
                    transform.localScale = new Vector3(1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                }
                else
                {
                    transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                }
            }
            detectReset = detectResetTime;
        }
    }
}
