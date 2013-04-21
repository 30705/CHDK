#include "conf.h"

void change_video_tables(int a, int b){
}

void  set_quality(int *x){ // -17 highest; +12 lowest
 
 if (conf.video_mode) *x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF969AE4 

void __attribute__((naked,noinline)) movie_record_task(  ) { 
asm volatile (
      "STMFD   SP!, {R2-R10,LR} \n"
      "LDR     R6, =0xFF969014 \n"
      "LDR     R7, =0xFF96950C \n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x66E0 \n"
      "LDR     R9, =0x67F \n"
      "LDR     R10, =0x2710 \n"
      "MOV     R8, #1 \n"
      "MOV     R5, #0 \n"
"loc_FF969B04:\n"
      "LDR     R0, [R4, #0x24] \n"
      "MOV     R2, #0 \n"
      "ADD     R1, SP, #4 \n"
      "BL      sub_FF839B84 \n"
      "LDR     R0, [R4, #0x2C] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R0, [R4, #0xC] \n"
      "CMPNE   R0, #2 \n"
      "LDRNE   R0, [R4, #0x44] \n"
      "CMPNE   R0, #6 \n"
      "BNE     loc_FF969C28 \n"
      "LDR     R0, [SP, #4] \n"
      "LDR     R1, [R0] \n"
      "SUB     R1, R1, #2 \n"
      "CMP     R1, #0xB \n"
      "ADDCC   PC, PC, R1, LSL #2 \n"
      "B       loc_FF969C28 \n"
      "B       loc_FF969BD8 \n" //(01)
      "B       loc_FF969BFC \n" //(02)
      "B       loc_FF969C0C \n" //(03)
      "B       loc_FF969C14 \n" //(04)
      "B       loc_FF969BE0 \n" //(05)
      "B       loc_FF969C1C \n" //(06)
      "B       loc_FF969BEC \n" //(07)
      "B       loc_FF969C28 \n" //(08)
      "B       loc_FF969C24 \n" //(09)
      "B       loc_FF969BA4 \n" //(10)
      "B       loc_FF969B74 \n" //(11)
"loc_FF969B74:\n" //Jump Table entry 11
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R5, [R4, #0x34] \n"
      "STRH    R5, [R4, #6] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xCC] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "MOV     R0, #6 \n"
      "STR     R0, [R4, #0x44] \n"
      "B       loc_FF969BC4 \n"
"loc_FF969BA4:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40] \n"
      "STR     R5, [R4, #0x30] \n"
      "STR     R6, [R4, #0xB4] \n"
      "STR     R7, [R4, #0xCC] \n"
      "LDR     R0, [R4, #0xC] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R4, #0xC] \n"
      "STR     R8, [R4, #0x44] \n"
"loc_FF969BC4:\n"
      "LDR     R2, =0xFF968830 \n"
      "LDR     R1, =0xACE28 \n"
      "LDR     R0, =0xFF968944 \n"
      "BL      sub_FF852C24 \n"
      "B       loc_FF969C28 \n"
"loc_FF969BD8:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF96916C \n"
      "B       loc_FF969C28 \n"
"loc_FF969BE0:\n" //Jump Table entry 05
      "LDR     R1, [R4, #0xCC] \n"
      "BLX     R1 \n"
//begin patch
      "LDR     R0, =0x6764 \n"  // added, 0x6768-0x4 taken from  "loc_FF96950C:" see commented function below.
      "BL      set_quality \n"  // added
      "BL      mute_on_zoom\n"  // added
//end patch
      "B       loc_FF969C28 \n"
"loc_FF969BEC:\n" //Jump Table entry 07
      "LDR     R1, [R0, #0x18] \n"
      "LDR     R0, [R0, #4] \n"
      "BL      sub_FFAAC970 \n"
      "B       loc_FF969C28 \n"
"loc_FF969BFC:\n" //Jump Table entry 02
      "LDR     R0, [R4, #0x44] \n"
      "CMP     R0, #5 \n"
      "STRNE   R8, [R4, #0x34] \n"
      "B       loc_FF969C28 \n"
"loc_FF969C0C:\n" //Jump Table entry 03
      "BL      sub_FF968CD4 \n"
      "B       loc_FF969C28 \n"
"loc_FF969C14:\n" //Jump Table entry 04
      "BL      sub_FF968990 \n"
      "B       loc_FF969C28 \n"
"loc_FF969C1C:\n" //Jump Table entry 06
      "BL      sub_FF9687BC \n"
      "B       loc_FF969C28 \n"
"loc_FF969C24:\n" //Jump Table entry 09
      "BL      sub_FF96A068 \n"
"loc_FF969C28:\n"
      "LDR     R1, [SP, #4] \n"
      "LDR     R3, =0xFF968604 \n"
      "STR     R5, [R1] \n"
      "STR     R9, [SP] \n"
      "LDR     R0, [R4, #0x28] \n"
      "MOV     R2, R10 \n"
      "BL      sub_FF83A4FC \n"
      "B       loc_FF969B04 \n"
	);
}

//This function was used to take values for set_quality
//** sub_FF96950C_my  @ 0xFF96950C 
/*
void __attribute__((naked,noinline)) sub_FF96950C_my(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R11,LR} \n"
      "SUB     SP, SP, #0x64 \n"
      "MOV     R9, #0 \n"
      "LDR     R6, =0x66E0 \n"
      "STR     R9, [SP, #0x54] \n"
      "STR     R9, [SP, #0x4C] \n"
      "STR     R9, [R6, #0xB8] \n"
      "STR     R9, [R6, #0xBC] \n"
      "STR     R9, [R6, #0xC0] \n"
      "MOV     R4, R0 \n"
      "STR     R9, [R6, #0xC4] \n"
      "LDR     R0, [R6, #0x44] \n"
      "MOV     R11, #4 \n"
      "CMP     R0, #3 \n"
      "STREQ   R11, [R6, #0x44] \n"
      "LDR     R0, [R6, #0xB4] \n"
      "MOV     R8, R9 \n"
      "MOV     R5, #1 \n"
      "MOV     R7, R9 \n"
      "BLX     R0 \n"
      "LDR     R0, [R6, #0x44] \n"
      "CMP     R0, #6 \n"
      "BEQ     loc_FF96957C \n"
      "LDR     R1, [R6, #0xC] \n"
      "CMP     R1, #2 \n"
      "BNE     loc_FF9695A4 \n"
      "CMP     R0, #5 \n"
      "BEQ     loc_FF9695B4 \n"
"loc_FF96957C:\n"
      "LDR     R2, =0xFF9693E0 \n"
      "LDR     R1, =0xFF969444 \n"
      "LDR     R0, =0xFF9694A8 \n"
      "MOV     R7, #1 \n"
      "ADD     R3, SP, #0x34 \n"
      "BL      sub_FF853A44 \n"
      "LDR     R0, [R6, #0x44] \n"
      "CMP     R0, #4 \n"
      "MOVNE   R5, #0 \n"
      "B       loc_FF9695C4 \n"
"loc_FF9695A4:\n"
      "CMP     R0, #4 \n"
      "BEQ     loc_FF9695C4 \n"
      "CMP     R1, #2 \n"
      "BNE     loc_FF9695BC \n"
"loc_FF9695B4:\n"
      "MOV     R0, #0 \n"
      "BL      sub_FF853A50 \n"
"loc_FF9695BC:\n"
      "ADD     SP, SP, #0x64 \n"
      "LDMFD   SP!, {R4-R11,PC} \n"
"loc_FF9695C4:\n"
      "LDRH    R0, [R6, #6] \n"
      "CMP     R0, #3 \n"
      "BNE     loc_FF9695E4 \n"
      "LDR     R0, [R6, #0x6C] \n"
      "LDR     R1, [R6, #0xC8] \n"
      "BL      sub_FFB585CC \n"
      "CMP     R1, #0 \n"
      "MOVNE   R5, #0 \n"
"loc_FF9695E4:\n"
      "LDR     R0, [R6, #0x44] \n"
      "CMP     R0, #6 \n"
      "CMPNE   R0, #1 \n"
      "CMPNE   R0, #3 \n"
      "BNE     loc_FF969628 \n"
      "CMP     R7, #1 \n"
      "CMPEQ   R5, #0 \n"
      "BNE     loc_FF969628 \n"
      "BL      sub_FF853A48 \n"
      "LDR     R0, [R6, #0x18] \n"
      "MOV     R1, #0x3E8 \n"
      "BL      sub_FF839FA0 \n"
      "CMP     R0, #9 \n"
      "BNE     loc_FF969A60 \n"
      "MOV     R0, #0x90000 \n"
      "BL      sub_FF892064 \n"
      "B       loc_FF9695BC \n"
"loc_FF969628:\n"
      "CMP     R5, #1 \n"
      "MOV     R10, #1 \n"
      "BNE     loc_FF969650 \n"
      "ADD     R3, SP, #0x4C \n"
      "ADD     R2, SP, #0x50 \n"
      "ADD     R1, SP, #0x54 \n"
      "ADD     R0, SP, #0x58 \n"
      "BL      sub_FFAACA30 \n"
      "MOVS    R9, R0 \n"
      "BNE     loc_FF96966C \n"
"loc_FF969650:\n"
      "LDR     R0, [R6, #0x34] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF9697DC \n"
      "LDR     R0, [R6, #0x6C] \n"
      "LDR     R1, [R6, #0x48] \n"
      "CMP     R0, R1 \n"
      "BCC     loc_FF9697DC \n"
"loc_FF96966C:\n"
      "CMP     R9, #0x80000001 \n"
      "STREQ   R11, [R6, #0x70] \n"
      "BEQ     loc_FF9696A4 \n"
      "CMP     R9, #0x80000003 \n"
      "STREQ   R10, [R6, #0x70] \n"
      "BEQ     loc_FF9696A4 \n"
      "CMP     R9, #0x80000005 \n"
      "MOVEQ   R0, #2 \n"
      "BEQ     loc_FF9696A0 \n"
      "CMP     R9, #0x80000007 \n"
      "STRNE   R8, [R6, #0x70] \n"
      "BNE     loc_FF9696A4 \n"
      "MOV     R0, #3 \n"
"loc_FF9696A0:\n"
      "STR     R0, [R6, #0x70] \n"
"loc_FF9696A4:\n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "BNE     loc_FF96970C \n"
      "LDR     R0, =0xFF9693D4 \n"
      "MOV     R1, #0 \n"
      "BL      sub_FFA688B8 \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "STRD    R2, [SP, #0x28] \n"
      "MOV     R2, #0x18 \n"
      "ADD     R1, SP, #0x34 \n"
      "ADD     R0, SP, #0x10 \n"
      "BL      sub_FFB582B0 \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "MVN     R3, #1 \n"
      "ADD     R0, SP, #0x60 \n"
      "STMEA   SP, {R0-R3} \n"
      "MOV     R3, #0 \n"
      "LDR     R0, =0xACE74 \n"
      "MOV     R2, R3 \n"
      "MOV     R1, #0x40 \n"
      "BL      sub_FFA68804 \n"
      "B       loc_FF969764 \n"
"loc_FF969704:\n"
      "MOV     R1, #1 \n"
      "B       loc_FF9699F0 \n"
"loc_FF96970C:\n"
      "BL      sub_FF96A138 \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "MVN     R1, #1 \n"
      "MOV     R0, #0 \n"
      "ADD     R5, SP, #0x1C \n"
      "STMIA   R5, {R0-R3} \n"
      "LDR     R3, [R4, #0x1C] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "ADD     R0, SP, #0x60 \n"
      "ADD     R4, SP, #0xC \n"
      "STMIA   R4, {R0-R3} \n"
      "MOV     R3, #0 \n"
      "MOV     R1, #0x40 \n"
      "STMEA   SP, {R1,R3} \n"
      "MOV     R2, #0 \n"
      "STR     R3, [SP, #8] \n"
      "LDR     R3, =0xACE74 \n"
      "MOV     R1, R2 \n"
      "MOV     R0, R2 \n"
      "BL      sub_FFA67510 \n"
"loc_FF969764:\n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      sub_FF839FA0 \n"
      "CMP     R0, #9 \n"
      "BEQ     loc_FF969704 \n"
      "LDR     R0, [SP, #0x5C] \n"
      "CMP     R0, #0 \n"
      "BEQ     loc_FF96978C \n"
"loc_FF969784:\n"
      "MOV     R1, #1 \n"
      "B       loc_FF969A08 \n"
"loc_FF96978C:\n"
      "LDR     R0, [R6, #0xC] \n"
      "MOV     R4, #5 \n"
      "CMP     R0, #2 \n"
      "MOV     R0, #1 \n"
      "BNE     loc_FF9697C8 \n"
      "BL      sub_FFA68878 \n"
      "BL      sub_FFA688A0 \n"
      "MOV     R0, #0 \n"
      "BL      sub_FF853A50 \n"
      "BL      sub_FF853A60 \n"
      "STR     R4, [R6, #0x44] \n"
      "BL      sub_FF96A138 \n"
      "BL      sub_FF853ABC \n"
      "STR     R10, [R6, #0x44] \n"
      "B       loc_FF9697D4 \n"
"loc_FF9697C8:\n"
      "BL      sub_FFA675C0 \n"
      "BL      sub_FFA6760C \n"
      "STR     R4, [R6, #0x44] \n"
"loc_FF9697D4:\n"
      "STR     R8, [R6, #0x34] \n"
      "B       loc_FF9695BC \n"
"loc_FF9697DC:\n"
      "CMP     R5, #1 \n"
      "BNE     loc_FF969A58 \n"
      "STR     R10, [R6, #0x38] \n"
      "LDR     R0, [R6, #0x6C] \n"
      "LDR     R11, [R4, #0xC] \n"
      "CMP     R0, #0 \n"
      "LDRNE   R9, [SP, #0x58] \n"
      "LDRNE   R10, [SP, #0x54] \n"
      "BNE     loc_FF969928 \n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "BNE     loc_FF969880 \n"
      "LDR     R0, =0xFF9693D4 \n"
      "MOV     R1, #0 \n"
      "BL      sub_FFA688B8 \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "STRD    R2, [SP, #0x28] \n"
      "MOV     R2, #0x18 \n"
      "ADD     R1, SP, #0x34 \n"
      "ADD     R0, SP, #0x10 \n"
      "BL      sub_FFB582B0 \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "MVN     R3, #0 \n"
      "ADD     R0, SP, #0x60 \n"
      "STMEA   SP, {R0-R3} \n"
      "LDR     R0, [SP, #0x58] \n"
      "LDR     R1, [SP, #0x54] \n"
      "LDR     R2, [SP, #0x50] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "BL      sub_FFA68804 \n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      sub_FF839FA0 \n"
      "CMP     R0, #9 \n"
      "BEQ     loc_FF969704 \n"
      "LDR     R0, =0xFF9690F0 \n"
      "MOV     R1, #0 \n"
      "BL      sub_FFA688B8 \n"
      "B       loc_FF9698E8 \n"
"loc_FF969880:\n"
      "LDR     R0, [R4, #0x20] \n"
      "LDR     R2, [R6, #0x64] \n"
      "ADD     R3, SP, #0x5C \n"
      "MVN     R1, #0 \n"
      "ADD     R9, SP, #0x1C \n"
      "STMIA   R9, {R0-R3} \n"
      "LDR     R3, [R4, #0x1C] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "ADD     R0, SP, #0x60 \n"
      "ADD     R9, SP, #0xC \n"
      "STMIA   R9, {R0-R3} \n"
      "LDR     R1, [SP, #0x50] \n"
      "LDR     R2, [SP, #0x54] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "STMFA   SP, {R1,R3} \n"
      "STR     R2, [SP] \n"
      "LDMIB   R4, {R0,R1} \n"
      "LDR     R3, [SP, #0x58] \n"
      "MOV     R2, R11 \n"
      "BL      sub_FFA67510 \n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      sub_FF839FA0 \n"
      "CMP     R0, #9 \n"
      "BEQ     loc_FF969704 \n"
"loc_FF9698E8:\n"
      "LDR     R0, [SP, #0x5C] \n"
      "CMP     R0, #0 \n"
      "BNE     loc_FF969784 \n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "MOV     R0, #1 \n"
      "BNE     loc_FF96990C \n"
      "BL      sub_FFA68878 \n"
      "B       loc_FF969910 \n"
"loc_FF96990C:\n"
      "BL      sub_FFA675C0 \n"
"loc_FF969910:\n"
      "STR     R8, [R6, #0xC4] \n"
      "LDR     R0, [SP, #0x60] \n"
      "LDR     R1, [SP, #0x58] \n"
      "ADD     R9, R1, R0 \n"
      "LDR     R1, [SP, #0x54] \n"
      "SUB     R10, R1, R0 \n"
"loc_FF969928:\n"
      "LDR     R0, [R6, #0xC] \n"
      "LDR     R2, [R6, #0x64] \n"
      "CMP     R0, #2 \n"
      "ADD     R3, SP, #0x5C \n"
      "BNE     loc_FF969980 \n"
      "STRD    R2, [SP, #0x28] \n"
      "MOV     R2, #0x18 \n"
      "ADD     R1, SP, #0x34 \n"
      "ADD     R0, SP, #0x10 \n"
      "BL      sub_FFB582B0 \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "LDR     R3, [R6, #0x68] \n"
      "ADD     R0, SP, #0x60 \n"
      "STMEA   SP, {R0-R3} \n"
      "LDR     R2, [SP, #0x50] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "MOV     R1, R10 \n"
      "MOV     R0, R9 \n"
      "BL      sub_FFA68804 \n"
      "BL      sub_FF853A48 \n"
      "B       loc_FF9699D8 \n"
"loc_FF969980:\n"
      "LDR     R1, [R6, #0x68] \n"
      "LDR     R0, [R4, #0x20] \n"
      "STR     R1, [SP, #0x20] \n"
      "STR     R0, [SP, #0x1C] \n"
      "STR     R2, [SP, #0x24] \n"
      "STR     R3, [SP, #0x28] \n"
      "LDR     R3, [R4, #0x1C] \n"
      "LDR     R1, [R6, #0x84] \n"
      "LDR     R2, [R6, #0x88] \n"
      "ADD     R0, SP, #0x60 \n"
      "STR     R2, [SP, #0x14] \n"
      "LDR     R2, [SP, #0x50] \n"
      "STR     R1, [SP, #0x10] \n"
      "STR     R3, [SP, #0x18] \n"
      "LDR     R3, [SP, #0x4C] \n"
      "STR     R0, [SP, #0xC] \n"
      "STMFA   SP, {R2,R3} \n"
      "STR     R10, [SP] \n"
      "LDMIB   R4, {R0,R1} \n"
      "MOV     R3, R9 \n"
      "MOV     R2, R11 \n"
      "BL      sub_FFA67510 \n"
"loc_FF9699D8:\n"
      "LDR     R0, [R6, #0x18] \n"
      "LDR     R1, [R6, #0x60] \n"
      "BL      sub_FF839FA0 \n"
      "CMP     R0, #9 \n"
      "BNE     loc_FF9699F8 \n"
      "MOV     R1, #0 \n"
"loc_FF9699F0:\n"
      "MOV     R0, #0x90000 \n"
      "B       loc_FF969A0C \n"
"loc_FF9699F8:\n"
      "LDR     R0, [SP, #0x5C] \n"
      "CMP     R0, #0 \n"
      "BEQ     loc_FF969A14 \n"
      "MOV     R1, #0 \n"
"loc_FF969A08:\n"
      "MOV     R0, #0xA0000 \n"
"loc_FF969A0C:\n"
      "BL      sub_FF969374 \n"
      "B       loc_FF9695BC \n"
"loc_FF969A14:\n"
      "LDR     R0, [R6, #0xC] \n"
      "CMP     R0, #2 \n"
      "MOV     R0, #0 \n"
      "BNE     loc_FF969A2C \n"
      "BL      sub_FFA68878 \n"
      "B       loc_FF969A30 \n"
"loc_FF969A2C:\n"
      "BL      sub_FFA675C0 \n"
"loc_FF969A30:\n"
      "LDR     R0, [SP, #0x58] \n"
      "LDR     R1, [SP, #0x60] \n"
      "BL      sub_FFAACC54 \n"
      "LDR     R0, [R6, #0x68] \n"
      "LDR     R3, =0x6768 \n"   // <- 0x6768
      "ADD     R1, R0, #1 \n"
      "STR     R1, [R6, #0x68] \n"
      "LDR     R0, [SP, #0x60] \n"
      "SUB     R2, R3, #4 \n"  // <- -4
      "BL      sub_FFAAAA28 \n"
        //PATCH BEGIN
                "LDR    R0, =0x6764\n"  // added, 0x6768-0x4
                "BL     set_quality\n"  // added
        //PATCH END
"loc_FF969A58:\n"
      "CMP     R7, #1 \n"
      "BNE     loc_FF969A6C \n"
"loc_FF969A60:\n"
      "BL      sub_FF853A4C \n"
      "MOV     R0, #1 \n"
      "BL      sub_FF853A50 \n"
"loc_FF969A6C:\n"
      "CMP     R5, #1 \n"
      "LDRNEH  R0, [R6, #6] \n"
      "CMPNE   R0, #3 \n"
      "BNE     loc_FF9695BC \n"
      "LDR     R0, [R6, #0x6C] \n"
      "ADD     R0, R0, #1 \n"
      "STR     R0, [R6, #0x6C] \n"
      "LDRH    R1, [R6, #6] \n"
      "CMP     R1, #3 \n"
      "LDRNE   R1, [R6, #0x54] \n"
      "LDREQ   R1, =0x3E9 \n"
      "MUL     R0, R1, R0 \n"
      "LDRNE   R1, [R6, #0x50] \n"
      "LDREQ   R1, =0x1770 \n"
      "BL      sub_FFB585CC \n"
      "MOV     R4, R0 \n"
      "BL      sub_FFAACFD8 \n"
      "LDR     R0, [R6, #0x8C] \n"
      "CMP     R0, R4 \n"
      "BNE     loc_FF969AC8 \n"
      "LDR     R0, [R6, #0x3C] \n"
      "CMP     R0, #1 \n"
      "BNE     loc_FF969ADC \n"
"loc_FF969AC8:\n"
      "LDR     R1, [R6, #0x98] \n"
      "MOV     R0, R4 \n"
      "BLX     R1 \n"
      "STR     R4, [R6, #0x8C] \n"
      "STR     R8, [R6, #0x3C] \n"
"loc_FF969ADC:\n"
      "STR     R8, [R6, #0x38] \n"
      "B       loc_FF9695BC \n"
	);
}
*/