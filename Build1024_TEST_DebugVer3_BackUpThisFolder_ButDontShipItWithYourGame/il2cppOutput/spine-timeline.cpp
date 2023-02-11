#include "pch-cpp.hpp"

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

IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnityEngine_CoreModule[];
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsspineU2Dtimeline[];
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
IL2CPP_EXTERN_C const RuntimeMethod* Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_RuntimeMethod_var;
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
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonAnimationPlayableHandle_Awake_mA343FDAE99E4B98DDB6C96D985F7193CCFC5D227_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonAnimationPlayableHandle__ctor_m6A65DED137CE9B7ED9C77199722D62598425FEC8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonAnimationPlayableHandle_get_SkeletonData_m36D235853CFB1D380745ED1AA7CC68773016CFD0_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonAnimationPlayableHandle_get_Skeleton_m89A242C9232F14E6DF6382DF1D6CD658EE2BA48E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonGraphicPlayableHandle_Awake_m7ABB8022D2B8152BFACE481917F5393D278A05EB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonGraphicPlayableHandle__ctor_m7C062CD4809F306523558512A8522CBE8E43B269_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonGraphicPlayableHandle_get_SkeletonData_mA4647B64590B1087D466C782D2A5B9A333072C54_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SkeletonGraphicPlayableHandle_get_Skeleton_m22DBF626CEA9ADF5343A0571486FDEC32B7D34AD_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateClip_CreatePlayable_mD1032BDA98B16C19C16AC3C25326B055599BC807_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateClip__ctor_mF7502B962F50B8CE59DDBF0FE22707E7B329FD28_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateClip_get_clipCaps_mCF30A930DA45E24FDDC483BC189383E962400961_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateClip_get_duration_mA39B55EF9045326BABC1886E94F952E2AA6613F8_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateGraphicTrack_CreateTrackMixer_mBC3BC55D62A0B73D6346E60C3A6A783BF89E879B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateGraphicTrack__ctor_m4865F8FA9ECBCCC65A4011A7A00D4DB2CFB8D3BB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateMixerBehaviour_ProcessFrame_mF5BA9FDFE0AC4CE04804BA76342A32060F55AC5B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateMixerBehaviour__ctor_m6BD590C29289864A712F30981FE66DF5A1545834_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateTrack_CreateTrackMixer_m2B0FAA0C0DEF16A83A49FC3631C4619D79804D9E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineAnimationStateTrack__ctor_m5C08385174D879806AE50459A3288C5CE649BCA5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpinePlayableHandleBase_HandleEvents_m21536E264F6D4799B403DE3B8527A05B625C595A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpinePlayableHandleBase_add_AnimationEvents_m02560BDC4FD5A3507CDC2EF1F8995886E958AD20_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpinePlayableHandleBase_remove_AnimationEvents_m3D95EFCF9BFF6E8EA70A8ECA6E6AC2CE2B891D16_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipClip_CreatePlayable_m399DFE9F9DEC2D9A22FC6AC492B091F2DC36C855_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipClip__ctor_mDE5A2A09432F92FC654EFD404444C89D7651322B_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipClip_get_clipCaps_mFDD25F831A3BC37B82501293FB4DDD97F919C8A1_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipMixerBehaviour_OnGraphStop_m5EA7912190C81F89762618BF49F00555C8978537_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipMixerBehaviour_ProcessFrame_mE4F7C08F019E4F32DEAEF9E86BC0A15CBC4CC613_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipMixerBehaviour__ctor_m9975EEBA7F6FC321B1DC75E4D937270E5AB80CF9_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipTrack_CreateTrackMixer_m03EDED11E716C641B10EB6FBE1C763B7DE770048_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipTrack_GatherProperties_m8DC1508AB025A66D158D852A7FBC71240AFA68DB_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeMethod* SpineSkeletonFlipTrack__ctor_m72A9FAC6E5FE629734F1581BFD47F0F418EC6514_RuntimeMethod_var;
IL2CPP_EXTERN_C const RuntimeType* AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ClipCaps_t5A4215235745856AF28238667B359DD8C4BD76DE_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB_0_0_0_var;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Animation_get_Duration_m385D29E0C137F21E8AD0DD9A945C0610AF175632 (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* __this, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, const RuntimeMethod* method) ;
// System.Single Spine.AnimationStateData::get_DefaultMix()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float AnimationStateData_get_DefaultMix_m4BDB14E9DF538918293CF58F4D62B7DB49AAB476 (AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* __this, const RuntimeMethod* method) ;
// Spine.TrackEntry Spine.AnimationState::SetEmptyAnimation(System.Int32,System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* AnimationState_SetEmptyAnimation_m2C660F117296347DFF557578CCC42E7215935656 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, int32_t ___trackIndex0, float ___mixDuration1, const RuntimeMethod* method) ;
// Spine.TrackEntry Spine.AnimationState::SetAnimation(System.Int32,Spine.Animation,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, int32_t ___trackIndex0, Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* ___animation1, bool ___loop2, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_EventThreshold(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_EventThreshold_mB58AD3053F5C702066F23AE2DBD52F4DD6DE2823 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_DrawOrderThreshold(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_DrawOrderThreshold_mB1343F81A778546FDE7464B66698B838A44F24F3 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_TimeScale(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_TimeScale_m9C6DC53ED8731A1A5A3EE825BEF667BA848A8588 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_AttachmentThreshold(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_AttachmentThreshold_mA75133539615A962566CE1CAAA1FFB9ED49A3DC0 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_HoldPrevious(System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, bool ___value0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_MixDuration(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_MixDuration_m22C7A7BDE2F947A311BC27093C0C5B96B4CA9C55 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Implicit(UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___exists0, const RuntimeMethod* method) ;
// System.Void Spine.Unity.SkeletonAnimation::Update(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimation_Update_mA405A7645B8BA03A1CD193F3AE50E1D08FBC19D0 (SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* __this, float ___deltaTime0, const RuntimeMethod* method) ;
// System.Void Spine.Unity.SkeletonGraphic::LateUpdate()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphic_LateUpdate_m6A04288EA0CEDAE3A87FC0BC09E797D70B9D4347 (SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* __this, const RuntimeMethod* method) ;
// System.Boolean UnityEngine.Object::op_Inequality(UnityEngine.Object,UnityEngine.Object)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7 (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___x0, Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C* ___y1, const RuntimeMethod* method) ;
// Spine.Unity.SkeletonDataAsset Spine.Unity.AnimationReferenceAsset::get_SkeletonDataAsset()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E (AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* __this, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* TrackEntry_get_MixingFrom_m7598E2772B37B33B23647FD261DDD3FEA15B9B25 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, const RuntimeMethod* method) ;
// Spine.Animation Spine.TrackEntry::get_Animation()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, const RuntimeMethod* method) ;
// System.Void Spine.AnimationState::ClearTracks()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimationState_ClearTracks_mA999F7457875DB7A591547FB7AE9BAE7D8B263B5 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, const RuntimeMethod* method) ;
// System.Void Spine.SpineSkeletonExtensions::AllowImmediateQueue(Spine.TrackEntry)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonExtensions_AllowImmediateQueue_m6450A5DD17C6052864A9C9866A614ED1857036A8 (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* ___trackEntry0, const RuntimeMethod* method) ;
// System.Void Spine.TrackEntry::set_MixTime(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void TrackEntry_set_MixTime_mA8371A354DA49CDCF4415ED4F23943C03013206D (TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.AnimationState::Update(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AnimationState_Update_mF60411EBD6B62050473B445C624110B5FBFACA20 (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, float ___delta0, const RuntimeMethod* method) ;
// System.Boolean Spine.AnimationState::Apply(Spine.Skeleton)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool AnimationState_Apply_mB430A13C849E59376436A50476EB6811FC14E25A (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, const RuntimeMethod* method) ;
// System.Void Spine.Animation::Apply(Spine.Skeleton,System.Single,System.Single,System.Boolean,Spine.ExposedList`1<Spine.Event>,System.Single,Spine.MixBlend,Spine.MixDirection)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Animation_Apply_mC43B0C9C2690CCB590A9332824DB73DF94A42608 (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, float ___lastTime1, float ___time2, bool ___loop3, ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* ___events4, float ___alpha5, int32_t ___blend6, int32_t ___direction7, const RuntimeMethod* method) ;
// System.Void Spine.Skeleton::UpdateWorldTransform()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Skeleton_UpdateWorldTransform_m12FD1ACD50E9E19EA655B9F4CCD1F39F59B06F92 (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
// System.Single Spine.Skeleton::get_ScaleX()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR float Skeleton_get_ScaleX_m0172910DB4B5C924E6010D1F7E41127B01E70FB3 (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, const RuntimeMethod* method) ;
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
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02 (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, float ___value0, const RuntimeMethod* method) ;
// System.Void Spine.Skeleton::set_ScaleY(System.Single)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A (Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* __this, float ___value0, const RuntimeMethod* method) ;
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ClipCaps_t5A4215235745856AF28238667B359DD8C4BD76DE_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipClip_get_clipCaps_mFDD25F831A3BC37B82501293FB4DDD97F919C8A1_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipClip_get_clipCaps_mFDD25F831A3BC37B82501293FB4DDD97F919C8A1_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 0));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 1));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 2));
		// get { return ClipCaps.None; }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 3));
		V_0 = 0;
		goto IL_0005;
	}

IL_0005:
	{
		// get { return ClipCaps.None; }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 4));
		int32_t L_0 = V_0;
		return L_0;
	}
}
// UnityEngine.Playables.Playable SpineSkeletonFlipClip::CreatePlayable(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineSkeletonFlipClip_CreatePlayable_m399DFE9F9DEC2D9A22FC6AC492B091F2DC36C855 (SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___owner1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipClip_CreatePlayable_m399DFE9F9DEC2D9A22FC6AC492B091F2DC36C855_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___graph0), (&___owner1));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipClip_CreatePlayable_m399DFE9F9DEC2D9A22FC6AC492B091F2DC36C855_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 5));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 6));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 7));
		// var playable = ScriptPlayable<SpineSkeletonFlipBehaviour>.Create(graph, template);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 8));
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_1 = __this->___template_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 9));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 L_2;
		L_2 = ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496(L_0, L_1, 0, ScriptPlayable_1_Create_m0813FBB5EF84976D21594C786C01ABF8CBEDE496_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 9));
		V_0 = L_2;
		// return playable;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 10));
		ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 L_3 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 11));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_4;
		L_4 = ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5(L_3, ScriptPlayable_1_op_Implicit_m53E682A855DF8AAED65A7EC0535C9694C3D1DFE5_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 11));
		V_1 = L_4;
		goto IL_0018;
	}

IL_0018:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 12));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_5 = V_1;
		return L_5;
	}
}
// System.Void SpineSkeletonFlipClip::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipClip__ctor_mDE5A2A09432F92FC654EFD404444C89D7651322B (SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipClip__ctor_mDE5A2A09432F92FC654EFD404444C89D7651322B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipClip_tA8D4A8E9E16D7B1A20C9D6AE06072140D0A832F1_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipClip__ctor_mDE5A2A09432F92FC654EFD404444C89D7651322B_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 13));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 14));
	{
		// public SpineSkeletonFlipBehaviour template = new SpineSkeletonFlipBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 15));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 16));
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_0 = (SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE*)il2cpp_codegen_object_new(SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		SpineSkeletonFlipBehaviour__ctor_mBE993B5699493C5A5A95CF0254F80A53E735CD4A(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 16));
		__this->___template_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___template_4), (void*)L_0);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 17));
		PlayableAsset__ctor_m36B842356F02DF323B356BAAF6E3DC59BA9E1AB8(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 17));
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_get_Skeleton_m89A242C9232F14E6DF6382DF1D6CD658EE2BA48E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonAnimationPlayableHandle_get_Skeleton_m89A242C9232F14E6DF6382DF1D6CD658EE2BA48E_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 18));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 19));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 20));
		// public override Skeleton Skeleton {    get { return skeletonAnimation.Skeleton; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 21));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_0 = __this->___skeletonAnimation_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 22));
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonRenderer_get_Skeleton_m4B631F464CF860CC96CB34DF8AF61EE6B4F940BA(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 22));
		V_0 = L_1;
		goto IL_000f;
	}

IL_000f:
	{
		// public override Skeleton Skeleton {    get { return skeletonAnimation.Skeleton; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 23));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_2 = V_0;
		return L_2;
	}
}
// Spine.SkeletonData Spine.Unity.Playables.SkeletonAnimationPlayableHandle::get_SkeletonData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* SkeletonAnimationPlayableHandle_get_SkeletonData_m36D235853CFB1D380745ED1AA7CC68773016CFD0 (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_get_SkeletonData_m36D235853CFB1D380745ED1AA7CC68773016CFD0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonAnimationPlayableHandle_get_SkeletonData_m36D235853CFB1D380745ED1AA7CC68773016CFD0_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 24));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 25));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 26));
		// public override SkeletonData SkeletonData { get { return skeletonAnimation.Skeleton.Data; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 27));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_0 = __this->___skeletonAnimation_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 28));
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonRenderer_get_Skeleton_m4B631F464CF860CC96CB34DF8AF61EE6B4F940BA(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 28));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 29));
		NullCheck(L_1);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_2;
		L_2 = Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA(L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 29));
		V_0 = L_2;
		goto IL_0014;
	}

