using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Character : MonoBehaviour
{
    [Header("Character Animation")]
    [SerializeField] private Animator bodyAnimator = null;
    [SerializeField] private Animator legAnimator = null;
    
    [Space]
    public bool isAttackAnimPlaying;
    
    // Start is called before the first frame update
    void Start()
    {

    }

    [Header("Character Movement")]
    bool isMoving;
    public float speed;
    private Vector3 direction;
    // Update is called once per frame
    void Update()
    {
        KeyboardControls();

        transform.Translate(direction * speed * Time.deltaTime);
    }

    void KeyboardControls()
    {
        if(Input.GetKey(KeyCode.D))
        {
            direction = new Vector3(1, 0, 0);
            transform.localScale = new Vector3(0.5f, 0.5f, 1);
            bodyAnimator.SetBool("Walking", true);
            legAnimator.SetBool("Walking", true);
            
            isMoving = true;
        }
        else if(Input.GetKey(KeyCode.A))
        {
            direction = new Vector3(-1, 0, 0);
            transform.localScale = new Vector3(-0.5f, 0.5f, 1);
            bodyAnimator.SetBool("Walking", true);
            legAnimator.SetBool("Walking", true);

            isMoving = true;
        }
        else
        {
            direction = Vector3.zero;
            bodyAnimator.SetBool("Walking", false);
            legAnimator.SetBool("Walking", false);

            isMoving = false;
        }

        if(Input.GetKeyDown("space") && !isAttackAnimPlaying)
        {
            isAttackAnimPlaying = true;
            if(isMoving)
            {
                int randNumber = Random.Range(1, 3);

                if(randNumber == 1)
                {
                    bodyAnimator.SetTrigger("Attack_" + 1);
                    legAnimator.SetTrigger("Attack_" + 1);
                }
                if(randNumber == 2)
                {
                    bodyAnimator.SetTrigger("Attack_" + 4);
                    legAnimator.SetTrigger("Attack_" + 4);
                }
            }
            else
            {
                int randNumber = Random.Range(1, 3);

                if(randNumber == 1)
                {
                    bodyAnimator.SetTrigger("Attack_" + 2);
                    legAnimator.SetTrigger("Attack_" + 2);
                }
                if(randNumber == 2)
                {
                    bodyAnimator.SetTrigger("Attack_" + 3);
                    legAnimator.SetTrigger("Attack_" + 3);
                }
            }
        }
        /*if(Input.GetKeyDown("space"))
        {
            bodyAnimator.SetTrigger("Attack_0");
        }
        if(Input.GetKeyDown("a"))
        {
            legAnimator.SetBool("Walking", true);
            tempMoveBool = true;
            speed = -1 * speed;
            transform.localScale = new Vector3(-0.5f, 0.5f, 1);
        }
        if(Input.GetKeyDown("d"))
        {
            legAnimator.SetBool("Walking", true);
            tempMoveBool = true;
            speed = Mathf.Abs(speed);
            transform.localScale = new Vector3(0.5f, 0.5f, 1);
        }
        if(Input.GetKeyUp("a") || Input.GetKeyUp("d"))
        {
            Debug.Log("shouldnt enter");
            legAnimator.SetBool("Walking", false);
            tempMoveBool = false;
            speed = Mathf.Abs(speed);
        }

        if(tempMoveBool)
        {
            Vector3 xVec = new Vector3(1, 0, 0);
            transform.Translate(xVec * speed * Time.deltaTime);
        }*/
    }
}
