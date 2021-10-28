/* SPDX-License-Identifier: MIT */
/*
 * Copyright © 2021 Intel Corporation
 */

#ifndef __I915_DRM_PRELIM_H__
#define __I915_DRM_PRELIM_H__

#include "drm.h"

/*
 * Modifications to structs/values defined here are subject to
 * backwards-compatibility constraints.
 *
 * Internal/downstream declarations must be added here, not to
 * i915_drm.h. The values in i915_drm_prelim.h must also be kept
 * synchronized with values in i915_drm.h.
 */

struct prelim_i915_tiling {
#define PRELIM_I915_TILING_F	3
#define PRELIM_I915_TILING_LAST	PRELIM_I915_TILING_F
#define I915_TILING_F		PRELIM_I915_TILING_F
#define I915_TILING_LAST	PRELIM_I915_TILING_LAST
};

struct prelim_i915_uevent {
/*
 * PRELIM_I915_RESET_FAILED_UEVENT - Event is generated when engine or GPU
 *	resets fail and also when GPU is declared wedged. The value
 *	supplied with the event is always 1. Event is also generated when
 *	resets are disabled by module parameter and an attempt to reset
 *	either engine or GPU is made.
 */
#define PRELIM_I915_RESET_FAILED_UEVENT	"RESET_FAILED"
#define I915_RESET_FAILED_UEVENT	"RESET_FAILED"

/*
 * PRELIM_I915_MEMORY_HEALTH_UEVENT - Generated when driver receives a memory
 *	degradation error from the GPU FW. The event serves as notification to
 *	an Admin to reboot the system as soon as possible, due to the fact that
 *	device is no longer RUNTIME recoverable again. This event will always
 *	have a value of 1, which indicates that uncorrectable error has been
 *	detected, and that runtime memory sparing is not feasible without system
 *	reboot - for recovery of failed BANK.
 */
#define PRELIM_I915_MEMORY_HEALTH_UEVENT	"MEMORY_HEALTH"
#define I915_MEMORY_HEALTH_UEVENT	"MEMORY_HEALTH"
};

/*
 * Top 8 bits of every non-engine counter are GT id.
 * FIXME: __PRELIM_I915_PMU_GT_SHIFT will be changed to 56
 */
#define __PRELIM_I915_PMU_GT_SHIFT (60)
#define __I915_PMU_GT_SHIFT (60)

#define ___PRELIM_I915_PMU_OTHER(gt, x) \
	(((__u64)__I915_PMU_ENGINE(0xff, 0xff, 0xf) + 1 + (x)) | \
	((__u64)(gt) << __PRELIM_I915_PMU_GT_SHIFT))
#define ___I915_PMU_OTHER ___PRELIM_I915_PMU_OTHER

#define __I915_PMU_OTHER(x) ___PRELIM_I915_PMU_OTHER(0, x)

#define __PRELIM_I915_PMU_ACTUAL_FREQUENCY(gt)		___PRELIM_I915_PMU_OTHER(gt, 0)
#define __PRELIM_I915_PMU_REQUESTED_FREQUENCY(gt)	___PRELIM_I915_PMU_OTHER(gt, 1)
#define __PRELIM_I915_PMU_INTERRUPTS(gt)		___PRELIM_I915_PMU_OTHER(gt, 2)
#define __PRELIM_I915_PMU_RC6_RESIDENCY(gt)		___PRELIM_I915_PMU_OTHER(gt, 3)
#define __PRELIM_I915_PMU_SOFTWARE_GT_AWAKE_TIME(gt)	___PRELIM_I915_PMU_OTHER(gt, 4)
#define __PRELIM_I915_PMU_ENGINE_RESET_COUNT(gt)	___PRELIM_I915_PMU_OTHER(gt, 5)
#define __PRELIM_I915_PMU_EU_ATTENTION_COUNT(gt)	___PRELIM_I915_PMU_OTHER(gt, 6)
#define __PRELIM_I915_PMU_RENDER_GROUP_BUSY(gt)		___PRELIM_I915_PMU_OTHER(gt, 7)
#define __PRELIM_I915_PMU_COPY_GROUP_BUSY(gt)		___PRELIM_I915_PMU_OTHER(gt, 8)
#define __PRELIM_I915_PMU_MEDIA_GROUP_BUSY(gt)		___PRELIM_I915_PMU_OTHER(gt, 9)
#define __PRELIM_I915_PMU_ANY_ENGINE_GROUP_BUSY(gt)	___PRELIM_I915_PMU_OTHER(gt, 10)

#define __I915_PMU_ACTUAL_FREQUENCY		__PRELIM_I915_PMU_ACTUAL_FREQUENCY
#define __I915_PMU_REQUESTED_FREQUENCY		__PRELIM_I915_PMU_REQUESTED_FREQUENCY
#define __I915_PMU_INTERRUPTS			__PRELIM_I915_PMU_INTERRUPTS
#define __I915_PMU_RC6_RESIDENCY		__PRELIM_I915_PMU_RC6_RESIDENCY
#define __I915_PMU_SOFTWARE_GT_AWAKE_TIME	__PRELIM_I915_PMU_SOFTWARE_GT_AWAKE_TIME
#define __I915_PMU_ENGINE_RESET_COUNT		__PRELIM_I915_PMU_ENGINE_RESET_COUNT
#define __I915_PMU_EU_ATTENTION_COUNT		__PRELIM_I915_PMU_EU_ATTENTION_COUNT

#define __PRELIM_I915_PMU_HW_ERROR_EVENT_ID_OFFSET	(__I915_PMU_OTHER(0) + 1000)
#define __I915_PMU_HW_ERROR_EVENT_ID_OFFSET	__PRELIM_I915_PMU_HW_ERROR_EVENT_ID_OFFSET

#define PRELIM_I915_PMU_ENGINE_RESET_COUNT	__PRELIM_I915_PMU_ENGINE_RESET_COUNT(0)
#define I915_PMU_ENGINE_RESET_COUNT		PRELIM_I915_PMU_ENGINE_RESET_COUNT
#define PRELIM_I915_PMU_EU_ATTENTION_COUNT	__PRELIM_I915_PMU_EU_ATTENTION_COUNT(0)
#define I915_PMU_EU_ATTENTION_COUNT		PRELIM_I915_PMU_EU_ATTENTION_COUNT
#define PRELIM_I915_PMU_RENDER_GROUP_BUSY              __PRELIM_I915_PMU_RENDER_GROUP_BUSY(0)
#define PRELIM_I915_PMU_COPY_GROUP_BUSY                __PRELIM_I915_PMU_COPY_GROUP_BUSY(0)
#define PRELIM_I915_PMU_MEDIA_GROUP_BUSY               __PRELIM_I915_PMU_MEDIA_GROUP_BUSY(0)
#define PRELIM_I915_PMU_ANY_ENGINE_GROUP_BUSY          __PRELIM_I915_PMU_ANY_ENGINE_GROUP_BUSY(0)

/*
 * HW error counters.
 */
#define PRELIM_I915_PMU_GT_ERROR_CORRECTABLE_L3_SNG		(0)
#define PRELIM_I915_PMU_GT_ERROR_CORRECTABLE_GUC		(1)
#define PRELIM_I915_PMU_GT_ERROR_CORRECTABLE_SAMPLER		(2)
#define PRELIM_I915_PMU_GT_ERROR_CORRECTABLE_SLM		(3)
#define PRELIM_I915_PMU_GT_ERROR_CORRECTABLE_EU_IC		(4)
#define PRELIM_I915_PMU_GT_ERROR_CORRECTABLE_EU_GRF		(5)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_ARR_BIST			(6)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_L3_DOUB			(7)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_L3_ECC_CHK		(8)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_GUC			(9)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_IDI_PAR			(10)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_SQIDI			(11)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_SAMPLER			(12)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_SLM			(13)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_EU_IC			(14)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_EU_GRF			(15)
#define I915_PMU_GT_ERROR_CORRECTABLE_L3_SNG		(0)
#define I915_PMU_GT_ERROR_CORRECTABLE_GUC		(1)
#define I915_PMU_GT_ERROR_CORRECTABLE_SAMPLER		(2)
#define I915_PMU_GT_ERROR_CORRECTABLE_SLM		(3)
#define I915_PMU_GT_ERROR_CORRECTABLE_EU_IC		(4)
#define I915_PMU_GT_ERROR_CORRECTABLE_EU_GRF		(5)
#define I915_PMU_GT_ERROR_FATAL_ARR_BIST		(6)
#define I915_PMU_GT_ERROR_FATAL_L3_DOUB			(7)
#define I915_PMU_GT_ERROR_FATAL_L3_ECC_CHK		(8)
#define I915_PMU_GT_ERROR_FATAL_GUC			(9)
#define I915_PMU_GT_ERROR_FATAL_IDI_PAR			(10)
#define I915_PMU_GT_ERROR_FATAL_SQIDI			(11)
#define I915_PMU_GT_ERROR_FATAL_SAMPLER			(12)
#define I915_PMU_GT_ERROR_FATAL_SLM			(13)
#define I915_PMU_GT_ERROR_FATAL_EU_IC			(14)
#define I915_PMU_GT_ERROR_FATAL_EU_GRF			(15)
#define PRELIM_I915_PMU_SGUNIT_ERROR_CORRECTABLE		(16)
#define PRELIM_I915_PMU_SGUNIT_ERROR_NONFATAL			(17)
#define PRELIM_I915_PMU_SGUNIT_ERROR_FATAL			(18)
#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_PSF_CSC_0		(19)
#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_PSF_CSC_1		(20)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_PSF_CSC_0		(21)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_PSF_CSC_1		(22)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_PSF_CSC_2		(23)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_PSF_CSC_0		(24)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_PSF_CSC_1		(25)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_PSF_CSC_2		(26)
#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_PUNIT		(27)
#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_MDFI_EAST		(28)
#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_MDFI_WEST		(29)
#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_MDFI_SOUTH	(30)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_PUNIT		(31)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_MDFI_EAST		(32)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_MDFI_WEST		(33)
#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_MDFI_SOUTH		(34)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_PUNIT			(35)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_MDFI_EAST		(36)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_MDFI_WEST		(37)
#define PRELIM_I915_PMU_SOC_ERROR_FATAL_MDFI_SOUTH		(38)
#define I915_PMU_SGUNIT_ERROR_CORRECTABLE		(16)
#define I915_PMU_SGUNIT_ERROR_NONFATAL			(17)
#define I915_PMU_SGUNIT_ERROR_FATAL			(18)
#define I915_PMU_SOC_ERROR_CORRECTABLE_PSF_CSC_0	(19)
#define I915_PMU_SOC_ERROR_CORRECTABLE_PSF_CSC_1	(20)
#define I915_PMU_SOC_ERROR_NONFATAL_PSF_CSC_0		(21)
#define I915_PMU_SOC_ERROR_NONFATAL_PSF_CSC_1		(22)
#define I915_PMU_SOC_ERROR_NONFATAL_PSF_CSC_2		(23)
#define I915_PMU_SOC_ERROR_FATAL_PSF_CSC_0		(24)
#define I915_PMU_SOC_ERROR_FATAL_PSF_CSC_1		(25)
#define I915_PMU_SOC_ERROR_FATAL_PSF_CSC_2		(26)
#define I915_PMU_SOC_ERROR_CORRECTABLE_PUNIT		(27)
#define I915_PMU_SOC_ERROR_CORRECTABLE_MDFI_EAST	(28)
#define I915_PMU_SOC_ERROR_CORRECTABLE_MDFI_WEST	(29)
#define I915_PMU_SOC_ERROR_CORRECTABLE_MDFI_SOUTH	(30)
#define I915_PMU_SOC_ERROR_NONFATAL_PUNIT		(31)
#define I915_PMU_SOC_ERROR_NONFATAL_MDFI_EAST		(32)
#define I915_PMU_SOC_ERROR_NONFATAL_MDFI_WEST		(33)
#define I915_PMU_SOC_ERROR_NONFATAL_MDFI_SOUTH		(34)
#define I915_PMU_SOC_ERROR_FATAL_PUNIT			(35)
#define I915_PMU_SOC_ERROR_FATAL_MDFI_EAST		(36)
#define I915_PMU_SOC_ERROR_FATAL_MDFI_WEST		(37)
#define I915_PMU_SOC_ERROR_FATAL_MDFI_SOUTH		(38)

