/*
 * boot.c - auto-generated by CHDK code_gen.
 */
#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "dryos31.h"

#define offsetof(TYPE, MEMBER) ((int) &((TYPE *)0)->MEMBER)

const char * const new_sa = &_end;

/*----------------------------------------------------------------------
    CreateTask_spytask
-----------------------------------------------------------------------*/
void CreateTask_spytask()
{
    _CreateTask("SpyTask", 0x19, 0x2000, core_spytask, 0);
}

/*----------------------------------------------------------------------
    boot()

    Main entry point for the CHDK code
-----------------------------------------------------------------------*/

/*************************************************************/
//** boot @ 0xFF82000C - 0xFF82017C, length=93
void __attribute__((naked,noinline)) boot() {
asm volatile (
"    LDR     R1, =0xC0410000 \n"
"    MOV     R0, #0 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    MOV     R1, #0 \n"
"    MCR     p15, 0, R1, c7, c10, 4 \n"
"    MCR     p15, 0, R1, c7, c5 \n"
"    MCR     p15, 0, R1, c7, c6 \n"
"    MOV     R0, #0x3D \n"
"    MCR     p15, 0, R0, c6, c0 \n"
"    MOV     R0, #0xC000002F \n"
"    MCR     p15, 0, R0, c6, c1 \n"
"    MOV     R0, #0x35 \n"
"    MCR     p15, 0, R0, c6, c2 \n"
"    MOV     R0, #0x40000035 \n"
"    MCR     p15, 0, R0, c6, c3 \n"
"    MOV     R0, #0x80000017 \n"
"    MCR     p15, 0, R0, c6, c4 \n"
"    LDR     R0, =0xFF80002D \n"
"    MCR     p15, 0, R0, c6, c5 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c2, c0, 1 \n"
"    MOV     R0, #0x34 \n"
"    MCR     p15, 0, R0, c3, c0 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 2 \n"
"    LDR     R0, =0x3333330 \n"
"    MCR     p15, 0, R0, c5, c0, 3 \n"
"    MRC     p15, 0, R0, c1, c0 \n"
"    ORR     R0, R0, #0x1000 \n"
"    ORR     R0, R0, #4 \n"
"    ORR     R0, R0, #1 \n"
"    MCR     p15, 0, R0, c1, c0 \n"
"    MOV     R1, #0x80000006 \n"
"    MCR     p15, 0, R1, c9, c1 \n"
"    MOV     R1, #6 \n"
"    MCR     p15, 0, R1, c9, c1, 1 \n"
"    MRC     p15, 0, R1, c1, c0 \n"
"    ORR     R1, R1, #0x50000 \n"
"    MCR     p15, 0, R1, c1, c0 \n"
"    LDR     R2, =0xC0200000 \n"
"    MOV     R1, #1 \n"
"    STR     R1, [R2, #0x10C] \n"
"    MVN     R1, #0 \n"
"    STR     R1, [R2, #0xC] \n"
"    STR     R1, [R2, #0x1C] \n"
"    STR     R1, [R2, #0x2C] \n"
"    STR     R1, [R2, #0x3C] \n"
"    STR     R1, [R2, #0x4C] \n"
"    STR     R1, [R2, #0x5C] \n"
"    STR     R1, [R2, #0x6C] \n"
"    STR     R1, [R2, #0x7C] \n"
"    STR     R1, [R2, #0x8C] \n"
"    STR     R1, [R2, #0x9C] \n"
"    STR     R1, [R2, #0xAC] \n"
"    STR     R1, [R2, #0xBC] \n"
"    STR     R1, [R2, #0xCC] \n"
"    STR     R1, [R2, #0xDC] \n"
"    STR     R1, [R2, #0xEC] \n"
"    STR     R1, [R2, #0xFC] \n"
"    LDR     R1, =0xC0400008 \n"
"    LDR     R2, =0x430005 \n"
"    STR     R2, [R1] \n"
"    MOV     R1, #1 \n"
"    LDR     R2, =0xC0243100 \n"
"    STR     R2, [R1] \n"
"    LDR     R2, =0xC0242010 \n"
"    LDR     R1, [R2] \n"
"    ORR     R1, R1, #1 \n"
"    STR     R1, [R2] \n"
"    LDR     R0, =0xFFD52B40 \n"
"    LDR     R1, =0x6B1000 \n"
"    LDR     R3, =0x6BE8D2 \n"

"loc_FF82013C:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF82013C \n"
"    LDR     R0, =0xFFD42FE0 \n"
"    LDR     R1, =0x1900 \n"
"    LDR     R3, =0x11460 \n"

"loc_FF820158:\n"
"    CMP     R1, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF820158 \n"
"    LDR     R1, =0x1BDF3C \n"
"    MOV     R2, #0 \n"

"loc_FF820170:\n"
"    CMP     R3, R1 \n"
"    STRCC   R2, [R3], #4 \n"
"    BCC     loc_FF820170 \n"
/* CreateTask is located in ROM, patching the lower level CreateTask_low function instead
 * Note: task function is the first argument
*/
// Install CreateTask_low patch
"    LDR     R0, =patch_CreateTask_low\n"   // Patch data
"    LDM     R0, {R1,R2}\n"             // Get two patch instructions
"    LDR     R0, =hook_CreateTask_low\n"    // Address to patch
"    STM     R0, {R1,R2}\n"             // Store patch instructions

"    B       sub_FF8203C4_my \n"  // --> Patched. Old value = 0xFF8203C4.

"patch_CreateTask_low:\n"
"    LDR     PC, [PC,#-0x4]\n"          // Do jump to absolute address CreateTask_my
"    .long   CreateTask_low_my\n"
);
}

