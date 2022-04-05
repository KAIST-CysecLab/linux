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

#define OPTEE_RKP_SMCCC_CALL_WORKAROUND_QCOM_FALKOR_E1003 \
    ARM_SMCCC_CALL_VAL(1,1,54,0)

#define OPTEE_RKP_SMCCC_CALL_SET_TTBR0_EL1 \
    ARM_SMCCC_CALL_VAL(1,1,53,0)

#define OPTEE_RKP_SMCCC_CALL_WORKAROUND_CAVIUM_27456 \
    ARM_SMCCC_CALL_VAL(1,1,54,1)

#endif