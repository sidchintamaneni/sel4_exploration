
/*
 * Automatically generated system call stubs.
 */

#pragma once

#include <sel4/config.h>
#include <sel4/types.h>
#include <sel4/sel4_arch/constants.h>

/*
 * The following code generates a compile-time error if the system call
 * stub generator has an incorrect understanding of how large a type is.
 *
 * If you receive a compile-time error here, you will need to adjust
 * the type information in the stub generator.
 */
#define assert_size_correct(type, expected_bytes) \
        typedef unsigned long __type_##type##_size_incorrect[ \
                (sizeof(type) == expected_bytes) ? 1 : -1]

assert_size_correct(int, 4);
assert_size_correct(long, 8);
assert_size_correct(seL4_Uint8, 1);
assert_size_correct(seL4_Uint16, 2);
assert_size_correct(seL4_Uint32, 4);
assert_size_correct(seL4_Uint64, 8);
assert_size_correct(seL4_Time, 8);
assert_size_correct(seL4_Word, 8);
assert_size_correct(seL4_Bool, 1);
assert_size_correct(seL4_CapRights_t, 8);
assert_size_correct(seL4_CPtr, 8);
assert_size_correct(seL4_CNode, 8);
assert_size_correct(seL4_IRQHandler, 8);
assert_size_correct(seL4_IRQControl, 8);
assert_size_correct(seL4_TCB, 8);
assert_size_correct(seL4_Untyped, 8);
assert_size_correct(seL4_DomainSet, 8);
assert_size_correct(seL4_SchedContext, 8);
assert_size_correct(seL4_SchedControl, 8);
assert_size_correct(seL4_RISCV_VMAttributes, 8);
assert_size_correct(seL4_RISCV_Page, 8);
assert_size_correct(seL4_RISCV_PageTable, 8);
assert_size_correct(seL4_RISCV_ASIDControl, 8);
assert_size_correct(seL4_RISCV_ASIDPool, 8);
assert_size_correct(seL4_UserContext, 256);

/*
 * Return types for generated methods.
 */
struct seL4_RISCV_Page_GetAddress {
	int error;
	seL4_Word paddr;
};
typedef struct seL4_RISCV_Page_GetAddress seL4_RISCV_Page_GetAddress_t;

struct seL4_TCB_GetBreakpoint {
	int error;
	seL4_Word vaddr;
	seL4_Word type;
	seL4_Word size;
	seL4_Word rw;
	seL4_Bool is_enabled;
};
typedef struct seL4_TCB_GetBreakpoint seL4_TCB_GetBreakpoint_t;

struct seL4_TCB_ConfigureSingleStepping {
	int error;
	seL4_Bool bp_was_consumed;
};
typedef struct seL4_TCB_ConfigureSingleStepping seL4_TCB_ConfigureSingleStepping_t;

struct seL4_SchedContext_Consumed {
	int error;
	seL4_Time consumed;
};
typedef struct seL4_SchedContext_Consumed seL4_SchedContext_Consumed_t;

struct seL4_SchedContext_YieldTo {
	int error;
	seL4_Time consumed;
};
typedef struct seL4_SchedContext_YieldTo seL4_SchedContext_YieldTo_t;

/*
 * Generated stubs.
 */
/**
 * @xmlonly <manual name="Map" label="riscv_pagetable_map"/> @endxmlonly
 * @brief @xmlonly Map a page table at a specific virtual address. @endxmlonly
 * 
 * @xmlonly
 * Starting from the VSpace, map the page table object at any unpopulated level for the provided virtual address. If all paging structures and mappings are present for this virtual address, return an seL4_DeleteFirst error.
 * @endxmlonly
 * 
 * @param[in] _service Capability to the page table to invoke.
 * @param[in] vspace VSpace to map the lower-level page table into. 
 * @param[in] vaddr Virtual address at which to map the page table. 
 * @param[in] attr VM Attributes for the mapping.  @xmlonly <docref>Possible values for this type are given
 * in <autoref label="ch:vspace"/>.</docref> @endxmlonly 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst A page is mapped in  @xmlonly <texttt text="vspace"/> @endxmlonly  at  @xmlonly <texttt text="vaddr"/> @endxmlonly .
 * Or, all required page tables are already mapped in  @xmlonly <texttt text="vspace"/> @endxmlonly  at  @xmlonly <texttt text="vaddr"/> @endxmlonly . 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="vspace"/> @endxmlonly  is not assigned to an ASID pool. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidArgument The  @xmlonly <texttt text="vaddr"/> @endxmlonly  is in the kernel virtual address range. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="vspace"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace"/> @endxmlonly  is not assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is already mapped in a VSpace. 
 */
LIBSEL4_INLINE seL4_Error
seL4_RISCV_PageTable_Map(seL4_RISCV_PageTable _service, seL4_RISCV_PageTable vspace, seL4_Word vaddr, seL4_RISCV_VMAttributes attr)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVPageTableMap, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, vspace);

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = attr;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Unmap" label="riscv_pagetable_unmap"/> @endxmlonly
 * @brief @xmlonly Unmap a page table. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="ch:vspace"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the page table to invoke.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="_service"/> @endxmlonly  is the root of a VSpace.
 * Or, a copy of the  @xmlonly <texttt text="_service"/> @endxmlonly  capability exists. 
 */
LIBSEL4_INLINE seL4_Error
seL4_RISCV_PageTable_Unmap(seL4_RISCV_PageTable _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVPageTableUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Map" label="riscv_page_map"/> @endxmlonly
 * @brief @xmlonly Map a page into a page table. @endxmlonly
 * 
 * @xmlonly
 * Takes a VSpace, or top-level <texttt text="Page Table"/>,
 * capability as an argument and installs a reference
 * to the given <texttt text="Page"/> in the page table slot corresponding to the given address. If a page is already mapped at the same virtual address, update the mapping attributes.
 * If the required paging structures are not present
 * this operation will fail, returning a seL4_FailedLookup error.
 * @endxmlonly
 * 
 * @param[in] _service Capability to the page to invoke.
 * @param[in] vspace VSpace to map the page into. 
 * @param[in] vaddr Virtual address at which to map the page. 
 * @param[in] rights Rights for the mapping.  @xmlonly <docref>Possible values for this type are given in <autoref label="sec:cap_rights"/>.</docref> @endxmlonly 
 * @param[in] attr VM Attributes for the mapping.  @xmlonly <docref>Possible values for this type are given
 * in <autoref label="ch:vspace"/>.</docref> @endxmlonly 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_AlignmentError The  @xmlonly <texttt text="vaddr"/> @endxmlonly  is not aligned to the page size of  @xmlonly <texttt text="_service"/> @endxmlonly . 
 * @retval seL4_DeleteFirst A mapping already exists in  @xmlonly <texttt text="vspace"/> @endxmlonly  at  @xmlonly <texttt text="vaddr"/> @endxmlonly . 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="vspace"/> @endxmlonly  does not have a paging structure at the required level mapped at  @xmlonly <texttt text="vaddr"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="vspace"/> @endxmlonly  is not assigned to an ASID pool. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidArgument The  @xmlonly <texttt text="_service"/> @endxmlonly  is already mapped in  @xmlonly <texttt text="vspace"/> @endxmlonly  at a different virtual address.
 * Or,  @xmlonly <texttt text="vaddr"/> @endxmlonly  is in the kernel virtual address range. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="vspace"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace"/> @endxmlonly  is not the root of a VSpace.
 * Or,  @xmlonly <texttt text="vspace"/> @endxmlonly  is not assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is already mapped in a different VSpace. 
 */
LIBSEL4_INLINE seL4_Error
seL4_RISCV_Page_Map(seL4_RISCV_Page _service, seL4_RISCV_PageTable vspace, seL4_Word vaddr, seL4_CapRights_t rights, seL4_RISCV_VMAttributes attr)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVPageMap, 0, 1, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, vspace);

	/* Marshal and initialise parameters. */
	mr0 = vaddr;
	mr1 = rights.words[0];
	mr2 = attr;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Unmap" label="riscv_page_unmap"/> @endxmlonly
 * @brief @xmlonly Unmap a page. @endxmlonly
 * 
 * @xmlonly
 * Removes an existing mapping.
 * @endxmlonly
 * 
 * @param[in] _service Capability to the page to invoke.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_RISCV_Page_Unmap(seL4_RISCV_Page _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVPageUnmap, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Get Address" label="riscv_page_get_address"/> @endxmlonly
 * @brief @xmlonly Get the physical address of a page. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="ch:vspace"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the page to invoke.
 * @return @xmlonly 
 *                 A <texttt text="seL4_RISCV_Page_GetAddress_t"/> struct that contains a
 *                 <texttt text="seL4_Word paddr"/>, which holds the physical address of the page,
 *                 and <texttt text="int error"/>. <docref>See <autoref label="sec:errors"/> for a description
 *                 of the message register and tag contents upon error.</docref>
 *              @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_RISCV_Page_GetAddress_t
seL4_RISCV_Page_GetAddress(seL4_RISCV_Page _service)
{
	seL4_RISCV_Page_GetAddress_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVPageGetAddress, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
		return result;
	}

	/* Unmarshal result. */
	result.paddr = mr0;
	return result;
}