#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_FBR(ss, n) \
	(PRELIM_I915_PMU_SOC_ERROR_FATAL_MDFI_SOUTH + 0x1 + (ss) * 0x4 + (n))

#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_FBR(ss, n) \
	(PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_FBR(1, 5) + (ss) * 0x4 + (n))

#define PRELIM_I915_PMU_SOC_ERROR_FATAL_FBR(ss, n) \
	(PRELIM_I915_PMU_SOC_ERROR_NONFATAL_FBR(1, 5) + (ss) * 0x4 + (n))

#define PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_HBM(ss, n)\
	(PRELIM_I915_PMU_SOC_ERROR_FATAL_FBR(1, 5) + (ss) * 0x10 + (n))

#define PRELIM_I915_PMU_SOC_ERROR_NONFATAL_HBM(ss, n)\
	(PRELIM_I915_PMU_SOC_ERROR_CORRECTABLE_HBM(1, 16) + (ss) * 0x10 + (n))

#define PRELIM_I915_PMU_SOC_ERROR_FATAL_HBM(ss, n)\
	(PRELIM_I915_PMU_SOC_ERROR_NONFATAL_HBM(1, 16) + (ss) * 0x10 + (n))

#define I915_PMU_SOC_ERROR_CORRECTABLE_FBR(ss, n)			\
	(I915_PMU_SOC_ERROR_FATAL_MDFI_SOUTH + 0x1 + (ss) * 0x4 + (n))

#define I915_PMU_SOC_ERROR_NONFATAL_FBR(ss, n) \
	(I915_PMU_SOC_ERROR_CORRECTABLE_FBR(1, 5) + (ss) * 0x4 + (n))

#define I915_PMU_SOC_ERROR_FATAL_FBR(ss, n) \
	(I915_PMU_SOC_ERROR_NONFATAL_FBR(1, 5) + (ss) * 0x4 + (n))

#define I915_PMU_SOC_ERROR_CORRECTABLE_HBM(ss, n)\
	(I915_PMU_SOC_ERROR_FATAL_FBR(1, 5) + (ss) * 0x10 + (n))

#define I915_PMU_SOC_ERROR_NONFATAL_HBM(ss, n)\
	(I915_PMU_SOC_ERROR_CORRECTABLE_HBM(1, 16) + (ss) * 0x10 + (n))

#define I915_PMU_SOC_ERROR_FATAL_HBM(ss, n)\
	(I915_PMU_SOC_ERROR_NONFATAL_HBM(1, 16) + (ss) * 0x10 + (n))

/* 161 is the last ID used by SOC errors */
#define PRELIM_I915_PMU_GT_ERROR_FATAL_FPU		(162)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_TLB		(163)
#define PRELIM_I915_PMU_GT_ERROR_FATAL_L3_FABRIC	(164)

#define PRELIM_I915_PMU_HW_ERROR(gt, id) \
	((__PRELIM_I915_PMU_HW_ERROR_EVENT_ID_OFFSET + (id)) | \
	((__u64)(gt) << __PRELIM_I915_PMU_GT_SHIFT))
#define I915_PMU_HW_ERROR	PRELIM_I915_PMU_HW_ERROR

/* Per GT driver error counters */
#define __PRELIM_I915_PMU_GT_DRIVER_ERROR_EVENT_ID_OFFSET (__I915_PMU_OTHER(0) + 2000)
#define __I915_PMU_GT_DRIVER_ERROR_EVENT_ID_OFFSET (__I915_PMU_OTHER(0) + 2000)

#define PRELIM_I915_PMU_GT_DRIVER_ERROR_GGTT			(0)
#define PRELIM_I915_PMU_GT_DRIVER_ERROR_ENGINE_OTHER		(1)
#define PRELIM_I915_PMU_GT_DRIVER_ERROR_GUC_COMMUNICATION	(2)
#define PRELIM_I915_PMU_GT_DRIVER_ERROR_RPS			(3)
#define PRELIM_I915_PMU_GT_DRIVER_ERROR_GT_OTHER		(4)
#define PRELIM_I915_PMU_GT_DRIVER_ERROR_INTERRUPT		(5)
#define I915_PMU_GT_DRIVER_ERROR_GGTT			(0)
#define I915_PMU_GT_DRIVER_ERROR_ENGINE_OTHER		(1)
#define I915_PMU_GT_DRIVER_ERROR_GUC_COMMUNICATION	(2)
#define I915_PMU_GT_DRIVER_ERROR_RPS			(3)
#define I915_PMU_GT_DRIVER_ERROR_GT_OTHER		(4)
#define I915_PMU_GT_DRIVER_ERROR_INTERRUPT		(5)

#define PRELIM_I915_PMU_GT_DRIVER_ERROR(gt, id) \
	((__PRELIM_I915_PMU_GT_DRIVER_ERROR_EVENT_ID_OFFSET + (id)) | \
	 ((__u64)(gt) << __PRELIM_I915_PMU_GT_SHIFT))
#define I915_PMU_GT_DRIVER_ERROR PRELIM_I915_PMU_GT_DRIVER_ERROR

/* Global driver error counters */
#define __PRELIM_I915_PMU_DRIVER_ERROR_EVENT_ID_OFFSET (__I915_PMU_OTHER(0) + 3000)
#define __I915_PMU_DRIVER_ERROR_EVENT_ID_OFFSET (__I915_PMU_OTHER(0) + 3000)

#define PRELIM_I915_PMU_DRIVER_ERROR_OBJECT_MIGRATION	(0)
#define I915_PMU_DRIVER_ERROR_OBJECT_MIGRATION	(0)

#define PRELIM_I915_PMU_DRIVER_ERROR(id)	(__PRELIM_I915_PMU_DRIVER_ERROR_EVENT_ID_OFFSET + (id))
#define I915_PMU_DRIVER_ERROR(id)	(__I915_PMU_DRIVER_ERROR_EVENT_ID_OFFSET + (id))

struct prelim_i915_user_extension {
#define PRELIM_I915_USER_EXT		(1 << 16)
#define PRELIM_I915_USER_EXT_MASK(x)	(x & 0xffff)
};

/* PRELIM ioctl's */
#define DRM_I915_GEM_VM_BIND		0x3c
#define DRM_I915_GEM_VM_UNBIND		0x3d
#define DRM_I915_GEM_VM_ADVISE		0x3e
#define DRM_I915_GEM_WAIT_USER_FENCE	0x3f
#define DRM_I915_GEM_VM_PREFETCH	0x40
#define DRM_I915_UUID_REGISTER		0x41
#define DRM_I915_UUID_UNREGISTER	0x42
#define DRM_I915_DEBUGGER_OPEN		0x43
#define DRM_I915_GEM_CLOS_RESERVE	0x44
#define DRM_I915_GEM_CLOS_FREE		0x45
#define DRM_I915_GEM_CACHE_RESERVE	0x46
#define DRM_I915_GEM_VM_GETPARAM        DRM_I915_GEM_CONTEXT_GETPARAM
#define DRM_I915_GEM_VM_SETPARAM        DRM_I915_GEM_CONTEXT_SETPARAM

/* PRELIM ioctl numbers go down from 0x5f */
#define PRELIM_DRM_I915_AGAMA_IOCTL_VERSION	0x5f
/* 0x5e is free, please use if needed */
#define PRELIM_DRM_I915_GEM_VM_BIND		0x5d
#define PRELIM_DRM_I915_GEM_VM_UNBIND		0x5c
#define PRELIM_DRM_I915_GEM_VM_ADVISE		0x5b
#define PRELIM_DRM_I915_GEM_WAIT_USER_FENCE	0x5a
#define PRELIM_DRM_I915_GEM_VM_PREFETCH		0x59
#define PRELIM_DRM_I915_UUID_REGISTER		0x58
#define PRELIM_DRM_I915_UUID_UNREGISTER		0x57
#define PRELIM_DRM_I915_DEBUGGER_OPEN		0x56
#define PRELIM_DRM_I915_GEM_CLOS_RESERVE	0x55
#define PRELIM_DRM_I915_GEM_CLOS_FREE		0x54
#define PRELIM_DRM_I915_GEM_CACHE_RESERVE	0x53
#define PRELIM_DRM_I915_GEM_VM_GETPARAM		DRM_I915_GEM_CONTEXT_GETPARAM
#define PRELIM_DRM_I915_GEM_VM_SETPARAM		DRM_I915_GEM_CONTEXT_SETPARAM

#define DRM_IOCTL_I915_GEM_CREATE_EXT		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CREATE, struct prelim_drm_i915_gem_create_ext)
#define DRM_IOCTL_I915_GEM_VM_BIND		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_VM_BIND, struct prelim_drm_i915_gem_vm_bind)
#define DRM_IOCTL_I915_GEM_VM_UNBIND		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_VM_UNBIND, struct prelim_drm_i915_gem_vm_bind)
#define DRM_IOCTL_I915_GEM_VM_ADVISE		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_VM_ADVISE, struct prelim_drm_i915_gem_vm_advise)
#define DRM_IOCTL_I915_GEM_WAIT_USER_FENCE	DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_WAIT_USER_FENCE, struct prelim_drm_i915_gem_wait_user_fence)
#define DRM_IOCTL_I915_GEM_VM_PREFETCH		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_VM_PREFETCH, struct prelim_drm_i915_gem_vm_prefetch)
#define DRM_IOCTL_I915_UUID_REGISTER		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_UUID_REGISTER, struct prelim_drm_i915_uuid_control)
#define DRM_IOCTL_I915_UUID_UNREGISTER		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_UUID_UNREGISTER, struct prelim_drm_i915_uuid_control)
#define DRM_IOCTL_I915_DEBUGGER_OPEN		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_DEBUGGER_OPEN, struct prelim_drm_i915_debugger_open_param)
#define DRM_IOCTL_I915_GEM_CLOS_RESERVE		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CLOS_RESERVE, struct prelim_drm_i915_gem_clos_reserve)
#define DRM_IOCTL_I915_GEM_CLOS_FREE		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CLOS_FREE, struct prelim_drm_i915_gem_clos_free)
#define DRM_IOCTL_I915_GEM_CACHE_RESERVE	DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CACHE_RESERVE, struct prelim_drm_i915_gem_cache_reserve)
#define DRM_IOCTL_I915_GEM_VM_GETPARAM		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_VM_GETPARAM, struct prelim_drm_i915_gem_vm_param)
#define DRM_IOCTL_I915_GEM_VM_SETPARAM		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_VM_SETPARAM, struct prelim_drm_i915_gem_vm_param)

