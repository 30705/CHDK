/*
 * capt_seq.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"

#define USE_STUBS_NRFLAG 1 // see stubs_min.S

#define NR_AUTO (0)

//#define PAUSE_FOR_FILE_COUNTER 1000  // Enable delay in capt_seq_hook_raw_here to ensure file counter is updated

#include "../../../generic/capt_seq.c"

/*************************************************************/
//** capt_seq_task @ 0xFF88BF78 - 0xFF88C250, length=183
void __attribute__((naked,noinline)) capt_seq_task() {
asm volatile (
"    STMFD   SP!, {R3-R7,LR} \n"
"    LDR     R5, =0x1CD30 \n"
"    LDR     R7, =0x3530 \n"
"    MOV     R6, #0 \n"

"loc_FF88BF88:\n"
"    LDR     R0, [R7, #4] \n"
"    MOV     R2, #0 \n"
"    MOV     R1, SP \n"
"    BL      sub_006B8458 /*_ReceiveMessageQueue*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF88BFB8 \n"
"    LDR     R2, =0x429 \n"
"    LDR     R1, =0xFF88B8F4 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    BL      _ExitTask \n"
"    LDMFD   SP!, {R3-R7,PC} \n"

"loc_FF88BFB8:\n"
"    LDR     R0, [SP] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #0x23 \n"
"    CMPNE   R0, #0x19 \n"
"    BLNE    sub_FF9989C8 \n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x25 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF88C214 \n"
"    B       loc_FF88C078 \n"
"    B       loc_FF88C090 \n"
"    B       loc_FF88C09C \n"
"    B       loc_FF88C0B0 \n"
"    B       loc_FF88C0A8 \n"
"    B       loc_FF88C0BC \n"
"    B       loc_FF88C0C4 \n"
"    B       loc_FF88C0CC \n"
"    B       loc_FF88C0D8 \n"
"    B       loc_FF88C104 \n"
"    B       loc_FF88C0E4 \n"
"    B       loc_FF88C0F0 \n"
"    B       loc_FF88C0F8 \n"
"    B       loc_FF88C10C \n"
"    B       loc_FF88C114 \n"
"    B       loc_FF88C11C \n"
"    B       loc_FF88C124 \n"
"    B       loc_FF88C12C \n"
"    B       loc_FF88C138 \n"
"    B       loc_FF88C140 \n"
"    B       loc_FF88C148 \n"
"    B       loc_FF88C150 \n"
"    B       loc_FF88C158 \n"
"    B       loc_FF88C160 \n"
"    B       loc_FF88C168 \n"
"    B       loc_FF88C170 \n"
"    B       loc_FF88C17C \n"
"    B       loc_FF88C184 \n"
"    B       loc_FF88C18C \n"
"    B       loc_FF88C194 \n"
"    B       loc_FF88C19C \n"
"    B       loc_FF88C1A8 \n"
"    B       loc_FF88C1B0 \n"
"    B       loc_FF88C1BC \n"
"    B       loc_FF88C1F4 \n"
"    B       loc_FF88C200 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C078:\n"
"    BL      sub_FF88C79C \n"
"    BL      shooting_expo_param_override\n"    // added
"    BL      sub_FF889574 \n"
//To do: Check if this is needed.
//"    MOV     R0, #0\n"                          // added
//"    STR     R0, [R5,#0x28]\n"                  // added, fixes overrides behavior at short shutter press (from S95)
"    LDR     R0, [R5, #0x28] \n"
"    CMP     R0, #0 \n"
"    BLNE    sub_FF9975D8_my \n"  // --> Patched. Old value = 0xFF9975D8.
"    B       loc_FF88C224 \n"

"loc_FF88C090:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF9974CC_my \n"  // --> Patched. Old value = 0xFF9974CC.
"    B       loc_FF88C224 \n"

"loc_FF88C09C:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF88CAF8 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0A8:\n"
"    BL      sub_FF88C404 \n"
"    B       loc_FF88C0B4 \n"

"loc_FF88C0B0:\n"
"    BL      sub_FF88C778 \n"

"loc_FF88C0B4:\n"
"    STR     R6, [R5, #0x28] \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0BC:\n"
"    BL      sub_FF88C780 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0C4:\n"
"    BL      sub_FF88C9BC \n"
"    B       loc_FF88C0DC \n"

"loc_FF88C0CC:\n"
"    LDR     R0, [R0, #0x10] \n"
"    BL      sub_FF997674 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0D8:\n"
"    BL      sub_FF88CA50 \n"

"loc_FF88C0DC:\n"
"    BL      sub_FF889574 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0E4:\n"
"    LDR     R0, [R5, #0x50] \n"
"    BL      sub_FF88D0FC \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0F0:\n"
"    BL      sub_FF88D544 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C0F8:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF88D5AC \n"
"    B       loc_FF88C224 \n"

"loc_FF88C104:\n"
"    BL      sub_FF88C778 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C10C:\n"
"    BL      sub_FF9969C8 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C114:\n"
"    BL      sub_FF996C04 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C11C:\n"
"    BL      sub_FF996CC0 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C124:\n"
"    BL      sub_FF996D98 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C12C:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF997000 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C138:\n"
"    BL      sub_FF997160 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C140:\n"
"    BL      sub_FF893040 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C148:\n"
"    BL      sub_FF89304C \n"
"    B       loc_FF88C224 \n"

"loc_FF88C150:\n"
"    BL      sub_FF9971FC \n"
"    B       loc_FF88C224 \n"

"loc_FF88C158:\n"
"    BL      sub_FF9972A8 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C160:\n"
"    BL      sub_FF88CC60 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C168:\n"
"    MOV     R0, #0 \n"
"    B       loc_FF88C174 \n"

"loc_FF88C170:\n"
"    LDR     R0, [R0, #0xC] \n"

"loc_FF88C174:\n"
"    BL      sub_FF88CCEC \n"
"    B       loc_FF88C224 \n"

"loc_FF88C17C:\n"
"    BL      sub_FF996E68 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C184:\n"
"    BL      sub_FF996EA8 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C18C:\n"
"    BL      sub_FF88FAE4 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C194:\n"
"    BL      sub_FF88FBD4 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C19C:\n"
"    LDR     R0, [R0, #0xC] \n"
"    BL      sub_FF9973B8 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C1A8:\n"
"    BL      sub_FF997440 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C1B0:\n"
"    BL      sub_FF88FD60 \n"
"    BL      sub_FF88FC2C \n"
"    B       loc_FF88C224 \n"

"loc_FF88C1BC:\n"
"    MOV     R0, #1 \n"
"    BL      sub_FF997EC8 \n"
"    MOV     R0, #1 \n"
"    BL      sub_FF997FF4 \n"
"    LDR     R0, =0x1CE30 \n"
"    LDRH    R0, [R0, #0x90] \n"
"    CMP     R0, #4 \n"
"    LDRNEH  R0, [R5] \n"
"    SUBNE   R1, R0, #0x8200 \n"
"    SUBNES  R1, R1, #0x31 \n"
"    BNE     loc_FF88C224 \n"
"    BL      sub_FF88FBD4 \n"
"    BL      sub_FF8900F8 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C1F4:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0x10 \n"
"    B       loc_FF88C208 \n"

"loc_FF88C200:\n"
"    MOV     R2, #0 \n"
"    MOV     R1, #0xF \n"

"loc_FF88C208:\n"
"    MOV     R0, #0 \n"
"    BL      sub_FF88A048 \n"
"    B       loc_FF88C224 \n"

"loc_FF88C214:\n"
"    LDR     R2, =0x54D \n"
"    LDR     R1, =0xFF88B8F4 /*'SsShootTask.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"

"loc_FF88C224:\n"
"    LDR     R0, [SP] \n"
"    LDR     R1, [R0, #4] \n"
"    LDR     R0, [R7] \n"
"    BL      sub_006B81EC /*_SetEventFlag*/ \n"
"    LDR     R4, [SP] \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R2, =0x11E \n"
"    LDREQ   R1, =0xFF88B8F4 /*'SsShootTask.c'*/ \n"
"    BLEQ    _DebugAssert \n"
"    STR     R6, [R4, #8] \n"
"    B       loc_FF88BF88 \n"
);
}