IL_0014:
	{
		// public override SkeletonData SkeletonData { get { return skeletonAnimation.Skeleton.Data; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 30));
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_3 = V_0;
		return L_3;
	}
}
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle_Awake_mA343FDAE99E4B98DDB6C96D985F7193CCFC5D227 (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_Awake_mA343FDAE99E4B98DDB6C96D985F7193CCFC5D227_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonAnimationPlayableHandle_Awake_mA343FDAE99E4B98DDB6C96D985F7193CCFC5D227_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 31));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 32));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 33));
		// InitializeReference();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 34));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 35));
		SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 35));
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 36));
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::InitializeReference()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonAnimationPlayableHandle_InitializeReference_mD7D34ABF399B197FCD904519BF27BAEC7F635FBC_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 37));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 38));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 39));
		// if (skeletonAnimation == null)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 40));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_0 = __this->___skeletonAnimation_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 41));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 41));
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 42));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_001d;
		}
	}
	{
		// skeletonAnimation = GetComponent<SkeletonAnimation>();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 43));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 44));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_3;
		L_3 = Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49(__this, Component_GetComponent_TisSkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_m6020CEF81684DECD44FF5B722E326D5FB34FDC49_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 44));
		__this->___skeletonAnimation_5 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___skeletonAnimation_5), (void*)L_3);
	}

IL_001d:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 45));
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonAnimationPlayableHandle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonAnimationPlayableHandle__ctor_m6A65DED137CE9B7ED9C77199722D62598425FEC8 (SkeletonAnimationPlayableHandle_tE4106016529A0CC2A08637A824E085D424710CD2* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimationPlayableHandle__ctor_m6A65DED137CE9B7ED9C77199722D62598425FEC8_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonAnimationPlayableHandle__ctor_m6A65DED137CE9B7ED9C77199722D62598425FEC8_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_get_Skeleton_m22DBF626CEA9ADF5343A0571486FDEC32B7D34AD_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonGraphicPlayableHandle_get_Skeleton_m22DBF626CEA9ADF5343A0571486FDEC32B7D34AD_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 46));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 47));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 48));
		// public override Skeleton Skeleton {    get { return skeletonGraphic.Skeleton; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 49));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_0 = __this->___skeletonGraphic_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 50));
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonGraphic_get_Skeleton_mF8BED82D73B930C6D58A62E787A6DC4DF7055BAF(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 50));
		V_0 = L_1;
		goto IL_000f;
	}

IL_000f:
	{
		// public override Skeleton Skeleton {    get { return skeletonGraphic.Skeleton; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 51));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_2 = V_0;
		return L_2;
	}
}
// Spine.SkeletonData Spine.Unity.Playables.SkeletonGraphicPlayableHandle::get_SkeletonData()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* SkeletonGraphicPlayableHandle_get_SkeletonData_mA4647B64590B1087D466C782D2A5B9A333072C54 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_get_SkeletonData_mA4647B64590B1087D466C782D2A5B9A333072C54_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* V_0 = NULL;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonGraphicPlayableHandle_get_SkeletonData_mA4647B64590B1087D466C782D2A5B9A333072C54_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 52));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 53));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 54));
		// public override SkeletonData SkeletonData { get { return skeletonGraphic.Skeleton.Data; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 55));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_0 = __this->___skeletonGraphic_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 56));
		NullCheck(L_0);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_1;
		L_1 = SkeletonGraphic_get_Skeleton_mF8BED82D73B930C6D58A62E787A6DC4DF7055BAF(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 56));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 57));
		NullCheck(L_1);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_2;
		L_2 = Skeleton_get_Data_m5423B9E46B37D1872DCC9400C76C1D0D47F080FA(L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 57));
		V_0 = L_2;
		goto IL_0014;
	}

IL_0014:
	{
		// public override SkeletonData SkeletonData { get { return skeletonGraphic.Skeleton.Data; } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 58));
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_3 = V_0;
		return L_3;
	}
}
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::Awake()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle_Awake_m7ABB8022D2B8152BFACE481917F5393D278A05EB (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_Awake_m7ABB8022D2B8152BFACE481917F5393D278A05EB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonGraphicPlayableHandle_Awake_m7ABB8022D2B8152BFACE481917F5393D278A05EB_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 59));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 60));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 61));
		// InitializeReference();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 62));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 63));
		SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 63));
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 64));
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::InitializeReference()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonGraphicPlayableHandle_InitializeReference_m76DE63262FE3E1FA61E7A04D5BC426E71741F535_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 65));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 66));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 67));
		// if (skeletonGraphic == null)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 68));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_0 = __this->___skeletonGraphic_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 69));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 69));
		V_0 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 70));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_001d;
		}
	}
	{
		// skeletonGraphic = GetComponent<SkeletonGraphic>();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 71));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 72));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_3;
		L_3 = Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF(__this, Component_GetComponent_TisSkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_m026105FA594104FE1DF3DDFB83E69F29903E1BAF_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 72));
		__this->___skeletonGraphic_5 = L_3;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___skeletonGraphic_5), (void*)L_3);
	}

IL_001d:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 73));
		return;
	}
}
// System.Void Spine.Unity.Playables.SkeletonGraphicPlayableHandle::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SkeletonGraphicPlayableHandle__ctor_m7C062CD4809F306523558512A8522CBE8E43B269 (SkeletonGraphicPlayableHandle_tEAC949A8A1868901D292149D30C790598DED8CEA* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphicPlayableHandle__ctor_m7C062CD4809F306523558512A8522CBE8E43B269_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SkeletonGraphicPlayableHandle__ctor_m7C062CD4809F306523558512A8522CBE8E43B269_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase_add_AnimationEvents_m02560BDC4FD5A3507CDC2EF1F8995886E958AD20_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_0 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_1 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_2 = NULL;
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpinePlayableHandleBase_add_AnimationEvents_m02560BDC4FD5A3507CDC2EF1F8995886E958AD20_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_0 = __this->___AnimationEvents_4;
		V_0 = L_0;
	}

IL_0007:
	{
		CHECK_PAUSE_POINT;
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase_remove_AnimationEvents_m3D95EFCF9BFF6E8EA70A8ECA6E6AC2CE2B891D16_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_0 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_1 = NULL;
	SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* V_2 = NULL;
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpinePlayableHandleBase_remove_AnimationEvents_m3D95EFCF9BFF6E8EA70A8ECA6E6AC2CE2B891D16_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_0 = __this->___AnimationEvents_4;
		V_0 = L_0;
	}

IL_0007:
	{
		CHECK_PAUSE_POINT;
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase_HandleEvents_m21536E264F6D4799B403DE3B8527A05B625C595A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	int32_t V_1 = 0;
	int32_t V_2 = 0;
	bool V_3 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___eventBuffer0));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_1), (&V_2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpinePlayableHandleBase_HandleEvents_m21536E264F6D4799B403DE3B8527A05B625C595A_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 74));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 75));
	int32_t G_B3_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 76));
		// if (eventBuffer == null || AnimationEvents == null) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 77));
		ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* L_0 = ___eventBuffer0;
		if (!L_0)
		{
			goto IL_000f;
		}
	}
	{
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_1 = __this->___AnimationEvents_4;
		G_B3_0 = ((((RuntimeObject*)(SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C*)L_1) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		goto IL_0010;
	}

IL_000f:
	{
		G_B3_0 = 1;
	}

IL_0010:
	{
		V_0 = (bool)G_B3_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 78));
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_0016;
		}
	}
	{
		// if (eventBuffer == null || AnimationEvents == null) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 79));
		goto IL_0041;
	}

IL_0016:
	{
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 80));
		V_1 = 0;
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 81));
		ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* L_3 = ___eventBuffer0;
		NullCheck(L_3);
		int32_t L_4 = L_3->___Count_1;
		V_2 = L_4;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 82));
		goto IL_0039;
	}

IL_0021:
	{
		// AnimationEvents.Invoke(eventBuffer.Items[i]);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 83));
		SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* L_5 = __this->___AnimationEvents_4;
		ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E* L_6 = ___eventBuffer0;
		NullCheck(L_6);
		EventU5BU5D_t1F3AC368F660BBC1A9874C694C498837AF4F414C* L_7 = L_6->___Items_0;
		int32_t L_8 = V_1;
		NullCheck(L_7);
		int32_t L_9 = L_8;
		Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* L_10 = (L_7)->GetAt(static_cast<il2cpp_array_size_t>(L_9));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 84));
		NullCheck(L_5);
		SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_inline(L_5, L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 84));
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 85));
		int32_t L_11 = V_1;
		V_1 = ((int32_t)il2cpp_codegen_add(L_11, 1));
	}

IL_0039:
	{
		// for (int i = 0, n = eventBuffer.Count; i < n; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 86));
		int32_t L_12 = V_1;
		int32_t L_13 = V_2;
		V_3 = (bool)((((int32_t)L_12) < ((int32_t)L_13))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 87));
		bool L_14 = V_3;
		if (L_14)
		{
			goto IL_0021;
		}
	}

IL_0041:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 88));
		return;
	}
}
// System.Void Spine.Unity.Playables.SpinePlayableHandleBase::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E (SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpinePlayableHandleBase__ctor_m108709BF8E5C4FE29194154573392C9832A5C34E_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 89));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 90));
	{
		// public bool customDuration = false;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 91));
		__this->___customDuration_2 = (bool)0;
		// public bool useBlendDuration = true;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 92));
		__this->___useBlendDuration_3 = (bool)1;
		// private bool isInitialized = false; // required to read preferences values from editor side.
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 93));
		__this->___isInitialized_4 = (bool)0;
		// public float mixDuration = 0.1f;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 94));
		__this->___mixDuration_5 = (0.100000001f);
		// public bool holdPrevious = false;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 95));
		__this->___holdPrevious_6 = (bool)0;
		// public float attachmentThreshold = 0.5f;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 96));
		__this->___attachmentThreshold_7 = (0.5f);
		// public float eventThreshold = 0.5f;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 97));
		__this->___eventThreshold_8 = (0.5f);
		// public float drawOrderThreshold = 0.5f;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 98));
		__this->___drawOrderThreshold_9 = (0.5f);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 99));
		PlayableBehaviour__ctor_mA6202DCD846F0DDFC5963764A404EE8AFABEA23A(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 99));
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
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ClipCaps_t5A4215235745856AF28238667B359DD8C4BD76DE_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_get_clipCaps_mCF30A930DA45E24FDDC483BC189383E962400961_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateClip_get_clipCaps_mCF30A930DA45E24FDDC483BC189383E962400961_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 100));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 101));
	int32_t G_B2_0 = 0;
	int32_t G_B1_0 = 0;
	int32_t G_B3_0 = 0;
	int32_t G_B3_1 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 102));
		// public ClipCaps clipCaps { get { return ClipCaps.Blending | ClipCaps.ClipIn | ClipCaps.SpeedMultiplier | (template.loop ? ClipCaps.Looping : 0); } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 103));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_0 = __this->___template_4;
		NullCheck(L_0);
		bool L_1 = L_0->___loop_1;
		G_B1_0 = ((int32_t)28);
		if (L_1)
		{
			G_B2_0 = ((int32_t)28);
			goto IL_0013;
		}
	}
	{
		G_B3_0 = 0;
		G_B3_1 = G_B1_0;
		goto IL_0014;
	}

IL_0013:
	{
		G_B3_0 = 1;
		G_B3_1 = G_B2_0;
	}

IL_0014:
	{
		V_0 = ((int32_t)(G_B3_1|G_B3_0));
		goto IL_0018;
	}

IL_0018:
	{
		// public ClipCaps clipCaps { get { return ClipCaps.Blending | ClipCaps.ClipIn | ClipCaps.SpeedMultiplier | (template.loop ? ClipCaps.Looping : 0); } }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 104));
		int32_t L_2 = V_0;
		return L_2;
	}
}
// UnityEngine.Playables.Playable Spine.Unity.Playables.SpineAnimationStateClip::CreatePlayable(UnityEngine.Playables.PlayableGraph,UnityEngine.GameObject)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F SpineAnimationStateClip_CreatePlayable_mD1032BDA98B16C19C16AC3C25326B055599BC807 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E ___graph0, GameObject_t76FEDD663AB33C991A9C9A23129337651094216F* ___owner1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_CreatePlayable_mD1032BDA98B16C19C16AC3C25326B055599BC807_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_0;
	memset((&V_0), 0, sizeof(V_0));
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_1;
	memset((&V_1), 0, sizeof(V_1));
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___graph0), (&___owner1));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateClip_CreatePlayable_mD1032BDA98B16C19C16AC3C25326B055599BC807_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 105));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 106));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 107));
		// var playable = ScriptPlayable<SpineAnimationStateBehaviour>.Create(graph, template);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 108));
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_1 = __this->___template_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 109));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_2;
		L_2 = ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0(L_0, L_1, 0, ScriptPlayable_1_Create_m4453B10EE912A3BF5FC992E67F023CABB2F2E0A0_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 109));
		V_0 = L_2;
		// playable.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 110));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 111));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_3;
		L_3 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_0), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 111));
		// return playable;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 112));
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_4 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 113));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_5;
		L_5 = ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8(L_4, ScriptPlayable_1_op_Implicit_mAC954B62F0FE5E0D3BBF7A891DBD3544FDDAFBB8_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 113));
		V_1 = L_5;
		goto IL_0020;
	}

