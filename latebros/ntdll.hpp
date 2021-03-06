#pragma once
#include "stdafx.h"

typedef NTSTATUS(NTAPI* fnNtCreateSection)(
	PHANDLE sectionHandle,
	ULONG                DesiredAccess,
	POBJECT_ATTRIBUTES   ObjectAttributes OPTIONAL,
	PLARGE_INTEGER       MaximumSize OPTIONAL,
	ULONG                PageAttributess,
	ULONG                SectionAttributes,
	HANDLE               FileHandle OPTIONAL);

typedef NTSTATUS(NTAPI* fnNtMapViewOfSection)(HANDLE          SectionHandle,
	HANDLE          ProcessHandle,
	PVOID           *BaseAddress,
	ULONG_PTR       ZeroBits,
	SIZE_T          CommitSize,
	PLARGE_INTEGER  SectionOffset,
	PSIZE_T         ViewSize,
	int InheritDisposition,
	ULONG           AllocationType,
	ULONG           Win32Protect);

__forceinline uint32_t CompareStrings( const char* StringA, const wchar_t* StringB );

namespace ntdll
{
	void initialise();
	uintptr_t get_procedure_address(void *module, std::string procedure_name);
	extern fnNtCreateSection NtCreateSection;
	extern fnNtMapViewOfSection NtMapViewOfSection;
}