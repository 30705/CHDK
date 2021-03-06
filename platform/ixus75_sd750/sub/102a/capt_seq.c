/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

static long *nrflag = (long*)0xCF74;

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFFB0AC20 - 0xFFB0AE64, length=146
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    SUB     SP, SP, #4 \n"
"    MOV     R4, SP \n"
"    B       loc_FFB0ADAC \n"

"loc_FFB0AC30:\n"
"    LDR     R2, [SP] \n"
"    LDR     R3, [R2] \n"
"    MOV     R0, R2 \n"
"    CMP     R3, #0x15 \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FFB0AD80 \n"
"    .long   loc_FFB0ACA0 \n"
"    .long   loc_FFB0ACC0 \n"
"    .long   loc_FFB0ACD4 \n"
"    .long   loc_FFB0ACE8 \n"
"    .long   loc_FFB0ACE0 \n"
"    .long   loc_FFB0ACF0 \n"
"    .long   loc_FFB0ACF8 \n"
"    .long   loc_FFB0AD04 \n"
"    .long   loc_FFB0AD0C \n"
"    .long   loc_FFB0AD18 \n"
"    .long   loc_FFB0AD20 \n"
"    .long   loc_FFB0AD28 \n"
"    .long   loc_FFB0AD30 \n"
"    .long   loc_FFB0AD38 \n"
"    .long   loc_FFB0AD40 \n"
"    .long   loc_FFB0AD4C \n"
"    .long   loc_FFB0AD54 \n"
"    .long   loc_FFB0AD5C \n"
"    .long   loc_FFB0AD64 \n"
"    .long   loc_FFB0AD70 \n"
"    .long   loc_FFB0AD78 \n"
"    .long   loc_FFB0AD94 \n"

"loc_FFB0ACA0:\n"
"    BL      sub_FFB0B294 \n"
"    BL      shooting_expo_param_override\n"   // +
"    BL      sub_FFB089A4 \n"
"    LDR     R3, =0xBE160 \n"
"    MOV     R2, #0\n"                          // added
"    STR     R2, [R3,#0x24]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
//"  LDR     R2, [R3, #0x24] \n"  // above patch makes these three lines redundant
//"  CMP     R2, #0 \n"
//"  BEQ     loc_FFB0AD90 \n"
//"  BL      _sub_FFB0A850 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0ACC0:\n"
"    BL      sub_FFB0A774_my \n"  // --> Patched. Old value = 0xFFB0A774.

"loc_FFB0ACC4:\n"
"    LDR     R2, =0xBE160 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2, #0x24] \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0ACD4:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FFB0B4B4 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0ACE0:\n"
"    BL      sub_FFB0AE94 \n"
"    B       loc_FFB0ACC4 \n"

"loc_FFB0ACE8:\n"
"    BL      sub_FFB0B24C \n"
"    B       loc_FFB0ACC4 \n"

"loc_FFB0ACF0:\n"
"    BL      sub_FFB0B25C \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0ACF8:\n"
"    BL      sub_FFB0B3AC \n"
"    BL      sub_FFB089A4 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD04:\n"
"    BL      sub_FFB0A92C \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD0C:\n"
"    BL      sub_FFB0B41C \n"
"    BL      sub_FFB089A4 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD18:\n"
"    BL      sub_FFB0B24C \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD20:\n"
"    BL      sub_FFB0CB84 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD28:\n"
"    BL      sub_FFB0CD58 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD30:\n"
"    BL      sub_FFB0CDEC \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD38:\n"
"    BL      sub_FFB0CEE8 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD40:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FFB0D154 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD4C:\n"
"    BL      sub_FFB0D328 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD54:\n"
"    BL      sub_FFB0D3C4 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD5C:\n"
"    BL      sub_FFB0D484 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD64:\n"
"    BL      sub_FFB0B608 \n"
"    BL      sub_FFB0A698 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD70:\n"
"    BL      sub_FFB0D028 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD78:\n"
"    BL      sub_FFB0D084 \n"
"    B       loc_FFB0AD90 \n"

"loc_FFB0AD80:\n"
"    MOV     R1, #0x4C0 \n"
"    LDR     R0, =0xFFB0A4F4 /*'SsShootTask.c'*/ \n"
"    ADD     R1, R1, #0xE \n"
"    BL      _DebugAssert \n"

"loc_FFB0AD90:\n"
"    LDR     R2, [SP] \n"

