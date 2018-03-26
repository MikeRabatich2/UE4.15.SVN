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


#include "VertexFormatParameters.h"
#include <string.h>
#include <stdlib.h>

using namespace NvParameterized;

namespace nvidia
{
namespace apex
{

using namespace VertexFormatParametersNS;

const char* const VertexFormatParametersFactory::vptr =
    NvParameterized::getVptr<VertexFormatParameters, VertexFormatParameters::ClassAlignment>();

const uint32_t NumParamDefs = 11;
static NvParameterized::DefinitionImpl* ParamDefTable; // now allocated in buildTree [NumParamDefs];


static const size_t ParamLookupChildrenTable[] =
{
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
};

#define TENUM(type) nvidia::##type
#define CHILDREN(index) &ParamLookupChildrenTable[index]
static const NvParameterized::ParamLookupNode ParamLookupTable[NumParamDefs] =
{
	{ TYPE_STRUCT, false, 0, CHILDREN(0), 3 },
	{ TYPE_U32, false, (size_t)(&((ParametersStruct*)0)->winding), NULL, 0 }, // winding
	{ TYPE_BOOL, false, (size_t)(&((ParametersStruct*)0)->hasSeparateBoneBuffer), NULL, 0 }, // hasSeparateBoneBuffer
	{ TYPE_ARRAY, true, (size_t)(&((ParametersStruct*)0)->bufferFormats), CHILDREN(3), 1 }, // bufferFormats
	{ TYPE_STRUCT, false, 1 * sizeof(BufferFormat_Type), CHILDREN(4), 6 }, // bufferFormats[]
	{ TYPE_STRING, false, (size_t)(&((BufferFormat_Type*)0)->name), NULL, 0 }, // bufferFormats[].name
	{ TYPE_I32, false, (size_t)(&((BufferFormat_Type*)0)->semantic), NULL, 0 }, // bufferFormats[].semantic
	{ TYPE_U32, false, (size_t)(&((BufferFormat_Type*)0)->id), NULL, 0 }, // bufferFormats[].id
	{ TYPE_U32, false, (size_t)(&((BufferFormat_Type*)0)->format), NULL, 0 }, // bufferFormats[].format
	{ TYPE_U32, false, (size_t)(&((BufferFormat_Type*)0)->access), NULL, 0 }, // bufferFormats[].access
	{ TYPE_BOOL, false, (size_t)(&((BufferFormat_Type*)0)->serialize), NULL, 0 }, // bufferFormats[].serialize
};


bool VertexFormatParameters::mBuiltFlag = false;
NvParameterized::MutexType VertexFormatParameters::mBuiltFlagMutex;

VertexFormatParameters::VertexFormatParameters(NvParameterized::Traits* traits, void* buf, int32_t* refCount) :
	NvParameters(traits, buf, refCount)
{
	//mParameterizedTraits->registerFactory(className(), &VertexFormatParametersFactoryInst);

	if (!buf) //Do not init data if it is inplace-deserialized
	{
		initDynamicArrays();
		initStrings();
		initReferences();
		initDefaults();
	}
}

VertexFormatParameters::~VertexFormatParameters()
{
	freeStrings();
	freeReferences();
	freeDynamicArrays();
}

void VertexFormatParameters::destroy()
{
	// We cache these fields here to avoid overwrite in destructor
	bool doDeallocateSelf = mDoDeallocateSelf;
	NvParameterized::Traits* traits = mParameterizedTraits;
	int32_t* refCount = mRefCount;
	void* buf = mBuffer;

	this->~VertexFormatParameters();

	NvParameters::destroy(this, traits, doDeallocateSelf, refCount, buf);
}

const NvParameterized::DefinitionImpl* VertexFormatParameters::getParameterDefinitionTree(void)
{
	if (!mBuiltFlag) // Double-checked lock
	{
		NvParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);
		if (!mBuiltFlag)
		{
			buildTree();
		}
	}

	return(&ParamDefTable[0]);
}

const NvParameterized::DefinitionImpl* VertexFormatParameters::getParameterDefinitionTree(void) const
{
	VertexFormatParameters* tmpParam = const_cast<VertexFormatParameters*>(this);

	if (!mBuiltFlag) // Double-checked lock
	{
		NvParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);
		if (!mBuiltFlag)
		{
			tmpParam->buildTree();
		}
	}

	return(&ParamDefTable[0]);
}

