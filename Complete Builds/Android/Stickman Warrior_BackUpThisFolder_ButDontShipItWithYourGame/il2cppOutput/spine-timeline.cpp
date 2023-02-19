﻿#include "pch-cpp.hpp"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include <limits>
#include <stdint.h>


struct VirtualActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
struct GenericVirtualActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_virtual_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
struct InterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename R>
struct InterfaceFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeClass* declaringInterface, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_interface_invoke_data(slot, obj, declaringInterface);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};
struct GenericInterfaceActionInvoker0
{
	typedef void (*Action)(void*, const RuntimeMethod*);

	static inline void Invoke (const RuntimeMethod* method, RuntimeObject* obj)
	{
		VirtualInvokeData invokeData;
		il2cpp_codegen_get_generic_interface_invoke_data(method, obj, &invokeData);
		((Action)invokeData.methodPtr)(obj, invokeData.method);
	}
};
template <typename T1>
struct InvokerActionInvoker1;
template <typename T1>
struct InvokerActionInvoker1<T1*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1)
	{
		void* params[1] = { p1 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};
template <typename T1, typename T2>
struct InvokerActionInvoker2;
template <typename T1, typename T2>
struct InvokerActionInvoker2<T1*, T2*>
{
	static inline void Invoke (Il2CppMethodPointer methodPtr, const RuntimeMethod* method, void* obj, T1* p1, T2* p2)
	{
		void* params[2] = { p1, p2 };
		method->invoker_method(methodPtr, method, obj, params, NULL);
	}
};

// System.Action`1<UnityEngine.Playables.PlayableDirector>
struct Action_1_tB645F646DB079054A9500B09427CB02A88372D3F;
// System.Action`3<UnityEngine.Timeline.TimelineClip,UnityEngine.GameObject,UnityEngine.Playables.Playable>
struct Action_3_t3638A0A401CA68AF6FECFB956B602BBF7B9EFA72;
// System.Action`3<UnityEngine.Timeline.TrackAsset,UnityEngine.GameObject,UnityEngine.Playables.Playable>
struct Action_3_t8A9161BC98843636E3BF066B37CBCC15C593B73E;
// System.Collections.Generic.Dictionary`2<UnityEngine.Material,UnityEngine.Material>
struct Dictionary_2_t7B0F5D63DDA1E532530982C8043F0A132FF9745F;
// System.Collections.Generic.Dictionary`2<Spine.Slot,UnityEngine.Material>
struct Dictionary_2_tF46BBFD2B39F05EA43825A1BD4B99EADEDE994D4;
// System.Collections.Generic.Dictionary`2<UnityEngine.Texture,UnityEngine.Material>
struct Dictionary_2_t0EB522A36CBFB73E1DB8B66A87752EA513361ACD;
// System.Collections.Generic.Dictionary`2<UnityEngine.Texture,UnityEngine.Texture>
struct Dictionary_2_t5BE8DFCD10ADA75C178B92A43A8FF7EE49D7E610;
// System.Collections.Generic.Dictionary`2<System.Type,UnityEngine.Timeline.TrackBindingTypeAttribute>
struct Dictionary_2_tF0368534E8881FC0469B58E4901741C5B0CC1D79;
// System.Collections.Generic.Dictionary`2<Spine.AnimationStateData/AnimationPair,System.Single>
struct Dictionary_2_tFC66226EB631803AB42AC8AA018D1446D98C3E88;
// Spine.Unity.DoubleBuffered`1<Spine.Unity.MeshRendererBuffers/SmartMesh>
struct DoubleBuffered_1_tAA5948FEDBAA5BD58CAE43B2515316D275B074AE;
// Spine.ExposedList`1<Spine.Animation>
struct ExposedList_1_t05C3DB7146AAFC91022372E09618489E9A255D7F;
// Spine.ExposedList`1<Spine.Bone>
struct ExposedList_1_t849594F8CC2D95E44660D7B3F2A8ED08A920EC76;
// Spine.ExposedList`1<Spine.BoneData>
struct ExposedList_1_t8AB80252C5BCE6B8A6A9C0098C944FC1A20830FF;
// Spine.ExposedList`1<Spine.Event>
struct ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E;
// Spine.ExposedList`1<Spine.EventData>
struct ExposedList_1_t508ADA5F8A7704859C2107E981798BA1484DCD9E;
// Spine.ExposedList`1<Spine.IUpdatable>
struct ExposedList_1_t71C5FB8B50C5DC6DB428B20CFD98F4D207B1BED1;
// Spine.ExposedList`1<Spine.IkConstraint>
struct ExposedList_1_tC99DB3CFE5976DE3F9E2C44BAB20AA8D8FDBA32C;
// Spine.ExposedList`1<Spine.IkConstraintData>
struct ExposedList_1_t8E5593D0177B15969E195039106DE69FCECA2F5B;
// Spine.ExposedList`1<System.Int32>
struct ExposedList_1_t78C35B13C09679E167D37A21B1793179083457D5;
// Spine.ExposedList`1<UnityEngine.Mesh>
struct ExposedList_1_t06E83C6B69FFBF51FF15EF7A1AB7CC9B674677A2;
// Spine.ExposedList`1<Spine.PathConstraint>
struct ExposedList_1_tE76122B92598756895B4778D125358BEFB5E1EAD;
// Spine.ExposedList`1<Spine.PathConstraintData>
struct ExposedList_1_tB5DF3CC22CDC499FB1A80B68A5D3C4614017FED3;
// Spine.ExposedList`1<System.Single>
struct ExposedList_1_tD73D23BD855506DEC8EFBB0A8EAA86A1F2053245;
// Spine.ExposedList`1<Spine.Skin>
struct ExposedList_1_tB3B714EFCBEF2468DFD394055159910792E45928;
// Spine.ExposedList`1<Spine.Slot>
struct ExposedList_1_t463A36CA55DF116E467973BD0102551B2820CDDD;
// Spine.ExposedList`1<Spine.SlotData>
struct ExposedList_1_tF3A893E298F714C9656A72BAFEE686BAC3300074;
// Spine.ExposedList`1<Spine.Timeline>
struct ExposedList_1_tA26A17A89AD06F765B3D726D420D4FAA58BE3F9F;
// Spine.ExposedList`1<Spine.TrackEntry>
struct ExposedList_1_t19DC027924CCEBF55B52280A831270C82F0F7B9E;
// Spine.ExposedList`1<Spine.TransformConstraint>
struct ExposedList_1_t6E388F5B49D56E0E710FEFC69AE31CC950CDB621;
// Spine.ExposedList`1<Spine.TransformConstraintData>
struct ExposedList_1_t79D5FAA1F444637DAF411F78F3D78BED9F176B8E;
// System.Collections.Generic.HashSet`1<System.Int32>
struct HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2;
// System.Collections.Generic.IEnumerable`1<UnityEngine.Timeline.TrackAsset>
struct IEnumerable_1_tCF360FA8155395D7F2E3092E355BE18C4A37F7E0;
// System.Collections.Generic.List`1<UnityEngine.CanvasRenderer>
struct List_1_tF927985772F2034B6D3251636D0EA26C950BE569;
// System.Collections.Generic.List`1<UnityEngine.Timeline.IMarker>
struct List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF;
// System.Collections.Generic.List`1<UnityEngine.UI.RawImage>
struct List_1_t8F8EC453709D820AD028F01D85A01A31FB4B1B52;
// System.Collections.Generic.List`1<UnityEngine.ScriptableObject>
struct List_1_tF941E9C3FEB6F1C2D20E73A90AA7F6319EB3F828;
// System.Collections.Generic.List`1<Spine.Unity.SkeletonDataModifierAsset>
struct List_1_tBFA73B26AF72BABC85549F091C4BA5A95B9FB412;
// System.Collections.Generic.List`1<Spine.Slot>
struct List_1_t75CC7DC5981BB1205F28E94CAC72B41781A3E0D4;
// System.Collections.Generic.List`1<UnityEngine.Timeline.TimelineClip>
struct List_1_tD78196B4DE777C4B74ADAD24051A9978F5191506;
// System.Collections.Generic.List`1<UnityEngine.Timeline.TrackAsset>
struct List_1_t6908BEEFB57470CB30420983896AA06BFB8796F0;
// System.Collections.Generic.List`1<UnityEngine.Transform>
struct List_1_t991BBC5A1D51F59A450367DF944DAA207F22D06D;
// Spine.Pool`1<Spine.TrackEntry>
struct Pool_1_t2511ABDF24C6E1B959576D963729E5F88506C991;
// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween>
struct TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4;
// Spine.Unity.AtlasAssetBase[]
struct AtlasAssetBaseU5BU5D_t6D8EAEA3267D1DFC3FBFAA3ECE699B48E92E5C82;
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
// Spine.Event[]
struct EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C;
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
// System.Single[]
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;
// System.String[]
struct StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248;
// UnityEngine.Timeline.TimelineClip[]
struct TimelineClipU5BU5D_t37945156A55BC896C442C4FE59198216769A4E64;
// UnityEngine.Timeline.TrackAsset[]
struct TrackAssetU5BU5D_tE6935AFD32D0BE4B0C69D1CCE96B55D383BCF88C;
// UnityEngine.Vector2[]
struct Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA;
// UnityEngine.Vector3[]
struct Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C;
// Spine.Animation
struct Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62;
// UnityEngine.AnimationClip
struct AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712;
// Spine.Unity.AnimationReferenceAsset
struct AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658;
// Spine.AnimationState
struct AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC;
// Spine.AnimationStateData
struct AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62;
// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C;
// Spine.Unity.BlendModeMaterials
struct BlendModeMaterials_t3DA4B85DB36B60D661B6403BD49E7D62F56B81D8;
// UnityEngine.Canvas
struct Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26;
// UnityEngine.CanvasRenderer
struct CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860;
// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3;
// System.Delegate
struct Delegate_t;
// System.DelegateData
struct DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E;
// Spine.Event
struct Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5;
// Spine.EventData
struct EventData_t0CB41981A14EA97459A419469AD9926522A59090;
// Spine.EventQueue
struct EventQueue_tD7A22C8477C3484CB82157A339353AD637C1704D;
// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F;
// Spine.Unity.IAnimationStateComponent
struct IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3;
// System.IAsyncResult
struct IAsyncResult_t7B9B5A0ECB35DCEC31B8A8122C37D687369253B5;
// UnityEngine.Timeline.IPropertyCollector
struct IPropertyCollector_tB7A05EB96DC9D20D8FE2EB89ECD2F7575BEA72BA;
// Spine.Unity.ISkeletonComponent
struct ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482;
// UnityEngine.Material
struct Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3;
// UnityEngine.MaterialPropertyBlock
struct MaterialPropertyBlock_t2308669579033A857EFE6E4831909F638B27411D;
// UnityEngine.Mesh
struct Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4;
// UnityEngine.MeshFilter
struct MeshFilter_t6D1CE2473A1E45AC73013400585A1163BF66B2F5;
// Spine.Unity.MeshGenerator
struct MeshGenerator_t754492D79919D913B93BE05E83D270CEACAC392C;
// Spine.Unity.MeshGeneratorDelegate
struct MeshGeneratorDelegate_t799773C2F6BEC0D47D27646DB0FBE22A28821E8B;
// UnityEngine.MeshRenderer
struct MeshRenderer_t4B7747212F0B88244BB7790C61AE124BFC15BAAE;
// Spine.Unity.MeshRendererBuffers
struct MeshRendererBuffers_tB9308AD2A53E8B70963EF29DBF88716A6BBE567B;
// System.Reflection.MethodInfo
struct MethodInfo_t;
// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71;
// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C;
// UnityEngine.Playables.PlayableAsset
struct PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E;
// UnityEngine.Playables.PlayableBehaviour
struct PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2;
// UnityEngine.Playables.PlayableDirector
struct PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475;
// UnityEngine.UI.RectMask2D
struct RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670;
// UnityEngine.RectTransform
struct RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5;
// UnityEngine.RuntimeAnimatorController
struct RuntimeAnimatorController_t6F7C753402B42EC23C163099CF935C5E0D7A7254;
// Spine.Skeleton
struct Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC;
// Spine.Unity.SkeletonAnimation
struct SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A;
// Spine.Unity.Playables.SkeletonAnimationPlayableHandle
struct SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2;
// Spine.SkeletonData
struct SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B;
// Spine.Unity.SkeletonDataAsset
struct SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F;
// Spine.Unity.SkeletonGraphic
struct SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1;
// Spine.Unity.Playables.SkeletonGraphicPlayableHandle
struct SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA;
// Spine.Unity.SkeletonRenderer
struct SkeletonRenderer_t6D14A218C3A502F075DC4C4423EE2ACEBFEB620A;
// Spine.Unity.SkeletonRendererInstruction
struct SkeletonRendererInstruction_t7EBEBDCF3450913487EE58F1C3F0A0E084A51163;
// Spine.Skin
struct Skin_tD0213151BACA5300AF80D52F1DA6B95510F35B83;
// Spine.Unity.Playables.SpineAnimationStateBehaviour
struct SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08;
// Spine.Unity.Playables.SpineAnimationStateClip
struct SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A;
// Spine.Unity.Playables.SpineAnimationStateGraphicTrack
struct SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88;
// Spine.Unity.Playables.SpineAnimationStateMixerBehaviour
struct SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D;
// Spine.Unity.Playables.SpineAnimationStateTrack
struct SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3;
// Spine.Unity.Playables.SpineEventDelegate
struct SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C;
// Spine.Unity.Playables.SpinePlayableHandleBase
struct SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570;
// SpineSkeletonFlipBehaviour
struct SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE;
// SpineSkeletonFlipClip
struct SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1;
// Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour
struct SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D;
// Spine.Unity.Playables.SpineSkeletonFlipTrack
struct SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0;
// System.String
struct String_t;
// UnityEngine.TextAsset
struct TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69;
// UnityEngine.Texture
struct Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700;
// UnityEngine.Texture2D
struct Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4;
// UnityEngine.Timeline.TrackAsset
struct TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96;
// Spine.TrackEntry
struct TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB;
// UnityEngine.Events.UnityAction
struct UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7;
// Spine.Unity.UpdateBonesDelegate
struct UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD;
// UnityEngine.UI.VertexHelper
struct VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE;
// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
// Spine.AnimationState/TrackEntryDelegate
struct TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C;
// Spine.AnimationState/TrackEntryEventDelegate
struct TrackEntryEventDelegate_tC73115975F60CA3AE0364B9EB9901B89E30359F3;
// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent
struct CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8;
// Spine.Unity.SkeletonGraphic/SkeletonRendererDelegate
struct SkeletonRendererDelegate_tF00A46D09906FA01EB8DC11B3306FE0E7C3A8A1C;
// Spine.Unity.SkeletonRenderer/InstructionDelegate
struct InstructionDelegate_t751C3C0C3012ADBD85CD298FF1DCCDE3541B57B6;
// Spine.Unity.SkeletonRenderer/SkeletonRendererDelegate
struct SkeletonRendererDelegate_t8DAF5E58107FFA0E1E02F3869D004088226BF4F7;
// Spine.Unity.SkeletonRenderer/SpriteMaskInteractionMaterials
struct SpriteMaskInteractionMaterials_tF9C97C34FC619F4BCF4E47C16262899351C10720;

IL2CPP_EXTERN_C RuntimeClass* AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeClass* TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteralD9AEAA6A49FCC6BC5EF6CE3F695813A1EAB670BE;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8_RuntimeMethod_var;
struct Delegate_t_marshaled_com;
struct Delegate_t_marshaled_pinvoke;

struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771;
struct EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C;
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918;
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C;

IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// <Module>
struct U3CModuleU3E_t6189A1E2F1D7402780301F76127407559890790E 
{
};

// Spine.ExposedList`1<Spine.Event>
struct ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E  : public RuntimeObject
{
	// T[] Spine.ExposedList`1::Items
	EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C* ___Items_0;
	// System.Int32 Spine.ExposedList`1::Count
	int32_t ___Count_1;
	// System.Int32 Spine.ExposedList`1::version
	int32_t ___version_4;
};

struct ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E_StaticFields
{
	// T[] Spine.ExposedList`1::EmptyArray
	EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C* ___EmptyArray_3;
};

// Spine.Animation
struct Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62  : public RuntimeObject
{
	// System.String Spine.Animation::name
	String_t* ___name_0;
	// Spine.ExposedList`1<Spine.Timeline> Spine.Animation::timelines
	ExposedList_1_tA26A17A89AD06F765B3D726D420D4FAA58BE3F9F* ___timelines_1;
	// System.Collections.Generic.HashSet`1<System.Int32> Spine.Animation::timelineIds
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___timelineIds_2;
	// System.Single Spine.Animation::duration
	float ___duration_3;
};

// Spine.AnimationState
struct AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC  : public RuntimeObject
{
	// Spine.AnimationStateData Spine.AnimationState::data
	AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* ___data_8;
	// Spine.ExposedList`1<Spine.TrackEntry> Spine.AnimationState::tracks
	ExposedList_1_t19DC027924CCEBF55B52280A831270C82F0F7B9E* ___tracks_9;
	// Spine.ExposedList`1<Spine.Event> Spine.AnimationState::events
	ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* ___events_10;
	// Spine.AnimationState/TrackEntryDelegate Spine.AnimationState::Start
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Start_11;
	// Spine.AnimationState/TrackEntryDelegate Spine.AnimationState::Interrupt
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Interrupt_12;
	// Spine.AnimationState/TrackEntryDelegate Spine.AnimationState::End
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___End_13;
	// Spine.AnimationState/TrackEntryDelegate Spine.AnimationState::Dispose
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Dispose_14;
	// Spine.AnimationState/TrackEntryDelegate Spine.AnimationState::Complete
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Complete_15;
	// Spine.AnimationState/TrackEntryEventDelegate Spine.AnimationState::Event
	TrackEntryEventDelegate_tC73115975F60CA3AE0364B9EB9901B89E30359F3* ___Event_16;
	// Spine.EventQueue Spine.AnimationState::queue
	EventQueue_tD7A22C8477C3484CB82157A339353AD637C1704D* ___queue_17;
	// System.Collections.Generic.HashSet`1<System.Int32> Spine.AnimationState::propertyIDs
	HashSet_1_t4A2F2B74276D0AD3ED0F873045BD61E9504ECAE2* ___propertyIDs_18;
	// System.Boolean Spine.AnimationState::animationsChanged
	bool ___animationsChanged_19;
	// System.Single Spine.AnimationState::timeScale
	float ___timeScale_20;
	// System.Int32 Spine.AnimationState::unkeyedState
	int32_t ___unkeyedState_21;
	// Spine.Pool`1<Spine.TrackEntry> Spine.AnimationState::trackEntryPool
	Pool_1_t2511ABDF24C6E1B959576D963729E5F88506C991* ___trackEntryPool_22;
};

struct AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_StaticFields
{
	// Spine.Animation Spine.AnimationState::EmptyAnimation
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___EmptyAnimation_0;
};

// Spine.AnimationStateData
struct AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62  : public RuntimeObject
{
	// Spine.SkeletonData Spine.AnimationStateData::skeletonData
	SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* ___skeletonData_0;
	// System.Collections.Generic.Dictionary`2<Spine.AnimationStateData/AnimationPair,System.Single> Spine.AnimationStateData::animationToMixTime
	Dictionary_2_tFC66226EB631803AB42AC8AA018D1446D98C3E88* ___animationToMixTime_1;
	// System.Single Spine.AnimationStateData::defaultMix
	float ___defaultMix_2;
};
struct Il2CppArrayBounds;

// Spine.Event
struct Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5  : public RuntimeObject
{
	// Spine.EventData Spine.Event::data
	EventData_t0CB41981A14EA97459A419469AD9926522A59090* ___data_0;
	// System.Single Spine.Event::time
	float ___time_1;
	// System.Int32 Spine.Event::intValue
	int32_t ___intValue_2;
	// System.Single Spine.Event::floatValue
	float ___floatValue_3;
	// System.String Spine.Event::stringValue
	String_t* ___stringValue_4;
	// System.Single Spine.Event::volume
	float ___volume_5;
	// System.Single Spine.Event::balance
	float ___balance_6;
};

// UnityEngine.Playables.PlayableBehaviour
struct PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2  : public RuntimeObject
{
};

// Spine.Skeleton
struct Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC  : public RuntimeObject
{
	// Spine.SkeletonData Spine.Skeleton::data
	SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* ___data_0;
	// Spine.ExposedList`1<Spine.Bone> Spine.Skeleton::bones
	ExposedList_1_t849594F8CC2D95E44660D7B3F2A8ED08A920EC76* ___bones_1;
	// Spine.ExposedList`1<Spine.Slot> Spine.Skeleton::slots
	ExposedList_1_t463A36CA55DF116E467973BD0102551B2820CDDD* ___slots_2;
	// Spine.ExposedList`1<Spine.Slot> Spine.Skeleton::drawOrder
	ExposedList_1_t463A36CA55DF116E467973BD0102551B2820CDDD* ___drawOrder_3;
	// Spine.ExposedList`1<Spine.IkConstraint> Spine.Skeleton::ikConstraints
	ExposedList_1_tC99DB3CFE5976DE3F9E2C44BAB20AA8D8FDBA32C* ___ikConstraints_4;
	// Spine.ExposedList`1<Spine.TransformConstraint> Spine.Skeleton::transformConstraints
	ExposedList_1_t6E388F5B49D56E0E710FEFC69AE31CC950CDB621* ___transformConstraints_5;
	// Spine.ExposedList`1<Spine.PathConstraint> Spine.Skeleton::pathConstraints
	ExposedList_1_tE76122B92598756895B4778D125358BEFB5E1EAD* ___pathConstraints_6;
	// Spine.ExposedList`1<Spine.IUpdatable> Spine.Skeleton::updateCache
	ExposedList_1_t71C5FB8B50C5DC6DB428B20CFD98F4D207B1BED1* ___updateCache_7;
	// Spine.ExposedList`1<Spine.Bone> Spine.Skeleton::updateCacheReset
	ExposedList_1_t849594F8CC2D95E44660D7B3F2A8ED08A920EC76* ___updateCacheReset_8;
	// Spine.Skin Spine.Skeleton::skin
	Skin_tD0213151BACA5300AF80D52F1DA6B95510F35B83* ___skin_9;
	// System.Single Spine.Skeleton::r
	float ___r_10;
	// System.Single Spine.Skeleton::g
	float ___g_11;
	// System.Single Spine.Skeleton::b
	float ___b_12;
	// System.Single Spine.Skeleton::a
	float ___a_13;
	// System.Single Spine.Skeleton::time
	float ___time_14;
	// System.Single Spine.Skeleton::scaleX
	float ___scaleX_15;
	// System.Single Spine.Skeleton::scaleY
	float ___scaleY_16;
	// System.Single Spine.Skeleton::x
	float ___x_17;
	// System.Single Spine.Skeleton::y
	float ___y_18;
};

// Spine.SkeletonData
struct SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B  : public RuntimeObject
{
	// System.String Spine.SkeletonData::name
	String_t* ___name_0;
	// Spine.ExposedList`1<Spine.BoneData> Spine.SkeletonData::bones
	ExposedList_1_t8AB80252C5BCE6B8A6A9C0098C944FC1A20830FF* ___bones_1;
	// Spine.ExposedList`1<Spine.SlotData> Spine.SkeletonData::slots
	ExposedList_1_tF3A893E298F714C9656A72BAFEE686BAC3300074* ___slots_2;
	// Spine.ExposedList`1<Spine.Skin> Spine.SkeletonData::skins
	ExposedList_1_tB3B714EFCBEF2468DFD394055159910792E45928* ___skins_3;
	// Spine.Skin Spine.SkeletonData::defaultSkin
	Skin_tD0213151BACA5300AF80D52F1DA6B95510F35B83* ___defaultSkin_4;
	// Spine.ExposedList`1<Spine.EventData> Spine.SkeletonData::events
	ExposedList_1_t508ADA5F8A7704859C2107E981798BA1484DCD9E* ___events_5;
	// Spine.ExposedList`1<Spine.Animation> Spine.SkeletonData::animations
	ExposedList_1_t05C3DB7146AAFC91022372E09618489E9A255D7F* ___animations_6;
	// Spine.ExposedList`1<Spine.IkConstraintData> Spine.SkeletonData::ikConstraints
	ExposedList_1_t8E5593D0177B15969E195039106DE69FCECA2F5B* ___ikConstraints_7;
	// Spine.ExposedList`1<Spine.TransformConstraintData> Spine.SkeletonData::transformConstraints
	ExposedList_1_t79D5FAA1F444637DAF411F78F3D78BED9F176B8E* ___transformConstraints_8;
	// Spine.ExposedList`1<Spine.PathConstraintData> Spine.SkeletonData::pathConstraints
	ExposedList_1_tB5DF3CC22CDC499FB1A80B68A5D3C4614017FED3* ___pathConstraints_9;
	// System.Single Spine.SkeletonData::x
	float ___x_10;
	// System.Single Spine.SkeletonData::y
	float ___y_11;
	// System.Single Spine.SkeletonData::width
	float ___width_12;
	// System.Single Spine.SkeletonData::height
	float ___height_13;
	// System.String Spine.SkeletonData::version
	String_t* ___version_14;
	// System.String Spine.SkeletonData::hash
	String_t* ___hash_15;
	// System.Single Spine.SkeletonData::fps
	float ___fps_16;
	// System.String Spine.SkeletonData::imagesPath
	String_t* ___imagesPath_17;
	// System.String Spine.SkeletonData::audioPath
	String_t* ___audioPath_18;
};

// System.String
struct String_t  : public RuntimeObject
{
	// System.Int32 System.String::_stringLength
	int32_t ____stringLength_4;
	// System.Char System.String::_firstChar
	Il2CppChar ____firstChar_5;
};

struct String_t_StaticFields
{
	// System.String System.String::Empty
	String_t* ___Empty_6;
};

// Spine.TrackEntry
struct TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB  : public RuntimeObject
{
	// Spine.Animation Spine.TrackEntry::animation
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___animation_0;
	// Spine.TrackEntry Spine.TrackEntry::next
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* ___next_1;
	// Spine.TrackEntry Spine.TrackEntry::mixingFrom
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* ___mixingFrom_2;
	// Spine.TrackEntry Spine.TrackEntry::mixingTo
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* ___mixingTo_3;
	// Spine.AnimationState/TrackEntryDelegate Spine.TrackEntry::Start
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Start_4;
	// Spine.AnimationState/TrackEntryDelegate Spine.TrackEntry::Interrupt
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Interrupt_5;
	// Spine.AnimationState/TrackEntryDelegate Spine.TrackEntry::End
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___End_6;
	// Spine.AnimationState/TrackEntryDelegate Spine.TrackEntry::Dispose
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Dispose_7;
	// Spine.AnimationState/TrackEntryDelegate Spine.TrackEntry::Complete
	TrackEntryDelegate_tC534B015761F6771D522A1894DFC271421A4A05C* ___Complete_8;
	// Spine.AnimationState/TrackEntryEventDelegate Spine.TrackEntry::Event
	TrackEntryEventDelegate_tC73115975F60CA3AE0364B9EB9901B89E30359F3* ___Event_9;
	// System.Int32 Spine.TrackEntry::trackIndex
	int32_t ___trackIndex_10;
	// System.Boolean Spine.TrackEntry::loop
	bool ___loop_11;
	// System.Boolean Spine.TrackEntry::holdPrevious
	bool ___holdPrevious_12;
	// System.Single Spine.TrackEntry::eventThreshold
	float ___eventThreshold_13;
	// System.Single Spine.TrackEntry::attachmentThreshold
	float ___attachmentThreshold_14;
	// System.Single Spine.TrackEntry::drawOrderThreshold
	float ___drawOrderThreshold_15;
	// System.Single Spine.TrackEntry::animationStart
	float ___animationStart_16;
	// System.Single Spine.TrackEntry::animationEnd
	float ___animationEnd_17;
	// System.Single Spine.TrackEntry::animationLast
	float ___animationLast_18;
	// System.Single Spine.TrackEntry::nextAnimationLast
	float ___nextAnimationLast_19;
	// System.Single Spine.TrackEntry::delay
	float ___delay_20;
	// System.Single Spine.TrackEntry::trackTime
	float ___trackTime_21;
	// System.Single Spine.TrackEntry::trackLast
	float ___trackLast_22;
	// System.Single Spine.TrackEntry::nextTrackLast
	float ___nextTrackLast_23;
	// System.Single Spine.TrackEntry::trackEnd
	float ___trackEnd_24;
	// System.Single Spine.TrackEntry::timeScale
	float ___timeScale_25;
	// System.Single Spine.TrackEntry::alpha
	float ___alpha_26;
	// System.Single Spine.TrackEntry::mixTime
	float ___mixTime_27;
	// System.Single Spine.TrackEntry::mixDuration
	float ___mixDuration_28;
	// System.Single Spine.TrackEntry::interruptAlpha
	float ___interruptAlpha_29;
	// System.Single Spine.TrackEntry::totalAlpha
	float ___totalAlpha_30;
	// Spine.MixBlend Spine.TrackEntry::mixBlend
	int32_t ___mixBlend_31;
	// Spine.ExposedList`1<System.Int32> Spine.TrackEntry::timelineMode
	ExposedList_1_t78C35B13C09679E167D37A21B1793179083457D5* ___timelineMode_32;
	// Spine.ExposedList`1<Spine.TrackEntry> Spine.TrackEntry::timelineHoldMix
	ExposedList_1_t19DC027924CCEBF55B52280A831270C82F0F7B9E* ___timelineHoldMix_33;
	// Spine.ExposedList`1<System.Single> Spine.TrackEntry::timelinesRotation
	ExposedList_1_tD73D23BD855506DEC8EFBB0A8EAA86A1F2053245* ___timelinesRotation_34;
};

// System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
// Native definition for P/Invoke marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
// Native definition for COM marshalling of System.ValueType
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};