/*************************************************************/
//** CreateTask_low_my @ 0x006B15A4 - 0x006B15A8, length=2
void __attribute__((naked,noinline)) CreateTask_low_my() {
asm volatile (
" STMFD SP!, {R1}\n"
//R0 = Pointer to task function to create

/*** INSTALL capt_seq_task() hook ***/
"    LDR     R1, =task_CaptSeq\n"       // DryOS original code function ptr.
"    CMP     R1, R0\n"                  // is the given taskptr equal to our searched function?
"    LDREQ   R0, =capt_seq_task\n"      // if so replace with our task function base ptr.
"    BEQ     exitHook\n"                // below compares not necessary if this check has found something.

/*** INSTALL task_developseq() hook ***/
//"    LDR     R1, =task_DvlpSeqTask\n"
//"    CMP     R1, R0\n"
//"    LDREQ   R0, =task_developseq_my\n"
//"    BEQ     exitHook\n"

/*** INSTALL exp_drv_task() hook ***/
//"    LDR     R1, =task_ExpDrv\n"
//"    CMP     R1, R0\n"
//"    LDREQ   R0, =exp_drv_task\n"
//"    BEQ     exitHook\n"

/*** INSTALL filewrite() hook ***/
//"    LDR     R1, =task_FileWrite\n"
//"    CMP     R1, R0\n"
//"    LDREQ   R0, =filewritetask\n"
//"    BEQ     exitHook\n"

/*** INSTALL movie_record_task() hook ***/
"    LDR     R1, =task_MovieRecord\n"
"    CMP     R1, R0\n"
"    LDREQ   R0, =movie_record_task\n"
"    BEQ exitHook\n"

/*** INSTALL liveimage_task() hook ***/
"    LDR     R1, =task_LiveImageTask\n"
"    CMP     R1, R0\n"
"    LDREQ   R0, =liveimage_task\n"
"    BEQ     exitHook\n"

/*** INSTALL init_file_modules_task() hook ***/
"   LDR     R1, =task_InitFileModules\n"
"   CMP     R1, R0\n"
"   LDREQ   R0, =init_file_modules_task\n"

"exitHook:\n" 
// restore overwritten registers
"    LDMFD SP!, {R1}\n"
// Execute overwritten instructions from original code, then jump to firmware
"    STMFD   SP!, {R4-R8,LR} \n"
"    CMP     R3, #0 \n"
"    LDR     PC, =0x006B15AC \n"  // Continue in firmware
);
}

