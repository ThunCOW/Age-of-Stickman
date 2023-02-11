using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Unit Animations")]
public class AnimationList : ScriptableObject
{
    public List<AnimationsByStance> AnimationListByStance;
    private Dictionary<StanceList, UnitAnimations> animationsByStanceDict;
    private Dictionary<StanceList, float> speedByStanceDict;

    // Awake function is called when created
    public void OnStart()
    {
        foreach(var animationByStance in AnimationListByStance)
        {
            animationByStance.ActiveAnimations.Initialize();
        }

        animationsByStanceDict = new Dictionary<StanceList, UnitAnimations>();
        speedByStanceDict = new Dictionary<StanceList, float>();

        foreach (AnimationsByStance animationList in AnimationListByStance)
        {
            animationsByStanceDict.Add(animationList.Stance, animationList.ActiveAnimations);
            speedByStanceDict.Add(animationList.Stance, animationList.extraSpeed);
        }
    }

    public UnitAnimations GetActiveAnimationsByStance(StanceList stance)
    {
        OnStart();
        return animationsByStanceDict[stance];
    }

    public float GetSpeedByStance(StanceList stance)
    {
        return speedByStanceDict[stance];
    }

    public AnimationList InitializeSO()
    {
        return Instantiate(this);
    }
}

[System.Serializable]
public class AnimationsByStance
{
    public StanceList Stance;

    public UnitAnimations ActiveAnimations;

    public float extraSpeed;
}

[System.Serializable]
public class UnitAnimations
{
    public BasicAnimation idle;
    public BasicAnimation Movement;
    public BasicAnimation MovementBackward;
    public BasicAnimation BlockAttack;
    public BasicAnimation BlockWeaponSwap;
    public BasicAnimation ResetSlots;
    public BasicAnimation Hurt;
    public List<BasicAnimation> Hurts;
    public BasicAnimation Kicked;
    public BasicAnimation Slammed;
    public BasicAnimation KnockedDown;

    public List<BasicAnimation> Attack;
    public List<BasicAnimation> WalkAttack;
    public List<BasicAnimation> ProjectileAttack;
    public ChangeStanceAction ChangeStance;
    public SpeedDependantAnimation SwapWeapon;

    public DeathAnimationByDamageRegion DeathAnimationByDamageRegion;
    [Space]
    [Space]

    public List<BasicAnimation> BreakStance;
    
    public void Initialize()
    {
        if (idle != null) idle = idle.InitializeSO();
        if (Movement != null) Movement = Movement.InitializeSO();
        if (MovementBackward != null) MovementBackward = MovementBackward.InitializeSO();
        if (Hurt != null) Hurt = Hurt.InitializeSO();
        if (Kicked != null) Kicked = Kicked.InitializeSO();
        if (Slammed != null) Slammed = Slammed.InitializeSO();
        if (KnockedDown != null) KnockedDown = KnockedDown.InitializeSO();

        /*
         * *************************
         */
        int i;
        for(i = 0; i < Attack.Count; i++)
        {
            Attack[i] = Attack[i].InitializeSO();
        }
        for(i = 0; i < WalkAttack.Count; i++)
        {
            WalkAttack[i] = WalkAttack[i].InitializeSO();
        }
        
        /*
         * *******************
        */
        for(i = 0; i < DeathAnimationByDamageRegion.highRegion.Count; i++)
        {
            DeathAnimationByDamageRegion.highRegion[i] = DeathAnimationByDamageRegion.highRegion[i].InitializeSO() as DeathAnimation;
        }
        for(i = 0; i < DeathAnimationByDamageRegion.midRegion.Count; i++)
        {
            DeathAnimationByDamageRegion.midRegion[i] = DeathAnimationByDamageRegion.midRegion[i].InitializeSO() as DeathAnimation;
        }
        for(i = 0; i < DeathAnimationByDamageRegion.lowRegion.Count; i++)
        {
            DeathAnimationByDamageRegion.lowRegion[i] = DeathAnimationByDamageRegion.lowRegion[i].InitializeSO() as DeathAnimation;
        }
        
        // Spear death
        for(i = 0; i < DeathAnimationByDamageRegion.SpearThrowHead.Count; i++)
        {
            DeathAnimationByDamageRegion.SpearThrowHead[i] = DeathAnimationByDamageRegion.SpearThrowHead[i].InitializeSO() as DeathAnimation;
        }
        for (i = 0; i < DeathAnimationByDamageRegion.SpearThrowBody.Count; i++)
        {
            DeathAnimationByDamageRegion.SpearThrowBody[i] = DeathAnimationByDamageRegion.SpearThrowBody[i].InitializeSO() as DeathAnimation;
        }
    }
}

[System.Serializable]
public class DeathAnimationByDamageRegion
{
    public List<DeathAnimation> highRegion;
    public List<DeathAnimation> midRegion;
    public List<DeathAnimation> lowRegion;
    public List<DeathAnimation> SpearThrowHead;
    public List<DeathAnimation> SpearThrowBody;
}

[System.Serializable]
public class ChangeStanceAction
{
    public BasicAnimation Animation;
    public int chance;
}