#define PRELIM_DRM_IOCTL_I915_GEM_CREATE_EXT		DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GEM_CREATE, struct prelim_drm_i915_gem_create_ext)
#define PRELIM_DRM_IOCTL_I915_GEM_VM_BIND		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_BIND, struct prelim_drm_i915_gem_vm_bind)
#define PRELIM_DRM_IOCTL_I915_GEM_VM_UNBIND		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_UNBIND, struct prelim_drm_i915_gem_vm_bind)
#define PRELIM_DRM_IOCTL_I915_GEM_VM_ADVISE		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_ADVISE, struct prelim_drm_i915_gem_vm_advise)
#define PRELIM_DRM_IOCTL_I915_GEM_WAIT_USER_FENCE	DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_WAIT_USER_FENCE, struct prelim_drm_i915_gem_wait_user_fence)
#define PRELIM_DRM_IOCTL_I915_GEM_VM_PREFETCH		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_PREFETCH, struct prelim_drm_i915_gem_vm_prefetch)
#define PRELIM_DRM_IOCTL_I915_UUID_REGISTER		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_UUID_REGISTER, struct prelim_drm_i915_uuid_control)
#define PRELIM_DRM_IOCTL_I915_UUID_UNREGISTER		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_UUID_UNREGISTER, struct prelim_drm_i915_uuid_control)
#define PRELIM_DRM_IOCTL_I915_DEBUGGER_OPEN		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_DEBUGGER_OPEN, struct prelim_drm_i915_debugger_open_param)
#define PRELIM_DRM_IOCTL_I915_GEM_CLOS_RESERVE		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_CLOS_RESERVE, struct prelim_drm_i915_gem_clos_reserve)
#define PRELIM_DRM_IOCTL_I915_GEM_CLOS_FREE		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_CLOS_FREE, struct prelim_drm_i915_gem_clos_free)
#define PRELIM_DRM_IOCTL_I915_GEM_CACHE_RESERVE		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_CACHE_RESERVE, struct prelim_drm_i915_gem_cache_reserve)
#define PRELIM_DRM_IOCTL_I915_GEM_VM_GETPARAM		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_GETPARAM, struct prelim_drm_i915_gem_vm_param)
#define PRELIM_DRM_IOCTL_I915_GEM_VM_SETPARAM		DRM_IOWR(DRM_COMMAND_BASE + PRELIM_DRM_I915_GEM_VM_SETPARAM, struct prelim_drm_i915_gem_vm_param)
/* End PRELIM ioctl's */

/* getparam */
#define PRELIM_I915_PARAM               (1 << 16)
/*
 * Querying I915_PARAM_EXECBUF2_MAX_ENGINE will return the number of context
 * map engines addressable via the low bits of execbuf2 flags, or in the
 * cases where the parameter is not supported (-EINVAL), legacy maximum of
 * 64 engines should be assumed.
 */
#define PRELIM_I915_PARAM_EXECBUF2_MAX_ENGINE	(PRELIM_I915_PARAM | 1)
#define I915_PARAM_EXECBUF2_MAX_ENGINE	55

/* Total local memory in bytes */
#define PRELIM_I915_PARAM_LMEM_TOTAL_BYTES	(PRELIM_I915_PARAM | 2)
#define I915_PARAM_LMEM_TOTAL_BYTES	56

/* Available local memory in bytes */
#define PRELIM_I915_PARAM_LMEM_AVAIL_BYTES	(PRELIM_I915_PARAM | 3)
#define I915_PARAM_LMEM_AVAIL_BYTES	57

/* Shared Virtual Memory (SVM) support capability */
#define PRELIM_I915_PARAM_HAS_SVM		(PRELIM_I915_PARAM | 4)
#define I915_PARAM_HAS_SVM		58

/*
 * Frequency of the timestamps in OA reports. This used to be the same as the CS
 * timestamp frequency, but differs on some platforms.
 */
#define PRELIM_I915_PARAM_OA_TIMESTAMP_FREQUENCY	(PRELIM_I915_PARAM | 5)

/* VM_BIND feature availability */
#define PRELIM_I915_PARAM_HAS_VM_BIND	(PRELIM_I915_PARAM | 6)
#define I915_PARAM_HAS_VM_BIND		59
/* End getparam */

struct prelim_drm_i915_gem_create_ext {

	/**
	 * Requested size for the object.
	 *
	 * The (page-aligned) allocated size for the object will be returned.
	 */
	__u64 size;
	/**
	 * Returned handle for the object.
	 *
	 * Object handles are nonzero.
	 */
	__u32 handle;
	__u32 pad;
#define PRELIM_I915_GEM_CREATE_EXT_SETPARAM	(PRELIM_I915_USER_EXT | 1)
#define PRELIM_I915_GEM_CREATE_EXT_FLAGS_UNKNOWN \
	(~PRELIM_I915_GEM_CREATE_EXT_SETPARAM)
#define I915_GEM_CREATE_EXT_SETPARAM (1u << 0)
#define I915_GEM_CREATE_EXT_FLAGS_UNKNOWN \
	(-(I915_GEM_CREATE_EXT_SETPARAM << 1))
	__u64 extensions;
};
#define drm_i915_gem_create_ext prelim_drm_i915_gem_create_ext

struct prelim_drm_i915_gem_object_param {
	/* Object handle (0 for I915_GEM_CREATE_EXT_SETPARAM) */
	__u32 handle;

	/* Data pointer size */
	__u32 size;

/*
 * PRELIM_I915_OBJECT_PARAM:
 *
 * Select object namespace for the param.
 */
#define PRELIM_I915_OBJECT_PARAM  (1ull << 48)
#define I915_OBJECT_PARAM  (1ull<<32)

/*
 * PRELIM_I915_PARAM_MEMORY_REGIONS:
 *
 * Set the data pointer with the desired set of placements in priority
 * order(each entry must be unique and supported by the device), as an array of
 * prelim_drm_i915_gem_memory_class_instance, or an equivalent layout of class:instance
 * pair encodings. See PRELIM_DRM_I915_QUERY_MEMORY_REGIONS for how to query the
 * supported regions.
 *
 * Note that this requires the PRELIM_I915_OBJECT_PARAM namespace:
 *	.param = PRELIM_I915_OBJECT_PARAM | PRELIM_I915_PARAM_MEMORY_REGIONS
 */
#define PRELIM_I915_PARAM_MEMORY_REGIONS ((1 << 16) | 0x1)
#define I915_PARAM_MEMORY_REGIONS 0x1
	__u64 param;

	/* Data value or pointer */
	__u64 data;
};
#define drm_i915_gem_object_param prelim_drm_i915_gem_object_param

struct prelim_drm_i915_gem_create_ext_setparam {
	struct i915_user_extension base;
	struct prelim_drm_i915_gem_object_param param;
};
#define drm_i915_gem_create_ext_setparam prelim_drm_i915_gem_create_ext_setparam

#define PRELIM_PERF_VERSION	(1000)

/**
 * Returns OA buffer properties to be used with mmap.
 *
 * This ioctl is available in perf revision 1000.
 */
#define PRELIM_I915_PERF_IOCTL_GET_OA_BUFFER_INFO _IOWR('i', 0x80, struct prelim_drm_i915_perf_oa_buffer_info)
#define I915_PERF_IOCTL_GET_OA_BUFFER_INFO _IOWR('i', 0x3, struct prelim_drm_i915_perf_oa_buffer_info)

/**
 * OA buffer size and offset.
 *
 * OA output buffer
 *   type: 0
 *   flags: mbz
 *
 *   After querying the info, pass (size,offset) to mmap(),
 *
 *   mmap(0, info.size, PROT_READ, MAP_PRIVATE, perf_fd, info.offset).
 *
 *   Note that only a private (not shared between processes, or across fork())
 *   read-only mmapping is allowed.
 *
 *   Userspace must treat the incoming data as tainted, but it conforms to the OA
 *   format as specified by user config. The buffer provides reports that have
 *   OA counters - A, B and C.
 */
struct prelim_drm_i915_perf_oa_buffer_info {
	__u32 type;   /* in */
	__u32 flags;  /* in */
	__u64 size;   /* out */
	__u64 offset; /* out */
	__u64 rsvd;   /* mbz */
};
#define drm_i915_perf_oa_buffer_info prelim_drm_i915_perf_oa_buffer_info

enum prelim_drm_i915_eu_stall_property_id {
	/**
	 * This field specifies the Per DSS Memory Buffer Size.
	 * Valid values are 128 KB, 256 KB, and 512 KB.
	 */
	PRELIM_DRM_I915_EU_STALL_PROP_BUF_SZ = 1001,

	/**
	 * This field specifies the sampling rate per tile
	 * in multiples of 251 cycles. Valid values are 1 to 7.
	 * If the value is 1, sampling interval is 251 cycles.
	 * If the value is 7, sampling interval is 7 x 251 cycles.
	 */
	PRELIM_DRM_I915_EU_STALL_PROP_SAMPLE_RATE,

	/**
	 * This field specifies the EU stall data poll period
	 * in nanoseconds. Minimum allowed value is 100 ms.
	 * A default value is used by the driver if this field
	 * is not specified.
	 */
	PRELIM_DRM_I915_EU_STALL_PROP_POLL_PERIOD,

	PRELIM_DRM_I915_EU_STALL_PROP_MAX
};

/*
 * Info that the driver adds to each entry in the EU stall counters data.
 */
struct prelim_drm_i915_stall_cntr_info {
	__u16 subslice;
	__u16 flags;
/* EU stall data line dropped due to memory buffer being full */
#define PRELIM_I915_EUSTALL_FLAG_OVERFLOW_DROP	(1 << 8)
};

struct prelim_drm_i915_perf_open_param {
	/* PRELIM flags */
#define PRELIM_I915_PERF_FLAG_FD_EU_STALL	(1 << 16)
};

struct prelim_drm_i915_gem_memory_class_instance {
	__u16 memory_class; /* see enum prelim_drm_i915_gem_memory_class */
	__u16 memory_instance;
};
#define drm_i915_gem_memory_class_instance prelim_drm_i915_gem_memory_class_instance