/*************************************************************/
//** sub_FF8203C4_my @ 0xFF8203C4 - 0xFF82042C, length=27
void __attribute__((naked,noinline)) sub_FF8203C4_my() {

    //Replacement of sub_ for correct power-on.
    //(short press = playback mode, long press = record mode)
    // Similar to ixus160: http://chdk.setepontos.com/index.php?topic=12321.msg123724#msg123724
    // look at power-on switch sub_FF86AF28
    // value and pointer from sub_FF86A830
    *(int*)(0x297c+0x4) = (*(int*)0xC022F484)&0x20000 ? 0x400000 : 0x200000;

asm volatile (
"    LDR     R0, =0xFF82043C \n"
"    MOV     R1, #0 \n"
"    LDR     R3, =0xFF820474 \n"

"loc_FF8203D0:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8203D0 \n"
"    LDR     R0, =0xFF820474 \n"
"    MOV     R1, #0x1C0 \n"
"    LDR     R3, =0xFF82065C \n"

"loc_FF8203EC:\n"
"    CMP     R0, R3 \n"
"    LDRCC   R2, [R0], #4 \n"
"    STRCC   R2, [R1], #4 \n"
"    BCC     loc_FF8203EC \n"
"    MOV     R0, #0xD2 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    MOV     R0, #0xD3 \n"
"    MSR     CPSR_cxsf, R0 \n"
"    MOV     SP, #0x1000 \n"
"    LDR     R0, =0x3A8 \n"
"    LDR     R2, =0xEEEEEEEE \n"
"    MOV     R3, #0x1000 \n"

"loc_FF820420:\n"
"    CMP     R0, R3 \n"
"    STRCC   R2, [R0], #4 \n"
"    BCC     loc_FF820420 \n"
"    B       sub_FF8228D4_my \n"  // --> Patched. Old value = 0xFF8228D4.
);
}

/*************************************************************/
//** sub_FF8228D4_my @ 0xFF8228D4 - 0xFF8229D8, length=66
void __attribute__((naked,noinline)) sub_FF8228D4_my() {
asm volatile (
"    LDR     R0, =0x1A5C \n"
"    STR     LR, [SP, #-4]! \n"
"    SUB     SP, SP, #0x7C \n"
"    MOV     R1, #0x80000 \n"
"    STR     R1, [R0] \n"
"    LDR     R0, =0x40BEE980 \n"
"    LDR     R1, =0x1A60 \n"
"    STR     R0, [R1] \n"
"    LDR     R1, =0x1A64 \n"
"    ADD     R0, R0, #0x2000 \n"
"    STR     R0, [R1] \n"
"    MOV     R1, #0x78 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006BAAF4 \n"
"    MOV     R0, #0x84000 \n"
"    STR     R0, [SP, #8] \n"

#if defined(CHDK_NOT_IN_CANON_HEAP) // use original heap offset if CHDK is loaded in high memory
"    LDR     R0, =0x1BDF3C \n"
#else
"    LDR     R0, =new_sa\n"   // otherwise use patched value
"    LDR     R0, [R0]\n"      //
#endif

"    LDR     R2, =0x5817B0 \n"
"    STR     R0, [SP, #0xC] \n"
"    SUB     R0, R2, R0 \n"
"    STR     R0, [SP, #0x10] \n"
"    MOV     R0, #0x22 \n"
"    STR     R0, [SP, #0x1C] \n"
"    MOV     R0, #0x7C \n"
"    STR     R0, [SP, #0x20] \n"
"    LDR     R1, =0x58A000 \n"
"    LDR     R0, =0x1D3 \n"
"    STR     R1, [SP, #4] \n"
"    STR     R0, [SP, #0x24] \n"
"    MOV     R0, #0x96 \n"
"    STR     R2, [SP, #0x14] \n"
"    STR     R1, [SP, #0x18] \n"
"    STR     R0, [SP, #0x28] \n"
"    STR     R0, [SP, #0x2C] \n"
"    MOV     R0, #0x64 \n"
"    STR     R0, [SP, #0x30] \n"
"    MOV     R0, #0 \n"
"    STR     R0, [SP, #0x34] \n"
"    STR     R0, [SP, #0x38] \n"
"    STR     R0, [SP, #0x3C] \n"
"    MOV     R0, #0x10 \n"
"    STR     R0, [SP, #0x60] \n"
"    MOV     R0, #0x1000 \n"
"    STR     R0, [SP, #0x64] \n"
"    MOV     R0, #0x100 \n"
"    STR     R0, [SP, #0x68] \n"
"    MOV     R0, #0x2000 \n"
"    STR     R0, [SP, #0x6C] \n"
"    LDR     R1, =sub_FF8246FC_my \n"  // --> Patched. Old value = 0xFF8246FC.
"    MOV     R2, #0 \n"
"    ADD     R0, SP, #4 \n"
"    BL      sub_006B1BC8 \n"
"    ADD     SP, SP, #0x7C \n"
"    LDR     PC, [SP], #4 \n"
);
}