"loc_FFB0AD94:\n"
"    LDR     R3, =0x97A30 \n"
"    LDR     R1, [R2, #4] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFB1E990 /*_SetEventFlag*/ \n"
"    LDR     R0, [SP] \n"
"    BL      sub_FFB0A574 \n"

"loc_FFB0ADAC:\n"
"    LDR     R3, =0x97A34 \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [R3] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FFB1F0A8 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFB0AC30 \n"
"    LDR     R0, =0xFFB0A4F4 /*'SsShootTask.c'*/ \n"
"    MOV     R1, #0x400 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
"    MOV     PC, LR \n"
);
}

/*************************************************************/
//** sub_FFB0A774_my @ 0xFFB0A774 - 0xFFB0A844, length=53
void __attribute__((naked,noinline)) sub_FFB0A774_my() {
asm volatile (
"    STMFD   SP!, {R4,R5,LR} \n"
"    LDR     R3, =0xBE160 \n"
"    LDR     R5, [R0, #0xC] \n"
"    LDR     R1, [R3, #0x24] \n"
"    LDR     R2, [R5, #8] \n"
"    CMP     R1, #0 \n"
"    ORR     R2, R2, #1 \n"
"    STR     R2, [R5, #8] \n"
"    BNE     loc_FFB0A7C8 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FFB14CC4 \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFB0A7C8 \n"
"    LDR     R3, [R5, #8] \n"
"    MOV     R0, #1 \n"
"    ORR     R3, R3, #0x40000000 \n"
"    STR     R3, [R5, #8] \n"

"loc_FFB0A7B8:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    LDMFD   SP!, {R4,R5,LR} \n"
"    B       sub_FFB08F1C \n"

"loc_FFB0A7C8:\n"
"    LDR     R4, =0xBE160 \n"
"    BL      sub_FFB0B26C \n"
"    LDR     R3, [R4, #0x24] \n"
"    CMP     R3, #0 \n"
"    BNE     loc_FFB0A810 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFB0C450 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FFB0A7B8 \n"
"    BL      sub_FF82668C \n"
"    BL      sub_FF81BEA8 \n"
"    STR     R0, [R5, #0x14] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFB0D834 \n"
"    BL      sub_FFB0E228 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFB0D94C_my \n"  // --> Patched. Old value = 0xFFB0D94C.
"    BL      capt_seq_hook_raw_here\n"   // +
"    B       loc_FFB0A824 \n"

"loc_FFB0A810:\n"
"    LDR     R3, =0xCF60 \n"
"    LDR     R2, [R3] \n"
"    CMP     R2, #0 \n"
"    MOVNE   R0, #0x1D \n"
"    MOVEQ   R0, #0 \n"

"loc_FFB0A824:\n"
"    MOV     R1, #1 \n"
"    MOV     R2, R5 \n"
"    BL      sub_FFB08F1C \n"
"    BL      sub_FFB0DCC8 \n"
"    CMP     R0, #0 \n"
"    LDRNE   R3, [R5, #8] \n"
"    ORRNE   R3, R3, #0x2000 \n"
"    STRNE   R3, [R5, #8] \n"
"    LDMFD   SP!, {R4,R5,PC} \n"
);
}

/*************************************************************/
//** sub_FFB0D94C_my @ 0xFFB0D94C - 0xFFB0D9A4, length=23
void __attribute__((naked,noinline)) sub_FFB0D94C_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    MOV     R4, R0 \n"
"    SUB     SP, SP, #0xC \n"
"    BL      sub_FFB0E3BC \n"
"    MVN     R1, #0 \n"
"    BL      sub_FFB1EB2C /*_ClearEventFlag*/ \n"
"    MOV     R0, #0x8A \n"
"    ADD     R1, SP, #4 \n"
"    MOV     R2, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FFB0D98C \n"
"    MOV     R1, #0x1D0 \n"
"    LDR     R0, =0xFFB0D7D0 /*'SsCaptureSeq.c'*/ \n"
"    ADD     R1, R1, #2 \n"
"    BL      _DebugAssert \n"

"loc_FFB0D98C:\n"
"    LDR     R3, =0xBE160 \n"
"    LDR     R2, =0xBE220 \n"
"    LDR     R0, [R3, #0x7C] \n"
"    LDRSH   R1, [R2, #0xE] \n"
"    BL      sub_FFA44DE0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFB0D754 \n"
"    BL      wait_until_remote_button_is_released\n"
"    BL      capt_seq_hook_set_nr\n"
"    LDR     PC, =0xFFB0D9A8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF974C00 - 0xFF975154, length=342
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    SUB     SP, SP, #0x20 \n"
"    ADD     R7, SP, #4 \n"
"    B       loc_FF975110 \n"