IL_0020:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 114));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_6 = V_1;
		return L_6;
	}
}
// System.Double Spine.Unity.Playables.SpineAnimationStateClip::get_duration()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR double SpineAnimationStateClip_get_duration_mA39B55EF9045326BABC1886E94F952E2AA6613F8 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Double_tE150EF3D1D43DEE85D533810AB4C742307EEDE5F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_get_duration_mA39B55EF9045326BABC1886E94F952E2AA6613F8_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	double V_1 = 0.0;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateClip_get_duration_mA39B55EF9045326BABC1886E94F952E2AA6613F8_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 115));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 116));
	int32_t G_B3_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 117));
		// if (template.animationReference == null || template.animationReference.Animation == null)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 118));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_0 = __this->___template_4;
		NullCheck(L_0);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_1 = L_0->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 119));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 119));
		if (L_2)
		{
			goto IL_0029;
		}
	}
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_3 = __this->___template_4;
		NullCheck(L_3);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_4 = L_3->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 120));
		NullCheck(L_4);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_5;
		L_5 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_4, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 120));
		G_B3_0 = ((((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_5) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		goto IL_002a;
	}

IL_0029:
	{
		G_B3_0 = 1;
	}

IL_002a:
	{
		V_0 = (bool)G_B3_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 121));
		bool L_6 = V_0;
		if (!L_6)
		{
			goto IL_003a;
		}
	}
	{
		// return 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 122));
		V_1 = (0.0);
		goto IL_0053;
	}

IL_003a:
	{
		// return template.animationReference.Animation.Duration;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 123));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_7 = __this->___template_4;
		NullCheck(L_7);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_8 = L_7->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 124));
		NullCheck(L_8);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_9;
		L_9 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_8, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 124));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 125));
		NullCheck(L_9);
		float L_10;
		L_10 = Animation_get_Duration_m385D29E0C137F21E8AD0DD9A945C0610AF175632(L_9, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 125));
		V_1 = ((double)L_10);
		goto IL_0053;
	}

IL_0053:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 126));
		double L_11 = V_1;
		return L_11;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateClip::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateClip__ctor_mF7502B962F50B8CE59DDBF0FE22707E7B329FD28 (SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip__ctor_mF7502B962F50B8CE59DDBF0FE22707E7B329FD28_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateClip_tD501A1CC9F51BF07D9D0D455D34FDC431177521A_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateClip__ctor_mF7502B962F50B8CE59DDBF0FE22707E7B329FD28_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 127));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 128));
	{
		// public SpineAnimationStateBehaviour template = new SpineAnimationStateBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 129));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 130));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_0 = (SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08*)il2cpp_codegen_object_new(SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_il2cpp_TypeInfo_var);
		NullCheck(L_0);
		SpineAnimationStateBehaviour__ctor_m372A98358EBD75BB1DAD40FC7E22DC475D0ED723(L_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 130));
		__this->___template_4 = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___template_4), (void*)L_0);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 131));
		PlayableAsset__ctor_m36B842356F02DF323B356BAAF6E3DC59BA9E1AB8(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 131));
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateGraphicTrack_CreateTrackMixer_mBC3BC55D62A0B73D6346E60C3A6A783BF89E879B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D V_0;
	memset((&V_0), 0, sizeof(V_0));
	SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* V_1 = NULL;
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_2;
	memset((&V_2), 0, sizeof(V_2));
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___graph0), (&___go1), (&___inputCount2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateGraphicTrack_CreateTrackMixer_mBC3BC55D62A0B73D6346E60C3A6A783BF89E879B_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 132));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 133));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 134));
		// var scriptPlayable = ScriptPlayable<SpineAnimationStateMixerBehaviour>.Create(graph, inputCount);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 135));
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		int32_t L_1 = ___inputCount2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 136));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_2;
		L_2 = ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F(L_0, L_1, ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 136));
		V_0 = L_2;
		// var mixerBehaviour = scriptPlayable.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 137));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 138));
		SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* L_3;
		L_3 = ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4((&V_0), ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 138));
		V_1 = L_3;
		// mixerBehaviour.trackIndex = this.trackIndex;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 139));
		SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* L_4 = V_1;
		int32_t L_5 = __this->___trackIndex_28;
		NullCheck(L_4);
		L_4->___trackIndex_1 = L_5;
		// return scriptPlayable;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 140));
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_6 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 141));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_7;
		L_7 = ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5(L_6, ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 141));
		V_2 = L_7;
		goto IL_0026;
	}

IL_0026:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 142));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_8 = V_2;
		return L_8;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateGraphicTrack::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateGraphicTrack__ctor_m4865F8FA9ECBCCC65A4011A7A00D4DB2CFB8D3BB (SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateGraphicTrack__ctor_m4865F8FA9ECBCCC65A4011A7A00D4DB2CFB8D3BB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateGraphicTrack_t30873C71178581F4BB6853A2ACB68A4B02AB3F88_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateGraphicTrack__ctor_m4865F8FA9ECBCCC65A4011A7A00D4DB2CFB8D3BB_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 143));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 144));
	{
		// public int trackIndex = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 145));
		__this->___trackIndex_28 = 0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 146));
		il2cpp_codegen_runtime_class_init_inline(TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 146));
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour_ProcessFrame_mF5BA9FDFE0AC4CE04804BA76342A32060F55AC5B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* V_0 = NULL;
	SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* V_1 = NULL;
	RuntimeObject* V_2 = NULL;
	RuntimeObject* V_3 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_4 = NULL;
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* V_5 = NULL;
	int32_t V_6 = 0;
	SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* V_7 = NULL;
	bool V_8 = false;
	bool V_9 = false;
	bool V_10 = false;
	int32_t V_11 = 0;
	bool V_12 = false;
	int32_t V_13 = 0;
	float V_14 = 0.0f;
	float V_15 = 0.0f;
	bool V_16 = false;
	bool V_17 = false;
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_18;
	memset((&V_18), 0, sizeof(V_18));
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* V_19 = NULL;
	bool V_20 = false;
	float V_21 = 0.0f;
	bool V_22 = false;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* V_23 = NULL;
	bool V_24 = false;
	bool V_25 = false;
	bool V_26 = false;
	bool V_27 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___playable0), (&___info1), (&___playerData2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_5), (&V_6), (&V_7), (&V_11), (&V_13), (&V_14), (&V_15), (&V_16), (&V_18), (&V_19), (&V_21), (&V_23));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateMixerBehaviour_ProcessFrame_mF5BA9FDFE0AC4CE04804BA76342A32060F55AC5B_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 147));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 148));
	int32_t G_B3_0 = 0;
	int32_t G_B10_0 = 0;
	int32_t G_B19_0 = 0;
	float G_B24_0 = 0.0f;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 149));
		// var skeletonAnimation = playerData as SkeletonAnimation;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 150));
		RuntimeObject* L_0 = ___playerData2;
		V_0 = ((SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A*)IsInstClass((RuntimeObject*)L_0, SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A_il2cpp_TypeInfo_var));
		// var skeletonGraphic = playerData as SkeletonGraphic;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 151));
		RuntimeObject* L_1 = ___playerData2;
		V_1 = ((SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1*)IsInstClass((RuntimeObject*)L_1, SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1_il2cpp_TypeInfo_var));
		// var animationStateComponent = playerData as IAnimationStateComponent;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 152));
		RuntimeObject* L_2 = ___playerData2;
		V_2 = ((RuntimeObject*)IsInst((RuntimeObject*)L_2, IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var));
		// var skeletonComponent = playerData as ISkeletonComponent;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 153));
		RuntimeObject* L_3 = ___playerData2;
		V_3 = ((RuntimeObject*)IsInst((RuntimeObject*)L_3, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var));
		// if (animationStateComponent == null || skeletonComponent == null) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 154));
		RuntimeObject* L_4 = V_2;
		if (!L_4)
		{
			goto IL_0026;
		}
	}
	{
		RuntimeObject* L_5 = V_3;
		G_B3_0 = ((((RuntimeObject*)(RuntimeObject*)L_5) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		goto IL_0027;
	}

IL_0026:
	{
		G_B3_0 = 1;
	}

IL_0027:
	{
		V_8 = (bool)G_B3_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 155));
		bool L_6 = V_8;
		if (!L_6)
		{
			goto IL_0032;
		}
	}
	{
		// if (animationStateComponent == null || skeletonComponent == null) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 156));
		goto IL_0283;
	}

IL_0032:
	{
		// var skeleton = skeletonComponent.Skeleton;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 157));
		RuntimeObject* L_7 = V_3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 158));
		NullCheck(L_7);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_8;
		L_8 = InterfaceFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(1 /* Spine.Skeleton Spine.Unity.ISkeletonComponent::get_Skeleton() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_7);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 158));
		V_4 = L_8;
		// var state = animationStateComponent.AnimationState;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 159));
		RuntimeObject* L_9 = V_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 160));
		NullCheck(L_9);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_10;
		L_10 = InterfaceFuncInvoker0< AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* >::Invoke(0 /* Spine.AnimationState Spine.Unity.IAnimationStateComponent::get_AnimationState() */, IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var, L_9);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 160));
		V_5 = L_10;
		// if (!Application.isPlaying) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 161));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 162));
		bool L_11;
		L_11 = Application_get_isPlaying_m0B3B501E1093739F8887A0DAC5F61D9CB49CC337(NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 162));
		V_9 = (bool)((((int32_t)L_11) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 163));
		bool L_12 = V_9;
		if (!L_12)
		{
			goto IL_0062;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 164));
		// PreviewEditModePose(playable, skeletonComponent, animationStateComponent,
		//     skeletonAnimation, skeletonGraphic);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 165));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_13 = ___playable0;
		RuntimeObject* L_14 = V_3;
		RuntimeObject* L_15 = V_2;
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_16 = V_0;
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_17 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 166));
		SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584(__this, L_13, L_14, L_15, L_16, L_17, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 166));
		// return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 167));
		goto IL_0283;
	}

IL_0062:
	{
		// int inputCount = playable.GetInputCount();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 168));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_18 = ___playable0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 169));
		int32_t L_19;
		L_19 = PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9(L_18, PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 169));
		V_6 = L_19;
		// if (this.lastInputWeights == null || this.lastInputWeights.Length < inputCount) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 170));
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_20 = __this->___lastInputWeights_0;
		if (!L_20)
		{
			goto IL_0080;
		}
	}
	{
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_21 = __this->___lastInputWeights_0;
		NullCheck(L_21);
		int32_t L_22 = V_6;
		G_B10_0 = ((((int32_t)((int32_t)(((RuntimeArray*)L_21)->max_length))) < ((int32_t)L_22))? 1 : 0);
		goto IL_0081;
	}

IL_0080:
	{
		G_B10_0 = 1;
	}

IL_0081:
	{
		V_10 = (bool)G_B10_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 171));
		bool L_23 = V_10;
		if (!L_23)
		{
			goto IL_00bb;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 172));
		// this.lastInputWeights = new float[inputCount];
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 173));
		int32_t L_24 = V_6;
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_25 = (SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*)(SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C*)SZArrayNew(SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C_il2cpp_TypeInfo_var, (uint32_t)L_24);
		__this->___lastInputWeights_0 = L_25;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___lastInputWeights_0), (void*)L_25);
		// for (int i = 0; i < inputCount; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 174));
		V_11 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 175));
		goto IL_00ae;
	}

IL_009a:
	{
		// this.lastInputWeights[i] = default(float);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 176));
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_26 = __this->___lastInputWeights_0;
		int32_t L_27 = V_11;
		NullCheck(L_26);
		(L_26)->SetAt(static_cast<il2cpp_array_size_t>(L_27), (float)(0.0f));
		// for (int i = 0; i < inputCount; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 177));
		int32_t L_28 = V_11;
		V_11 = ((int32_t)il2cpp_codegen_add(L_28, 1));
	}

IL_00ae:
	{
		// for (int i = 0; i < inputCount; i++)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 178));
		int32_t L_29 = V_11;
		int32_t L_30 = V_6;
		V_12 = (bool)((((int32_t)L_29) < ((int32_t)L_30))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 179));
		bool L_31 = V_12;
		if (L_31)
		{
			goto IL_009a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 180));
	}

