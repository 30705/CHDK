/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

/*************************************************************/
//** movie_record_task @ 0xFF17FC00 - 0xFF17FD78, length=95
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R2-R10,LR} \n"
"    LDR     R6, =0xFF17E970 \n"
"    LDR     R7, =0xFF17F658 \n"
"    LDR     R4, =0x7098 \n"
"    LDR     R9, =0x67F \n"
"    LDR     R10, =0x2710 \n"
"    MOV     R8, #1 \n"
"    MOV     R5, #0 \n"

"loc_FF17FC20:\n"
"    LDR     R0, [R4, #0x24] \n"
"    MOV     R2, #0 \n"
"    ADD     R1, SP, #4 \n"
"    BL      sub_FF02ADD8 \n"
"    LDR     R0, [R4, #0x2C] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, [R4, #0xC] \n"
"    CMPNE   R0, #2 \n"
"    LDRNE   R0, [R4, #0x44] \n"
"    CMPNE   R0, #6 \n"
"    BNE     loc_FF17FD5C \n"
"    LDR     R0, [SP, #4] \n"
"    LDR     R1, [R0] \n"
"    SUB     R1, R1, #2 \n"
"    CMP     R1, #0xD \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF17FD5C \n"
"    B       loc_FF17FCFC \n"
"    B       loc_FF17FD20 \n"
"    B       loc_FF17FD30 \n"
"    B       loc_FF17FD38 \n"
"    B       loc_FF17FD40 \n"
"    B       loc_FF17FD48 \n"
"    B       loc_FF17FD04 \n"
"    B       loc_FF17FD50 \n"
"    B       loc_FF17FD10 \n"
"    B       loc_FF17FD5C \n"
"    B       loc_FF17FD58 \n"
"    B       loc_FF17FCC8 \n"
"    B       loc_FF17FC98 \n"

"loc_FF17FC98:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R5, [R4, #0x34] \n"
"    STRH    R5, [R4, #6] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    MOV     R0, #6 \n"
"    STR     R0, [R4, #0x44] \n"
"    B       loc_FF17FCE8 \n"

"loc_FF17FCC8:\n"
"    STR     R5, [R4, #0x40] \n"
"    STR     R5, [R4, #0x30] \n"
"    STR     R6, [R4, #0xD8] \n"
"    STR     R7, [R4, #0xF0] \n"
"    LDR     R0, [R4, #0xC] \n"
"    ADD     R0, R0, #1 \n"
"    STR     R0, [R4, #0xC] \n"
"    STR     R8, [R4, #0x44] \n"

"loc_FF17FCE8:\n"
"    LDR     R2, =0xFF17DFAC \n"
"    LDR     R1, =0xB3608 \n"
"    LDR     R0, =0xFF17E0C0 \n"
"    BL      sub_FF0449C8 \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FCFC:\n"
"    BL      sub_FF17F23C_my \n"  // --> Patched. Old value = 0xFF17F23C.
"    B       loc_FF17FD5C \n"

"loc_FF17FD04:\n"
"    LDR     R1, [R4, #0xF0] \n"
"    BLX     R1 \n"

"    LDR     R0, =0x711C\n"         //added - Found @FF17FB5C
"    BL      set_quality\n"         //added

"    B       loc_FF17FD5C \n"

"loc_FF17FD10:\n"
"    LDR     R1, [R0, #0x18] \n"
"    LDR     R0, [R0, #4] \n"
"    BL      sub_FF304FB4 \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD20:\n"
"    LDR     R0, [R4, #0x44] \n"
"    CMP     R0, #5 \n"
"    STRNE   R8, [R4, #0x34] \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD30:\n"
"    BL      sub_FF17E64C \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD38:\n"
"    BL      sub_FF17E360 \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD40:\n"
"    BL      sub_FF17E118 \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD48:\n"
"    BL      sub_FF17DD40 \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD50:\n"
"    BL      sub_FF17DCC0 \n"
"    B       loc_FF17FD5C \n"

"loc_FF17FD58:\n"
"    BL      sub_FF1802AC \n"

"loc_FF17FD5C:\n"
"    LDR     R1, [SP, #4] \n"
"    LDR     R3, =0xFF17DA24 \n"
"    STR     R5, [R1] \n"
"    STR     R9, [SP] \n"
"    LDR     R0, [R4, #0x28] \n"
"    MOV     R2, R10 \n"
"    BL      sub_FF02B750 \n"
"    B       loc_FF17FC20 \n"
);
}