// System.Nullable`1<System.Boolean>
struct Nullable_1_t78F453FADB4A9F50F267A4E349019C34410D1A01 
{
	// System.Boolean System.Nullable`1::hasValue
	bool ___hasValue_0;
	// T System.Nullable`1::value
	bool ___value_1;
};

// System.Boolean
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	// System.Boolean System.Boolean::m_value
	bool ___m_value_0;
};

struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	// System.String System.Boolean::TrueString
	String_t* ___TrueString_5;
	// System.String System.Boolean::FalseString
	String_t* ___FalseString_6;
};

// UnityEngine.Color
struct Color_tD001788D726C3A7F1379BEED0260B9591F440C1F 
{
	// System.Single UnityEngine.Color::r
	float ___r_0;
	// System.Single UnityEngine.Color::g
	float ___g_1;
	// System.Single UnityEngine.Color::b
	float ___b_2;
	// System.Single UnityEngine.Color::a
	float ___a_3;
};

// UnityEngine.Timeline.DiscreteTime
struct DiscreteTime_t1598D60B0B2432F702E2A6120D04369EE54600A6 
{
	// System.Int64 UnityEngine.Timeline.DiscreteTime::m_DiscreteTime
	int64_t ___m_DiscreteTime_2;
};

struct DiscreteTime_t1598D60B0B2432F702E2A6120D04369EE54600A6_StaticFields
{
	// UnityEngine.Timeline.DiscreteTime UnityEngine.Timeline.DiscreteTime::kMaxTime
	DiscreteTime_t1598D60B0B2432F702E2A6120D04369EE54600A6 ___kMaxTime_1;
};

// System.Double
struct Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F 
{
	// System.Double System.Double::m_value
	double ___m_value_0;
};

// System.Int32
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	// System.Int32 System.Int32::m_value
	int32_t ___m_value_0;
};

// System.IntPtr
struct IntPtr_t 
{
	// System.Void* System.IntPtr::m_value
	void* ___m_value_0;
};

struct IntPtr_t_StaticFields
{
	// System.IntPtr System.IntPtr::Zero
	intptr_t ___Zero_1;
};

// UnityEngine.Timeline.MarkerList
struct MarkerList_tD4B632EBA98CE678EB8D108A1AF559F734FA7698 
{
	// System.Collections.Generic.List`1<UnityEngine.ScriptableObject> UnityEngine.Timeline.MarkerList::m_Objects
	List_1_tF941E9C3FEB6F1C2D20E73A90AA7F6319EB3F828* ___m_Objects_0;
	// System.Collections.Generic.List`1<UnityEngine.Timeline.IMarker> UnityEngine.Timeline.MarkerList::m_Cache
	List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF* ___m_Cache_1;
	// System.Boolean UnityEngine.Timeline.MarkerList::m_CacheDirty
	bool ___m_CacheDirty_2;
	// System.Boolean UnityEngine.Timeline.MarkerList::m_HasNotifications
	bool ___m_HasNotifications_3;
};
// Native definition for P/Invoke marshalling of UnityEngine.Timeline.MarkerList
struct MarkerList_tD4B632EBA98CE678EB8D108A1AF559F734FA7698_marshaled_pinvoke
{
	List_1_tF941E9C3FEB6F1C2D20E73A90AA7F6319EB3F828* ___m_Objects_0;
	List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF* ___m_Cache_1;
	int32_t ___m_CacheDirty_2;
	int32_t ___m_HasNotifications_3;
};
// Native definition for COM marshalling of UnityEngine.Timeline.MarkerList
struct MarkerList_tD4B632EBA98CE678EB8D108A1AF559F734FA7698_marshaled_com
{
	List_1_tF941E9C3FEB6F1C2D20E73A90AA7F6319EB3F828* ___m_Objects_0;
	List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF* ___m_Cache_1;
	int32_t ___m_CacheDirty_2;
	int32_t ___m_HasNotifications_3;
};

// UnityEngine.Mathf
struct Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682 
{
	union
	{
		struct
		{
		};
		uint8_t Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682__padding[1];
	};
};

struct Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields
{
	// System.Single UnityEngine.Mathf::Epsilon
	float ___Epsilon_0;
};

// System.Single
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	// System.Single System.Single::m_value
	float ___m_value_0;
};

// Spine.Unity.Playables.SpineAnimationStateBehaviour
struct SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08  : public PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2
{
	// Spine.Unity.AnimationReferenceAsset Spine.Unity.Playables.SpineAnimationStateBehaviour::animationReference
	AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* ___animationReference_0;
	// System.Boolean Spine.Unity.Playables.SpineAnimationStateBehaviour::loop
	bool ___loop_1;
	// System.Boolean Spine.Unity.Playables.SpineAnimationStateBehaviour::customDuration
	bool ___customDuration_2;
	// System.Boolean Spine.Unity.Playables.SpineAnimationStateBehaviour::useBlendDuration
	bool ___useBlendDuration_3;
	// System.Boolean Spine.Unity.Playables.SpineAnimationStateBehaviour::isInitialized
	bool ___isInitialized_4;
	// System.Single Spine.Unity.Playables.SpineAnimationStateBehaviour::mixDuration
	float ___mixDuration_5;
	// System.Boolean Spine.Unity.Playables.SpineAnimationStateBehaviour::holdPrevious
	bool ___holdPrevious_6;
	// System.Single Spine.Unity.Playables.SpineAnimationStateBehaviour::attachmentThreshold
	float ___attachmentThreshold_7;
	// System.Single Spine.Unity.Playables.SpineAnimationStateBehaviour::eventThreshold
	float ___eventThreshold_8;
	// System.Single Spine.Unity.Playables.SpineAnimationStateBehaviour::drawOrderThreshold
	float ___drawOrderThreshold_9;
};

// Spine.Unity.Playables.SpineAnimationStateMixerBehaviour
struct SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D  : public PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2
{
	// System.Single[] Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::lastInputWeights
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___lastInputWeights_0;
	// System.Int32 Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::trackIndex
	int32_t ___trackIndex_1;
	// Spine.AnimationState Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::dummyAnimationState
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* ___dummyAnimationState_2;
};

// SpineSkeletonFlipBehaviour
struct SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE  : public PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2
{
	// System.Boolean SpineSkeletonFlipBehaviour::flipX
	bool ___flipX_0;
	// System.Boolean SpineSkeletonFlipBehaviour::flipY
	bool ___flipY_1;
};

// Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour
struct SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D  : public PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2
{
	// System.Single Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::originalScaleX
	float ___originalScaleX_0;
	// System.Single Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::originalScaleY
	float ___originalScaleY_1;
	// System.Single Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::baseScaleX
	float ___baseScaleX_2;
	// System.Single Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::baseScaleY
	float ___baseScaleY_3;
	// Spine.Unity.Playables.SpinePlayableHandleBase Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::playableHandle
	SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* ___playableHandle_4;
	// System.Boolean Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::m_FirstFrameHappened
	bool ___m_FirstFrameHappened_5;
};

// UnityEngine.Vector4
struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 
{
	// System.Single UnityEngine.Vector4::x
	float ___x_1;
	// System.Single UnityEngine.Vector4::y
	float ___y_2;
	// System.Single UnityEngine.Vector4::z
	float ___z_3;
	// System.Single UnityEngine.Vector4::w
	float ___w_4;
};

struct Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3_StaticFields
{
	// UnityEngine.Vector4 UnityEngine.Vector4::zeroVector
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___zeroVector_5;
	// UnityEngine.Vector4 UnityEngine.Vector4::oneVector
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___oneVector_6;
	// UnityEngine.Vector4 UnityEngine.Vector4::positiveInfinityVector
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___positiveInfinityVector_7;
	// UnityEngine.Vector4 UnityEngine.Vector4::negativeInfinityVector
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___negativeInfinityVector_8;
};

// System.Void
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};

// UnityEngine.Timeline.TrackAsset/TransientBuildData
struct TransientBuildData_t3BE8EF6B5113561AEE7D53FDF3DB331D39BE194F 
{
	// System.Collections.Generic.List`1<UnityEngine.Timeline.TrackAsset> UnityEngine.Timeline.TrackAsset/TransientBuildData::trackList
	List_1_t6908BEEFB57470CB30420983896AA06BFB8796F0* ___trackList_0;
	// System.Collections.Generic.List`1<UnityEngine.Timeline.TimelineClip> UnityEngine.Timeline.TrackAsset/TransientBuildData::clipList
	List_1_tD78196B4DE777C4B74ADAD24051A9978F5191506* ___clipList_1;
	// System.Collections.Generic.List`1<UnityEngine.Timeline.IMarker> UnityEngine.Timeline.TrackAsset/TransientBuildData::markerList
	List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF* ___markerList_2;
};
// Native definition for P/Invoke marshalling of UnityEngine.Timeline.TrackAsset/TransientBuildData
struct TransientBuildData_t3BE8EF6B5113561AEE7D53FDF3DB331D39BE194F_marshaled_pinvoke
{
	List_1_t6908BEEFB57470CB30420983896AA06BFB8796F0* ___trackList_0;
	List_1_tD78196B4DE777C4B74ADAD24051A9978F5191506* ___clipList_1;
	List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF* ___markerList_2;
};
// Native definition for COM marshalling of UnityEngine.Timeline.TrackAsset/TransientBuildData
struct TransientBuildData_t3BE8EF6B5113561AEE7D53FDF3DB331D39BE194F_marshaled_com
{
	List_1_t6908BEEFB57470CB30420983896AA06BFB8796F0* ___trackList_0;
	List_1_tD78196B4DE777C4B74ADAD24051A9978F5191506* ___clipList_1;
	List_1_tB481045C42962DD282E8A89B2AF0246A4042EADF* ___markerList_2;
};

// System.Delegate
struct Delegate_t  : public RuntimeObject
{
	// System.IntPtr System.Delegate::method_ptr
	Il2CppMethodPointer ___method_ptr_0;
	// System.IntPtr System.Delegate::invoke_impl
	intptr_t ___invoke_impl_1;
	// System.Object System.Delegate::m_target
	RuntimeObject* ___m_target_2;
	// System.IntPtr System.Delegate::method
	intptr_t ___method_3;
	// System.IntPtr System.Delegate::delegate_trampoline
	intptr_t ___delegate_trampoline_4;
	// System.IntPtr System.Delegate::extra_arg
	intptr_t ___extra_arg_5;
	// System.IntPtr System.Delegate::method_code
	intptr_t ___method_code_6;
	// System.IntPtr System.Delegate::interp_method
	intptr_t ___interp_method_7;
	// System.IntPtr System.Delegate::interp_invoke_impl
	intptr_t ___interp_invoke_impl_8;
	// System.Reflection.MethodInfo System.Delegate::method_info
	MethodInfo_t* ___method_info_9;
	// System.Reflection.MethodInfo System.Delegate::original_method_info
	MethodInfo_t* ___original_method_info_10;
	// System.DelegateData System.Delegate::data
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	// System.Boolean System.Delegate::method_is_virtual
	bool ___method_is_virtual_12;
};
// Native definition for P/Invoke marshalling of System.Delegate
struct Delegate_t_marshaled_pinvoke
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};
// Native definition for COM marshalling of System.Delegate
struct Delegate_t_marshaled_com
{
	intptr_t ___method_ptr_0;
	intptr_t ___invoke_impl_1;
	Il2CppIUnknown* ___m_target_2;
	intptr_t ___method_3;
	intptr_t ___delegate_trampoline_4;
	intptr_t ___extra_arg_5;
	intptr_t ___method_code_6;
	intptr_t ___interp_method_7;
	intptr_t ___interp_invoke_impl_8;
	MethodInfo_t* ___method_info_9;
	MethodInfo_t* ___original_method_info_10;
	DelegateData_t9B286B493293CD2D23A5B2B5EF0E5B1324C2B77E* ___data_11;
	int32_t ___method_is_virtual_12;
};

// UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C  : public RuntimeObject
{
	// System.IntPtr UnityEngine.Object::m_CachedPtr
	intptr_t ___m_CachedPtr_0;
};

struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_StaticFields
{
	// System.Int32 UnityEngine.Object::OffsetOfInstanceIDInCPlusPlusObject
	int32_t ___OffsetOfInstanceIDInCPlusPlusObject_1;
};
// Native definition for P/Invoke marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
	intptr_t ___m_CachedPtr_0;
};
// Native definition for COM marshalling of UnityEngine.Object
struct Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
	intptr_t ___m_CachedPtr_0;
};

// UnityEngine.Playables.PlayableGraph
struct PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E 
{
	// System.IntPtr UnityEngine.Playables.PlayableGraph::m_Handle
	intptr_t ___m_Handle_0;
	// System.UInt32 UnityEngine.Playables.PlayableGraph::m_Version
	uint32_t ___m_Version_1;
};

// UnityEngine.Playables.PlayableHandle
struct PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 
{
	// System.IntPtr UnityEngine.Playables.PlayableHandle::m_Handle
	intptr_t ___m_Handle_0;
	// System.UInt32 UnityEngine.Playables.PlayableHandle::m_Version
	uint32_t ___m_Version_1;
};

struct PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4_StaticFields
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.PlayableHandle::m_Null
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Null_2;
};

// UnityEngine.Playables.PlayableOutputHandle
struct PlayableOutputHandle_tEB217645A8C0356A3AC6F964F283003B9740E883 
{
	// System.IntPtr UnityEngine.Playables.PlayableOutputHandle::m_Handle
	intptr_t ___m_Handle_0;
	// System.UInt32 UnityEngine.Playables.PlayableOutputHandle::m_Version
	uint32_t ___m_Version_1;
};

struct PlayableOutputHandle_tEB217645A8C0356A3AC6F964F283003B9740E883_StaticFields
{
	// UnityEngine.Playables.PlayableOutputHandle UnityEngine.Playables.PlayableOutputHandle::m_Null
	PlayableOutputHandle_tEB217645A8C0356A3AC6F964F283003B9740E883 ___m_Null_2;
};

// UnityEngine.Playables.ScriptPlayable`1<System.Object>
struct ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.ScriptPlayable`1::m_Handle
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle_0;
};

struct ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_StaticFields
{
	// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1::m_NullPlayable
	ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___m_NullPlayable_1;
};

// UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>
struct ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.ScriptPlayable`1::m_Handle
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle_0;
};

struct ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_StaticFields
{
	// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1::m_NullPlayable
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 ___m_NullPlayable_1;
};

// UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateMixerBehaviour>
struct ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D 
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.ScriptPlayable`1::m_Handle
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle_0;
};

struct ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_StaticFields
{
	// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1::m_NullPlayable
	ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D ___m_NullPlayable_1;
};

// UnityEngine.Playables.ScriptPlayable`1<SpineSkeletonFlipBehaviour>
struct ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.ScriptPlayable`1::m_Handle
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle_0;
};

struct ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_StaticFields
{
	// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1::m_NullPlayable
	ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 ___m_NullPlayable_1;
};

// UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour>
struct ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB 
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.ScriptPlayable`1::m_Handle
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle_0;
};

struct ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB_StaticFields
{
	// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1::m_NullPlayable
	ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB ___m_NullPlayable_1;
};