IL_00bb:
	{
		// var lastInputWeights = this.lastInputWeights;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 181));
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_32 = __this->___lastInputWeights_0;
		V_7 = L_32;
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 182));
		V_13 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 183));
		goto IL_0274;
	}

IL_00cb:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 184));
		// float lastInputWeight = lastInputWeights[i];
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 185));
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_33 = V_7;
		int32_t L_34 = V_13;
		NullCheck(L_33);
		int32_t L_35 = L_34;
		float L_36 = (L_33)->GetAt(static_cast<il2cpp_array_size_t>(L_35));
		V_14 = L_36;
		// float inputWeight = playable.GetInputWeight(i);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 186));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_37 = ___playable0;
		int32_t L_38 = V_13;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 187));
		float L_39;
		L_39 = PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B(L_37, L_38, PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 187));
		V_15 = L_39;
		// bool trackStarted = lastInputWeight == 0 && inputWeight > 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 188));
		float L_40 = V_14;
		if ((!(((float)L_40) == ((float)(0.0f)))))
		{
			goto IL_00f1;
		}
	}
	{
		float L_41 = V_15;
		G_B19_0 = ((((float)L_41) > ((float)(0.0f)))? 1 : 0);
		goto IL_00f2;
	}

IL_00f1:
	{
		G_B19_0 = 0;
	}

IL_00f2:
	{
		V_16 = (bool)G_B19_0;
		// lastInputWeights[i] = inputWeight;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 189));
		SingleU5BU5D_t89DEFE97BCEDB5857010E79ECE0F52CF6E93B87C* L_42 = V_7;
		int32_t L_43 = V_13;
		float L_44 = V_15;
		NullCheck(L_42);
		(L_42)->SetAt(static_cast<il2cpp_array_size_t>(L_43), (float)L_44);
		// if (trackStarted) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 190));
		bool L_45 = V_16;
		V_17 = L_45;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 191));
		bool L_46 = V_17;
		if (!L_46)
		{
			goto IL_026d;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 192));
		// ScriptPlayable<SpineAnimationStateBehaviour> inputPlayable = (ScriptPlayable<SpineAnimationStateBehaviour>)playable.GetInput(i);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 193));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_47 = ___playable0;
		int32_t L_48 = V_13;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 194));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_49;
		L_49 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_47, L_48, PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 194));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 195));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_50;
		L_50 = ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980(L_49, ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 195));
		V_18 = L_50;
		// SpineAnimationStateBehaviour clipData = inputPlayable.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 196));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 197));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_51;
		L_51 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_18), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 197));
		V_19 = L_51;
		// if (clipData.animationReference == null) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 198));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_52 = V_19;
		NullCheck(L_52);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_53 = L_52->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 199));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_54;
		L_54 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_53, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 199));
		V_20 = L_54;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 200));
		bool L_55 = V_20;
		if (!L_55)
		{
			goto IL_0169;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 201));
		// float mixDuration = clipData.customDuration ? clipData.mixDuration : state.Data.DefaultMix;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 202));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_56 = V_19;
		NullCheck(L_56);
		bool L_57 = L_56->___customDuration_2;
		if (L_57)
		{
			goto IL_014a;
		}
	}
	{
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_58 = V_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 203));
		NullCheck(L_58);
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_59;
		L_59 = AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C(L_58, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 203));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 204));
		NullCheck(L_59);
		float L_60;
		L_60 = AnimationStateData_get_DefaultMix_m4BDB14E9DF538918293CF58F4D62B7DB49AAB476(L_59, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 204));
		G_B24_0 = L_60;
		goto IL_0151;
	}

IL_014a:
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_61 = V_19;
		NullCheck(L_61);
		float L_62 = L_61->___mixDuration_5;
		G_B24_0 = L_62;
	}

IL_0151:
	{
		V_21 = G_B24_0;
		// state.SetEmptyAnimation(trackIndex, mixDuration);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 205));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_63 = V_5;
		int32_t L_64 = __this->___trackIndex_1;
		float L_65 = V_21;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 206));
		NullCheck(L_63);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_66;
		L_66 = AnimationState_SetEmptyAnimation_m2C660F117296347DFF557578CCC42E7215935656(L_63, L_64, L_65, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 206));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 207));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 208));
		goto IL_0228;
	}

IL_0169:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 209));
		// if (clipData.animationReference.Animation != null) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 210));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_67 = V_19;
		NullCheck(L_67);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_68 = L_67->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 211));
		NullCheck(L_68);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_69;
		L_69 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_68, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 211));
		V_22 = (bool)((!(((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_69) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 212));
		bool L_70 = V_22;
		if (!L_70)
		{
			goto IL_0227;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 213));
		// Spine.TrackEntry trackEntry = state.SetAnimation(trackIndex, clipData.animationReference.Animation, clipData.loop);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 214));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_71 = V_5;
		int32_t L_72 = __this->___trackIndex_1;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_73 = V_19;
		NullCheck(L_73);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_74 = L_73->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 215));
		NullCheck(L_74);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_75;
		L_75 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_74, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 215));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_76 = V_19;
		NullCheck(L_76);
		bool L_77 = L_76->___loop_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 216));
		NullCheck(L_71);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_78;
		L_78 = AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D(L_71, L_72, L_75, L_77, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 216));
		V_23 = L_78;
		// trackEntry.EventThreshold = clipData.eventThreshold;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 217));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_79 = V_23;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_80 = V_19;
		NullCheck(L_80);
		float L_81 = L_80->___eventThreshold_8;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 218));
		NullCheck(L_79);
		TrackEntry_set_EventThreshold_mB58AD3053F5C702066F23AE2DBD52F4DD6DE2823(L_79, L_81, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 218));
		// trackEntry.DrawOrderThreshold = clipData.drawOrderThreshold;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 219));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_82 = V_23;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_83 = V_19;
		NullCheck(L_83);
		float L_84 = L_83->___drawOrderThreshold_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 220));
		NullCheck(L_82);
		TrackEntry_set_DrawOrderThreshold_mB1343F81A778546FDE7464B66698B838A44F24F3(L_82, L_84, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 220));
		// trackEntry.TrackTime = (float)inputPlayable.GetTime() * (float)inputPlayable.GetSpeed();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 221));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_85 = V_23;
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_86 = V_18;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 222));
		double L_87;
		L_87 = PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A(L_86, PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 222));
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_88 = V_18;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 223));
		double L_89;
		L_89 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_88, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 223));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 224));
		NullCheck(L_85);
		TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3(L_85, ((float)il2cpp_codegen_multiply(((float)L_87), ((float)L_89))), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 224));
		// trackEntry.TimeScale = (float)inputPlayable.GetSpeed();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 225));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_90 = V_23;
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_91 = V_18;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 226));
		double L_92;
		L_92 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_91, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 226));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 227));
		NullCheck(L_90);
		TrackEntry_set_TimeScale_m9C6DC53ED8731A1A5A3EE825BEF667BA848A8588(L_90, ((float)L_92), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 227));
		// trackEntry.AttachmentThreshold = clipData.attachmentThreshold;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 228));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_93 = V_23;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_94 = V_19;
		NullCheck(L_94);
		float L_95 = L_94->___attachmentThreshold_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 229));
		NullCheck(L_93);
		TrackEntry_set_AttachmentThreshold_mA75133539615A962566CE1CAAA1FFB9ED49A3DC0(L_93, L_95, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 229));
		// trackEntry.HoldPrevious = clipData.holdPrevious;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 230));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_96 = V_23;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_97 = V_19;
		NullCheck(L_97);
		bool L_98 = L_97->___holdPrevious_6;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 231));
		NullCheck(L_96);
		TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3(L_96, L_98, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 231));
		// if (clipData.customDuration)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 232));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_99 = V_19;
		NullCheck(L_99);
		bool L_100 = L_99->___customDuration_2;
		V_24 = L_100;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 233));
		bool L_101 = V_24;
		if (!L_101)
		{
			goto IL_0226;
		}
	}
	{
		// trackEntry.MixDuration = clipData.mixDuration;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 234));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_102 = V_23;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_103 = V_19;
		NullCheck(L_103);
		float L_104 = L_103->___mixDuration_5;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 235));
		NullCheck(L_102);
		TrackEntry_set_MixDuration_m22C7A7BDE2F947A311BC27093C0C5B96B4CA9C55(L_102, L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 235));
	}

IL_0226:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 236));
	}

IL_0227:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 237));
	}

IL_0228:
	{
		// if (skeletonAnimation) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 238));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_105 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 239));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_106;
		L_106 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_105, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 239));
		V_25 = L_106;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 240));
		bool L_107 = V_25;
		if (!L_107)
		{
			goto IL_024b;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 241));
		// skeletonAnimation.Update(0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 242));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_108 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 243));
		NullCheck(L_108);
		SkeletonAnimation_Update_mA405A7645B8BA03A1CD193F3AE50E1D08FBC19D0(L_108, (0.0f), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 243));
		// skeletonAnimation.LateUpdate();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 244));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_109 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 245));
		NullCheck(L_109);
		VirtualActionInvoker0::Invoke(10 /* System.Void Spine.Unity.SkeletonRenderer::LateUpdate() */, L_109);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 245));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 246));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 247));
		goto IL_026c;
	}

IL_024b:
	{
		// else if (skeletonGraphic) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 248));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_110 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 249));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_111;
		L_111 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_110, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 249));
		V_26 = L_111;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 250));
		bool L_112 = V_26;
		if (!L_112)
		{
			goto IL_026c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 251));
		// skeletonGraphic.Update(0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 252));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_113 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 253));
		NullCheck(L_113);
		VirtualActionInvoker1< float >::Invoke(77 /* System.Void Spine.Unity.SkeletonGraphic::Update(System.Single) */, L_113, (0.0f));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 253));
		// skeletonGraphic.LateUpdate();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 254));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_114 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 255));
		NullCheck(L_114);
		SkeletonGraphic_LateUpdate_m6A04288EA0CEDAE3A87FC0BC09E797D70B9D4347(L_114, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 255));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 256));
	}

IL_026c:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 257));
	}

IL_026d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 258));
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 259));
		int32_t L_115 = V_13;
		V_13 = ((int32_t)il2cpp_codegen_add(L_115, 1));
	}

IL_0274:
	{
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 260));
		int32_t L_116 = V_13;
		int32_t L_117 = V_6;
		V_27 = (bool)((((int32_t)L_116) < ((int32_t)L_117))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 261));
		bool L_118 = V_27;
		if (L_118)
		{
			goto IL_00cb;
		}
	}

IL_0283:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 262));
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteralD9AEAA6A49FCC6BC5EF6CE3F695813A1EAB670BE);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	int32_t V_1 = 0;
	bool V_2 = false;
	bool V_3 = false;
	int32_t V_4 = 0;
	float V_5 = 0.0f;
	bool V_6 = false;
	bool V_7 = false;
	bool V_8 = false;
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_9;
	memset((&V_9), 0, sizeof(V_9));
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* V_10 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_11 = NULL;
	bool V_12 = false;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* V_13 = NULL;
	float V_14 = 0.0f;
	bool V_15 = false;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* V_16 = NULL;
	float V_17 = 0.0f;
	float V_18 = 0.0f;
	bool V_19 = false;
	bool V_20 = false;
	ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 V_21;
	memset((&V_21), 0, sizeof(V_21));
	SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* V_22 = NULL;
	bool V_23 = false;
	bool V_24 = false;
	bool V_25 = false;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* V_26 = NULL;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* V_27 = NULL;
	bool V_28 = false;
	bool V_29 = false;
	bool V_30 = false;
	bool V_31 = false;
	bool V_32 = false;
	bool V_33 = false;
	bool V_34 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___playable0), (&___skeletonComponent1), (&___animationStateComponent2), (&___skeletonAnimation3), (&___skeletonGraphic4));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_4), (&V_5), (&V_9), (&V_10), (&V_11), (&V_12), (&V_13), (&V_14), (&V_15), (&V_16), (&V_17), (&V_18), (&V_21), (&V_22), (&V_26), (&V_27), (&V_28));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateMixerBehaviour_PreviewEditModePose_m31096D7FB7C2A2E033AC803C31089E3103DB1584_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 263));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 264));
	int32_t G_B5_0 = 0;
	int32_t G_B17_0 = 0;
	int32_t G_B22_0 = 0;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* G_B26_0 = NULL;
	Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* G_B30_0 = NULL;
	int32_t G_B34_0 = 0;
	int32_t G_B42_0 = 0;
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* G_B45_0 = NULL;
	SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* G_B45_1 = NULL;
	AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* G_B44_0 = NULL;
	SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* G_B44_1 = NULL;
	TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* G_B48_0 = NULL;
	int32_t G_B53_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 265));
		// if (Application.isPlaying) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 266));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 267));
		bool L_0;
		L_0 = Application_get_isPlaying_m0B3B501E1093739F8887A0DAC5F61D9CB49CC337(NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 267));
		V_2 = L_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 268));
		bool L_1 = V_2;
		if (!L_1)
		{
			goto IL_000f;
		}
	}
	{
		// if (Application.isPlaying) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 269));
		goto IL_039c;
	}