"loc_FF974C10:\n"
"    CMP     R2, #0x22 \n"
"    BNE     loc_FF974C28 \n"
"    LDR     R0, [R12, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x88] \n"
"    B       loc_FF974C8C \n"

"loc_FF974C28:\n"
"    CMP     R2, #0x1D \n"
"    BNE     loc_FF974C3C \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF974AD0 \n"
"    B       loc_FF974C7C \n"

"loc_FF974C3C:\n"
"    CMP     R2, #0x1E \n"
"    BNE     loc_FF974C50 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF974B2C \n"
"    B       loc_FF974C7C \n"

"loc_FF974C50:\n"
"    SUB     R3, R2, #0x1F \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF974C68 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF974B88 \n"
"    B       loc_FF974C7C \n"

"loc_FF974C68:\n"
"    CMP     R2, #0x21 \n"
"    BNE     loc_FF974C98 \n"
"    BL      sub_FF93AC60 \n"
"    BL      sub_FF93DD98 \n"
"    BL      sub_FF93CFD0 \n"

"loc_FF974C7C:\n"
"    LDR     R3, [SP, #4] \n"
"    LDR     R0, [R3, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x88] \n"

"loc_FF974C8C:\n"
"    LDR     R0, [SP, #4] \n"
"    BL      sub_FF9705CC \n"
"    B       loc_FF975110 \n"

"loc_FF974C98:\n"
"    CMP     R2, #0xD \n"
"    MOV     R8, #1 \n"
"    BNE     loc_FF974D08 \n"
"    LDR     R1, [R12, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#2 \n"
"    ADD     R6, SP, #0x14 \n"
"    SUB     R1, R1, #8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP, #4] \n"
"    BL      sub_FF97307C \n"
"    LDR     R3, [SP, #4] \n"
"    LDR     R1, [R3, #0x7C] \n"
"    LDR     R2, [R3, #0x8C] \n"
"    ADD     R0, R3, #4 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x88] \n"
"    LDR     R0, [SP, #4] \n"
"    BL      sub_FF97334C \n"
"    LDR     R3, [SP, #4] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x7C] \n"
"    LDR     R2, [R3, #0x94] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x90] \n"
"    B       loc_FF975058 \n"

"loc_FF974D08:\n"
"    SUB     R3, R2, #0xE \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF974DC4 \n"
"    ADD     R6, SP, #0x14 \n"
"    ADD     R5, SP, #8 \n"
"    MOV     R0, R12 \n"
"    MOV     R1, R6 \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF973440 \n"
"    MOV     R4, R0 \n"
"    CMP     R4, #5 \n"
"    CMPNE   R4, #1 \n"
"    BNE     loc_FF974D5C \n"
"    LDR     R12, [SP, #4] \n"
"    MOV     R0, R5 \n"
"    LDR     R1, [R12, #0x7C] \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x88] \n"
"    B       loc_FF974D94 \n"

"loc_FF974D5C:\n"
"    CMP     R4, #6 \n"
"    CMPNE   R4, #2 \n"
"    BNE     loc_FF974DA4 \n"
"    LDR     R12, [SP, #4] \n"
"    MOV     R0, R5 \n"
"    MOV     R1, R8 \n"
"    MOV     R2, R4 \n"
"    LDR     R3, [R12, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x88] \n"
"    MOV     R1, R6 \n"
"    LDR     R0, [SP, #4] \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF974700 \n"

"loc_FF974D94:\n"
"    MOV     R1, R4 \n"
"    LDR     R0, [SP, #4] \n"
"    BL      sub_FF974A64 \n"
"    B       loc_FF975058 \n"

"loc_FF974DA4:\n"
"    LDR     R12, [SP, #4] \n"
"    MOV     R2, R4 \n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x7C] \n"
"    LDR     R3, [R12, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x88] \n"
"    B       loc_FF975058 \n"

"loc_FF974DC4:\n"
"    SUB     R3, R2, #0x19 \n"
"    CMP     R3, #1 \n"
"    BHI     loc_FF974E1C \n"
"    LDR     R1, [R12, #0x7C] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R12, R1, LSL#2 \n"
"    ADD     R6, SP, #0x14 \n"
"    SUB     R1, R1, #8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R0, [SP, #4] \n"
"    BL      sub_FF972530 \n"
"    LDR     R3, [SP, #4] \n"
"    ADD     R0, R3, #4 \n"
"    LDR     R1, [R3, #0x7C] \n"
"    LDR     R2, [R3, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3, #0x88] \n"
"    LDR     R0, [SP, #4] \n"
"    BL      sub_FF972850 \n"
"    B       loc_FF975058 \n"

