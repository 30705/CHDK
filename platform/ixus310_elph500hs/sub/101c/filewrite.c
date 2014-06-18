/*
 * filewrite.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"

typedef struct {
    unsigned int address;
    unsigned int length;
} cam_ptp_data_chunk; //camera specific structure

#define MAX_CHUNKS_FOR_JPEG 7   // filewritetask is prepared for this many chunks
/*
 * fwt_data_struct: defined here as it's camera dependent
 * unneeded members are designated with unkn
 * pdc is required, everything after that is optional (DryOS < R50)
 * file_offset, full_size, seek_flag only needs to be defined for DryOS>=r50 generation cameras
 */
typedef struct
{
    int unkn1[5];
    cam_ptp_data_chunk pdc[MAX_CHUNKS_FOR_JPEG];
    int unkn2;
    char name[32];
} fwt_data_struct;

#include "../../../generic/filewrite.c"

/*************************************************************/
//** filewritetask @ 0xFF2E250C - 0xFF2E25EC, length=57
void __attribute__((naked,noinline)) filewritetask() {
asm volatile (
"    STMFD   SP!, {R1-R5,LR} \n"
"    LDR     R5, =0xC20C \n"

"loc_FF2E2514:\n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R5, #0x10] \n"
"    ADD     R1, SP, #8 \n"
"    BL      sub_FF02ADD8 /*_ReceiveMessageQueue*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R1, #0x348 \n"
"    LDRNE   R0, =0xFF2E260C \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #8] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0xA \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF2E2514 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E0 \n"
"    B       loc_FF2E25E8 \n"
"    B       loc_FF2E2570 \n"
"    B       loc_FF2E25D8 \n"

"loc_FF2E2570:\n"
"    MOV     R0, #0 \n"
"    MOV     R4, R5 \n"
"    STR     R0, [SP] \n"

"loc_FF2E257C:\n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R1, SP \n"
"    BL      sub_FF02B01C /*_GetNumberOfPostedMessages*/ \n"
"    LDR     R0, [SP] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF2E25A8 \n"
"    LDR     R0, [R4, #0x10] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02ADD8 /*_ReceiveMessageQueue*/ \n"
"    B       loc_FF2E257C \n"

"loc_FF2E25A8:\n"
"    LDR     R0, [R4, #4] \n"
"    CMN     R0, #1 \n"
"    BEQ     loc_FF2E25CC \n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    MVN     R0, #0 \n"
"    STR     R0, [R4, #4] \n"
"    LDR     R0, =0x116DEC \n"
"    BL      sub_FF0682A4 \n"
"    BL      sub_FF06649C \n"

"loc_FF2E25CC:\n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      _GiveSemaphore \n"
"    B       loc_FF2E2514 \n"

"loc_FF2E25D8:\n"
"    BL      sub_FF2E2258_my \n"  // --> Patched. Old value = 0xFF2E2258.
"    B       loc_FF2E2514 \n"

"loc_FF2E25E0:\n"
"    BL      sub_FF2E27E8_my \n"  // --> Patched. Old value = 0xFF2E27E8.
"    B       loc_FF2E2514 \n"

"loc_FF2E25E8:\n"
"    BL      sub_FF2E2398_my \n"  // --> Patched. Old value = 0xFF2E2398.
"    B       loc_FF2E2514 \n"
);
}

