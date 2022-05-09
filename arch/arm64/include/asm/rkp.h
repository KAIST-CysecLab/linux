/*
 * Copyright (C) 2021 Hyeseon Oh
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __ASM_RKP_H
#define __ASM_RKP_H

#include <linux/arm-smccc.h>

#define OPTEE_RKP_SMCCC_CALL_SET_TTBR0_EL1 \
    ARM_SMCCC_CALL_VAL(1,1,53,0)

#define OPTEE_RKP_OWNER 53
#define OPTEE_RKP_FUNC_UPPER    (ARM_SMCCC_CALL_VAL(1,1,53,0) >> 16) & 0xFFFF

#define OPTEE_RKP_REG_TTBR 0

#ifdef __ASSEMBLY__
/* define assembler macros */

    .macro  rkp_emulate_msr, reg, param1
    // save x0-x1
    stp x0, x1, [sp, #-0x10]!
    mov x1, \param1
    mov x0, \reg
    // msr register-to-emulate
    smc #1
    // restore x0-x1
    ldp x0, x1, [sp], #0x10
    .endm

#else
/* define C macros */
#define rkp_write_sysreg(v, r) do {                         \
        u64 __val = (u64)(v);                               \
        asm volatile (                                      \
            "stp x0, x1, [sp, #-0x10]!\n\t"                 \
            "mov x1, %0\n\t"                                \
            "mov x0, %1\n\t"                                \
            "smc #1\n\t"                                    \
            "ldp x0, x1, [sp], #0x10\n\t"                   \
            :: "r"(__val), "I"(r)                           \
        );                                                  \
    } while (0)
#endif


#endif