/**
 * @xmlonly <manual name="Make Pool" label="riscv_asid_control_make_pool"/> @endxmlonly
 * @brief @xmlonly Create an ASID Pool. @endxmlonly
 * 
 * @xmlonly
 * Together with a capability to <texttt text="Untyped Memory"/>, which is passed as an argument,
 * create an <texttt text="ASID Pool"/>. The untyped capability must represent a
 * 4K memory object. This will create an ASID pool with enough space for 1024 VSpaces.
 * @endxmlonly
 * 
 * @param[in] _service The master ASIDControl capability to invoke.
 * @param[in] untyped Capability to an untyped memory object that will become the pool. Must be 4K bytes. 
 * @param[in] root CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] depth Number of bits of index to resolve to find the destination slot. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability.
 * Or, there are no more ASID pools available. 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="index"/> @endxmlonly  or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="root"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="untyped"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="untyped"/> @endxmlonly  is not the exact size of an ASID pool object.
 * Or,  @xmlonly <texttt text="untyped"/> @endxmlonly  is a device untyped  @xmlonly <docref>(see <autoref label="sec:kernmemalloc"/>)</docref> @endxmlonly . 
 * @retval seL4_RangeError The  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="untyped"/> @endxmlonly  has been used to retype an object.
 * Or, a copy of the  @xmlonly <texttt text="untyped"/> @endxmlonly  capability exists. 
 */
LIBSEL4_INLINE seL4_Error
seL4_RISCV_ASIDControl_MakePool(seL4_RISCV_ASIDControl _service, seL4_Untyped untyped, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVASIDControlMakePool, 0, 2, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, untyped);
	seL4_SetCap(1, root);

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xffull);
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Assign" label="riscv_asid_pool_assign"/> @endxmlonly
 * @brief @xmlonly Assign an ASID Pool. @endxmlonly
 * 
 * @xmlonly
 * Assigns an ASID to the VSpace passed in as an argument.
 * @endxmlonly
 * 
 * @param[in] _service The ASID Pool capability to invoke, which must be to an ASID pool that is not full.
 * @param[in] vspace The top-level  @xmlonly <texttt text="PageTable"/> @endxmlonly  that is being assigned to an ASID pool. Must not already be assigned
 * to an ASID pool. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst There are no more ASIDs available in  @xmlonly <texttt text="_service"/> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="vspace"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace"/> @endxmlonly  is already assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="vspace"/> @endxmlonly  is mapped in a VSpace. 
 */
LIBSEL4_INLINE seL4_Error
seL4_RISCV_ASIDPool_Assign(seL4_RISCV_ASIDPool _service, seL4_CPtr vspace)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVASIDPoolAssign, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, vspace);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Get IRQ Handler with Trigger Type" label="riscv_irq_controlgettrigger"/> @endxmlonly
 * @brief @xmlonly Create an IRQ handler capability and specify the trigger method (edge or level). @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:interrupts"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service An IRQControl capability. This gives you the authority to make this call.
 * @param[in] irq The IRQ that you want this capability to handle. 
 * @param[in] trigger Indicates whether this IRQ is edge (1) or level (0) triggered. 
 * @param[in] root CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] depth Number of bits of index to resolve to find the destination slot. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="index"/> @endxmlonly  or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="root"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the platform does not support setting the IRQ trigger. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="irq"/> @endxmlonly  is invalid.
 * Or,  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_RevokeFirst An IRQ handler capability for  @xmlonly <texttt text="irq"/> @endxmlonly  has already been created. 
 */
LIBSEL4_INLINE seL4_Error
seL4_IRQControl_GetTrigger(seL4_IRQControl _service, seL4_Word irq, seL4_Word trigger, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(RISCVIRQIssueIRQHandlerTrigger, 0, 1, 4);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = irq;
	mr1 = trigger;
	mr2 = index;
	mr3 = (depth & 0xffull);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Retype" label="untyped_retype"/> @endxmlonly
 * @brief @xmlonly Retype an untyped object @endxmlonly
 * 
 * @xmlonly
 * Given a capability, <texttt text="_service"/>, to an untyped object,
 * creates <texttt text="num_objects"/> of the requested type. Creates
 * <texttt text="num_objects"/> capabilities to the new objects starting
 * at <texttt text="node_offset"/> in the CNode specified by
 * <texttt text="root"/>, <texttt text="node_index"/>, and
 * <texttt text="node_depth"/>.
 * 
 * For variable-sized
 * kernel objects, the <texttt text="size_bits"/> argument is used to
 * determine the size of objects to create. The relationship between
 * <texttt text="size_bits"/> and object size depends on the type of object
 * being created. <docref>See <autoref label="sec:object_sizes"/> for more information
 * about object sizes.</docref>
 * 
 * <docref>See <autoref label="sec:kernmemalloc"/> for more information about how untyped
 * memory is retyped.</docref>
 * 
 * <docref>See <autoref label="sec:caps_to_new_objects"/> for more information about the
 * placement of capabilities to created objects.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to an untyped object.
 * @param[in] type The seL4 object type that we are retyping to. 
 * @param[in] size_bits Used to determine the size of variable-sized objects. 
 * @param[in] root CPtr to the CNode at the root of the destination CSpace. 
 * @param[in] node_index CPtr to the destination CNode. Resolved relative to the root parameter. 
 * @param[in] node_depth Number of bits of node_index to translate when addressing the destination CNode. 
 * @param[in] node_offset Number of slots into the node at which capabilities start being placed. 
 * @param[in] num_objects Number of capabilities to create. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst A capability exists in the destination window of the CNode. 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="root"/> @endxmlonly ,  @xmlonly <texttt text="node_index"/> @endxmlonly , or  @xmlonly <texttt text="node_depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidArgument The  @xmlonly <texttt text="size_bits"/> @endxmlonly  is too big or too small for the requested object type.
 * Or,  @xmlonly <texttt text="type"/> @endxmlonly  cannot be created from a device untyped  @xmlonly <docref>(see <autoref label="sec:kernmemalloc"/>)</docref> @endxmlonly .
 * Or, the requested object  @xmlonly <texttt text="type"/> @endxmlonly  does not exist. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_NotEnoughMemory The total size of the new objects exceeds the space available. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="num_objects"/> @endxmlonly  do not fit in the destination CNode at  @xmlonly <texttt text="node_offset"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="num_objects"/> @endxmlonly  is greater than  @xmlonly <texttt text="CONFIG_RETYPE_FAN_OUT_LIMIT"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="size_bits"/> @endxmlonly  is too large. 
 */
LIBSEL4_INLINE seL4_Error
seL4_Untyped_Retype(seL4_Untyped _service, seL4_Word type, seL4_Word size_bits, seL4_CNode root, seL4_Word node_index, seL4_Word node_depth, seL4_Word node_offset, seL4_Word num_objects)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(UntypedRetype, 0, 1, 6);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = type;
	mr1 = size_bits;
	mr2 = node_index;
	mr3 = node_depth;
	seL4_SetMR(4, node_offset);
	seL4_SetMR(5, num_objects);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Read Registers" label="tcb_readregisters"/> @endxmlonly
 * @brief @xmlonly Read a thread's registers into the first <texttt text="count"/> fields of a given
 * seL4_UserContext @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:read_write_registers"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] suspend_source The invocation should also suspend the source thread. 
 * @param[in] arch_flags Architecture dependent flags. These have no meaning on x86, ARM, and RISC-V. 
 * @param[in] count The number of registers to read. 
 * @param[out] regs The structure to read the registers into. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is the current thread's TCB. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="count"/> @endxmlonly  requested too few or too many registers. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_ReadRegisters(seL4_TCB _service, seL4_Bool suspend_source, seL4_Uint8 arch_flags, seL4_Word count, seL4_UserContext *regs)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBReadRegisters, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = (suspend_source & 0x1ull) | ((arch_flags & 0xffull) << 8);
	mr1 = count;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	/* Unmarshal result. */
	regs->pc = mr0;
	regs->ra = mr1;
	regs->sp = mr2;
	regs->gp = mr3;
	regs->s0 = seL4_GetMR(4);
	regs->s1 = seL4_GetMR(5);
	regs->s2 = seL4_GetMR(6);
	regs->s3 = seL4_GetMR(7);
	regs->s4 = seL4_GetMR(8);
	regs->s5 = seL4_GetMR(9);
	regs->s6 = seL4_GetMR(10);
	regs->s7 = seL4_GetMR(11);
	regs->s8 = seL4_GetMR(12);
	regs->s9 = seL4_GetMR(13);
	regs->s10 = seL4_GetMR(14);
	regs->s11 = seL4_GetMR(15);
	regs->a0 = seL4_GetMR(16);
	regs->a1 = seL4_GetMR(17);
	regs->a2 = seL4_GetMR(18);
	regs->a3 = seL4_GetMR(19);
	regs->a4 = seL4_GetMR(20);
	regs->a5 = seL4_GetMR(21);
	regs->a6 = seL4_GetMR(22);
	regs->a7 = seL4_GetMR(23);
	regs->t0 = seL4_GetMR(24);
	regs->t1 = seL4_GetMR(25);
	regs->t2 = seL4_GetMR(26);
	regs->t3 = seL4_GetMR(27);
	regs->t4 = seL4_GetMR(28);
	regs->t5 = seL4_GetMR(29);
	regs->t6 = seL4_GetMR(30);
	regs->tp = seL4_GetMR(31);
	return result;
}