/*************************************************************/
//** sub_FF9975D8_my @ 0xFF9975D8 - 0xFF997670, length=39
void __attribute__((naked,noinline)) sub_FF9975D8_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF88B4DC \n"
"    MOV     R4, R0 \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF891720 \n"
"    LDR     R6, =0x74D0 \n"
"    TST     R0, #1 \n"
"    MOV     R5, #1 \n"
"    BNE     loc_FF99766C \n"
"    BL      sub_FF89177C \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF99766C \n"
"    BL      sub_FF88C788 \n"
"    BL      sub_FF88D8F4 \n"
"    MOV     R1, R4 \n"
"    BL      sub_FF88D950 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R4, #8 \n"
"    MOV     R0, #0x3F \n"
"    BL      _SetPropertyCase \n"
"    BL      sub_FF9981B4 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1804 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1B84_my \n"  // --> Patched. Old value = 0xFFAC1B84.
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"

"loc_FF99766C:\n"
"    STR     R5, [R6] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FF9974CC_my @ 0xFF9974CC - 0xFF9975D4, length=67
void __attribute__((naked,noinline)) sub_FF9974CC_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R6, =0x1CD30 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R6, #0x28] \n"
"    MOV     R4, #0 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF997518 \n"
"    LDR     R0, =0x74D0 \n"
"    MOV     R2, R5 \n"
"    LDR     R0, [R0] \n"
"    MOV     R1, #1 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R4, #0x1D \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF88A048 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF998750 \n"
"    B       loc_FF9975CC \n"

