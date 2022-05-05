using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TempEnemy : TempChar
{
    [HideInInspector] public GameObject Player;

    private void OnValidate()
    {
        AnimationClip[] animationClipList = charAnimator.runtimeAnimatorController.animationClips;

        if(randomTestA)
        {
            RandomGen rg = new RandomGen();
            rg.RandomGenTestA();
            randomTestA = false;
        }
    }
    
    protected override void Start()
    {
        base.Start();

        if(transform.position.x > Player.transform.position.x)
        {
            direction = -1;
            transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
        }
        else
        {
            direction = 1;
            transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
        }
        Vector3 worldToScreen = Camera.main.ScreenToWorldPoint(new Vector3(Screen.width, 0, 0));
        worldToScreen -= Camera.main.ScreenToWorldPoint(new Vector3(0, 0, 0));

        // Player's distance to borders of the screen
        playerDistance = worldToScreen.x / 2;
        float temp = Random.Range(1, 2.5f);
        playerDistance -= temp;
    }

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
                if(target == null) target = Player;
                
                if(transform.position.x > Player.transform.position.x)
                {
                    transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                    
                    if(ai_move)
                        direction = -1;
                }
                else
                {
                    transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                    
                    if(ai_move)
                        direction = 1;
                }

                AIControls();
            }

            AggressivenessControl();
        }

        
    }

    public override bool stunned{
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

                AggressivenessControl();
                nextDecision = 0;
                ai_attack = false;
                ai_move = false;
            }
        }
        get{return _stunned;}
    }

    /*
        AI bools
    */
    [Header("AI BOOLS")]
    [SerializeField] bool ai_inScreen = false;
    [SerializeField] bool ai_isOutOfRange = true;
    [SerializeField] bool ai_move = false;
    [SerializeField] bool ai_attack = false;
    public bool ai_isAttacking = false;
    [SerializeField] int ai_attackRepeat;

    void AIControls()
    {
        if(ai_inScreen)
        {
            ai_isOutOfRange = !IsInPlayerRange(playerDistance, Color.red);
            if(ai_isOutOfRange)
            {
                // Player's distance to borders of the screen
                nextDecision = 1.5f;
            }
        }

        //if(!lockMovement)
            if(ai_isOutOfRange)
            {
                if(IsInPlayerRange(playerDistance, Color.red))
                {
                    direction = 0;
                    
                    charAnimator.SetBool("Walking", false);
                    ai_inScreen = true;
                    ai_move = false;
                }
                else
                {
                    charAnimator.SetBool("Walking", true);
                    
                    ai_inScreen = false;
                    ai_move = true;
                }
            }

        if(ai_inScreen)
        {
            if(!ai_move && !ai_attack)
                AIDecision();

            if(ai_move && !ai_attack)
            {
                if(IsInPlayerRange(distanceToPlayer, Color.blue, 0.3f))
                {
                    direction = 0;

                    charAnimator.SetBool("Walking", false);
                    ai_move = false;
                }
                else
                {
                    charAnimator.SetBool("Walking", true);
                }
            }
            
            if(ai_attack && !ai_isAttacking && !ai_move)
            {
                int randNumber = Random.Range(0, 2);

                if(IsInPlayerRange(offensiveSkills[randNumber].ReachDistance, Color.green, 0.5f))
                {
                    charAnimator.SetTrigger(offensiveSkills[randNumber].SkillName);
                    damageType = DeathType.Body1;
                }
                else
                {
                    // we can make it move here
                }
                
                ai_attackRepeat--;
                if(ai_attackRepeat == 0)
                    ai_attack = false;
            }

            if(ai_attack && ai_move)
            {
                Debug.Log("ikiside doğru");
            }
        }
    }

    /*void Movement()
    {
        if(IsInPlayerRange(initialDistanceToPlayer))
        {
            //direction = 0;
            
            //charAnimator.SetBool("Walking", false);
            inScreen = true;
        }
        else
        {
            charAnimator.SetBool("Walking", true);
            
            inScreen = false;
        }
    }*/

    

    [SerializeField] private float nextDecision;
    [SerializeField] private float maxWaitForDecision;
    [SerializeField] private float aggressivenessByDistance;
    [SerializeField] private float aggressivenessByHealth;
    [SerializeField] private float aggressivenessByDefault;
    [SerializeField] private float aggressiveness;
    
    private float distanceToPlayer;
    private void AIDecision()
    {
        bool isInAttackRange = IsInPlayerRange(2, Color.green, 0.5f);

        int randNumber = -1;
        
        nextDecision -= Time.deltaTime;
        if(nextDecision <= 0f) 
        {
            if(isInAttackRange)
            {
                if(aggressiveness < 10)
                {
                    randNumber = 0;
                }
                else if(aggressiveness >= 10 && aggressiveness < 20)
                {
                    randNumber = 5;
                    /*int randomPercentage = Random.Range(0, 100);
                    if(randomPercentage >= 80)
                        randNumber = 25;*/
                }
                else if(aggressiveness >= 20)
                {
                    randNumber = 5;
                }
                
                for(int i = 0; i < 2; i++)
                {
                    randNumber += Random.Range(10, ((30 / 2) + 1));
                }
                if(randNumber >= 30 - 1)
                        randNumber = 30 - 1;
            }
            else
            {
                if(aggressiveness < 10)
                {
                    randNumber = 0;
                }
                else if(aggressiveness >= 10 && aggressiveness < 20)
                {
                    randNumber = 5;
                }
                else if(aggressiveness >= 20 && aggressiveness < 30)
                {
                    randNumber = 5;
                }
                else if(aggressiveness >= 30)
                {
                    
                }
                
                for(int i = 0; i < 2; i++)
                {
                    randNumber += Random.Range(0, ((20 / 2) + 1));
                }
                if(randNumber >= 20 - 1)
                        randNumber = 20 - 1;

            }

            if(aggressiveness < 5)
            {
                nextDecision = Random.Range(0, maxWaitForDecision);
            }
            else if(aggressiveness >= 5 && aggressiveness < 10)
            {
                nextDecision = Random.Range(0, maxWaitForDecision / 2);
                nextDecision += Random.Range(0, maxWaitForDecision / 2);
            }
            else if(aggressiveness >= 10 && aggressiveness < 20)
            {
                nextDecision = -1;
                nextDecision += Random.Range(0, maxWaitForDecision / 3);
                nextDecision += Random.Range(0, maxWaitForDecision / 3);
                nextDecision += Random.Range(0, maxWaitForDecision / 3);

            }
            else if(aggressiveness >= 20)
            {
                nextDecision = 0;
            }
        }

        
        // wait
        if(randNumber >= 10 && randNumber < 20)
        {
            direction = 0;

            ai_move = false;
            charAnimator.SetBool("Walking", false);
        }
        // move closer
        else if(randNumber >= 0 && randNumber < 10)
        {
            if(!IsInPlayerRange(2, Color.blue, 0.1f))
            {
                distanceToPlayer = Vector3.Distance(transform.position, Player.transform.position);
                ai_move = true;
                
                float moveRandDistance = 0;
                moveRandDistance += Random.Range(0, distanceToPlayer / 2);
                moveRandDistance += Random.Range(0, distanceToPlayer / 2);

                distanceToPlayer -= moveRandDistance;
            }
            else
            {
                direction = 0;

                ai_move = false;
                charAnimator.SetBool("Walking", false);
            }
        }
        // attack
        else if(randNumber >= 20)
        {
            ai_attack = true;
            ai_attackRepeat = Random.Range(1, 3);
        }
    }

    float aggressivenessCheck = 0.3f;
    void AggressivenessControl()
    {
        aggressivenessCheck -= Time.deltaTime;
        if(aggressivenessCheck <= 0)
        {
            aggressiveness = 0;
            
            float tempDist = Vector3.Distance(transform.position, Player.transform.position);
            //Debug.Log(playerDistance + " " + tempDist);
            aggressivenessByDistance = (playerDistance - tempDist) * 10 / (playerDistance - 3);

            aggressivenessByHealth = (MaxHealth - Health + 0.1f) * 10 / MaxHealth;

            aggressiveness += aggressivenessByDefault;
            aggressiveness += aggressivenessByDistance;
            aggressiveness += aggressivenessByHealth;

            aggressivenessCheck = 0.3f;
        }
    }

    private float playerDistance;
    private bool IsInPlayerRange(float distance, Color color, float inc = 0)
    {
        int dir = 1;
        if(transform.localScale.x < 0)
            dir = -1;
        Vector3 start = new Vector3(transform.position.x, transform.position.y + inc, transform.position.z);
        Debug.DrawRay(start, Vector3.right * dir * (distance), color);
        
        if(Vector3.Distance(transform.position, target.transform.position) <= distance)
            return true;
        else
            return false;

        /*
        RaycastHit2D raycastHit = Physics2D.Raycast(transform.position, Vector3.right * dir, distance, 1 << LayerMask.NameToLayer("Player"));

        if (raycastHit.collider != null)
        {
            return true;
        }
        else
            return false;*/
    }

    [Header("Offensive Attacks")]
    public List<Skill> offensiveSkills = new List<Skill>();

    public bool randomTestA;
}