// UnityEngine.Component
struct Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// UnityEngine.GameObject
struct GameObject_t76FEDD663AB33C991A9C9A23129337651094216F  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};

// System.MulticastDelegate
struct MulticastDelegate_t  : public Delegate_t
{
	// System.Delegate[] System.MulticastDelegate::delegates
	DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771* ___delegates_13;
};
// Native definition for P/Invoke marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_pinvoke : public Delegate_t_marshaled_pinvoke
{
	Delegate_t_marshaled_pinvoke** ___delegates_13;
};
// Native definition for COM marshalling of System.MulticastDelegate
struct MulticastDelegate_t_marshaled_com : public Delegate_t_marshaled_com
{
	Delegate_t_marshaled_com** ___delegates_13;
};

// UnityEngine.Playables.Playable
struct Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F 
{
	// UnityEngine.Playables.PlayableHandle UnityEngine.Playables.Playable::m_Handle
	PlayableHandle_t5D6A01EF94382EFEDC047202F71DF882769654D4 ___m_Handle_0;
};

struct Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_StaticFields
{
	// UnityEngine.Playables.Playable UnityEngine.Playables.Playable::m_NullPlayable
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___m_NullPlayable_1;
};

// UnityEngine.Playables.PlayableOutput
struct PlayableOutput_t2F7C45A58DA3E788EEDDB439549E21CF3FCF3680 
{
	// UnityEngine.Playables.PlayableOutputHandle UnityEngine.Playables.PlayableOutput::m_Handle
	PlayableOutputHandle_tEB217645A8C0356A3AC6F964F283003B9740E883 ___m_Handle_0;
};

struct PlayableOutput_t2F7C45A58DA3E788EEDDB439549E21CF3FCF3680_StaticFields
{
	// UnityEngine.Playables.PlayableOutput UnityEngine.Playables.PlayableOutput::m_NullPlayableOutput
	PlayableOutput_t2F7C45A58DA3E788EEDDB439549E21CF3FCF3680 ___m_NullPlayableOutput_1;
};

// UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A  : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C
{
};
// Native definition for P/Invoke marshalling of UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_pinvoke : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_pinvoke
{
};
// Native definition for COM marshalling of UnityEngine.ScriptableObject
struct ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A_marshaled_com : public Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_marshaled_com
{
};

// Spine.Unity.AnimationReferenceAsset
struct AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	// Spine.Unity.SkeletonDataAsset Spine.Unity.AnimationReferenceAsset::skeletonDataAsset
	SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* ___skeletonDataAsset_5;
	// System.String Spine.Unity.AnimationReferenceAsset::animationName
	String_t* ___animationName_6;
	// Spine.Animation Spine.Unity.AnimationReferenceAsset::animation
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___animation_7;
};

// System.AsyncCallback
struct AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C  : public MulticastDelegate_t
{
};

// UnityEngine.Behaviour
struct Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA  : public Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3
{
};

// UnityEngine.Playables.FrameData
struct FrameData_t02E705D0271F73A24ADF9BA4B6F8760B6696F314 
{
	// System.UInt64 UnityEngine.Playables.FrameData::m_FrameID
	uint64_t ___m_FrameID_0;
	// System.Double UnityEngine.Playables.FrameData::m_DeltaTime
	double ___m_DeltaTime_1;
	// System.Single UnityEngine.Playables.FrameData::m_Weight
	float ___m_Weight_2;
	// System.Single UnityEngine.Playables.FrameData::m_EffectiveWeight
	float ___m_EffectiveWeight_3;
	// System.Double UnityEngine.Playables.FrameData::m_EffectiveParentDelay
	double ___m_EffectiveParentDelay_4;
	// System.Single UnityEngine.Playables.FrameData::m_EffectiveParentSpeed
	float ___m_EffectiveParentSpeed_5;
	// System.Single UnityEngine.Playables.FrameData::m_EffectiveSpeed
	float ___m_EffectiveSpeed_6;
	// UnityEngine.Playables.FrameData/Flags UnityEngine.Playables.FrameData::m_Flags
	int32_t ___m_Flags_7;
	// UnityEngine.Playables.PlayableOutput UnityEngine.Playables.FrameData::m_Output
	PlayableOutput_t2F7C45A58DA3E788EEDDB439549E21CF3FCF3680 ___m_Output_8;
};

// UnityEngine.Playables.PlayableAsset
struct PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
};

// Spine.Unity.SkeletonDataAsset
struct SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F  : public ScriptableObject_tB3BFDB921A1B1795B38A5417D3B97A89A140436A
{
	// Spine.Unity.AtlasAssetBase[] Spine.Unity.SkeletonDataAsset::atlasAssets
	AtlasAssetBaseU5BU5D_t6D8EAEA3267D1DFC3FBFAA3ECE699B48E92E5C82* ___atlasAssets_4;
	// System.Single Spine.Unity.SkeletonDataAsset::scale
	float ___scale_5;
	// UnityEngine.TextAsset Spine.Unity.SkeletonDataAsset::skeletonJSON
	TextAsset_t2C64E93DA366D9DE5A8209E1802FA4884AC1BD69* ___skeletonJSON_6;
	// System.Boolean Spine.Unity.SkeletonDataAsset::isUpgradingBlendModeMaterials
	bool ___isUpgradingBlendModeMaterials_7;
	// Spine.Unity.BlendModeMaterials Spine.Unity.SkeletonDataAsset::blendModeMaterials
	BlendModeMaterials_t3DA4B85DB36B60D661B6403BD49E7D62F56B81D8* ___blendModeMaterials_8;
	// System.Collections.Generic.List`1<Spine.Unity.SkeletonDataModifierAsset> Spine.Unity.SkeletonDataAsset::skeletonDataModifiers
	List_1_tBFA73B26AF72BABC85549F091C4BA5A95B9FB412* ___skeletonDataModifiers_9;
	// System.String[] Spine.Unity.SkeletonDataAsset::fromAnimation
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___fromAnimation_10;
	// System.String[] Spine.Unity.SkeletonDataAsset::toAnimation
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___toAnimation_11;
	// System.Single[] Spine.Unity.SkeletonDataAsset::duration
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* ___duration_12;
	// System.Single Spine.Unity.SkeletonDataAsset::defaultMix
	float ___defaultMix_13;
	// UnityEngine.RuntimeAnimatorController Spine.Unity.SkeletonDataAsset::controller
	RuntimeAnimatorController_t6F7C753402B42EC23C163099CF935C5E0D7A7254* ___controller_14;
	// Spine.SkeletonData Spine.Unity.SkeletonDataAsset::skeletonData
	SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* ___skeletonData_15;
	// Spine.AnimationStateData Spine.Unity.SkeletonDataAsset::stateData
	AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* ___stateData_16;
};

// Spine.Unity.Playables.SpineEventDelegate
struct SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C  : public MulticastDelegate_t
{
};

// UnityEngine.MonoBehaviour
struct MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
};

// UnityEngine.Playables.PlayableDirector
struct PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475  : public Behaviour_t01970CFBBA658497AE30F311C447DB0440BAB7FA
{
	// System.Action`1<UnityEngine.Playables.PlayableDirector> UnityEngine.Playables.PlayableDirector::played
	Action_1_tB645F646DB079054A9500B09427CB02A88372D3F* ___played_4;
	// System.Action`1<UnityEngine.Playables.PlayableDirector> UnityEngine.Playables.PlayableDirector::paused
	Action_1_tB645F646DB079054A9500B09427CB02A88372D3F* ___paused_5;
	// System.Action`1<UnityEngine.Playables.PlayableDirector> UnityEngine.Playables.PlayableDirector::stopped
	Action_1_tB645F646DB079054A9500B09427CB02A88372D3F* ___stopped_6;
};

// Spine.Unity.Playables.SpineAnimationStateClip
struct SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A  : public PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E
{
	// Spine.Unity.Playables.SpineAnimationStateBehaviour Spine.Unity.Playables.SpineAnimationStateClip::template
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* ___template_4;
};

// SpineSkeletonFlipClip
struct SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1  : public PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E
{
	// SpineSkeletonFlipBehaviour SpineSkeletonFlipClip::template
	SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* ___template_4;
};

// UnityEngine.Timeline.TrackAsset
struct TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96  : public PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E
{
	// System.Int32 UnityEngine.Timeline.TrackAsset::m_Version
	int32_t ___m_Version_5;
	// UnityEngine.AnimationClip UnityEngine.Timeline.TrackAsset::m_AnimClip
	AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712* ___m_AnimClip_6;
	// System.Boolean UnityEngine.Timeline.TrackAsset::m_Locked
	bool ___m_Locked_11;
	// System.Boolean UnityEngine.Timeline.TrackAsset::m_Muted
	bool ___m_Muted_12;
	// System.String UnityEngine.Timeline.TrackAsset::m_CustomPlayableFullTypename
	String_t* ___m_CustomPlayableFullTypename_13;
	// UnityEngine.AnimationClip UnityEngine.Timeline.TrackAsset::m_Curves
	AnimationClip_t00BD2F131D308A4AD2C6B0BF66644FC25FECE712* ___m_Curves_14;
	// UnityEngine.Playables.PlayableAsset UnityEngine.Timeline.TrackAsset::m_Parent
	PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E* ___m_Parent_15;
	// System.Collections.Generic.List`1<UnityEngine.ScriptableObject> UnityEngine.Timeline.TrackAsset::m_Children
	List_1_tF941E9C3FEB6F1C2D20E73A90AA7F6319EB3F828* ___m_Children_16;
	// System.Int32 UnityEngine.Timeline.TrackAsset::m_ItemsHash
	int32_t ___m_ItemsHash_17;
	// UnityEngine.Timeline.TimelineClip[] UnityEngine.Timeline.TrackAsset::m_ClipsCache
	TimelineClipU5BU5D_t37945156A55BC896C442C4FE59198216769A4E64* ___m_ClipsCache_18;
	// UnityEngine.Timeline.DiscreteTime UnityEngine.Timeline.TrackAsset::m_Start
	DiscreteTime_t1598D60B0B2432F702E2A6120D04369EE54600A6 ___m_Start_19;
	// UnityEngine.Timeline.DiscreteTime UnityEngine.Timeline.TrackAsset::m_End
	DiscreteTime_t1598D60B0B2432F702E2A6120D04369EE54600A6 ___m_End_20;
	// System.Boolean UnityEngine.Timeline.TrackAsset::m_CacheSorted
	bool ___m_CacheSorted_21;
	// System.Nullable`1<System.Boolean> UnityEngine.Timeline.TrackAsset::m_SupportsNotifications
	Nullable_1_t78F453FADB4A9F50F267A4E349019C34410D1A01 ___m_SupportsNotifications_22;
	// System.Collections.Generic.IEnumerable`1<UnityEngine.Timeline.TrackAsset> UnityEngine.Timeline.TrackAsset::m_ChildTrackCache
	RuntimeObject* ___m_ChildTrackCache_24;
	// System.Collections.Generic.List`1<UnityEngine.Timeline.TimelineClip> UnityEngine.Timeline.TrackAsset::m_Clips
	List_1_tD78196B4DE777C4B74ADAD24051A9978F5191506* ___m_Clips_26;
	// UnityEngine.Timeline.MarkerList UnityEngine.Timeline.TrackAsset::m_Markers
	MarkerList_tD4B632EBA98CE678EB8D108A1AF559F734FA7698 ___m_Markers_27;
};

struct TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_StaticFields
{
	// UnityEngine.Timeline.TrackAsset/TransientBuildData UnityEngine.Timeline.TrackAsset::s_BuildData
	TransientBuildData_t3BE8EF6B5113561AEE7D53FDF3DB331D39BE194F ___s_BuildData_7;
	// System.Action`3<UnityEngine.Timeline.TimelineClip,UnityEngine.GameObject,UnityEngine.Playables.Playable> UnityEngine.Timeline.TrackAsset::OnClipPlayableCreate
	Action_3_t3638A0A401CA68AF6FECFB956B602BBF7B9EFA72* ___OnClipPlayableCreate_9;
	// System.Action`3<UnityEngine.Timeline.TrackAsset,UnityEngine.GameObject,UnityEngine.Playables.Playable> UnityEngine.Timeline.TrackAsset::OnTrackAnimationPlayableCreate
	Action_3_t8A9161BC98843636E3BF066B37CBCC15C593B73E* ___OnTrackAnimationPlayableCreate_10;
	// UnityEngine.Timeline.TrackAsset[] UnityEngine.Timeline.TrackAsset::s_EmptyCache
	TrackAssetU5BU5D_tE6935AFD32D0BE4B0C69D1CCE96B55D383BCF88C* ___s_EmptyCache_23;
	// System.Collections.Generic.Dictionary`2<System.Type,UnityEngine.Timeline.TrackBindingTypeAttribute> UnityEngine.Timeline.TrackAsset::s_TrackBindingTypeAttributeCache
	Dictionary_2_tF0368534E8881FC0469B58E4901741C5B0CC1D79* ___s_TrackBindingTypeAttributeCache_25;
};

// Spine.Unity.SkeletonRenderer
struct SkeletonRenderer_t6D14A218C3A502F075DC4C4423EE2ACEBFEB620A  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// Spine.Unity.SkeletonDataAsset Spine.Unity.SkeletonRenderer::skeletonDataAsset
	SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* ___skeletonDataAsset_4;
	// System.String Spine.Unity.SkeletonRenderer::initialSkinName
	String_t* ___initialSkinName_5;
	// System.Boolean Spine.Unity.SkeletonRenderer::initialFlipX
	bool ___initialFlipX_6;
	// System.Boolean Spine.Unity.SkeletonRenderer::initialFlipY
	bool ___initialFlipY_7;
	// Spine.Unity.UpdateMode Spine.Unity.SkeletonRenderer::updateMode
	int32_t ___updateMode_8;
	// Spine.Unity.UpdateMode Spine.Unity.SkeletonRenderer::updateWhenInvisible
	int32_t ___updateWhenInvisible_9;
	// System.String[] Spine.Unity.SkeletonRenderer::separatorSlotNames
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___separatorSlotNames_10;
	// System.Collections.Generic.List`1<Spine.Slot> Spine.Unity.SkeletonRenderer::separatorSlots
	List_1_t75CC7DC5981BB1205F28E94CAC72B41781A3E0D4* ___separatorSlots_11;
	// System.Single Spine.Unity.SkeletonRenderer::zSpacing
	float ___zSpacing_12;
	// System.Boolean Spine.Unity.SkeletonRenderer::useClipping
	bool ___useClipping_13;
	// System.Boolean Spine.Unity.SkeletonRenderer::immutableTriangles
	bool ___immutableTriangles_14;
	// System.Boolean Spine.Unity.SkeletonRenderer::pmaVertexColors
	bool ___pmaVertexColors_15;
	// System.Boolean Spine.Unity.SkeletonRenderer::clearStateOnDisable
	bool ___clearStateOnDisable_16;
	// System.Boolean Spine.Unity.SkeletonRenderer::tintBlack
	bool ___tintBlack_17;
	// System.Boolean Spine.Unity.SkeletonRenderer::singleSubmesh
	bool ___singleSubmesh_18;
	// System.Boolean Spine.Unity.SkeletonRenderer::fixDrawOrder
	bool ___fixDrawOrder_19;
	// System.Boolean Spine.Unity.SkeletonRenderer::addNormals
	bool ___addNormals_20;
	// System.Boolean Spine.Unity.SkeletonRenderer::calculateTangents
	bool ___calculateTangents_21;
	// UnityEngine.SpriteMaskInteraction Spine.Unity.SkeletonRenderer::maskInteraction
	int32_t ___maskInteraction_22;
	// Spine.Unity.SkeletonRenderer/SpriteMaskInteractionMaterials Spine.Unity.SkeletonRenderer::maskMaterials
	SpriteMaskInteractionMaterials_tF9C97C34FC619F4BCF4E47C16262899351C10720* ___maskMaterials_23;
	// System.Boolean Spine.Unity.SkeletonRenderer::disableRenderingOnOverride
	bool ___disableRenderingOnOverride_28;
	// Spine.Unity.SkeletonRenderer/InstructionDelegate Spine.Unity.SkeletonRenderer::generateMeshOverride
	InstructionDelegate_t751C3C0C3012ADBD85CD298FF1DCCDE3541B57B6* ___generateMeshOverride_29;
	// Spine.Unity.MeshGeneratorDelegate Spine.Unity.SkeletonRenderer::OnPostProcessVertices
	MeshGeneratorDelegate_t799773C2F6BEC0D47D27646DB0FBE22A28821E8B* ___OnPostProcessVertices_30;
	// System.Collections.Generic.Dictionary`2<UnityEngine.Material,UnityEngine.Material> Spine.Unity.SkeletonRenderer::customMaterialOverride
	Dictionary_2_t7B0F5D63DDA1E532530982C8043F0A132FF9745F* ___customMaterialOverride_31;
	// System.Collections.Generic.Dictionary`2<Spine.Slot,UnityEngine.Material> Spine.Unity.SkeletonRenderer::customSlotMaterials
	Dictionary_2_tF46BBFD2B39F05EA43825A1BD4B99EADEDE994D4* ___customSlotMaterials_32;
	// Spine.Unity.SkeletonRendererInstruction Spine.Unity.SkeletonRenderer::currentInstructions
	SkeletonRendererInstruction_t7EBEBDCF3450913487EE58F1C3F0A0E084A51163* ___currentInstructions_33;
	// Spine.Unity.MeshGenerator Spine.Unity.SkeletonRenderer::meshGenerator
	MeshGenerator_t754492D79919D913B93BE05E83D270CEACAC392C* ___meshGenerator_34;
	// Spine.Unity.MeshRendererBuffers Spine.Unity.SkeletonRenderer::rendererBuffers
	MeshRendererBuffers_tB9308AD2A53E8B70963EF29DBF88716A6BBE567B* ___rendererBuffers_35;
	// UnityEngine.MeshRenderer Spine.Unity.SkeletonRenderer::meshRenderer
	MeshRenderer_t4B7747212F0B88244BB7790C61AE124BFC15BAAE* ___meshRenderer_36;
	// UnityEngine.MeshFilter Spine.Unity.SkeletonRenderer::meshFilter
	MeshFilter_t6D1CE2473A1E45AC73013400585A1163BF66B2F5* ___meshFilter_37;
	// System.Boolean Spine.Unity.SkeletonRenderer::valid
	bool ___valid_38;
	// Spine.Skeleton Spine.Unity.SkeletonRenderer::skeleton
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton_39;
	// Spine.Unity.SkeletonRenderer/SkeletonRendererDelegate Spine.Unity.SkeletonRenderer::OnRebuild
	SkeletonRendererDelegate_t8DAF5E58107FFA0E1E02F3869D004088226BF4F7* ___OnRebuild_40;
	// Spine.Unity.SkeletonRenderer/SkeletonRendererDelegate Spine.Unity.SkeletonRenderer::OnMeshAndMaterialsUpdated
	SkeletonRendererDelegate_t8DAF5E58107FFA0E1E02F3869D004088226BF4F7* ___OnMeshAndMaterialsUpdated_41;
	// UnityEngine.MaterialPropertyBlock Spine.Unity.SkeletonRenderer::reusedPropertyBlock
	MaterialPropertyBlock_t2308669579033A857EFE6E4831909F638B27411D* ___reusedPropertyBlock_42;
};

struct SkeletonRenderer_t6D14A218C3A502F075DC4C4423EE2ACEBFEB620A_StaticFields
{
	// System.Int32 Spine.Unity.SkeletonRenderer::STENCIL_COMP_PARAM_ID
	int32_t ___STENCIL_COMP_PARAM_ID_24;
	// System.Int32 Spine.Unity.SkeletonRenderer::SUBMESH_DUMMY_PARAM_ID
	int32_t ___SUBMESH_DUMMY_PARAM_ID_43;
};

// Spine.Unity.Playables.SpineAnimationStateGraphicTrack
struct SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88  : public TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96
{
	// System.Int32 Spine.Unity.Playables.SpineAnimationStateGraphicTrack::trackIndex
	int32_t ___trackIndex_28;
};

// Spine.Unity.Playables.SpineAnimationStateTrack
struct SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3  : public TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96
{
	// System.Int32 Spine.Unity.Playables.SpineAnimationStateTrack::trackIndex
	int32_t ___trackIndex_28;
};

// Spine.Unity.Playables.SpinePlayableHandleBase
struct SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
	// Spine.Unity.Playables.SpineEventDelegate Spine.Unity.Playables.SpinePlayableHandleBase::AnimationEvents
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* ___AnimationEvents_4;
};

// Spine.Unity.Playables.SpineSkeletonFlipTrack
struct SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0  : public TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96
{
};

// UnityEngine.EventSystems.UIBehaviour
struct UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D  : public MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71
{
};

// UnityEngine.UI.Graphic
struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931  : public UIBehaviour_tB9D4295827BD2EEDEF0749200C6CA7090C742A9D
{
	// UnityEngine.Material UnityEngine.UI.Graphic::m_Material
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_Material_6;
	// UnityEngine.Color UnityEngine.UI.Graphic::m_Color
	Color_tD001788D726C3A7F1379BEED0260B9591F440C1F ___m_Color_7;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipLayoutUpdate
	bool ___m_SkipLayoutUpdate_8;
	// System.Boolean UnityEngine.UI.Graphic::m_SkipMaterialUpdate
	bool ___m_SkipMaterialUpdate_9;
	// System.Boolean UnityEngine.UI.Graphic::m_RaycastTarget
	bool ___m_RaycastTarget_10;
	// UnityEngine.Vector4 UnityEngine.UI.Graphic::m_RaycastPadding
	Vector4_t58B63D32F48C0DBF50DE2C60794C4676C80EDBE3 ___m_RaycastPadding_11;
	// UnityEngine.RectTransform UnityEngine.UI.Graphic::m_RectTransform
	RectTransform_t6C5DA5E41A89E0F488B001E45E58963480E543A5* ___m_RectTransform_12;
	// UnityEngine.CanvasRenderer UnityEngine.UI.Graphic::m_CanvasRenderer
	CanvasRenderer_tAB9A55A976C4E3B2B37D0CE5616E5685A8B43860* ___m_CanvasRenderer_13;
	// UnityEngine.Canvas UnityEngine.UI.Graphic::m_Canvas
	Canvas_t2DB4CEFDFF732884866C83F11ABF75F5AE8FFB26* ___m_Canvas_14;
	// System.Boolean UnityEngine.UI.Graphic::m_VertsDirty
	bool ___m_VertsDirty_15;
	// System.Boolean UnityEngine.UI.Graphic::m_MaterialDirty
	bool ___m_MaterialDirty_16;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyLayoutCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyLayoutCallback_17;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyVertsCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyVertsCallback_18;
	// UnityEngine.Events.UnityAction UnityEngine.UI.Graphic::m_OnDirtyMaterialCallback
	UnityAction_t11A1F3B953B365C072A5DCC32677EE1796A962A7* ___m_OnDirtyMaterialCallback_19;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::m_CachedMesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___m_CachedMesh_22;
	// UnityEngine.Vector2[] UnityEngine.UI.Graphic::m_CachedUvs
	Vector2U5BU5D_tFEBBC94BCC6C9C88277BA04047D2B3FDB6ED7FDA* ___m_CachedUvs_23;
	// UnityEngine.UI.CoroutineTween.TweenRunner`1<UnityEngine.UI.CoroutineTween.ColorTween> UnityEngine.UI.Graphic::m_ColorTweenRunner
	TweenRunner_1_t5BB0582F926E75E2FE795492679A6CF55A4B4BC4* ___m_ColorTweenRunner_24;
	// System.Boolean UnityEngine.UI.Graphic::<useLegacyMeshGeneration>k__BackingField
	bool ___U3CuseLegacyMeshGenerationU3Ek__BackingField_25;
};