IL_000f:
	{
		// if (skeletonComponent == null || animationStateComponent == null) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 270));
		RuntimeObject* L_2 = ___skeletonComponent1;
		if (!L_2)
		{
			goto IL_0018;
		}
	}
	{
		RuntimeObject* L_3 = ___animationStateComponent2;
		G_B5_0 = ((((RuntimeObject*)(RuntimeObject*)L_3) == ((RuntimeObject*)(RuntimeObject*)NULL))? 1 : 0);
		goto IL_0019;
	}

IL_0018:
	{
		G_B5_0 = 1;
	}

IL_0019:
	{
		V_3 = (bool)G_B5_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 271));
		bool L_4 = V_3;
		if (!L_4)
		{
			goto IL_0022;
		}
	}
	{
		// if (skeletonComponent == null || animationStateComponent == null) return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 272));
		goto IL_039c;
	}

IL_0022:
	{
		// int inputCount = playable.GetInputCount();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 273));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_5 = ___playable0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 274));
		int32_t L_6;
		L_6 = PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9(L_5, PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 274));
		V_0 = L_6;
		// int lastNonZeroWeightTrack = -1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 275));
		V_1 = (-1);
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 276));
		V_4 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 277));
		goto IL_0054;
	}

IL_0030:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 278));
		// float inputWeight = playable.GetInputWeight(i);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 279));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_7 = ___playable0;
		int32_t L_8 = V_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 280));
		float L_9;
		L_9 = PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B(L_7, L_8, PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 280));
		V_5 = L_9;
		// if (inputWeight > 0) lastNonZeroWeightTrack = i;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 281));
		float L_10 = V_5;
		V_6 = (bool)((((float)L_10) > ((float)(0.0f)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 282));
		bool L_11 = V_6;
		if (!L_11)
		{
			goto IL_004d;
		}
	}
	{
		// if (inputWeight > 0) lastNonZeroWeightTrack = i;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 283));
		int32_t L_12 = V_4;
		V_1 = L_12;
	}

IL_004d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 284));
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 285));
		int32_t L_13 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_13, 1));
	}

IL_0054:
	{
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 286));
		int32_t L_14 = V_4;
		int32_t L_15 = V_0;
		V_7 = (bool)((((int32_t)L_14) < ((int32_t)L_15))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 287));
		bool L_16 = V_7;
		if (L_16)
		{
			goto IL_0030;
		}
	}
	{
		// if (lastNonZeroWeightTrack != -1) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 288));
		int32_t L_17 = V_1;
		V_8 = (bool)((((int32_t)((((int32_t)L_17) == ((int32_t)(-1)))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 289));
		bool L_18 = V_8;
		if (!L_18)
		{
			goto IL_039c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 290));
		// ScriptPlayable<SpineAnimationStateBehaviour> inputPlayableClip =
		//     (ScriptPlayable<SpineAnimationStateBehaviour>)playable.GetInput(lastNonZeroWeightTrack);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 291));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_19 = ___playable0;
		int32_t L_20 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 292));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_21;
		L_21 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_19, L_20, PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 292));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 293));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_22;
		L_22 = ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980(L_21, ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 293));
		V_9 = L_22;
		// SpineAnimationStateBehaviour clipData = inputPlayableClip.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 294));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 295));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_23;
		L_23 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_9), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 295));
		V_10 = L_23;
		// var skeleton = skeletonComponent.Skeleton;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 296));
		RuntimeObject* L_24 = ___skeletonComponent1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 297));
		NullCheck(L_24);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_25;
		L_25 = InterfaceFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(1 /* Spine.Skeleton Spine.Unity.ISkeletonComponent::get_Skeleton() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_24);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 297));
		V_11 = L_25;
		// bool skeletonDataMismatch = clipData.animationReference != null && clipData.animationReference.SkeletonDataAsset &&
		//     skeletonComponent.SkeletonDataAsset.GetSkeletonData(true) != clipData.animationReference.SkeletonDataAsset.GetSkeletonData(true);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 298));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_26 = V_10;
		NullCheck(L_26);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_27 = L_26->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 299));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_28;
		L_28 = Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7(L_27, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 299));
		if (!L_28)
		{
			goto IL_00d6;
		}
	}
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_29 = V_10;
		NullCheck(L_29);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_30 = L_29->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 300));
		NullCheck(L_30);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_31;
		L_31 = AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E(L_30, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 300));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 301));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_32;
		L_32 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_31, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 301));
		if (!L_32)
		{
			goto IL_00d6;
		}
	}
	{
		RuntimeObject* L_33 = ___skeletonComponent1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 302));
		NullCheck(L_33);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_34;
		L_34 = InterfaceFuncInvoker0< SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* >::Invoke(0 /* Spine.Unity.SkeletonDataAsset Spine.Unity.ISkeletonComponent::get_SkeletonDataAsset() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_33);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 302));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 303));
		NullCheck(L_34);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_35;
		L_35 = SkeletonDataAsset_GetSkeletonData_mCBAFA745AEC7A8191A7FBE1EE05A8A877886832E(L_34, (bool)1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 303));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_36 = V_10;
		NullCheck(L_36);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_37 = L_36->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 304));
		NullCheck(L_37);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_38;
		L_38 = AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E(L_37, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 304));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 305));
		NullCheck(L_38);
		SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B* L_39;
		L_39 = SkeletonDataAsset_GetSkeletonData_mCBAFA745AEC7A8191A7FBE1EE05A8A877886832E(L_38, (bool)1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 305));
		G_B17_0 = ((((int32_t)((((RuntimeObject*)(SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B*)L_35) == ((RuntimeObject*)(SkeletonData_t9C91D0DD00FAB7BC1C97343490070F3F8ACD517B*)L_39))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_00d7;
	}

IL_00d6:
	{
		G_B17_0 = 0;
	}

IL_00d7:
	{
		V_12 = (bool)G_B17_0;
		// if (skeletonDataMismatch) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 306));
		bool L_40 = V_12;
		V_19 = L_40;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 307));
		bool L_41 = V_19;
		if (!L_41)
		{
			goto IL_010c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 308));
		// Debug.LogWarningFormat("SpineAnimationStateMixerBehaviour tried to apply an animation for the wrong skeleton. Expected {0}. Was {1}",
		//     skeletonComponent.SkeletonDataAsset, clipData.animationReference.SkeletonDataAsset);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 309));
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_42 = (ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918*)SZArrayNew(ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918_il2cpp_TypeInfo_var, (uint32_t)2);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_43 = L_42;
		RuntimeObject* L_44 = ___skeletonComponent1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 310));
		NullCheck(L_44);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_45;
		L_45 = InterfaceFuncInvoker0< SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* >::Invoke(0 /* Spine.Unity.SkeletonDataAsset Spine.Unity.ISkeletonComponent::get_SkeletonDataAsset() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_44);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 310));
		NullCheck(L_43);
		ArrayElementTypeCheck (L_43, L_45);
		(L_43)->SetAt(static_cast<il2cpp_array_size_t>(0), (RuntimeObject*)L_45);
		ObjectU5BU5D_t8061030B0A12A55D5AD8652A20C922FE99450918* L_46 = L_43;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_47 = V_10;
		NullCheck(L_47);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_48 = L_47->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 311));
		NullCheck(L_48);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_49;
		L_49 = AnimationReferenceAsset_get_SkeletonDataAsset_mEBA7A5BE7D3E6A0D5ED37A9EDF46568A0C46FB3E(L_48, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 311));
		NullCheck(L_46);
		ArrayElementTypeCheck (L_46, L_49);
		(L_46)->SetAt(static_cast<il2cpp_array_size_t>(1), (RuntimeObject*)L_49);
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 312));
		il2cpp_codegen_runtime_class_init_inline(Debug_t8394C7EEAECA3689C2C9B9DE9C7166D73596276F_il2cpp_TypeInfo_var);
		Debug_LogWarningFormat_m0D4A31935564D0FA042103C1231DBBD2ED0BC20A(_stringLiteralD9AEAA6A49FCC6BC5EF6CE3F695813A1EAB670BE, L_46, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 312));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 313));
	}

IL_010c:
	{
		// Animation fromAnimation = null;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 314));
		V_13 = (Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)NULL;
		// float fromClipTime = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 315));
		V_14 = (0.0f);
		// bool fromClipLoop = false;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 316));
		V_15 = (bool)0;
		// if (lastNonZeroWeightTrack != 0 && inputCount > 1) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 317));
		int32_t L_50 = V_1;
		if (!L_50)
		{
			goto IL_0122;
		}
	}
	{
		int32_t L_51 = V_0;
		G_B22_0 = ((((int32_t)L_51) > ((int32_t)1))? 1 : 0);
		goto IL_0123;
	}

IL_0122:
	{
		G_B22_0 = 0;
	}

IL_0123:
	{
		V_20 = (bool)G_B22_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 318));
		bool L_52 = V_20;
		if (!L_52)
		{
			goto IL_0180;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 319));
		// var fromClip = (ScriptPlayable<SpineAnimationStateBehaviour>)playable.GetInput(lastNonZeroWeightTrack - 1);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 320));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_53 = ___playable0;
		int32_t L_54 = V_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 321));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_55;
		L_55 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_53, ((int32_t)il2cpp_codegen_subtract(L_54, 1)), PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 321));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 322));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_56;
		L_56 = ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980(L_55, ScriptPlayable_1_op_Explicit_m19AF0B3289FD1659D614E88391E5EAC835895980_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 322));
		V_21 = L_56;
		// var fromClipData = fromClip.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 323));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 324));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_57;
		L_57 = ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58((&V_21), ScriptPlayable_1_GetBehaviour_mDB12F34D014BA2DDDDBEDEBA38DE5E41EB667B58_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 324));
		V_22 = L_57;
		// fromAnimation = fromClipData.animationReference != null ? fromClipData.animationReference.Animation : null;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 325));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_58 = V_22;
		NullCheck(L_58);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_59 = L_58->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 326));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_60;
		L_60 = Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7(L_59, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 326));
		if (L_60)
		{
			goto IL_0155;
		}
	}
	{
		G_B26_0 = ((Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)(NULL));
		goto IL_0161;
	}

IL_0155:
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_61 = V_22;
		NullCheck(L_61);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_62 = L_61->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 327));
		NullCheck(L_62);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_63;
		L_63 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_62, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 327));
		G_B26_0 = L_63;
	}

IL_0161:
	{
		V_13 = G_B26_0;
		// fromClipTime = (float)fromClip.GetTime() * (float)fromClip.GetSpeed();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 328));
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_64 = V_21;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 329));
		double L_65;
		L_65 = PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A(L_64, PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 329));
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_66 = V_21;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 330));
		double L_67;
		L_67 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_66, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 330));
		V_14 = ((float)il2cpp_codegen_multiply(((float)L_65), ((float)L_67)));
		// fromClipLoop = fromClipData.loop;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 331));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_68 = V_22;
		NullCheck(L_68);
		bool L_69 = L_68->___loop_1;
		V_15 = L_69;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 332));
	}

IL_0180:
	{
		// Animation toAnimation = clipData.animationReference != null ? clipData.animationReference.Animation : null;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 333));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_70 = V_10;
		NullCheck(L_70);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_71 = L_70->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 334));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_72;
		L_72 = Object_op_Inequality_m4D656395C27694A7F33F5AA8DE80A7AAF9E20BA7(L_71, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 334));
		if (L_72)
		{
			goto IL_0192;
		}
	}
	{
		G_B30_0 = ((Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)(NULL));
		goto IL_019e;
	}

IL_0192:
	{
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_73 = V_10;
		NullCheck(L_73);
		AnimationReferenceAsset_t06E2B8B2B5653BBE5F0198AB4B22C2BF71907658* L_74 = L_73->___animationReference_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 335));
		NullCheck(L_74);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_75;
		L_75 = AnimationReferenceAsset_get_Animation_m6A56EAE47BFAD4D53CB371A006864432B329034F(L_74, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 335));
		G_B30_0 = L_75;
	}

IL_019e:
	{
		V_16 = G_B30_0;
		// float toClipTime = (float)inputPlayableClip.GetTime() * (float)inputPlayableClip.GetSpeed();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 336));
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_76 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 337));
		double L_77;
		L_77 = PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A(L_76, PlayableExtensions_GetTime_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_mB233C763DEBF8593CDB6F0DA241434EE8A5C714A_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 337));
		ScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4 L_78 = V_9;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 338));
		double L_79;
		L_79 = PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B(L_78, PlayableExtensions_GetSpeed_TisScriptPlayable_1_t170607B87C4021A3F774D5D8165DCE380CD2EFC4_m3F7D4A175AEBEE51B2788A310CD8737A91D9955B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 338));
		V_17 = ((float)il2cpp_codegen_multiply(((float)L_77), ((float)L_79)));
		// float mixDuration = clipData.mixDuration;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 339));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_80 = V_10;
		NullCheck(L_80);
		float L_81 = L_80->___mixDuration_5;
		V_18 = L_81;
		// if (!clipData.customDuration && fromAnimation != null && toAnimation != null) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 340));
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_82 = V_10;
		NullCheck(L_82);
		bool L_83 = L_82->___customDuration_2;
		if (L_83)
		{
			goto IL_01d0;
		}
	}
	{
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_84 = V_13;
		if (!L_84)
		{
			goto IL_01d0;
		}
	}
	{
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_85 = V_16;
		G_B34_0 = ((!(((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_85) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		goto IL_01d1;
	}

IL_01d0:
	{
		G_B34_0 = 0;
	}

IL_01d1:
	{
		V_23 = (bool)G_B34_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 341));
		bool L_86 = V_23;
		if (!L_86)
		{
			goto IL_01ef;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 342));
		// mixDuration = animationStateComponent.AnimationState.Data.GetMix(fromAnimation, toAnimation);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 343));
		RuntimeObject* L_87 = ___animationStateComponent2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 344));
		NullCheck(L_87);
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_88;
		L_88 = InterfaceFuncInvoker0< AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* >::Invoke(0 /* Spine.AnimationState Spine.Unity.IAnimationStateComponent::get_AnimationState() */, IAnimationStateComponent_t78919B4AFDC56EBA97AD95C9E3C9AA54A2F85FE3_il2cpp_TypeInfo_var, L_87);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 344));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 345));
		NullCheck(L_88);
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_89;
		L_89 = AnimationState_get_Data_m5DAC1A14FBF6989870C698C66383EDDA450FF18C(L_88, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 345));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_90 = V_13;
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_91 = V_16;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 346));
		NullCheck(L_89);
		float L_92;
		L_92 = AnimationStateData_GetMix_m1F69969EB5ED5B0523496EEF610D195C756F1C9E(L_89, L_90, L_91, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 346));
		V_18 = L_92;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 347));
	}