/**
 * @xmlonly <manual name="Write Registers" label="tcb_writeregisters"/> @endxmlonly
 * @brief @xmlonly Set a thread's registers to the first <texttt text="count"/> fields of a given seL4_UserContext @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:read_write_registers"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] resume_target The invocation should also resume the destination thread. 
 * @param[in] arch_flags Architecture dependent flags. These have no meaning on x86, ARM, and RISC-V. 
 * @param[in] count The number of registers to be set. 
 * @param[in] regs Data structure containing the new register values. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is the current thread's TCB. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_WriteRegisters(seL4_TCB _service, seL4_Bool resume_target, seL4_Uint8 arch_flags, seL4_Word count, seL4_UserContext *regs)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBWriteRegisters, 0, 0, 34);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = (resume_target & 0x1ull) | ((arch_flags & 0xffull) << 8);
	mr1 = count;
	mr2 = regs->pc;
	mr3 = regs->ra;
	seL4_SetMR(4, regs->sp);
	seL4_SetMR(5, regs->gp);
	seL4_SetMR(6, regs->s0);
	seL4_SetMR(7, regs->s1);
	seL4_SetMR(8, regs->s2);
	seL4_SetMR(9, regs->s3);
	seL4_SetMR(10, regs->s4);
	seL4_SetMR(11, regs->s5);
	seL4_SetMR(12, regs->s6);
	seL4_SetMR(13, regs->s7);
	seL4_SetMR(14, regs->s8);
	seL4_SetMR(15, regs->s9);
	seL4_SetMR(16, regs->s10);
	seL4_SetMR(17, regs->s11);
	seL4_SetMR(18, regs->a0);
	seL4_SetMR(19, regs->a1);
	seL4_SetMR(20, regs->a2);
	seL4_SetMR(21, regs->a3);
	seL4_SetMR(22, regs->a4);
	seL4_SetMR(23, regs->a5);
	seL4_SetMR(24, regs->a6);
	seL4_SetMR(25, regs->a7);
	seL4_SetMR(26, regs->t0);
	seL4_SetMR(27, regs->t1);
	seL4_SetMR(28, regs->t2);
	seL4_SetMR(29, regs->t3);
	seL4_SetMR(30, regs->t4);
	seL4_SetMR(31, regs->t5);
	seL4_SetMR(32, regs->t6);
	seL4_SetMR(33, regs->tp);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Copy Registers" label="tcb_copyregisters"/> @endxmlonly
 * @brief @xmlonly Copy the registers from one thread to another @endxmlonly
 * 
 * @xmlonly
 * In the context of this function, frame registers are those that are read, modified or preserved by a
 * system call and integer registers are those that are not. Refer to the seL4 userland library source for specifics.
 * <docref><autoref label="sec:thread_deactivation"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on. This is the destination TCB.
 * @param[in] source Cap to the source TCB. 
 * @param[in] suspend_source The invocation should also suspend the source thread. 
 * @param[in] resume_target The invocation should also resume the destination thread. 
 * @param[in] transfer_frame Frame registers should be transferred. 
 * @param[in] transfer_integer Integer registers should be transferred. 
 * @param[in] arch_flags Architecture dependent flags. These have no meaning on x86, ARM, and RISC-V. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="source"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_CopyRegisters(seL4_TCB _service, seL4_TCB source, seL4_Bool suspend_source, seL4_Bool resume_target, seL4_Bool transfer_frame, seL4_Bool transfer_integer, seL4_Uint8 arch_flags)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBCopyRegisters, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, source);

	/* Marshal and initialise parameters. */
	mr0 = (suspend_source & 0x1ull) | ((resume_target & 0x1ull) << 1) | ((transfer_frame & 0x1ull) << 2) | ((transfer_integer & 0x1ull) << 3) | ((arch_flags & 0xffull) << 8);
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#if !defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Configure" label="tcb_configure"/> @endxmlonly
 * @brief @xmlonly Set the parameters of a TCB @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] fault_ep CPtr to the endpoint which receives IPCs when this thread faults. This capability is in the CSpace of the thread being configured. 
 * @param[in] cspace_root The new CSpace root. 
 * @param[in] cspace_root_data Optionally set the guard and guard size of the new root CNode. If set to zero, this parameter has no effect. 
 * @param[in] vspace_root The new VSpace root. 
 * @param[in] vspace_root_data Has no effect on x86 or ARM processors. 
 * @param[in] buffer Location of the thread's IPC buffer. Must be 512-byte aligned. The IPC buffer may not cross a page boundary. 
 * @param[in] bufferFrame Capability to a page containing the thread's IPC buffer. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly ,  @xmlonly <texttt text="bufferFrame"/> @endxmlonly ,  @xmlonly <texttt text="cspace_root"/> @endxmlonly , or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is not assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="cspace_root_data"/> @endxmlonly  is invalid.
 * Or,  @xmlonly <texttt text="buffer"/> @endxmlonly  is not aligned.
 * Or,  @xmlonly <texttt text="bufferFrame"/> @endxmlonly  is retyped from a device untyped  @xmlonly <docref>(see <autoref label="sec:kernmemalloc"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="bufferFrame"/> @endxmlonly ,  @xmlonly <texttt text="cspace_root"/> @endxmlonly , or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_Configure(seL4_TCB _service, seL4_Word fault_ep, seL4_CNode cspace_root, seL4_Word cspace_root_data, seL4_CPtr vspace_root, seL4_Word vspace_root_data, seL4_Word buffer, seL4_CPtr bufferFrame)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBConfigure, 0, 3, 4);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, cspace_root);
	seL4_SetCap(1, vspace_root);
	seL4_SetCap(2, bufferFrame);

	/* Marshal and initialise parameters. */
	mr0 = fault_ep;
	mr1 = cspace_root_data;
	mr2 = vspace_root_data;
	mr3 = buffer;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Configure (MCS)" label="tcb_configure_mcs"/> @endxmlonly
 * @brief @xmlonly Set the parameters of a TCB @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] cspace_root The new CSpace root. 
 * @param[in] cspace_root_data Optionally set the guard and guard size of the new root CNode. If set to zero, this parameter has no effect. 
 * @param[in] vspace_root The new VSpace root. 
 * @param[in] vspace_root_data Has no effect on x86 or ARM processors. 
 * @param[in] buffer Location of the thread's IPC buffer. Must be 512-byte aligned. The IPC buffer may not cross a page boundary. 
 * @param[in] bufferFrame Capability to a page containing the thread's IPC buffer. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_AlignmentError The  @xmlonly <texttt text="buffer"/> @endxmlonly  is not aligned. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly ,  @xmlonly <texttt text="bufferFrame"/> @endxmlonly ,  @xmlonly <texttt text="cspace_root"/> @endxmlonly , or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is not assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="cspace_root_data"/> @endxmlonly  is invalid.
 * Or,  @xmlonly <texttt text="bufferFrame"/> @endxmlonly  is retyped from a device untyped  @xmlonly <docref>(see <autoref label="sec:kernmemalloc"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="bufferFrame"/> @endxmlonly ,  @xmlonly <texttt text="cspace_root"/> @endxmlonly , or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_Configure(seL4_TCB _service, seL4_CNode cspace_root, seL4_Word cspace_root_data, seL4_CPtr vspace_root, seL4_Word vspace_root_data, seL4_Word buffer, seL4_CPtr bufferFrame)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBConfigure, 0, 3, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, cspace_root);
	seL4_SetCap(1, vspace_root);
	seL4_SetCap(2, bufferFrame);

	/* Marshal and initialise parameters. */
	mr0 = cspace_root_data;
	mr1 = vspace_root_data;
	mr2 = buffer;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
