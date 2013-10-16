/*
 * movie_rec.c - auto-generated by CHDK code_gen.
 */
#include "conf.h"

int *video_quality = &conf.video_quality;
int *video_mode    = &conf.video_mode;

long def_table1[56]={
0x10000,0xC000,0x5800, 0x2000, 0x1C6A, 0x1550,0x9C5,  0x38D,  0x3C45, 0x2D34, 0x14B8, 0x788,  0x5F60, 0x4788,
0x20C9, 0xBE1, 0x8661, 0x64C9, 0x2E31, 0x10CB,0xB21A, 0x8594, 0x3D39, 0x1642, 0xE249, 0xA9B8, 0x4DC9, 0x1C48,
0x117D2,0xD1DF,0x6030, 0x22F9, 0x153D5,0xFEE1,0x74D1, 0x2A79, 0x195F8,0x1307C,0x8B8D, 0x32AA, 0x1E01C,0x16817,
0xA509, 0x3C01,0x2328E,0x1A5ED,0xC160, 0x4637,0x28C99,0x1E975,0xE054, 0x5190, 0x2F08B,0x2346B,0x102AF,0x5E0E
};

long def_table2[12]={0xE666,0xACCD,0x4F33,0x1CCD,-0x170A,-0x1148,-0x7EB,-0x2E1,-0x2BC6,-0x20D5,-0xF0C,-0x579};

long table1[56], table2[12];

void change_video_tables(int a, int b){
 int i;
 for (i=0;i<56;i++) table1[i]=(def_table1[i]*a)/b;
 for (i=0;i<12;i++) table2[i]=(def_table2[i]*a)/b;
}

long CompressionRateTable[]={0x60, 0x5D, 0x5A, 0x57, 0x54, 0x51, 0x4D, 0x48, 0x42, 0x3B, 0x32, 0x29, 0x22, 0x1D, 0x17, 0x14, 0x10, 0xE, 0xB, 9, 7, 6, 5, 4, 3, 2, 1};

/*************************************************************/
//** movie_record_task @ 0xFF9482BC - 0xFF9483B8, length=64
void __attribute__((naked,noinline)) movie_record_task() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    SUB     SP, SP, #4 \n"
"    MOV     R4, SP \n"
"    B       loc_FF94837C \n"

"loc_FF9482CC:\n"
"    LDR     R3, =0x85418 \n"
"    LDR     R2, [R3] \n"
"    CMP     R2, #0 \n"
"    BNE     loc_FF948368 \n"
"    SUB     R3, R12, #1 \n"
"    CMP     R3, #0xA \n"
"    LDRLS   PC, [PC, R3, LSL#2] \n"
"    B       loc_FF948368 \n"
"    .long   loc_FF948318 \n"
"    .long   loc_FF948320 \n"
"    .long   loc_FF948338 \n"
"    .long   loc_FF948340 \n"
"    .long   loc_FF948348 \n"
"    .long   loc_FF948328 \n"
"    .long   loc_FF948350 \n"
"    .long   loc_FF948330 \n"
"    .long   loc_FF948368 \n"
"    .long   loc_FF948360 \n"
"    .long   loc_FF948358 \n"

"loc_FF948318:\n"
"    BL      sub_FF9483FC \n"
"    B       loc_FF948364 \n"

"loc_FF948320:\n"
"    BL      unlock_optical_zoom\n"  //+
"    BL      sub_FF948630 \n"
"    B       loc_FF948364 \n"

"loc_FF948328:\n"
"    BL      sub_FF948AC0_my \n"  // --> Patched. Old value = 0xFF948AC0.
"    B       loc_FF948364 \n"

"loc_FF948330:\n"
"    BL      sub_FF948F14 \n"
"    B       loc_FF948364 \n"

"loc_FF948338:\n"
"    BL      sub_FF948D38 \n"
"    B       loc_FF948364 \n"

"loc_FF948340:\n"
"    BL      sub_FF949120 \n"
"    B       loc_FF948364 \n"

