/** @file
  Declaration of NVRAM var list and display methods.

  Copyright (c) 2020, Mike Beaton. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-3-Clause

**/

#ifndef __BH__LIST_VARS__
#define __BH__LIST_VARS__

//
// Basic UEFI Libraries
//
#include <Uefi.h>
#include <Library/UefiLib.h>

// Return an NVRAM value, the allocated buffer for the data must be freed by the caller using FreePool
EFI_STATUS
GetNvramValue (
  IN CHAR16     *Name,
  IN EFI_GUID   *Guid,
  OUT UINT32    *Attr,
  OUT UINTN     *DataSize,
  OUT VOID      **Data
  );

// Display an NVRAM value, allocating and freeing the buffer needed for the data (always display GUID)
EFI_STATUS
DisplayNvramValue (
  IN CHAR16     *Name,
  IN EFI_GUID   *Guid,
  BOOLEAN       isString
  );

// Display an NVRAM value, allocating and freeing the buffer needed for the data (don't display GUID)
EFI_STATUS
DisplayNvramValueWithoutGuid (
  IN CHAR16     *Name,
  IN EFI_GUID   *Guid,
  BOOLEAN       isString
  );

/**
  List all NVRAM vars to conout, with some keyboard control:

  'a' - list remaining with no wait for keyboard input
  'x', 'q' - abort listing
  Any other key - show next var

  @param[in]  Prefix  Only display vars starting with prefix; display all vars if NULL.

  @retval             EFI_NOT_FOUND if listing completed, no more vars to show;
                      EFI_SUCCESS if listing aborted early ßby user;
                      EFI_OUT_OF_RESOURCES if could not allocate;
                      any other return value, error returned by subsidiary method.
**/
EFI_STATUS
ListVars (
  IN CHAR16 *Prefix OPTIONAL
  );

// Toggle or set NVRAM var
EFI_STATUS
ToggleOrSetVar (
  IN CHAR16 *Name,
  IN EFI_GUID *Guid,
  IN CHAR8 *PreferredValue,
  UINTN PreferredSize,
  BOOLEAN Toggle
  );

#endif
