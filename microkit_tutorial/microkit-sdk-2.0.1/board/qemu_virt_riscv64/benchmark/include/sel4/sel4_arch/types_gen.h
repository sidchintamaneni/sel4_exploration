/* generated from /Users/ivanv/ts/microkit/seL4/libsel4/sel4_arch_include/riscv64/sel4/sel4_arch/types.bf */

#pragma once

#include <sel4/config.h>
#include <sel4/simple_types.h>
#include <sel4/debug_assert.h>
struct vm_attributes {
    seL4_Uint64 words[1];
};
typedef struct vm_attributes vm_attributes_t;

LIBSEL4_INLINE_FUNC vm_attributes_t CONST
vm_attributes_new(seL4_Uint64 riscvExecuteNever) {
    vm_attributes_t vm_attributes;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert((riscvExecuteNever & ~0x1ull) == ((0 && (riscvExecuteNever & (1ull << 63))) ? 0x0 : 0));

    vm_attributes.words[0] = 0
        | (riscvExecuteNever & 0x1ull) << 0;

    return vm_attributes;
}

LIBSEL4_INLINE_FUNC void
vm_attributes_ptr_new(vm_attributes_t *vm_attributes_ptr, seL4_Uint64 riscvExecuteNever) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert((riscvExecuteNever & ~0x1ull) == ((0 && (riscvExecuteNever & (1ull << 63))) ? 0x0 : 0));

    vm_attributes_ptr->words[0] = 0
        | (riscvExecuteNever & 0x1ull) << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
vm_attributes_get_riscvExecuteNever(vm_attributes_t vm_attributes) {
    seL4_Uint64 ret;
    ret = (vm_attributes.words[0] & 0x1ull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC vm_attributes_t CONST
vm_attributes_set_riscvExecuteNever(vm_attributes_t vm_attributes, seL4_Uint64 v64) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x1ull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));
    vm_attributes.words[0] &= ~0x1ull;
    vm_attributes.words[0] |= (v64 << 0) & 0x1ull;
    return vm_attributes;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
vm_attributes_ptr_get_riscvExecuteNever(vm_attributes_t *vm_attributes_ptr) {
    seL4_Uint64 ret;
    ret = (vm_attributes_ptr->words[0] & 0x1ull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
vm_attributes_ptr_set_riscvExecuteNever(vm_attributes_t *vm_attributes_ptr, seL4_Uint64 v64) {
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0x1ull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));
    vm_attributes_ptr->words[0] &= ~0x1ull;
    vm_attributes_ptr->words[0] |= (v64 << 0) & 0x1;
}

struct seL4_Fault {
    seL4_Uint64 words[12];
};
typedef struct seL4_Fault seL4_Fault_t;

enum seL4_Fault_tag {
    seL4_Fault_NullFault = 0,
    seL4_Fault_CapFault = 1,
    seL4_Fault_UnknownSyscall = 2,
    seL4_Fault_UserException = 3,
    seL4_Fault_Timeout = 5,
    seL4_Fault_VMFault = 6
};
typedef enum seL4_Fault_tag seL4_Fault_tag_t;

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_get_seL4_FaultType(seL4_Fault_t seL4_Fault) {
    return (seL4_Fault.words[0] >> 0) & 0xfull;
}

