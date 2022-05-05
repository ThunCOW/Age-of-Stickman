using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimationEvents : MonoBehaviour
{
    private TempChar character;
    private bool isAI;

    // Start is called before the first frame update
    void Start()
    {
        try
        {
            character = GetComponentInParent<TempChar>();
            if(character is TempEnemy)
                isAI = true;
        }
        catch{}
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void Attack()
    {
        character.DealDamage();
    }

    void Stunned()
    {
        character.stunned = true;
        character.canMove = false;
    }

    void UnStunned()
    {
        character.stunned = false;
        character.canMove = true;

        if(isAI)
        {
            TempEnemy t = character as TempEnemy;
            t.ai_isAttacking = false;
        }
    }

    void LockMovement()
    {
        character.lockMovement = true;
        LockDirection();
    }
    void UnlockMovement()
    {
        character.lockMovement = false;
        UnlockDirection();
    }

    // Locks movement during animation
    void StopMovement()
    {
        character.canMove = false;
        LockDirection();
        
        if(isAI)
        {
            TempEnemy t = character as TempEnemy;
            t.ai_isAttacking = true;
        }
    }
    void StartMovement()
    {
        character.canMove = true;
        UnlockDirection();
        
        if(isAI)
        {
            TempEnemy t = character as TempEnemy;
            t.ai_isAttacking = false;
        }
    }

    // Resets throw trigger manually
    void ResetThrowTrigger()
    {
        character.charAnimator.ResetTrigger("Throw");
    }

    // Resets swap trigger manually
    void ResetSwapTrigger()
    {
        character.charAnimator.ResetTrigger("Swap");
        ResetAttackTrigger();
    }

    // Resets attack triggers manually
    void ResetAttackTrigger()
    {
        character.charAnimator.ResetTrigger("afsdfasd");
        character.charAnimator.ResetTrigger("Walk_Attack_1");
        character.charAnimator.ResetTrigger("Walk_Attack_2");
        character.charAnimator.ResetTrigger("Idle_Attack_1");
        character.charAnimator.ResetTrigger("Idle_Attack_2");
        ResetThrowTrigger();
    }

    // Locks direction character is during animation
    void LockDirection()
    {
        character.isAnimationDirectionLocked = true;
    }
    void UnlockDirection()
    {
        character.isAnimationDirectionLocked = false;
    }
}
