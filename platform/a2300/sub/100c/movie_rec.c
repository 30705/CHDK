#include "conf.h"

void change_video_tables(int a, int b){}

void  set_quality(int *x){ // -17 highest; +12 lowest
	if (conf.video_mode) 
		*x=12-((conf.video_quality-1)*(12+17)/(99-1));
}

//** movie_record_task  @ 0xFF95B55C 

void __attribute__((naked,noinline)) movie_record_task(  ) { 
asm volatile (
      "STMFD   SP!, {R2-R10,LR}\n"
      "LDR     R6, =0xFF95A9F4\n"
      "LDR     R7, =0xFF95AF20\n" //This function was used to take values for set_quality -->
      "LDR     R4, =0x6318\n"
      "LDR     R9, =0x69B\n"
      "LDR     R10, =0x2710\n"
      "MOV     R8, #1\n"
      "MOV     R5, #0\n"
"loc_FF95B57C:\n"
      "LDR     R0, [R4, #0x24]\n"
      "MOV     R2, #0\n"
      "ADD     R1, SP, #4\n"
      "BL      sub_003F7218\n"
      "LDR     R0, [R4, #0x2C]\n"
      "CMP     R0, #0\n"
      "LDRNE   R0, [R4, #0xC]\n"
      "CMPNE   R0, #2\n"
      "LDRNE   R0, [R4, #0x44]\n"
      "CMPNE   R0, #6\n"
      "BNE     loc_FF95B6A0\n"
      "LDR     R0, [SP, #4]\n"
      "LDR     R1, [R0]\n"
      "SUB     R1, R1, #2\n"
      "CMP     R1, #0xB\n"
      "ADDCC   PC, PC, R1, LSL #2\n"
      "B       loc_FF95B6A0\n"
      "B       loc_FF95B650\n" //(01)
      "B       loc_FF95B674\n" //(02)
      "B       loc_FF95B684\n" //(03)
      "B       loc_FF95B68C\n" //(04)
      "B       loc_FF95B658\n" //(05)
      "B       loc_FF95B694\n" //(06)
      "B       loc_FF95B664\n" //(07)
      "B       loc_FF95B6A0\n" //(08)
      "B       loc_FF95B69C\n" //(09)
      "B       loc_FF95B61C\n" //(10)
      "B       loc_FF95B5EC\n" //(11)
"loc_FF95B5EC:\n" //Jump Table entry 11
      "STR     R5, [R4, #0x40]\n"
      "STR     R5, [R4, #0x30]\n"
      "STR     R5, [R4, #0x34]\n"
      "STRH    R5, [R4, #6]\n"
      "STR     R6, [R4, #0xB4]\n"
      "STR     R7, [R4, #0xD0]\n"
      "LDR     R0, [R4, #0xC]\n"
      "ADD     R0, R0, #1\n"
      "STR     R0, [R4, #0xC]\n"
      "MOV     R0, #6\n"
      "STR     R0, [R4, #0x44]\n"
      "B       loc_FF95B63C\n"
"loc_FF95B61C:\n" //Jump Table entry 10
      "STR     R5, [R4, #0x40]\n"
      "STR     R5, [R4, #0x30]\n"
      "STR     R6, [R4, #0xB4]\n"
      "STR     R7, [R4, #0xD0]\n"
      "LDR     R0, [R4, #0xC]\n"
      "ADD     R0, R0, #1\n"
      "STR     R0, [R4, #0xC]\n"
      "STR     R8, [R4, #0x44]\n"
"loc_FF95B63C:\n"
      "LDR     R2, =0xFF95A154\n"
      "LDR     R1, =0xACC18\n"
      "LDR     R0, =0xFF95A268\n"
      "BL      sub_FF84B05C\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B650:\n" //Jump Table entry 01
      "BL      unlock_optical_zoom \n" //added
      "BL      sub_FF95AB54\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B658:\n" //Jump Table entry 05
      "LDR     R1, [R4, #0xD0]\n"
      "BLX     R1\n"
//begin patch
      "LDR	   R0, =0x639C \n"		// added, 0x63A0-0x4 taken from  "loc_FF95B444" see commented function below.
      "BL      set_quality \n"		// added
//end patch      
      "B       loc_FF95B6A0\n"
"loc_FF95B664:\n" //Jump Table entry 07
      "LDR     R1, [R0, #0x18]\n"
      "LDR     R0, [R0, #4]\n"
      "BL      sub_FFA6A61C\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B674:\n" //Jump Table entry 02
      "LDR     R0, [R4, #0x44]\n"
      "CMP     R0, #5\n"
      "STRNE   R8, [R4, #0x34]\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B684:\n" //Jump Table entry 03
      "BL      sub_FF95A654\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B68C:\n" //Jump Table entry 04
      "BL      sub_FF95A2B4\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B694:\n" //Jump Table entry 06
      "BL      sub_FF95A0E0\n"
      "B       loc_FF95B6A0\n"
"loc_FF95B69C:\n" //Jump Table entry 09
      "BL      sub_FF95BB78\n"
"loc_FF95B6A0:\n"
      "LDR     R1, [SP, #4]\n"
      "LDR     R3, =0xFF959E40\n"
      "STR     R5, [R1]\n"
      "STR     R9, [SP]\n"
      "LDR     R0, [R4, #0x28]\n"
      "MOV     R2, R10\n"
      "BL      sub_003F7B90\n"
      "B       loc_FF95B57C\n"
	);
}

