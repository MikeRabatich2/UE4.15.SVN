// This code contains NVIDIA Confidential Information and is disclosed to you
// under a form of NVIDIA software license agreement provided separately to you.
//
// Notice
// NVIDIA Corporation and its licensors retain all intellectual property and
// proprietary rights in and to this software and related documentation and
// any modifications thereto. Any use, reproduction, disclosure, or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA Corporation is strictly prohibited.
//
// ALL NVIDIA DESIGN SPECIFICATIONS, CODE ARE PROVIDED "AS IS.". NVIDIA MAKES
// NO WARRANTIES, EXPRESSED, IMPLIED, STATUTORY, OR OTHERWISE WITH RESPECT TO
// THE MATERIALS, AND EXPRESSLY DISCLAIMS ALL IMPLIED WARRANTIES OF NONINFRINGEMENT,
// MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE.
//
// Information and code furnished is believed to be accurate and reliable.
// However, NVIDIA Corporation assumes no responsibility for the consequences of use of such
// information or for any infringement of patents or other rights of third parties that may
// result from its use. No license is granted by implication or otherwise under any patent
// or patent rights of NVIDIA Corporation. Details are subject to change without notice.
// This code supersedes and replaces all information previously supplied.
// NVIDIA Corporation products are not authorized for use as critical
// components in life support devices or systems without express written approval of
// NVIDIA Corporation.
//
// Copyright (c) 2008-2015 NVIDIA Corporation. All rights reserved.

// This file was generated by NvParameterized/scripts/GenParameterized.pl


#ifndef HEADER_ClothingActorParam_0p2_h
#define HEADER_ClothingActorParam_0p2_h

#include "NvParametersTypes.h"

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
#include "nvparameterized/NvParameterized.h"
#include "nvparameterized/NvParameterizedTraits.h"
#include "NvParameters.h"
#include "NvTraitsInternal.h"
#endif

namespace nvidia
{
namespace parameterized
{

#if PX_VC
#pragma warning(push)
#pragma warning(disable: 4324) // structure was padded due to __declspec(align())
#endif

namespace ClothingActorParam_0p2NS
{

struct GroupsMask_Type;
struct LODWeights_Type;
struct ClothDescTemplate_Type;
struct ShapeDescFlags_Type;
struct ShapeDescTemplate_Type;
struct ActorDescTemplate_Type;
struct WindParameters_Type;
struct MaxDistanceScale_Type;
struct ClothingActorFlags_Type;

struct MAT44_DynamicArray1D_Type
{
	physx::PxMat44* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct VEC3_DynamicArray1D_Type
{
	physx::PxVec3* buf;
	bool isAllocated;
	int32_t elementSize;
	int32_t arraySizes[1];
};

struct ActorDescTemplate_Type
{
	uint64_t userData;
	uint64_t name;
};
struct GroupsMask_Type
{
	uint32_t bits0;
	uint32_t bits1;
	uint32_t bits2;
	uint32_t bits3;
};
struct ClothDescTemplate_Type
{
	float collisionResponseCoefficient;
	uint16_t collisionGroup;
	GroupsMask_Type groupsMask;
	physx::PxBounds3 validBounds;
	uint64_t compartment;
	uint64_t userData;
};
struct MaxDistanceScale_Type
{
	float Scale;
	bool Multipliable;
};
struct ClothingActorFlags_Type
{
	bool ParallelPhysXMeshSkinning;
	bool ParallelMeshMeshSkinning;
	bool ParallelCpuSkinning;
	bool RecomputeNormals;
	bool Visualize;
};
struct ShapeDescFlags_Type
{
	bool NX_SF_VISUALIZATION;
	bool NX_SF_DISABLE_COLLISION;
	bool NX_SF_DISABLE_RAYCASTING;
	bool NX_SF_DYNAMIC_DYNAMIC_CCD;
	bool NX_SF_DISABLE_SCENE_QUERIES;
};
struct ShapeDescTemplate_Type
{
	ShapeDescFlags_Type flags;
	uint16_t collisionGroup;
	GroupsMask_Type groupsMask;
	uint16_t materialIndex;
	uint64_t userData;
	uint64_t name;
};
struct WindParameters_Type
{
	physx::PxVec3 Velocity;
	float Adaption;
};
struct LODWeights_Type
{
	float maxDistance;
	float distanceWeight;
	float bias;
	float benefitsBias;
};

struct ParametersStruct
{

	physx::PxMat44 globalPose;
	bool useHardwareCloth;
	ClothingActorFlags_Type flags;
	bool fallbackSkinning;
	bool slowStart;
	bool useInternalBoneOrder;
	bool updateStateWithGlobalMatrices;
	uint32_t uvChannelForTangentUpdate;
	float maxDistanceBlendTime;
	uint32_t clothingMaterialIndex;
	LODWeights_Type lodWeights;
	WindParameters_Type windParams;
	MaxDistanceScale_Type maxDistanceScale;
	uint64_t userData;
	MAT44_DynamicArray1D_Type boneMatrices;
	ClothDescTemplate_Type clothDescTemplate;
	ShapeDescTemplate_Type shapeDescTemplate;
	ActorDescTemplate_Type actorDescTemplate;
	float actorScale;
	NvParameterized::Interface* runtimeCooked;
	VEC3_DynamicArray1D_Type morphDisplacements;
	VEC3_DynamicArray1D_Type morphPhysicalMeshNewPositions;

};

static const uint32_t checksum[] = { 0x931064bf, 0x4b58babd, 0xd449c5ad, 0x56a18a24, };

} // namespace ClothingActorParam_0p2NS

#ifndef NV_PARAMETERIZED_ONLY_LAYOUTS
class ClothingActorParam_0p2 : public NvParameterized::NvParameters, public ClothingActorParam_0p2NS::ParametersStruct
{
public:
	ClothingActorParam_0p2(NvParameterized::Traits* traits, void* buf = 0, int32_t* refCount = 0);