"loc_FF997518:\n"
"    BL      sub_FF88D8F4 \n"
"    MOV     R1, R5 \n"
"    BL      sub_FF88D950 \n"
"    LDR     R0, =0x10E \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x30 \n"
"    BL      _SetPropertyCase \n"
"    MOV     R2, #4 \n"
"    ADD     R1, R5, #0x34 \n"
"    MOV     R0, #0x2C \n"
"    BL      _SetPropertyCase \n"
"    MOV     R0, #0xC \n"
"    BL      sub_FF891720 \n"
"    TST     R0, #1 \n"
"    BNE     loc_FF997560 \n"
"    BL      sub_FF89177C \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF997568 \n"

"loc_FF997560:\n"
"    BL      sub_FF889E28 \n"
"    MOV     R4, #1 \n"

"loc_FF997568:\n"
"    TST     R4, #1 \n"
"    BNE     loc_FF9975B0 \n"
"    BL      sub_FF9981B4 \n"
"    MVN     R1, #0x1000 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAC0EE4 \n"
"    TST     R0, #1 \n"
"    MOV     R4, R0 \n"
"    BNE     loc_FF9975B0 \n"
"    BL      sub_FF88C788 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAC1804 \n"
"    MOV     R0, #2 \n"
"    BL      sub_FF8931C0 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FFAC1B84_my \n"  // --> Patched. Old value = 0xFFAC1B84.
"    B       loc_FF9975CC \n"

"loc_FF9975B0:\n"
"    MOV     R2, R5 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF88A048 \n"
"    MOV     R1, R4 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF998964 \n"

"loc_FF9975CC:\n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x28] \n"
"    LDMFD   SP!, {R4-R6,PC} \n"
);
}