/*************************************************************/
//** sub_FF2E2258_my @ 0xFF2E2258 - 0xFF2E2324, length=52
void __attribute__((naked,noinline)) sub_FF2E2258_my() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0x3C \n"
"    ADD     R0, R0, #0x50 \n"
"    BL      sub_FF0682A4 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF066434 \n"
"    LDR     R0, [R4, #0xC] \n"
"    BL      sub_FF00033C \n"
"    LDR     R0, [R4, #0x4C] \n"
"    ADD     R7, R4, #0x50 \n"
"    CMP     R0, #1 \n"
"    LDREQ   R0, [R4, #8] \n"
"    ORREQ   R0, R0, #0x8000 \n"
"    STREQ   R0, [R4, #8] \n"
"    LDR     R5, [R4, #0xC] \n"
"    LDR     R8, [R4, #8] \n"
"    BL      sub_FF1846F0 \n"
//hook start
"    STMFD   SP!, {R2,R4-R12,LR} \n"
"    MOV     R0, R4 \n"
"    BL      filewrite_main_hook \n"
"    LDMFD   SP!, {R2,R4-R12,LR} \n"
//hook end
"    LDR     R9, =0x1B6 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R9 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    MOV     R6, R0 \n"
"    BL      sub_FF1847C0 \n"
"    CMN     R6, #1 \n"
"    MOVNE   R5, R6 \n"
"    BNE     sub_FF2E2330 \n"
"    BL      sub_FF1846F0 \n"
"    MOV     R0, R7 \n"
"    BL      sub_FF027D1C \n"
"    MOV     R2, #0xF \n"
"    MOV     R1, R7 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_FF3CA088 \n"
"    MOV     R0, #0 \n"
"    LDR     R1, =0x41FF \n"
"    STRB    R0, [SP, #0x13] \n"
"    STR     R1, [SP, #0x24] \n"
"    MOV     R1, #0x10 \n"
"    STR     R0, [SP, #0x2C] \n"
"    STR     R1, [SP, #0x28] \n"
"    ADD     R1, SP, #0x24 \n"
"    ADD     R0, SP, #4 \n"
"    STR     R5, [SP, #0x30] \n"
"    STR     R5, [SP, #0x34] \n"
"    STR     R5, [SP, #0x38] \n"
"    BL      sub_FF065DA8 \n"
"    MOV     R2, R9 \n"
"    MOV     R1, R8 \n"
"    MOV     R0, R7 \n"
"    BL      fwt_open \n"  // --> Patched. Old value = _Open.
"    LDR     PC, =0xFF2E2328 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2E27E8_my @ 0xFF2E27E8 - 0xFF2E28B0, length=51
void __attribute__((naked,noinline)) sub_FF2E27E8_my() {
asm volatile (
"    STMFD   SP!, {R4-R10,LR} \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #6 \n"
"    BHI     loc_FF2E2814 \n"
"    ADD     R0, R5, R0, LSL#3 \n"
"    LDR     R8, [R0, #0x14]! \n"
"    LDR     R7, [R0, #4] \n"
"    CMP     R7, #0 \n"
"    BNE     loc_FF2E282C \n"
"    B       loc_FF2E2820 \n"

"loc_FF2E2814:\n"
"    LDR     R1, =0x2A2 \n"
"    LDR     R0, =0xFF2E260C \n"
"    BL      _DebugAssert \n"

"loc_FF2E2820:\n"
"    MOV     R1, R5 \n"
"    MOV     R0, #7 \n"
"    B       sub_FF2E28C0 \n"

"loc_FF2E282C:\n"
"    LDR     R9, =0xC20C \n"
"    MOV     R4, R7 \n"

"loc_FF2E2834:\n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R4, #0x1000000 \n"
"    MOVLS   R6, R4 \n"
"    MOVHI   R6, #0x1000000 \n"
"    BIC     R1, R0, #0xFF000000 \n"
"    CMP     R1, #0 \n"
"    BICNE   R0, R0, #0xFF000000 \n"
"    RSBNE   R0, R0, #0x1000000 \n"
"    CMPNE   R6, R0 \n"
"    MOVHI   R6, R0 \n"
"    LDR     R0, [R9, #4] \n"
"    MOV     R2, R6 \n"
"    MOV     R1, R8 \n"
"    BL      fwt_write \n"  // --> Patched. Old value = _Write.
"    LDR     R1, [R5, #4] \n"
"    CMP     R6, R0 \n"
"    ADD     R1, R1, R0 \n"
"    STR     R1, [R5, #4] \n"
"    BEQ     loc_FF2E2894 \n"
"    CMN     R0, #1 \n"
"    LDRNE   R0, =0x9200015 \n"
"    LDREQ   R0, =0x9200005 \n"
"    STR     R0, [R5, #0x10] \n"
"    B       loc_FF2E2820 \n"

"loc_FF2E2894:\n"
"    SUB     R4, R4, R0 \n"
"    CMP     R4, R7 \n"
"    LDRCS   R1, =0x2CD \n"
"    ADD     R8, R8, R0 \n"
"    LDRCS   R0, =0xFF2E260C \n"
"    BLCS    _DebugAssert \n"
"    CMP     R4, #0 \n"
"    BNE     loc_FF2E2834 \n"
"    LDR     PC, =0xFF2E28B4 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF2E2398_my @ 0xFF2E2398 - 0xFF2E23CC, length=14
void __attribute__((naked,noinline)) sub_FF2E2398_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0xC20C \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    SUB     SP, SP, #0x38 \n"
"    CMN     R0, #1 \n"
"    BEQ     sub_FF2E23E0 \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R6, =0x9200003 \n"
"    TST     R1, #0x8000 \n"
"    BEQ     loc_FF2E23CC \n"
//mod start
"    LDR R3, =current_write_ignored\n"
"    LDR R3, [R3]\n"
"    CMP R3, #0\n"
"    BNE loc_D\n" // jump over the next block
//mod end
"    BL      sub_FF027740 \n"
"    B       sub_FF2E23D0 \n"

"loc_FF2E23CC:\n"
"loc_D:\n"
"    BL      fwt_close \n"  // --> Patched. Old value = _Close.
"    LDR     PC, =0xFF2E23D0 \n"  // Continue in firmware
);
}
