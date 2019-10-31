/*******************************************************************************
 *
 * File: kernel.c
 *
 * Author: Alexy Torres Aurora Dugo
 *
 * Date: 30/10/2019
 *
 * Version: 1.0
 *
 * Boot code for ARMv7 version of MiniKernel
 ******************************************************************************/


#include "gic.h"
#include "serial.h"

void int_handler(cpu_state_t *cpu_state, uint32_t int_id, 
                 stack_state_t* stack_state)
{
    (void)cpu_state;
    (void)int_id;
    (void)stack_state;
    serial_put_string("SWI\n", 4);
}

void main(void)
{
    serial_put_string("ARM Minikernel\n", 15);
    __asm__ __volatile__("swi %0" :: "i" (0x2a));
    while(1);
}