//This function was used to take values for set_quality
//** sub_FF95AF20_my  @ 0xFF95AF20 
/*
void __attribute__((naked,noinline)) sub_FF95AB02C_my(  ) { 
asm volatile (
      "STMFD   SP!, {R4-R11,LR}\n"
      "SUB     SP, SP, #0x64\n"
      "MOV     R9, #0\n"
      "LDR     R6, =0x6318\n"
      "STR     R9, [SP, #0x54]\n"
      "STR     R9, [SP, #0x4C]\n"
      "STR     R9, [R6, #0xB8]\n"
      "STR     R9, [R6, #0xBC]\n"
      "STR     R9, [R6, #0xC0]\n"
      "STR     R9, [R6, #0xC4]\n"
      "MOV     R4, R0\n"
      "STR     R9, [R6, #0xC8]\n"
      "LDR     R0, [R6, #0x44]\n"
      "MOV     R11, #4\n"
      "CMP     R0, #3\n"
      "STREQ   R11, [R6, #0x44]\n"
      "LDR     R0, [R6, #0xB4]\n"
      "MOV     R8, R9\n"
      "MOV     R5, #1\n"
      "MOV     R7, R9\n"
      "BLX     R0\n"
      "LDR     R0, [R6, #0x44]\n"
      "CMP     R0, #6\n"
      "BEQ     loc_FF95AF94\n"
      "LDR     R1, [R6, #0xC]\n"
      "CMP     R1, #2\n"
      "BNE     loc_FF95AFBC\n"
      "CMP     R0, #5\n"
      "BEQ     loc_FF95AFCC\n"
"loc_FF95AF94:\n"
      "LDR     R2, =0xFF95ADF4\n"
      "LDR     R1, =0xFF95AE58\n"
      "LDR     R0, =0xFF95AEBC\n"
      "MOV     R7, #1\n"
      "ADD     R3, SP, #0x30\n"
      "BL      sub_FF84BBA4\n"
      "LDR     R0, [R6, #0x44]\n"
      "CMP     R0, #4\n"
      "MOVNE   R5, #0\n"
      "B       loc_FF95AFDC\n"
"loc_FF95AFBC:\n"
      "CMP     R0, #4\n"
      "BEQ     loc_FF95AFDC\n"
      "CMP     R1, #2\n"
      "BNE     loc_FF95AFD4\n"
"loc_FF95AFCC:\n"
      "MOV     R0, #0\n"
      "BL      sub_FF84BC10\n"
"loc_FF95AFD4:\n"
      "ADD     SP, SP, #0x64\n"
      "LDMFD   SP!, {R4-R11,PC}\n"
"loc_FF95AFDC:\n"
      "LDRH    R0, [R6, #6]\n"
      "CMP     R0, #3\n"
      "BNE     loc_FF95B010\n"
      "LDR     R0, [R6, #0xCC]\n"
      "CMP     R0, #0\n"
      "LDREQ   R1, =0x8E8\n"
      "LDREQ   R0, =0xFF959E40\n"
      "BLEQ    _DebugAssert \n"
      "LDR     R0, [R6, #0x6C]\n"
      "LDR     R1, [R6, #0xCC]\n"
      "BL      sub_003FC934\n"
      "CMP     R1, #0\n"
      "MOVNE   R5, #0\n"
"loc_FF95B010:\n"
      "LDR     R0, [R6, #0x44]\n"
      "CMP     R0, #6\n"
      "CMPNE   R0, #1\n"
      "CMPNE   R0, #3\n"
      "BNE     loc_FF95B054\n"
      "CMP     R7, #1\n"
      "CMPEQ   R5, #0\n"
      "BNE     loc_FF95B054\n"
      "BL      sub_FF84BBC8\n"
      "LDR     R0, [R6, #0x18]\n"
      "MOV     R1, #0x3E8\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BNE     loc_FF95B4C0\n"
      "MOV     R0, #0x90000\n"
      "BL      sub_FF836004\n"
      "B       loc_FF95AFD4\n"
"loc_FF95B054:\n"
      "CMP     R5, #1\n"
      "MOV     R10, #1\n"
      "BNE     loc_FF95B07C\n"
      "ADD     R3, SP, #0x4C\n"
      "ADD     R2, SP, #0x50\n"
      "ADD     R1, SP, #0x54\n"
      "ADD     R0, SP, #0x58\n"
      "BL      sub_FFA6A6F4\n"
      "MOVS    R9, R0\n"
      "BNE     loc_FF95B098\n"
"loc_FF95B07C:\n"
      "LDR     R0, [R6, #0x34]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF95B214\n"
      "LDR     R0, [R6, #0x6C]\n"
      "LDR     R1, [R6, #0x48]\n"
      "CMP     R0, R1\n"
      "BCC     loc_FF95B214\n"
"loc_FF95B098:\n"
      "CMP     R9, #0x80000001\n"
      "STREQ   R11, [R6, #0x70]\n"
      "BEQ     loc_FF95B0D0\n"
      "CMP     R9, #0x80000003\n"
      "STREQ   R10, [R6, #0x70]\n"
      "BEQ     loc_FF95B0D0\n"
      "CMP     R9, #0x80000005\n"
      "MOVEQ   R0, #2\n"
      "BEQ     loc_FF95B0CC\n"
      "CMP     R9, #0x80000007\n"
      "STRNE   R8, [R6, #0x70]\n"
      "BNE     loc_FF95B0D0\n"
      "MOV     R0, #3\n"
"loc_FF95B0CC:\n"
      "STR     R0, [R6, #0x70]\n"
"loc_FF95B0D0:\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "BNE     loc_FF95B134\n"
      "LDR     R0, =0xFF95ADE8\n"
      "MOV     R1, #0\n"
      "BL      sub_FFA35F70\n"
      "LDR     R1, [R6, #0x64]\n"
      "LDR     R2, =0xACC64\n"
      "ADD     R3, SP, #0x5C\n"
      "ADD     R0, SP, #0x30\n"
      "STRD    R0, [SP, #0x10]\n"
      "STRD    R2, [SP, #0x18]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "MVN     R3, #1\n"
      "ADD     R0, SP, #0x60\n"
      "STMEA   SP, {R0-R3}\n"
      "MOV     R3, #0\n"
      "LDR     R0, =0xACCC4\n"
      "MOV     R2, R3\n"
      "MOV     R1, #0x40\n"
      "BL      sub_FFA35EC4\n"
      "B       loc_FF95B18C\n"
"loc_FF95B12C:\n"
      "MOV     R1, #1\n"
      "B       loc_FF95B404\n"
"loc_FF95B134:\n"
      "BL      sub_FF95BC48\n"
      "LDR     R2, [R6, #0x64]\n"
      "ADD     R3, SP, #0x5C\n"
      "MVN     R1, #1\n"
      "MOV     R0, #0\n"
      "ADD     R5, SP, #0x1C\n"
      "STMIA   R5, {R0-R3}\n"
      "LDR     R3, [R4, #0x1C]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "ADD     R0, SP, #0x60\n"
      "ADD     R4, SP, #0xC\n"
      "STMIA   R4, {R0-R3}\n"
      "MOV     R3, #0\n"
      "MOV     R1, #0x40\n"
      "STMEA   SP, {R1,R3}\n"
      "MOV     R2, #0\n"
      "STR     R3, [SP, #8]\n"
      "LDR     R3, =0xACCC4\n"
      "MOV     R1, R2\n"
      "MOV     R0, R2\n"
      "BL      sub_FFA34BB4\n"
"loc_FF95B18C:\n"
      "LDR     R0, [R6, #0x18]\n"
      "LDR     R1, [R6, #0x60]\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BEQ     loc_FF95B12C\n"
      "LDR     R0, [SP, #0x5C]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF95B1B4\n"
"loc_FF95B1AC:\n"
      "MOV     R1, #1\n"
      "B       loc_FF95B41C\n"
"loc_FF95B1B4:\n"
      "LDR     R0, [R6, #0xC]\n"
      "MOV     R4, #5\n"
      "CMP     R0, #2\n"
      "MOV     R0, #1\n"
      "BNE     loc_FF95B200\n"
      "BL      sub_FFA35F38\n"
      "BL      sub_FFA35F54\n"
      "BL      sub_FF84BBEC\n"
      "MOV     R0, #0\n"
      "BL      sub_FF84BC10\n"
      "BL      sub_FF84BC40\n"
      "STR     R4, [R6, #0x44]\n"
      "LDR     R0, [R6, #0x64]\n"
      "CMP     R0, #1\n"
      "BLEQ    sub_FFA35F94\n"
      "BL      sub_FF95BC48\n"
      "BL      sub_FF84BC9C\n"
      "STR     R10, [R6, #0x44]\n"
      "B       loc_FF95B20C\n"
"loc_FF95B200:\n"
      "BL      sub_FFA34C60\n"
      "BL      sub_FFA34CA8\n"
      "STR     R4, [R6, #0x44]\n"
"loc_FF95B20C:\n"
      "STR     R8, [R6, #0x34]\n"
      "B       loc_FF95AFD4\n"
"loc_FF95B214:\n"
      "CMP     R5, #1\n"
      "BNE     loc_FF95B4B8\n"
      "STR     R10, [R6, #0x38]\n"
      "LDR     R0, [R6, #0x6C]\n"
      "LDR     R11, [R4, #0xC]\n"
      "CMP     R0, #0\n"
      "LDRNE   R9, [SP, #0x58]\n"
      "LDRNE   R10, [SP, #0x54]\n"
      "BNE     loc_FF95B33C\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "BNE     loc_FF95B294\n"
      "LDR     R0, =0xFF95ADE8\n"
      "MOV     R1, #0\n"
      "BL      sub_FFA35F70\n"
      "LDR     R1, [R6, #0x64]\n"
      "LDR     R2, =0xACC64\n"
      "ADD     R3, SP, #0x5C\n"
      "ADD     R0, SP, #0x30\n"
      "STRD    R0, [SP, #0x10]\n"
      "STRD    R2, [SP, #0x18]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "MVN     R3, #0\n"
      "ADD     R0, SP, #0x60\n"
      "STMEA   SP, {R0-R3}\n"
      "LDR     R0, [SP, #0x58]\n"
      "LDR     R1, [SP, #0x54]\n"
      "LDR     R2, [SP, #0x50]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "BL      sub_FFA35EC4\n"
      "B       loc_FF95B2E8\n"
"loc_FF95B294:\n"
      "LDR     R0, [R4, #0x20]\n"
      "LDR     R2, [R6, #0x64]\n"
      "ADD     R3, SP, #0x5C\n"
      "MVN     R1, #0\n"
      "ADD     R9, SP, #0x1C\n"
      "STMIA   R9, {R0-R3}\n"
      "LDR     R3, [R4, #0x1C]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "ADD     R0, SP, #0x60\n"
      "ADD     R9, SP, #0xC\n"
      "STMIA   R9, {R0-R3}\n"
      "LDR     R1, [SP, #0x50]\n"
      "LDR     R2, [SP, #0x54]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "STMFA   SP, {R1,R3}\n"
      "STR     R2, [SP]\n"
      "LDMIB   R4, {R0,R1}\n"
      "LDR     R3, [SP, #0x58]\n"
      "MOV     R2, R11\n"
      "BL      sub_FFA34BB4\n"
"loc_FF95B2E8:\n"
      "LDR     R0, [R6, #0x18]\n"
      "LDR     R1, [R6, #0x60]\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BEQ     loc_FF95B12C\n"
      "LDR     R0, [SP, #0x5C]\n"
      "CMP     R0, #0\n"
      "BNE     loc_FF95B1AC\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "MOV     R0, #1\n"
      "BNE     loc_FF95B320\n"
      "BL      sub_FFA35F38\n"
      "B       loc_FF95B324\n"
"loc_FF95B320:\n"
      "BL      sub_FFA34C60\n"
"loc_FF95B324:\n"
      "STR     R8, [R6, #0xC4]\n"
      "LDR     R0, [SP, #0x60]\n"
      "LDR     R1, [SP, #0x58]\n"
      "ADD     R9, R1, R0\n"
      "LDR     R1, [SP, #0x54]\n"
      "SUB     R10, R1, R0\n"
"loc_FF95B33C:\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "BNE     loc_FF95B39C\n"
      "LDR     R0, =0xFF95AAD0\n"
      "MOV     R1, #0\n"
      "BL      sub_FFA35F70\n"
      "LDR     R1, [R6, #0x64]\n"
      "LDR     R2, =0xACC64\n"
      "ADD     R0, SP, #0x30\n"
      "ADD     R3, SP, #0x5C\n"
      "STRD    R0, [SP, #0x10]\n"
      "STRD    R2, [SP, #0x18]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "LDR     R3, [R6, #0x68]\n"
      "ADD     R0, SP, #0x60\n"
      "STMEA   SP, {R0-R3}\n"
      "LDR     R2, [SP, #0x50]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "MOV     R1, R10\n"
      "MOV     R0, R9\n"
      "BL      sub_FFA35EC4\n"
      "BL      sub_FF84BBC8\n"
      "B       loc_FF95B3EC\n"
"loc_FF95B39C:\n"
      "LDR     R0, [R4, #0x20]\n"
      "LDR     R1, [R6, #0x68]\n"
      "LDR     R2, [R6, #0x64]\n"
      "ADD     R3, SP, #0x5C\n"
      "ADD     R12, SP, #0x1C\n"
      "STMIA   R12, {R0-R3}\n"
      "LDR     R3, [R4, #0x1C]\n"
      "LDR     R1, [R6, #0x84]\n"
      "LDR     R2, [R6, #0x88]\n"
      "ADD     R0, SP, #0x60\n"
      "ADD     R12, SP, #0xC\n"
      "STMIA   R12, {R0-R3}\n"
      "LDR     R2, [SP, #0x50]\n"
      "LDR     R3, [SP, #0x4C]\n"
      "STMFA   SP, {R2,R3}\n"
      "STR     R10, [SP]\n"
      "LDMIB   R4, {R0,R1}\n"
      "MOV     R3, R9\n"
      "MOV     R2, R11\n"
      "BL      sub_FFA34BB4\n"
"loc_FF95B3EC:\n"
      "LDR     R0, [R6, #0x18]\n"
      "LDR     R1, [R6, #0x60]\n"
      "BL      _TakeSemaphore \n"
      "CMP     R0, #9\n"
      "BNE     loc_FF95B40C\n"
      "MOV     R1, #0\n"
"loc_FF95B404:\n"
      "MOV     R0, #0x90000\n"
      "B       loc_FF95B420\n"
"loc_FF95B40C:\n"
      "LDR     R0, [SP, #0x5C]\n"
      "CMP     R0, #0\n"
      "BEQ     loc_FF95B428\n"
      "MOV     R1, #0\n"
"loc_FF95B41C:\n"
      "MOV     R0, #0xA0000\n"
"loc_FF95B420:\n"
      "BL      sub_FF95AD78\n"
      "B       loc_FF95AFD4\n"
"loc_FF95B428:\n"
      "LDR     R0, [R6, #0xC]\n"
      "CMP     R0, #2\n"
      "MOV     R0, #0\n"
      "BNE     loc_FF95B440\n"
      "BL      sub_FFA35F38\n"
      "B       loc_FF95B444\n"
"loc_FF95B440:\n"
      "BL      sub_FFA34C60\n"
"loc_FF95B444:\n"
      "LDR     R0, [SP, #0x58]\n"
      "LDR     R1, [SP, #0x60]\n"
      "BL      sub_FFA6A91C\n"
      "LDR     R0, [R6, #0x68]\n"
      "LDR     R3, =0x63A0\n"        // <- 0x63A0
      "ADD     R1, R0, #1\n"
      "STR     R1, [R6, #0x68]\n"
      "LDR     R0, [SP, #0x60]\n"
      "SUB     R2, R3, #4\n"         // <- -4
      "BL      sub_FFA68190\n"
//begin patch
      "LDR	   R0, =0x639C \n"		// added, 0x63A0-0x4
      "BL      set_quality \n"		// added
//end patch
      "LDR     R0, [R6, #0x64]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF95B4B8\n"
      "ADD     R0, SP, #0x48\n"
      "BL      sub_FFA35FF4\n"
      "LDR     R1, =0xACC34\n"
      "LDR     R0, [R1, #4]\n"
      "LDR     R1, [R1]\n"
      "SUB     R2, R0, #0x400\n"
      "SUBS    R2, R2, #0x38\n"
      "ADDEQ   R0, R0, #8\n"
      "MOV     R1, R1, LSR #4\n"
      "MOV     R0, R0, LSR #4\n"
      "MUL     R1, R0, R1\n"
      "LDR     R0, [SP, #0x48]\n"
      "BL      sub_003FC934\n"
      "LDR     R1, =0xACC64\n"
      "STR     R0, [SP, #0x48]\n"
      "BL      sub_FFA684C0\n"
"loc_FF95B4B8:\n"
      "CMP     R7, #1\n"
      "BNE     loc_FF95B4CC\n"
"loc_FF95B4C0:\n"
      "BL      sub_FF84BBEC\n"
      "MOV     R0, #1\n"
      "BL      sub_FF84BC10\n"
"loc_FF95B4CC:\n"
      "CMP     R5, #1\n"
      "LDRNEH  R0, [R6, #6]\n"
      "CMPNE   R0, #3\n"
      "BNE     loc_FF95AFD4\n"
      "LDR     R0, [R6, #0x6C]\n"
      "ADD     R0, R0, #1\n"
      "STR     R0, [R6, #0x6C]\n"
      "LDRH    R1, [R6, #6]\n"
      "CMP     R1, #3\n"
      "LDRNE   R1, [R6, #0x54]\n"
      "MULNE   R0, R1, R0\n"
      "LDRNE   R1, [R6, #0x50]\n"
      "BNE     loc_FF95B51C\n"
      "LDR     R1, [R6, #0x58]\n"
      "CMP     R1, #0x19\n"
      "LDRNE   R1, =0x3E9\n"
      "MOVEQ   R1, #0x3E8\n"
      "MUL     R0, R1, R0\n"
      "LDRNE   R1, =0x1770\n"
      "LDREQ   R1, =0x1388\n"
"loc_FF95B51C:\n"
      "BL      sub_003FC934\n"
      "MOV     R4, R0\n"
      "BL      sub_FFA6ACB0\n"
      "LDR     R0, [R6, #0x8C]\n"
      "CMP     R0, R4\n"
      "BNE     loc_FF95B540\n"
      "LDR     R0, [R6, #0x3C]\n"
      "CMP     R0, #1\n"
      "BNE     loc_FF95B554\n"
"loc_FF95B540:\n"
      "LDR     R1, [R6, #0x98]\n"
      "MOV     R0, R4\n"
      "BLX     R1\n"
      "STR     R4, [R6, #0x8C]\n"
      "STR     R8, [R6, #0x3C]\n"
"loc_FF95B554:\n"
      "STR     R8, [R6, #0x38]\n"
      "B       loc_FF95AFD4\n"
	);
}
*/
