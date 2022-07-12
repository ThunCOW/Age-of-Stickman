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
            gameManager.PlayerUnits.Add(this);
        }

        private void FixedUpdate()
        {
            if (canMove)
                transform.position = new Vector3(transform.position.x + ((int)direction * speed * multiplier) * Time.deltaTime, transform.position.y, transform.position.z);
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
                    direction = Directions.right;

                    if (target == null)
                    {
                        //transform.localScale = new Vector3(Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                    }
                }

                charAnimator.SetBool("WalkBehind", true);

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
                    direction = Directions.left;

                    if (target == null)
                    {
                        //transform.localScale = new Vector3(-1 * Mathf.Abs(transform.localScale.x), transform.localScale.y, 1);
                    }
                    else
                    {

                    }
                }

                charAnimator.SetBool("Walk", true);

                isMoving = true;

                if (transform.localScale.x < 0)
                    movingForward = true;
                else
                    movingForward = false;
            }
            else
            {
                if (!isAnimationDirectionLocked) direction = 0;
                charAnimator.SetBool("Walk", false);
                charAnimator.SetBool("WalkBehind", false);

                isMoving = false;
            }
        }
    }
}