using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace StickmanChampion
{
    public class AnimationEventController : MonoBehaviour
    {
        Unit_Old Unit = null;
        void Start()
        {
            Unit = gameObject.transform.GetComponentInParent<Unit_Old>();
        }

        public void RangedAttack()
        {
            Unit.releaseProjectile = true;
        }

        public void MeleeAttack()
        {
            Unit.meleeHitTrigger = true;
            StartCoroutine(Unit.DealDamage());
        }
    } 
}