struct prelim_drm_i915_query_item {
#define PRELIM_DRM_I915_QUERY			(1 << 16)
#define PRELIM_DRM_I915_QUERY_MASK(x)		(x & 0xffff)
/* Keep lower 16 bits same as previous values */
#define PRELIM_DRM_I915_QUERY_MEMORY_REGIONS	(PRELIM_DRM_I915_QUERY | 4)
#define DRM_I915_QUERY_MEMORY_REGIONS   4
#define PRELIM_DRM_I915_QUERY_DISTANCE_INFO	(PRELIM_DRM_I915_QUERY | 5)
#define DRM_I915_QUERY_DISTANCE_INFO	5
	/**
	 * Query HWConfig Table: Copies a device information table to the
	 * query's item.data_ptr directly if the allocated length is big enough
	 * For details about table format and content see intel_hwconfig_types.h
	 */
#define PRELIM_DRM_I915_QUERY_HWCONFIG_TABLE	(PRELIM_DRM_I915_QUERY | 6)
#define DRM_I915_QUERY_HWCONFIG_TABLE	6
#define PRELIM_DRM_I915_QUERY_GEOMETRY_SLICES	(PRELIM_DRM_I915_QUERY | 7)
#define PRELIM_DRM_I915_QUERY_COMPUTE_SLICES	(PRELIM_DRM_I915_QUERY | 8)
	/**
	 * Query Command Streamer timestamp register.
	 */
#define PRELIM_DRM_I915_QUERY_CS_CYCLES		(PRELIM_DRM_I915_QUERY | 9)
#define DRM_I915_QUERY_CS_CYCLES	9

#define PRELIM_DRM_I915_QUERY_FABRIC_INFO	(PRELIM_DRM_I915_QUERY | 11)
#define DRM_I915_QUERY_FABRIC_INFO	11

#define PRELIM_DRM_I915_QUERY_ENGINE_INFO	(PRELIM_DRM_I915_QUERY | 13)
#define PRELIM_DRM_I915_QUERY_L3_BANK_COUNT	(PRELIM_DRM_I915_QUERY | 14)
};

/*
 * Number of BB in execbuf2 IOCTL - 1, used to submit more than BB in a single
 * execbuf2 IOCTL.
 *
 * Return -EINVAL if more than 1 BB (value 0) is specified if
 * PRELIM_I915_CONTEXT_ENGINES_EXT_PARALLEL_SUBMIT hasn't been called on the gem
 * context first. Also returns -EINVAL if gem context has been setup with
 * I915_PARALLEL_BB_PREEMPT_BOUNDARY and the number BBs not equal to the total
 * number hardware contexts in the gem context.
 */
#define I915_EXEC_NUMBER_BB_LSB		(21)
#define I915_EXEC_NUMBER_BB_MASK	(0x3f << I915_EXEC_NUMBER_BB_LSB)
#define I915_EXEC_NUMBER_BB_MSB		(26)
#define I915_EXEC_NUMBER_BB_MASK_MSB	(1 << I915_EXEC_NUMBER_BB_MSB)
#define PRELIM_I915_EXEC_NUMBER_BB_LSB		(48)
#define PRELIM_I915_EXEC_NUMBER_BB_MASK		(0x3full << PRELIM_I915_EXEC_NUMBER_BB_LSB)
#define PRELIM_I915_EXEC_NUMBER_BB_MSB		(54)
#define PRELIM_I915_EXEC_NUMBER_BB_MASK_MSB	(1ull << PRELIM_I915_EXEC_NUMBER_BB_MSB)

/*
 * In XEHPSDV total number of engines can be more than the maximum supported
 * engines by I915_EXEC_RING_MASK.
 * PRELIM_I915_EXEC_ENGINE_MASK expands the total number of engines from 64 to 256.
 *
 * To use PRELIM_I915_EXEC_ENGINE_MASK, userspace needs to query
 * I915_PARAM_EXECBUF2_MAX_ENGINE. On getting valid value, userspace needs
 * to set PRELIM_I915_EXEC_ENGINE_MASK_SELECT to enable PRELIM_I915_EXEC_ENGINE_MASK.
 *
 * Bitfield associated with legacy I915_EXEC_CONSTANTS_MASK which was
 * restricted previously, will be utilized by PRELIM_I915_EXEC_ENGINE_MASK.
 *
 * PRELIM_I915_EXEC_ENGINE_MASK only applies to contexts with engine map set up.
 */
#define PRELIM_I915_EXEC_ENGINE_MASK    (0xff)
#define PRELIM_I915_EXEC_ENGINE_MASK_SELECT (1ull << 55)
#define I915_EXEC_ENGINE_MASK    (0xff)
#define I915_EXEC_ENGINE_MASK_SELECT (1 << 27)

#define __I915_EXEC_UNKNOWN_FLAGS (~(GENMASK_ULL(55, 48) | GENMASK_ULL(27, 0)))

/*
 * Indicates the 2k user priority levels are statically mapped into 3 buckets as
 * follows:
 *
 * -1k to -1	Low priority
 * 0		Normal priority
 * 1 to 1k	Highest priority
 */
#define   PRELIM_I915_SCHEDULER_CAP_STATIC_PRIORITY_MAP	(1ul << 31)
#define   I915_SCHEDULER_CAP_STATIC_PRIORITY_MAP	(1ul << 5)

enum prelim_drm_i915_gem_engine_class {
#define	PRELIM_I915_ENGINE_CLASS		(1 << 8)
#define	PRELIM_I915_ENGINE_CLASS_MASK(x)	(x & 0xff)

	PRELIM_I915_ENGINE_CLASS_COMPUTE = 4,
};

/*
 * prelim_i915_context_engines_parallel_submit:
 *
 * Setup a gem context to allow multiple BBs to be submitted in a single execbuf
 * IOCTL. Those BBs will then be scheduled to run on the GPU in parallel.
 *
 * All hardware contexts in the engine set are configured for parallel
 * submission (i.e. once this gem context is configured for parallel submission,
 * all the hardware contexts, regardless if a BB is available on each individual
 * context, will be submitted to the GPU in parallel). A user can submit BBs to
 * subset (or superset) of the hardware contexts, in a single execbuf IOCTL, but
 * it is not recommended as it may reserve physical engines with nothing to run
 * on them. Highly recommended to configure the gem context with N hardware
 * contexts then always submit N BBs in a single IOCTL.
 *
 * Their are two currently defined ways to control the placement of the
 * hardware contexts on physical engines: default behavior (no flags) and
 * PRELIM_I915_PARALLEL_IMPLICT_BONDS (a flag). More flags may be added the in the
 * future as new hardware / use cases arise. Details of how to use this
 * interface below above the flags.
 *
 * Returns -EINVAL if hardware context placement configuration invalid or if the
 * placement configuration isn't supported on the platform / submission
 * interface.
 */
struct prelim_i915_context_engines_parallel_submit {
	struct i915_user_extension base;

/*
 * Default placement behvavior (currently unsupported):
 *
 * Rather than restricting parallel submission to a single class with a
 * logically contiguous placement (PRELIM_I915_PARALLEL_IMPLICT_BONDS), add a mode that
 * enables parallel submission across multiple engine classes. In this case each
 * context's logical engine mask indicates where that context can placed
 * compared to the flag, PRELIM_I915_PARALLEL_IMPLICT_BONDS, where only the first
 * context's logical mask controls the placement. It is implied in this mode
 * that all contexts have mutual exclusive placement (e.g. if one context is
 * running VCS0 no other contexts can run on VCS0).
 *
 * Example 1 pseudo code:
 * INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 * set_engines(INVALID, INVALID)
 * set_load_balance(engine_index=0, num_siblings=4, engines=VCS0,VCS1,VCS2,VCS3)
 * set_load_balance(engine_index=1, num_siblings=4, engines=RCS0,RCS1,RCS2,RCS3)
 * set_parallel()
 *
 * Results in the following valid placements:
 * VCS0, RCS0
 * VCS0, RCS1
 * VCS0, RCS2
 * VCS0, RCS3
 * VCS1, RCS0
 * VCS1, RCS1
 * VCS1, RCS2
 * VCS1, RCS3
 * VCS2, RCS0
 * VCS2, RCS1
 * VCS2, RCS2
 * VCS2, RCS3
 * VCS3, RCS0
 * VCS3, RCS1
 * VCS3, RCS2
 * VCS3, RCS3
 *
 * Example 2 pseudo code:
 * INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 * set_engines(INVALID, INVALID)
 * set_load_balance(engine_index=0, num_siblings=3, engines=VCS0,VCS1,VCS2)
 * set_load_balance(engine_index=1, num_siblings=3, engines=VCS0,VCS1,VCS2)
 * set_parallel()
 *
 * Results in the following valid placements:
 * VCS0, VCS1
 * VCS0, VCS2
 * VCS1, VCS0
 * VCS1, VCS2
 * VCS2, VCS0
 * VCS2, VCS1
 *
 * This enables a use case where all engines are created equally, we don't care
 * where they are scheduled, we just want a certain number of resources, for
 * those resources to be scheduled in parallel, and possibly across multiple
 * engine classes.
 *
 * This mode is not supported with GuC submission gen12 or any prior platforms,
 * but could be supported in execlists mode. Future GuC platforms may support
 * this.
 */

/*
 * PRELIM_I915_PARALLEL_IMPLICT_BONDS - Create implict bonds between each context.
 * Each context must have the same number sibling and bonds are implictly create
 * of the siblings.
 *
 * All of the below examples are in logical space.
 *
 * Example 1 pseudo code:
 * set_engines(VCS0, VCS1)
 * set_parallel(flags=PRELIM_I915_PARALLEL_IMPLICT_BONDS)
 *
 * Results in the following valid placements:
 * VCS0, VCS1
 *
 * Example 2 pseudo code:
 * INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 * set_engines(INVALID, INVALID)
 * set_load_balance(engine_index=0, num_siblings=4, engines=VCS0,VCS2,VCS4,VCS6)
 * set_load_balance(engine_index=1, num_siblings=4, engines=VCS1,VCS3,VCS5,VCS7)
 * set_parallel(flags=PRELIM_I915_PARALLEL_IMPLICT_BONDS)
 *
 * Results in the following valid placements:
 * VCS0, VCS1
 * VCS2, VCS3
 * VCS4, VCS5
 * VCS6, VCS7
 *
 * Example 3 pseudo code:
 * INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 * set_engines(INVALID, INVALID, INVALID, INVALID)
 * set_load_balance(engine_index=0, num_siblings=2, engines=VCS0,VCS4)
 * set_load_balance(engine_index=1, num_siblings=2, engines=VCS1,VCS5)
 * set_load_balance(engine_index=2, num_siblings=2, engines=VCS2,VCS6)
 * set_load_balance(engine_index=3, num_siblings=2, engines=VCS3,VCS7)
 * set_parallel(flags=PRELIM_I915_PARALLEL_IMPLICT_BONDS)
 *
 * Results in the following valid placements:
 * VCS0, VCS1, VCS2, VCS3
 * VCS4, VCS5, VCS6, VCS7
 *
 * This enables a use case where all engines are not equal and certain placement
 * rules are required (i.e. split-frame requires all contexts to be placed in a
 * logically contiguous order on the VCS engines on gen11/gen12 platforms). This
 * use case (logically contiguous placement, within a single engine class) is
 * supported when using GuC submission. Execlist mode could support all possible
 * bonding configurations.
 */
#define PRELIM_I915_PARALLEL_IMPLICT_BONDS	(1ull << 63)
#define I915_PARALLEL_IMPLICT_BONDS	(1<<0)
/*
 * Do not allow BBs to be preempted mid BB rather insert coordinated preemption
 * points on all hardware contexts between each BB. An example use case of this
 * feature is split-frame on gen11 or gen12 hardware. When using this feature a
 * BB must be submitted on each hardware context in the parallel gem context.
 * The execbuf2 IOCTL enforces the user adheres to policy.
 */
#define PRELIM_I915_PARALLEL_BATCH_PREEMPT_BOUNDARY	(1ull << 62)
#define I915_PARALLEL_BATCH_PREEMPT_BOUNDARY	(1<<1)
#define __I915_PARALLEL_UNKNOWN_FLAGS	(-(I915_PARALLEL_BATCH_PREEMPT_BOUNDARY << 1))
#define __PRELIM_I915_PARALLEL_UNKNOWN_FLAGS (~(GENMASK_ULL(63, 62) | GENMASK_ULL(1, 0)))
	__u64 flags; /* all undefined flags must be zero */
	__u64 mbz64[4]; /* reserved for future use; must be zero */
} __attribute__ ((packed));
#define i915_context_engines_parallel_submit prelim_i915_context_engines_parallel_submit