/*************************************************************/
//** sub_FF17F23C_my @ 0xFF17F23C - 0xFF17F49C, length=153
void __attribute__((naked,noinline)) sub_FF17F23C_my() {
asm volatile (
"    STMFD   SP!, {R0-R8,LR} \n"
"    LDR     R6, =0x7098 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R6, #0x34] \n"
"    STR     R0, [R6, #0x38] \n"
"    MOV     R0, R6 \n"
"    LDR     R0, [R0, #0x5C] \n"
"    LDRH    R1, [R6, #6] \n"
"    MOV     R3, #0x3E8 \n"
"    MUL     R0, R3, R0 \n"
"    CMP     R1, #0 \n"
"    MOV     R2, #1 \n"
"    BNE     loc_FF17F280 \n"
"    LDR     R1, [R6, #0x90] \n"
"    CMP     R1, #0 \n"
"    BNE     loc_FF17F290 \n"
"    B       loc_FF17F288 \n"

"loc_FF17F280:\n"
"    CMP     R1, #3 \n"
"    BNE     loc_FF17F290 \n"

"loc_FF17F288:\n"
"    STR     R2, [R6, #0x48] \n"
"    B       loc_FF17F29C \n"

"loc_FF17F290:\n"
"    MOV     R1, #0x3E8 \n"
"    BL      sub_FF3CA58C \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF17F29C:\n"
"    LDR     R4, =0xB363C \n"
"    MOV     R7, #2 \n"
"    LDR     R0, [R4, #8] \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF17F304 \n"
"    LDR     R0, [R6, #0x58] \n"
"    MOV     R1, #4 \n"
"    CMP     R0, #0x18 \n"
"    BEQ     loc_FF17F498 \n"
"    BGT     loc_FF17F2E0 \n"
"    CMP     R0, #0xA \n"
"    CMPNE   R0, #0xF \n"
"    STREQ   R7, [R4, #0x14] \n"
"    BEQ     loc_FF17F304 \n"
"    CMP     R0, #0x14 \n"
"    BNE     loc_FF17F2F8 \n"
"    B       loc_FF17F498 \n"

"loc_FF17F2E0:\n"
"    CMP     R0, #0x1E \n"
"    BEQ     loc_FF17F498 \n"
"    CMP     R0, #0x3C \n"
"    MOVEQ   R0, #8 \n"
"    STREQ   R0, [R4, #0x14] \n"
"    BEQ     loc_FF17F304 \n"

"loc_FF17F2F8:\n"
"    LDR     R1, =0x777 \n"
"    LDR     R0, =0xFF17DA24 \n"
"    BL      _DebugAssert \n"

"loc_FF17F304:\n"
"    LDR     R2, =0x709A \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xAA \n"
"    BL      sub_FF088180 \n"
"    LDR     R2, =0x709C \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #2 \n"
"    MOV     R1, #0xA9 \n"
"    BL      sub_FF088180 \n"
"    LDR     R2, =0x70E8 \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA2 \n"
"    BL      sub_FF088180 \n"
"    LDR     R2, =0x70EC \n"
"    LDR     R0, [R6, #0xB8] \n"
"    MOV     R3, #4 \n"
"    MOV     R1, #0xA3 \n"
"    BL      sub_FF088180 \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R2, =0x7198 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, #0xD \n"
"    BLNE    sub_FF08268C \n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R5, =0x7198 \n"
"    LDR     R8, =0xB3624 \n"
"    CMP     R0, #2 \n"
"    CMPNE   R0, #3 \n"
"    BNE     loc_FF17F400 \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDRNE   R0, =0x443FC000 \n"
"    STRNE   R0, [R5] \n"
"    BNE     loc_FF17F400 \n"
"    LDR     R0, =0x460B8600 \n"
"    LDR     R1, =0x10959E0 \n"
"    STR     R0, [R5] \n"
"    STR     R1, [R5, #4] \n"
"    LDMIA   R8, {R1,R2} \n"
"    STR     R0, [R6, #0xA0] \n"
"    MUL     R1, R2, R1 \n"
"    MOV     R2, #0 \n"
"    MOV     R3, R1, LSL#1 \n"
"    ADD     R1, R0, R3 \n"
"    STR     R3, [R6, #0x9C] \n"
"    STR     R1, [R6, #0xA4] \n"
"    STMEA   SP, {R1-R3} \n"
"    MOV     R3, R2 \n"
"    MOV     R2, #9 \n"
"    MOV     R1, #5 \n"
"    MOV     R0, #0x10 \n"
"    BL      sub_FF2AF624 \n"
"    LDR     R1, [R5] \n"
"    LDR     R0, [R6, #0x9C] \n"
"    ADD     R1, R1, R0, LSL#1 \n"
"    STR     R1, [R5] \n"
"    LDR     R1, [R5, #4] \n"
"    RSB     R0, R0, #0 \n"
"    ADD     R0, R1, R0, LSL#1 \n"
"    STR     R0, [R5, #4] \n"

"loc_FF17F400:\n"
"    LDR     R3, =0xFF17F208 \n"
"    LDMIA   R5, {R0,R1} \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =0xB363C \n"
"    SUB     R2, R3, #0x18 \n"
"    BL      sub_FF303918_my \n"  // --> Patched. Old value = 0xFF303918.
"    LDR     R3, [R6, #0xB8] \n"
"    STR     R3, [SP] \n"
"    LDR     R0, [R6, #0x90] \n"
"    LDRD    R2, [R6, #0xF8] \n"
"    BL      sub_FF303D2C \n"
"    LDR     R0, [R6, #0x64] \n"
"    LDR     R3, =0x7120 \n"
"    AND     R1, R0, #0xFF \n"
"    LDR     R0, [R8] \n"
"    SUB     R2, R3, #4 \n"
"    BL      sub_FF301A04 \n"
"    LDRH    R0, [R6, #6] \n"
"    CMP     R0, #2 \n"
"    LDREQ   R0, =0xFF17EEDC \n"
"    STREQ   R0, [R6, #0xF0] \n"
"    LDR     R0, [R6, #0x90] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0xFF17EB20 \n"
"    STREQ   R1, [R6, #0xF0] \n"
"    LDR     R2, [R6, #0xC] \n"
"    LDR     R1, =0xFF4152BC \n"
"    CMP     R2, #2 \n"
"    BNE     sub_FF17F4A0 \n"
"    LDR     R0, [R6, #0x4C] \n"
"    ADD     R0, R1, R0, LSL#3 \n"
"    LDR     R1, [R8, #0xC] \n"
"    LDR     R0, [R0, R1, LSL#2] \n"
"    BL      sub_FF2B56C0 \n"
"    LDR     R0, =0xFF17EA4C \n"
"    MOV     R1, #0 \n"
"    BL      sub_FF2B5BD4 \n"
"    B       sub_FF17F4DC \n"

"loc_FF17F498:\n"
"    STR     R1, [R4, #0x14] \n"
"    B       loc_FF17F304 \n"
);
}