	virtual ~ClothingActorParam_0p2();

	virtual void destroy();

	static const char* staticClassName(void)
	{
		return("ClothingActorParam");
	}

	const char* className(void) const
	{
		return(staticClassName());
	}

	static const uint32_t ClassVersion = ((uint32_t)0 << 16) + (uint32_t)2;

	static uint32_t staticVersion(void)
	{
		return ClassVersion;
	}

	uint32_t version(void) const
	{
		return(staticVersion());
	}

	static const uint32_t ClassAlignment = 8;

	static const uint32_t* staticChecksum(uint32_t& bits)
	{
		bits = 8 * sizeof(ClothingActorParam_0p2NS::checksum);
		return ClothingActorParam_0p2NS::checksum;
	}

	static void freeParameterDefinitionTable(NvParameterized::Traits* traits);

	const uint32_t* checksum(uint32_t& bits) const
	{
		return staticChecksum(bits);
	}

	const ClothingActorParam_0p2NS::ParametersStruct& parameters(void) const
	{
		ClothingActorParam_0p2* tmpThis = const_cast<ClothingActorParam_0p2*>(this);
		return *(static_cast<ClothingActorParam_0p2NS::ParametersStruct*>(tmpThis));
	}

	ClothingActorParam_0p2NS::ParametersStruct& parameters(void)
	{
		return *(static_cast<ClothingActorParam_0p2NS::ParametersStruct*>(this));
	}

	virtual NvParameterized::ErrorType getParameterHandle(const char* long_name, NvParameterized::Handle& handle) const;
	virtual NvParameterized::ErrorType getParameterHandle(const char* long_name, NvParameterized::Handle& handle);

	void initDefaults(void);

protected:

	virtual const NvParameterized::DefinitionImpl* getParameterDefinitionTree(void);
	virtual const NvParameterized::DefinitionImpl* getParameterDefinitionTree(void) const;


	virtual void getVarPtr(const NvParameterized::Handle& handle, void*& ptr, size_t& offset) const;

private:

	void buildTree(void);
	void initDynamicArrays(void);
	void initStrings(void);
	void initReferences(void);
	void freeDynamicArrays(void);
	void freeStrings(void);
	void freeReferences(void);

	static bool mBuiltFlag;
	static NvParameterized::MutexType mBuiltFlagMutex;
};

class ClothingActorParam_0p2Factory : public NvParameterized::Factory
{
	static const char* const vptr;

public:

	virtual void freeParameterDefinitionTable(NvParameterized::Traits* traits)
	{
		ClothingActorParam_0p2::freeParameterDefinitionTable(traits);
	}

	virtual NvParameterized::Interface* create(NvParameterized::Traits* paramTraits)
	{
		// placement new on this class using mParameterizedTraits

		void* newPtr = paramTraits->alloc(sizeof(ClothingActorParam_0p2), ClothingActorParam_0p2::ClassAlignment);
		if (!NvParameterized::IsAligned(newPtr, ClothingActorParam_0p2::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class ClothingActorParam_0p2");
			paramTraits->free(newPtr);
			return 0;
		}

		memset(newPtr, 0, sizeof(ClothingActorParam_0p2)); // always initialize memory allocated to zero for default values
		return NV_PARAM_PLACEMENT_NEW(newPtr, ClothingActorParam_0p2)(paramTraits);
	}

	virtual NvParameterized::Interface* finish(NvParameterized::Traits* paramTraits, void* bufObj, void* bufStart, int32_t* refCount)
	{
		if (!NvParameterized::IsAligned(bufObj, ClothingActorParam_0p2::ClassAlignment)
		        || !NvParameterized::IsAligned(bufStart, ClothingActorParam_0p2::ClassAlignment))
		{
			NV_PARAM_TRAITS_WARNING(paramTraits, "Unaligned memory allocation for class ClothingActorParam_0p2");
			return 0;
		}

		// Init NvParameters-part
		// We used to call empty constructor of ClothingActorParam_0p2 here
		// but it may call default constructors of members and spoil the data
		NV_PARAM_PLACEMENT_NEW(bufObj, NvParameterized::NvParameters)(paramTraits, bufStart, refCount);

		// Init vtable (everything else is already initialized)
		*(const char**)bufObj = vptr;

		return (ClothingActorParam_0p2*)bufObj;
	}

	virtual const char* getClassName()
	{
		return (ClothingActorParam_0p2::staticClassName());
	}

	virtual uint32_t getVersion()
	{
		return (ClothingActorParam_0p2::staticVersion());
	}

	virtual uint32_t getAlignment()
	{
		return (ClothingActorParam_0p2::ClassAlignment);
	}

	virtual const uint32_t* getChecksum(uint32_t& bits)
	{
		return (ClothingActorParam_0p2::staticChecksum(bits));
	}
};
#endif // NV_PARAMETERIZED_ONLY_LAYOUTS

} // namespace parameterized
} // namespace nvidia

#if PX_VC
#pragma warning(pop)
#endif

#endif
