using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class PlayerUnit : Unit
    {
        // Start is called before the first frame update
        protected override void Start()
        {
            base.Start();

            gameManager.Player = this;
        }

        protected override void CharacterControls()
        {
            KeyboardControls();
        }


        void KeyboardControls()
        {
            if (Input.GetKey(KeyCode.D))
            {
                if (!isAnimationDirectionLocked)
                {
                    direction = MoveDirection.right;

                    if (target == null)
                    {
                        //transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                    }
                }

                unitAnimator.SetBool("WalkBehind", true);

                isMoving = true;

                if (transform.localScale.x > 0)
                    movingForward = true;
                else
                    movingForward = false;
            }
            else if (Input.GetKey(KeyCode.A))
            {
                if (!isAnimationDirectionLocked)
                {
                    direction = MoveDirection.left;

                    if (target == null)
                    {
                        //transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                    }
                    else
                    {

                    }
                }

                unitAnimator.SetBool("Walk", true);

                isMoving = true;

                if (transform.localScale.x < 0)
                    movingForward = true;
                else
                    movingForward = false;
            }
            else
            {
                if (!isAnimationDirectionLocked) direction = MoveDirection.waiting;
                unitAnimator.SetBool("Walk", false);
                unitAnimator.SetBool("WalkBehind", false);

                isMoving = false;
            }
        }
    }
}