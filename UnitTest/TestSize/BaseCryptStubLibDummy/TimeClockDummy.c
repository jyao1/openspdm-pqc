/** @file

Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#include <Base.h>
#include <Library/DebugLib.h>

typedef int time_t;

//
// Structures Definitions
//
struct tm {
  int   tm_sec;     /* seconds after the minute [0-60] */
  int   tm_min;     /* minutes after the hour [0-59] */
  int   tm_hour;    /* hours since midnight [0-23] */
  int   tm_mday;    /* day of the month [1-31] */
  int   tm_mon;     /* months since January [0-11] */
  int   tm_year;    /* years since 1900 */
  int   tm_wday;    /* days since Sunday [0-6] */
  int   tm_yday;    /* days since January 1 [0-365] */
  int   tm_isdst;   /* Daylight Savings Time flag */
  long  tm_gmtoff;  /* offset from CUT in seconds */
  char  *tm_zone;   /* timezone abbreviation */
};

//
// -- Time Management Routines --
//

time_t time (time_t *timer)
{
  ASSERT(FALSE);
  return 0;
}

struct tm * gmtime (const time_t *timer)
{
  ASSERT(FALSE);
  return NULL;
}

time_t _time64 (time_t* t) {
  ASSERT(FALSE);
  return 0;
}

struct tm *mbedtls_platform_gmtime_r( const time_t *tt,
                                      struct tm *tm_buf )
{
  ASSERT(FALSE);
  return NULL;
}