/**
 * struct prelim_drm_i915_context_engines_parallel2_submit - Configure engine
 * for parallel submission.
 *
 * Setup a slot in the context engine map to allow multiple BBs to be submitted
 * in a single execbuf IOCTL. Those BBs will then be scheduled to run on the GPU
 * in parallel. Multiple hardware contexts are created internally in the i915
 * run these BBs. Once a slot is configured for N BBs only N BBs can be
 * submitted in each execbuf IOCTL and this is implicit behavior e.g. The user
 * doesn't tell the execbuf IOCTL there are N BBs, the execbuf IOCTL knows how
 * many BBs there are based on the slot's configuration. The N BBs are the last
 * N buffer objects or first N if I915_EXEC_BATCH_FIRST is set.
 *
 * The default placement behavior is to create implicit bonds between each
 * context if each context maps to more than 1 physical engine (e.g. context is
 * a virtual engine). Also we only allow contexts of same engine class and these
 * contexts must be in logically contiguous order. Examples of the placement
 * behavior described below. Lastly, the default is to not allow BBs to
 * preempted mid BB rather insert coordinated preemption on all hardware
 * contexts between each set of BBs. Flags may be added in the future to change
 * both of these default behaviors.
 *
 * Returns -EINVAL if hardware context placement configuration is invalid or if
 * the placement configuration isn't supported on the platform / submission
 * interface.
 * Returns -ENODEV if extension isn't supported on the platform / submission
 * inteface.
 *
 * .. code-block::
 *
 *	Example 1 pseudo code:
 *	CS[X] = generic engine of same class, logical instance X
 *	INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 *	set_engines(INVALID)
 *	set_parallel(engine_index=0, width=2, num_siblings=1,
 *		     engines=CS[0],CS[1])
 *
 *	Results in the following valid placement:
 *	CS[0], CS[1]
 *
 *	Example 2 pseudo code:
 *	CS[X] = generic engine of same class, logical instance X
 *	INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 *	set_engines(INVALID)
 *	set_parallel(engine_index=0, width=2, num_siblings=2,
 *		     engines=CS[0],CS[2],CS[1],CS[3])
 *
 *	Results in the following valid placements:
 *	CS[0], CS[1]
 *	CS[2], CS[3]
 *
 *	This can also be thought of as 2 virtual engines described by 2-D array
 *	in the engines the field with bonds placed between each index of the
 *	virtual engines. e.g. CS[0] is bonded to CS[1], CS[2] is bonded to
 *	CS[3].
 *	VE[0] = CS[0], CS[2]
 *	VE[1] = CS[1], CS[3]
 *
 *	Example 3 pseudo code:
 *	CS[X] = generic engine of same class, logical instance X
 *	INVALID = I915_ENGINE_CLASS_INVALID, I915_ENGINE_CLASS_INVALID_NONE
 *	set_engines(INVALID)
 *	set_parallel(engine_index=0, width=2, num_siblings=2,
 *		     engines=CS[0],CS[1],CS[1],CS[3])
 *
 *	Results in the following valid and invalid placements:
 *	CS[0], CS[1]
 *	CS[1], CS[3] - Not logical contiguous, return -EINVAL
 */
struct prelim_drm_i915_context_engines_parallel2_submit {
	/**
	 * @base: base user extension.
	 */
	struct i915_user_extension base;

	/**
	 * @engine_index: slot for parallel engine
	 */
	__u16 engine_index;

	/**
	 * @width: number of contexts per parallel engine
	 */
	__u16 width;

	/**
	 * @num_siblings: number of siblings per context
	 */
	__u16 num_siblings;

	/**
	 * @mbz16: reserved for future use; must be zero
	 */
	__u16 mbz16;

	/**
	 * @flags: all undefined flags must be zero, currently not defined flags
	 */
	__u64 flags;

	/**
	 * @mbz64: reserved for future use; must be zero
	 */
	__u64 mbz64[3];

	/**
	 * @engines: 2-d array of engine instances to configure parallel engine
	 *
	 * length = width (i) * num_siblings (j)
	 * index = j + i * num_siblings
	 */
	struct i915_engine_class_instance engines[0];
} __attribute__ ((packed));

struct prelim_i915_context_param_engines {
#define PRELIM_I915_CONTEXT_ENGINES_EXT_PARALLEL_SUBMIT (PRELIM_I915_USER_EXT | 2) /* see prelim_i915_context_engines_parallel_submit */
#define I915_CONTEXT_ENGINES_EXT_PARALLEL_SUBMIT 2 /* see i915_context_engines_parallel_submit */
#define PRELIM_I915_CONTEXT_ENGINES_EXT_PARALLEL2_SUBMIT (PRELIM_I915_USER_EXT | 3) /* see prelim_i915_context_engines_parallel2_submit */
};

enum prelim_drm_i915_oa_format {
	/* Values continue from enum drm_i915_oa_format */
	/* XEHPSDV */
	I915_OAR_FORMAT_A32u40_A4u32_B8_C8 = 11,
	I915_OA_FORMAT_A24u40_A14u32_B8_C8,
	I915_OAM_FORMAT_A2u64_B8_C8,

	/* DG2 */
	I915_OAR_FORMAT_A36u64_B8_C8,
	I915_OAC_FORMAT_A24u64_B8_C8,
	I915_OA_FORMAT_A38u64_R2u64_B8_C8,
	I915_OAM_FORMAT_A2u64_R2u64_B8_C8,

	/* Move to 'enum drm_i915_oa_format' after switch to PRELIM uapi */
	I915_OA_FORMAT_MAX,		/* non-ABI */

	/* Start of PRELIM formats */
	PRELIM_I915_OA_FORMAT_START = 128,

	/* XEHPSDV */
	PRELIM_I915_OAR_FORMAT_A32u40_A4u32_B8_C8 = PRELIM_I915_OA_FORMAT_START,
	PRELIM_I915_OA_FORMAT_A24u40_A14u32_B8_C8,
	PRELIM_I915_OAM_FORMAT_A2u64_B8_C8,

	/* DG2 */
	PRELIM_I915_OAR_FORMAT_A36u64_B8_C8,
	PRELIM_I915_OAC_FORMAT_A24u64_B8_C8,
	PRELIM_I915_OA_FORMAT_A38u64_R2u64_B8_C8,
	PRELIM_I915_OAM_FORMAT_A2u64_R2u64_B8_C8,

	PRELIM_I915_OA_FORMAT_MAX	/* non-ABI */
};

enum prelim_drm_i915_perf_record_type {
#define PRELIM_DRM_I915_PERF_RECORD	(1 << 16)
	/*
	 * MMIO trigger queue is full.
	 * This record type is available in perf revision 1003.
	 */
	PRELIM_DRM_I915_PERF_RECORD_OA_MMIO_TRG_Q_FULL = (PRELIM_DRM_I915_PERF_RECORD | 1),
};

/*
 * Access Counter programming
 *
 * The programmable access counters enable hardware to detect and report
 * frequently accessed pages. The report generated by hardware can be used by
 * software for influencing page migration and data placement decisions.
 *
 * Once the count reaches the value set by trigger, HW generates trigger
 * interrupt. DRM driver then starts the page migration from SMEM to
 * LMEM so the upcoming access to the same page(s) from GPU will access LMEM
 * to achive better performance.
 *
 * Due to the HW capacity limitation, an access counter can be de-allocated on
 * the fly. If the counter getting de-allocated has reached at least notify
 * it is reported to SW via interrupt. The driver interrupt handling is TBD.
 *
 * The use case is to let the upper layer SW such as Open CL to make the
 * decision to program all the configurations and the DRM driver will handle
 * the interrupts generated by HW.
 *
 * NOTE: if ac_notify is set to 0, access counter notification reporting is disabled
 *       if ac_trigger is set to 0, access counter triggering is disabled.
 *
 *	Only allowed in i915_gem_context_create_ioctl extension
 */
struct prelim_drm_i915_gem_context_param_acc {
		__u16 trigger;
		__u16 notify;
		__u8  granularity;
#define   PRELIM_I915_CONTEXT_ACG_128K      0
#define   PRELIM_I915_CONTEXT_ACG_2M        1
#define   PRELIM_I915_CONTEXT_ACG_16M       2
#define   PRELIM_I915_CONTEXT_ACG_64M       3
#define   I915_CONTEXT_ACG_128K      0
#define   I915_CONTEXT_ACG_2M        1
#define   I915_CONTEXT_ACG_16M       2
#define   I915_CONTEXT_ACG_64M       3
		__u8 pad1;
		__u16 pad2;
};
#define drm_i915_gem_context_param_acc prelim_drm_i915_gem_context_param_acc

struct prelim_drm_i915_gem_context_param {
/*
 * I915_CONTEXT_PARAM_DEBUG_FLAGS
 *
 * Set or clear debug flags associated with this context.
 * The flags works with 32 bit masking to enable/disable individual
 * flags. For example to set debug flag of bit position 0, the
 * value needs to be 0x0000000100000001, and to clear flag of
 * bit position 0, the value needs to be 0x0000000100000000.
 *
 */
#define PRELIM_I915_CONTEXT_PARAM		(1 << 16)
#define PRELIM_I915_CONTEXT_PARAM_DEBUG_FLAGS	(PRELIM_I915_CONTEXT_PARAM | 0xfd)
#define I915_CONTEXT_PARAM_DEBUG_FLAGS	0xfd /* temporary */

/*
 * Notify driver that SIP is provided with the pipeline setup.
 * Driver raises exception on hang resolution and waits for pipeline's
 * sip to signal attention before capturing state of user objects
 * associated with the context.
 *
 */
#define PRELIM_I915_CONTEXT_PARAM_DEBUG_FLAG_SIP	(1ull << 0)
#define I915_CONTEXT_PARAM_DEBUG_FLAG_SIP    (1ull << 0)

/*
 *  PRELIM_I915_CONTEXT_PARAM_ACC:
 *
 *  To be able to change the access counter thresholds and configurations.
 *
 *  By default: access counter feature is disabled.
 */
#define PRELIM_I915_CONTEXT_PARAM_ACC		(PRELIM_I915_CONTEXT_PARAM | 0xd)
#define I915_CONTEXT_PARAM_ACC    0xd
};

struct prelim_drm_i915_gem_context_create_ext {
#define PRELIM_I915_CONTEXT_CREATE_FLAGS_ULLS		(1u << 31)
#define I915_CONTEXT_CREATE_FLAGS_ULLS			(1u << 2)
#define I915_CONTEXT_CREATE_FLAGS_UNKNOWN (~(GENMASK(31, 31) | GENMASK(2, 0)))
};

/*
 *  PRELIM_I915_CONTEXT_PARAM_RUNALONE:
 *
 *  Enable runalone mode on a context, disabled by default.
 */