/*************************************************************/
//** sub_FF8246FC_my @ 0xFF8246FC - 0xFF824794, length=39
void __attribute__((naked,noinline)) sub_FF8246FC_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    LDR     R4, =0xFF8247B8 /*'/_term'*/ \n"
"    BL      sub_FF820858 \n"
"    LDR     R1, =0x1A5C \n"
"    LDR     R0, =0x19F0 \n"
"    LDR     R1, [R1] \n"
"    LDR     R0, [R0] \n"
"    ADD     R1, R1, #0x10 \n"
"    CMP     R0, R1 \n"
"    LDRCC   R0, =0xFF8247C8 /*'USER_MEM size checking'*/ \n"
"    BLCC    _err_init_task \n"
"    BL      sub_FF8234D8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF8247E0 /*'dmSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8224E8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF8247E8 /*'termDriverInit'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF8225C8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF8247F8 /*'termDeviceCreate'*/ \n"
"    BLLT    _err_init_task \n"
"    MOV     R0, R4 \n"
"    BL      sub_FF822100 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF82480C /*'stdioSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF82534C \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF824818 /*'stdlibSetup'*/ \n"
"    BLLT    _err_init_task \n"
"    BL      sub_FF8210A8 \n"
"    CMP     R0, #0 \n"
"    LDRLT   R0, =0xFF824824 /*'extlib_setup'*/ \n"
"    BLLT    _err_init_task \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF8285C0_my \n"  // --> Patched. Old value = 0xFF8285C0.
);
}

/*************************************************************/
//** sub_FF8285C0_my @ 0xFF8285C0 - 0xFF828630, length=29
void __attribute__((naked,noinline)) sub_FF8285C0_my() {
asm volatile (
"    STMFD   SP!, {R3,LR} \n"
//"  BL      _sub_FF89B12C \n"  // --> Nullsub call removed.
"    BL      sub_FF83892C \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF8285E4 \n"
"    BL      sub_FF82E8B0 /*_IsNormalCameraMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    MOVNE   R0, #1 \n"
"    BNE     loc_FF8285E8 \n"

"loc_FF8285E4:\n"
"    MOV     R0, #0 \n"

"loc_FF8285E8:\n"
"    BL      sub_FF82D9E0 \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF8285FC \n"
"    BL      sub_FF82D1C8 \n"

"loc_FF8285F8:\n"
"    B       loc_FF8285F8 \n"

"loc_FF8285FC:\n"
"    BL      sub_FF82A464 \n"
"    LDR     R1, =0x60E000 \n"
"    MOV     R0, #0 \n"
"    BL      sub_FF838E38 \n"
"    BL      sub_FF82A7AC \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =task_Startup_my \n"  // --> Patched. Old value = 0xFF828558.
"    MOV     R2, #0 \n"
"    MOV     R1, #0x19 \n"
"    LDR     R0, =0xFF82863C /*'Startup'*/ \n"
"    BL      _CreateTask \n"
"    MOV     R0, #0 \n"
"    LDMFD   SP!, {R3,PC} \n"
);
}