/**
 * @xmlonly <manual name="Set Priority" label="tcb_setpriority"/> @endxmlonly
 * @brief @xmlonly Change a thread's priority @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:sched"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] authority Capability to the TCB to use the MCP from when setting the priority. 
 * @param[in] priority The thread's new priority. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="authority"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="priority"/> @endxmlonly  is greater than the maximum controlled priority of  @xmlonly <texttt text="authority"/> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetPriority(seL4_TCB _service, seL4_TCB authority, seL4_Word priority)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetPriority, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, authority);

	/* Marshal and initialise parameters. */
	mr0 = priority;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Set Maximum Controlled Priority" label="tcb_setmcpriority"/> @endxmlonly
 * @brief @xmlonly Change a thread's maximum controlled priority @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:sched"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] authority Capability to the TCB to use the MCP from when setting the MCP. 
 * @param[in] mcp The thread's new maximum controlled priority. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="authority"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="mcp"/> @endxmlonly  is greater than the maximum controlled priority of  @xmlonly <texttt text="authority"/> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetMCPriority(seL4_TCB _service, seL4_TCB authority, seL4_Word mcp)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetMCPriority, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, authority);

	/* Marshal and initialise parameters. */
	mr0 = mcp;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#if !defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Set Sched Params" label="tcb_setschedparams"/> @endxmlonly
 * @brief @xmlonly Change a thread's priority and maximum controlled priority. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:sched"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] authority Capability to the TCB to use the MCP from when setting the priority and MCP. 
 * @param[in] mcp The thread's new maximum controlled priority. 
 * @param[in] priority The thread's new priority. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="authority"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="mcp"/> @endxmlonly  is greater than the maximum controlled priority of  @xmlonly <texttt text="authority"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="priority"/> @endxmlonly  is greater than the maximum controlled priority of  @xmlonly <texttt text="authority"/> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetSchedParams(seL4_TCB _service, seL4_TCB authority, seL4_Word mcp, seL4_Word priority)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetSchedParams, 0, 1, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, authority);

	/* Marshal and initialise parameters. */
	mr0 = mcp;
	mr1 = priority;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Set Sched Params (MCS)" label="tcb_setschedparams_mcs"/> @endxmlonly
 * @brief @xmlonly Change a thread's priority, maximum controlled priority, scheduling context
 * and fault handler. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:sched"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] authority Capability to the TCB to use the MCP from when setting the priority and MCP. 
 * @param[in] mcp The thread's new maximum controlled priority. 
 * @param[in] priority The thread's new priority. 
 * @param[in] sched_context Capability to the scheduling context that the TCB should run on. If the scheduling context is already bound to a notification or TCB that is not this TCB this operation will fail. Similarly, if this TCB is already bound to a scheduling context that is not this scheduling context, this will also fail. 
 * @param[in] fault_ep CPtr to the endpoint which receives IPCs when this thread faults. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="sched_context"/> @endxmlonly  is already bound.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is the current thread's TCB.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is a TCB in the blocked state and  @xmlonly <texttt text="sched_context"/> @endxmlonly  is not schedulable. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly ,  @xmlonly <texttt text="authority"/> @endxmlonly ,  @xmlonly <texttt text="sched_context"/> @endxmlonly , or  @xmlonly <texttt text="fault_ep"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="fault_ep"/> @endxmlonly  does not have both Write rights and either Grant or GrantReply rights to the Endpoint  @xmlonly <docref>(see <autoref label="sec:cap_rights"/>)</docref> @endxmlonly . 
 * @retval seL4_RangeError The  @xmlonly <texttt text="mcp"/> @endxmlonly  is greater than the maximum controlled priority of  @xmlonly <texttt text="authority"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="priority"/> @endxmlonly  is greater than the maximum controlled priority of  @xmlonly <texttt text="authority"/> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetSchedParams(seL4_TCB _service, seL4_TCB authority, seL4_Word mcp, seL4_Word priority, seL4_CPtr sched_context, seL4_CPtr fault_ep)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetSchedParams, 0, 3, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, authority);
	seL4_SetCap(1, sched_context);
	seL4_SetCap(2, fault_ep);

	/* Marshal and initialise parameters. */
	mr0 = mcp;
	mr1 = priority;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Set Timeout Endpoint" label="tcb_settimeoutendpoint"/> @endxmlonly
 * @brief @xmlonly Set a thread's timeout endpoint. @endxmlonly
 * 
 * @xmlonly
 * Timeout exception messages will be delivered to this endpoint if it is not a null capability.
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] timeout_fault_ep CPtr to the endpoint which receives IPCs when this thread triggers timeout faults. Can be null. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="timeout_fault_ep"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="timeout_fault_ep"/> @endxmlonly  does not have both Write rights and either Grant or GrantReply rights to the Endpoint  @xmlonly <docref>(see <autoref label="sec:cap_rights"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetTimeoutEndpoint(seL4_TCB _service, seL4_CPtr timeout_fault_ep)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetTimeoutEndpoint, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, timeout_fault_ep);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
/**
 * @xmlonly <manual name="Set IPC Buffer" label="tcb_setipcbuffer"/> @endxmlonly
 * @brief @xmlonly Set a thread's IPC buffer @endxmlonly
 * 
 * @xmlonly
 * See Sections <shortref sec="threads"/> and <shortref sec="messageinfo"/>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] buffer Location of the thread's IPC buffer. Must be 512-byte aligned. The IPC buffer may not cross a page boundary. 
 * @param[in] bufferFrame Capability to a page containing the thread's IPC buffer. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_AlignmentError The  @xmlonly <texttt text="buffer"/> @endxmlonly  is not aligned. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="bufferFrame"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="bufferFrame"/> @endxmlonly  is retyped from a device untyped  @xmlonly <docref>(see <autoref label="sec:kernmemalloc"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="bufferFrame"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetIPCBuffer(seL4_TCB _service, seL4_Word buffer, seL4_CPtr bufferFrame)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetIPCBuffer, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, bufferFrame);

	/* Marshal and initialise parameters. */
	mr0 = buffer;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#if !defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Set Space" label="tcb_setspace"/> @endxmlonly
 * @brief @xmlonly Set the fault endpoint, CSpace and VSpace of a thread @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] fault_ep CPtr to the endpoint which receives IPCs when this thread faults. This capability is in the CSpace of the thread being configured. 
 * @param[in] cspace_root The new CSpace root. 
 * @param[in] cspace_root_data Optionally set the guard and guard size of the new root CNode. If set to zero, this parameter has no effect. 
 * @param[in] vspace_root The new VSpace root. 
 * @param[in] vspace_root_data Has no effect on x86 or ARM processors. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly ,  @xmlonly <texttt text="cspace_root"/> @endxmlonly , or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is not assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="cspace_root_data"/> @endxmlonly  is invalid. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="cspace_root"/> @endxmlonly  or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetSpace(seL4_TCB _service, seL4_Word fault_ep, seL4_CNode cspace_root, seL4_Word cspace_root_data, seL4_CPtr vspace_root, seL4_Word vspace_root_data)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetSpace, 0, 2, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, cspace_root);
	seL4_SetCap(1, vspace_root);

	/* Marshal and initialise parameters. */
	mr0 = fault_ep;
	mr1 = cspace_root_data;
	mr2 = vspace_root_data;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Set Space (MCS)" label="tcb_setspace_mcs"/> @endxmlonly
 * @brief @xmlonly Set the fault endpoint, CSpace and VSpace of a thread @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] fault_ep CPtr to the endpoint which receives IPCs when this thread faults. On MCS this cap gets copied into the TCB. 
 * @param[in] cspace_root The new CSpace root. 
 * @param[in] cspace_root_data Optionally set the guard and guard size of the new root CNode. If set to zero, this parameter has no effect. 
 * @param[in] vspace_root The new VSpace root. 
 * @param[in] vspace_root_data Has no effect on x86 or ARM processors. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly ,  @xmlonly <texttt text="cspace_root"/> @endxmlonly , or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is not assigned to an ASID pool.
 * Or,  @xmlonly <texttt text="cspace_root_data"/> @endxmlonly  is invalid. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="fault_ep"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="fault_ep"/> @endxmlonly  does not have both Write rights and either Grant or GrantReply rights to the Endpoint  @xmlonly <docref>(see <autoref label="sec:cap_rights"/>)</docref> @endxmlonly . 
 * @retval seL4_RevokeFirst The  @xmlonly <texttt text="cspace_root"/> @endxmlonly  or  @xmlonly <texttt text="vspace_root"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetSpace(seL4_TCB _service, seL4_CPtr fault_ep, seL4_CNode cspace_root, seL4_Word cspace_root_data, seL4_CPtr vspace_root, seL4_Word vspace_root_data)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetSpace, 0, 3, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, fault_ep);
	seL4_SetCap(1, cspace_root);
	seL4_SetCap(2, vspace_root);

	/* Marshal and initialise parameters. */
	mr0 = cspace_root_data;
	mr1 = vspace_root_data;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