NvParameterized::ErrorType VertexFormatParameters::getParameterHandle(const char* long_name, Handle& handle) const
{
	ErrorType Ret = NvParameters::getParameterHandle(long_name, handle);
	if (Ret != ERROR_NONE)
	{
		return(Ret);
	}

	size_t offset;
	void* ptr;

	getVarPtr(handle, ptr, offset);

	if (ptr == NULL)
	{
		return(ERROR_INDEX_OUT_OF_RANGE);
	}

	return(ERROR_NONE);
}

NvParameterized::ErrorType VertexFormatParameters::getParameterHandle(const char* long_name, Handle& handle)
{
	ErrorType Ret = NvParameters::getParameterHandle(long_name, handle);
	if (Ret != ERROR_NONE)
	{
		return(Ret);
	}

	size_t offset;
	void* ptr;

	getVarPtr(handle, ptr, offset);

	if (ptr == NULL)
	{
		return(ERROR_INDEX_OUT_OF_RANGE);
	}

	return(ERROR_NONE);
}

void VertexFormatParameters::getVarPtr(const Handle& handle, void*& ptr, size_t& offset) const
{
	ptr = getVarPtrHelper(&ParamLookupTable[0], const_cast<VertexFormatParameters::ParametersStruct*>(&parameters()), handle, offset);
}


/* Dynamic Handle Indices */
/* [1,0] - bufferFormats.name */

void VertexFormatParameters::freeParameterDefinitionTable(NvParameterized::Traits* traits)
{
	if (!traits)
	{
		return;
	}

	if (!mBuiltFlag) // Double-checked lock
	{
		return;
	}

	NvParameterized::MutexType::ScopedLock lock(mBuiltFlagMutex);

	if (!mBuiltFlag)
	{
		return;
	}

	for (uint32_t i = 0; i < NumParamDefs; ++i)
	{
		ParamDefTable[i].~DefinitionImpl();
	}

	traits->free(ParamDefTable);

	mBuiltFlag = false;
}

#define PDEF_PTR(index) (&ParamDefTable[index])