/*************************************************************/
//** sub_FF303918_my @ 0xFF303918 - 0xFF303CD0, length=239
void __attribute__((naked,noinline)) sub_FF303918_my() {
asm volatile (
"    STMFD   SP!, {R0-R12,LR} \n"
"    MOV     R9, R0 \n"
"    LDR     R0, [R2, #0x10] \n"
"    LDR     R8, [SP, #0x38] \n"
"    CMP     R0, #0 \n"
"    LDREQ   R1, =0x32A \n"
"    LDREQ   R0, =0xFF3028EC \n"
"    MOV     R5, #0 \n"
"    MOV     R4, R2 \n"
"    MOV     R10, R3 \n"
"    MOV     R7, R5 \n"
"    BLEQ    _DebugAssert \n"
"    LDR     R6, =0xCF78 \n"
"    LDR     R0, [R4] \n"
"    MOV     R11, #0x1E \n"
"    STR     R0, [R6, #0xD0] \n"
"    LDR     R0, [R4, #4] \n"
"    STR     R0, [R6, #0xD4] \n"
"    LDR     R0, [R4, #0x10] \n"
"    STR     R0, [R6, #0xE0] \n"
"    LDR     R1, [R4, #8] \n"
"    LDR     R0, =0x7530 \n"
"    CMP     R1, #0xB \n"
"    ADDCC   PC, PC, R1, LSL#2 \n"
"    B       loc_FF303A04 \n"
"    B       loc_FF3039B8 \n"
"    B       loc_FF3039A8 \n"
"    B       loc_FF3039E0 \n"
"    B       loc_FF3039F4 \n"
"    B       loc_FF303A04 \n"
"    B       loc_FF303A04 \n"
"    B       loc_FF303A04 \n"
"    B       loc_FF303A04 \n"
"    B       loc_FF3039D8 \n"
"    B       loc_FF3039D0 \n"
"    B       loc_FF3039C0 \n"

"loc_FF3039A8:\n"
"    LDR     R7, =0x5DC0 \n"
"    MOV     R0, #0x18 \n"
"    STR     R7, [R6, #0x12C] \n"
"    B       loc_FF3039EC \n"

"loc_FF3039B8:\n"
"    MOV     R7, R0 \n"
"    B       loc_FF3039C4 \n"

"loc_FF3039C0:\n"
"    LDR     R7, =0x5DC \n"

"loc_FF3039C4:\n"
"    STR     R0, [R6, #0x12C] \n"
"    STR     R11, [R6, #0xD8] \n"
"    B       loc_FF303A10 \n"

"loc_FF3039D0:\n"
"    LDR     R7, =0xBB8 \n"
"    B       loc_FF3039C4 \n"

"loc_FF3039D8:\n"
"    LDR     R7, =0x1770 \n"
"    B       loc_FF3039C4 \n"

"loc_FF3039E0:\n"
"    LDR     R7, =0x36EE800 \n"  // --> Patched. Old value = 0x3A980. 2hrs, original = 240000 (30 secs)
"    STR     R0, [R6, #0x12C] \n"
"    MOV     R0, #0xF0 \n"

"loc_FF3039EC:\n"
"    STR     R0, [R6, #0xD8] \n"
"    B       loc_FF303A10 \n"

"loc_FF3039F4:\n"
"    STR     R0, [R6, #0x12C] \n"
"    LDR     R7, =0x1B77400 \n"  // --> Patched. Old value = 0x1D4C0. 2hrs, original = 120000 (30 secs)
"    MOV     R0, #0x78 \n"
"    B       loc_FF3039EC \n"

"loc_FF303A04:\n"
"    LDR     R1, =0x35B \n"
"    LDR     R0, =0xFF3028EC \n"
"    BL      _DebugAssert \n"

"loc_FF303A10:\n"
"    LDR     R0, [R6, #0xD8] \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0xE0F. 2hrs, original = 3599 (59:59)
"    MOV     R0, R0, LSR#1 \n"
"    STR     R0, [R6, #0xDC] \n"
"    LDR     R0, [R10] \n"
"    STR     R0, [R6, #0xE4] \n"
"    LDRH    R0, [R10, #0x10] \n"
"    STR     R0, [R6, #0xE8] \n"
"    LDR     R0, [R10, #4] \n"
"    STRH    R0, [R6, #2] \n"
"    LDR     R0, [R10, #8] \n"
"    STRH    R0, [R6, #4] \n"
"    LDR     R0, [R10, #0x14] \n"
"    STR     R0, [R6, #0xEC] \n"
"    STR     R8, [R6, #0x128] \n"
"    LDR     R0, [R6, #0xD0] \n"
"    CMP     R0, #0x140 \n"
"    MOVEQ   R0, #0x20000 \n"
"    MOVEQ   R5, #1 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FF303AA4 \n"
"    CMP     R0, #0x280 \n"
"    LDREQ   R0, =0x7A760 \n"
"    MOVEQ   R5, #2 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FF303AA4 \n"
"    CMP     R0, #0x500 \n"
"    LDREQ   R0, =0x11DA50 \n"
"    LDR     R1, =0x1C20 \n"  // --> Patched. Old value = 0x257. 2hrs, original = 599 (9:59)
"    MOVEQ   R5, #4 \n"
"    STREQ   R0, [R6, #0xAC] \n"
"    BEQ     loc_FF303AA4 \n"
"    CMP     R0, #0x780 \n"
"    BNE     loc_FF303AAC \n"
"    LDR     R1, =600 \n"           // Added - 10mins, original = 599 (9:59)
"    MOV     R0, #0x200000 \n"
"    MOV     R5, #5 \n"
"    STR     R0, [R6, #0xAC] \n"

"loc_FF303AA4:\n"
"    STR     R1, [R6, #0x4C] \n"
"    B       loc_FF303AB8 \n"

"loc_FF303AAC:\n"
"    LDR     R1, =0x383 \n"
"    LDR     R0, =0xFF3028EC \n"
"    BL      _DebugAssert \n"

"loc_FF303AB8:\n"
"    LDR     R0, [R6, #0x4C] \n"
"    LDR     R1, =0x138D \n"
"    MUL     R0, R7, R0 \n"
"    BL      sub_FF3CA58C \n"
"    ADD     R0, R0, #1 \n"
"    ADD     R0, R0, R0, LSL#2 \n"
"    STR     R0, [R6, #0x48] \n"
"    LDR     R8, [R4, #8] \n"
"    CMP     R8, #2 \n"
"    CMPNE   R8, #3 \n"
"    BNE     loc_FF303B10 \n"
"    RSB     R0, R7, R7, LSL#4 \n"
"    LDR     R1, =0x3E9 \n"
"    MOV     R0, R0, LSL#1 \n"
"    STR     R11, [R6, #0x4C] \n"
"    BL      sub_FF3CA58C \n"
"    LDR     R1, [R6, #0xE0] \n"
"    MOV     R7, R1 \n"
"    BL      sub_FF3CA58C \n"
"    ADD     R0, R0, #1 \n"
"    MUL     R0, R7, R0 \n"
"    STR     R0, [R6, #0x48] \n"

"loc_FF303B10:\n"
"    LDR     R0, [R4, #0xC] \n"
"    LDR     R7, [R10, #0xC] \n"
"    MOVS    R1, R0 \n"
"    MOV     R0, R7, LSR#1 \n"
"    STR     R7, [R6, #0x94] \n"
"    STR     R0, [R6, #0x98] \n"
"    ADD     R0, R9, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R6, #0xF4] \n"
"    LDR     R2, [R6, #0x48] \n"
"    MOVNE   R1, #1 \n"
"    MOV     R2, R2, LSL#2 \n"
"    ADD     R3, R0, R2 \n"
"    STR     R3, [R6, #0xF8] \n"
"    LDRH    R12, [R6, #4] \n"
"    LDR     R0, [SP, #4] \n"
"    ADD     R2, R2, R3 \n"
"    CMP     R12, #0 \n"
"    ADD     R0, R0, R9 \n"
"    BEQ     loc_FF303C8C \n"
"    STR     R2, [R6, #0xFC] \n"
"    LDR     R3, [R6, #0x4C] \n"
"    LDR     R9, =0x11B7E0 \n"
"    ADD     R2, R2, R3, LSL#3 \n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R6, #0x100] \n"
"    LDR     R3, [R6, #0xAC] \n"
"    LDR     R11, =0xD0F8 \n"
"    ADD     R2, R2, R3 \n"
"    ADD     R3, R2, #0x100000 \n"
"    STR     R2, [R6, #0x78] \n"
"    SUB     R0, R0, R3 \n"
"    RSB     R2, R7, #0 \n"
"    ADD     R0, R0, R2, LSL#1 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R3, [R6, #0x104] \n"
"    ADD     R8, R3, R0 \n"
"    STR     R0, [R6, #0x110] \n"
"    STR     R8, [R6, #0x108] \n"
"    MOV     R2, #0 \n"
"    ADD     R10, R9, #0x10 \n"
"    STR     R8, [R6, #0x10C] \n"

"loc_FF303BC0:\n"
"    MLA     R0, R2, R7, R8 \n"
"    ADD     R12, R9, R2, LSL#3 \n"
"    ADD     R0, R0, #3 \n"
"    BIC     R0, R0, #3 \n"
"    STR     R0, [R11, R2, LSL#2] \n"
"    MOV     R0, #0 \n"
"    ADD     R6, R10, R2, LSL#3 \n"

"loc_FF303BDC:\n"
"    STR     R3, [R12, R0, LSL#2] \n"
"    STR     R3, [R6, R0, LSL#2] \n"
"    ADD     R0, R0, #1 \n"
"    CMP     R0, #2 \n"
"    BLT     loc_FF303BDC \n"
"    ADD     R2, R2, #1 \n"
"    CMP     R2, #2 \n"
"    BLT     loc_FF303BC0 \n"
"    LDRH    R3, [R4, #0x14] \n"
"    LDR     R2, [R4, #8] \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF0D2708 \n"
"    LDR     R1, =0xCF78 \n"
"    LDR     R2, [R1, #0x94] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R1, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"

"loc_FF303C8C:\n"
"    ADD     R2, R2, #0x1F \n"
"    BIC     R2, R2, #0x1F \n"
"    STR     R2, [R6, #0x100] \n"
"    LDR     R3, [R6, #0xAC] \n"
"    ADD     R2, R2, R3 \n"
"    SUB     R0, R0, R2 \n"
"    MOV     R0, R0, LSR#15 \n"
"    MOV     R0, R0, LSL#15 \n"
"    STR     R2, [R6, #0x104] \n"
"    STR     R0, [R6, #0x110] \n"
"    ADD     R0, R0, R2 \n"
"    STR     R0, [R6, #0x108] \n"
"    LDRH    R3, [R4, #0x14] \n"
"    MOV     R2, R8 \n"
"    MOV     R0, R5 \n"
"    BL      sub_FF0D2708 \n"
"    STR     R0, [R6, #0x8C] \n"
"    LDMFD   SP!, {R0-R12,PC} \n"
);
}
