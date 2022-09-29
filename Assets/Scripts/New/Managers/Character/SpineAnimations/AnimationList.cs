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
    public BasicAnimation Hurt;
    public BasicAnimation Kicked;
    public BasicAnimation Slammed;
    public BasicAnimation KnockedDown;

    public List<BasicAnimation> Attack;
    public List<BasicAnimation> WalkAttack;
    public List<BasicAnimation> Death;

    public DeathAnimationByDamageRegion DeathAnimationByDamageRegion;
    [Space]
    [Space]

    public List<BasicAnimation> BreakStance;
}

[System.Serializable]
public class DeathAnimationByDamageRegion
{
    public List<DeathAnimation> highRegion;
    public List<DeathAnimation> midRegion;
    public List<DeathAnimation> lowRegion;
}