LIBSEL4_INLINE_FUNC int CONST
seL4_Fault_seL4_FaultType_equals(seL4_Fault_t seL4_Fault, seL4_Uint64 seL4_Fault_type_tag) {
    return ((seL4_Fault.words[0] >> 0) & 0xfull) == seL4_Fault_type_tag;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_ptr_get_seL4_FaultType(seL4_Fault_t *seL4_Fault_ptr) {
    return (seL4_Fault_ptr->words[0] >> 0) & 0xfull;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_NullFault_new(void) {
    seL4_Fault_t seL4_Fault;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_NullFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_NullFault & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_NullFault & 0xfull) << 0;
    seL4_Fault.words[1] = 0;
    seL4_Fault.words[2] = 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_NullFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_NullFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_NullFault & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_NullFault & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0;
    seL4_Fault_ptr->words[2] = 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_new(seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 InRecvPhase, seL4_Uint64 LookupFailureType, seL4_Uint64 MR4, seL4_Uint64 MR5, seL4_Uint64 MR6) {
    seL4_Fault_t seL4_Fault;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_CapFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_CapFault & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_CapFault & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | MR6 << 0;
    seL4_Fault.words[2] = 0
        | MR5 << 0;
    seL4_Fault.words[3] = 0
        | MR4 << 0;
    seL4_Fault.words[4] = 0
        | LookupFailureType << 0;
    seL4_Fault.words[5] = 0
        | InRecvPhase << 0;
    seL4_Fault.words[6] = 0
        | Addr << 0;
    seL4_Fault.words[7] = 0
        | IP << 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 InRecvPhase, seL4_Uint64 LookupFailureType, seL4_Uint64 MR4, seL4_Uint64 MR5, seL4_Uint64 MR6) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_CapFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_CapFault & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_CapFault & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | MR6 << 0;
    seL4_Fault_ptr->words[2] = 0
        | MR5 << 0;
    seL4_Fault_ptr->words[3] = 0
        | MR4 << 0;
    seL4_Fault_ptr->words[4] = 0
        | LookupFailureType << 0;
    seL4_Fault_ptr->words[5] = 0
        | InRecvPhase << 0;
    seL4_Fault_ptr->words[6] = 0
        | Addr << 0;
    seL4_Fault_ptr->words[7] = 0
        | IP << 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_IP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[7] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_IP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[7] &= ~0xffffffffffffffffull;
    seL4_Fault.words[7] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_IP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[7] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_IP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[7] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[7] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_Addr(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[6] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_Addr(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[6] &= ~0xffffffffffffffffull;
    seL4_Fault.words[6] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_Addr(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[6] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_Addr(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[6] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[6] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_InRecvPhase(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[5] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_InRecvPhase(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[5] &= ~0xffffffffffffffffull;
    seL4_Fault.words[5] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_InRecvPhase(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[5] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_InRecvPhase(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[5] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[5] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_LookupFailureType(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_LookupFailureType(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_LookupFailureType(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_LookupFailureType(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_MR4(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_MR4(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_MR4(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_MR4(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_MR5(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_MR5(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_MR5(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_MR5(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_CapFault_get_MR6(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_CapFault_set_MR6(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_CapFault_ptr_get_MR6(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_CapFault_ptr_set_MR6(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_CapFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_new(seL4_Uint64 FaultIP, seL4_Uint64 SP, seL4_Uint64 RA, seL4_Uint64 A0, seL4_Uint64 A1, seL4_Uint64 A2, seL4_Uint64 A3, seL4_Uint64 A4, seL4_Uint64 A5, seL4_Uint64 A6, seL4_Uint64 Syscall) {
    seL4_Fault_t seL4_Fault;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_UnknownSyscall & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UnknownSyscall & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UnknownSyscall & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | Syscall << 0;
    seL4_Fault.words[2] = 0
        | A6 << 0;
    seL4_Fault.words[3] = 0
        | A5 << 0;
    seL4_Fault.words[4] = 0
        | A4 << 0;
    seL4_Fault.words[5] = 0
        | A3 << 0;
    seL4_Fault.words[6] = 0
        | A2 << 0;
    seL4_Fault.words[7] = 0
        | A1 << 0;
    seL4_Fault.words[8] = 0
        | A0 << 0;
    seL4_Fault.words[9] = 0
        | RA << 0;
    seL4_Fault.words[10] = 0
        | SP << 0;
    seL4_Fault.words[11] = 0
        | FaultIP << 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 FaultIP, seL4_Uint64 SP, seL4_Uint64 RA, seL4_Uint64 A0, seL4_Uint64 A1, seL4_Uint64 A2, seL4_Uint64 A3, seL4_Uint64 A4, seL4_Uint64 A5, seL4_Uint64 A6, seL4_Uint64 Syscall) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_UnknownSyscall & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UnknownSyscall & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UnknownSyscall & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | Syscall << 0;
    seL4_Fault_ptr->words[2] = 0
        | A6 << 0;
    seL4_Fault_ptr->words[3] = 0
        | A5 << 0;
    seL4_Fault_ptr->words[4] = 0
        | A4 << 0;
    seL4_Fault_ptr->words[5] = 0
        | A3 << 0;
    seL4_Fault_ptr->words[6] = 0
        | A2 << 0;
    seL4_Fault_ptr->words[7] = 0
        | A1 << 0;
    seL4_Fault_ptr->words[8] = 0
        | A0 << 0;
    seL4_Fault_ptr->words[9] = 0
        | RA << 0;
    seL4_Fault_ptr->words[10] = 0
        | SP << 0;
    seL4_Fault_ptr->words[11] = 0
        | FaultIP << 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_FaultIP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[11] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_FaultIP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[11] &= ~0xffffffffffffffffull;
    seL4_Fault.words[11] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_FaultIP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[11] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_FaultIP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[11] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[11] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_SP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[10] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_SP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[10] &= ~0xffffffffffffffffull;
    seL4_Fault.words[10] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_SP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[10] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_SP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[10] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[10] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_RA(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[9] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_RA(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[9] &= ~0xffffffffffffffffull;
    seL4_Fault.words[9] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_RA(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[9] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_RA(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[9] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[9] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A0(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[8] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A0(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[8] &= ~0xffffffffffffffffull;
    seL4_Fault.words[8] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A0(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[8] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A0(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[8] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[8] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A1(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[7] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A1(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[7] &= ~0xffffffffffffffffull;
    seL4_Fault.words[7] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A1(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[7] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A1(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[7] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[7] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A2(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[6] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A2(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[6] &= ~0xffffffffffffffffull;
    seL4_Fault.words[6] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A2(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[6] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A2(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[6] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[6] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A3(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[5] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A3(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[5] &= ~0xffffffffffffffffull;
    seL4_Fault.words[5] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A3(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[5] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A3(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[5] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[5] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A4(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A4(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A4(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A4(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A5(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A5(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A5(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A5(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_A6(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_A6(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_A6(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_A6(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UnknownSyscall_get_Syscall(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UnknownSyscall_set_Syscall(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UnknownSyscall_ptr_get_Syscall(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UnknownSyscall_ptr_set_Syscall(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UnknownSyscall);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_new(seL4_Uint64 FaultIP, seL4_Uint64 SP, seL4_Uint64 Number, seL4_Uint64 Code) {
    seL4_Fault_t seL4_Fault;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_UserException & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UserException & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UserException & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | Code << 0;
    seL4_Fault.words[2] = 0
        | Number << 0;
    seL4_Fault.words[3] = 0
        | SP << 0;
    seL4_Fault.words[4] = 0
        | FaultIP << 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 FaultIP, seL4_Uint64 SP, seL4_Uint64 Number, seL4_Uint64 Code) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_UserException & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_UserException & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_UserException & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | Code << 0;
    seL4_Fault_ptr->words[2] = 0
        | Number << 0;
    seL4_Fault_ptr->words[3] = 0
        | SP << 0;
    seL4_Fault_ptr->words[4] = 0
        | FaultIP << 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UserException_get_FaultIP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[4] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_FaultIP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[4] &= ~0xffffffffffffffffull;
    seL4_Fault.words[4] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UserException_ptr_get_FaultIP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[4] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_FaultIP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[4] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[4] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UserException_get_SP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_SP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UserException_ptr_get_SP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_SP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UserException_get_Number(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_Number(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UserException_ptr_get_Number(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_Number(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_UserException_get_Code(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_UserException_set_Code(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_UserException_ptr_get_Code(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_UserException_ptr_set_Code(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_UserException);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_Timeout_new(seL4_Uint64 data, seL4_Uint64 consumed) {
    seL4_Fault_t seL4_Fault;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_Timeout & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_Timeout & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault.words[0] = 0
        | ((seL4_Uint64)seL4_Fault_Timeout & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | consumed << 0;
    seL4_Fault.words[2] = 0
        | data << 0;
    seL4_Fault.words[3] = 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_Timeout_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 data, seL4_Uint64 consumed) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_Timeout & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_Timeout & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] = 0
        | ((seL4_Uint64)seL4_Fault_Timeout & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | consumed << 0;
    seL4_Fault_ptr->words[2] = 0
        | data << 0;
    seL4_Fault_ptr->words[3] = 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_Timeout_get_data(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_Timeout_set_data(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_Timeout_ptr_get_data(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_Timeout_ptr_set_data(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_Timeout_get_consumed(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_Timeout_set_consumed(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_Timeout_ptr_get_consumed(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_Timeout_ptr_set_consumed(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_Timeout);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_new(seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 PrefetchFault, seL4_Uint64 FSR) {
    seL4_Fault_t seL4_Fault;

    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert((FSR & ~0x1full) == ((0 && (FSR & (1ull << 63))) ? 0x0 : 0));  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_VMFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_VMFault & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault.words[0] = 0
        | (FSR & 0x1full) << 27
        | ((seL4_Uint64)seL4_Fault_VMFault & 0xfull) << 0;
    seL4_Fault.words[1] = 0
        | PrefetchFault << 0;
    seL4_Fault.words[2] = 0
        | Addr << 0;
    seL4_Fault.words[3] = 0
        | IP << 0;
    seL4_Fault.words[4] = 0;
    seL4_Fault.words[5] = 0;
    seL4_Fault.words[6] = 0;
    seL4_Fault.words[7] = 0;
    seL4_Fault.words[8] = 0;
    seL4_Fault.words[9] = 0;
    seL4_Fault.words[10] = 0;
    seL4_Fault.words[11] = 0;

    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_new(seL4_Fault_t *seL4_Fault_ptr, seL4_Uint64 IP, seL4_Uint64 Addr, seL4_Uint64 PrefetchFault, seL4_Uint64 FSR) {
    /* fail if user has passed bits that we will override */  
    seL4_DebugAssert((FSR & ~0x1full) == ((0 && (FSR & (1ull << 63))) ? 0x0 : 0));  
    seL4_DebugAssert(((seL4_Uint64)seL4_Fault_VMFault & ~0xfull) == ((0 && ((seL4_Uint64)seL4_Fault_VMFault & (1ull << 63))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] = 0
        | (FSR & 0x1full) << 27
        | ((seL4_Uint64)seL4_Fault_VMFault & 0xfull) << 0;
    seL4_Fault_ptr->words[1] = 0
        | PrefetchFault << 0;
    seL4_Fault_ptr->words[2] = 0
        | Addr << 0;
    seL4_Fault_ptr->words[3] = 0
        | IP << 0;
    seL4_Fault_ptr->words[4] = 0;
    seL4_Fault_ptr->words[5] = 0;
    seL4_Fault_ptr->words[6] = 0;
    seL4_Fault_ptr->words[7] = 0;
    seL4_Fault_ptr->words[8] = 0;
    seL4_Fault_ptr->words[9] = 0;
    seL4_Fault_ptr->words[10] = 0;
    seL4_Fault_ptr->words[11] = 0;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_VMFault_get_IP(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_IP(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[3] &= ~0xffffffffffffffffull;
    seL4_Fault.words[3] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_VMFault_ptr_get_IP(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[3] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_IP(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[3] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[3] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_VMFault_get_Addr(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_Addr(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[2] &= ~0xffffffffffffffffull;
    seL4_Fault.words[2] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_VMFault_ptr_get_Addr(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[2] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_Addr(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[2] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[2] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_VMFault_get_PrefetchFault(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_PrefetchFault(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[1] &= ~0xffffffffffffffffull;
    seL4_Fault.words[1] |= (v64 << 0) & 0xffffffffffffffffull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_VMFault_ptr_get_PrefetchFault(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[1] & 0xffffffffffffffffull) >> 0;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_PrefetchFault(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xffffffffffffffffull >> 0) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[1] &= ~0xffffffffffffffffull;
    seL4_Fault_ptr->words[1] |= (v64 << 0) & 0xffffffffffffffffull;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 CONST
seL4_Fault_VMFault_get_FSR(seL4_Fault_t seL4_Fault) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault.words[0] & 0xf8000000ull) >> 27;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC seL4_Fault_t CONST
seL4_Fault_VMFault_set_FSR(seL4_Fault_t seL4_Fault, seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault.words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);
    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xf8000000ull >> 27 ) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault.words[0] &= ~0xf8000000ull;
    seL4_Fault.words[0] |= (v64 << 27) & 0xf8000000ull;
    return seL4_Fault;
}

LIBSEL4_INLINE_FUNC seL4_Uint64 PURE
seL4_Fault_VMFault_ptr_get_FSR(seL4_Fault_t *seL4_Fault_ptr) {
    seL4_Uint64 ret;
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    ret = (seL4_Fault_ptr->words[0] & 0xf8000000ull) >> 27;
    /* Possibly sign extend */
    if (__builtin_expect(!!(0 && (ret & (1ull << (63)))), 0)) {
        ret |= 0x0;
    }
    return ret;
}

LIBSEL4_INLINE_FUNC void
seL4_Fault_VMFault_ptr_set_FSR(seL4_Fault_t *seL4_Fault_ptr,
                                      seL4_Uint64 v64) {
    seL4_DebugAssert(((seL4_Fault_ptr->words[0] >> 0) & 0xf) ==
           seL4_Fault_VMFault);

    /* fail if user has passed bits that we will override */
    seL4_DebugAssert((((~0xf8000000ull >> 27) | 0x0) & v64) == ((0 && (v64 & (1ull << (63)))) ? 0x0 : 0));

    seL4_Fault_ptr->words[0] &= ~0xf8000000ull;
    seL4_Fault_ptr->words[0] |= (v64 << 27) & 0xf8000000ull;
}