[System.Serializable]
public class Skill
{
    public string SkillName;
    public float Probability;
    public float ReachDistance;

    /*[HideInInspector]
    public int listIndx = 0;
    [HideInInspector]
    public List<AnimationClip> AnimationList = new List<AnimationClip>();
    [HideInInspector]
    private string[] animList2 = new string[] {"waera", "arwe", "dsgfsd"};*/
    //private enum test{};

    void OnValidate()
    {
        
    }
}

public static class GaussDist
{
    static float pi = 3.14f;
    static float e = 2.718f;

    public static float GaussRandom(float x, float mean, float standartDeviation)
    {
        float a = 1 / Mathf.Sqrt(2 * pi * Mathf.Pow(standartDeviation, 2));
        float b = a * Mathf.Pow(e, - ( (Mathf.Pow(x - mean, 2) / (2 * Mathf.Pow(standartDeviation, 2))) ));
        return b;
    }
}

public class RandomGen
{
    public void RandomGenTestA()
    {
        int actionAmount = 2;
        int totalAction = (actionAmount * 10);
        float[] randDmg = new float[totalAction];
        int turn = 2;
        int cycle = 5000;
        
        for(int a = 0; a < cycle; a++)
        {
            int damage = 5;
            for(int i = 0; i < turn; i++)
            {
                damage += Random.Range(0, ((totalAction / turn) + 1));
            }
            if(damage >= totalAction - 1)
                    damage = totalAction - 1;
            randDmg[damage]++;
        }
        
        float[] choice = new float[2];
        for(int x = 0; x < totalAction; x++)
        {
            float p = randDmg[x] * 100 / cycle;
            if(x < 10)
            {
                choice[0] += p;
            }
            else if(x >= 10 && x < 20)
            {
                choice[1] += p;
            }
            /*else if(x >= 20 && x < 30)
            {
                choice[2] += p;
            }*/
            
            //Debug.Log(x + " prob = " + p);
        }
        for(int x = 0; x < 2; x++)
        {
            Debug.Log("choice " + x + " prob = " + choice[x]);
        }
    }