/*************************************************************/
//** sub_FFAC1B84_my @ 0xFFAC1B84 - 0xFFAC1DF4, length=157
void __attribute__((naked,noinline)) sub_FFAC1B84_my() {
asm volatile (
"    STMFD   SP!, {R2-R8,LR} \n"
"    MOV     R4, R0 \n"
"    BL      sub_FFAC176C \n"
"    BL      sub_FF997C80 \n"
"    LDR     R7, =0x1CD30 \n"
"    LDR     R0, [R7, #0x184] \n"
"    CMP     R0, #2 \n"
"    BNE     loc_FFAC1BC0 \n"
"    ADD     R0, R7, #0x100 \n"
"    LDRH    R0, [R0, #0x8E] \n"
"    CMP     R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    MOVLS   R0, #3 \n"
"    BLLS    sub_FF919B10 \n"

"loc_FFAC1BC0:\n"
"    LDR     R0, =0x12F \n"
"    MOV     R2, #4 \n"
"    ADD     R1, SP, #4 \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    MOVNE   R2, #0x18C \n"
"    LDRNE   R1, =0xFFAC1E08 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    LDR     R0, [SP, #4] \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRNE   R0, =0xFFAC13F4 \n"
"    LDREQ   R0, =0xFFAC1B4C \n"
"    MOVNE   R1, R4 \n"
"    MOVEQ   R1, #0 \n"
"    BL      sub_FF8CB528 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1894_my \n"  // --> Patched. Old value = 0xFFAC1894.
"    LDR     R1, =0xCB4C \n"
"    MOV     R2, #4 \n"
"    MOV     R0, #0x8A \n"
"    BL      _GetPropertyCase \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x19B \n"
"    LDRNE   R1, =0xFFAC1E08 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      sub_FF88ED60 \n"
"    BL      sub_FF97B0A8 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1F00 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R8, =0xCB4C \n"
"    AND     R0, R0, #0xFF00 \n"
"    CMP     R0, #0x600 \n"
"    LDRH    R0, [R4, #0x18] \n"
"    LDRNE   R2, =0xFFAC1658 \n"
"    LDREQ   R2, =0xFFAC15D4 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAC1C7C \n"
"    CMP     R0, #1 \n"
"    BEQ     loc_FFAC1CA0 \n"
"    CMP     R0, #4 \n"
"    BNE     loc_FFAC1D14 \n"

"loc_FFAC1C7C:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1278 \n"
"    MOV     R5, R0 \n"
"    BL      sub_FF8C8250 \n"
"    B       loc_FFAC1D28 \n"

"loc_FFAC1CA0:\n"
"    STR     R6, [SP] \n"
"    MOV     R3, R2 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC12F8 \n"
"    MOV     R5, R0 \n"
"    MOV     R1, #0 \n"
"    MOV     R0, #0x45 \n"
"    BL      sub_FF8321D8 \n"
"    TST     R5, #1 \n"
"    BNE     loc_FFAC1D28 \n"
"    LDR     R0, =0xFFAC1B4C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8CB528 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1F00 \n"
"    MOV     R6, R0 \n"
"    LDR     R0, [R8] \n"
"    BL      sub_FFAC16F0 \n"
"    LDR     R1, [R4, #0x34] \n"
"    LDR     R2, [R8] \n"
"    MOV     R3, R6 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1378 \n"
"    MOV     R5, R0 \n"
"    BL      sub_FFAC1200 \n"
"    B       loc_FFAC1D28 \n"

"loc_FFAC1D14:\n"
"    LDR     R2, =0x1D5 \n"
"    LDR     R1, =0xFFAC1E08 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    MOV     R5, #0x1D \n"

"loc_FFAC1D28:\n"
"    BL      sub_FF97B0C0 \n"
"    LDR     R8, =0xFFAC1B4C \n"
"    TST     R5, #1 \n"
"    BNE     loc_FFAC1DA8 \n"
"    LDR     R0, [R7, #0xF8] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FFAC1D60 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF998F5C \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x1EF \n"
"    LDRNE   R1, =0xFFAC1E08 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    BL      capt_seq_hook_raw_here \n"         // added

"loc_FFAC1D60:\n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC197C \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFAC1934 \n"
"    CMP     R6, R8 \n"
"    BEQ     loc_FFAC1DA8 \n"
"    BL      sub_FF9981B4 \n"
"    MOV     R3, #0x1FC \n"
"    STR     R3, [SP] \n"
"    LDR     R2, =0x3A98 \n"
"    LDR     R3, =0xFFAC1E08 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOV     R1, #4 \n"
"    BL      sub_FF8919F0 \n"
"    CMP     R0, #0 \n"
"    MOVNE   R2, #0x1FC \n"
"    LDRNE   R1, =0xFFAC1E08 /*'SsStandardCaptureSeq.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"

"loc_FFAC1DA8:\n"
"    MOV     R2, R4 \n"
"    MOV     R1, #1 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF88A048 \n"
"    LDR     R0, [R7, #0x28] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FFAC1DDC \n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF9986E8 \n"
"    B       loc_FFAC1DF0 \n"

"loc_FFAC1DDC:\n"
"    SUBS    R1, R6, R8 \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R5 \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF99867C \n"

"loc_FFAC1DF0:\n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R2-R8,PC} \n"
"    .ltorg\n"         // added
);
}

/*************************************************************/
//** sub_FFAC1894_my @ 0xFFAC1894 - 0xFFAC18D4, length=17
void __attribute__((naked,noinline)) sub_FFAC1894_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    MOV     R4, R0 \n"
"    LDR     R0, =0x1CD30 \n"
"    LDR     R5, =0xCB44 \n"
"    LDR     R0, [R0, #0xEC] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x1CE30 \n"
"    LDRNEH  R0, [R0, #0x8E] \n"
"    CMPNE   R0, #3 \n"
"    LDRNE   R0, [R4, #8] \n"
"    CMPNE   R0, #1 \n"
"    BHI     loc_FFAC18D4 \n"
"    LDR     R1, [R4, #0x1C] \n"
"    MOV     R0, #0 \n"
"    BL      sub_FFA24354 \n"
"    STR     R0, [R5] \n"

"loc_FFAC18D4:\n"
"    BL      wait_until_remote_button_is_released\n" // added
"    BL      capt_seq_hook_set_nr\n"                 // added
"    LDR     R0, [R4, #0x20] \n"
"    LDR     PC, =0xFFAC18D8 \n"  // Continue in firmware
);
}

