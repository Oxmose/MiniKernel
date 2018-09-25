#include "ppc-asm.h"
.file	"tests.S"
.text
  /* Define kernel entry point */
.globl	test_entry
.type	test_entry,@function
test_entry:
/* PR */
mflr r0
stw r0, 8(sp)
stwu sp, -16(sp)
/* Tests will be cat here */
/*******************************************************************************
 * simple_10access.S
 *
 * Author  Alexy Torres Aurora Dugo
 * Version 1.0
 *
 * Cache simulator tests, generating traces.
 * 10 acceses: 5 read 5 writes
 ******************************************************************************/

li r3, 0x7000
lwz r4, 0(r3)
lwz r4, 4(r3)
lwz r4, 8(r3)
lwz r4, 12(r3)
lwz r4, 16(r3)

li r3, 0x7000
stw r4, 0(r3)
stw r4, 4(r3)
stw r4, 8(r3)
stw r4, 12(r3)
stw r4, 16(r3)
/* EP */
addi sp, sp, 16
lwz r0, 8(sp)
mtlr r0
blr