IL_01ef:
	{
		// if (trackIndex == 0)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 348));
		int32_t L_93 = __this->___trackIndex_1;
		V_24 = (bool)((((int32_t)L_93) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 349));
		bool L_94 = V_24;
		if (!L_94)
		{
			goto IL_0206;
		}
	}
	{
		// skeleton.SetToSetupPose();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 350));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_95 = V_11;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 351));
		NullCheck(L_95);
		Skeleton_SetToSetupPose_m12FBF0ABCEA99C4795C39EF74008F5372894DD71(L_95, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 351));
	}

IL_0206:
	{
		// if (fromAnimation != null && mixDuration > 0 && toClipTime < mixDuration) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 352));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_96 = V_13;
		if (!L_96)
		{
			goto IL_021b;
		}
	}
	{
		float L_97 = V_18;
		if ((!(((float)L_97) > ((float)(0.0f)))))
		{
			goto IL_021b;
		}
	}
	{
		float L_98 = V_17;
		float L_99 = V_18;
		G_B42_0 = ((((float)L_98) < ((float)L_99))? 1 : 0);
		goto IL_021c;
	}

IL_021b:
	{
		G_B42_0 = 0;
	}

IL_021c:
	{
		V_25 = (bool)G_B42_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 353));
		bool L_100 = V_25;
		if (!L_100)
		{
			goto IL_033a;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 354));
		// dummyAnimationState = dummyAnimationState ?? new AnimationState(skeletonComponent.SkeletonDataAsset.GetAnimationStateData());
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 355));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_101 = __this->___dummyAnimationState_2;
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_102 = L_101;
		G_B44_0 = L_102;
		G_B44_1 = __this;
		if (L_102)
		{
			G_B45_0 = L_102;
			G_B45_1 = __this;
			goto IL_0241;
		}
	}
	{
		RuntimeObject* L_103 = ___skeletonComponent1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 356));
		NullCheck(L_103);
		SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* L_104;
		L_104 = InterfaceFuncInvoker0< SkeletonDataAsset_tCA945F8ACCDEEE8C8424D2A6513D1C5FEFB8809F* >::Invoke(0 /* Spine.Unity.SkeletonDataAsset Spine.Unity.ISkeletonComponent::get_SkeletonDataAsset() */, ISkeletonComponent_t33C74410837089F7A80E6488BC2BA6EFC39C7482_il2cpp_TypeInfo_var, L_103);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 356));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 357));
		NullCheck(L_104);
		AnimationStateData_t59A6A8CA553459E329D55049B38C027F09CA8D62* L_105;
		L_105 = SkeletonDataAsset_GetAnimationStateData_m26E2621493EF9FC9D9673FA9C74B48D32D09AF9C(L_104, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 357));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 358));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_106 = (AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC*)il2cpp_codegen_object_new(AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC_il2cpp_TypeInfo_var);
		NullCheck(L_106);
		AnimationState__ctor_m633A801A8038EF0840C36EF102705EE1B6690145(L_106, L_105, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 358));
		G_B45_0 = L_106;
		G_B45_1 = G_B44_1;
	}

IL_0241:
	{
		NullCheck(G_B45_1);
		G_B45_1->___dummyAnimationState_2 = G_B45_0;
		Il2CppCodeGenWriteBarrier((void**)(&G_B45_1->___dummyAnimationState_2), (void*)G_B45_0);
		// var toTrack = dummyAnimationState.GetCurrent(0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 359));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_107 = __this->___dummyAnimationState_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 360));
		NullCheck(L_107);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_108;
		L_108 = AnimationState_GetCurrent_m56ACBF9037B2D88C1134F0FC9D9927CD9E1DEA02(L_107, 0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 360));
		V_26 = L_108;
		// var fromTrack = toTrack != null ? toTrack.MixingFrom : null;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 361));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_109 = V_26;
		if (L_109)
		{
			goto IL_025b;
		}
	}
	{
		G_B48_0 = ((TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB*)(NULL));
		goto IL_0262;
	}

IL_025b:
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_110 = V_26;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 362));
		NullCheck(L_110);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_111;
		L_111 = TrackEntry_get_MixingFrom_m7598E2772B37B33B23647FD261DDD3FEA15B9B25(L_110, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 362));
		G_B48_0 = L_111;
	}

IL_0262:
	{
		V_27 = G_B48_0;
		// bool isAnimationTransitionMatch = (toTrack != null && toTrack.Animation == toAnimation && fromTrack != null && fromTrack.Animation == fromAnimation);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 363));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_112 = V_26;
		if (!L_112)
		{
			goto IL_0284;
		}
	}
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_113 = V_26;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 364));
		NullCheck(L_113);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_114;
		L_114 = TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775(L_113, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 364));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_115 = V_16;
		if ((!(((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_114) == ((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_115))))
		{
			goto IL_0284;
		}
	}
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_116 = V_27;
		if (!L_116)
		{
			goto IL_0284;
		}
	}
	{
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_117 = V_27;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 365));
		NullCheck(L_117);
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_118;
		L_118 = TrackEntry_get_Animation_m5BE3D98B59824CA342B208DD84BB9DE3265F7775(L_117, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 365));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_119 = V_13;
		G_B53_0 = ((((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_118) == ((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_119))? 1 : 0);
		goto IL_0285;
	}

IL_0284:
	{
		G_B53_0 = 0;
	}

IL_0285:
	{
		V_28 = (bool)G_B53_0;
		// if (!isAnimationTransitionMatch) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 366));
		bool L_120 = V_28;
		V_29 = (bool)((((int32_t)L_120) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 367));
		bool L_121 = V_29;
		if (!L_121)
		{
			goto IL_02ed;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 368));
		// dummyAnimationState.ClearTracks();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 369));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_122 = __this->___dummyAnimationState_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 370));
		NullCheck(L_122);
		AnimationState_ClearTracks_mA999F7457875DB7A591547FB7AE9BAE7D8B263B5(L_122, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 370));
		// fromTrack = dummyAnimationState.SetAnimation(0, fromAnimation, fromClipLoop);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 371));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_123 = __this->___dummyAnimationState_2;
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_124 = V_13;
		bool L_125 = V_15;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 372));
		NullCheck(L_123);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_126;
		L_126 = AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D(L_123, 0, L_124, L_125, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 372));
		V_27 = L_126;
		// fromTrack.AllowImmediateQueue();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 373));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_127 = V_27;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 374));
		SpineSkeletonExtensions_AllowImmediateQueue_m6450A5DD17C6052864A9C9866A614ED1857036A8(L_127, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 374));
		// if (toAnimation != null) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 375));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_128 = V_16;
		V_30 = (bool)((!(((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_128) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 376));
		bool L_129 = V_30;
		if (!L_129)
		{
			goto IL_02ec;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 377));
		// toTrack = dummyAnimationState.SetAnimation(0, toAnimation, clipData.loop);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 378));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_130 = __this->___dummyAnimationState_2;
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_131 = V_16;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_132 = V_10;
		NullCheck(L_132);
		bool L_133 = L_132->___loop_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 379));
		NullCheck(L_130);
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_134;
		L_134 = AnimationState_SetAnimation_m99C0C1AFC68FD9DC4DEF9896EE9B1457F0BFB26D(L_130, 0, L_131, L_133, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 379));
		V_26 = L_134;
		// toTrack.HoldPrevious = clipData.holdPrevious;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 380));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_135 = V_26;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_136 = V_10;
		NullCheck(L_136);
		bool L_137 = L_136->___holdPrevious_6;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 381));
		NullCheck(L_135);
		TrackEntry_set_HoldPrevious_m2CDC9D4E79E9F76F21F9DB41133981BDCE411CD3(L_135, L_137, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 381));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 382));
	}

IL_02ec:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 383));
	}

IL_02ed:
	{
		// fromTrack.TrackTime = fromClipTime;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 384));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_138 = V_27;
		float L_139 = V_14;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 385));
		NullCheck(L_138);
		TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3(L_138, L_139, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 385));
		// if (toTrack != null) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 386));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_140 = V_26;
		V_31 = (bool)((!(((RuntimeObject*)(TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB*)L_140) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 387));
		bool L_141 = V_31;
		if (!L_141)
		{
			goto IL_0318;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 388));
		// toTrack.TrackTime = toClipTime;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 389));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_142 = V_26;
		float L_143 = V_17;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 390));
		NullCheck(L_142);
		TrackEntry_set_TrackTime_m6CF1AD30C2A77BCCAB59733C1AE9E13DBA03D7F3(L_142, L_143, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 390));
		// toTrack.MixTime = toClipTime;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 391));
		TrackEntry_t1496EC4C0D889FEFFA9170033055B7CF70FA43EB* L_144 = V_26;
		float L_145 = V_17;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 392));
		NullCheck(L_144);
		TrackEntry_set_MixTime_mA8371A354DA49CDCF4415ED4F23943C03013206D(L_144, L_145, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 392));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 393));
	}

IL_0318:
	{
		// dummyAnimationState.Update(0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 394));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_146 = __this->___dummyAnimationState_2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 395));
		NullCheck(L_146);
		AnimationState_Update_mF60411EBD6B62050473B445C624110B5FBFACA20(L_146, (0.0f), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 395));
		// dummyAnimationState.Apply(skeleton);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 396));
		AnimationState_t056B14929BC2451BF251DE322CC4B9C7982015DC* L_147 = __this->___dummyAnimationState_2;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_148 = V_11;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 397));
		NullCheck(L_147);
		bool L_149;
		L_149 = AnimationState_Apply_mB430A13C849E59376436A50476EB6811FC14E25A(L_147, L_148, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 397));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 398));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 399));
		goto IL_0367;
	}

IL_033a:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 400));
		// if (toAnimation != null)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 401));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_150 = V_16;
		V_32 = (bool)((!(((RuntimeObject*)(Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62*)L_150) <= ((RuntimeObject*)(RuntimeObject*)NULL)))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 402));
		bool L_151 = V_32;
		if (!L_151)
		{
			goto IL_0366;
		}
	}
	{
		// toAnimation.Apply(skeleton, 0, toClipTime, clipData.loop, null, 1f, MixBlend.Setup, MixDirection.In);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 403));
		Animation_tD27D05B1F34A664CFD328E44F1FB594E82757D62* L_152 = V_16;
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_153 = V_11;
		float L_154 = V_17;
		SpineAnimationStateBehaviour_t90E6469ACD974E7BC77D1AA4C0B201AC0D09DB08* L_155 = V_10;
		NullCheck(L_155);
		bool L_156 = L_155->___loop_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 404));
		NullCheck(L_152);
		Animation_Apply_mC43B0C9C2690CCB590A9332824DB73DF94A42608(L_152, L_153, (0.0f), L_154, L_156, (ExposedList_1_t2B9A8726FBAC69918D551BAAAA4E679883EE516E*)NULL, (1.0f), 0, 0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 404));
	}

IL_0366:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 405));
	}

