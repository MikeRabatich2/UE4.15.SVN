#
# Build PhysXCharacterKinematic
#

SET(GW_DEPS_ROOT $ENV{GW_DEPS_ROOT})
FIND_PACKAGE(PxShared REQUIRED)

SET(PHYSX_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../)

SET(LL_SOURCE_DIR ${PHYSX_SOURCE_DIR}/PhysXCharacterKinematic/src)

# Use generator expressions to set config specific preprocessor definitions
SET(PHYSXCHARACTERKINEMATICS_COMPILE_DEFS 
	# Common to all configurations
	${PHYSX_LINUX_COMPILE_DEFS};PX_PHYSX_CHARACTER_EXPORTS;PX_PHYSX_CORE_EXPORTS;PX_FOUNDATION_DLL=1;
)

if(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")
	LIST(APPEND PHYSXCHARACTERKINEMATICS_COMPILE_DEFS
		${PHYSX_LINUX_DEBUG_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=DEBUG;
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "checked")
	LIST(APPEND PHYSXCHARACTERKINEMATICS_COMPILE_DEFS
		${PHYSX_LINUX_CHECKED_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=CHECKED;
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "profile")
	LIST(APPEND PHYSXCHARACTERKINEMATICS_COMPILE_DEFS
		${PHYSX_LINUX_PROFILE_COMPILE_DEFS};PX_PHYSX_DLL_NAME_POSTFIX=PROFILE;
	)
elseif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "release")
	LIST(APPEND PHYSXCHARACTERKINEMATICS_COMPILE_DEFS
		${PHYSX_LINUX_RELEASE_COMPILE_DEFS}
	)
else(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")
	MESSAGE(FATAL_ERROR "Unknown configuration ${CMAKE_BUILD_TYPE}")
endif(${CMAKE_BUILD_TYPE_LOWERCASE} STREQUAL "debug")



# include common PhysXCharacterKinematic settings
INCLUDE(../common/PhysXCharacterKinematic.cmake)

# enable -fPIC so we can link static libs with the editor
SET_TARGET_PROPERTIES(PhysXCharacterKinematic PROPERTIES POSITION_INDEPENDENT_CODE TRUE)
