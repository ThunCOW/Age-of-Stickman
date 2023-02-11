#include "pch-c.h"
#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif


#include "codegen/il2cpp-codegen-metadata.h"





#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodExecutionContextInfo g_methodExecutionContextInfos[1] = 
{
	{ 10592, 0,  0 } /*tableIndex: 0 */,
};
#else
static const Il2CppMethodExecutionContextInfo g_methodExecutionContextInfos[1] = { { 0, 0, 0 } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const char* g_methodExecutionContextInfoStrings[1] = 
{
	"particle",
};
#else
static const char* g_methodExecutionContextInfoStrings[1] = { NULL };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodExecutionContextInfoIndex g_methodExecutionContextInfoIndexes[37] = 
{
	{ 0, 1 } /* 0x06000001 System.Void UnityEngine.ParticleSystem::Emit(UnityEngine.Vector3,UnityEngine.Vector3,System.Single,System.Single,UnityEngine.Color32) */,
	{ 0, 0 } /* 0x06000002 System.Void UnityEngine.ParticleSystem::Emit(UnityEngine.ParticleSystem/Particle) */,
	{ 0, 0 } /* 0x06000003 System.Single UnityEngine.ParticleSystem::get_time() */,
	{ 0, 0 } /* 0x06000004 System.Void UnityEngine.ParticleSystem::set_randomSeed(System.UInt32) */,
	{ 0, 0 } /* 0x06000005 System.Boolean UnityEngine.ParticleSystem::get_useAutoRandomSeed() */,
	{ 0, 0 } /* 0x06000006 System.Void UnityEngine.ParticleSystem::set_useAutoRandomSeed(System.Boolean) */,
	{ 0, 0 } /* 0x06000007 System.Void UnityEngine.ParticleSystem::Simulate(System.Single,System.Boolean,System.Boolean,System.Boolean) */,
	{ 0, 0 } /* 0x06000008 System.Void UnityEngine.ParticleSystem::Stop(System.Boolean,UnityEngine.ParticleSystemStopBehavior) */,
	{ 0, 0 } /* 0x06000009 System.Void UnityEngine.ParticleSystem::Emit(System.Int32) */,
	{ 0, 0 } /* 0x0600000A System.Void UnityEngine.ParticleSystem::Emit_Internal(System.Int32) */,
	{ 0, 0 } /* 0x0600000B System.Void UnityEngine.ParticleSystem::Emit(UnityEngine.ParticleSystem/EmitParams,System.Int32) */,
	{ 0, 0 } /* 0x0600000C System.Void UnityEngine.ParticleSystem::EmitOld_Internal(UnityEngine.ParticleSystem/Particle&) */,
	{ 0, 0 } /* 0x0600000D UnityEngine.ParticleSystem/MainModule UnityEngine.ParticleSystem::get_main() */,
	{ 0, 0 } /* 0x0600000E UnityEngine.ParticleSystem/SubEmittersModule UnityEngine.ParticleSystem::get_subEmitters() */,
	{ 0, 0 } /* 0x0600000F System.Void UnityEngine.ParticleSystem::.ctor() */,
	{ 0, 0 } /* 0x06000010 System.Void UnityEngine.ParticleSystem::Emit_Injected(UnityEngine.ParticleSystem/EmitParams&,System.Int32) */,
	{ 0, 0 } /* 0x06000011 System.Void UnityEngine.ParticleSystem/MainModule::.ctor(UnityEngine.ParticleSystem) */,
	{ 0, 0 } /* 0x06000012 System.Single UnityEngine.ParticleSystem/MainModule::get_duration() */,
	{ 0, 0 } /* 0x06000013 System.Boolean UnityEngine.ParticleSystem/MainModule::get_loop() */,
	{ 0, 0 } /* 0x06000014 System.Single UnityEngine.ParticleSystem/MainModule::get_duration_Injected(UnityEngine.ParticleSystem/MainModule&) */,
	{ 0, 0 } /* 0x06000015 System.Boolean UnityEngine.ParticleSystem/MainModule::get_loop_Injected(UnityEngine.ParticleSystem/MainModule&) */,
	{ 0, 0 } /* 0x06000016 System.Void UnityEngine.ParticleSystem/SubEmittersModule::.ctor(UnityEngine.ParticleSystem) */,
	{ 0, 0 } /* 0x06000017 System.Int32 UnityEngine.ParticleSystem/SubEmittersModule::get_subEmittersCount() */,
	{ 0, 0 } /* 0x06000018 UnityEngine.ParticleSystem UnityEngine.ParticleSystem/SubEmittersModule::GetSubEmitterSystem(System.Int32) */,
	{ 0, 0 } /* 0x06000019 System.Int32 UnityEngine.ParticleSystem/SubEmittersModule::get_subEmittersCount_Injected(UnityEngine.ParticleSystem/SubEmittersModule&) */,
	{ 0, 0 } /* 0x0600001A UnityEngine.ParticleSystem UnityEngine.ParticleSystem/SubEmittersModule::GetSubEmitterSystem_Injected(UnityEngine.ParticleSystem/SubEmittersModule&,System.Int32) */,
	{ 0, 0 } /* 0x0600001B System.Void UnityEngine.ParticleSystem/Particle::set_lifetime(System.Single) */,
	{ 0, 0 } /* 0x0600001C System.Void UnityEngine.ParticleSystem/Particle::set_position(UnityEngine.Vector3) */,
	{ 0, 0 } /* 0x0600001D System.Void UnityEngine.ParticleSystem/Particle::set_velocity(UnityEngine.Vector3) */,
	{ 0, 0 } /* 0x0600001E System.Void UnityEngine.ParticleSystem/Particle::set_remainingLifetime(System.Single) */,
	{ 0, 0 } /* 0x0600001F System.Void UnityEngine.ParticleSystem/Particle::set_startLifetime(System.Single) */,
	{ 0, 0 } /* 0x06000020 System.Void UnityEngine.ParticleSystem/Particle::set_startColor(UnityEngine.Color32) */,
	{ 0, 0 } /* 0x06000021 System.Void UnityEngine.ParticleSystem/Particle::set_randomSeed(System.UInt32) */,
	{ 0, 0 } /* 0x06000022 System.Void UnityEngine.ParticleSystem/Particle::set_startSize(System.Single) */,
	{ 0, 0 } /* 0x06000023 System.Void UnityEngine.ParticleSystem/Particle::set_rotation3D(UnityEngine.Vector3) */,
	{ 0, 0 } /* 0x06000024 System.Void UnityEngine.ParticleSystem/Particle::set_angularVelocity3D(UnityEngine.Vector3) */,
	{ 0, 0 } /* 0x06000025 System.Int32 UnityEngine.ParticleSystemRenderer::GetMeshes(UnityEngine.Mesh[]) */,
};
#else
static const Il2CppMethodExecutionContextInfoIndex g_methodExecutionContextInfoIndexes[1] = { { 0, 0} };
#endif
#if IL2CPP_MONO_DEBUGGER
IL2CPP_EXTERN_C Il2CppSequencePoint g_sequencePointsUnityEngine_ParticleSystemModule[];
Il2CppSequencePoint g_sequencePointsUnityEngine_ParticleSystemModule[117] = 
{
	{ 27708, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 0 } /* seqPointIndex: 0 */,
	{ 27708, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 1 } /* seqPointIndex: 1 */,
	{ 27708, 1, 120, 120, 9, 10, 0, kSequencePointKind_Normal, 0, 2 } /* seqPointIndex: 2 */,
	{ 27708, 1, 121, 121, 13, 78, 1, kSequencePointKind_Normal, 0, 3 } /* seqPointIndex: 3 */,
	{ 27708, 1, 122, 122, 13, 42, 9, kSequencePointKind_Normal, 0, 4 } /* seqPointIndex: 4 */,
	{ 27708, 1, 122, 122, 13, 42, 12, kSequencePointKind_StepOut, 0, 5 } /* seqPointIndex: 5 */,
	{ 27708, 1, 123, 123, 13, 42, 18, kSequencePointKind_Normal, 0, 6 } /* seqPointIndex: 6 */,
	{ 27708, 1, 123, 123, 13, 42, 21, kSequencePointKind_StepOut, 0, 7 } /* seqPointIndex: 7 */,
	{ 27708, 1, 124, 124, 13, 42, 27, kSequencePointKind_Normal, 0, 8 } /* seqPointIndex: 8 */,
	{ 27708, 1, 124, 124, 13, 42, 31, kSequencePointKind_StepOut, 0, 9 } /* seqPointIndex: 9 */,
	{ 27708, 1, 125, 125, 13, 47, 37, kSequencePointKind_Normal, 0, 10 } /* seqPointIndex: 10 */,
	{ 27708, 1, 125, 125, 13, 47, 41, kSequencePointKind_StepOut, 0, 11 } /* seqPointIndex: 11 */,
	{ 27708, 1, 126, 126, 13, 39, 47, kSequencePointKind_Normal, 0, 12 } /* seqPointIndex: 12 */,
	{ 27708, 1, 126, 126, 13, 39, 50, kSequencePointKind_StepOut, 0, 13 } /* seqPointIndex: 13 */,
	{ 27708, 1, 127, 127, 13, 48, 56, kSequencePointKind_Normal, 0, 14 } /* seqPointIndex: 14 */,
	{ 27708, 1, 127, 127, 13, 48, 58, kSequencePointKind_StepOut, 0, 15 } /* seqPointIndex: 15 */,
	{ 27708, 1, 127, 127, 13, 48, 63, kSequencePointKind_StepOut, 0, 16 } /* seqPointIndex: 16 */,
	{ 27708, 1, 128, 128, 13, 55, 69, kSequencePointKind_Normal, 0, 17 } /* seqPointIndex: 17 */,
	{ 27708, 1, 128, 128, 13, 55, 71, kSequencePointKind_StepOut, 0, 18 } /* seqPointIndex: 18 */,
	{ 27708, 1, 128, 128, 13, 55, 76, kSequencePointKind_StepOut, 0, 19 } /* seqPointIndex: 19 */,
	{ 27708, 1, 129, 129, 13, 41, 82, kSequencePointKind_Normal, 0, 20 } /* seqPointIndex: 20 */,
	{ 27708, 1, 129, 129, 13, 41, 86, kSequencePointKind_StepOut, 0, 21 } /* seqPointIndex: 21 */,
	{ 27708, 1, 130, 130, 13, 37, 92, kSequencePointKind_Normal, 0, 22 } /* seqPointIndex: 22 */,
	{ 27708, 1, 130, 130, 13, 37, 95, kSequencePointKind_StepOut, 0, 23 } /* seqPointIndex: 23 */,
	{ 27708, 1, 131, 131, 13, 44, 101, kSequencePointKind_Normal, 0, 24 } /* seqPointIndex: 24 */,
	{ 27708, 1, 131, 131, 13, 44, 104, kSequencePointKind_StepOut, 0, 25 } /* seqPointIndex: 25 */,
	{ 27708, 1, 132, 132, 9, 10, 110, kSequencePointKind_Normal, 0, 26 } /* seqPointIndex: 26 */,
	{ 27709, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 27 } /* seqPointIndex: 27 */,
	{ 27709, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 28 } /* seqPointIndex: 28 */,
	{ 27709, 1, 136, 136, 9, 10, 0, kSequencePointKind_Normal, 0, 29 } /* seqPointIndex: 29 */,
	{ 27709, 1, 137, 137, 13, 44, 1, kSequencePointKind_Normal, 0, 30 } /* seqPointIndex: 30 */,
	{ 27709, 1, 137, 137, 13, 44, 4, kSequencePointKind_StepOut, 0, 31 } /* seqPointIndex: 31 */,
	{ 27709, 1, 138, 138, 9, 10, 10, kSequencePointKind_Normal, 0, 32 } /* seqPointIndex: 32 */,
	{ 27716, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 33 } /* seqPointIndex: 33 */,
	{ 27716, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 34 } /* seqPointIndex: 34 */,
	{ 27716, 2, 176, 176, 37, 38, 0, kSequencePointKind_Normal, 0, 35 } /* seqPointIndex: 35 */,
	{ 27716, 2, 176, 176, 39, 60, 1, kSequencePointKind_Normal, 0, 36 } /* seqPointIndex: 36 */,
	{ 27716, 2, 176, 176, 39, 60, 3, kSequencePointKind_StepOut, 0, 37 } /* seqPointIndex: 37 */,
	{ 27716, 2, 176, 176, 61, 62, 9, kSequencePointKind_Normal, 0, 38 } /* seqPointIndex: 38 */,
	{ 27720, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 39 } /* seqPointIndex: 39 */,
	{ 27720, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 40 } /* seqPointIndex: 40 */,
	{ 27720, 3, 635, 635, 38, 39, 0, kSequencePointKind_Normal, 0, 41 } /* seqPointIndex: 41 */,
	{ 27720, 3, 635, 635, 40, 68, 1, kSequencePointKind_Normal, 0, 42 } /* seqPointIndex: 42 */,
	{ 27720, 3, 635, 635, 40, 68, 2, kSequencePointKind_StepOut, 0, 43 } /* seqPointIndex: 43 */,
	{ 27720, 3, 635, 635, 69, 70, 10, kSequencePointKind_Normal, 0, 44 } /* seqPointIndex: 44 */,
	{ 27721, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 45 } /* seqPointIndex: 45 */,
	{ 27721, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 46 } /* seqPointIndex: 46 */,
	{ 27721, 3, 653, 653, 52, 53, 0, kSequencePointKind_Normal, 0, 47 } /* seqPointIndex: 47 */,
	{ 27721, 3, 653, 653, 54, 89, 1, kSequencePointKind_Normal, 0, 48 } /* seqPointIndex: 48 */,
	{ 27721, 3, 653, 653, 54, 89, 2, kSequencePointKind_StepOut, 0, 49 } /* seqPointIndex: 49 */,
	{ 27721, 3, 653, 653, 90, 91, 10, kSequencePointKind_Normal, 0, 50 } /* seqPointIndex: 50 */,
	{ 27724, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 51 } /* seqPointIndex: 51 */,
	{ 27724, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 52 } /* seqPointIndex: 52 */,
	{ 27724, 3, 20, 20, 64, 65, 0, kSequencePointKind_Normal, 0, 53 } /* seqPointIndex: 53 */,
	{ 27724, 3, 20, 20, 66, 100, 1, kSequencePointKind_Normal, 0, 54 } /* seqPointIndex: 54 */,
	{ 27724, 3, 20, 20, 101, 102, 8, kSequencePointKind_Normal, 0, 55 } /* seqPointIndex: 55 */,
	{ 27729, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 56 } /* seqPointIndex: 56 */,
	{ 27729, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 57 } /* seqPointIndex: 57 */,
	{ 27729, 3, 497, 497, 71, 72, 0, kSequencePointKind_Normal, 0, 58 } /* seqPointIndex: 58 */,
	{ 27729, 3, 497, 497, 73, 107, 1, kSequencePointKind_Normal, 0, 59 } /* seqPointIndex: 59 */,
	{ 27729, 3, 497, 497, 108, 109, 8, kSequencePointKind_Normal, 0, 60 } /* seqPointIndex: 60 */,
	{ 27734, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 61 } /* seqPointIndex: 61 */,
	{ 27734, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 62 } /* seqPointIndex: 62 */,
	{ 27734, 1, 94, 94, 75, 76, 0, kSequencePointKind_Normal, 0, 63 } /* seqPointIndex: 63 */,
	{ 27734, 1, 94, 94, 77, 103, 1, kSequencePointKind_Normal, 0, 64 } /* seqPointIndex: 64 */,
	{ 27734, 1, 94, 94, 77, 103, 3, kSequencePointKind_StepOut, 0, 65 } /* seqPointIndex: 65 */,
	{ 27734, 1, 94, 94, 104, 105, 9, kSequencePointKind_Normal, 0, 66 } /* seqPointIndex: 66 */,
	{ 27735, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 67 } /* seqPointIndex: 67 */,
	{ 27735, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 68 } /* seqPointIndex: 68 */,
	{ 27735, 4, 190, 190, 70, 71, 0, kSequencePointKind_Normal, 0, 69 } /* seqPointIndex: 69 */,
	{ 27735, 4, 190, 190, 72, 91, 1, kSequencePointKind_Normal, 0, 70 } /* seqPointIndex: 70 */,
	{ 27735, 4, 190, 190, 92, 93, 8, kSequencePointKind_Normal, 0, 71 } /* seqPointIndex: 71 */,
	{ 27736, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 72 } /* seqPointIndex: 72 */,
	{ 27736, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 73 } /* seqPointIndex: 73 */,
	{ 27736, 4, 191, 191, 70, 71, 0, kSequencePointKind_Normal, 0, 74 } /* seqPointIndex: 74 */,
	{ 27736, 4, 191, 191, 72, 91, 1, kSequencePointKind_Normal, 0, 75 } /* seqPointIndex: 75 */,
	{ 27736, 4, 191, 191, 92, 93, 8, kSequencePointKind_Normal, 0, 76 } /* seqPointIndex: 76 */,
	{ 27737, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 77 } /* seqPointIndex: 77 */,
	{ 27737, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 78 } /* seqPointIndex: 78 */,
	{ 27737, 4, 194, 194, 77, 78, 0, kSequencePointKind_Normal, 0, 79 } /* seqPointIndex: 79 */,
	{ 27737, 4, 194, 194, 79, 98, 1, kSequencePointKind_Normal, 0, 80 } /* seqPointIndex: 80 */,
	{ 27737, 4, 194, 194, 99, 100, 8, kSequencePointKind_Normal, 0, 81 } /* seqPointIndex: 81 */,
	{ 27738, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 82 } /* seqPointIndex: 82 */,
	{ 27738, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 83 } /* seqPointIndex: 83 */,
	{ 27738, 4, 195, 195, 78, 79, 0, kSequencePointKind_Normal, 0, 84 } /* seqPointIndex: 84 */,
	{ 27738, 4, 195, 195, 80, 104, 1, kSequencePointKind_Normal, 0, 85 } /* seqPointIndex: 85 */,
	{ 27738, 4, 195, 195, 105, 106, 8, kSequencePointKind_Normal, 0, 86 } /* seqPointIndex: 86 */,
	{ 27739, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 87 } /* seqPointIndex: 87 */,
	{ 27739, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 88 } /* seqPointIndex: 88 */,
	{ 27739, 4, 196, 196, 74, 75, 0, kSequencePointKind_Normal, 0, 89 } /* seqPointIndex: 89 */,
	{ 27739, 4, 196, 196, 76, 97, 1, kSequencePointKind_Normal, 0, 90 } /* seqPointIndex: 90 */,
	{ 27739, 4, 196, 196, 98, 99, 8, kSequencePointKind_Normal, 0, 91 } /* seqPointIndex: 91 */,
	{ 27740, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 92 } /* seqPointIndex: 92 */,
	{ 27740, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 93 } /* seqPointIndex: 93 */,
	{ 27740, 4, 197, 197, 73, 74, 0, kSequencePointKind_Normal, 0, 94 } /* seqPointIndex: 94 */,
	{ 27740, 4, 197, 197, 75, 96, 1, kSequencePointKind_Normal, 0, 95 } /* seqPointIndex: 95 */,
	{ 27740, 4, 197, 197, 97, 98, 8, kSequencePointKind_Normal, 0, 96 } /* seqPointIndex: 96 */,
	{ 27741, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 97 } /* seqPointIndex: 97 */,
	{ 27741, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 98 } /* seqPointIndex: 98 */,
	{ 27741, 4, 200, 200, 72, 73, 0, kSequencePointKind_Normal, 0, 99 } /* seqPointIndex: 99 */,
	{ 27741, 4, 200, 200, 74, 121, 1, kSequencePointKind_Normal, 0, 100 } /* seqPointIndex: 100 */,
	{ 27741, 4, 200, 200, 74, 121, 5, kSequencePointKind_StepOut, 0, 101 } /* seqPointIndex: 101 */,
	{ 27741, 4, 200, 200, 122, 123, 15, kSequencePointKind_Normal, 0, 102 } /* seqPointIndex: 102 */,
	{ 27742, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 103 } /* seqPointIndex: 103 */,
	{ 27742, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 104 } /* seqPointIndex: 104 */,
	{ 27742, 4, 204, 204, 88, 89, 0, kSequencePointKind_Normal, 0, 105 } /* seqPointIndex: 105 */,
	{ 27742, 4, 204, 204, 90, 125, 1, kSequencePointKind_Normal, 0, 106 } /* seqPointIndex: 106 */,
	{ 27742, 4, 204, 204, 90, 125, 8, kSequencePointKind_StepOut, 0, 107 } /* seqPointIndex: 107 */,
	{ 27742, 4, 204, 204, 126, 162, 18, kSequencePointKind_Normal, 0, 108 } /* seqPointIndex: 108 */,
	{ 27742, 4, 204, 204, 163, 164, 32, kSequencePointKind_Normal, 0, 109 } /* seqPointIndex: 109 */,
	{ 27743, 0, 0, 0, 0, 0, -1, kSequencePointKind_Normal, 0, 110 } /* seqPointIndex: 110 */,
	{ 27743, 0, 0, 0, 0, 0, 16777215, kSequencePointKind_Normal, 0, 111 } /* seqPointIndex: 111 */,
	{ 27743, 4, 207, 207, 102, 103, 0, kSequencePointKind_Normal, 0, 112 } /* seqPointIndex: 112 */,
	{ 27743, 4, 207, 207, 104, 146, 1, kSequencePointKind_Normal, 0, 113 } /* seqPointIndex: 113 */,
	{ 27743, 4, 207, 207, 104, 146, 8, kSequencePointKind_StepOut, 0, 114 } /* seqPointIndex: 114 */,
	{ 27743, 4, 207, 207, 147, 183, 18, kSequencePointKind_Normal, 0, 115 } /* seqPointIndex: 115 */,
	{ 27743, 4, 207, 207, 184, 185, 32, kSequencePointKind_Normal, 0, 116 } /* seqPointIndex: 116 */,
};
#else
extern Il2CppSequencePoint g_sequencePointsUnityEngine_ParticleSystemModule[];
Il2CppSequencePoint g_sequencePointsUnityEngine_ParticleSystemModule[1] = { { 0, 0, 0, 0, 0, 0, 0, kSequencePointKind_Normal, 0, 0, } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppCatchPoint g_catchPoints[1] = { { 0, 0, 0, 0, } };
#else
static const Il2CppCatchPoint g_catchPoints[1] = { { 0, 0, 0, 0, } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppSequencePointSourceFile g_sequencePointSourceFiles[] = {
{ "", { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} }, //0 
{ "\\Users\\bokken\\buildslave\\unity\\build\\Modules\\ParticleSystem\\Managed\\ParticleSystem.deprecated.cs", { 254, 108, 111, 128, 100, 7, 222, 4, 156, 244, 245, 164, 175, 217, 189, 197} }, //1 
{ "\\Users\\bokken\\buildslave\\unity\\build\\Modules\\ParticleSystem\\ScriptBindings\\ParticleSystem.bindings.cs", { 236, 65, 203, 223, 251, 100, 230, 5, 113, 251, 2, 165, 182, 52, 78, 2} }, //2 
{ "\\Users\\bokken\\buildslave\\unity\\build\\Modules\\ParticleSystem\\ScriptBindings\\ParticleSystemModules.bindings.cs", { 3, 133, 160, 165, 97, 183, 14, 149, 224, 6, 3, 184, 42, 99, 31, 70} }, //3 
{ "\\Users\\bokken\\buildslave\\unity\\build\\Modules\\ParticleSystem\\Managed\\ParticleSystemStructs.cs", { 220, 239, 182, 144, 220, 43, 200, 140, 248, 250, 235, 227, 210, 7, 223, 37} }, //4 
};
#else
static const Il2CppSequencePointSourceFile g_sequencePointSourceFiles[1] = { NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppTypeSourceFilePair g_typeSourceFiles[7] = 
{
	{ 4097, 1 },
	{ 4097, 2 },
	{ 4097, 3 },
	{ 4093, 3 },
	{ 4094, 3 },
	{ 4095, 1 },
	{ 4095, 4 },
};
#else
static const Il2CppTypeSourceFilePair g_typeSourceFiles[1] = { { 0, 0 } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodScope g_methodScopes[3] = 
{
	{ 0, 111 },
	{ 0, 12 },
	{ 0, 12 },
};
#else
static const Il2CppMethodScope g_methodScopes[1] = { { 0, 0 } };
#endif
#if IL2CPP_MONO_DEBUGGER
static const Il2CppMethodHeaderInfo g_methodHeaderInfos[37] = 
{
	{ 111, 0, 1 } /* System.Void UnityEngine.ParticleSystem::Emit(UnityEngine.Vector3,UnityEngine.Vector3,System.Single,System.Single,UnityEngine.Color32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Emit(UnityEngine.ParticleSystem/Particle) */,
	{ 0, 0, 0 } /* System.Single UnityEngine.ParticleSystem::get_time() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::set_randomSeed(System.UInt32) */,
	{ 0, 0, 0 } /* System.Boolean UnityEngine.ParticleSystem::get_useAutoRandomSeed() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::set_useAutoRandomSeed(System.Boolean) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Simulate(System.Single,System.Boolean,System.Boolean,System.Boolean) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Stop(System.Boolean,UnityEngine.ParticleSystemStopBehavior) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Emit(System.Int32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Emit_Internal(System.Int32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Emit(UnityEngine.ParticleSystem/EmitParams,System.Int32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::EmitOld_Internal(UnityEngine.ParticleSystem/Particle&) */,
	{ 12, 1, 1 } /* UnityEngine.ParticleSystem/MainModule UnityEngine.ParticleSystem::get_main() */,
	{ 12, 2, 1 } /* UnityEngine.ParticleSystem/SubEmittersModule UnityEngine.ParticleSystem::get_subEmitters() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::.ctor() */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem::Emit_Injected(UnityEngine.ParticleSystem/EmitParams&,System.Int32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/MainModule::.ctor(UnityEngine.ParticleSystem) */,
	{ 0, 0, 0 } /* System.Single UnityEngine.ParticleSystem/MainModule::get_duration() */,
	{ 0, 0, 0 } /* System.Boolean UnityEngine.ParticleSystem/MainModule::get_loop() */,
	{ 0, 0, 0 } /* System.Single UnityEngine.ParticleSystem/MainModule::get_duration_Injected(UnityEngine.ParticleSystem/MainModule&) */,
	{ 0, 0, 0 } /* System.Boolean UnityEngine.ParticleSystem/MainModule::get_loop_Injected(UnityEngine.ParticleSystem/MainModule&) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/SubEmittersModule::.ctor(UnityEngine.ParticleSystem) */,
	{ 0, 0, 0 } /* System.Int32 UnityEngine.ParticleSystem/SubEmittersModule::get_subEmittersCount() */,
	{ 0, 0, 0 } /* UnityEngine.ParticleSystem UnityEngine.ParticleSystem/SubEmittersModule::GetSubEmitterSystem(System.Int32) */,
	{ 0, 0, 0 } /* System.Int32 UnityEngine.ParticleSystem/SubEmittersModule::get_subEmittersCount_Injected(UnityEngine.ParticleSystem/SubEmittersModule&) */,
	{ 0, 0, 0 } /* UnityEngine.ParticleSystem UnityEngine.ParticleSystem/SubEmittersModule::GetSubEmitterSystem_Injected(UnityEngine.ParticleSystem/SubEmittersModule&,System.Int32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_lifetime(System.Single) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_position(UnityEngine.Vector3) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_velocity(UnityEngine.Vector3) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_remainingLifetime(System.Single) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_startLifetime(System.Single) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_startColor(UnityEngine.Color32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_randomSeed(System.UInt32) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_startSize(System.Single) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_rotation3D(UnityEngine.Vector3) */,
	{ 0, 0, 0 } /* System.Void UnityEngine.ParticleSystem/Particle::set_angularVelocity3D(UnityEngine.Vector3) */,
	{ 0, 0, 0 } /* System.Int32 UnityEngine.ParticleSystemRenderer::GetMeshes(UnityEngine.Mesh[]) */,
};
#else
static const Il2CppMethodHeaderInfo g_methodHeaderInfos[1] = { { 0, 0, 0 } };
#endif
IL2CPP_EXTERN_C const Il2CppDebuggerMetadataRegistration g_DebuggerMetadataRegistrationUnityEngine_ParticleSystemModule;
const Il2CppDebuggerMetadataRegistration g_DebuggerMetadataRegistrationUnityEngine_ParticleSystemModule = 
{
	(Il2CppMethodExecutionContextInfo*)g_methodExecutionContextInfos,
	(Il2CppMethodExecutionContextInfoIndex*)g_methodExecutionContextInfoIndexes,
	(Il2CppMethodScope*)g_methodScopes,
	(Il2CppMethodHeaderInfo*)g_methodHeaderInfos,
	(Il2CppSequencePointSourceFile*)g_sequencePointSourceFiles,
	117,
	(Il2CppSequencePoint*)g_sequencePointsUnityEngine_ParticleSystemModule,
	0,
	(Il2CppCatchPoint*)g_catchPoints,
	7,
	(Il2CppTypeSourceFilePair*)g_typeSourceFiles,
	(const char**)g_methodExecutionContextInfoStrings,
};