"loc_FF948348:\n"
"    BL      sub_FF9492E4 \n"
"    B       loc_FF948364 \n"

"loc_FF948350:\n"
"    BL      sub_FF948FD4 \n"
"    B       loc_FF948364 \n"

"loc_FF948358:\n"
"    BL      sub_FF9490B4 \n"
"    B       loc_FF948364 \n"

"loc_FF948360:\n"
"    BL      sub_FF948D88 \n"

"loc_FF948364:\n"
"    LDR     R1, [SP] \n"

"loc_FF948368:\n"
"    LDR     R3, =0x85348 \n"
"    MOV     R2, #0 \n"
"    STR     R2, [R1] \n"
"    LDR     R0, [R3] \n"
"    BL      sub_FF822FA0 /*_PostMessageQueue*/ \n"

"loc_FF94837C:\n"
"    LDR     R3, =0x85344 \n"
"    MOV     R1, R4 \n"
"    LDR     R0, [R3] \n"
"    MOV     R2, #0 \n"
"    BL      sub_FF822B88 /*_ReceiveMessageQueue*/ \n"
"    LDR     R0, [SP] \n"
"    LDR     R12, [R0] \n"
"    CMP     R12, #0xC \n"
"    MOV     R1, R0 \n"
"    BNE     loc_FF9482CC \n"
"    LDR     R3, =0x8533C \n"
"    LDR     R0, [R3] \n"
"    BL      _GiveSemaphore \n"
"    BL      _ExitTask \n"
"    ADD     SP, SP, #4 \n"
"    LDMFD   SP!, {R4,PC} \n"
);
}

