/* 
	File : core_portme.c
*/
/*
	Author : Shay Gal-On, EEMBC
	Legal : TODO!
*/ 
#include <stdio.h>
#include <stdlib.h>
#include "coremark.h"
#include "platform.h"
#include "encoding.h"

#if VALIDATION_RUN
	volatile ee_s32 seed1_volatile=0x3415;
	volatile ee_s32 seed2_volatile=0x3415;
	volatile ee_s32 seed3_volatile=0x66;
#endif
#if PERFORMANCE_RUN
	volatile ee_s32 seed1_volatile=0x0;
	volatile ee_s32 seed2_volatile=0x0;
	volatile ee_s32 seed3_volatile=0x66;
#endif
#if PROFILE_RUN
	volatile ee_s32 seed1_volatile=0x8;
	volatile ee_s32 seed2_volatile=0x8;
	volatile ee_s32 seed3_volatile=0x8;
#endif
	volatile ee_s32 seed4_volatile=ITERATIONS;
	volatile ee_s32 seed5_volatile=0;

static uint64_t start_time_val, stop_time_val;

static uint64_t read_mcycle(void) {
  uint32_t hi = read_csr(mcycleh);
  uint32_t lo = read_csr(mcycle);
  if (hi != read_csr(mcycleh))
    return read_mcycle();
  else
    return ((uint64_t)hi << 32) | lo;
}

void start_time(void) {
  start_time_val = read_mcycle();
}

void stop_time(void) {
  stop_time_val = read_mcycle();
}

CORE_TICKS get_time(void) {
  return (stop_time_val - start_time_val) / 1000000;
}

secs_ret time_in_secs(CORE_TICKS ticks) {
  return ticks * (1000000.0 / get_cpu_freq());
}

ee_u32 default_num_contexts=1;

/* Function : portable_init
	Target specific initialization code 
	Test for some common mistakes.
*/
void portable_init(core_portable *p, int *argc, char *argv[])
{
	if (sizeof(ee_ptr_int) != sizeof(ee_u8 *)) {
		ee_printf("ERROR! Please define ee_ptr_int to a type that holds a pointer!\n");
	}
	if (sizeof(ee_u32) != 4) {
		ee_printf("ERROR! Please define ee_u32 to a 32b unsigned type!\n");
	}
	p->portable_id=1;
}
/* Function : portable_fini
	Target specific final code 
*/
void portable_fini(core_portable *p)
{
	p->portable_id=0;
}