/*************************************************************/
//** exp_drv_task @ 0xFF8D94A0 - 0xFF8D9B24, length=418
void __attribute__((naked,noinline)) exp_drv_task() {
asm volatile (
"    STMFD   SP!, {R4-R9,LR} \n"
"    SUB     SP, SP, #0x2C \n"
"    LDR     R6, =0x43A8 \n"
"    LDR     R7, =0xBB8 \n"
"    LDR     R4, =0x59AC0 \n"
"    MOV     R0, #0 \n"
"    ADD     R5, SP, #0x1C \n"
"    STR     R0, [SP, #0xC] \n"

"loc_FF8D94C0:\n"
"    LDR     R0, [R6, #0x20] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #0x28 \n"
"    BL      sub_006B8458 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP, #0xC] \n"
"    CMP     R0, #1 \n"
"    BNE     loc_FF8D950C \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x14 \n"
"    CMPNE   R0, #0x15 \n"
"    CMPNE   R0, #0x16 \n"
"    CMPNE   R0, #0x17 \n"
"    BEQ     loc_FF8D9670 \n"
"    CMP     R0, #0x2A \n"
"    BEQ     loc_FF8D95F4 \n"
"    ADD     R1, SP, #0xC \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8D9440 \n"

"loc_FF8D950C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x30 \n"
"    BNE     loc_FF8D9538 \n"
"    BL      sub_FF8DAAEC \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #1 \n"
"    BL      sub_006B81EC /*_SetEventFlag*/ \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #0x2C \n"
"    LDMFD   SP!, {R4-R9,PC} \n"

"loc_FF8D9538:\n"
"    CMP     R1, #0x2F \n"
"    BNE     loc_FF8D9554 \n"
"    LDR     R2, [R0, #0xA8]! \n"
"    LDR     R1, [R0, #4] \n"
"    MOV     R0, R1 \n"
"    BLX     R2 \n"
"    B       loc_FF8D9B1C \n"

"loc_FF8D9554:\n"
"    CMP     R1, #0x28 \n"
"    BNE     loc_FF8D95A4 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8D487C \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_FF884164 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x80 \n"
"    BL      sub_006B8120 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    LDRNE   R2, =0x170B \n"
"    BNE     loc_FF8D9660 \n"

"loc_FF8D9590:\n"
"    LDR     R1, [SP, #0x28] \n"
"    LDR     R0, [R1, #0xAC] \n"
"    LDR     R1, [R1, #0xA8] \n"
"    BLX     R1 \n"
"    B       loc_FF8D9B1C \n"

"loc_FF8D95A4:\n"
"    CMP     R1, #0x29 \n"
"    BNE     loc_FF8D95EC \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8D9440 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    LDR     R0, =0xFF8D488C \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_FF884374 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #0x100 \n"
"    BL      sub_006B8120 /*_WaitForAllEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8D9590 \n"
"    LDR     R2, =0x1715 \n"
"    B       loc_FF8D9660 \n"

"loc_FF8D95EC:\n"
"    CMP     R1, #0x2A \n"
"    BNE     loc_FF8D9604 \n"

"loc_FF8D95F4:\n"
"    LDR     R0, [SP, #0x28] \n"
"    ADD     R1, SP, #0xC \n"
"    BL      sub_FF8D9440 \n"
"    B       loc_FF8D9590 \n"

"loc_FF8D9604:\n"
"    CMP     R1, #0x2D \n"
"    BNE     loc_FF8D961C \n"
"    BL      sub_FF8C2FE4 \n"
"    BL      sub_FF8C3E48 \n"
"    BL      sub_FF8C3928 \n"
"    B       loc_FF8D9590 \n"

"loc_FF8D961C:\n"
"    CMP     R1, #0x2E \n"
"    BNE     loc_FF8D9670 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R1, #4 \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    LDR     R1, =0xFF8D48AC \n"
"    LDR     R0, =0xFFFFF400 \n"
"    MOV     R2, #4 \n"
"    BL      sub_FF8DAB50 \n"
"    BL      sub_FF8C2C78 \n"
"    LDR     R0, [R6, #0x1C] \n"
"    MOV     R2, R7 \n"
"    MOV     R1, #4 \n"
"    BL      sub_006B8034 /*_WaitForAnyEventFlag*/ \n"
"    TST     R0, #1 \n"
"    BEQ     loc_FF8D9590 \n"
"    LDR     R2, =0x174D \n"

"loc_FF8D9660:\n"
"    LDR     R1, =0xFF8D5030 /*'ExpDrv.c'*/ \n"
"    MOV     R0, #0 \n"
"    BL      _DebugAssert \n"
"    B       loc_FF8D9590 \n"

"loc_FF8D9670:\n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R8, #1 \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x12 \n"
"    CMPNE   R1, #0x13 \n"
"    BNE     loc_FF8D96D8 \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8D78A4 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xA8] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DAE2C \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xB4] \n"
"    LDR     R3, [R0, #0xB0] \n"
"    B       loc_FF8D99E0 \n"

"loc_FF8D96D8:\n"
"    CMP     R1, #0x14 \n"
"    CMPNE   R1, #0x15 \n"
"    CMPNE   R1, #0x16 \n"
"    CMPNE   R1, #0x17 \n"
"    BNE     loc_FF8D9780 \n"
"    ADD     R3, SP, #0xC \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8D7B14 \n"
"    CMP     R0, #1 \n"
"    MOV     R9, R0 \n"
"    CMPNE   R9, #5 \n"
"    BNE     loc_FF8D972C \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, R9 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xA8] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R12 \n"
"    B       loc_FF8D9764 \n"

"loc_FF8D972C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R9, #2 \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R12, [R0, #0xA8] \n"
"    LDR     R3, [R0, #0xAC] \n"
"    CMPNE   R9, #6 \n"
"    MOV     R2, R9 \n"
"    ADD     R0, R0, #4 \n"
"    BNE     loc_FF8D9778 \n"
"    BLX     R12 \n"
"    LDR     R0, [SP, #0x28] \n"
"    MOV     R2, SP \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_FF8D9158 \n"

"loc_FF8D9764:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R2, [SP, #0xC] \n"
"    MOV     R1, R9 \n"
"    BL      sub_FF8D93D8 \n"
"    B       loc_FF8D99E8 \n"

"loc_FF8D9778:\n"
"    BLX     R12 \n"
"    B       loc_FF8D99E8 \n"

"loc_FF8D9780:\n"
"    CMP     R1, #0x24 \n"
"    CMPNE   R1, #0x25 \n"
"    BNE     loc_FF8D97CC \n"
"    LDR     R1, [R0, #0x94] \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R1, R0, R1, LSL#2 \n"
"    SUB     R1, R1, #8 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    BL      sub_FF8D67C0 \n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R3, [R0, #0xA8] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8D6C10 \n"
"    B       loc_FF8D99E8 \n"

"loc_FF8D97CC:\n"
"    ADD     R1, R0, #4 \n"
"    LDMIA   R1, {R2,R3,R9} \n"
"    STMIA   R5, {R2,R3,R9} \n"
"    LDR     R1, [R0] \n"
"    CMP     R1, #0x28 \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D9888 \n"
"    B       loc_FF8D9888 \n"
"    B       loc_FF8D9890 \n"
"    B       loc_FF8D9898 \n"
"    B       loc_FF8D9898 \n"
"    B       loc_FF8D9898 \n"
"    B       loc_FF8D9888 \n"
"    B       loc_FF8D9890 \n"
"    B       loc_FF8D9898 \n"
"    B       loc_FF8D9898 \n"
"    B       loc_FF8D98B0 \n"
"    B       loc_FF8D98B0 \n"
"    B       loc_FF8D99BC \n"
"    B       loc_FF8D99C4 \n"
"    B       loc_FF8D99C4 \n"
"    B       loc_FF8D99C4 \n"
"    B       loc_FF8D99C4 \n"
"    B       loc_FF8D99CC \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D98A0 \n"
"    B       loc_FF8D98A8 \n"
"    B       loc_FF8D98A8 \n"
"    B       loc_FF8D98A8 \n"
"    B       loc_FF8D98BC \n"
"    B       loc_FF8D98BC \n"
"    B       loc_FF8D98C4 \n"
"    B       loc_FF8D98FC \n"
"    B       loc_FF8D9934 \n"
"    B       loc_FF8D996C \n"
"    B       loc_FF8D99A4 \n"
"    B       loc_FF8D99A4 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99D0 \n"
"    B       loc_FF8D99AC \n"
"    B       loc_FF8D99B4 \n"

"loc_FF8D9888:\n"
"    BL      sub_FF8D4EB0 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D9890:\n"
"    BL      sub_FF8D5180 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D9898:\n"
"    BL      sub_FF8D53C0 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D98A0:\n"
"    BL      sub_FF8D5708 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D98A8:\n"
"    BL      sub_FF8D5938 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D98B0:\n"
"    BL      sub_FF8D5D28_my \n"  // --> Patched. Old value = 0xFF8D5D28.
"    MOV     R8, #0 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D98BC:\n"
"    BL      sub_FF8D5F04 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D98C4:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8D6448 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D98FC:\n"
"    LDRH    R1, [R0, #4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8DAB9C \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D9934:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R0, #6] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R4, #8] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8DACD8 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D996C:\n"
"    LDRH    R1, [R4] \n"
"    STRH    R1, [SP, #0x1C] \n"
"    LDRH    R1, [R4, #2] \n"
"    STRH    R1, [SP, #0x1E] \n"
"    LDRH    R1, [R4, #4] \n"
"    STRH    R1, [SP, #0x20] \n"
"    LDRH    R1, [R4, #6] \n"
"    STRH    R1, [SP, #0x22] \n"
"    LDRH    R1, [R0, #0xC] \n"
"    STRH    R1, [SP, #0x24] \n"
"    LDRH    R1, [R4, #0xA] \n"
"    STRH    R1, [SP, #0x26] \n"
"    BL      sub_FF8DAD84 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D99A4:\n"
"    BL      sub_FF8D655C \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D99AC:\n"
"    BL      sub_FF8D6D28 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D99B4:\n"
"    BL      sub_FF8D70D0 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D99BC:\n"
"    BL      sub_FF8D7340 \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D99C4:\n"
"    BL      sub_FF8D750C \n"
"    B       loc_FF8D99D0 \n"

"loc_FF8D99CC:\n"
"    BL      sub_FF8D7684 \n"

"loc_FF8D99D0:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R1, [R0, #0x94] \n"
"    LDR     R2, [R0, #0xAC] \n"
"    LDR     R3, [R0, #0xA8] \n"

"loc_FF8D99E0:\n"
"    ADD     R0, R0, #4 \n"
"    BLX     R3 \n"

"loc_FF8D99E8:\n"
"    LDR     R0, [SP, #0x28] \n"
"    LDR     R0, [R0] \n"
"    CMP     R0, #0x10 \n"
"    BEQ     loc_FF8D9A20 \n"
"    BGT     loc_FF8D9A10 \n"
"    CMP     R0, #1 \n"
"    CMPNE   R0, #4 \n"
"    CMPNE   R0, #0xE \n"
"    BNE     loc_FF8D9A54 \n"
"    B       loc_FF8D9A20 \n"

"loc_FF8D9A10:\n"
"    CMP     R0, #0x13 \n"
"    CMPNE   R0, #0x17 \n"
"    CMPNE   R0, #0x1A \n"
"    BNE     loc_FF8D9A54 \n"

"loc_FF8D9A20:\n"
"    LDRSH   R0, [R4] \n"
"    CMN     R0, #0xC00 \n"
"    LDRNESH R1, [R4, #8] \n"
"    CMNNE   R1, #0xC00 \n"
"    STRNEH  R0, [SP, #0x1C] \n"
"    STRNEH  R1, [SP, #0x24] \n"
"    BNE     loc_FF8D9A54 \n"
"    ADD     R0, SP, #0x10 \n"
"    BL      sub_FF8DB050 \n"
"    LDRH    R0, [SP, #0x10] \n"
"    STRH    R0, [SP, #0x1C] \n"
"    LDRH    R0, [SP, #0x18] \n"
"    STRH    R0, [SP, #0x24] \n"

"loc_FF8D9A54:\n"
"    LDR     R0, [SP, #0x28] \n"
"    CMP     R8, #1 \n"
"    BNE     loc_FF8D9AA4 \n"
"    LDR     R1, [R0, #0x94] \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, R1, R1, LSL#1 \n"
"    ADD     R0, R0, R1, LSL#2 \n"
"    SUB     R8, R0, #8 \n"
"    LDR     R0, =0x59AC0 \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006BCD9C \n"
"    LDR     R0, =0x59ACC \n"
"    MOV     R2, #0xC \n"
"    ADD     R1, SP, #0x1C \n"
"    BL      sub_006BCD9C \n"
"    LDR     R0, =0x59AD8 \n"
"    MOV     R2, #0xC \n"
"    MOV     R1, R8 \n"
"    BL      sub_006BCD9C \n"
"    B       loc_FF8D9B1C \n"

"loc_FF8D9AA4:\n"
"    LDR     R0, [R0] \n"
"    MOV     R3, #1 \n"
"    CMP     R0, #0xB \n"
"    BNE     loc_FF8D9AE8 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF8D4C7C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, #0 \n"
"    STRD    R2, [SP] \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, #0 \n"
"    B       loc_FF8D9B18 \n"

"loc_FF8D9AE8:\n"
"    MOV     R2, #1 \n"
"    STRD    R2, [SP] \n"
"    MOV     R3, R2 \n"
"    MOV     R1, R2 \n"
"    MOV     R0, R2 \n"
"    BL      sub_FF8D4C7C \n"
"    MOV     R3, #1 \n"
"    MOV     R2, R3 \n"
"    MOV     R1, R3 \n"
"    MOV     R0, R3 \n"
"    STR     R3, [SP] \n"
"    STR     R3, [SP, #4] \n"

"loc_FF8D9B18:\n"
"    BL      sub_FF8D4DF8 \n"

"loc_FF8D9B1C:\n"
"    LDR     R0, [SP, #0x28] \n"
"    BL      sub_FF8DAAEC \n"
"    B       loc_FF8D94C0 \n"
);
}