#define PRELIM_I915_CONTEXT_PARAM_RUNALONE      (PRELIM_I915_CONTEXT_PARAM | 0xf)

enum prelim_drm_i915_perf_property_id {
	/* Values continue from enum drm_i915_perf_property_id */
	DRM_I915_PERF_PROP_OA_BUFFER_SIZE = 9,

	DRM_I915_PERF_PROP_OA_ENGINE_CLASS,

	DRM_I915_PERF_PROP_OA_ENGINE_INSTANCE,

	/* Move to 'enum drm_i915_perf_property_id' after switch to PRELIM uapi */
	DRM_I915_PERF_PROP_MAX, /* non-ABI */

	/* Downstream PRELIM properties */
	PRELIM_DRM_I915_PERF_PROP = (1 << 16),

	/**
	 * Specify a global OA buffer size to be allocated in bytes. The size
	 * specified must be supported by HW (before XEHPSDV supported sizes are
	 * powers of 2 ranging from 128Kb to 16Mb. With XEHPSDV max supported size
	 * is 128Mb).
	 *
	 * This property is available in perf revision 1001.
	 */
	PRELIM_DRM_I915_PERF_PROP_OA_BUFFER_SIZE = (PRELIM_DRM_I915_PERF_PROP | 1),

	/**
	 * Specify the engine class defined in @enum drm_i915_gem_engine_class.
	 * This defaults to I915_ENGINE_CLASS_RENDER or
	 * I915_ENGINE_CLASS_COMPUTE based on the platform.
	 *
	 * This property is available in perf revision 1002
	 *
	 * Perf revision 1004 supports I915_ENGINE_CLASS_VIDEO and
	 * I915_ENGINE_CLASS_VIDEO_ENHANCE.
	 */
	PRELIM_DRM_I915_PERF_PROP_OA_ENGINE_CLASS = (PRELIM_DRM_I915_PERF_PROP | 2),

	/**
	 * Specify the engine instance. Defaults to 0.
	 *
	 * This property is available in perf revision 1002.
	 */
	PRELIM_DRM_I915_PERF_PROP_OA_ENGINE_INSTANCE = (PRELIM_DRM_I915_PERF_PROP | 3),

	PRELIM_DRM_I915_PERF_PROP_LAST,

	/*
	 * After switch to PRELIM uapi this would be:
	 * PRELIM_DRM_I915_PERF_PROP_MAX = DRM_I915_PERF_PROP_MAX +
	 *				(PRELIM_DRM_I915_PERF_PROP_LAST & 0xffff)
	 */
	PRELIM_DRM_I915_PERF_PROP_MAX = DRM_I915_PERF_PROP_MAX,
};

struct prelim_drm_i915_uuid_control {
	char  uuid[36]; /* String formatted like
			 *      "%08x-%04x-%04x-%04x-%012x"
			 */

	__u32 uuid_class; /* Predefined UUID class or handle to
			   * the previously registered UUID Class
			   */

	__u32 flags;	/* MBZ */

	__u64 ptr;	/* Pointer to CPU memory payload associated
			 * with the UUID Resource.
			 * For uuid_class I915_UUID_CLASS_STRING
			 * it must point to valid string buffer.
			 * Otherwise must point to page aligned buffer
			 * or be NULL.
			 */

	__u64 size;	/* Length of the payload in bytes */

#define PRELIM_I915_UUID_CLASS_STRING	((__u32)-1)
#define I915_UUID_CLASS_STRING	((__u32)-1)
/*
 * d9900de4-be09-56ab-84a5-dfc280f52ee5 =
 *                          sha1(“I915_UUID_CLASS_STRING”)[0..35]
 */
#define PRELIM_I915_UUID_CLASS_MAX_RESERVED ((__u32)-1024)
#define I915_UUID_CLASS_MAX_RESERVED ((__u32)-1024)

	__u32 handle; /* Output: Registered handle ID */

	__u64 extensions; /* MBZ */
};
#define drm_i915_uuid_control prelim_drm_i915_uuid_control

/*
 * struct prelim_drm_i915_vm_bind_ext_uuid
 *
 * Used for registering metadata that will be attached to the vm
 */
struct prelim_drm_i915_vm_bind_ext_uuid {
#define PRELIM_I915_VM_BIND_EXT_UUID	(PRELIM_I915_USER_EXT | 1)
#define I915_VM_BIND_EXT_UUID     1
	struct i915_user_extension base;
	__u32 uuid_handle; /* Handle to the registered UUID resource. */
};
#define drm_i915_vm_bind_ext_uuid prelim_drm_i915_vm_bind_ext_uuid

/**
 * Do a debug event read for a debugger connection.
 *
 * This ioctl is available in debug version 1.
 */
#define PRELIM_I915_DEBUG_IOCTL_READ_EVENT _IO('j', 0x0)
#define I915_DEBUG_IOCTL_READ_EVENT _IO('i', 0x0)
#define PRELIM_I915_DEBUG_IOCTL_READ_UUID  _IOWR('j', 0x1, struct prelim_drm_i915_debug_read_uuid)
#define I915_DEBUG_IOCTL_READ_UUID  _IOWR('i', 0x1, struct drm_i915_debug_read_uuid)
#define PRELIM_I915_DEBUG_IOCTL_VM_OPEN  _IOW('j', 0x2, struct prelim_drm_i915_debug_vm_open)
#define PRELIM_I915_DEBUG_IOCTL_EU_CONTROL _IOWR('j', 0x3, struct prelim_drm_i915_debug_eu_control)
#define PRELIM_I915_DEBUG_IOCTL_ACK_EVENT _IOW('j', 0x4, struct prelim_drm_i915_debug_event_ack)

struct prelim_drm_i915_debug_event {
	__u32 type;
#define PRELIM_DRM_I915_DEBUG_EVENT_NONE     0
#define PRELIM_DRM_I915_DEBUG_EVENT_READ     1
#define PRELIM_DRM_I915_DEBUG_EVENT_CLIENT   2
#define PRELIM_DRM_I915_DEBUG_EVENT_CONTEXT  3
#define PRELIM_DRM_I915_DEBUG_EVENT_UUID     4
#define PRELIM_DRM_I915_DEBUG_EVENT_VM       5
#define PRELIM_DRM_I915_DEBUG_EVENT_VM_BIND  6
#define PRELIM_DRM_I915_DEBUG_EVENT_CONTEXT_PARAM 7
#define PRELIM_DRM_I915_DEBUG_EVENT_EU_ATTENTION 8
#define PRELIM_DRM_I915_DEBUG_EVENT_ENGINES 9
#define DRM_I915_DEBUG_EVENT_NONE     0
#define DRM_I915_DEBUG_EVENT_READ     1
#define DRM_I915_DEBUG_EVENT_CLIENT   2
#define DRM_I915_DEBUG_EVENT_CONTEXT  3
#define DRM_I915_DEBUG_EVENT_UUID     4
#define PRELIM_DRM_I915_DEBUG_EVENT_MAX_EVENT PRELIM_DRM_I915_DEBUG_EVENT_ENGINES

	__u32 flags;
#define PRELIM_DRM_I915_DEBUG_EVENT_CREATE	(1 << 31)
#define PRELIM_DRM_I915_DEBUG_EVENT_DESTROY	(1 << 30)
#define PRELIM_DRM_I915_DEBUG_EVENT_STATE_CHANGE (1 << 29)
#define PRELIM_DRM_I915_DEBUG_EVENT_NEED_ACK	(1 << 28)
#define DRM_I915_DEBUG_EVENT_CREATE	(1 << 0)
#define DRM_I915_DEBUG_EVENT_DESTROY	(1 << 1)
#define DRM_I915_DEBUG_EVENT_STATE_CHANGE (1 << 2)
#define DRM_I915_DEBUG_EVENT_NEED_ACK	(1 << 3)
	__u64 seqno;
	__u64 size;
} __attribute__((packed));
#define drm_i915_debug_event prelim_drm_i915_debug_event

struct prelim_drm_i915_debug_event_client {
	struct prelim_drm_i915_debug_event base; /* .flags = CREATE/DESTROY */

	__u64 handle; /* This is unique per debug connection */
} __attribute__((packed));
#define drm_i915_debug_event_client prelim_drm_i915_debug_event_client

struct prelim_drm_i915_debug_event_context {
	struct prelim_drm_i915_debug_event base;

	__u64 client_handle;
	__u64 handle;
} __attribute__((packed));
#define drm_i915_debug_event_context prelim_drm_i915_debug_event_context

struct prelim_drm_i915_debugger_open_param {
	__u64 pid; /* input: Target process ID */
	__u32 flags;
#define PRELIM_DRM_I915_DEBUG_FLAG_FD_NONBLOCK	(1u << 31)
#define DRM_I915_DEBUG_FLAG_FD_NONBLOCK (1u << 0)

	__u32 version;
	__u64 events;  /* input: event types to subscribe to */
	__u64 extensions; /* MBZ */
};
#define drm_i915_debugger_open_param prelim_drm_i915_debugger_open_param

struct prelim_drm_i915_debug_event_uuid {
	struct prelim_drm_i915_debug_event base;
	__u64 client_handle;

	__u64 handle;
	__u64 class_handle; /* Can be filtered based on pre-defined classes */
	__u64 payload_size;
} __attribute__((packed));
#define drm_i915_debug_event_uuid prelim_drm_i915_debug_event_uuid

struct prelim_drm_i915_debug_event_vm {
	struct drm_i915_debug_event base;
	__u64 client_handle;

	__u64 handle;
} __attribute__((packed));

struct prelim_drm_i915_debug_event_vm_bind {
	struct drm_i915_debug_event base;
	__u64 client_handle;

	__u64 vm_handle;
	__u64 va_start;
	__u64 va_length;
	__u32 num_uuids;
	__u32 flags;
	__u64 uuids[0];
} __attribute__((packed));

struct prelim_drm_i915_debug_event_eu_attention {
	struct prelim_drm_i915_debug_event base;
	__u64 client_handle;
	__u64 ctx_handle;
	__u64 lrc_handle;

	__u32 flags;

	struct i915_engine_class_instance ci;

	__u32 bitmask_size;

	/**
	 * Bitmask of thread attentions starting from natural
	 * hardware order of slice=0,subslice=0,eu=0, 8 attention
	 * bits per eu.
	 *
	 * NOTE: For dual subslice GENs, the bitmask is for
	 * lockstepped EUs and not for logical EUs. This makes
	 * the bitmask includu only half of logical EU count
	 * provided by topology query as we only control the
	 * 'pair' instead of individual EUs.
	 */

	__u8 bitmask[0];
} __attribute__((packed));

struct prelim_drm_i915_debug_read_uuid {
	__u64 client_handle;
	__u64 handle;
	__u32 flags; /* MBZ */
	char uuid[36]; /* output */
	__u64 payload_ptr;
	__u64 payload_size;
} __attribute__((packed));
#define drm_i915_debug_read_uuid prelim_drm_i915_debug_read_uuid

struct prelim_drm_i915_debug_event_context_param {
	struct prelim_drm_i915_debug_event base;
	__u64 client_handle;
	__u64 ctx_handle;
	struct drm_i915_gem_context_param param;
} __attribute__((packed));
#define drm_i915_debug_event_context_param prelim_drm_i915_debug_event_context_param

struct prelim_drm_i915_debug_engine_info {
	struct i915_engine_class_instance engine;
	__u64 lrc_handle;
} __attribute__((packed));