/*************************************************************/
//** sub_FF948AC0_my @ 0xFF948AC0 - 0xFF948C70, length=109
void __attribute__((naked,noinline)) sub_FF948AC0_my() {
asm volatile (
"    STMFD   SP!, {R4-R11,LR} \n"
"    LDR     R5, =0x85434 \n"
"    SUB     SP, SP, #0x34 \n"
"    LDR     R3, [R5] \n"
"    CMP     R3, #3 \n"
"    MOV     R4, R0 \n"
"    MOVEQ   R3, #4 \n"
"    STREQ   R3, [R5] \n"
"    LDR     R3, =0x854DC \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3] \n"
"    LDR     R2, [R5] \n"
"    CMP     R2, #4 \n"
"    BNE     loc_FF948C6C \n"
"    ADD     R0, SP, #0x30 \n"
"    ADD     R1, SP, #0x2C \n"
"    ADD     R2, SP, #0x28 \n"
"    ADD     R3, SP, #0x24 \n"
"    BL      sub_FF94A280 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF948B3C \n"
"    LDR     R3, =0x85420 \n"
"    LDR     R2, [R3] \n"
"    CMP     R2, #1 \n"
"    BNE     loc_FF948B50 \n"
"    LDR     R2, =0x85470 \n"
"    LDR     R1, =0x85448 \n"
"    LDR     R12, [R2] \n"
"    LDR     R3, [R1] \n"
"    CMP     R12, R3 \n"
"    BCC     loc_FF948B50 \n"

"loc_FF948B3C:\n"
"    BL      sub_FF948CB0 \n"
"    BL      sub_FF948EE4 \n"
"    MOV     R3, #5 \n"
"    STR     R3, [R5] \n"
"    B       loc_FF948C6C \n"

"loc_FF948B50:\n"
"    LDR     R12, =0x85478 \n"
"    LDR     R11, =0x85484 \n"
"    LDMIB   R4, {R0-R2} \n"
"    LDR     R10, [R12] \n"
"    LDR     R7, [R11] \n"
"    LDR     R4, [SP, #0x2C] \n"
"    LDR     R5, [SP, #0x28] \n"
"    LDR     R6, [SP, #0x24] \n"
"    LDR     R8, =0x85424 \n"
"    LDR     R3, [SP, #0x30] \n"
"    ADD     R12, SP, #0x20 \n"
"    ADD     LR, SP, #0x1C \n"
"    MOV     R9, #1 \n"
"    STMEA   SP, {R4-R6,R12} \n"
"    STR     R10, [SP, #0x10] \n"
"    STR     R7, [SP, #0x14] \n"
"    STR     LR, [SP, #0x18] \n"
"    STR     R9, [R8] \n"
"    BL      sub_FF89A5B8 \n"
"    LDR     R3, =0x8533C \n"
"    MOV     R1, #0x3E8 \n"
"    LDR     R0, [R3] \n"
"    BL      _TakeSemaphore \n"
"    CMP     R0, #9 \n"
"    BNE     loc_FF948BC4 \n"
"    BL      sub_FF94AA40 \n"
"    LDR     R3, =0x85434 \n"
"    LDR     R0, =0xFF948AA8 \n"
"    B       loc_FF948BDC \n"

"loc_FF948BC4:\n"
"    LDR     R5, [SP, #0x1C] \n"
"    CMP     R5, #0 \n"
"    BEQ     loc_FF948BE8 \n"
"    BL      sub_FF94AA40 \n"
"    LDR     R3, =0x85434 \n"
"    LDR     R0, =0xFF948AB4 \n"

"loc_FF948BDC:\n"
"    STR     R9, [R3] \n"
"    BL      sub_FF95D754 \n"
"    B       loc_FF948C6C \n"

"loc_FF948BE8:\n"
"    BL      sub_FF89A72C \n"
"    LDR     R0, [SP, #0x30] \n"
"    LDR     R1, [SP, #0x20] \n"
"    BL      sub_FF94A764 \n"
"    LDR     R4, =0x85470 \n"
"    LDR     R3, [R4] \n"
"    ADD     R3, R3, #1 \n"
"    LDR     R0, [SP, #0x20] \n"
"    MOV     R1, R11 \n"
"    STR     R3, [R4] \n"
"    MOV     R2, R5 \n"
"    BL      sub_FF949648_my \n"  // --> Patched. Old value = 0xFF949648.
"    LDR     R3, =0x8545C \n"
"    LDR     R4, [R4] \n"
"    LDR     R1, [R3] \n"
"    MOV     R0, R4 \n"
"    BL      sub_FFBC3704 \n"
"    CMP     R0, #0 \n"
"    BEQ     loc_FF948C48 \n"
"    LDR     R6, =0x85428 \n"
"    LDR     R3, [R6] \n"
"    CMP     R3, #1 \n"
"    BNE     loc_FF948C60 \n"
"    B       loc_FF948C4C \n"

"loc_FF948C48:\n"
"    LDR     R6, =0x85428 \n"

"loc_FF948C4C:\n"
"    MOV     R0, R4 \n"
"    LDR     R3, =0x854B8 \n"
"    MOV     LR, PC \n"
"    LDR     PC, [R3] \n"
"    STR     R5, [R6] \n"

"loc_FF948C60:\n"
"    LDR     R2, =0x85424 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"

"loc_FF948C6C:\n"
"    ADD     SP, SP, #0x34 \n"
"    LDMFD   SP!, {R4-R11,PC} \n"
);
}