    public void RandomGenTestB()
    {
        int aggressiveness = 10;

        int[] choice = new int[10];

        int cycle = 5000;
        
        float maxWaitForDecision = 5;
        float nextDecision = 0;
        for(int a = 0; a < cycle; a++)
        {
            
            if(aggressiveness >= 0 && aggressiveness < 5)
            {
                nextDecision = Random.Range(0, maxWaitForDecision);
            }
            else if(aggressiveness >= 5 && aggressiveness < 10)
            {
                nextDecision = Random.Range(0, maxWaitForDecision / 2);
                nextDecision += Random.Range(0, maxWaitForDecision / 2);
            }
            else if(aggressiveness >= 10 && aggressiveness < 20)
            {
                nextDecision = -1;
                nextDecision += Random.Range(0, maxWaitForDecision / 3);
                nextDecision += Random.Range(0, maxWaitForDecision / 3);
                nextDecision += Random.Range(0, maxWaitForDecision / 3);
            }
            else if(aggressiveness >= 20)
            {
                
            }

            /*
            nextDecision = x
            nextDecision -=
            nextDecision +=

            ile

            nextDecision +=
            nextDecision +=

            aynı oranda doğru
            */

            for(int i = 0; i < 10; i++)
            {
                if(nextDecision > i && nextDecision <= i + 1)
                    choice[i]++;
            }
        }

        for(int x = 0; x < 10; x++)
        {
            choice[x] = choice[x] * 100 / cycle;
            Debug.Log(x + " prob = %" + choice[x]);
        }
    }
}