struct prelim_drm_i915_debug_event_engines {
	struct prelim_drm_i915_debug_event base;
	__u64 client_handle;
	__u64 ctx_handle;
	__u64 num_engines;
	struct prelim_drm_i915_debug_engine_info engines[0];
} __attribute__((packed));

struct prelim_drm_i915_debug_vm_open {
	__u64 client_handle;
	__u64 handle; /* input: The target address space (ppGTT) */
	__u64 flags;
#define PRELIM_I915_DEBUG_VM_OPEN_READ_ONLY	O_RDONLY
#define PRELIM_I915_DEBUG_VM_OPEN_WRITE_ONLY	O_WRONLY
#define PRELIM_I915_DEBUG_VM_OPEN_READ_WRITE	O_RDWR
};

struct prelim_drm_i915_debug_eu_control {
	__u64 client_handle;
	__u32 cmd;
#define PRELIM_I915_DEBUG_EU_THREADS_CMD_INTERRUPT_ALL 0
#define PRELIM_I915_DEBUG_EU_THREADS_CMD_STOPPED   1
#define PRELIM_I915_DEBUG_EU_THREADS_CMD_RESUME    2
#define PRELIM_I915_DEBUG_EU_THREADS_CMD_INTERRUPT 3
	__u32 flags;
	__u64 seqno;

	struct i915_engine_class_instance ci;
	__u32 bitmask_size;

	/**
	 * Bitmask of thread attentions starting from natural
	 * hardware order of slice=0,subslice=0,eu=0, 8 attention bits
	 * per eu.
	 *
	 * NOTE: For dual subslice GENs, the bitmask is for
	 * lockstepped EUs and not for logical EUs. This makes
	 * the bitmask includu only half of logical EU count
	 * provided by topology query as we only control the
	 * 'pair' instead of individual EUs.
	 */
	__u64 bitmask_ptr;
} __attribute__((packed));

struct prelim_drm_i915_debug_event_ack {
	__u32 type;
	__u32 flags; /* MBZ */
	__u64 seqno;
} __attribute__((packed));

enum prelim_drm_i915_gem_memory_class {
	PRELIM_I915_MEMORY_CLASS_SYSTEM = 0,
	PRELIM_I915_MEMORY_CLASS_DEVICE,
	PRELIM_I915_MEMORY_CLASS_NONE = -1
};

enum drm_i915_gem_memory_class {
	I915_MEMORY_CLASS_SYSTEM = 0,
	I915_MEMORY_CLASS_DEVICE,
	I915_MEMORY_CLASS_NONE = -1
};

/**
 * struct prelim_drm_i915_memory_region_info
 *
 * Describes one region as known to the driver.
 */
struct prelim_drm_i915_memory_region_info {
	/** class:instance pair encoding */
	struct prelim_drm_i915_gem_memory_class_instance region;

	/** MBZ */
	__u32 rsvd0;

	/** MBZ */
	__u64 caps;

	/** MBZ */
	__u64 flags;

	/** Memory probed by the driver (-1 = unknown) */
	__u64 probed_size;

	/** Estimate of memory remaining (-1 = unknown) */
	__u64 unallocated_size;

	/** MBZ */
	__u64 rsvd1[8];
};
#define drm_i915_memory_region_info prelim_drm_i915_memory_region_info

/**
 * struct prelim_drm_i915_query_memory_regions
 *
 * Region info query enumerates all regions known to the driver by filling in
 * an array of struct prelim_drm_i915_memory_region_info structures.
 */
struct prelim_drm_i915_query_memory_regions {
	/** Number of supported regions */
	__u32 num_regions;

	/** MBZ */
	__u32 rsvd[3];

	/* Info about each supported region */
	struct prelim_drm_i915_memory_region_info regions[];
};
#define drm_i915_query_memory_regions prelim_drm_i915_query_memory_regions

/**
 * struct prelim_drm_i915_query_distance_info
 *
 * Distance info query returns the distance of given (class, instance)
 * engine to the memory region id passed by the user. If the distance
 * is -1 it means region is unreachable.
 */
struct prelim_drm_i915_query_distance_info {
	/** Engine for which distance is queried */
	struct i915_engine_class_instance engine;

	/** Memory region to be used */
	struct prelim_drm_i915_gem_memory_class_instance region;

	/** Distance to region from engine */
	__s32 distance;

	/** Must be zero */
	__u32 rsvd[3];
};
#define drm_i915_query_distance_info prelim_drm_i915_query_distance_info

/**
 * struct prelim_drm_i915_query_cs_cycles
 *
 * The query returns the command streamer cycles and the frequency that can be
 * used to calculate the command streamer timestamp. In addition the query
 * returns the cpu timestamp that indicates when the command streamer cycle
 * count was captured.
 */
struct prelim_drm_i915_query_cs_cycles {
	/** Engine for which command streamer cycles is queried. */
	struct i915_engine_class_instance engine;

	/** Must be zero. */
	__u32 flags;

	/**
	 * Command streamer cycles as read from the command streamer
	 * register at 0x358 offset.
	 */
	__u64 cs_cycles;

	/** Frequency of the cs cycles in Hz. */
	__u64 cs_frequency;

	/** CPU timestamp in nanoseconds. */
	__u64 cpu_timestamp;

	/**
	 * Reference clock id for CPU timestamp. For definition, see
	 * clock_gettime(2) and perf_event_open(2). Supported clock ids are
	 * CLOCK_MONOTONIC, CLOCK_MONOTONIC_RAW, CLOCK_REALTIME, CLOCK_BOOTTIME,
	 * CLOCK_TAI.
	 */
	__s32 clockid;

	/** Must be zero. */
	__u32 rsvd;
};
#define drm_i915_query_cs_cycles prelim_drm_i915_query_cs_cycles

/**
 * struct prelim_drm_i915_query_fabric_info
 *
 * With the given fabric id, query fabric info wrt the device.
 * Higher bandwidth is better.  0 means no fabric.
 * Latency is averaged latency (from all paths)
 *
 * fabric_id can be obtained from
 *    /sys/class/drm/cardx/device/iaf.y/iaf_fabric_id
 * Bandwidth is in Gigabits per second (max value of 8 * 4 * 90)
 *    8 possible ports
 *    4 lanes max per port
 *   90 gigabits per lane
 * Latency is in tenths of path length. 10 == 1 fabric link between src and dst
 *   POR is max 1 link (zero hops).
 */
struct prelim_drm_i915_query_fabric_info {
	__u32 fabric_id;
	__u16 bandwidth;
	__u16 latency;
};
#define drm_i915_query_fabric_info prelim_drm_i915_query_fabric_info

/**
 * struct prelim_drm_i915_engine_info
 *
 * Describes one engine and it's capabilities as known to the driver.
 */
struct prelim_drm_i915_engine_info {
	/** Engine class and instance. */
	struct i915_engine_class_instance engine;

	/**
	 * SW defined id that identifies the OA unit associated with this
	 * engine. A value of U32_MAX means engine is not supported by OA. All
	 * other values are valid and can be used to group engines into the
	 * associated OA unit.
	 */
	__u32 oa_unit_id;

	/** Engine flags. */
	__u64 flags;
#define PRELIM_I915_ENGINE_INFO_HAS_KNOWN_CAPABILITIES	(1ull << 63)
#define I915_ENGINE_INFO_HAS_KNOWN_CAPABILITIES		(1 << 0)
#define PRELIM_I915_ENGINE_INFO_HAS_LOGICAL_INSTANCE	(1ull << 62)
#define I915_ENGINE_INFO_HAS_LOGICAL_INSTANCE		(1 << 1)
#define PRELIM_I915_ENGINE_INFO_HAS_OA_UNIT_ID		(1ull << 61)

	/** Capabilities of this engine. */
	__u64 capabilities;
#define PRELIM_I915_RENDER_CLASS_CAPABILITY_3D		(1ull << 63)
#define I915_RENDER_CLASS_CAPABILITY_3D			(1 << 0)
#define I915_VIDEO_CLASS_CAPABILITY_HEVC		(1 << 0)
#define I915_VIDEO_AND_ENHANCE_CLASS_CAPABILITY_SFC	(1 << 1)
#define PRELIM_I915_VIDEO_CLASS_CAPABILITY_VDENC	(1ull << 63)
#define I915_VIDEO_CLASS_CAPABILITY_VDENC		(1 << 2)
#define PRELIM_I915_COPY_CLASS_CAP_BLOCK_COPY		(1ull << 63)
#define I915_COPY_CLASS_CAP_BLOCK_COPY			(1 << 0)
	/*
	 * The following are capabilties of the copy engines, while all engines
	 * are functionally same, but engines with cap PRELIM_I915_COPY_CLASS_CAP_SATURATE_LINK
	 * can saturate pcie and scaleup links faster than engines with
	 * PRELIM_I915_COPY_CLASS_CAP_SATURATE_PCIE. Engines having the capability of
	 * PRELIM_I915_COPY_CLASS_CAP_SATURATE_LMEM can operate at HBM speeds.
	 */
#define PRELIM_I915_COPY_CLASS_CAP_SATURATE_PCIE	(1ull << 62)
#define I915_COPY_CLASS_CAP_SATURATE_PCIE		(1 << 1)
#define PRELIM_I915_COPY_CLASS_CAP_SATURATE_LINK	(1ull << 61)
#define I915_COPY_CLASS_CAP_SATURATE_LINK		(1 << 2)
#define PRELIM_I915_COPY_CLASS_CAP_SATURATE_LMEM	(1ull << 60)
#define I915_COPY_CLASS_CAP_SATURATE_LMEM		(1 << 3)

	/** All known capabilities for this engine class. */
	__u64 known_capabilities;

	/** Logical engine instance */
	__u16 logical_instance;

	/** Reserved fields. */
	__u16 rsvd1[3];
	__u64 rsvd2[2];
};

/**
 * struct drm_i915_query_engine_info
 *
 * Engine info query enumerates all engines known to the driver by filling in
 * an array of struct drm_i915_engine_info structures.
 */
struct prelim_drm_i915_query_engine_info {
	/** Number of struct drm_i915_engine_info structs following. */
	__u32 num_engines;

	/** MBZ */
	__u32 rsvd[3];

	/** Marker for drm_i915_engine_info structures. */
	struct prelim_drm_i915_engine_info engines[];
};

/**
 * struct prelim_drm_i915_gem_vm_bind
 *
 * VA to object/buffer mapping to [un]bind.
 *
 * NOTE:
 * A vm_bind will hold a reference on the BO which is released
 * during corresponding vm_unbind or while closing the VM.
 * Hence closing the BO alone will not ensure BO is released.
 */
struct prelim_drm_i915_gem_vm_bind {
	/** vm to [un]bind **/
	__u32 vm_id;

	/** BO handle or file descriptor. Set 'fd' to -1 for system pages **/
	union {
		__u32 handle;
		__s32 fd;
	};

	/** VA start to [un]bind **/
	__u64 start;

	/** Offset in object to [un]bind **/
	__u64 offset;

	/** VA length to [un]bind **/
	__u64 length;