/**
 * @xmlonly <manual name="Suspend" label="tcb_suspend"/> @endxmlonly
 * @brief @xmlonly Suspend a thread @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:thread_deactivation"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_Suspend(seL4_TCB _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSuspend, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Resume" label="tcb_resume"/> @endxmlonly
 * @brief @xmlonly Resume a thread @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:thread_deactivation"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_Resume(seL4_TCB _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBResume, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Bind Notification" label="tcb_bindnotification"/> @endxmlonly
 * @brief @xmlonly Binds a notification object to a <obj name="TCB"/> @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:notification-binding"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] notification Notification to bind. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="notification"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="notification"/> @endxmlonly  is already bound.
 * Or,  @xmlonly <texttt text="notification"/> @endxmlonly  does not have Read rights to the Notification  @xmlonly <docref>(see <autoref label="sec:cap_rights"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_BindNotification(seL4_TCB _service, seL4_CPtr notification)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBBindNotification, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, notification);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Unbind Notification" label="tcb_unbindnotification"/> @endxmlonly
 * @brief @xmlonly Unbinds any notification object from a <obj name="TCB"/> @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:notification-binding"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is not bound to a notification. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_UnbindNotification(seL4_TCB _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBUnbindNotification, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#if (!defined(CONFIG_KERNEL_MCS) && defined(CONFIG_ENABLE_SMP_SUPPORT))
/**
 * @xmlonly <manual name="Set CPU Affinity" label="tcb_setaffinity"/> @endxmlonly
 * @brief @xmlonly Change a thread's current CPU in multicore machine @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:thread_creation"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] affinity The thread's new CPU to run. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="affinity"/> @endxmlonly  is not a valid CPU number. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetAffinity(seL4_TCB _service, seL4_Word affinity)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetAffinity, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = affinity;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="Set Breakpoint" label="tcb_setbreakpoint"/> @endxmlonly
 * @brief @xmlonly Set or modify a thread's breakpoints or watchpoints. Calls to this function
 * overwrite previous configurations for the target breakpoint. Do not use this
 * with seL4_SingleStep: the API will reject the call and return an error.
 * Instead, use seL4_TCB_ConfigureSingleStepping to configure single-stepping. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:debug_exceptions"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @param[in] vaddr A virtual address which forms part of the match conditions for the triggering of the breakpoint. 
 * @param[in] type One of: seL4_InstructionBreakpoint, which specifies that the breakpoint should occur on instruction execution at the specified vaddr or seL4_DataBreakpoint, which states that the breakpoint should occur on data access at the specified vaddr. 
 * @param[in] size A positive integer indicating the trigger-span of the watchpoint. Must be zero when 'type' is seL4_InstructionBreakpoint. 
 * @param[in] rw One of seL4_BreakOnRead, meaning the breakpoint will only be triggered on read-access; seL4_BreakOnWrite meaning the breakpoint will only be triggered on write-access, and seL4_BreakOnReadWrite meaning the breakpoint will be triggered on any access. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_AlignmentError The  @xmlonly <texttt text="vaddr"/> @endxmlonly  is not aligned to  @xmlonly <texttt text="size"/> @endxmlonly  bytes. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidArgument The  @xmlonly <texttt text="bp_num"/> @endxmlonly ,  @xmlonly <texttt text="size"/> @endxmlonly , or  @xmlonly <texttt text="rw"/> @endxmlonly  is not valid for the given  @xmlonly <texttt text="type"/> @endxmlonly .
 * Or, argument values are inappropriate for the target architecture.
 * Or,  @xmlonly <texttt text="vaddr"/> @endxmlonly  is in the kernel virtual address range. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The argument values are inappropriate for the target architecture. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetBreakpoint(seL4_TCB _service, seL4_Uint16 bp_num, seL4_Word vaddr, seL4_Word type, seL4_Word size, seL4_Word rw)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetBreakpoint, 0, 0, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xffffull);
	mr1 = vaddr;
	mr2 = type;
	mr3 = size;
	seL4_SetMR(4, rw);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="Get Breakpoint" label="tcb_getbreakpoint"/> @endxmlonly
 * @brief @xmlonly Read a breakpoint or watchpoint's current configuration. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:debug_exceptions"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @return @xmlonly 
 *                 A <texttt text="seL4_TCB_GetBreakpoint_t"/>: Struct that contains
 *                 <texttt text="seL4_Error error"/>, an seL4 API error value,
 *                 <texttt text="seL4_Word vaddr"/>, the virtual address at which the breakpoint will currently
 *                 be triggered;
 *                 <texttt text="seL4_Word type"/>, the type of operation which will currently trigger the
 *                 breakpoint, whether instruction execution, or data access;
 *                 <texttt text="seL4_Word size"/>, integer value for the span-size of the breakpoint.
 *                 Usually a power of two (1, 2, 4, etc.);
 *                 <texttt text="seL4_Word rw"/>, the access direction that will currently trigger the breakpoint,
 *                 whether read, write, or both and
 *                 <texttt text="seL4_Bool is_enabled"/>, which indicates whether or not the breakpoint
 *                 will currently be triggered if the match conditions are met.
 *              @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The argument values are inappropriate for the target architecture. 
 */