IL_0367:
	{
		// skeleton.UpdateWorldTransform();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 406));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_157 = V_11;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 407));
		NullCheck(L_157);
		Skeleton_UpdateWorldTransform_m12FD1ACD50E9E19EA655B9F4CCD1F39F59B06F92(L_157, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 407));
		// if (skeletonAnimation)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 408));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_158 = ___skeletonAnimation3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 409));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_159;
		L_159 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_158, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 409));
		V_33 = L_159;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 410));
		bool L_160 = V_33;
		if (!L_160)
		{
			goto IL_0386;
		}
	}
	{
		// skeletonAnimation.LateUpdate();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 411));
		SkeletonAnimation_tA7637DB9E47845B3BFB091C272604F43BC71B29A* L_161 = ___skeletonAnimation3;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 412));
		NullCheck(L_161);
		VirtualActionInvoker0::Invoke(10 /* System.Void Spine.Unity.SkeletonRenderer::LateUpdate() */, L_161);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 412));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 413));
		goto IL_039b;
	}

IL_0386:
	{
		// else if (skeletonGraphic)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 414));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_162 = ___skeletonGraphic4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 415));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_163;
		L_163 = Object_op_Implicit_m18E1885C296CC868AC918101523697CFE6413C79(L_162, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 415));
		V_34 = L_163;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 416));
		bool L_164 = V_34;
		if (!L_164)
		{
			goto IL_039b;
		}
	}
	{
		// skeletonGraphic.LateUpdate();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 417));
		SkeletonGraphic_t16853919DC5368237A1FFFE440DFB70ABAFA2AF1* L_165 = ___skeletonGraphic4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 418));
		NullCheck(L_165);
		SkeletonGraphic_LateUpdate_m6A04288EA0CEDAE3A87FC0BC09E797D70B9D4347(L_165, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 418));
	}

IL_039b:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 419));
	}

IL_039c:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 420));
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateMixerBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateMixerBehaviour__ctor_m6BD590C29289864A712F30981FE66DF5A1545834 (SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour__ctor_m6BD590C29289864A712F30981FE66DF5A1545834_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateMixerBehaviour__ctor_m6BD590C29289864A712F30981FE66DF5A1545834_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateTrack_CreateTrackMixer_m2B0FAA0C0DEF16A83A49FC3631C4619D79804D9E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D V_0;
	memset((&V_0), 0, sizeof(V_0));
	SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* V_1 = NULL;
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_2;
	memset((&V_2), 0, sizeof(V_2));
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___graph0), (&___go1), (&___inputCount2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateTrack_CreateTrackMixer_m2B0FAA0C0DEF16A83A49FC3631C4619D79804D9E_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 421));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 422));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 423));
		// var scriptPlayable = ScriptPlayable<SpineAnimationStateMixerBehaviour>.Create(graph, inputCount);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 424));
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		int32_t L_1 = ___inputCount2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 425));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D_il2cpp_TypeInfo_var);
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_2;
		L_2 = ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F(L_0, L_1, ScriptPlayable_1_Create_m528EC0A5B8AE520B9191928961CEF38040073E1F_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 425));
		V_0 = L_2;
		// var mixerBehaviour = scriptPlayable.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 426));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 427));
		SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* L_3;
		L_3 = ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4((&V_0), ScriptPlayable_1_GetBehaviour_m364A796F4E89094AAD19A4A3FB5BBEE6F1B44DD4_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 427));
		V_1 = L_3;
		// mixerBehaviour.trackIndex = this.trackIndex;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 428));
		SpineAnimationStateMixerBehaviour_tD9B4EBFAC03EBDAB1DCF5A58176FFCDC839C6F1D* L_4 = V_1;
		int32_t L_5 = __this->___trackIndex_28;
		NullCheck(L_4);
		L_4->___trackIndex_1 = L_5;
		// return scriptPlayable;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 429));
		ScriptPlayable_1_tC54BCBBDF857E491EA611D5227DF0B44CA009E5D L_6 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 430));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_7;
		L_7 = ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5(L_6, ScriptPlayable_1_op_Implicit_m2F8D717C5C1F7BD40DC8D6ACEC4268A8F6FC5EC5_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 430));
		V_2 = L_7;
		goto IL_0026;
	}

IL_0026:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 431));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_8 = V_2;
		return L_8;
	}
}
// System.Void Spine.Unity.Playables.SpineAnimationStateTrack::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineAnimationStateTrack__ctor_m5C08385174D879806AE50459A3288C5CE649BCA5 (SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateTrack__ctor_m5C08385174D879806AE50459A3288C5CE649BCA5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineAnimationStateTrack_t941852C55DA762EF03EC8419C9DAB1EBBAB309A3_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineAnimationStateTrack__ctor_m5C08385174D879806AE50459A3288C5CE649BCA5_RuntimeMethod_var, methodExecutionContextThis, NULL, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 432));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 433));
	{
		// public int trackIndex = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 434));
		__this->___trackIndex_28 = 0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 435));
		il2cpp_codegen_runtime_class_init_inline(TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A(__this, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 435));
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour_ProcessFrame_mE4F7C08F019E4F32DEAEF9E86BC0A15CBC4CC613_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_0 = NULL;
	int32_t V_1 = 0;
	float V_2 = 0.0f;
	float V_3 = 0.0f;
	int32_t V_4 = 0;
	bool V_5 = false;
	bool V_6 = false;
	int32_t V_7 = 0;
	float V_8 = 0.0f;
	ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 V_9;
	memset((&V_9), 0, sizeof(V_9));
	SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* V_10 = NULL;
	bool V_11 = false;
	bool V_12 = false;
	bool V_13 = false;
	bool V_14 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___playable0), (&___info1), (&___playerData2));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0), (&V_1), (&V_2), (&V_3), (&V_4), (&V_7), (&V_8), (&V_9), (&V_10));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipMixerBehaviour_ProcessFrame_mE4F7C08F019E4F32DEAEF9E86BC0A15CBC4CC613_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 436));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 437));
	int32_t G_B14_0 = 0;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 438));
		// playableHandle = playerData as SpinePlayableHandleBase;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 439));
		RuntimeObject* L_0 = ___playerData2;
		__this->___playableHandle_4 = ((SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570*)IsInstClass((RuntimeObject*)L_0, SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var));
		Il2CppCodeGenWriteBarrier((void**)(&__this->___playableHandle_4), (void*)((SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570*)IsInstClass((RuntimeObject*)L_0, SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570_il2cpp_TypeInfo_var)));
		// if (playableHandle == null)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 440));
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_1 = __this->___playableHandle_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 441));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_2;
		L_2 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_1, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 441));
		V_5 = L_2;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 442));
		bool L_3 = V_5;
		if (!L_3)
		{
			goto IL_0024;
		}
	}
	{
		// return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 443));
		goto IL_014c;
	}

IL_0024:
	{
		// var skeleton = playableHandle.Skeleton;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 444));
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_4 = __this->___playableHandle_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 445));
		NullCheck(L_4);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_5;
		L_5 = VirtualFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(5 /* Spine.Skeleton Spine.Unity.Playables.SpinePlayableHandleBase::get_Skeleton() */, L_4);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 445));
		V_0 = L_5;
		// if (!m_FirstFrameHappened) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 446));
		bool L_6 = __this->___m_FirstFrameHappened_5;
		V_6 = (bool)((((int32_t)L_6) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 447));
		bool L_7 = V_6;
		if (!L_7)
		{
			goto IL_0082;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 448));
		// originalScaleX = skeleton.ScaleX;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 449));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_8 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 450));
		NullCheck(L_8);
		float L_9;
		L_9 = Skeleton_get_ScaleX_m0172910DB4B5C924E6010D1F7E41127B01E70FB3(L_8, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 450));
		__this->___originalScaleX_0 = L_9;
		// originalScaleY = skeleton.ScaleY;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 451));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_10 = V_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 452));
		NullCheck(L_10);
		float L_11;
		L_11 = Skeleton_get_ScaleY_m57C4D92B37F5622B9283BA4C8FD4A94C49D982B4(L_10, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 452));
		__this->___originalScaleY_1 = L_11;
		// baseScaleX = Mathf.Abs(originalScaleX);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 453));
		float L_12 = __this->___originalScaleX_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 454));
		float L_13;
		L_13 = fabsf(L_12);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 454));
		__this->___baseScaleX_2 = L_13;
		// baseScaleY = Mathf.Abs(originalScaleY);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 455));
		float L_14 = __this->___originalScaleY_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 456));
		float L_15;
		L_15 = fabsf(L_14);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 456));
		__this->___baseScaleY_3 = L_15;
		// m_FirstFrameHappened = true;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 457));
		__this->___m_FirstFrameHappened_5 = (bool)1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 458));
	}

IL_0082:
	{
		// int inputCount = playable.GetInputCount();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 459));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_16 = ___playable0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 460));
		int32_t L_17;
		L_17 = PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9(L_16, PlayableExtensions_GetInputCount_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m772B13877349239BF55A96EA7D68F336E9807DE9_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 460));
		V_1 = L_17;
		// float totalWeight = 0f;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 461));
		V_2 = (0.0f);
		// float greatestWeight = 0f;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 462));
		V_3 = (0.0f);
		// int currentInputs = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 463));
		V_4 = 0;
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 464));
		V_7 = 0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 465));
		goto IL_010d;
	}

IL_009d:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 466));
		// float inputWeight = playable.GetInputWeight(i);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 467));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_18 = ___playable0;
		int32_t L_19 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 468));
		float L_20;
		L_20 = PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B(L_18, L_19, PlayableExtensions_GetInputWeight_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m4F6B7FA5420EA769FBD0AB1E4B27450FE1A3A84B_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 468));
		V_8 = L_20;
		// ScriptPlayable<SpineSkeletonFlipBehaviour> inputPlayable = (ScriptPlayable<SpineSkeletonFlipBehaviour>)playable.GetInput(i);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 469));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_21 = ___playable0;
		int32_t L_22 = V_7;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 470));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_23;
		L_23 = PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F(L_21, L_22, PlayableExtensions_GetInput_TisPlayable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_m158A295DC663053FFE765BC7905AD8754138043F_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 470));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 471));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t9E21A524B96633472C7278772BD4086090A1CB22 L_24;
		L_24 = ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E(L_23, ScriptPlayable_1_op_Explicit_m829A56C331E9FBF2CECAFC8BD869050DE3AE6D5E_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 471));
		V_9 = L_24;
		// SpineSkeletonFlipBehaviour input = inputPlayable.GetBehaviour();
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 472));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 473));
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_25;
		L_25 = ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED((&V_9), ScriptPlayable_1_GetBehaviour_mE66E7FC9E64C1D80E7F574AEF46D39E9172B8AED_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 473));
		V_10 = L_25;
		// totalWeight += inputWeight;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 474));
		float L_26 = V_2;
		float L_27 = V_8;
		V_2 = ((float)il2cpp_codegen_add(L_26, L_27));
		// if (inputWeight > greatestWeight) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 475));
		float L_28 = V_8;
		float L_29 = V_3;
		V_11 = (bool)((((float)L_28) > ((float)L_29))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 476));
		bool L_30 = V_11;
		if (!L_30)
		{
			goto IL_00eb;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 477));
		// SetSkeletonScaleFromFlip(skeleton, input.flipX, input.flipY);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 478));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_31 = V_0;
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_32 = V_10;
		NullCheck(L_32);
		bool L_33 = L_32->___flipX_0;
		SpineSkeletonFlipBehaviour_t04A0A079147C9B8CBF4C55F4F6F8119C063F8FBE* L_34 = V_10;
		NullCheck(L_34);
		bool L_35 = L_34->___flipY_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 479));
		SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5(__this, L_31, L_33, L_35, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 479));
		// greatestWeight = inputWeight;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 480));
		float L_36 = V_8;
		V_3 = L_36;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 481));
	}

IL_00eb:
	{
		// if (!Mathf.Approximately(inputWeight, 0f))
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 482));
		float L_37 = V_8;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 483));
		bool L_38;
		L_38 = Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_inline(L_37, (0.0f), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 483));
		V_12 = (bool)((((int32_t)L_38) == ((int32_t)0))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 484));
		bool L_39 = V_12;
		if (!L_39)
		{
			goto IL_0106;
		}
	}
	{
		// currentInputs++;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 485));
		int32_t L_40 = V_4;
		V_4 = ((int32_t)il2cpp_codegen_add(L_40, 1));
	}

IL_0106:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 486));
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 487));
		int32_t L_41 = V_7;
		V_7 = ((int32_t)il2cpp_codegen_add(L_41, 1));
	}

IL_010d:
	{
		// for (int i = 0; i < inputCount; i++) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 488));
		int32_t L_42 = V_7;
		int32_t L_43 = V_1;
		V_13 = (bool)((((int32_t)L_42) < ((int32_t)L_43))? 1 : 0);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 489));
		bool L_44 = V_13;
		if (L_44)
		{
			goto IL_009d;
		}
	}
	{
		// if (currentInputs != 1 && 1f - totalWeight > greatestWeight) {
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 490));
		int32_t L_45 = V_4;
		if ((((int32_t)L_45) == ((int32_t)1)))
		{
			goto IL_0129;
		}
	}
	{
		float L_46 = V_2;
		float L_47 = V_3;
		G_B14_0 = ((((float)((float)il2cpp_codegen_subtract((1.0f), L_46))) > ((float)L_47))? 1 : 0);
		goto IL_012a;
	}