/*************************************************************/
//** sub_FF8D5D28_my @ 0xFF8D5D28 - 0xFF8D5DEC, length=50
void __attribute__((naked,noinline)) sub_FF8D5D28_my() {
asm volatile (
"    STMFD   SP!, {R4-R8,LR} \n"
"    LDR     R7, =0x43A8 \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R7, #0x1C] \n"
"    MOV     R1, #0x3E \n"
"    BL      sub_006B8234 /*_ClearEventFlag*/ \n"
"    MOV     R2, #0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    MOV     R3, #1 \n"
"    MOV     R1, R2 \n"
"    BL      sub_FF8D4914 \n"
"    MOV     R6, R0 \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8D4ADC \n"
"    LDRSH   R0, [R4, #8] \n"
"    BL      sub_FF8D4B34 \n"
"    LDRSH   R0, [R4, #0xA] \n"
"    BL      sub_FF8D4B8C \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF8D4BE4 \n"
"    MOV     R5, R0 \n"
"    LDR     R0, [R4] \n"
"    LDR     R8, =0x59AD8 \n"
"    CMP     R0, #0xB \n"
"    MOVEQ   R6, #0 \n"
"    MOVEQ   R5, R6 \n"
"    BEQ     loc_FF8D5DC0 \n"
"    CMP     R6, #1 \n"
"    BNE     loc_FF8D5DC0 \n"
"    LDRSH   R0, [R4, #4] \n"
"    LDR     R1, =0xFF8D486C \n"
"    MOV     R2, #2 \n"
"    BL      sub_FF8841EC \n"
"    STRH    R0, [R4, #4] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R7, #0x28] \n"
"    B       loc_FF8D5DC8 \n"

"loc_FF8D5DC0:\n"
"    LDRH    R0, [R8] \n"
"    STRH    R0, [R4, #4] \n"

"loc_FF8D5DC8:\n"
"    CMP     R5, #1 \n"
"    LDRNEH  R0, [R8, #8] \n"
"    BNE     loc_FF8D5DE4 \n"
"    LDRSH   R0, [R4, #0xC] \n"
"    LDR     R1, =0xFF8D48F0 \n"
"    MOV     R2, #0x20 \n"
"    BL      sub_FF8DAB58 \n"

"loc_FF8D5DE4:\n"
"    STRH    R0, [R4, #0xC] \n"
"    LDRSH   R0, [R4, #6] \n"
"    BL      sub_FF8C2CF0_my \n"  // --> Patched. Old value = 0xFF8C2CF0.
"    LDR     PC, =0xFF8D5DF0 \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8C2CF0_my @ 0xFF8C2CF0 - 0xFF8C2D64, length=30
void __attribute__((naked,noinline)) sub_FF8C2CF0_my() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    LDR     R5, =0x3FFC \n"
"    MOV     R4, R0 \n"
"    LDR     R0, [R5, #4] \n"
"    CMP     R0, #1 \n"
"    MOVNE   R2, #0x168 \n"
"    LDRNE   R1, =0xFF8C2AA0 /*'Shutter.c'*/ \n"
"    MOVNE   R0, #0 \n"
"    BLNE    _DebugAssert \n"
"    CMN     R4, #0xC00 \n"
"    LDREQSH R4, [R5, #2] \n"
"    CMN     R4, #0xC00 \n"
"    LDREQ   R2, =0x16E \n"
"    LDREQ   R1, =0xFF8C2AA0 /*'Shutter.c'*/ \n"
"    MOVEQ   R0, #0 \n"
"    STRH    R4, [R5, #2] \n"
"    BLEQ    _DebugAssert \n"
"    MOV     R0, R4 \n"
"    BL      apex2us \n"  // --> Patched. Old value = _apex2us.
"    MOV     R4, R0 \n"
//"  BL      _sub_FF919240 \n"  // --> Nullsub call removed.
"    MOV     R0, R4 \n"
"    BL      sub_FF91C31C \n"
"    TST     R0, #1 \n"
"    LDMEQFD SP!, {R4-R6,PC} \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    LDR     R2, =0x173 \n"
"    LDR     R1, =0xFF8C2AA0 /*'Shutter.c'*/ \n"
"    MOV     R0, #0 \n"
"    B       _DebugAssert \n"
);
}