"loc_FF974E1C:\n"
"    ADD     R6, SP, #0x14 \n"
"    ADD     R1, R12, #4 \n"
"    MOV     R2, #0xC \n"
"    MOV     R0, R6 \n"
"    BL      _memcpy \n"
"    LDR     R12, [SP, #4] \n"
"    LDR     R3, [R12] \n"
"    MOV     R2, R12 \n"
"    CMP     R3, #0x1C \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF975044 \n"
"    .long   loc_FF974EBC \n"
"    .long   loc_FF974EC8 \n"
"    .long   loc_FF974ED4 \n"
"    .long   loc_FF974ED4 \n"
"    .long   loc_FF974EBC \n"
"    .long   loc_FF974EC8 \n"
"    .long   loc_FF974ED4 \n"
"    .long   loc_FF974ED4 \n"
"    .long   loc_FF974EF8 \n"
"    .long   loc_FF974EF8 \n"
"    .long   loc_FF975018 \n"
"    .long   loc_FF975024 \n"
"    .long   loc_FF975034 \n"
"    .long   loc_FF975044 \n"
"    .long   loc_FF975044 \n"
"    .long   loc_FF975044 \n"
"    .long   loc_FF974EE0 \n"
"    .long   loc_FF974EEC \n"
"    .long   loc_FF974F08 \n"
"    .long   loc_FF974F14 \n"
"    .long   loc_FF974F4C \n"
"    .long   loc_FF974F84 \n"
"    .long   loc_FF974FBC \n"
"    .long   loc_FF974FF4 \n"
"    .long   loc_FF974FF4 \n"
"    .long   loc_FF975044 \n"
"    .long   loc_FF975044 \n"
"    .long   loc_FF975000 \n"
"    .long   loc_FF97500C \n"

"loc_FF974EBC:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF970F2C \n"
"    B       loc_FF975040 \n"

"loc_FF974EC8:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF9711D0 \n"
"    B       loc_FF975040 \n"

"loc_FF974ED4:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF971444 \n"
"    B       loc_FF975040 \n"

"loc_FF974EE0:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF971740 \n"
"    B       loc_FF975040 \n"

"loc_FF974EEC:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF9719A8 \n"
"    B       loc_FF975040 \n"

"loc_FF974EF8:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF971BA8_my \n"  // --> Patched. Old value = 0xFF971BA8.
"    MOV     R8, #0 \n"
"    B       loc_FF975040 \n"

"loc_FF974F08:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF971D08 \n"
"    B       loc_FF975040 \n"

"loc_FF974F14:\n"
"    LDRH    R1, [R2, #4] \n"
"    LDR     R3, =0x2C6E8 \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R3, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R3, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R3, [R3, #4] \n"
"    STRH    R3, [SP, #0x18] \n"
"    MOV     R0, R2 \n"
"    LDRH    R2, [R2, #0xC] \n"
"    STRH    R2, [SP, #0x1C] \n"
"    BL      sub_FF972000 \n"
"    B       loc_FF975040 \n"

"loc_FF974F4C:\n"
"    MOV     R0, R2 \n"
"    LDRH    R2, [R2, #4] \n"
"    LDR     R3, =0x2C6E8 \n"
"    STRH    R2, [SP, #0x14] \n"
"    LDRH    R2, [R3, #8] \n"
"    STRH    R2, [SP, #0x1C] \n"
"    LDRH    R1, [R3, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R2, [R3, #4] \n"
"    STRH    R2, [SP, #0x18] \n"
"    LDRH    R3, [R3, #6] \n"
"    STRH    R3, [SP, #0x1A] \n"
"    BL      sub_FF972128 \n"
"    B       loc_FF975040 \n"

"loc_FF974F84:\n"
"    LDR     R3, =0x2C6E8 \n"
"    LDRH    R1, [R3] \n"
"    STRH    R1, [SP, #0x14] \n"
"    MOV     R0, R2 \n"
"    LDRH    R2, [R2, #6] \n"
"    STRH    R2, [SP, #0x16] \n"
"    LDRH    R2, [R3, #8] \n"
"    STRH    R2, [SP, #0x1C] \n"
"    LDRH    R1, [R3, #4] \n"
"    STRH    R1, [SP, #0x18] \n"
"    LDRH    R3, [R3, #6] \n"
"    STRH    R3, [SP, #0x1A] \n"
"    BL      sub_FF9721EC \n"
"    B       loc_FF975040 \n"

