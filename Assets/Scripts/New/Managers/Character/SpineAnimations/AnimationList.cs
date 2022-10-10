using System.Collections.Generic;
using UnityEngine;

[CreateAssetMenu(menuName = "Spine Animation/Unit Animations")]
public class AnimationList : ScriptableObject
{
    public List<AnimationsByStance> AnimationListByStance;
    private Dictionary<StanceList, UnitAnimations> animationsByStanceDict;
    // Awake function is called when created
    public void OnStart()
    {
        foreach(var animationByStance in AnimationListByStance)
        {
            animationByStance.ActiveAnimations.Initialize();
        }

        animationsByStanceDict = new Dictionary<StanceList, UnitAnimations>();

        foreach (AnimationsByStance animationList in AnimationListByStance)
        {
            animationsByStanceDict.Add(animationList.Stance, animationList.ActiveAnimations);
        }
    }

    public UnitAnimations GetActiveAnimationsByStance(StanceList stance)
    {
        OnStart();
        return animationsByStanceDict[stance];
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
}

[System.Serializable]
public class UnitAnimations
{
    public BasicAnimation idle;
    public BasicAnimation Movement;
    public BasicAnimation MovementBackward;
    public BasicAnimation BlockAttack;
    public BasicAnimation ResetSlots;
    public BasicAnimation Hurt;
    public BasicAnimation Kicked;
    public BasicAnimation Slammed;
    public BasicAnimation KnockedDown;

    public List<BasicAnimation> Attack;
    public List<BasicAnimation> WalkAttack;

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
    }
}

[System.Serializable]
public class DeathAnimationByDamageRegion
{
    public List<DeathAnimation> highRegion;
    public List<DeathAnimation> midRegion;
    public List<DeathAnimation> lowRegion;
}