/*************************************************************/
//** task_Startup_my @ 0xFF828558 - 0xFF8285BC, length=26
void __attribute__((naked,noinline)) task_Startup_my() {
asm volatile (
"    STMFD   SP!, {R4,LR} \n"
"    BL      sub_FF822C7C \n"
"    BL      sub_FF82DE6C \n"
"    BL      sub_FF82D174 \n"
//"  BL      _sub_FF86AF38 \n"  // --> Nullsub call removed.
"    BL      sub_FF838B68 \n"
//"  BL      _sub_FF838A28 \n"  // load DISKBOOT.BIN
"    BL      sub_FF838CC4 \n"
"    BL      sub_FF838F0C \n"
//"  BL      _sub_FF838CB8 \n"  // --> Nullsub call removed.
"    BL      sub_FF838BA4 \n"
"    BL      sub_FF834B50 \n"
"    BL      sub_FF838F14 \n"
"    BL      CreateTask_spytask\n" // added
"    BL      taskcreatePhySw_my \n"  // --> Patched. Old value = 0xFF82D88C.
"    BL      init_required_fw_features\n" // added
"    BL      sub_FF832B6C \n"
"    BL      sub_FF8B4B4C \n"
"    BL      sub_FF82AFE0 \n"
"    BL      sub_FF82CCD0 \n"
"    BL      sub_FF838738 \n"
"    BL      sub_FF82D128 \n"
"    BL      sub_FF82CC64 \n"
//"  BL      _sub_FF838CBC \n"  // --> Nullsub call removed.
"    BL      sub_FF82BCF8 \n"
"    BL      sub_FF82CC20 \n"
"    LDMFD   SP!, {R4,LR} \n"
"    B       sub_FF822DCC \n"
);
}

/*************************************************************/
//** taskcreatePhySw_my @ 0xFF82D88C - 0xFF82D8D0, length=18
void __attribute__((naked,noinline)) taskcreatePhySw_my() {
asm volatile (
"    STMFD   SP!, {R3-R5,LR} \n"
"    BL      sub_FF837988 \n"
"    BL      sub_FF82E7E8 /*_IsFactoryMode_FW*/ \n"
"    CMP     R0, #0 \n"
"    BLEQ    sub_FF8378F0 /*_OpLog.Start_FW*/ \n"
"    LDR     R4, =0x1C94 \n"
"    LDR     R0, [R4, #4] \n"
"    CMP     R0, #0 \n"
"    BNE     loc_FF82D8D0 \n"
"    MOV     R3, #0 \n"
"    STR     R3, [SP] \n"
"    LDR     R3, =mykbd_task \n"  // --> Patched. Old value = 0xFF82D858.
"    MOV     R2, #0x2000 \n"  // --> Patched. Old value = 0x800. stack size for new task_PhySw so we don't have to do stack switch
"    MOV     R1, #0x17 \n"
"    LDR     R0, =0xFF82DB3C /*'PhySw'*/ \n"
"    BL      sub_FF82661C /*_CreateTaskStrictly*/ \n"
"    STR     R0, [R4, #4] \n"

"loc_FF82D8D0:\n"
"    LDMFD   SP!, {R3-R5,PC} \n"
);
}

/*************************************************************/
//** init_file_modules_task @ 0xFF85BA04 - 0xFF85BA38, length=14
void __attribute__((naked,noinline)) init_file_modules_task() {
asm volatile (
"    STMFD   SP!, {R4-R6,LR} \n"
"    BL      sub_FF8A1E0C \n"
"    LDR     R5, =0x5006 \n"
"    MOVS    R4, R0 \n"
"    MOVNE   R1, #0 \n"
"    MOVNE   R0, R5 \n"
"    BLNE    _PostLogicalEventToUI \n"
"    BL      sub_FF8A1E3C \n"
"    BL      core_spytask_can_start\n"  // CHDK: Set "it's-safe-to-start" flag for spytask
"    CMP     R4, #0 \n"
"    LDMNEFD SP!, {R4-R6,PC} \n"
"    MOV     R0, R5 \n"
"    LDMFD   SP!, {R4-R6,LR} \n"
"    MOV     R1, #0 \n"
"    B       _PostLogicalEventToUI \n"
);
}
/*
    *** TEMPORARY workaround ***
    Init stuff to avoid asserts on cameras running DryOS r54+
    Execute this only once
 */
void init_required_fw_features(void) {
    extern void _init_focus_eventflag();
    //extern void _init_nd_eventflag();
    //extern void _init_nd_semaphore();
    //extern void _init_zoom_semaphore(); // for MoveZoomLensWithPoint

    _init_focus_eventflag();
    //_init_nd_eventflag();
    //_init_nd_semaphore();
}