"loc_FF974FBC:\n"
"    LDR     R3, =0x2C6E8 \n"
"    LDRH    R1, [R3, #6] \n"
"    STRH    R1, [SP, #0x1A] \n"
"    LDRH    R1, [R3] \n"
"    STRH    R1, [SP, #0x14] \n"
"    LDRH    R1, [R3, #2] \n"
"    STRH    R1, [SP, #0x16] \n"
"    LDRH    R3, [R3, #4] \n"
"    STRH    R3, [SP, #0x18] \n"
"    MOV     R0, R2 \n"
"    LDRH    R2, [R2, #0xC] \n"
"    STRH    R2, [SP, #0x1C] \n"
"    BL      sub_FF9722A4 \n"
"    B       loc_FF975040 \n"

"loc_FF974FF4:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF972354 \n"
"    B       loc_FF975040 \n"

"loc_FF975000:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF97299C \n"
"    B       loc_FF975040 \n"

"loc_FF97500C:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF972B98 \n"
"    B       loc_FF975040 \n"

"loc_FF975018:\n"
"    MOV     R0, R2 \n"
"    BL      sub_FF972D54 \n"
"    B       loc_FF975040 \n"

"loc_FF975024:\n"
"    MOV     R0, R2 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF972F3C \n"
"    B       loc_FF975040 \n"

"loc_FF975034:\n"
"    MOV     R0, R2 \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF972F3C \n"

"loc_FF975040:\n"
"    LDR     R12, [SP, #4] \n"

"loc_FF975044:\n"
"    ADD     R0, R12, #4 \n"
"    LDR     R1, [R12, #0x7C] \n"
"    LDR     R2, [R12, #0x8C] \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R12, #0x88] \n"

"loc_FF975058:\n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF975080 \n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, [R1, #0x7C] \n"
"    ADD     R3, R3, R3, LSL#1 \n"
"    ADD     R1, R1, R3, LSL#2 \n"
"    MOV     R0, R6 \n"
"    SUB     R1, R1, #8 \n"
"    BL      sub_FF970BE4 \n"
"    B       loc_FF9750FC \n"

"loc_FF975080:\n"
"    LDR     R3, [SP, #4] \n"
"    LDR     R2, [R3] \n"
"    CMP     R2, #9 \n"
"    BNE     loc_FF9750C8 \n"
"    MOV     R4, #0 \n"
"    MOV     R1, #1 \n"
"    MOV     R2, R1 \n"
"    MOV     R3, R1 \n"
"    MOV     R0, R4 \n"
"    STR     R4, [SP] \n"
"    BL      sub_FF970B28 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    MOV     R2, R1 \n"
"    MOV     R3, R1 \n"
"    STR     R4, [SP] \n"
"    BL      sub_FF970D80 \n"
"    B       loc_FF9750FC \n"

"loc_FF9750C8:\n"
"    MOV     R4, #1 \n"
"    MOV     R0, R4 \n"
"    MOV     R1, R4 \n"
"    MOV     R2, R4 \n"
"    MOV     R3, R4 \n"
"    STR     R4, [SP] \n"
"    BL      sub_FF970B28 \n"
"    MOV     R0, R4 \n"
"    MOV     R1, R0 \n"
"    MOV     R2, R0 \n"
"    MOV     R3, R0 \n"
"    STR     R4, [SP] \n"
"    BL      sub_FF970D80 \n"

"loc_FF9750FC:\n"
"    LDR     R2, =0x2C734 \n"
"    MOV     R3, #0 \n"
"    LDR     R0, [SP, #4] \n"
"    STR     R3, [R2] \n"
"    BL      sub_FF9705CC \n"

"loc_FF975110:\n"
"    LDR     R3, =0x2C6DC \n"
"    MOV     R2, #0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, R7 \n"
"    BL      sub_FFB1F0A8 /*_ReceiveMessageQueue*/ \n"
"    LDR     R12, [SP, #4] \n"
"    LDR     R2, [R12] \n"
"    CMP     R2, #0x23 \n"
"    BNE     loc_FF974C10 \n"
"    MOV     R0, R12 \n"
"    BL      sub_FF9705CC \n"
"    LDR     R3, =0x2C6D8 \n"
"    MOV     R1, #1 \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFB1E990 /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x20 \n"
"    LDMFD   SP!, {R4-R8,PC} \n"
);
}