LIBSEL4_INLINE seL4_TCB_GetBreakpoint_t
seL4_TCB_GetBreakpoint(seL4_TCB _service, seL4_Uint16 bp_num)
{
	seL4_TCB_GetBreakpoint_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBGetBreakpoint, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xffffull);
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
		return result;
	}

	/* Unmarshal result. */
	result.vaddr = mr0;
	result.type = mr1;
	result.size = mr2;
	result.rw = mr3;
	result.is_enabled = (seL4_GetMR(4) & 0x1);
	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="Unset Breakpoint" label="tcb_unsetbreakpoint"/> @endxmlonly
 * @brief @xmlonly Disables a hardware breakpoint or watchpoint. The caller should assume that
 * the underlying configuration of the hardware registers has also been cleared.
 * Do not use this to clear single-stepping: the API will reject the call and
 * return an error. Instead, use seL4_TCB_ConfigureSingleStepping to disable
 * single-stepping. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:debug_exceptions"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the argument values are inappropriate for the target architecture. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The argument values are inappropriate for the target architecture. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_UnsetBreakpoint(seL4_TCB _service, seL4_Uint16 bp_num)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBUnsetBreakpoint, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xffffull);
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_HARDWARE_DEBUG_API)
/**
 * @xmlonly <manual name="Configure Single Stepping" label="tcb_configuresinglestepping"/> @endxmlonly
 * @brief @xmlonly Set or modify single stepping options for the target TCB. Subsequent calls to this
 * function overwrite previous configuration. Depending on your processor architecture,
 * this may or may not require the consumption of a hardware register. @endxmlonly
 * 
 * @xmlonly
 * <docref>See Sections <shortref sec="single_stepping_debug_exception"/> and <shortref sec="debug_exceptions"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] bp_num The API-ID of a target breakpoint. This ID will be a positive integer, with values ranging from 0 to seL4_NumHWBreakpoints - 1. This value is unused on AARCH64 
 * @param[in] num_instructions Number of instructions to step over before delivering a fault to the target thread's fault endpoint. Setting this to 0 disables single-stepping. 
 * @return @xmlonly 
 *                 A <texttt text="seL4_TCB_ConfigureSingleStepping_t"/>: Struct that contains
 *                 <texttt text="seL4_Error error"/>, an seL4 API error value,
 *                 <texttt text="seL4_Bool bp_was_consumed"/>, a boolean which indicates whether or not the <texttt text="bp_num"/>
 *                 breakpoint ID that was passed to the function, was consumed in the setup of the single-stepping
 *                 functionality: if this is <texttt text="true"/>, the caller should not attempt to re-use <texttt text="bp_num"/>
 *                 until it has disabled the single-stepping functionality via a subsequent call to
 *                 seL4_TCB_ConfigureSingleStepping with an <texttt text="num_instructions"/> argument of 0.
 *              @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the argument values are inappropriate for the target architecture. 
 * @retval seL4_InvalidArgument The argument values are inappropriate for the target architecture. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_TCB_ConfigureSingleStepping_t
seL4_TCB_ConfigureSingleStepping(seL4_TCB _service, seL4_Uint16 bp_num, seL4_Word num_instructions)
{
	seL4_TCB_ConfigureSingleStepping_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBConfigureSingleStepping, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = (bp_num & 0xffffull);
	mr1 = num_instructions;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
		return result;
	}

	/* Unmarshal result. */
	result.bp_was_consumed = (mr0 & 0x1);
	return result;
}