struct Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931_StaticFields
{
	// UnityEngine.Material UnityEngine.UI.Graphic::s_DefaultUI
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___s_DefaultUI_4;
	// UnityEngine.Texture2D UnityEngine.UI.Graphic::s_WhiteTexture
	Texture2D_tE6505BC111DD8A424A9DBE8E05D7D09E11FFFCF4* ___s_WhiteTexture_5;
	// UnityEngine.Mesh UnityEngine.UI.Graphic::s_Mesh
	Mesh_t6D9C539763A09BC2B12AEAEF36F6DFFC98AE63D4* ___s_Mesh_20;
	// UnityEngine.UI.VertexHelper UnityEngine.UI.Graphic::s_VertexHelper
	VertexHelper_tB905FCB02AE67CBEE5F265FE37A5938FC5D136FE* ___s_VertexHelper_21;
};

// Spine.Unity.SkeletonAnimation
struct SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A  : public SkeletonRenderer_t6D14A218C3A502F075DC4C4423EE2ACEBFEB620A
{
	// Spine.AnimationState Spine.Unity.SkeletonAnimation::state
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* ___state_44;
	// System.Boolean Spine.Unity.SkeletonAnimation::wasUpdatedAfterInit
	bool ___wasUpdatedAfterInit_45;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonAnimation::_BeforeApply
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ____BeforeApply_46;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonAnimation::_UpdateLocal
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ____UpdateLocal_47;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonAnimation::_UpdateWorld
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ____UpdateWorld_48;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonAnimation::_UpdateComplete
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ____UpdateComplete_49;
	// System.String Spine.Unity.SkeletonAnimation::_animationName
	String_t* ____animationName_50;
	// System.Boolean Spine.Unity.SkeletonAnimation::loop
	bool ___loop_51;
	// System.Single Spine.Unity.SkeletonAnimation::timeScale
	float ___timeScale_52;
};

// Spine.Unity.Playables.SkeletonAnimationPlayableHandle
struct SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2  : public SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570
{
	// Spine.Unity.SkeletonAnimation Spine.Unity.Playables.SkeletonAnimationPlayableHandle::skeletonAnimation
	SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* ___skeletonAnimation_5;
};

// Spine.Unity.Playables.SkeletonGraphicPlayableHandle
struct SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA  : public SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570
{
	// Spine.Unity.SkeletonGraphic Spine.Unity.Playables.SkeletonGraphicPlayableHandle::skeletonGraphic
	SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* ___skeletonGraphic_5;
};

// UnityEngine.UI.MaskableGraphic
struct MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E  : public Graphic_tCBFCA4585A19E2B75465AECFEAC43F4016BF7931
{
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculateStencil
	bool ___m_ShouldRecalculateStencil_26;
	// UnityEngine.Material UnityEngine.UI.MaskableGraphic::m_MaskMaterial
	Material_t18053F08F347D0DCA5E1140EC7EC4533DD8A14E3* ___m_MaskMaterial_27;
	// UnityEngine.UI.RectMask2D UnityEngine.UI.MaskableGraphic::m_ParentMask
	RectMask2D_tACF92BE999C791A665BD1ADEABF5BCEB82846670* ___m_ParentMask_28;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_Maskable
	bool ___m_Maskable_29;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IsMaskingGraphic
	bool ___m_IsMaskingGraphic_30;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_IncludeForMasking
	bool ___m_IncludeForMasking_31;
	// UnityEngine.UI.MaskableGraphic/CullStateChangedEvent UnityEngine.UI.MaskableGraphic::m_OnCullStateChanged
	CullStateChangedEvent_t6073CD0D951EC1256BF74B8F9107D68FC89B99B8* ___m_OnCullStateChanged_32;
	// System.Boolean UnityEngine.UI.MaskableGraphic::m_ShouldRecalculate
	bool ___m_ShouldRecalculate_33;
	// System.Int32 UnityEngine.UI.MaskableGraphic::m_StencilValue
	int32_t ___m_StencilValue_34;
	// UnityEngine.Vector3[] UnityEngine.UI.MaskableGraphic::m_Corners
	Vector3U5BU5D_tFF1859CCE176131B909E2044F76443064254679C* ___m_Corners_35;
};

// Spine.Unity.SkeletonGraphic
struct SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1  : public MaskableGraphic_tFC5B6BE351C90DE53744DF2A70940242774B361E
{
	// Spine.Unity.SkeletonDataAsset Spine.Unity.SkeletonGraphic::skeletonDataAsset
	SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* ___skeletonDataAsset_36;
	// System.String Spine.Unity.SkeletonGraphic::initialSkinName
	String_t* ___initialSkinName_37;
	// System.Boolean Spine.Unity.SkeletonGraphic::initialFlipX
	bool ___initialFlipX_38;
	// System.Boolean Spine.Unity.SkeletonGraphic::initialFlipY
	bool ___initialFlipY_39;
	// System.String Spine.Unity.SkeletonGraphic::startingAnimation
	String_t* ___startingAnimation_40;
	// System.Boolean Spine.Unity.SkeletonGraphic::startingLoop
	bool ___startingLoop_41;
	// System.Single Spine.Unity.SkeletonGraphic::timeScale
	float ___timeScale_42;
	// System.Boolean Spine.Unity.SkeletonGraphic::freeze
	bool ___freeze_43;
	// Spine.Unity.UpdateMode Spine.Unity.SkeletonGraphic::updateMode
	int32_t ___updateMode_44;
	// Spine.Unity.UpdateMode Spine.Unity.SkeletonGraphic::updateWhenInvisible
	int32_t ___updateWhenInvisible_45;
	// System.Boolean Spine.Unity.SkeletonGraphic::unscaledTime
	bool ___unscaledTime_46;
	// System.Boolean Spine.Unity.SkeletonGraphic::allowMultipleCanvasRenderers
	bool ___allowMultipleCanvasRenderers_47;
	// System.Collections.Generic.List`1<UnityEngine.CanvasRenderer> Spine.Unity.SkeletonGraphic::canvasRenderers
	List_1_tF927985772F2034B6D3251636D0EA26C950BE569* ___canvasRenderers_48;
	// System.Collections.Generic.List`1<UnityEngine.UI.RawImage> Spine.Unity.SkeletonGraphic::rawImages
	List_1_t8F8EC453709D820AD028F01D85A01A31FB4B1B52* ___rawImages_49;
	// System.Int32 Spine.Unity.SkeletonGraphic::usedRenderersCount
	int32_t ___usedRenderersCount_50;
	// System.String[] Spine.Unity.SkeletonGraphic::separatorSlotNames
	StringU5BU5D_t7674CD946EC0CE7B3AE0BE70E6EE85F2ECD9F248* ___separatorSlotNames_52;
	// System.Collections.Generic.List`1<Spine.Slot> Spine.Unity.SkeletonGraphic::separatorSlots
	List_1_t75CC7DC5981BB1205F28E94CAC72B41781A3E0D4* ___separatorSlots_53;
	// System.Boolean Spine.Unity.SkeletonGraphic::enableSeparatorSlots
	bool ___enableSeparatorSlots_54;
	// System.Collections.Generic.List`1<UnityEngine.Transform> Spine.Unity.SkeletonGraphic::separatorParts
	List_1_t991BBC5A1D51F59A450367DF944DAA207F22D06D* ___separatorParts_55;
	// System.Boolean Spine.Unity.SkeletonGraphic::updateSeparatorPartLocation
	bool ___updateSeparatorPartLocation_56;
	// System.Boolean Spine.Unity.SkeletonGraphic::wasUpdatedAfterInit
	bool ___wasUpdatedAfterInit_57;
	// UnityEngine.Texture Spine.Unity.SkeletonGraphic::baseTexture
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___baseTexture_58;
	// System.Collections.Generic.Dictionary`2<UnityEngine.Texture,UnityEngine.Texture> Spine.Unity.SkeletonGraphic::customTextureOverride
	Dictionary_2_t5BE8DFCD10ADA75C178B92A43A8FF7EE49D7E610* ___customTextureOverride_59;
	// System.Collections.Generic.Dictionary`2<UnityEngine.Texture,UnityEngine.Material> Spine.Unity.SkeletonGraphic::customMaterialOverride
	Dictionary_2_t0EB522A36CBFB73E1DB8B66A87752EA513361ACD* ___customMaterialOverride_60;
	// UnityEngine.Texture Spine.Unity.SkeletonGraphic::overrideTexture
	Texture_t791CBB51219779964E0E8A2ED7C1AA5F92A4A700* ___overrideTexture_61;
	// Spine.Skeleton Spine.Unity.SkeletonGraphic::skeleton
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton_62;
	// Spine.Unity.SkeletonGraphic/SkeletonRendererDelegate Spine.Unity.SkeletonGraphic::OnRebuild
	SkeletonRendererDelegate_tF00A46D09906FA01EB8DC11B3306FE0E7C3A8A1C* ___OnRebuild_63;
	// Spine.Unity.SkeletonGraphic/SkeletonRendererDelegate Spine.Unity.SkeletonGraphic::OnMeshAndMaterialsUpdated
	SkeletonRendererDelegate_tF00A46D09906FA01EB8DC11B3306FE0E7C3A8A1C* ___OnMeshAndMaterialsUpdated_64;
	// Spine.AnimationState Spine.Unity.SkeletonGraphic::state
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* ___state_65;
	// Spine.Unity.MeshGenerator Spine.Unity.SkeletonGraphic::meshGenerator
	MeshGenerator_t754492D79919D913B93BE05E83D270CEACAC392C* ___meshGenerator_66;
	// Spine.Unity.DoubleBuffered`1<Spine.Unity.MeshRendererBuffers/SmartMesh> Spine.Unity.SkeletonGraphic::meshBuffers
	DoubleBuffered_1_tAA5948FEDBAA5BD58CAE43B2515316D275B074AE* ___meshBuffers_67;
	// Spine.Unity.SkeletonRendererInstruction Spine.Unity.SkeletonGraphic::currentInstructions
	SkeletonRendererInstruction_t7EBEBDCF3450913487EE58F1C3F0A0E084A51163* ___currentInstructions_68;
	// Spine.ExposedList`1<UnityEngine.Mesh> Spine.Unity.SkeletonGraphic::meshes
	ExposedList_1_t06E83C6B69FFBF51FF15EF7A1AB7CC9B674677A2* ___meshes_69;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonGraphic::BeforeApply
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ___BeforeApply_70;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonGraphic::UpdateLocal
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ___UpdateLocal_71;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonGraphic::UpdateWorld
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ___UpdateWorld_72;
	// Spine.Unity.UpdateBonesDelegate Spine.Unity.SkeletonGraphic::UpdateComplete
	UpdateBonesDelegate_tDF212048AB03483AD7CDAA46A3D862E4703361FD* ___UpdateComplete_73;
	// Spine.Unity.MeshGeneratorDelegate Spine.Unity.SkeletonGraphic::OnPostProcessVertices
	MeshGeneratorDelegate_t799773C2F6BEC0D47D27646DB0FBE22A28821E8B* ___OnPostProcessVertices_74;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// System.Delegate[]
struct DelegateU5BU5D_tC5AB7E8F745616680F337909D3A8E6C722CDF771  : public RuntimeArray
{
	ALIGN_FIELD (8) Delegate_t* m_Items[1];

	inline Delegate_t* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Delegate_t* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Delegate_t* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Delegate_t** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Delegate_t* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// Spine.Event[]
struct EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C  : public RuntimeArray
{
	ALIGN_FIELD (8) Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* m_Items[1];

	inline Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};
// System.Single[]
struct SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C  : public RuntimeArray
{
	ALIGN_FIELD (8) float m_Items[1];

	inline float GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline float* GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, float value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
	}
	inline float GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline float* GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, float value)
	{
		m_Items[index] = value;
	}
};
// System.Object[]
struct ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918  : public RuntimeArray
{
	ALIGN_FIELD (8) RuntimeObject* m_Items[1];

	inline RuntimeObject* GetAt(il2cpp_array_size_t index) const
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAt(il2cpp_array_size_t index)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		return m_Items + index;
	}
	inline void SetAt(il2cpp_array_size_t index, RuntimeObject* value)
	{
		IL2CPP_ARRAY_BOUNDS_CHECK(index, (uint32_t)(this)->max_length);
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
	inline RuntimeObject* GetAtUnchecked(il2cpp_array_size_t index) const
	{
		return m_Items[index];
	}
	inline RuntimeObject** GetAddressAtUnchecked(il2cpp_array_size_t index)
	{
		return m_Items + index;
	}
	inline void SetAtUnchecked(il2cpp_array_size_t index, RuntimeObject* value)
	{
		m_Items[index] = value;
		Il2CppCodeGenWriteBarrier((void**)m_Items + index, (void*)value);
	}
};


// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<System.Object>::Create(UnityEngine.Playables.PlayableGraph,T,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ScriptPlayable_1_Create_mCAF6C1AE93353CC333626F054FE86F022BFCB9FA_gshared (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, RuntimeObject* ___template1, int32_t ___inputCount2, const RuntimeMethod* method) ;
// UnityEngine.Playables.Playable UnityEngine.Playables.ScriptPlayable`1<System.Object>::op_Implicit(UnityEngine.Playables.ScriptPlayable`1<T>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ScriptPlayable_1_op_Implicit_m3FD2FD61DA16E18891F5223F509D18DBB614265A_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___playable0, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<System.Object>()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method) ;
// T UnityEngine.Playables.ScriptPlayable`1<System.Object>::GetBehaviour()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* ScriptPlayable_1_GetBehaviour_m86713AAFF1D1F7D4FB370489F71AE4228741EFE8_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000* __this, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<System.Object>::Create(UnityEngine.Playables.PlayableGraph,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ScriptPlayable_1_Create_mA469AA7F23C196EEFBE59D8AD1D800EE8E7B6DB1_gshared (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, int32_t ___inputCount1, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Playables.PlayableExtensions::GetInputCount<UnityEngine.Playables.Playable>(U)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method) ;
// System.Single UnityEngine.Playables.PlayableExtensions::GetInputWeight<UnityEngine.Playables.Playable>(U,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, int32_t ___inputIndex1, const RuntimeMethod* method) ;
// UnityEngine.Playables.Playable UnityEngine.Playables.PlayableExtensions::GetInput<UnityEngine.Playables.Playable>(U,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, int32_t ___inputPort1, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<System.Object>::op_Explicit(UnityEngine.Playables.Playable)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ScriptPlayable_1_op_Explicit_m338A0D445285A5BB298742C0ECEC3D707DF671F9_gshared (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method) ;
// System.Double UnityEngine.Playables.PlayableExtensions::GetTime<UnityEngine.Playables.ScriptPlayable`1<System.Object>>(U)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetTime_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m7CC665FE5EFE4C2D69951BBEE60F21FC080D8439_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___playable0, const RuntimeMethod* method) ;
// System.Double UnityEngine.Playables.PlayableExtensions::GetSpeed<UnityEngine.Playables.ScriptPlayable`1<System.Object>>(U)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double PlayableExtensions_GetSpeed_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m5747BC1DC48D365A5B92532A694B537AE6987B89_gshared (ScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000 ___playable0, const RuntimeMethod* method) ;