/*************************************************************/
//** sub_FF971BA8_my @ 0xFF971BA8 - 0xFF971CF0, length=83
void __attribute__((naked,noinline)) sub_FF971BA8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R3, =0x2C6D8 \n"
"    MOV     R4, R0 \n"
"    MOV     R1, #0x3E \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FFB1EB2C /*_ClearEventFlag*/ \n"
"    MOV     R1, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    BL      sub_FF970700 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF970868 \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF970904 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF9709A0 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    BL      sub_FF970A3C \n"
"    LDR     R3, [R4] \n"
"    CMP     R3, #9 \n"
"    MOV     R5, R0 \n"
"    MOVEQ   R5, #0 \n"
"    MOVEQ   R6, R5 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF971C2C \n"
"    MOV     R2, #2 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF970620 \n"
"    BL      sub_FFAE502C \n"
"    LDR     R2, =0x2C728 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    B       loc_FF971C30 \n"

"loc_FF971C2C:\n"
"    BL      sub_FF970AD8 \n"

"loc_FF971C30:\n"
"    STRH    R0, [R4, #4] \n"
"    CMP     R5, #1 \n"
"    BNE     loc_FF971C50 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF9706E4 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF970ECC \n"
"    B       loc_FF971C54 \n"

"loc_FF971C50:\n"
"    BL      sub_FF970B18 \n"

"loc_FF971C54:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF93A8DC_my \n"  // --> Patched. Old value = 0xFF93A8DC.
"    LDRSH   R0, [R4, #8] \n"
"    MOV     R1, #1 \n"
"    BL      sub_FF93CB90 \n"
"    ADD     R0, R4, #8 \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF93CC50 \n"
"    LDRSH   R0, [R4, #0xE] \n"
"    BL      sub_FF95ECAC \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF971CB8 \n"
"    LDR     R3, =0x2C6D8 \n"
"    MOV     R2, #0xBB0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, #2 \n"
"    ADD     R2, R2, #8 \n"
"    BL      sub_FFB1E980 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF971CB8 \n"
"    MOV     R1, #0x4A0 \n"
"    LDR     R0, =0xFF970578 /*'ExpDrv.c'*/ \n"
"    ADD     R1, R1, #3 \n"
"    BL      _DebugAssert \n"

"loc_FF971CB8:\n"
"    CMP     R5, #1 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    LDR     R3, =0x2C6D8 \n"
"    MOV     R2, #0xBB0 \n"
"    LDR     R0, [R3] \n"
"    MOV     R1, #0x20 \n"
"    ADD     R2, R2, #8 \n"
"    BL      sub_FFB1E980 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    MOV     R1, #0x4A0 \n"
"    LDR     R0, =0xFF970578 /*'ExpDrv.c'*/ \n"
"    ADD     R1, R1, #8 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    B       _DebugAssert \n"
);
}

/*************************************************************/
//** sub_FF93A8DC_my @ 0xFF93A8DC - 0xFF93A938, length=24
void __attribute__((naked,noinline)) sub_FF93A8DC_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R3, =0x64F4 \n"
"    LDR     R2, [R3] \n"
"    MOV     R1, #0x168 \n"
"    MOV     R3, R0, LSL#16 \n"
"    CMP     R2, #1 \n"
"    ADD     R1, R1, #3 \n"
"    LDR     R0, =0xFF93A0F8 /*'Shutter.c'*/ \n"
"    MOV     R4, R3, ASR#16 \n"
"    BEQ     loc_FF93A908 \n"
"    BL      _DebugAssert \n"

"loc_FF93A908:\n"
"    MOV     R1, #0x170 \n"
"    CMN     R4, #0xC00 \n"
"    LDR     R3, =0x13266 \n"
"    LDR     R0, =0xFF93A0F8 /*'Shutter.c'*/ \n"
"    ADD     R1, R1, #1 \n"
"    LDREQSH R4, [R3] \n"
"    LDRNE   R3, =0x13266 \n"
"    CMN     R4, #0xC00 \n"
"    STRH    R4, [R3] \n"
"    BNE     loc_FF93A934 \n"
"    BL      _DebugAssert \n"

"loc_FF93A934:\n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    LDR     PC, =0xFF93A93C \n"  // Continue in firmware
);
}