	/** Flags **/
	__u64 flags;
#define PRELIM_I915_GEM_VM_BIND_IMMEDIATE	(1ull << 63)
#define PRELIM_I915_GEM_VM_BIND_READONLY	(1ull << 62)
#define I915_GEM_VM_BIND_IMMEDIATE   (1 << 0)
#define I915_GEM_VM_BIND_READONLY    (1 << 1)
#define PRELIM_I915_GEM_VM_BIND_CAPTURE		(1ull << 61)
#define I915_GEM_VM_BIND_CAPTURE     (1 << 2)
#define PRELIM_I915_GEM_VM_BIND_FD		(1ull << 60)
#define I915_GEM_VM_BIND_FD          (1 << 3)

	__u64 extensions;
};
#define drm_i915_gem_vm_bind prelim_drm_i915_gem_vm_bind

/**
 * struct prelim_drm_i915_gem_vm_advise
 *
 * Set attribute (hint) for an address range or whole buffer object.
 *
 * To apply attribute to whole buffer object, specify:  handle
 * To apply attribute to address range, specify:  vm_id, start, and length.
 */
struct prelim_drm_i915_gem_vm_advise {
	/** vm that contains address range (specified with start, length) */
	__u32 vm_id;

	/** BO handle to apply hint */
	__u32 handle;

	/** VA start of address range to apply hint */
	__u64 start;

	/** Length of range to apply attribute */
	__u64 length;

	/**
	 * Attributes to apply to address range or buffer object
	 *
	 * ATOMIC_SYSTEM
	 *      inform that atomic access is enabled for both CPU and GPU.
	 *      For some platforms, this may be required for correctness
	 *      and this hint will influence migration policy.
	 * ATOMIC_DEVICE
	 *      inform that atomic access is enabled for GPU devices. For
	 *      some platforms, this may be required for correctness and
	 *      this hint will influence migration policy.
	 * ATOMIC_NONE
	 *	clears above ATOMIC_SYSTEM / ATOMIC_DEVICE hint.
	 * PREFERRED_LOCATION
	 *	sets the preferred memory class and instance for this object's
	 *	backing store.  This is a hint only and not guaranteed to be
	 *	honored.  It is an error to choose a memory region that was not
	 *	part of the original set of placements for the GEM object.
	 *	If choosing a preferred location that is in conflict with the
	 *	use of ATOMIC_SYSTEM or ATOMIC_DEVICE, the atomic hint will
	 *	always be honored first.
	 *	To clear the current preferred location, specify memory class
	 *	as I915_MEMORY_CLASS_NONE.
	 */
	__u32 attribute;
#define PRELIM_I915_VM_ADVISE				(1 << 16)
#define PRELIM_I915_VM_ADVISE_ATOMIC_NONE		(PRELIM_I915_VM_ADVISE | 0)
#define PRELIM_I915_VM_ADVISE_ATOMIC_SYSTEM		(PRELIM_I915_VM_ADVISE | 1)
#define PRELIM_I915_VM_ADVISE_ATOMIC_DEVICE		(PRELIM_I915_VM_ADVISE | 2)
#define I915_VM_ADVISE_ATOMIC_NONE		0
#define I915_VM_ADVISE_ATOMIC_SYSTEM		1
#define I915_VM_ADVISE_ATOMIC_DEVICE		2
#define PRELIM_I915_VM_ADVISE_PREFERRED_LOCATION	(PRELIM_I915_VM_ADVISE | 3)
#define I915_VM_ADVISE_PREFERRED_LOCATION	3

	/** Preferred location (memory region) for object backing */
	struct prelim_drm_i915_gem_memory_class_instance region;

	__u32 rsvd[2];
};
#define drm_i915_gem_vm_advise prelim_drm_i915_gem_vm_advise

/**
 * struct prelim_drm_i915_gem_wait_user_fence
 *
 * Wait on user fence. User fence can be woken up either by,
 *    1. GPU context indicated by 'ctx_id', or,
 *    2. Kerrnel driver async worker upon PRELIM_I915_UFENCE_WAIT_SOFT.
 *       'ctx_id' is ignored when this flag is set.
 *
 * Wakeup when below condition is true.
 * (*addr & MASK) OP (VALUE & MASK)
 *
 */
struct prelim_drm_i915_gem_wait_user_fence {
	__u64 extensions;
	__u64 addr;
	__u32 ctx_id;
	__u16 op;
#define PRELIM_I915_UFENCE		(1 << 8)
#define PRELIM_I915_UFENCE_WAIT_EQ	(PRELIM_I915_UFENCE | 0)
#define PRELIM_I915_UFENCE_WAIT_NEQ	(PRELIM_I915_UFENCE | 1)
#define PRELIM_I915_UFENCE_WAIT_GT	(PRELIM_I915_UFENCE | 2)
#define PRELIM_I915_UFENCE_WAIT_GTE	(PRELIM_I915_UFENCE | 3)
#define PRELIM_I915_UFENCE_WAIT_LT	(PRELIM_I915_UFENCE | 4)
#define PRELIM_I915_UFENCE_WAIT_LTE	(PRELIM_I915_UFENCE | 5)
#define PRELIM_I915_UFENCE_WAIT_BEFORE	(PRELIM_I915_UFENCE | 6)
#define PRELIM_I915_UFENCE_WAIT_AFTER	(PRELIM_I915_UFENCE | 7)
#define I915_UFENCE_WAIT_EQ      0
#define I915_UFENCE_WAIT_NEQ     1
#define I915_UFENCE_WAIT_GT      2
#define I915_UFENCE_WAIT_GTE     3
#define I915_UFENCE_WAIT_LT      4
#define I915_UFENCE_WAIT_LTE     5
#define I915_UFENCE_WAIT_BEFORE  6
#define I915_UFENCE_WAIT_AFTER   7
	__u16 flags;
#define PRELIM_I915_UFENCE_WAIT_SOFT	(1 << 15)
#define PRELIM_I915_UFENCE_WAIT_ABSTIME	(1 << 14)
#define I915_UFENCE_WAIT_SOFT    0x1
#define I915_UFENCE_WAIT_ABSTIME 0x2
	__u64 value;
	__u64 mask;
#define PRELIM_I915_UFENCE_WAIT_U8     0xffu
#define PRELIM_I915_UFENCE_WAIT_U16    0xffffu
#define PRELIM_I915_UFENCE_WAIT_U32    0xfffffffful
#define PRELIM_I915_UFENCE_WAIT_U64    0xffffffffffffffffull
#define I915_UFENCE_WAIT_U8     0xffu
#define I915_UFENCE_WAIT_U16    0xffffu
#define I915_UFENCE_WAIT_U32    0xfffffffful
#define I915_UFENCE_WAIT_U64    0xffffffffffffffffull
	__s64 timeout;
};
#define drm_i915_gem_wait_user_fence prelim_drm_i915_gem_wait_user_fence

struct prelim_drm_i915_vm_bind_ext_sync_fence {
#define PRELIM_I915_VM_BIND_EXT_SYNC_FENCE     (PRELIM_I915_USER_EXT | 0)
#define I915_VM_BIND_EXT_SYNC_FENCE     0
	struct i915_user_extension base;
	__u64 addr;
	__u64 val;
};
#define drm_i915_vm_bind_ext_sync_fence prelim_drm_i915_vm_bind_ext_sync_fence

struct prelim_drm_i915_gem_vm_region_ext {
#define PRELIM_I915_GEM_VM_CONTROL_EXT_REGION	(PRELIM_I915_USER_EXT | 0)
#define I915_GEM_VM_CONTROL_EXT_REGION 0
	struct i915_user_extension base;
	/* memory region: to find gt to create vm on */
	struct prelim_drm_i915_gem_memory_class_instance region;
	__u32 pad;
};
#define drm_i915_gem_vm_region_ext prelim_drm_i915_gem_vm_region_ext

struct prelim_drm_i915_gem_vm_control {
#define PRELIM_I915_VM_CREATE_FLAGS_DISABLE_SCRATCH	((1 << 16) | 1)
#define I915_VM_CREATE_FLAGS_DISABLE_SCRATCH	(1u << 0)
#define PRELIM_I915_VM_CREATE_FLAGS_UNKNOWN (~(GENMASK(16, 16) | GENMASK(0, 0)))
};

struct prelim_drm_i915_vm_bind_ext_set_pat {
#define PRELIM_I915_VM_BIND_EXT_SET_PAT	(PRELIM_I915_USER_EXT | 2)
#define I915_VM_BIND_EXT_SET_PAT       2
       struct i915_user_extension base;
       __u64 pat_index;
};
#define drm_i915_vm_bind_ext_set_pat prelim_drm_i915_vm_bind_ext_set_pat

/**
 * struct prelim_drm_i915_gem_clos_reserve
 *
 * Allows clients to request reservation of one free CLOS, to use in subsequent
 * Cache Reservations.
 *
 */
struct prelim_drm_i915_gem_clos_reserve {
	__u16 clos_index;
	__u16 pad16;
};
#define drm_i915_gem_clos_reserve prelim_drm_i915_gem_clos_reserve

/**
 * struct prelim_drm_i915_gem_clos_free
 *
 * Free off a previously reserved CLOS set. Any corresponding Cache Reservations
 * that are active for the CLOS are automatically dropped and returned to the
 * Shared set.
 *
 * The clos_index indicates the CLOS set which is being released and must
 * correspond to a CLOS index previously reserved.
 *
 */
struct prelim_drm_i915_gem_clos_free {
	__u16 clos_index;
	__u16 pad16;
};
#define drm_i915_gem_clos_free prelim_drm_i915_gem_clos_free

/**
 * struct prelim_drm_i915_gem_cache_reserve
 *
 * Allows clients to request, or release, reservation of one or more cache ways,
 * within a previously reserved CLOS set.
 *
 * If num_ways = 0, i915 will drop any existing Reservation for the specified
 * clos_index and cache_level. The requested clos_index and cache_level Waymasks
 * will then track the Shared set once again.
 *
 * Otherwise, the requested number of Ways will be removed from the Shared set
 * for the requested cache level, and assigned to the Cache and CLOS specified
 * by cache_level/clos_index.
 *
 */
struct prelim_drm_i915_gem_cache_reserve {
	__u16 clos_index;
	__u16 cache_level; // e.g. 3 for L3
	__u16 num_ways;
	__u16 pad16;
};
#define drm_i915_gem_cache_reserve prelim_drm_i915_gem_cache_reserve

/**
 * struct prelim_drm_i915_gem_vm_prefetch
 *
 * Prefetch an address range to a memory region.
 */
struct prelim_drm_i915_gem_vm_prefetch {
	/** Memory region to prefetch to **/
	__u32 region;

	/** Reserved **/
	__u32 rsvd;

	/** VA start to prefetch **/
	__u64 start;

	/** VA length to prefetch **/
	__u64 length;
};
#define drm_i915_gem_vm_prefetch prelim_drm_i915_gem_vm_prefetch

struct prelim_drm_i915_gem_vm_param {
	__u32 vm_id;
	__u32 rsvd;

#define PRELIM_I915_VM_PARAM		(1ull << 63)
#define I915_VM_PARAM     (2ull << 32)
#define PRELIM_I915_GEM_VM_PARAM_SVM	(1 << 16)
#define I915_GEM_VM_PARAM_SVM   0x1
	__u64 param;

	__u64 value;
};
#define drm_i915_gem_vm_param prelim_drm_i915_gem_vm_param

#endif /* __I915_DRM_PRELIM_H__ */