// System.Void UnityEngine.Playables.PlayableBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableBehaviour__ctor_mA6202DCD846F0DDFC5963764A404EE8AFABEA23A (PlayableBehaviour_tCCFE023F2CAB1769A3EAB176BD5B0416C54C22E2* __this, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<SpineSkeletonFlipBehaviour>::Create(UnityEngine.Playables.PlayableGraph,T,System.Int32)
inline ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496 (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* ___template1, int32_t ___inputCount2, const RuntimeMethod* method)
{
	return ((  ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 (*) (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E, SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE*, int32_t, const RuntimeMethod*))ScriptPlayable_1_Create_mCAF6C1AE93353CC333626F054FE86F022BFCB9FA_gshared)(___graph0, ___template1, ___inputCount2, method);
}
// UnityEngine.Playables.Playable UnityEngine.Playables.ScriptPlayable`1<SpineSkeletonFlipBehaviour>::op_Implicit(UnityEngine.Playables.ScriptPlayable`1<T>)
inline Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5 (ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 ___playable0, const RuntimeMethod* method)
{
	return ((  Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F (*) (ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22, const RuntimeMethod*))ScriptPlayable_1_op_Implicit_m3FD2FD61DA16E18891F5223F509D18DBB614265A_gshared)(___playable0, method);
}
// System.Void SpineSkeletonFlipBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A (SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* __this, const RuntimeMethod* method) ;
// System.Void UnityEngine.Playables.PlayableAsset::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void PlayableAsset__ctor_m36B842356F02DF323B356BAAF6E3DC59BA9E1AB8 (PlayableAsset_t6964211C3DAE503FEEDD04089ED6B962945D271E* __this, const RuntimeMethod* method) ;
// Spine.Skeleton Spine.Unity.SkeletonRenderer::get_Skeleton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* SkeletonRenderer_get_Skeleton_m4B631F464CF860CC96CB34DF8AF61EE6B4F940BA (SkeletonRenderer_t6D14A218C3A502F075DC4C4423EE2ACEBFEB620A* __this, const RuntimeMethod* method) ;
// Spine.SkeletonData Spine.Skeleton::get_Data()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::InitializeReference()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Equality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___x0, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___y1, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<Spine.Unity.SkeletonAnimation>()
inline SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49 (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Void Spine.Unity.Playables.SpinePlayableHandleBase::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E (SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* __this, const RuntimeMethod* method) ;
// Spine.Skeleton Spine.Unity.SkeletonGraphic::get_Skeleton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* SkeletonGraphic_get_Skeleton_mF8BED82D73B930C6D58A62E787A6DC4DF7055BAF (SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* __this, const RuntimeMethod* method) ;
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::InitializeReference()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) ;
// T UnityEngine.Component::GetComponent<Spine.Unity.SkeletonGraphic>()
inline SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3* __this, const RuntimeMethod* method)
{
	return ((  SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* (*) (Component_t39FBE53E5EFCF4409111FB22C15FF73717632EC3*, const RuntimeMethod*))Component_GetComponent_TisRuntimeObject_m7181F81CAEC2CF53F5D2BC79B7425C16E1F80D33_gshared)(__this, method);
}
// System.Delegate System.Delegate::Combine(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Combine_m8B9D24CED35033C7FC56501DFE650F5CB7FF012C (Delegate_t* ___a0, Delegate_t* ___b1, const RuntimeMethod* method) ;
// System.Delegate System.Delegate::Remove(System.Delegate,System.Delegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Delegate_t* Delegate_Remove_m40506877934EC1AD4ADAE57F5E97AF0BC0F96116 (Delegate_t* ___source0, Delegate_t* ___value1, const RuntimeMethod* method) ;
// System.Void Spine.Unity.Playables.SpineEventDelegate::Invoke(Spine.Event)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_inline (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method) ;
// System.Void UnityEngine.MonoBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E (MonoBehaviour_t532A11E69716D348D8AA7F854AFCBFCB8AD17F71* __this, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>::Create(UnityEngine.Playables.PlayableGraph,T,System.Int32)
inline ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0 (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* ___template1, int32_t ___inputCount2, const RuntimeMethod* method)
{
	return ((  ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 (*) (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E, SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08*, int32_t, const RuntimeMethod*))ScriptPlayable_1_Create_mCAF6C1AE93353CC333626F054FE86F022BFCB9FA_gshared)(___graph0, ___template1, ___inputCount2, method);
}
// T UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>::GetBehaviour()
inline SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58 (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4* __this, const RuntimeMethod* method)
{
	return ((  SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* (*) (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4*, const RuntimeMethod*))ScriptPlayable_1_GetBehaviour_m86713AAFF1D1F7D4FB370489F71AE4228741EFE8_gshared)(__this, method);
}
// UnityEngine.Playables.Playable UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>::op_Implicit(UnityEngine.Playables.ScriptPlayable`1<T>)
inline Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8 (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 ___playable0, const RuntimeMethod* method)
{
	return ((  Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F (*) (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4, const RuntimeMethod*))ScriptPlayable_1_op_Implicit_m3FD2FD61DA16E18891F5223F509D18DBB614265A_gshared)(___playable0, method);
}
// Spine.Animation Spine.Unity.AnimationReferenceAsset::get_Animation()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F (AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* __this, const RuntimeMethod* method) ;
// System.Single Spine.Animation::get_Duration()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Animation_get_Duration_m385D29E0C137F21E8AD0DD9A945C0610AF175632_inline (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* __this, const RuntimeMethod* method) ;
// System.Void Spine.Unity.Playables.SpineAnimationStateBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723 (SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* __this, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateMixerBehaviour>::Create(UnityEngine.Playables.PlayableGraph,System.Int32)
inline ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, int32_t ___inputCount1, const RuntimeMethod* method)
{
	return ((  ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D (*) (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E, int32_t, const RuntimeMethod*))ScriptPlayable_1_Create_mA469AA7F23C196EEFBE59D8AD1D800EE8E7B6DB1_gshared)(___graph0, ___inputCount1, method);
}
// T UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateMixerBehaviour>::GetBehaviour()
inline SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4 (ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D* __this, const RuntimeMethod* method)
{
	return ((  SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* (*) (ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D*, const RuntimeMethod*))ScriptPlayable_1_GetBehaviour_m86713AAFF1D1F7D4FB370489F71AE4228741EFE8_gshared)(__this, method);
}
// UnityEngine.Playables.Playable UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateMixerBehaviour>::op_Implicit(UnityEngine.Playables.ScriptPlayable`1<T>)
inline Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5 (ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D ___playable0, const RuntimeMethod* method)
{
	return ((  Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F (*) (ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D, const RuntimeMethod*))ScriptPlayable_1_op_Implicit_m3FD2FD61DA16E18891F5223F509D18DBB614265A_gshared)(___playable0, method);
}
// System.Void UnityEngine.Timeline.TrackAsset::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A (TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Application::get_isPlaying()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Application_get_isPlaying_m0B3B501E1093739F8887A0DAC5F61D9CB49CC337 (const RuntimeMethod* method) ;
// System.Void Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::PreviewEditModePose(UnityEngine.Playables.Playable,Spine.Unity.ISkeletonComponent,Spine.Unity.IAnimationStateComponent,Spine.Unity.SkeletonAnimation,Spine.Unity.SkeletonGraphic)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584 (SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* __this, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, RuntimeObject* ___skeletonComponent1, RuntimeObject* ___animationStateComponent2, SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* ___skeletonAnimation3, SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* ___skeletonGraphic4, const RuntimeMethod* method) ;
// System.Int32 UnityEngine.Playables.PlayableExtensions::GetInputCount<UnityEngine.Playables.Playable>(U)
inline int32_t PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9 (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method)
{
	return ((  int32_t (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F, const RuntimeMethod*))PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_gshared)(___playable0, method);
}
// System.Single UnityEngine.Playables.PlayableExtensions::GetInputWeight<UnityEngine.Playables.Playable>(U,System.Int32)
inline float PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, int32_t ___inputIndex1, const RuntimeMethod* method)
{
	return ((  float (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F, int32_t, const RuntimeMethod*))PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_gshared)(___playable0, ___inputIndex1, method);
}
// UnityEngine.Playables.Playable UnityEngine.Playables.PlayableExtensions::GetInput<UnityEngine.Playables.Playable>(U,System.Int32)
inline Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, int32_t ___inputPort1, const RuntimeMethod* method)
{
	return ((  Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F, int32_t, const RuntimeMethod*))PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_gshared)(___playable0, ___inputPort1, method);
}
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>::op_Explicit(UnityEngine.Playables.Playable)
inline ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980 (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method)
{
	return ((  ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F, const RuntimeMethod*))ScriptPlayable_1_op_Explicit_m338A0D445285A5BB298742C0ECEC3D707DF671F9_gshared)(___playable0, method);
}
// Spine.AnimationStateData Spine.AnimationState::get_Data()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C_inline (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, const RuntimeMethod* method) ;
// System.Single Spine.AnimationStateData::get_DefaultMix()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float AnimationStateData_get_DefaultMix_m4BDB14E9DF538918293CF58F4D62B7DB49AAB476_inline (AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* __this, const RuntimeMethod* method) ;
// Spine.TrackEntry Spine.AnimationState::SetEmptyAnimation(System.Int32,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* AnimationState_SetEmptyAnimation_m2C660F117296347DFF557578CCC42E7215935656 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, int32_t ___trackIndex0, float ___mixDuration1, const RuntimeMethod* method) ;
// Spine.TrackEntry Spine.AnimationState::SetAnimation(System.Int32,Spine.Animation,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, int32_t ___trackIndex0, Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___animation1, bool ___loop2, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_EventThreshold(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_EventThreshold_mB58AD3053F5C702066F23AE2DBD52F4DD6DE2823_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_DrawOrderThreshold(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_DrawOrderThreshold_mB1343F81A778546FDE7464B66698B838A44F24F3_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Double UnityEngine.Playables.PlayableExtensions::GetTime<UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>>(U)
inline double PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 ___playable0, const RuntimeMethod* method)
{
	return ((  double (*) (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4, const RuntimeMethod*))PlayableExtensions_GetTime_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m7CC665FE5EFE4C2D69951BBEE60F21FC080D8439_gshared)(___playable0, method);
}
// System.Double UnityEngine.Playables.PlayableExtensions::GetSpeed<UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineAnimationStateBehaviour>>(U)
inline double PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 ___playable0, const RuntimeMethod* method)
{
	return ((  double (*) (ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4, const RuntimeMethod*))PlayableExtensions_GetSpeed_TisScriptPlayable_1_t5E80E6495A91412DAAE85DA280EE5A75E2A89000_m5747BC1DC48D365A5B92532A694B537AE6987B89_gshared)(___playable0, method);
}
// System.Void Spine.TrackEntry::set_TrackTime(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_TimeScale(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_TimeScale_m9C6DC53ED8731A1A5A3EE825BEF667BA848A8588_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_AttachmentThreshold(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_AttachmentThreshold_mA75133539615A962566CE1CAAA1FFB9ED49A3DC0_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_HoldPrevious(System.Boolean)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, bool ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_MixDuration(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_MixDuration_m22C7A7BDE2F947A311BC27093C0C5B96B4CA9C55_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Implicit(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___exists0, const RuntimeMethod* method) ;
// System.Void Spine.Unity.SkeletonAnimation::Update(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimation_Update_mA405A7645B8BA03A1CD193F3AE50E1D08FBC19D0 (SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* __this, float ___deltaTime0, const RuntimeMethod* method) ;
// System.Void Spine.Unity.SkeletonGraphic::LateUpdate()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphic_LateUpdate_m6A04288EA0CEDAE3A87FC0BC09E797D70B9D4347 (SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Inequality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___x0, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___y1, const RuntimeMethod* method) ;
// Spine.Unity.SkeletonDataAsset Spine.Unity.AnimationReferenceAsset::get_SkeletonDataAsset()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E_inline (AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* __this, const RuntimeMethod* method) ;
// Spine.SkeletonData Spine.Unity.SkeletonDataAsset::GetSkeletonData(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* SkeletonDataAsset_GetSkeletonData_mCBAFA745AEC7A8191A7FBE1EE05A8A877886832E (SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* __this, bool ___quiet0, const RuntimeMethod* method) ;
// System.Void UnityEngine.Debug::LogWarningFormat(System.String,System.Object[])
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Debug_LogWarningFormat_m0D4A31935564D0FA042103C1231DBBD2ED0BC20A (String_t* ___format0, ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* ___args1, const RuntimeMethod* method) ;
// System.Single Spine.AnimationStateData::GetMix(Spine.Animation,Spine.Animation)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AnimationStateData_GetMix_m1F69969EB5ED5B0523496EEF610D195C756F1C9E (AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* __this, Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___from0, Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___to1, const RuntimeMethod* method) ;
// System.Void Spine.Skeleton::SetToSetupPose()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Skeleton_SetToSetupPose_m12FBF0ABCEA99C4795C39EF74008F5372894DD71 (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
// Spine.AnimationStateData Spine.Unity.SkeletonDataAsset::GetAnimationStateData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* SkeletonDataAsset_GetAnimationStateData_m26E2621493EF9FC9D9673FA9C74B48D32D09AF9C (SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* __this, const RuntimeMethod* method) ;
// System.Void Spine.AnimationState::.ctor(Spine.AnimationStateData)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimationState__ctor_m633A801A8038EF0840C36EF102705EE1B6690145 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* ___data0, const RuntimeMethod* method) ;
// Spine.TrackEntry Spine.AnimationState::GetCurrent(System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* AnimationState_GetCurrent_m56ACBF9037B2D88C1134F0FC9D9927CD9E1DEA02 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, int32_t ___trackIndex0, const RuntimeMethod* method) ;
// Spine.TrackEntry Spine.TrackEntry::get_MixingFrom()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* TrackEntry_get_MixingFrom_m7598E2772B37B33B23647FD261DDD3FEA15B9B25_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, const RuntimeMethod* method) ;
// Spine.Animation Spine.TrackEntry::get_Animation()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, const RuntimeMethod* method) ;
// System.Void Spine.AnimationState::ClearTracks()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimationState_ClearTracks_mA999F7457875DB7A591547FB7AE9BAE7D8B263B5 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, const RuntimeMethod* method) ;
// System.Void Spine.SpineSkeletonExtensions::AllowImmediateQueue(Spine.TrackEntry)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonExtensions_AllowImmediateQueue_m6450A5DD17C6052864A9C9866A614ED1857036A8 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* ___trackEntry0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_MixTime(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_MixTime_mA8371A354DA49CDCF4415ED4F23943C03013206D_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.AnimationState::Update(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimationState_Update_mF60411EBD6B62050473B445C624110B5FBFACA20 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, float ___delta0, const RuntimeMethod* method) ;
// System.Boolean Spine.AnimationState::Apply(Spine.Skeleton)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AnimationState_Apply_mB430A13C849E59376436A50476EB6811FC14E25A (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, const RuntimeMethod* method) ;
// System.Void Spine.Animation::Apply(Spine.Skeleton,System.Single,System.Single,System.Boolean,Spine.ExposedList`1<Spine.Event>,System.Single,Spine.MixBlend,Spine.MixDirection)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Animation_Apply_mC43B0C9C2690CCB590A9332824DB73DF94A42608 (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, float ___lastTime1, float ___time2, bool ___loop3, ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* ___events4, float ___alpha5, int32_t ___blend6, int32_t ___direction7, const RuntimeMethod* method) ;
// System.Void Spine.Skeleton::UpdateWorldTransform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Skeleton_UpdateWorldTransform_m12FD1ACD50E9E19EA655B9F4CCD1F39F59B06F92 (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
// System.Single Spine.Skeleton::get_ScaleX()
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Skeleton_get_ScaleX_m0172910DB4B5C924E6010D1F7E41127B01E70FB3_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
// System.Single Spine.Skeleton::get_ScaleY()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Skeleton_get_ScaleY_m57C4D92B37F5622B9283BA4C8FD4A94C49D982B4 (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<SpineSkeletonFlipBehaviour>::op_Explicit(UnityEngine.Playables.Playable)
inline ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method)
{
	return ((  ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 (*) (Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F, const RuntimeMethod*))ScriptPlayable_1_op_Explicit_m338A0D445285A5BB298742C0ECEC3D707DF671F9_gshared)(___playable0, method);
}
// T UnityEngine.Playables.ScriptPlayable`1<SpineSkeletonFlipBehaviour>::GetBehaviour()
inline SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED (ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22* __this, const RuntimeMethod* method)
{
	return ((  SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* (*) (ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22*, const RuntimeMethod*))ScriptPlayable_1_GetBehaviour_m86713AAFF1D1F7D4FB370489F71AE4228741EFE8_gshared)(__this, method);
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::SetSkeletonScaleFromFlip(Spine.Skeleton,System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, bool ___flipX1, bool ___flipY2, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Mathf::Approximately(System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_inline (float ___a0, float ___b1, const RuntimeMethod* method) ;
// System.Void Spine.Skeleton::set_ScaleX(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.Skeleton::set_ScaleY(System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, float ___value0, const RuntimeMethod* method) ;
// UnityEngine.Playables.ScriptPlayable`1<T> UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour>::Create(UnityEngine.Playables.PlayableGraph,System.Int32)
inline ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, int32_t ___inputCount1, const RuntimeMethod* method)
{
	return ((  ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB (*) (PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E, int32_t, const RuntimeMethod*))ScriptPlayable_1_Create_mA469AA7F23C196EEFBE59D8AD1D800EE8E7B6DB1_gshared)(___graph0, ___inputCount1, method);
}
// UnityEngine.Playables.Playable UnityEngine.Playables.ScriptPlayable`1<Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour>::op_Implicit(UnityEngine.Playables.ScriptPlayable`1<T>)
inline Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61 (ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB ___playable0, const RuntimeMethod* method)
{
	return ((  Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F (*) (ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB, const RuntimeMethod*))ScriptPlayable_1_op_Implicit_m3FD2FD61DA16E18891F5223F509D18DBB614265A_gshared)(___playable0, method);
}
// System.Void UnityEngine.Timeline.TrackAsset::GatherProperties(UnityEngine.Playables.PlayableDirector,UnityEngine.Timeline.IPropertyCollector)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackAsset_GatherProperties_m09C1A335FCE1ABA158748583AF4A641FF2EBB09D (TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96* __this, PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475* ___director0, RuntimeObject* ___driver1, const RuntimeMethod* method) ;
// System.Single UnityEngine.Mathf::Max(System.Single,System.Single)
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline (float ___a0, float ___b1, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void SpineSkeletonFlipBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A (SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* __this, const RuntimeMethod* method) 
{
	{
		PlayableBehaviour__ctor_mA6202DCD846F0DDFC5963764A404EE8AFABEA23A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// UnityEngine.Timeline.ClipCaps SpineSkeletonFlipClip::get_clipCaps()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpineSkeletonFlipClip_get_clipCaps_mFDD25F831A3BC37B82501293FB4DDD97F919C8A1 (SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1* __this, const RuntimeMethod* method) 
{
	{
		// get { return ClipCaps.None; }
		return (int32_t)(0);
	}
}
// UnityEngine.Playables.Playable SpineSkeletonFlipClip::CreatePlayable(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineSkeletonFlipClip_CreatePlayable_m399DFE9F9DEC2D9A22FC6AC492B091F2DC36C855 (SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___owner1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// var playable = ScriptPlayable<SpineSkeletonFlipBehaviour>.Create(graph, template);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_1 = __this->___template_4;
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 L_2;
		L_2 = ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496(L_0, L_1, 0, ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496_RuntimeMethod_var);
		// return playable;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_3;
		L_3 = ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5(L_2, ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5_RuntimeMethod_var);
		return L_3;
	}
}
// System.Void SpineSkeletonFlipClip::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipClip__ctor_mDE5A2A09432F92FC654EFD404444C89D7651322B (SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SpineSkeletonFlipBehaviour template = new SpineSkeletonFlipBehaviour();
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_0 = (SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE*)il2cpp_codegen_object_new(SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A(L_0, NULL);
		__this->___template_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___template_4), (void*)L_0);
		PlayableAsset__ctor_m36B842356F02DF323B356BAAF6E3DC59BA9E1AB8(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Spine.Skeleton Spine.Unity.Playables.SkeletonAnimationPlayableHandle::get_Skeleton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* SkeletonAnimationPlayableHandle_get_Skeleton_m89A242C9232F14E6DF6382DF1D6CD658EE2BA48E (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	{
		// public override Skeleton Skeleton {    get { return skeletonAnimation.Skeleton; } }
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_0 = __this->___skeletonAnimation_5;
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonRenderer_get_Skeleton_m4B631F464CF860CC96CB34DF8AF61EE6B4F940BA(L_0, NULL);
		return L_1;
	}
}
// Spine.SkeletonData Spine.Unity.Playables.SkeletonAnimationPlayableHandle::get_SkeletonData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* SkeletonAnimationPlayableHandle_get_SkeletonData_m36D235853CFB1D380745ED1AA7CC68773016CFD0 (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	{
		// public override SkeletonData SkeletonData { get { return skeletonAnimation.Skeleton.Data; } }
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_0 = __this->___skeletonAnimation_5;
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonRenderer_get_Skeleton_m4B631F464CF860CC96CB34DF8AF61EE6B4F940BA(L_0, NULL);
		NullCheck(L_1);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_2;
		L_2 = Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA_inline(L_1, NULL);
		return L_2;
	}
}
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle_Awake_mA343FDAE99E4B98DDB6C96D985F7193CCFC5D227 (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	{
		// InitializeReference();
		SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC(__this, NULL);
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::InitializeReference()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (skeletonAnimation == null)
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_0 = __this->___skeletonAnimation_5;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_001a;
		}
	}
	{
		// skeletonAnimation = GetComponent<SkeletonAnimation>();
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_2;
		L_2 = Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49(__this, Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49_RuntimeMethod_var);
		__this->___skeletonAnimation_5 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___skeletonAnimation_5), (void*)L_2);
	}

IL_001a:
	{
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle__ctor_m6A65DED137CE9B7ED9C77199722D62598425FEC8 (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	{
		SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Spine.Skeleton Spine.Unity.Playables.SkeletonGraphicPlayableHandle::get_Skeleton()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* SkeletonGraphicPlayableHandle_get_Skeleton_m22DBF626CEA9ADF5343A0571486FDEC32B7D34AD (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	{
		// public override Skeleton Skeleton {    get { return skeletonGraphic.Skeleton; } }
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_0 = __this->___skeletonGraphic_5;
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonGraphic_get_Skeleton_mF8BED82D73B930C6D58A62E787A6DC4DF7055BAF(L_0, NULL);
		return L_1;
	}
}
// Spine.SkeletonData Spine.Unity.Playables.SkeletonGraphicPlayableHandle::get_SkeletonData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* SkeletonGraphicPlayableHandle_get_SkeletonData_mA4647B64590B1087D466C782D2A5B9A333072C54 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	{
		// public override SkeletonData SkeletonData { get { return skeletonGraphic.Skeleton.Data; } }
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_0 = __this->___skeletonGraphic_5;
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonGraphic_get_Skeleton_mF8BED82D73B930C6D58A62E787A6DC4DF7055BAF(L_0, NULL);
		NullCheck(L_1);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_2;
		L_2 = Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA_inline(L_1, NULL);
		return L_2;
	}
}
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle_Awake_m7ABB8022D2B8152BFACE481917F5393D278A05EB (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	{
		// InitializeReference();
		SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535(__this, NULL);
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::InitializeReference()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (skeletonGraphic == null)
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_0 = __this->___skeletonGraphic_5;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_001a;
		}
	}
	{
		// skeletonGraphic = GetComponent<SkeletonGraphic>();
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_2;
		L_2 = Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF(__this, Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF_RuntimeMethod_var);
		__this->___skeletonGraphic_5 = L_2;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___skeletonGraphic_5), (void*)L_2);
	}

