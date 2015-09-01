#ifndef PLATFORM_SPECIFIC_ENDIANS_
#define PLATFORM_SPECIFIC_ENDIANS_

#include <endian.h>

// Let us hope compiler provided any of those.
#if defined(__BYTE_ORDER) && __BYTE_ORDER == __BIG_ENDIAN || \
    defined(__BIG_ENDIAN__) || \
    defined(__ARMEB__) || \
    defined(__THUMBEB__) || \
    defined(__AARCH64EB__) || \
    defined(_MIBSEB) || defined(__MIBSEB) || defined(__MIBSEB__)

  #define ARCH_BIG_ENDIAN

#elif defined(__BYTE_ORDER) && __BYTE_ORDER == __LITTLE_ENDIAN || \
    defined(__LITTLE_ENDIAN__) || \
    defined(__ARMEL__) || \
    defined(__THUMBEL__) || \
    defined(__AARCH64EL__) || \
    defined(_MIPSEL) || defined(__MIPSEL) || defined(__MIPSEL__)

  #define ARCH_LITTLE_ENDIAN

#else
  // As a last hope user can define BIG_ENDIAN or LITTLE_ENDIAN by hand
  // and then recompile with anything
  #error "Failed to determine machine endianness, try different compiler"
#endif

#endif