/*************************************************************/
//** sub_FF949648_my @ 0xFF949648 - 0xFF9497AC, length=90
void __attribute__((naked,noinline)) sub_FF949648_my() {
asm volatile (
"    CMP     R2, #1 \n"
"    STMFD   SP!, {R4-R7,LR} \n"
"    MOV     R7, R0 \n"
"    MOV     R6, R1 \n"
//"  MOVEQ   R3, #0x79 \n"
//"  STREQ   R3, [R6] \n"
"    LDREQ   R3, =CompressionRateTable\n" // +
"    LDREQ   R2, [R3,#0x18]\n"            // +
"    STREQ   R2, [R6]\n"                  // +
"    LDMEQFD SP!, {R4-R7,PC} \n"
"    LDR     R12, =0x854E8 \n"
"    LDR     R0, [R12] \n"
"    LDR     R3, =0x854F0 \n"
"    CMP     R0, #0 \n"
"    LDR     R1, [R3] \n"
"    BEQ     loc_FF949690 \n"
"    LDR     R2, =0x854F4 \n"
"    LDR     R3, [R2] \n"
"    CMP     R3, #1 \n"
"    BNE     loc_FF9496A4 \n"
"    B       loc_FF949694 \n"

"loc_FF949690:\n"
"    LDR     R2, =0x854F4 \n"

"loc_FF949694:\n"
"    MOV     R3, #0 \n"
"    STR     R3, [R2] \n"
"    STR     R7, [R12] \n"
"    B       loc_FF949758 \n"

"loc_FF9496A4:\n"
"    LDR     R3, =0x854EC \n"
"    LDR     R2, [R3] \n"
"    LDR     R5, =table1 \n"  // --> Patched. Old value = 0xFF9494B0.
"    MOV     LR, R2, LSL#2 \n"
"    LDR     R3, [R5, LR] \n"
"    LDR     R4, =table2 \n"  // --> Patched. Old value = 0xFF9494EC.
"    RSB     R12, R3, R0 \n"
"    LDR     R2, [R4, LR] \n"
"    CMP     R12, #0 \n"
"    RSB     R0, R2, R0 \n"
"    BLE     loc_FF949704 \n"
"    ADD     R3, R5, #0x14 \n"
"    LDR     R2, [R3, LR] \n"
"    CMP     R2, R12 \n"
"    ADDGE   R1, R1, #1 \n"
"    BGE     loc_FF9496F8 \n"
"    ADD     R3, R5, #0x28 \n"
"    LDR     R2, [R3, LR] \n"
"    CMP     R2, R12 \n"
"    ADDGE   R1, R1, #2 \n"
"    ADDLT   R1, R1, #3 \n"

"loc_FF9496F8:\n"
"    CMP     R1, #0x1A \n"  // --> Patched. Old value = 0xE.
"    MOVGE   R1, #0x1A \n"  // --> Patched. Old value = 0xE.
"    B       loc_FF94973C \n"

"loc_FF949704:\n"
"    CMP     R0, #0 \n"
"    BGE     loc_FF94973C \n"
"    ADD     R3, R4, #0x14 \n"
"    LDR     R2, [R3, LR] \n"
"    CMP     R2, R0 \n"
"    SUBLE   R1, R1, #1 \n"
"    BLE     loc_FF949734 \n"
"    ADD     R3, R4, #0x28 \n"
"    LDR     R2, [R3, LR] \n"
"    CMP     R2, R0 \n"
"    SUBLE   R1, R1, #2 \n"
"    SUBGT   R1, R1, #3 \n"

"loc_FF949734:\n"
"    CMP     R1, #0 \n"
"    MOVLT   R1, #0 \n"

"loc_FF94973C:\n"
"    LDR     R0, =0x854F0 \n"
"    LDR     R3, [R0] \n"
"    CMP     R1, R3 \n"
"    LDRNE   R2, =0x854F4 \n"
"    MOVNE   R3, #1 \n"
"    STRNE   R1, [R0] \n"
"    STRNE   R3, [R2] \n"

"loc_FF949758:\n"
"    LDR     R3, =0x854F0 \n"
"    LDR     R1, =video_mode \n"  // --> Patched. Old value = 0x6F54.
"    LDR     R0, [R3] \n"
"    LDR     R2, =CompressionRateTable \n"  // --> Patched. Old value = 0xFF949474.
"    LDR     R12, [R1] \n"
"    LDR     LR, [R2, R0, LSL#2] \n"
"    LDR     R3, =0x854E8 \n"
"    CMP     R12, #1 \n"
"    STR     R7, [R3] \n"
"    STR     LR, [R6] \n"

"    LDREQ   R3, =video_quality\n"          // +
"    LDREQ   R3, [R3]\n"                    // +
"    LDREQ   R3, [R3]\n"                    // +

"    MOVEQ   R3, #0xB \n"
"    STREQ   R3, [R6] \n"
"    LDMFD   SP!, {R4-R7,PC} \n"
);
}