IL_001a:
	{
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle__ctor_m7C062CD4809F306523558512A8522CBE8E43B269 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	{
		SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_Multicast(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	il2cpp_array_size_t length = __this->___delegates_13->max_length;
	Delegate_t** delegatesToInvoke = reinterpret_cast<Delegate_t**>(__this->___delegates_13->GetAddressAtUnchecked(0));
	for (il2cpp_array_size_t i = 0; i < length; i++)
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* currentDelegate = reinterpret_cast<SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*>(delegatesToInvoke[i]);
		typedef void (*FunctionPointerType) (RuntimeObject*, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5*, const RuntimeMethod*);
		((FunctionPointerType)currentDelegate->___invoke_impl_1)((Il2CppObject*)currentDelegate->___method_code_6, ___e0, reinterpret_cast<RuntimeMethod*>(currentDelegate->___method_3));
	}
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenInst(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	NullCheck(___e0);
	typedef void (*FunctionPointerType) (Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___e0, method);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenStatic(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	typedef void (*FunctionPointerType) (Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5*, const RuntimeMethod*);
	((FunctionPointerType)__this->___method_ptr_0)(___e0, method);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenStaticInvoker(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	InvokerActionInvoker1< Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* >::Invoke(__this->___method_ptr_0, method, NULL, ___e0);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_ClosedStaticInvoker(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	InvokerActionInvoker2< RuntimeObject*, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* >::Invoke(__this->___method_ptr_0, method, NULL, __this->___m_target_2, ___e0);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenVirtual(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	NullCheck(___e0);
	VirtualActionInvoker0::Invoke(il2cpp_codegen_method_get_slot(method), ___e0);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenInterface(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	NullCheck(___e0);
	InterfaceActionInvoker0::Invoke(il2cpp_codegen_method_get_slot(method), il2cpp_codegen_method_get_declaring_type(method), ___e0);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenGenericVirtual(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	NullCheck(___e0);
	GenericVirtualActionInvoker0::Invoke(method, ___e0);
}
void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenGenericInterface(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method)
{
	NullCheck(___e0);
	GenericInterfaceActionInvoker0::Invoke(method, ___e0);
}
// System.Void Spine.Unity.Playables.SpineEventDelegate::.ctor(System.Object,System.IntPtr)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineEventDelegate__ctor_mEEDD5375624B62C700B1C2A9376C540C046980C4 (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, RuntimeObject* ___object0, intptr_t ___method1, const RuntimeMethod* method) 
{
	__this->___method_ptr_0 = il2cpp_codegen_get_virtual_call_method_pointer((RuntimeMethod*)___method1);
	__this->___method_3 = ___method1;
	__this->___m_target_2 = ___object0;
	Il2CppCodeGenWriteBarrier((void**)(&__this->___m_target_2), (void*)___object0);
	int parameterCount = il2cpp_codegen_method_parameter_count((RuntimeMethod*)___method1);
	__this->___method_code_6 = (intptr_t)__this;
	if (MethodIsStatic((RuntimeMethod*)___method1))
	{
		bool isOpen = parameterCount == 1;
		if (il2cpp_codegen_call_method_via_invoker((RuntimeMethod*)___method1))
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenStaticInvoker;
			else
				__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_ClosedStaticInvoker;
		else
			if (isOpen)
				__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenStatic;
			else
				{
					__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
					__this->___method_code_6 = (intptr_t)__this->___m_target_2;
				}
	}
	else
	{
		bool isOpen = parameterCount == 0;
		if (isOpen)
		{
			if (__this->___method_is_virtual_12)
			{
				if (il2cpp_codegen_method_is_generic_instance_method((RuntimeMethod*)___method1))
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___method1))
						__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenGenericInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenGenericVirtual;
				else
					if (il2cpp_codegen_method_is_interface_method((RuntimeMethod*)___method1))
						__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenInterface;
					else
						__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenVirtual;
			}
			else
			{
				__this->___invoke_impl_1 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_OpenInst;
			}
		}
		else
		{
			if (___object0 == NULL)
				il2cpp_codegen_raise_exception(il2cpp_codegen_get_argument_exception(NULL, "Delegate to an instance method cannot have null 'this'."), NULL);
			__this->___invoke_impl_1 = (intptr_t)__this->___method_ptr_0;
			__this->___method_code_6 = (intptr_t)__this->___m_target_2;
		}
	}
	__this->___extra_arg_5 = (intptr_t)&SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_Multicast;
}
// System.Void Spine.Unity.Playables.SpineEventDelegate::Invoke(Spine.Event)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775 (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___e0, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
// System.IAsyncResult Spine.Unity.Playables.SpineEventDelegate::BeginInvoke(Spine.Event,System.AsyncCallback,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* SpineEventDelegate_BeginInvoke_mE290564C3B72B4F3A10BDCDC4BCC43B0FC1AEC41 (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, AsyncCallback_t7FEF460CBDCFB9C5FA2EF776984778B9A4145F4C* ___callback1, RuntimeObject* ___object2, const RuntimeMethod* method) 
{
	void *__d_args[2] = {0};
	__d_args[0] = ___e0;
	return (RuntimeObject*)il2cpp_codegen_delegate_begin_invoke((RuntimeDelegate*)__this, __d_args, (RuntimeDelegate*)___callback1, (RuntimeObject*)___object2);
}
// System.Void Spine.Unity.Playables.SpineEventDelegate::EndInvoke(System.IAsyncResult)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineEventDelegate_EndInvoke_m8A510ED1B006F66493CB99F570D07F5B0B3EC5A9 (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, RuntimeObject* ___result0, const RuntimeMethod* method) 
{
	il2cpp_codegen_delegate_end_invoke((Il2CppAsyncResult*) ___result0, 0);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Spine.Unity.Playables.SpinePlayableHandleBase::add_AnimationEvents(Spine.Unity.Playables.SpineEventDelegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinePlayableHandleBase_add_AnimationEvents_m02560BDC4FD5A3507CDC2EF1F8995886E958AD20 (SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* __this, SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* ___value0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_0 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_1 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_2 = NULL;
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_0 = __this->___AnimationEvents_4;
		V_0 = L_0;
	}

IL_0007:
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_1 = V_0;
		V_1 = L_1;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_2 = V_1;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_3 = ___value0;
		Delegate_t* L_4;
		L_4 = Delegate_Combine_m8B9D24CED35033C7FC56501DFE650F5CB7FF012C(L_2, L_3, NULL);
		V_2 = ((SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)CastclassSealed((RuntimeObject*)L_4, SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C_il2cpp_TypeInfo_var));
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C** L_5 = (&__this->___AnimationEvents_4);
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_6 = V_2;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_7 = V_1;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_8;
		L_8 = InterlockedCompareExchangeImpl<SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*>(L_5, L_6, L_7);
		V_0 = L_8;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_9 = V_0;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_10 = V_1;
		if ((!(((RuntimeObject*)(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)L_9) == ((RuntimeObject*)(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// System.Void Spine.Unity.Playables.SpinePlayableHandleBase::remove_AnimationEvents(Spine.Unity.Playables.SpineEventDelegate)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinePlayableHandleBase_remove_AnimationEvents_m3D95EFCF9BFF6E8EA70A8ECA6E6AC2CE2B891D16 (SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* __this, SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* ___value0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_0 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_1 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_2 = NULL;
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_0 = __this->___AnimationEvents_4;
		V_0 = L_0;
	}

IL_0007:
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_1 = V_0;
		V_1 = L_1;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_2 = V_1;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_3 = ___value0;
		Delegate_t* L_4;
		L_4 = Delegate_Remove_m40506877934EC1AD4ADAE57F5E97AF0BC0F96116(L_2, L_3, NULL);
		V_2 = ((SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)CastclassSealed((RuntimeObject*)L_4, SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C_il2cpp_TypeInfo_var));
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C** L_5 = (&__this->___AnimationEvents_4);
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_6 = V_2;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_7 = V_1;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_8;
		L_8 = InterlockedCompareExchangeImpl<SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*>(L_5, L_6, L_7);
		V_0 = L_8;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_9 = V_0;
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_10 = V_1;
		if ((!(((RuntimeObject*)(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)L_9) == ((RuntimeObject*)(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)L_10))))
		{
			goto IL_0007;
		}
	}
	{
		return;
	}
}
// System.Void Spine.Unity.Playables.SpinePlayableHandleBase::HandleEvents(Spine.ExposedList`1<Spine.Event>)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinePlayableHandleBase_HandleEvents_m21536E264F6D4799B403DE3B8527A05B625C595A (SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* __this, ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* ___eventBuffer0, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	{
		// if (eventBuffer == null || AnimationEvents == null) return;
		ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* L_0 = ___eventBuffer0;
		if (!L_0)
		{
			goto IL_000b;
		}
	}
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_1 = __this->___AnimationEvents_4;
		if (L_1)
		{
			goto IL_000c;
		}
	}

IL_000b:
	{
		// if (eventBuffer == null || AnimationEvents == null) return;
		return;
	}

IL_000c:
	{
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		V_0 = 0;
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* L_2 = ___eventBuffer0;
		NullCheck(L_2);
		int32_t L_3 = L_2->___Count_1;
		V_1 = L_3;
		goto IL_002e;
	}

IL_0017:
	{
		// AnimationEvents.Invoke(eventBuffer.Items[i]);
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_4 = __this->___AnimationEvents_4;
		ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* L_5 = ___eventBuffer0;
		NullCheck(L_5);
		EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C* L_6 = L_5->___Items_0;
		int32_t L_7 = V_0;
		NullCheck(L_6);
		int32_t L_8 = L_7;
		Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* L_9 = (L_6)->GetAt(static_cast<il2cpp_array_size_t>(L_8));
		NullCheck(L_4);
		SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_inline(L_4, L_9, NULL);
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		int32_t L_10 = V_0;
		V_0 = ((int32_t)il2cpp_codegen_add(L_10, 1));
	}

IL_002e:
	{
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		int32_t L_11 = V_0;
		int32_t L_12 = V_1;
		if ((((int32_t)L_11) < ((int32_t)L_12)))
		{
			goto IL_0017;
		}
	}
	{
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpinePlayableHandleBase::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E (SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* __this, const RuntimeMethod* method) 
{
	{
		MonoBehaviour__ctor_m592DB0105CA0BC97AA1C5F4AD27B12D68A3B7C1E(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Spine.Unity.Playables.SpineAnimationStateBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723 (SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* __this, const RuntimeMethod* method) 
{
	{
		// public bool useBlendDuration = true;
		__this->___useBlendDuration_3 = (bool)1;
		// public float mixDuration = 0.1f;
		__this->___mixDuration_5 = (0.100000001f);
		// public float attachmentThreshold = 0.5f;
		__this->___attachmentThreshold_7 = (0.5f);
		// public float eventThreshold = 0.5f;
		__this->___eventThreshold_8 = (0.5f);
		// public float drawOrderThreshold = 0.5f;
		__this->___drawOrderThreshold_9 = (0.5f);
		PlayableBehaviour__ctor_mA6202DCD846F0DDFC5963764A404EE8AFABEA23A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// UnityEngine.Timeline.ClipCaps Spine.Unity.Playables.SpineAnimationStateClip::get_clipCaps()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t SpineAnimationStateClip_get_clipCaps_mCF30A930DA45E24FDDC483BC189383E962400961 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, const RuntimeMethod* method) 
{
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		// public ClipCaps clipCaps { get { return ClipCaps.Blending | ClipCaps.ClipIn | ClipCaps.SpeedMultiplier | (template.loop ? ClipCaps.Looping : 0); } }
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_0 = __this->___template_4;
		NullCheck(L_0);
		bool L_1 = L_0->___loop_1;
		G_B1_0 = ((int32_t)28);
		if (L_1)
		{
			G_B2_0 = ((int32_t)28);
			goto IL_0012;
		}
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_0013;
	}

IL_0012:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0013:
	{
		return (int32_t)(((int32_t)(G_B3_1|G_B3_0)));
	}
}
// UnityEngine.Playables.Playable Spine.Unity.Playables.SpineAnimationStateClip::CreatePlayable(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineAnimationStateClip_CreatePlayable_mD1032BDA98B16C19C16AC3C25326B055599BC807 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___owner1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// var playable = ScriptPlayable<SpineAnimationStateBehaviour>.Create(graph, template);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_1 = __this->___template_4;
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_2;
		L_2 = ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0(L_0, L_1, 0, ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0_RuntimeMethod_var);
		V_0 = L_2;
		// playable.GetBehaviour();
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_3;
		L_3 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_0), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		// return playable;
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_4 = V_0;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_5;
		L_5 = ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8(L_4, ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8_RuntimeMethod_var);
		return L_5;
	}
}
// System.Double Spine.Unity.Playables.SpineAnimationStateClip::get_duration()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double SpineAnimationStateClip_get_duration_mA39B55EF9045326BABC1886E94F952E2AA6613F8 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// if (template.animationReference == null || template.animationReference.Animation == null)
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_0 = __this->___template_4;
		NullCheck(L_0);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_1 = L_0->___animationReference_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_2)
		{
			goto IL_0025;
		}
	}
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_3 = __this->___template_4;
		NullCheck(L_3);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_4 = L_3->___animationReference_0;
		NullCheck(L_4);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_5;
		L_5 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_4, NULL);
		if (L_5)
		{
			goto IL_002f;
		}
	}

IL_0025:
	{
		// return 0;
		return (0.0);
	}

IL_002f:
	{
		// return template.animationReference.Animation.Duration;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_6 = __this->___template_4;
		NullCheck(L_6);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_7 = L_6->___animationReference_0;
		NullCheck(L_7);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_8;
		L_8 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_7, NULL);
		NullCheck(L_8);
		float L_9;
		L_9 = Animation_get_Duration_m385D29E0C137F21E8AD0DD9A945C0610AF175632_inline(L_8, NULL);
		return ((double)L_9);
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateClip::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateClip__ctor_mF7502B962F50B8CE59DDBF0FE22707E7B329FD28 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// public SpineAnimationStateBehaviour template = new SpineAnimationStateBehaviour();
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_0 = (SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08*)il2cpp_codegen_object_new(SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723(L_0, NULL);
		__this->___template_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___template_4), (void*)L_0);
		PlayableAsset__ctor_m36B842356F02DF323B356BAAF6E3DC59BA9E1AB8(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// UnityEngine.Playables.Playable Spine.Unity.Playables.SpineAnimationStateGraphicTrack::CreateTrackMixer(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineAnimationStateGraphicTrack_CreateTrackMixer_mBC3BC55D62A0B73D6346E60C3A6A783BF89E879B (SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___go1, int32_t ___inputCount2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// var scriptPlayable = ScriptPlayable<SpineAnimationStateMixerBehaviour>.Create(graph, inputCount);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		int32_t L_1 = ___inputCount2;
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_2;
		L_2 = ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F(L_0, L_1, ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		V_0 = L_2;
		// var mixerBehaviour = scriptPlayable.GetBehaviour();
		SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* L_3;
		L_3 = ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4((&V_0), ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		// mixerBehaviour.trackIndex = this.trackIndex;
		int32_t L_4 = __this->___trackIndex_28;
		NullCheck(L_3);
		L_3->___trackIndex_1 = L_4;
		// return scriptPlayable;
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_5 = V_0;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_6;
		L_6 = ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5(L_5, ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		return L_6;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateGraphicTrack::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateGraphicTrack__ctor_m4865F8FA9ECBCCC65A4011A7A00D4DB2CFB8D3BB (SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::ProcessFrame(UnityEngine.Playables.Playable,UnityEngine.Playables.FrameData,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateMixerBehaviour_ProcessFrame_mF5BA9FDFE0AC4CE04804BA76342A32060F55AC5B (SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* __this, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, FrameData_t02E705D0271F73A24ADF9BA4B6F8760B6696F314 ___info1, RuntimeObject* ___playerData2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* V_0 = NULL;
	SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	RuntimeObject* V_3 = NULL;
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* V_4 = NULL;
	int32_t V_5 = 0;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* V_6 = NULL;
	int32_t V_7 = 0;
	int32_t V_8 = 0;
	float V_9 = 0.0f;
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_10;
	memset((&V_10), 0, sizeof(V_10));
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* V_11 = NULL;
	float V_12 = 0.0f;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* V_13 = NULL;
	int32_t G_B14_0 = 0;
	float G_B19_0 = 0.0f;
	{
		// var skeletonAnimation = playerData as SkeletonAnimation;
		RuntimeObject* L_0 = ___playerData2;
		V_0 = ((SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A*)IsInstClass((RuntimeObject*)L_0, SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_il2cpp_TypeInfo_var));
		// var skeletonGraphic = playerData as SkeletonGraphic;
		RuntimeObject* L_1 = ___playerData2;
		V_1 = ((SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1*)IsInstClass((RuntimeObject*)L_1, SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_il2cpp_TypeInfo_var));
		// var animationStateComponent = playerData as IAnimationStateComponent;
		RuntimeObject* L_2 = ___playerData2;
		V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var));
		// var skeletonComponent = playerData as ISkeletonComponent;
		RuntimeObject* L_3 = ___playerData2;
		V_3 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var));
		// if (animationStateComponent == null || skeletonComponent == null) return;
		RuntimeObject* L_4 = V_2;
		if (!L_4)
		{
			goto IL_0022;
		}
	}
	{
		RuntimeObject* L_5 = V_3;
		if (L_5)
		{
			goto IL_0023;
		}
	}

IL_0022:
	{
		// if (animationStateComponent == null || skeletonComponent == null) return;
		return;
	}

IL_0023:
	{
		// var skeleton = skeletonComponent.Skeleton;
		RuntimeObject* L_6 = V_3;
		NullCheck(L_6);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_7;
		L_7 = InterfaceFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(1 /* Spine.Skeleton Spine.Unity.ISkeletonComponent::get_Skeleton() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_6);
		// var state = animationStateComponent.AnimationState;
		RuntimeObject* L_8 = V_2;
		NullCheck(L_8);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_9;
		L_9 = InterfaceFuncInvoker0< AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* >::Invoke(0 /* Spine.AnimationState Spine.Unity.IAnimationStateComponent::get_AnimationState() */, IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var, L_8);
		V_4 = L_9;
		// if (!Application.isPlaying) {
		bool L_10;
		L_10 = Application_get_isPlaying_m0B3B501E1093739F8887A0DAC5F61D9CB49CC337(NULL);
		if (L_10)
		{
			goto IL_0045;
		}
	}
	{
		// PreviewEditModePose(playable, skeletonComponent, animationStateComponent,
		//     skeletonAnimation, skeletonGraphic);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_11 = ___playable0;
		RuntimeObject* L_12 = V_3;
		RuntimeObject* L_13 = V_2;
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_14 = V_0;
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_15 = V_1;
		SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584(__this, L_11, L_12, L_13, L_14, L_15, NULL);
		// return;
		return;
	}

IL_0045:
	{
		// int inputCount = playable.GetInputCount();
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_16 = ___playable0;
		int32_t L_17;
		L_17 = PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9(L_16, PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		V_5 = L_17;
		// if (this.lastInputWeights == null || this.lastInputWeights.Length < inputCount) {
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_18 = __this->___lastInputWeights_0;
		if (!L_18)
		{
			goto IL_0061;
		}
	}
	{
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_19 = __this->___lastInputWeights_0;
		NullCheck(L_19);
		int32_t L_20 = V_5;
		if ((((int32_t)((int32_t)(((RuntimeArray*)L_19)->max_length))) >= ((int32_t)L_20)))
		{
			goto IL_008d;
		}
	}

IL_0061:
	{
		// this.lastInputWeights = new float[inputCount];
		int32_t L_21 = V_5;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_22 = (SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*)(SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*)SZArrayNew(SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_il2cpp_TypeInfo_var, (uint32_t)L_21);
		__this->___lastInputWeights_0 = L_22;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___lastInputWeights_0), (void*)L_22);
		// for (int i = 0; i < inputCount; i++)
		V_7 = 0;
		goto IL_0087;
	}

IL_0073:
	{
		// this.lastInputWeights[i] = default(float);
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_23 = __this->___lastInputWeights_0;
		int32_t L_24 = V_7;
		NullCheck(L_23);
		(L_23)->SetAt(static_cast<il2cpp_array_size_t>(L_24), (float)(0.0f));
		// for (int i = 0; i < inputCount; i++)
		int32_t L_25 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_25, 1));
	}

IL_0087:
	{
		// for (int i = 0; i < inputCount; i++)
		int32_t L_26 = V_7;
		int32_t L_27 = V_5;
		if ((((int32_t)L_26) < ((int32_t)L_27)))
		{
			goto IL_0073;
		}
	}

IL_008d:
	{
		// var lastInputWeights = this.lastInputWeights;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_28 = __this->___lastInputWeights_0;
		V_6 = L_28;
		// for (int i = 0; i < inputCount; i++) {
		V_8 = 0;
		goto IL_020a;
	}

IL_009d:
	{
		// float lastInputWeight = lastInputWeights[i];
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_29 = V_6;
		int32_t L_30 = V_8;
		NullCheck(L_29);
		int32_t L_31 = L_30;
		float L_32 = (L_29)->GetAt(static_cast<il2cpp_array_size_t>(L_31));
		// float inputWeight = playable.GetInputWeight(i);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_33 = ___playable0;
		int32_t L_34 = V_8;
		float L_35;
		L_35 = PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B(L_33, L_34, PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		V_9 = L_35;
		// bool trackStarted = lastInputWeight == 0 && inputWeight > 0;
		if ((!(((float)L_32) == ((float)(0.0f)))))
		{
			goto IL_00be;
		}
	}
	{
		float L_36 = V_9;
		G_B14_0 = ((((float)L_36) > ((float)(0.0f)))? 1 : 0);
		goto IL_00bf;
	}

IL_00be:
	{
		G_B14_0 = 0;
	}

IL_00bf:
	{
		// lastInputWeights[i] = inputWeight;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_37 = V_6;
		int32_t L_38 = V_8;
		float L_39 = V_9;
		NullCheck(L_37);
		(L_37)->SetAt(static_cast<il2cpp_array_size_t>(L_38), (float)L_39);
		// if (trackStarted) {
		if (!G_B14_0)
		{
			goto IL_0204;
		}
	}
	{
		// ScriptPlayable<SpineAnimationStateBehaviour> inputPlayable = (ScriptPlayable<SpineAnimationStateBehaviour>)playable.GetInput(i);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_40 = ___playable0;
		int32_t L_41 = V_8;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_42;
		L_42 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_40, L_41, PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_43;
		L_43 = ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980(L_42, ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		V_10 = L_43;
		// SpineAnimationStateBehaviour clipData = inputPlayable.GetBehaviour();
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_44;
		L_44 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_10), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		V_11 = L_44;
		// if (clipData.animationReference == null) {
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_45 = V_11;
		NullCheck(L_45);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_46 = L_45->___animationReference_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_47;
		L_47 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_46, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_47)
		{
			goto IL_0127;
		}
	}
	{
		// float mixDuration = clipData.customDuration ? clipData.mixDuration : state.Data.DefaultMix;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_48 = V_11;
		NullCheck(L_48);
		bool L_49 = L_48->___customDuration_2;
		if (L_49)
		{
			goto IL_0109;
		}
	}
	{
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_50 = V_4;
		NullCheck(L_50);
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_51;
		L_51 = AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C_inline(L_50, NULL);
		NullCheck(L_51);
		float L_52;
		L_52 = AnimationStateData_get_DefaultMix_m4BDB14E9DF538918293CF58F4D62B7DB49AAB476_inline(L_51, NULL);
		G_B19_0 = L_52;
		goto IL_0110;
	}

IL_0109:
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_53 = V_11;
		NullCheck(L_53);
		float L_54 = L_53->___mixDuration_5;
		G_B19_0 = L_54;
	}

IL_0110:
	{
		V_12 = G_B19_0;
		// state.SetEmptyAnimation(trackIndex, mixDuration);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_55 = V_4;
		int32_t L_56 = __this->___trackIndex_1;
		float L_57 = V_12;
		NullCheck(L_55);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_58;
		L_58 = AnimationState_SetEmptyAnimation_m2C660F117296347DFF557578CCC42E7215935656(L_55, L_56, L_57, NULL);
		goto IL_01d0;
	}

IL_0127:
	{
		// if (clipData.animationReference.Animation != null) {
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_59 = V_11;
		NullCheck(L_59);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_60 = L_59->___animationReference_0;
		NullCheck(L_60);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_61;
		L_61 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_60, NULL);
		if (!L_61)
		{
			goto IL_01d0;
		}
	}
	{
		// Spine.TrackEntry trackEntry = state.SetAnimation(trackIndex, clipData.animationReference.Animation, clipData.loop);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_62 = V_4;
		int32_t L_63 = __this->___trackIndex_1;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_64 = V_11;
		NullCheck(L_64);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_65 = L_64->___animationReference_0;
		NullCheck(L_65);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_66;
		L_66 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_65, NULL);
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_67 = V_11;
		NullCheck(L_67);
		bool L_68 = L_67->___loop_1;
		NullCheck(L_62);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_69;
		L_69 = AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D(L_62, L_63, L_66, L_68, NULL);
		V_13 = L_69;
		// trackEntry.EventThreshold = clipData.eventThreshold;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_70 = V_13;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_71 = V_11;
		NullCheck(L_71);
		float L_72 = L_71->___eventThreshold_8;
		NullCheck(L_70);
		TrackEntry_set_EventThreshold_mB58AD3053F5C702066F23AE2DBD52F4DD6DE2823_inline(L_70, L_72, NULL);
		// trackEntry.DrawOrderThreshold = clipData.drawOrderThreshold;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_73 = V_13;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_74 = V_11;
		NullCheck(L_74);
		float L_75 = L_74->___drawOrderThreshold_9;
		NullCheck(L_73);
		TrackEntry_set_DrawOrderThreshold_mB1343F81A778546FDE7464B66698B838A44F24F3_inline(L_73, L_75, NULL);
		// trackEntry.TrackTime = (float)inputPlayable.GetTime() * (float)inputPlayable.GetSpeed();
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_76 = V_13;
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_77 = V_10;
		double L_78;
		L_78 = PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A(L_77, PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_79 = V_10;
		double L_80;
		L_80 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_79, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		NullCheck(L_76);
		TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3_inline(L_76, ((float)il2cpp_codegen_multiply(((float)L_78), ((float)L_80))), NULL);
		// trackEntry.TimeScale = (float)inputPlayable.GetSpeed();
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_81 = V_13;
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_82 = V_10;
		double L_83;
		L_83 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_82, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		NullCheck(L_81);
		TrackEntry_set_TimeScale_m9C6DC53ED8731A1A5A3EE825BEF667BA848A8588_inline(L_81, ((float)L_83), NULL);
		// trackEntry.AttachmentThreshold = clipData.attachmentThreshold;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_84 = V_13;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_85 = V_11;
		NullCheck(L_85);
		float L_86 = L_85->___attachmentThreshold_7;
		NullCheck(L_84);
		TrackEntry_set_AttachmentThreshold_mA75133539615A962566CE1CAAA1FFB9ED49A3DC0_inline(L_84, L_86, NULL);
		// trackEntry.HoldPrevious = clipData.holdPrevious;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_87 = V_13;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_88 = V_11;
		NullCheck(L_88);
		bool L_89 = L_88->___holdPrevious_6;
		NullCheck(L_87);
		TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3_inline(L_87, L_89, NULL);
		// if (clipData.customDuration)
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_90 = V_11;
		NullCheck(L_90);
		bool L_91 = L_90->___customDuration_2;
		if (!L_91)
		{
			goto IL_01d0;
		}
	}
	{
		// trackEntry.MixDuration = clipData.mixDuration;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_92 = V_13;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_93 = V_11;
		NullCheck(L_93);
		float L_94 = L_93->___mixDuration_5;
		NullCheck(L_92);
		TrackEntry_set_MixDuration_m22C7A7BDE2F947A311BC27093C0C5B96B4CA9C55_inline(L_92, L_94, NULL);
	}

IL_01d0:
	{
		// if (skeletonAnimation) {
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_95 = V_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_96;
		L_96 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_95, NULL);
		if (!L_96)
		{
			goto IL_01eb;
		}
	}
	{
		// skeletonAnimation.Update(0);
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_97 = V_0;
		NullCheck(L_97);
		SkeletonAnimation_Update_mA405A7645B8BA03A1CD193F3AE50E1D08FBC19D0(L_97, (0.0f), NULL);
		// skeletonAnimation.LateUpdate();
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_98 = V_0;
		NullCheck(L_98);
		VirtualActionInvoker0::Invoke(10 /* System.Void Spine.Unity.SkeletonRenderer::LateUpdate() */, L_98);
		goto IL_0204;
	}

IL_01eb:
	{
		// else if (skeletonGraphic) {
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_99 = V_1;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_100;
		L_100 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_99, NULL);
		if (!L_100)
		{
			goto IL_0204;
		}
	}
	{
		// skeletonGraphic.Update(0);
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_101 = V_1;
		NullCheck(L_101);
		VirtualActionInvoker1< float >::Invoke(77 /* System.Void Spine.Unity.SkeletonGraphic::Update(System.Single) */, L_101, (0.0f));
		// skeletonGraphic.LateUpdate();
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_102 = V_1;
		NullCheck(L_102);
		SkeletonGraphic_LateUpdate_m6A04288EA0CEDAE3A87FC0BC09E797D70B9D4347(L_102, NULL);
	}

IL_0204:
	{
		// for (int i = 0; i < inputCount; i++) {
		int32_t L_103 = V_8;
		V_8 = ((int32_t)il2cpp_codegen_add(L_103, 1));
	}

IL_020a:
	{
		// for (int i = 0; i < inputCount; i++) {
		int32_t L_104 = V_8;
		int32_t L_105 = V_5;
		if ((((int32_t)L_104) < ((int32_t)L_105)))
		{
			goto IL_009d;
		}
	}
	{
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::PreviewEditModePose(UnityEngine.Playables.Playable,Spine.Unity.ISkeletonComponent,Spine.Unity.IAnimationStateComponent,Spine.Unity.SkeletonAnimation,Spine.Unity.SkeletonGraphic)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584 (SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* __this, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, RuntimeObject* ___skeletonComponent1, RuntimeObject* ___animationStateComponent2, SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* ___skeletonAnimation3, SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* ___skeletonGraphic4, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD9AEAA6A49FCC6BC5EF6CE3F695813A1EAB670BE);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_3;
	memset((&V_3), 0, sizeof(V_3));
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* V_4 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_5 = NULL;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* V_6 = NULL;
	float V_7 = 0.0f;
	bool V_8 = false;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* V_9 = NULL;
	float V_10 = 0.0f;
	float V_11 = 0.0f;
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_12;
	memset((&V_12), 0, sizeof(V_12));
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* V_13 = NULL;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* V_14 = NULL;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* V_15 = NULL;
	int32_t G_B15_0 = 0;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* G_B22_0 = NULL;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* G_B26_0 = NULL;
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* G_B37_0 = NULL;
	SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* G_B37_1 = NULL;
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* G_B36_0 = NULL;
	SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* G_B36_1 = NULL;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* G_B40_0 = NULL;
	int32_t G_B45_0 = 0;
	{
		// if (Application.isPlaying) return;
		bool L_0;
		L_0 = Application_get_isPlaying_m0B3B501E1093739F8887A0DAC5F61D9CB49CC337(NULL);
		if (!L_0)
		{
			goto IL_0008;
		}
	}
	{
		// if (Application.isPlaying) return;
		return;
	}

IL_0008:
	{
		// if (skeletonComponent == null || animationStateComponent == null) return;
		RuntimeObject* L_1 = ___skeletonComponent1;
		if (!L_1)
		{
			goto IL_000e;
		}
	}
	{
		RuntimeObject* L_2 = ___animationStateComponent2;
		if (L_2)
		{
			goto IL_000f;
		}
	}

IL_000e:
	{
		// if (skeletonComponent == null || animationStateComponent == null) return;
		return;
	}

IL_000f:
	{
		// int inputCount = playable.GetInputCount();
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_3 = ___playable0;
		int32_t L_4;
		L_4 = PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9(L_3, PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		V_0 = L_4;
		// int lastNonZeroWeightTrack = -1;
		V_1 = (-1);
		// for (int i = 0; i < inputCount; i++) {
		V_2 = 0;
		goto IL_0030;
	}

IL_001c:
	{
		// float inputWeight = playable.GetInputWeight(i);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_5 = ___playable0;
		int32_t L_6 = V_2;
		float L_7;
		L_7 = PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B(L_5, L_6, PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		// if (inputWeight > 0) lastNonZeroWeightTrack = i;
		if ((!(((float)L_7) > ((float)(0.0f)))))
		{
			goto IL_002c;
		}
	}
	{
		// if (inputWeight > 0) lastNonZeroWeightTrack = i;
		int32_t L_8 = V_2;
		V_1 = L_8;
	}

IL_002c:
	{
		// for (int i = 0; i < inputCount; i++) {
		int32_t L_9 = V_2;
		V_2 = ((int32_t)il2cpp_codegen_add(L_9, 1));
	}

IL_0030:
	{
		// for (int i = 0; i < inputCount; i++) {
		int32_t L_10 = V_2;
		int32_t L_11 = V_0;
		if ((((int32_t)L_10) < ((int32_t)L_11)))
		{
			goto IL_001c;
		}
	}
	{
		// if (lastNonZeroWeightTrack != -1) {
		int32_t L_12 = V_1;
		if ((((int32_t)L_12) == ((int32_t)(-1))))
		{
			goto IL_02f8;
		}
	}
	{
		// ScriptPlayable<SpineAnimationStateBehaviour> inputPlayableClip =
		//     (ScriptPlayable<SpineAnimationStateBehaviour>)playable.GetInput(lastNonZeroWeightTrack);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_13 = ___playable0;
		int32_t L_14 = V_1;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_15;
		L_15 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_13, L_14, PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_16;
		L_16 = ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980(L_15, ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		V_3 = L_16;
		// SpineAnimationStateBehaviour clipData = inputPlayableClip.GetBehaviour();
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_17;
		L_17 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_3), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		V_4 = L_17;
		// var skeleton = skeletonComponent.Skeleton;
		RuntimeObject* L_18 = ___skeletonComponent1;
		NullCheck(L_18);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_19;
		L_19 = InterfaceFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(1 /* Spine.Skeleton Spine.Unity.ISkeletonComponent::get_Skeleton() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_18);
		V_5 = L_19;
		// bool skeletonDataMismatch = clipData.animationReference != null && clipData.animationReference.SkeletonDataAsset &&
		//     skeletonComponent.SkeletonDataAsset.GetSkeletonData(true) != clipData.animationReference.SkeletonDataAsset.GetSkeletonData(true);
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_20 = V_4;
		NullCheck(L_20);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_21 = L_20->___animationReference_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_22;
		L_22 = Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7(L_21, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_22)
		{
			goto IL_00a0;
		}
	}
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_23 = V_4;
		NullCheck(L_23);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_24 = L_23->___animationReference_0;
		NullCheck(L_24);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_25;
		L_25 = AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E_inline(L_24, NULL);
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_26;
		L_26 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_25, NULL);
		if (!L_26)
		{
			goto IL_00a0;
		}
	}
	{
		RuntimeObject* L_27 = ___skeletonComponent1;
		NullCheck(L_27);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_28;
		L_28 = InterfaceFuncInvoker0< SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* >::Invoke(0 /* Spine.Unity.SkeletonDataAsset Spine.Unity.ISkeletonComponent::get_SkeletonDataAsset() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_27);
		NullCheck(L_28);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_29;
		L_29 = SkeletonDataAsset_GetSkeletonData_mCBAFA745AEC7A8191A7FBE1EE05A8A877886832E(L_28, (bool)1, NULL);
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_30 = V_4;
		NullCheck(L_30);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_31 = L_30->___animationReference_0;
		NullCheck(L_31);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_32;
		L_32 = AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E_inline(L_31, NULL);
		NullCheck(L_32);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_33;
		L_33 = SkeletonDataAsset_GetSkeletonData_mCBAFA745AEC7A8191A7FBE1EE05A8A877886832E(L_32, (bool)1, NULL);
		G_B15_0 = ((((int32_t)((((RuntimeObject*)(SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B*)L_29) == ((RuntimeObject*)(SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B*)L_33))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_00a1;
	}

IL_00a0:
	{
		G_B15_0 = 0;
	}

IL_00a1:
	{
		// if (skeletonDataMismatch) {
		if (!G_B15_0)
		{
			goto IL_00cb;
		}
	}
	{
		// Debug.LogWarningFormat("SpineAnimationStateMixerBehaviour tried to apply an animation for the wrong skeleton. Expected {0}. Was {1}",
		//     skeletonComponent.SkeletonDataAsset, clipData.animationReference.SkeletonDataAsset);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_34 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)2);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_35 = L_34;
		RuntimeObject* L_36 = ___skeletonComponent1;
		NullCheck(L_36);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_37;
		L_37 = InterfaceFuncInvoker0< SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* >::Invoke(0 /* Spine.Unity.SkeletonDataAsset Spine.Unity.ISkeletonComponent::get_SkeletonDataAsset() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_36);
		NullCheck(L_35);
		ArrayElementTypeCheck (L_35, L_37);
		(L_35)->SetAt(static_cast<il2cpp_array_size_t>(0), (RuntimeObject*)L_37);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_38 = L_35;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_39 = V_4;
		NullCheck(L_39);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_40 = L_39->___animationReference_0;
		NullCheck(L_40);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_41;
		L_41 = AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E_inline(L_40, NULL);
		NullCheck(L_38);
		ArrayElementTypeCheck (L_38, L_41);
		(L_38)->SetAt(static_cast<il2cpp_array_size_t>(1), (RuntimeObject*)L_41);
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarningFormat_m0D4A31935564D0FA042103C1231DBBD2ED0BC20A(_stringLiteralD9AEAA6A49FCC6BC5EF6CE3F695813A1EAB670BE, L_38, NULL);
	}

IL_00cb:
	{
		// Animation fromAnimation = null;
		V_6 = (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)NULL;
		// float fromClipTime = 0;
		V_7 = (0.0f);
		// bool fromClipLoop = false;
		V_8 = (bool)0;
		// if (lastNonZeroWeightTrack != 0 && inputCount > 1) {
		int32_t L_42 = V_1;
		if (!L_42)
		{
			goto IL_0134;
		}
	}
	{
		int32_t L_43 = V_0;
		if ((((int32_t)L_43) <= ((int32_t)1)))
		{
			goto IL_0134;
		}
	}
	{
		// var fromClip = (ScriptPlayable<SpineAnimationStateBehaviour>)playable.GetInput(lastNonZeroWeightTrack - 1);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_44 = ___playable0;
		int32_t L_45 = V_1;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_46;
		L_46 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_44, ((int32_t)il2cpp_codegen_subtract(L_45, 1)), PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_47;
		L_47 = ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980(L_46, ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		V_12 = L_47;
		// var fromClipData = fromClip.GetBehaviour();
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_48;
		L_48 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_12), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		V_13 = L_48;
		// fromAnimation = fromClipData.animationReference != null ? fromClipData.animationReference.Animation : null;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_49 = V_13;
		NullCheck(L_49);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_50 = L_49->___animationReference_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_51;
		L_51 = Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7(L_50, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_51)
		{
			goto IL_010a;
		}
	}
	{
		G_B22_0 = ((Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)(NULL));
		goto IL_0116;
	}

IL_010a:
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_52 = V_13;
		NullCheck(L_52);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_53 = L_52->___animationReference_0;
		NullCheck(L_53);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_54;
		L_54 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_53, NULL);
		G_B22_0 = L_54;
	}

IL_0116:
	{
		V_6 = G_B22_0;
		// fromClipTime = (float)fromClip.GetTime() * (float)fromClip.GetSpeed();
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_55 = V_12;
		double L_56;
		L_56 = PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A(L_55, PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_57 = V_12;
		double L_58;
		L_58 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_57, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		V_7 = ((float)il2cpp_codegen_multiply(((float)L_56), ((float)L_58)));
		// fromClipLoop = fromClipData.loop;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_59 = V_13;
		NullCheck(L_59);
		bool L_60 = L_59->___loop_1;
		V_8 = L_60;
	}

IL_0134:
	{
		// Animation toAnimation = clipData.animationReference != null ? clipData.animationReference.Animation : null;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_61 = V_4;
		NullCheck(L_61);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_62 = L_61->___animationReference_0;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_63;
		L_63 = Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7(L_62, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (L_63)
		{
			goto IL_0146;
		}
	}
	{
		G_B26_0 = ((Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)(NULL));
		goto IL_0152;
	}

IL_0146:
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_64 = V_4;
		NullCheck(L_64);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_65 = L_64->___animationReference_0;
		NullCheck(L_65);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_66;
		L_66 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_65, NULL);
		G_B26_0 = L_66;
	}

IL_0152:
	{
		V_9 = G_B26_0;
		// float toClipTime = (float)inputPlayableClip.GetTime() * (float)inputPlayableClip.GetSpeed();
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_67 = V_3;
		double L_68;
		L_68 = PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A(L_67, PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_69 = V_3;
		double L_70;
		L_70 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_69, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		V_10 = ((float)il2cpp_codegen_multiply(((float)L_68), ((float)L_70)));
		// float mixDuration = clipData.mixDuration;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_71 = V_4;
		NullCheck(L_71);
		float L_72 = L_71->___mixDuration_5;
		V_11 = L_72;
		// if (!clipData.customDuration && fromAnimation != null && toAnimation != null) {
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_73 = V_4;
		NullCheck(L_73);
		bool L_74 = L_73->___customDuration_2;
		if (L_74)
		{
			goto IL_0195;
		}
	}
	{
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_75 = V_6;
		if (!L_75)
		{
			goto IL_0195;
		}
	}
	{
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_76 = V_9;
		if (!L_76)
		{
			goto IL_0195;
		}
	}
	{
		// mixDuration = animationStateComponent.AnimationState.Data.GetMix(fromAnimation, toAnimation);
		RuntimeObject* L_77 = ___animationStateComponent2;
		NullCheck(L_77);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_78;
		L_78 = InterfaceFuncInvoker0< AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* >::Invoke(0 /* Spine.AnimationState Spine.Unity.IAnimationStateComponent::get_AnimationState() */, IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var, L_77);
		NullCheck(L_78);
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_79;
		L_79 = AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C_inline(L_78, NULL);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_80 = V_6;
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_81 = V_9;
		NullCheck(L_79);
		float L_82;
		L_82 = AnimationStateData_GetMix_m1F69969EB5ED5B0523496EEF610D195C756F1C9E(L_79, L_80, L_81, NULL);
		V_11 = L_82;
	}

IL_0195:
	{
		// if (trackIndex == 0)
		int32_t L_83 = __this->___trackIndex_1;
		if (L_83)
		{
			goto IL_01a4;
		}
	}
	{
		// skeleton.SetToSetupPose();
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_84 = V_5;
		NullCheck(L_84);
		Skeleton_SetToSetupPose_m12FBF0ABCEA99C4795C39EF74008F5372894DD71(L_84, NULL);
	}

IL_01a4:
	{
		// if (fromAnimation != null && mixDuration > 0 && toClipTime < mixDuration) {
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_85 = V_6;
		if (!L_85)
		{
			goto IL_02ad;
		}
	}
	{
		float L_86 = V_11;
		if ((!(((float)L_86) > ((float)(0.0f)))))
		{
			goto IL_02ad;
		}
	}
	{
		float L_87 = V_10;
		float L_88 = V_11;
		if ((!(((float)L_87) < ((float)L_88))))
		{
			goto IL_02ad;
		}
	}
	{
		// dummyAnimationState = dummyAnimationState ?? new AnimationState(skeletonComponent.SkeletonDataAsset.GetAnimationStateData());
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_89 = __this->___dummyAnimationState_2;
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_90 = L_89;
		G_B36_0 = L_90;
		G_B36_1 = __this;
		if (L_90)
		{
			G_B37_0 = L_90;
			G_B37_1 = __this;
			goto IL_01db;
		}
	}
	{
		RuntimeObject* L_91 = ___skeletonComponent1;
		NullCheck(L_91);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_92;
		L_92 = InterfaceFuncInvoker0< SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* >::Invoke(0 /* Spine.Unity.SkeletonDataAsset Spine.Unity.ISkeletonComponent::get_SkeletonDataAsset() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_91);
		NullCheck(L_92);
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_93;
		L_93 = SkeletonDataAsset_GetAnimationStateData_m26E2621493EF9FC9D9673FA9C74B48D32D09AF9C(L_92, NULL);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_94 = (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC*)il2cpp_codegen_object_new(AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_il2cpp_TypeInfo_var);
		NullCheck(L_94);
		AnimationState__ctor_m633A801A8038EF0840C36EF102705EE1B6690145(L_94, L_93, NULL);
		G_B37_0 = L_94;
		G_B37_1 = G_B36_1;
	}

IL_01db:
	{
		NullCheck(G_B37_1);
		G_B37_1->___dummyAnimationState_2 = G_B37_0;
		Il2CppCodeGenWriteBarrier((void**)(&G_B37_1->___dummyAnimationState_2), (void*)G_B37_0);
		// var toTrack = dummyAnimationState.GetCurrent(0);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_95 = __this->___dummyAnimationState_2;
		NullCheck(L_95);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_96;
		L_96 = AnimationState_GetCurrent_m56ACBF9037B2D88C1134F0FC9D9927CD9E1DEA02(L_95, 0, NULL);
		V_14 = L_96;
		// var fromTrack = toTrack != null ? toTrack.MixingFrom : null;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_97 = V_14;
		if (L_97)
		{
			goto IL_01f5;
		}
	}
	{
		G_B40_0 = ((TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB*)(NULL));
		goto IL_01fc;
	}

IL_01f5:
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_98 = V_14;
		NullCheck(L_98);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_99;
		L_99 = TrackEntry_get_MixingFrom_m7598E2772B37B33B23647FD261DDD3FEA15B9B25_inline(L_98, NULL);
		G_B40_0 = L_99;
	}

IL_01fc:
	{
		V_15 = G_B40_0;
		// bool isAnimationTransitionMatch = (toTrack != null && toTrack.Animation == toAnimation && fromTrack != null && fromTrack.Animation == fromAnimation);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_100 = V_14;
		if (!L_100)
		{
			goto IL_021e;
		}
	}
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_101 = V_14;
		NullCheck(L_101);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_102;
		L_102 = TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775_inline(L_101, NULL);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_103 = V_9;
		if ((!(((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_102) == ((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_103))))
		{
			goto IL_021e;
		}
	}
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_104 = V_15;
		if (!L_104)
		{
			goto IL_021e;
		}
	}
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_105 = V_15;
		NullCheck(L_105);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_106;
		L_106 = TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775_inline(L_105, NULL);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_107 = V_6;
		G_B45_0 = ((((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_106) == ((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_107))? 1 : 0);
		goto IL_021f;
	}

IL_021e:
	{
		G_B45_0 = 0;
	}

IL_021f:
	{
		// if (!isAnimationTransitionMatch) {
		if (G_B45_0)
		{
			goto IL_026e;
		}
	}
	{
		// dummyAnimationState.ClearTracks();
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_108 = __this->___dummyAnimationState_2;
		NullCheck(L_108);
		AnimationState_ClearTracks_mA999F7457875DB7A591547FB7AE9BAE7D8B263B5(L_108, NULL);
		// fromTrack = dummyAnimationState.SetAnimation(0, fromAnimation, fromClipLoop);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_109 = __this->___dummyAnimationState_2;
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_110 = V_6;
		bool L_111 = V_8;
		NullCheck(L_109);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_112;
		L_112 = AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D(L_109, 0, L_110, L_111, NULL);
		V_15 = L_112;
		// fromTrack.AllowImmediateQueue();
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_113 = V_15;
		SpineSkeletonExtensions_AllowImmediateQueue_m6450A5DD17C6052864A9C9866A614ED1857036A8(L_113, NULL);
		// if (toAnimation != null) {
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_114 = V_9;
		if (!L_114)
		{
			goto IL_026e;
		}
	}
	{
		// toTrack = dummyAnimationState.SetAnimation(0, toAnimation, clipData.loop);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_115 = __this->___dummyAnimationState_2;
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_116 = V_9;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_117 = V_4;
		NullCheck(L_117);
		bool L_118 = L_117->___loop_1;
		NullCheck(L_115);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_119;
		L_119 = AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D(L_115, 0, L_116, L_118, NULL);
		V_14 = L_119;
		// toTrack.HoldPrevious = clipData.holdPrevious;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_120 = V_14;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_121 = V_4;
		NullCheck(L_121);
		bool L_122 = L_121->___holdPrevious_6;
		NullCheck(L_120);
		TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3_inline(L_120, L_122, NULL);
	}

IL_026e:
	{
		// fromTrack.TrackTime = fromClipTime;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_123 = V_15;
		float L_124 = V_7;
		NullCheck(L_123);
		TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3_inline(L_123, L_124, NULL);
		// if (toTrack != null) {
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_125 = V_14;
		if (!L_125)
		{
			goto IL_028d;
		}
	}
	{
		// toTrack.TrackTime = toClipTime;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_126 = V_14;
		float L_127 = V_10;
		NullCheck(L_126);
		TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3_inline(L_126, L_127, NULL);
		// toTrack.MixTime = toClipTime;
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_128 = V_14;
		float L_129 = V_10;
		NullCheck(L_128);
		TrackEntry_set_MixTime_mA8371A354DA49CDCF4415ED4F23943C03013206D_inline(L_128, L_129, NULL);
	}

IL_028d:
	{
		// dummyAnimationState.Update(0);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_130 = __this->___dummyAnimationState_2;
		NullCheck(L_130);
		AnimationState_Update_mF60411EBD6B62050473B445C624110B5FBFACA20(L_130, (0.0f), NULL);
		// dummyAnimationState.Apply(skeleton);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_131 = __this->___dummyAnimationState_2;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_132 = V_5;
		NullCheck(L_131);
		bool L_133;
		L_133 = AnimationState_Apply_mB430A13C849E59376436A50476EB6811FC14E25A(L_131, L_132, NULL);
		goto IL_02d0;
	}

IL_02ad:
	{
		// if (toAnimation != null)
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_134 = V_9;
		if (!L_134)
		{
			goto IL_02d0;
		}
	}
	{
		// toAnimation.Apply(skeleton, 0, toClipTime, clipData.loop, null, 1f, MixBlend.Setup, MixDirection.In);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_135 = V_9;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_136 = V_5;
		float L_137 = V_10;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_138 = V_4;
		NullCheck(L_138);
		bool L_139 = L_138->___loop_1;
		NullCheck(L_135);
		Animation_Apply_mC43B0C9C2690CCB590A9332824DB73DF94A42608(L_135, L_136, (0.0f), L_137, L_139, (ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E*)NULL, (1.0f), 0, 0, NULL);
	}

IL_02d0:
	{
		// skeleton.UpdateWorldTransform();
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_140 = V_5;
		NullCheck(L_140);
		Skeleton_UpdateWorldTransform_m12FD1ACD50E9E19EA655B9F4CCD1F39F59B06F92(L_140, NULL);
		// if (skeletonAnimation)
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_141 = ___skeletonAnimation3;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_142;
		L_142 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_141, NULL);
		if (!L_142)
		{
			goto IL_02e8;
		}
	}
	{
		// skeletonAnimation.LateUpdate();
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_143 = ___skeletonAnimation3;
		NullCheck(L_143);
		VirtualActionInvoker0::Invoke(10 /* System.Void Spine.Unity.SkeletonRenderer::LateUpdate() */, L_143);
		return;
	}

IL_02e8:
	{
		// else if (skeletonGraphic)
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_144 = ___skeletonGraphic4;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_145;
		L_145 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_144, NULL);
		if (!L_145)
		{
			goto IL_02f8;
		}
	}
	{
		// skeletonGraphic.LateUpdate();
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_146 = ___skeletonGraphic4;
		NullCheck(L_146);
		SkeletonGraphic_LateUpdate_m6A04288EA0CEDAE3A87FC0BC09E797D70B9D4347(L_146, NULL);
	}

IL_02f8:
	{
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateMixerBehaviour__ctor_m6BD590C29289864A712F30981FE66DF5A1545834 (SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* __this, const RuntimeMethod* method) 
{
	{
		PlayableBehaviour__ctor_mA6202DCD846F0DDFC5963764A404EE8AFABEA23A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// UnityEngine.Playables.Playable Spine.Unity.Playables.SpineAnimationStateTrack::CreateTrackMixer(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineAnimationStateTrack_CreateTrackMixer_m2B0FAA0C0DEF16A83A49FC3631C4619D79804D9E (SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___go1, int32_t ___inputCount2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D V_0;
	memset((&V_0), 0, sizeof(V_0));
	{
		// var scriptPlayable = ScriptPlayable<SpineAnimationStateMixerBehaviour>.Create(graph, inputCount);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		int32_t L_1 = ___inputCount2;
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_2;
		L_2 = ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F(L_0, L_1, ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		V_0 = L_2;
		// var mixerBehaviour = scriptPlayable.GetBehaviour();
		SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* L_3;
		L_3 = ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4((&V_0), ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		// mixerBehaviour.trackIndex = this.trackIndex;
		int32_t L_4 = __this->___trackIndex_28;
		NullCheck(L_3);
		L_3->___trackIndex_1 = L_4;
		// return scriptPlayable;
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_5 = V_0;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_6;
		L_6 = ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5(L_5, ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		return L_6;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateTrack::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateTrack__ctor_m5C08385174D879806AE50459A3288C5CE649BCA5 (SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::ProcessFrame(UnityEngine.Playables.Playable,UnityEngine.Playables.FrameData,System.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour_ProcessFrame_mE4F7C08F019E4F32DEAEF9E86BC0A15CBC4CC613 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, FrameData_t02E705D0271F73A24ADF9BA4B6F8760B6696F314 ___info1, RuntimeObject* ___playerData2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_0 = NULL;
	int32_t V_1 = 0;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	int32_t V_4 = 0;
	int32_t V_5 = 0;
	float V_6 = 0.0f;
	ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 V_7;
	memset((&V_7), 0, sizeof(V_7));
	SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* V_8 = NULL;
	{
		// playableHandle = playerData as SpinePlayableHandleBase;
		RuntimeObject* L_0 = ___playerData2;
		__this->___playableHandle_4 = ((SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570*)IsInstClass((RuntimeObject*)L_0, SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___playableHandle_4), (void*)((SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570*)IsInstClass((RuntimeObject*)L_0, SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var)));
		// if (playableHandle == null)
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_1 = __this->___playableHandle_4;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_2)
		{
			goto IL_001b;
		}
	}
	{
		// return;
		return;
	}

IL_001b:
	{
		// var skeleton = playableHandle.Skeleton;
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_3 = __this->___playableHandle_4;
		NullCheck(L_3);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_4;
		L_4 = VirtualFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(5 /* Spine.Skeleton Spine.Unity.Playables.SpinePlayableHandleBase::get_Skeleton() */, L_3);
		V_0 = L_4;
		// if (!m_FirstFrameHappened) {
		bool L_5 = __this->___m_FirstFrameHappened_5;
		if (L_5)
		{
			goto IL_0070;
		}
	}
	{
		// originalScaleX = skeleton.ScaleX;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_6 = V_0;
		NullCheck(L_6);
		float L_7;
		L_7 = Skeleton_get_ScaleX_m0172910DB4B5C924E6010D1F7E41127B01E70FB3_inline(L_6, NULL);
		__this->___originalScaleX_0 = L_7;
		// originalScaleY = skeleton.ScaleY;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_8 = V_0;
		NullCheck(L_8);
		float L_9;
		L_9 = Skeleton_get_ScaleY_m57C4D92B37F5622B9283BA4C8FD4A94C49D982B4(L_8, NULL);
		__this->___originalScaleY_1 = L_9;
		// baseScaleX = Mathf.Abs(originalScaleX);
		float L_10 = __this->___originalScaleX_0;
		float L_11;
		L_11 = fabsf(L_10);
		__this->___baseScaleX_2 = L_11;
		// baseScaleY = Mathf.Abs(originalScaleY);
		float L_12 = __this->___originalScaleY_1;
		float L_13;
		L_13 = fabsf(L_12);
		__this->___baseScaleY_3 = L_13;
		// m_FirstFrameHappened = true;
		__this->___m_FirstFrameHappened_5 = (bool)1;
	}

IL_0070:
	{
		// int inputCount = playable.GetInputCount();
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_14 = ___playable0;
		int32_t L_15;
		L_15 = PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9(L_14, PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		V_1 = L_15;
		// float totalWeight = 0f;
		V_2 = (0.0f);
		// float greatestWeight = 0f;
		V_3 = (0.0f);
		// int currentInputs = 0;
		V_4 = 0;
		// for (int i = 0; i < inputCount; i++) {
		V_5 = 0;
		goto IL_00e9;
	}

IL_008b:
	{
		// float inputWeight = playable.GetInputWeight(i);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_16 = ___playable0;
		int32_t L_17 = V_5;
		float L_18;
		L_18 = PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B(L_16, L_17, PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		V_6 = L_18;
		// ScriptPlayable<SpineSkeletonFlipBehaviour> inputPlayable = (ScriptPlayable<SpineSkeletonFlipBehaviour>)playable.GetInput(i);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_19 = ___playable0;
		int32_t L_20 = V_5;
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_21;
		L_21 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_19, L_20, PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 L_22;
		L_22 = ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E(L_21, ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E_RuntimeMethod_var);
		V_7 = L_22;
		// SpineSkeletonFlipBehaviour input = inputPlayable.GetBehaviour();
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_23;
		L_23 = ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED((&V_7), ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED_RuntimeMethod_var);
		V_8 = L_23;
		// totalWeight += inputWeight;
		float L_24 = V_2;
		float L_25 = V_6;
		V_2 = ((float)il2cpp_codegen_add(L_24, L_25));
		// if (inputWeight > greatestWeight) {
		float L_26 = V_6;
		float L_27 = V_3;
		if ((!(((float)L_26) > ((float)L_27))))
		{
			goto IL_00cf;
		}
	}
	{
		// SetSkeletonScaleFromFlip(skeleton, input.flipX, input.flipY);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_28 = V_0;
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_29 = V_8;
		NullCheck(L_29);
		bool L_30 = L_29->___flipX_0;
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_31 = V_8;
		NullCheck(L_31);
		bool L_32 = L_31->___flipY_1;
		SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5(__this, L_28, L_30, L_32, NULL);
		// greatestWeight = inputWeight;
		float L_33 = V_6;
		V_3 = L_33;
	}

IL_00cf:
	{
		// if (!Mathf.Approximately(inputWeight, 0f))
		float L_34 = V_6;
		bool L_35;
		L_35 = Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_inline(L_34, (0.0f), NULL);
		if (L_35)
		{
			goto IL_00e3;
		}
	}
	{
		// currentInputs++;
		int32_t L_36 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_36, 1));
	}

IL_00e3:
	{
		// for (int i = 0; i < inputCount; i++) {
		int32_t L_37 = V_5;
		V_5 = ((int32_t)il2cpp_codegen_add(L_37, 1));
	}

IL_00e9:
	{
		// for (int i = 0; i < inputCount; i++) {
		int32_t L_38 = V_5;
		int32_t L_39 = V_1;
		if ((((int32_t)L_38) < ((int32_t)L_39)))
		{
			goto IL_008b;
		}
	}
	{
		// if (currentInputs != 1 && 1f - totalWeight > greatestWeight) {
		int32_t L_40 = V_4;
		if ((((int32_t)L_40) == ((int32_t)1)))
		{
			goto IL_0115;
		}
	}
	{
		float L_41 = V_2;
		float L_42 = V_3;
		if ((!(((float)((float)il2cpp_codegen_subtract((1.0f), L_41))) > ((float)L_42))))
		{
			goto IL_0115;
		}
	}
	{
		// skeleton.ScaleX = originalScaleX;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_43 = V_0;
		float L_44 = __this->___originalScaleX_0;
		NullCheck(L_43);
		Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02_inline(L_43, L_44, NULL);
		// skeleton.ScaleY = originalScaleY;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_45 = V_0;
		float L_46 = __this->___originalScaleY_1;
		NullCheck(L_45);
		Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A_inline(L_45, L_46, NULL);
	}

IL_0115:
	{
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::SetSkeletonScaleFromFlip(Spine.Skeleton,System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, bool ___flipX1, bool ___flipY2, const RuntimeMethod* method) 
{
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B2_0 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B1_0 = NULL;
	float G_B3_0 = 0.0f;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B3_1 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B5_0 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B4_0 = NULL;
	float G_B6_0 = 0.0f;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B6_1 = NULL;
	{
		// skeleton.ScaleX = flipX ? -baseScaleX : baseScaleX;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_0 = ___skeleton0;
		bool L_1 = ___flipX1;
		G_B1_0 = L_0;
		if (L_1)
		{
			G_B2_0 = L_0;
			goto IL_000c;
		}
	}
	{
		float L_2 = __this->___baseScaleX_2;
		G_B3_0 = L_2;
		G_B3_1 = G_B1_0;
		goto IL_0013;
	}

IL_000c:
	{
		float L_3 = __this->___baseScaleX_2;
		G_B3_0 = ((-L_3));
		G_B3_1 = G_B2_0;
	}

IL_0013:
	{
		NullCheck(G_B3_1);
		Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02_inline(G_B3_1, G_B3_0, NULL);
		// skeleton.ScaleY = flipY ? -baseScaleY : baseScaleY;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_4 = ___skeleton0;
		bool L_5 = ___flipY2;
		G_B4_0 = L_4;
		if (L_5)
		{
			G_B5_0 = L_4;
			goto IL_0024;
		}
	}
	{
		float L_6 = __this->___baseScaleY_3;
		G_B6_0 = L_6;
		G_B6_1 = G_B4_0;
		goto IL_002b;
	}

IL_0024:
	{
		float L_7 = __this->___baseScaleY_3;
		G_B6_0 = ((-L_7));
		G_B6_1 = G_B5_0;
	}

IL_002b:
	{
		NullCheck(G_B6_1);
		Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A_inline(G_B6_1, G_B6_0, NULL);
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::OnGraphStop(UnityEngine.Playables.Playable)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour_OnGraphStop_m5EA7912190C81F89762618BF49F00555C8978537 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// m_FirstFrameHappened = false;
		__this->___m_FirstFrameHappened_5 = (bool)0;
		// if (playableHandle == null)
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_0 = __this->___playableHandle_4;
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		if (!L_1)
		{
			goto IL_0016;
		}
	}
	{
		// return;
		return;
	}

IL_0016:
	{
		// var skeleton = playableHandle.Skeleton;
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_2 = __this->___playableHandle_4;
		NullCheck(L_2);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_3;
		L_3 = VirtualFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(5 /* Spine.Skeleton Spine.Unity.Playables.SpinePlayableHandleBase::get_Skeleton() */, L_2);
		// skeleton.ScaleX = originalScaleX;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_4 = L_3;
		float L_5 = __this->___originalScaleX_0;
		NullCheck(L_4);
		Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02_inline(L_4, L_5, NULL);
		// skeleton.ScaleY = originalScaleY;
		float L_6 = __this->___originalScaleY_1;
		NullCheck(L_4);
		Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A_inline(L_4, L_6, NULL);
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour__ctor_m9975EEBA7F6FC321B1DC75E4D937270E5AB80CF9 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, const RuntimeMethod* method) 
{
	{
		PlayableBehaviour__ctor_mA6202DCD846F0DDFC5963764A404EE8AFABEA23A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// UnityEngine.Playables.Playable Spine.Unity.Playables.SpineSkeletonFlipTrack::CreateTrackMixer(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject,System.Int32)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineSkeletonFlipTrack_CreateTrackMixer_m03EDED11E716C641B10EB6FBE1C763B7DE770048 (SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___go1, int32_t ___inputCount2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		// return ScriptPlayable<SpineSkeletonFlipMixerBehaviour>.Create(graph, inputCount);
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		int32_t L_1 = ___inputCount2;
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB L_2;
		L_2 = ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB(L_0, L_1, ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB_RuntimeMethod_var);
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_3;
		L_3 = ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61(L_2, ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61_RuntimeMethod_var);
		return L_3;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipTrack::GatherProperties(UnityEngine.Playables.PlayableDirector,UnityEngine.Timeline.IPropertyCollector)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipTrack_GatherProperties_m8DC1508AB025A66D158D852A7FBC71240AFA68DB (SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0* __this, PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475* ___director0, RuntimeObject* ___driver1, const RuntimeMethod* method) 
{
	{
		// base.GatherProperties(director, driver);
		PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475* L_0 = ___director0;
		RuntimeObject* L_1 = ___driver1;
		TrackAsset_GatherProperties_m09C1A335FCE1ABA158748583AF4A641FF2EBB09D(__this, L_0, L_1, NULL);
		// }
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipTrack::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipTrack__ctor_m72A9FAC6E5FE629734F1581BFD47F0F418EC6514 (SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	{
		il2cpp_codegen_runtime_class_init_inline(TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) 
{
	{
		// public SkeletonData Data { get { return data; } }
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_0 = __this->___data_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_inline (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___e0, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Animation_get_Duration_m385D29E0C137F21E8AD0DD9A945C0610AF175632_inline (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* __this, const RuntimeMethod* method) 
{
	{
		// public float Duration { get { return duration; } set { duration = value; } }
		float L_0 = __this->___duration_3;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C_inline (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, const RuntimeMethod* method) 
{
	{
		// return data;
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_0 = __this->___data_8;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float AnimationStateData_get_DefaultMix_m4BDB14E9DF538918293CF58F4D62B7DB49AAB476_inline (AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* __this, const RuntimeMethod* method) 
{
	{
		// public float DefaultMix { get { return defaultMix; } set { defaultMix = value; } }
		float L_0 = __this->___defaultMix_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_EventThreshold_mB58AD3053F5C702066F23AE2DBD52F4DD6DE2823_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float EventThreshold { get { return eventThreshold; } set { eventThreshold = value; } }
		float L_0 = ___value0;
		__this->___eventThreshold_13 = L_0;
		// public float EventThreshold { get { return eventThreshold; } set { eventThreshold = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_DrawOrderThreshold_mB1343F81A778546FDE7464B66698B838A44F24F3_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float DrawOrderThreshold { get { return drawOrderThreshold; } set { drawOrderThreshold = value; } }
		float L_0 = ___value0;
		__this->___drawOrderThreshold_15 = L_0;
		// public float DrawOrderThreshold { get { return drawOrderThreshold; } set { drawOrderThreshold = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float TrackTime { get { return trackTime; } set { trackTime = value; } }
		float L_0 = ___value0;
		__this->___trackTime_21 = L_0;
		// public float TrackTime { get { return trackTime; } set { trackTime = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_TimeScale_m9C6DC53ED8731A1A5A3EE825BEF667BA848A8588_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float TimeScale { get { return timeScale; } set { timeScale = value; } }
		float L_0 = ___value0;
		__this->___timeScale_25 = L_0;
		// public float TimeScale { get { return timeScale; } set { timeScale = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_AttachmentThreshold_mA75133539615A962566CE1CAAA1FFB9ED49A3DC0_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float AttachmentThreshold { get { return attachmentThreshold; } set { attachmentThreshold = value; } }
		float L_0 = ___value0;
		__this->___attachmentThreshold_14 = L_0;
		// public float AttachmentThreshold { get { return attachmentThreshold; } set { attachmentThreshold = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, bool ___value0, const RuntimeMethod* method) 
{
	{
		// public bool HoldPrevious { get { return holdPrevious; } set { holdPrevious = value; } }
		bool L_0 = ___value0;
		__this->___holdPrevious_12 = L_0;
		// public bool HoldPrevious { get { return holdPrevious; } set { holdPrevious = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_MixDuration_m22C7A7BDE2F947A311BC27093C0C5B96B4CA9C55_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float MixDuration { get { return mixDuration; } set { mixDuration = value; } }
		float L_0 = ___value0;
		__this->___mixDuration_28 = L_0;
		// public float MixDuration { get { return mixDuration; } set { mixDuration = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E_inline (AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* __this, const RuntimeMethod* method) 
{
	{
		// public SkeletonDataAsset SkeletonDataAsset { get { return skeletonDataAsset; } }
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_0 = __this->___skeletonDataAsset_5;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* TrackEntry_get_MixingFrom_m7598E2772B37B33B23647FD261DDD3FEA15B9B25_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, const RuntimeMethod* method) 
{
	{
		// public TrackEntry MixingFrom { get { return mixingFrom; } }
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_0 = __this->___mixingFrom_2;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, const RuntimeMethod* method) 
{
	{
		// public Animation Animation { get { return animation; } }
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_0 = __this->___animation_0;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void TrackEntry_set_MixTime_mA8371A354DA49CDCF4415ED4F23943C03013206D_inline (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float MixTime { get { return mixTime; } set { mixTime = value; } }
		float L_0 = ___value0;
		__this->___mixTime_27 = L_0;
		// public float MixTime { get { return mixTime; } set { mixTime = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Skeleton_get_ScaleX_m0172910DB4B5C924E6010D1F7E41127B01E70FB3_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) 
{
	{
		// public float ScaleX { get { return scaleX; } set { scaleX = value; } }
		float L_0 = __this->___scaleX_15;
		return L_0;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_inline (float ___a0, float ___b1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	{
		float L_0 = ___b1;
		float L_1 = ___a0;
		float L_2;
		L_2 = fabsf(((float)il2cpp_codegen_subtract(L_0, L_1)));
		float L_3 = ___a0;
		float L_4;
		L_4 = fabsf(L_3);
		float L_5 = ___b1;
		float L_6;
		L_6 = fabsf(L_5);
		float L_7;
		L_7 = Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline(L_4, L_6, NULL);
		float L_8 = ((Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields*)il2cpp_codegen_static_fields_for(Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var))->___Epsilon_0;
		float L_9;
		L_9 = Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline(((float)il2cpp_codegen_multiply((9.99999997E-07f), L_7)), ((float)il2cpp_codegen_multiply(L_8, (8.0f))), NULL);
		V_0 = (bool)((((float)L_2) < ((float)L_9))? 1 : 0);
		goto IL_0035;
	}

IL_0035:
	{
		bool L_10 = V_0;
		return L_10;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float ScaleX { get { return scaleX; } set { scaleX = value; } }
		float L_0 = ___value0;
		__this->___scaleX_15 = L_0;
		// public float ScaleX { get { return scaleX; } set { scaleX = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A_inline (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, float ___value0, const RuntimeMethod* method) 
{
	{
		// public float ScaleY { get { return scaleY * (Bone.yDown ? -1 : 1); } set { scaleY = value; } }
		float L_0 = ___value0;
		__this->___scaleY_16 = L_0;
		// public float ScaleY { get { return scaleY * (Bone.yDown ? -1 : 1); } set { scaleY = value; } }
		return;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline (float ___a0, float ___b1, const RuntimeMethod* method) 
{
	float V_0 = 0.0f;
	float G_B3_0 = 0.0f;
	{
		float L_0 = ___a0;
		float L_1 = ___b1;
		if ((((float)L_0) > ((float)L_1)))
		{
			goto IL_0008;
		}
	}
	{
		float L_2 = ___b1;
		G_B3_0 = L_2;
		goto IL_0009;
	}

IL_0008:
	{
		float L_3 = ___a0;
		G_B3_0 = L_3;
	}

IL_0009:
	{
		V_0 = G_B3_0;
		goto IL_000c;
	}

IL_000c:
	{
		float L_4 = V_0;
		return L_4;
	}
}