#endif
/**
 * @xmlonly <manual name="Set TLS Base" label="tcb_settlsbase"/> @endxmlonly
 * @brief @xmlonly Set the TLS base of the target TCB. @endxmlonly
 * 
 * @xmlonly
 * An invocation for setting the Thread Local Storage (TLS) base address. This ensures that across all platforms, the TLSBase register is viewed as being completely mutable, just like all of the general purpose registers, even on platforms where modification is a privileged operation.
 * @endxmlonly
 * 
 * @param[in] _service Capability to the TCB which is being operated on.
 * @param[in] tls_base The TLS base to set. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_TCB_SetTLSBase(seL4_TCB _service, seL4_Word tls_base)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(TCBSetTLSBase, 0, 0, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = tls_base;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Revoke" label="cnode_revoke"/> @endxmlonly
 * @brief @xmlonly Delete all child capabilities of a capability @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode at the root of the CSpace where the capability will be found. Must be at a depth equivalent to the wordsize.
 * @param[in] index CPtr to the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the capability being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="index"/> @endxmlonly  or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Revoke(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeRevoke, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xffull);
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Delete" label="cnode_delete"/> @endxmlonly
 * @brief @xmlonly Delete a capability @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode at the root of the CSpace where the capability will be found. Must be at a depth equivalent to the wordsize.
 * @param[in] index CPtr to the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the capability being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="index"/> @endxmlonly  or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Delete(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeDelete, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xffull);
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Cancel Badged Sends" label="cnode_cancelbadgedsends"/> @endxmlonly
 * @brief @xmlonly The cancel badged sends method is intended to allow for the reuse of badges by an
 * authority. When used with a badged endpoint capability it
 * will cancel any outstanding send operations for that endpoint and badge.
 * This operation has no effect on un-badged or other objects. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode at the root of the CSpace where the capability will be found. Must be at a depth equivalent to the wordsize.
 * @param[in] index CPtr to the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the capability being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="index"/> @endxmlonly  or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the capability does not have full rights to the Endpoint  @xmlonly <docref>(see <autoref label="sec:cap_rights"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_CancelBadgedSends(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeCancelBadgedSends, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xffull);
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Copy" label="cnode_copy"/> @endxmlonly
 * @brief @xmlonly Copy a capability, setting its access rights whilst doing so @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize.
 * @param[in] dest_index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPtr to the CNode that forms the root of the source CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] src_index CPtr to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @param[in] rights The rights inherited by the new capability. @xmlonly <docref> Possible values for this type are given in <autoref label="sec:cap_rights"/>  .</docref> @endxmlonly 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The index or depth of the source or destination is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="src_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source slot is empty. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source capability cannot be derived @xmlonly <docref> (see <autoref label="sec:cap_derivation"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="dest_depth"/> @endxmlonly  or  @xmlonly <texttt text="src_depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_RevokeFirst The source capability cannot be derived @xmlonly <docref> (see <autoref label="sec:cap_derivation"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Copy(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapRights_t rights)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeCopy, 0, 1, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xffull);
	mr2 = src_index;
	mr3 = (src_depth & 0xffull);
	seL4_SetMR(4, rights.words[0]);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Mint" label="cnode_mint"/> @endxmlonly
 * @brief @xmlonly Copy a capability, setting its access rights and badge whilst doing so @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize.
 * @param[in] dest_index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPtr to the CNode that forms the root of the source CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] src_index CPtr to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @param[in] rights The rights inherited by the new capability. @xmlonly <docref> Possible values for this type are given in <autoref label="sec:cap_rights"/>  .</docref> @endxmlonly 
 * @param[in] badge Badge or guard to be applied to the new capability. For badges on 32-bit platforms, the high 4 bits are ignored. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The index or depth of the source or destination is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="src_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source slot is empty. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source capability cannot be derived  @xmlonly <docref>(see <autoref label="sec:cap_derivation"/>)</docref> @endxmlonly .
 * Or, the badge or guard value is invalid. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="dest_depth"/> @endxmlonly  or  @xmlonly <texttt text="src_depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_RevokeFirst The source capability cannot be derived  @xmlonly <docref>(see <autoref label="sec:cap_derivation"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Mint(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_CapRights_t rights, seL4_Word badge)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeMint, 0, 1, 6);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xffull);
	mr2 = src_index;
	mr3 = (src_depth & 0xffull);
	seL4_SetMR(4, rights.words[0]);
	seL4_SetMR(5, badge);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Move" label="cnode_move"/> @endxmlonly
 * @brief @xmlonly Move a capability @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize.
 * @param[in] dest_index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPtr to the CNode that forms the root of the source CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] src_index CPtr to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The index or depth of the source or destination is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="src_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source slot is empty. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="dest_depth"/> @endxmlonly  or  @xmlonly <texttt text="src_depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Move(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeMove, 0, 1, 4);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xffull);
	mr2 = src_index;
	mr3 = (src_depth & 0xffull);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Mutate" label="cnode_mutate"/> @endxmlonly
 * @brief @xmlonly Move a capability, setting its guard in the process. This
 * operation is mostly useful for setting the guard of a CNode
 * capability without losing revokability of that CNode capability.
 * All other uses can be replaced by a combination of Mint and
 * Delete. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize.
 * @param[in] dest_index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] dest_depth Number of bits of dest_index to resolve to find the destination slot. 
 * @param[in] src_root CPtr to the CNode that forms the root of the source CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] src_index CPtr to the source slot. Resolved from the root of the source CSpace. 
 * @param[in] src_depth Number of bits of src_index to resolve to find the source slot. 
 * @param[in] badge Guard to be applied to the new capability. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The index or depth of the source or destination is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="src_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source slot is empty. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the guard value is invalid. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="dest_depth"/> @endxmlonly  or  @xmlonly <texttt text="src_depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Mutate(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth, seL4_Word badge)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeMutate, 0, 1, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xffull);
	mr2 = src_index;
	mr3 = (src_depth & 0xffull);
	seL4_SetMR(4, badge);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Rotate" label="cnode_rotate"/> @endxmlonly
 * @brief @xmlonly Given 3 capability slots - a destination, pivot and source - move the capability in the
 * pivot slot to the destination slot and the capability in the source slot to the pivot slot @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode at the root of the CSpace where the destination slot will be found. Must be at a depth equivalent to the wordsize.
 * @param[in] dest_index CPtr to the destination slot. Resolved relative to _service. Must be empty unless it refers to the same slot as the source slot. 
 * @param[in] dest_depth Depth to resolve dest_index to. 
 * @param[in] dest_badge The new capdata for the capability that ends up in the destination slot. 
 * @param[in] pivot_root CPtr to the CNode at the root of the CSpace where the pivot slot will be found. Must be at a depth equivalent to the wordsize. 
 * @param[in] pivot_index CPtr to the pivot slot. Resolved relative to pivot_root. The resolved slot must not refer to the source or destination slots. 
 * @param[in] pivot_depth Depth to resolve pivot_index to. 
 * @param[in] pivot_badge The new capdata for the capability that ends up in the pivot slot. 
 * @param[in] src_root CPtr to the CNode at the root of the CSpace where the source slot will be found. Must be at a depth equivalent to the wordsize. 
 * @param[in] src_index CPtr to the source slot. Resolved relative to src_root. 
 * @param[in] src_depth Depth to resolve src_index to. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst If the destination is not the same slot as the source and the destination slot contains a capability. 
 * @retval seL4_FailedLookup The index or depth of the source, destination, or pivot is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly .
 * Or,  @xmlonly <texttt text="src_root"/> @endxmlonly  or  @xmlonly <texttt text="pivot_root"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the source or pivot slot is empty. 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the pivot is the same slot as the source or destination.
 * Or, the guard value on the destination or pivot is invalid. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="dest_depth"/> @endxmlonly ,  @xmlonly <texttt text="src_depth"/> @endxmlonly , or  @xmlonly <texttt text="pivot_depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_Rotate(seL4_CNode _service, seL4_Word dest_index, seL4_Uint8 dest_depth, seL4_Word dest_badge, seL4_CNode pivot_root, seL4_Word pivot_index, seL4_Uint8 pivot_depth, seL4_Word pivot_badge, seL4_CNode src_root, seL4_Word src_index, seL4_Uint8 src_depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeRotate, 0, 2, 8);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, pivot_root);
	seL4_SetCap(1, src_root);

	/* Marshal and initialise parameters. */
	mr0 = dest_index;
	mr1 = (dest_depth & 0xffull);
	mr2 = dest_badge;
	mr3 = pivot_index;
	seL4_SetMR(4, (pivot_depth & 0xffull));
	seL4_SetMR(5, pivot_badge);
	seL4_SetMR(6, src_index);
	seL4_SetMR(7, (src_depth & 0xffull));

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#if !defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Save Caller" label="cnode_savecaller"/> @endxmlonly
 * @brief @xmlonly Save the reply capability from the last time the thread was called in the given CSpace so that it can be invoked later @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:cnode-ops"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service CPtr to the CNode at the root of the CSpace where the capability is to be saved. Must be at a depth equivalent to the wordsize.
 * @param[in] index CPtr to the slot in which to save the capability. Resolved from the root of the _service parameter. 
 * @param[in] depth Number of bits of index to resolve to find the slot being targeted. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="index"/> @endxmlonly  or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_CNode_SaveCaller(seL4_CNode _service, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(CNodeSaveCaller, 0, 0, 2);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = index;
	mr1 = (depth & 0xffull);
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
/**
 * @xmlonly <manual name="Get IRQ Handler" label="irq_controlget"/> @endxmlonly
 * @brief @xmlonly Create an IRQ handler capability @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:interrupts"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service An IRQControl capability. This gives you the authority to make this call.
 * @param[in] irq The IRQ that you want this capability to handle. 
 * @param[in] root CPtr to the CNode that forms the root of the destination CSpace. Must be at a depth equivalent to the wordsize. 
 * @param[in] index CPtr to the destination slot. Resolved from the root of the destination CSpace. 
 * @param[in] depth Number of bits of index to resolve to find the destination slot. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_DeleteFirst The destination slot contains a capability. 
 * @retval seL4_FailedLookup The  @xmlonly <texttt text="root"/> @endxmlonly ,  @xmlonly <texttt text="index"/> @endxmlonly , or  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, on x86, an IOAPIC is being used. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="irq"/> @endxmlonly  is invalid for the target architecture.
 * Or, on x86,  @xmlonly <texttt text="irq"/> @endxmlonly  is not in the ISA IRQ range.
 * Or,  @xmlonly <texttt text="depth"/> @endxmlonly  is invalid  @xmlonly <docref>(see <autoref label="s:cspace-addressing"/>)</docref> @endxmlonly . 
 * @retval seL4_RevokeFirst An IRQ handler capability for  @xmlonly <texttt text="irq"/> @endxmlonly  has already been created. 
 */
LIBSEL4_INLINE seL4_Error
seL4_IRQControl_Get(seL4_IRQControl _service, seL4_Word irq, seL4_CNode root, seL4_Word index, seL4_Uint8 depth)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQIssueIRQHandler, 0, 1, 3);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, root);

	/* Marshal and initialise parameters. */
	mr0 = irq;
	mr1 = index;
	mr2 = (depth & 0xffull);
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Acknowledge" label="irq_handleracknowledge"/> @endxmlonly
 * @brief @xmlonly Acknowledge the receipt of an interrupt and re-enable it @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:interrupts"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service The IRQ handler capability.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_IRQHandler_Ack(seL4_IRQHandler _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQAckIRQ, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Set Notification" label="irq_handlersetnotification"/> @endxmlonly
 * @brief @xmlonly Set the notification which the kernel will signal on interrupts
 * controlled by the supplied IRQ handler capability @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:interrupts"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service The IRQ handler capability.
 * @param[in] notification The notification which the IRQs will signal. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="notification"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="notification"/> @endxmlonly  does not have the Write right  @xmlonly <docref>(see <autoref label="sec:cap_rights"/>)</docref> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_IRQHandler_SetNotification(seL4_IRQHandler _service, seL4_CPtr notification)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQSetIRQHandler, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, notification);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Clear" label="irq_handlerclear"/> @endxmlonly
 * @brief @xmlonly Clear the handler capability from the IRQ slot @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:interrupts"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service The IRQ handler capability.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_IRQHandler_Clear(seL4_IRQHandler _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(IRQClearIRQHandler, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

/**
 * @xmlonly <manual name="Set" label="domainset_set"/> @endxmlonly
 * @brief @xmlonly Change the domain of a thread. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:domains"/>.</docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability allowing domain configuration.
 * @param[in] domain The thread's new domain. 
 * @param[in] thread Capability to the TCB which is being operated on. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidArgument The  @xmlonly <texttt text="domain"/> @endxmlonly  is greater than  @xmlonly <texttt text="CONFIG_NUM_DOMAINS"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="thread"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_DomainSet_Set(seL4_DomainSet _service, seL4_Uint8 domain, seL4_TCB thread)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(DomainSetSet, 0, 1, 1);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, thread);

	/* Marshal and initialise parameters. */
	mr0 = (domain & 0xffull);
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Configure Flags" label="schedcontrol_configureflags"/> @endxmlonly
 * @brief @xmlonly Set the parameters of a scheduling context by invoking the scheduling control capability. If the scheduling context is bound to a currently running thread, the parameters will take effect immediately: that is the current budget will be increased or reduced by the difference between the new and previous budget and the replenishment time will be updated according to any difference in the period. This can result in active threads being post-poned or released depending on the nature of the parameter change and the state of the thread. Additionally, if the scheduling context was previously empty (no budget) but bound to a runnable thread, this can result in a thread running for the first time since it now has access to CPU time. This call will return seL4 Invalid Argument if the parameters are too small (smaller than the kernel WCET for this platform) or too large (will overflow the timer). @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to a scheduling control object.
 * @param[in] schedcontext Capability to the scheduling context which is being operated on. 
 * @param[in] budget Timeslice in microseconds, when the budget expires the thread will be pre-empted. 
 * @param[in] period Period in microseconds, if equal to budget, this thread will be treated as a round-robin thread. Otherwise, sporadic servers will be used to assure the scheduling context does not exceed the budget over the specified period. 
 * @param[in] extra_refills Number of extra sporadic replenishments this scheduling context should use. Ignored for round-robin threads. 
 * @param[in] badge Identifier for this scheduling context. Delivered to timeout exception handler. Can be used to determine which scheduling context triggered the timeout. 
 * @param[in] flags Bitwise OR'd set of seL4_SchedContextFlag. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="schedcontext"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_RangeError The  @xmlonly <texttt text="budget"/> @endxmlonly  or  @xmlonly <texttt text="period"/> @endxmlonly  or  @xmlonly <texttt text="extra_refills"/> @endxmlonly  is too big or too small.
 * Or,  @xmlonly <texttt text="budget"/> @endxmlonly  is greater than  @xmlonly <texttt text="period"/> @endxmlonly . 
 */