IL_0129:
	{
		G_B14_0 = 0;
	}

IL_012a:
	{
		V_14 = (bool)G_B14_0;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 491));
		bool L_48 = V_14;
		if (!L_48)
		{
			goto IL_014c;
		}
	}
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 492));
		// skeleton.ScaleX = originalScaleX;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 493));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_49 = V_0;
		float L_50 = __this->___originalScaleX_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 494));
		NullCheck(L_49);
		Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02(L_49, L_50, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 494));
		// skeleton.ScaleY = originalScaleY;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 495));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_51 = V_0;
		float L_52 = __this->___originalScaleY_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 496));
		NullCheck(L_51);
		Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A(L_51, L_52, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 496));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 497));
	}

IL_014c:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 498));
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::SetSkeletonScaleFromFlip(Spine.Skeleton,System.Boolean,System.Boolean)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* ___skeleton0, bool ___flipX1, bool ___flipY2, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___skeleton0), (&___flipX1), (&___flipY2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipMixerBehaviour_SetSkeletonScaleFromFlip_m78D3A272C0BB79BCAE7A7CAE03DC801BB473BBD5_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 499));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 500));
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B2_0 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B1_0 = NULL;
	float G_B3_0 = 0.0f;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B3_1 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B5_0 = NULL;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B4_0 = NULL;
	float G_B6_0 = 0.0f;
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* G_B6_1 = NULL;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 501));
		// skeleton.ScaleX = flipX ? -baseScaleX : baseScaleX;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 502));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_0 = ___skeleton0;
		bool L_1 = ___flipX1;
		G_B1_0 = L_0;
		if (L_1)
		{
			G_B2_0 = L_0;
			goto IL_000d;
		}
	}
	{
		float L_2 = __this->___baseScaleX_2;
		G_B3_0 = L_2;
		G_B3_1 = G_B1_0;
		goto IL_0014;
	}

IL_000d:
	{
		float L_3 = __this->___baseScaleX_2;
		G_B3_0 = ((-L_3));
		G_B3_1 = G_B2_0;
	}

IL_0014:
	{
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 503));
		NullCheck(G_B3_1);
		Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02(G_B3_1, G_B3_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 503));
		// skeleton.ScaleY = flipY ? -baseScaleY : baseScaleY;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 504));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_4 = ___skeleton0;
		bool L_5 = ___flipY2;
		G_B4_0 = L_4;
		if (L_5)
		{
			G_B5_0 = L_4;
			goto IL_0026;
		}
	}
	{
		float L_6 = __this->___baseScaleY_3;
		G_B6_0 = L_6;
		G_B6_1 = G_B4_0;
		goto IL_002d;
	}

IL_0026:
	{
		float L_7 = __this->___baseScaleY_3;
		G_B6_0 = ((-L_7));
		G_B6_1 = G_B5_0;
	}

IL_002d:
	{
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 505));
		NullCheck(G_B6_1);
		Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A(G_B6_1, G_B6_0, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 505));
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 506));
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::OnGraphStop(UnityEngine.Playables.Playable)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour_OnGraphStop_m5EA7912190C81F89762618BF49F00555C8978537 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F ___playable0, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour_OnGraphStop_m5EA7912190C81F89762618BF49F00555C8978537_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* V_0 = NULL;
	bool V_1 = false;
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___playable0));
	DECLARE_METHOD_LOCALS(methodExecutionContextLocals, (&V_0));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipMixerBehaviour_OnGraphStop_m5EA7912190C81F89762618BF49F00555C8978537_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, methodExecutionContextLocals);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 507));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 508));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 509));
		// m_FirstFrameHappened = false;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 510));
		__this->___m_FirstFrameHappened_5 = (bool)0;
		// if (playableHandle == null)
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 511));
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_0 = __this->___playableHandle_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 512));
		il2cpp_codegen_runtime_class_init_inline(Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C_il2cpp_TypeInfo_var);
		bool L_1;
		L_1 = Object_op_Equality_mD3DB0D72CE0250C84033DC2A90AEF9D59896E536(L_0, (Object_tC12DECB6760A7F2CBF65D9DCF18D044C2D97152C*)NULL, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 512));
		V_1 = L_1;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 513));
		bool L_2 = V_1;
		if (!L_2)
		{
			goto IL_001a;
		}
	}
	{
		// return;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 514));
		goto IL_0040;
	}

IL_001a:
	{
		// var skeleton = playableHandle.Skeleton;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 515));
		SpinePlayableHandleBase_t391187B46C5A7AB79F8DB447F1E7997167264570* L_3 = __this->___playableHandle_4;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 516));
		NullCheck(L_3);
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_4;
		L_4 = VirtualFuncInvoker0< Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* >::Invoke(5 /* Spine.Skeleton Spine.Unity.Playables.SpinePlayableHandleBase::get_Skeleton() */, L_3);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 516));
		V_0 = L_4;
		// skeleton.ScaleX = originalScaleX;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 517));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_5 = V_0;
		float L_6 = __this->___originalScaleX_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 518));
		NullCheck(L_5);
		Skeleton_set_ScaleX_mB8541BBBB4468873617BB66FC99AA9F85ECBDE02(L_5, L_6, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 518));
		// skeleton.ScaleY = originalScaleY;
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 519));
		Skeleton_tB0DB92F26D8FBB7A7B8D0A52A9E995EC9468EACC* L_7 = V_0;
		float L_8 = __this->___originalScaleY_1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 520));
		NullCheck(L_7);
		Skeleton_set_ScaleY_mEAF31E9493E7D9EFB59AAD19CFB120E5B50DD72A(L_7, L_8, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 520));
	}

IL_0040:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 521));
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipMixerBehaviour::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipMixerBehaviour__ctor_m9975EEBA7F6FC321B1DC75E4D937270E5AB80CF9 (SpineSkeletonFlipMixerBehaviour_t3BD4545402F5D0752B18DF7F6FF3B94675B5E74D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipMixerBehaviour__ctor_m9975EEBA7F6FC321B1DC75E4D937270E5AB80CF9_RuntimeMethod_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipMixerBehaviour__ctor_m9975EEBA7F6FC321B1DC75E4D937270E5AB80CF9_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
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
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB_il2cpp_TypeInfo_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipTrack_CreateTrackMixer_m03EDED11E716C641B10EB6FBE1C763B7DE770048_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F V_0;
	memset((&V_0), 0, sizeof(V_0));
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___graph0), (&___go1), (&___inputCount2));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipTrack_CreateTrackMixer_m03EDED11E716C641B10EB6FBE1C763B7DE770048_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 522));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 523));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 524));
		// return ScriptPlayable<SpineSkeletonFlipMixerBehaviour>.Create(graph, inputCount);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 525));
		PlayableGraph_t4A5B0B45343A240F0761574FD7C672E0CFFF7A6E L_0 = ___graph0;
		int32_t L_1 = ___inputCount2;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 526));
		il2cpp_codegen_runtime_class_init_inline(ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB_il2cpp_TypeInfo_var);
		ScriptPlayable_1_t8902186B43A5B47E753A560DE8920EE6228BB2BB L_2;
		L_2 = ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB(L_0, L_1, ScriptPlayable_1_Create_m0A2ECBE9BAA5DE2FF261301303ACBD77A891C2EB_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 526));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 527));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_3;
		L_3 = ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61(L_2, ScriptPlayable_1_op_Implicit_m34B857C73D3EF573E23D19FD31C7DD0D38D23C61_RuntimeMethod_var);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 527));
		V_0 = L_3;
		goto IL_0010;
	}

IL_0010:
	{
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 528));
		Playable_t95C6B795846BA0C7D96E4DA14897CCCF2554334F L_4 = V_0;
		return L_4;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipTrack::GatherProperties(UnityEngine.Playables.PlayableDirector,UnityEngine.Timeline.IPropertyCollector)
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipTrack_GatherProperties_m8DC1508AB025A66D158D852A7FBC71240AFA68DB (SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0* __this, PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475* ___director0, RuntimeObject* ___driver1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipTrack_GatherProperties_m8DC1508AB025A66D158D852A7FBC71240AFA68DB_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_THIS(methodExecutionContextThis, (&__this));
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___director0), (&___driver1));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipTrack_GatherProperties_m8DC1508AB025A66D158D852A7FBC71240AFA68DB_RuntimeMethod_var, methodExecutionContextThis, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 529));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 530));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 531));
		// base.GatherProperties(director, driver);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 532));
		PlayableDirector_t895D7BC3CFBFFD823278F438EAC4AA91DBFEC475* L_0 = ___director0;
		RuntimeObject* L_1 = ___driver1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 533));
		TrackAsset_GatherProperties_m09C1A335FCE1ABA158748583AF4A641FF2EBB09D(__this, L_0, L_1, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 533));
		// }
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsspineU2Dtimeline + 534));
		return;
	}
}
// System.Void Spine.Unity.Playables.SpineSkeletonFlipTrack::.ctor()
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void SpineSkeletonFlipTrack__ctor_m72A9FAC6E5FE629734F1581BFD47F0F418EC6514 (SpineSkeletonFlipTrack_tD4D6D7B29F401FD9CA64EEA7F6B040D91AA0C7D0* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&SpineSkeletonFlipTrack__ctor_m72A9FAC6E5FE629734F1581BFD47F0F418EC6514_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, SpineSkeletonFlipTrack__ctor_m72A9FAC6E5FE629734F1581BFD47F0F418EC6514_RuntimeMethod_var, NULL, NULL, NULL);
	CHECK_PAUSE_POINT;
	{
		il2cpp_codegen_runtime_class_init_inline(TrackAsset_t31E19BE900C90F6616C0D337652C8614CD833B96_il2cpp_TypeInfo_var);
		TrackAsset__ctor_mC05CAAD737449BAF26721F82EA1972843F86FE9A(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void SpineEventDelegate_Invoke_mC45495D925D396D8D63DC5DA744929191B370775_inline (SpineEventDelegate_t530CC9B5E9370ACEA3B8DBE198CA8B37E0D02B1C* __this, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5* ___e0, const RuntimeMethod* method) 
{
	typedef void (*FunctionPointerType) (RuntimeObject*, Event_t8782CEE361C403E47F27D8A94C1D162945D1E1E5*, const RuntimeMethod*);
	((FunctionPointerType)__this->___invoke_impl_1)((Il2CppObject*)__this->___method_code_6, ___e0, reinterpret_cast<RuntimeMethod*>(__this->___method_3));
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_inline (float ___a0, float ___b1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	bool V_0 = false;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___a0), (&___b1));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, Mathf_Approximately_m1C8DD0BB6A2D22A7DCF09AD7F8EE9ABD12D3F620_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5598));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5599));
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5600));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5601));
		float L_0 = ___b1;
		float L_1 = ___a0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5602));
		float L_2;
		L_2 = fabsf(((float)il2cpp_codegen_subtract(L_0, L_1)));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5602));
		float L_3 = ___a0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5603));
		float L_4;
		L_4 = fabsf(L_3);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5603));
		float L_5 = ___b1;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5604));
		float L_6;
		L_6 = fabsf(L_5);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5604));
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5605));
		float L_7;
		L_7 = Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline(L_4, L_6, NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5605));
		float L_8 = ((Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_StaticFields*)il2cpp_codegen_static_fields_for(Mathf_tE284D016E3B297B72311AAD9EB8F0E643F6A4682_il2cpp_TypeInfo_var))->___Epsilon_0;
		STORE_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5606));
		float L_9;
		L_9 = Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline(((float)il2cpp_codegen_multiply((9.99999997E-07f), L_7)), ((float)il2cpp_codegen_multiply(L_8, (8.0f))), NULL);
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5606));
		V_0 = (bool)((((float)L_2) < ((float)L_9))? 1 : 0);
		goto IL_0035;
	}

IL_0035:
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5607));
		bool L_10 = V_0;
		return L_10;
	}
}
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR float Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_inline (float ___a0, float ___b1, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_RuntimeMethod_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C_0_0_0_var);
		s_Il2CppMethodInitialized = true;
	}
	float V_0 = 0.0f;
	DECLARE_METHOD_PARAMS(methodExecutionContextParameters, (&___a0), (&___b1));
	DECLARE_METHOD_EXEC_CTX(methodExecutionContext, Mathf_Max_mA9DCA91E87D6D27034F56ABA52606A9090406016_RuntimeMethod_var, NULL, methodExecutionContextParameters, NULL);
	CHECK_METHOD_ENTRY_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5472));
	CHECK_METHOD_EXIT_SEQ_POINT(methodExitChecker, methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5473));
	float G_B3_0 = 0.0f;
	{
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5474));
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5475));
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
		CHECK_SEQ_POINT(methodExecutionContext, (g_sequencePointsUnityEngine_CoreModule + 5476));
		float L_4 = V_0;
		return L_4;
	}
}