void VertexFormatParameters::buildTree(void)
{

	uint32_t allocSize = sizeof(NvParameterized::DefinitionImpl) * NumParamDefs;
	ParamDefTable = (NvParameterized::DefinitionImpl*)(mParameterizedTraits->alloc(allocSize));
	memset(ParamDefTable, 0, allocSize);

	for (uint32_t i = 0; i < NumParamDefs; ++i)
	{
		NV_PARAM_PLACEMENT_NEW(ParamDefTable + i, NvParameterized::DefinitionImpl)(*mParameterizedTraits);
	}

	// Initialize DefinitionImpl node: nodeIndex=0, longName=""
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[0];
		ParamDef->init("", TYPE_STRUCT, "STRUCT", true);






	}

	// Initialize DefinitionImpl node: nodeIndex=1, longName="winding"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[1];
		ParamDef->init("winding", TYPE_U32, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "This value defines which vertex winding orders will be rendered.  See RenderCullMode.", true);
		HintTable[1].init("shortDescription", "Vertex orders to be rendered", true);
		ParamDefTable[1].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=2, longName="hasSeparateBoneBuffer"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[2];
		ParamDef->init("hasSeparateBoneBuffer", TYPE_BOOL, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "Whether or not there exists a separate bone buffer.", true);
		HintTable[1].init("shortDescription", "Whether or not there exists a separate bone buffer", true);
		ParamDefTable[2].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=3, longName="bufferFormats"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[3];
		ParamDef->init("bufferFormats", TYPE_ARRAY, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "This includes Semantics/Names and Vertex Format for each buffer.", true);
		HintTable[1].init("shortDescription", "Format of all buffers.", true);
		ParamDefTable[3].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */




		ParamDef->setArraySize(-1);
		static const uint8_t dynHandleIndices[2] = { 1, 0, };
		ParamDef->setDynamicHandleIndicesMap(dynHandleIndices, 2);

	}

	// Initialize DefinitionImpl node: nodeIndex=4, longName="bufferFormats[]"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[4];
		ParamDef->init("bufferFormats", TYPE_STRUCT, "BufferFormat", true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "This includes Semantics/Names and Vertex Format for each buffer.", true);
		HintTable[1].init("shortDescription", "Format of all buffers.", true);
		ParamDefTable[4].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=5, longName="bufferFormats[].name"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[5];
		ParamDef->init("name", TYPE_STRING, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "Name by which this buffer is referenced, for custom semantics. For standard semantics, VertexFormat::getSemanticName() is used", true);
		HintTable[1].init("shortDescription", "Name by which this buffer is referenced", true);
		ParamDefTable[5].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=6, longName="bufferFormats[].semantic"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[6];
		ParamDef->init("semantic", TYPE_I32, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "This buffer's semantic. If it's a custom buffer, it will be RenderVertexSemantic::CUSTOM.", true);
		HintTable[1].init("shortDescription", "This buffer's semantic.", true);
		ParamDefTable[6].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=7, longName="bufferFormats[].id"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[7];
		ParamDef->init("id", TYPE_U32, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "This buffer's id. See VertexFormat::getSemanticID and VertexFormat::getID.", true);
		HintTable[1].init("shortDescription", "This buffer's id.", true);
		ParamDefTable[7].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=8, longName="bufferFormats[].format"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[8];
		ParamDef->init("format", TYPE_U32, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "The format of this buffer. Must be one of the RenderDataFormat::Enum values.", true);
		HintTable[1].init("shortDescription", "The format of this buffer", true);
		ParamDefTable[8].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=9, longName="bufferFormats[].access"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[9];
		ParamDef->init("access", TYPE_U32, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "The access type for this buffer. Must be one of the VertexDataAccess::Enum values.", true);
		HintTable[1].init("shortDescription", "The access type for this buffer", true);
		ParamDefTable[9].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// Initialize DefinitionImpl node: nodeIndex=10, longName="bufferFormats[].serialize"
	{
		NvParameterized::DefinitionImpl* ParamDef = &ParamDefTable[10];
		ParamDef->init("serialize", TYPE_BOOL, NULL, true);

#ifdef NV_PARAMETERIZED_HIDE_DESCRIPTIONS

#else

		static HintImpl HintTable[2];
		static Hint* HintPtrTable[2] = { &HintTable[0], &HintTable[1], };
		HintTable[0].init("longDescription", "This is only needed if this buffer needs to be rendered, clothing custom buffer MAX_DISTANCE for example doesn't need it.", true);
		HintTable[1].init("shortDescription", "Serialize this buffer", true);
		ParamDefTable[10].setHints((const NvParameterized::Hint**)HintPtrTable, 2);

#endif /* NV_PARAMETERIZED_HIDE_DESCRIPTIONS */





	}

	// SetChildren for: nodeIndex=0, longName=""
	{
		static Definition* Children[3];
		Children[0] = PDEF_PTR(1);
		Children[1] = PDEF_PTR(2);
		Children[2] = PDEF_PTR(3);

		ParamDefTable[0].setChildren(Children, 3);
	}

	// SetChildren for: nodeIndex=3, longName="bufferFormats"
	{
		static Definition* Children[1];
		Children[0] = PDEF_PTR(4);

		ParamDefTable[3].setChildren(Children, 1);
	}

	// SetChildren for: nodeIndex=4, longName="bufferFormats[]"
	{
		static Definition* Children[6];
		Children[0] = PDEF_PTR(5);
		Children[1] = PDEF_PTR(6);
		Children[2] = PDEF_PTR(7);
		Children[3] = PDEF_PTR(8);
		Children[4] = PDEF_PTR(9);
		Children[5] = PDEF_PTR(10);

		ParamDefTable[4].setChildren(Children, 6);
	}

	mBuiltFlag = true;

}
void VertexFormatParameters::initStrings(void)
{
}

void VertexFormatParameters::initDynamicArrays(void)
{
	bufferFormats.buf = NULL;
	bufferFormats.isAllocated = true;
	bufferFormats.elementSize = sizeof(BufferFormat_Type);
	bufferFormats.arraySizes[0] = 0;
}

void VertexFormatParameters::initDefaults(void)
{

	freeStrings();
	freeReferences();
	freeDynamicArrays();
	winding = uint32_t(0);
	hasSeparateBoneBuffer = bool(false);

	initDynamicArrays();
	initStrings();
	initReferences();
}

void VertexFormatParameters::initReferences(void)
{
}

void VertexFormatParameters::freeDynamicArrays(void)
{
	if (bufferFormats.isAllocated && bufferFormats.buf)
	{
		mParameterizedTraits->free(bufferFormats.buf);
	}
}

void VertexFormatParameters::freeStrings(void)
{

	for (int i = 0; i < bufferFormats.arraySizes[0]; ++i)
	{
		if (bufferFormats.buf[i].name.isAllocated && bufferFormats.buf[i].name.buf)
		{
			mParameterizedTraits->strfree((char*)bufferFormats.buf[i].name.buf);
		}
	}
}

void VertexFormatParameters::freeReferences(void)
{
}

} // namespace apex
} // namespace nvidia