LIBSEL4_INLINE seL4_Error
seL4_SchedControl_ConfigureFlags(seL4_SchedControl _service, seL4_SchedContext schedcontext, seL4_Time budget, seL4_Time period, seL4_Word extra_refills, seL4_Word badge, seL4_Word flags)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(SchedControlConfigureFlags, 0, 1, 5);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, schedcontext);

	/* Marshal and initialise parameters. */
	mr0 = budget;
	mr1 = period;
	mr2 = extra_refills;
	mr3 = badge;
	seL4_SetMR(4, flags);

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Bind" label="schedcontext_bind"/> @endxmlonly
 * @brief @xmlonly Bind an object to a scheduling context. The object can be a notification object or a
 * thread.
 * 
 * If the object is a thread and the thread is in a runnable state and the scheduling
 * context has available budget, this will start the thread running.
 * 
 * If the object is a notification, when passive threads wait on the notification object and
 * a signal arrives, the passive thread will receive the scheduling context and possess it
 * until it waits on the notification object again.
 * 
 * This operation will fail for notification objects if the scheduling context is already
 * bound to a notification object, and for thread objects if the scheduling context is
 * already bound to a thread. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the scheduling context which is being operated on.
 * @param[in] cap Capability to a TCB or a notification object 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="cap"/> @endxmlonly  is already bound to the same type of object.
 * Or,  @xmlonly <texttt text="cap"/> @endxmlonly  is a TCB in the blocked state and  @xmlonly <texttt text="_service"/> @endxmlonly  is not schedulable. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="cap"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_SchedContext_Bind(seL4_SchedContext _service, seL4_CPtr cap)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(SchedContextBind, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, cap);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Unbind" label="schedcontext_unbind"/> @endxmlonly
 * @brief @xmlonly Unbind any objects (threads or notification objects) from a scheduling context. This
 * will render the bound thread passive, see Section 6.1.5. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the scheduling context which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or, the current thread's TCB is bound to  @xmlonly <texttt text="_service"/> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_SchedContext_Unbind(seL4_SchedContext _service)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(SchedContextUnbind, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Unbind Object" label="schedcontext_unbindobject"/> @endxmlonly
 * @brief @xmlonly Unbind an object from a scheduling context. The object can be either a thread or a
 * notification.
 * 
 * If the thread being unbound is the thread that is bound to this scheduling context,
 * this will render the thread passive. However if the thread being
 * unbound received the scheduling context via scheduling context donation over IPC,
 * the scheduling context will be returned to the thread that it was originally bound to.
 * 
 * If the object is a notification and it is bound to the scheduling context, unbind it. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:passive"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the scheduling context which is being operated on.
 * @param[in] cap Capability to a notification that is bound to the scheduling context or capability to a TCB that is bound to this scheduling context or has received it through scheduling context donation. 
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="cap"/> @endxmlonly  is not bound to  @xmlonly <texttt text="_service"/> @endxmlonly .
 * Or,  @xmlonly <texttt text="cap"/> @endxmlonly  is the current thread's TCB. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  or  @xmlonly <texttt text="cap"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_Error
seL4_SchedContext_UnbindObject(seL4_SchedContext _service, seL4_CPtr cap)
{
	seL4_Error result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(SchedContextUnbindObject, 0, 1, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Setup input capabilities. */
	seL4_SetCap(0, cap);

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result = (seL4_Error) seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
	}

	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Consumed" label="schedcontext_consumed"/> @endxmlonly
 * @brief @xmlonly Return the amount of time used by this scheduling context since this function was last called or a timeout exception triggered. @endxmlonly
 * 
 * @xmlonly
 * <docref>See <autoref label="sec:threads"/></docref>
 * @endxmlonly
 * 
 * @param[in] _service Capability to the scheduling context which is being operated on.
 * @return @xmlonly <errorenumdesc/> @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_SchedContext_Consumed_t
seL4_SchedContext_Consumed(seL4_SchedContext _service)
{
	seL4_SchedContext_Consumed_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(SchedContextConsumed, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
		return result;
	}

	/* Unmarshal result. */
	result.consumed = mr0;
	return result;
}

#endif
#if defined(CONFIG_KERNEL_MCS)
/**
 * @xmlonly <manual name="Yield To" label="schedcontext_yieldto"/> @endxmlonly
 * @brief @xmlonly If a thread is currently runnable and running on this scheduling context and the scheduling context has available budget, place it at the head of the scheduling queue.
 * If the caller is at an equal priority to the thread this will result in the thread being scheduled.
 * If the caller is at a higher priority the thread will not run until the threads priority is the highest priority in the system.
 * The caller must have a maximum control priority greater than or equal to the threads priority. @endxmlonly
 * 
 * @xmlonly
 * Capability to the scheduling context which is being operated on.
 * @endxmlonly
 * 
 * @param[in] _service Capability to the scheduling context which is being operated on.
 * @return @xmlonly 
 *             <docref>See <autoref label="sec:scheduling_contexts"/></docref>
 *            @endxmlonly
 * @retval seL4_IllegalOperation The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type.
 * Or,  @xmlonly <texttt text="_service"/> @endxmlonly  is not bound to a TCB or is bound to the current thread's TCB.
 * Or, the target thread's priority is greater than the current thread's maximum controlled priority @xmlonly <docref> (see <autoref label="sec:sched"/>)</docref> @endxmlonly . 
 * @retval seL4_InvalidCapability The  @xmlonly <texttt text="_service"/> @endxmlonly  is a CPtr to a capability of the wrong type. 
 */
LIBSEL4_INLINE seL4_SchedContext_YieldTo_t
seL4_SchedContext_YieldTo(seL4_SchedContext _service)
{
	seL4_SchedContext_YieldTo_t result;
	seL4_MessageInfo_t tag = seL4_MessageInfo_new(SchedContextYieldTo, 0, 0, 0);
	seL4_MessageInfo_t output_tag;
	seL4_Word mr0;
	seL4_Word mr1;
	seL4_Word mr2;
	seL4_Word mr3;

	/* Marshal and initialise parameters. */
	mr0 = 0;
	mr1 = 0;
	mr2 = 0;
	mr3 = 0;

	/* Perform the call, passing in-register arguments directly. */
	output_tag = seL4_CallWithMRs(_service, tag,
		&mr0, &mr1, &mr2, &mr3);
	result.error = seL4_MessageInfo_get_label(output_tag);

	/* Unmarshal registers into IPC buffer on error. */
	if (result.error != seL4_NoError) {
		seL4_SetMR(0, mr0);
		seL4_SetMR(1, mr1);
		seL4_SetMR(2, mr2);
		seL4_SetMR(3, mr3);
#ifdef CONFIG_KERNEL_INVOCATION_REPORT_ERROR_IPC
		if (seL4_CanPrintError()) {
			seL4_DebugPutString(seL4_GetDebugError());
		}
#endif
		return result;
	}

	/* Unmarshal result. */
	result.consumed = mr0;
	return result;
}

#endif