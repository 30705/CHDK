#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#include <inttypes.h>

#include <capstone.h>


#include "stubs_load.h"
#include "firmware_load_ng.h"

/* copied from finsig_dryos.c */
char    out_buf[32*1024] = "";
int     out_len = 0;
char    hdr_buf[32*1024] = "";
int     hdr_len = 0;
int     out_hdr = 1;

FILE *out_fp;

void bprintf(char *fmt, ...)
{
    va_list argp;
    va_start(argp, fmt);

    if (out_hdr)
        hdr_len += vsprintf(hdr_buf+hdr_len,fmt,argp);
    else
        out_len += vsprintf(out_buf+out_len,fmt,argp);

    va_end(argp);
}

void add_blankline()
{
    if (strcmp(hdr_buf+hdr_len-2,"\n\n") != 0)
    {
        hdr_buf[hdr_len++] = '\n';
        hdr_buf[hdr_len] = 0;
    }
}

void write_output()
{
    add_blankline();
    if (out_fp)
    {
        fprintf(out_fp,"%s",hdr_buf);
        fprintf(out_fp,"%s",out_buf);
    }
}

// Master list of functions / addresses to find

#define DONT_EXPORT     1
#define OPTIONAL        2
#define UNUSED          4
#define BAD_MATCH       8
#define EV_MATCH        16
#define LIST_ALWAYS     32

typedef struct {
    char        *name;
    int         flags;
    uint32_t    val;
} func_entry;

int next_func_entry = 0;

#define MAX_FUNC_ENTRY  5000

func_entry  func_names[MAX_FUNC_ENTRY] =
{
    // Do these first as they are needed to find others
    { "ExportToEventProcedure_FW", UNUSED|DONT_EXPORT },
    { "CreateJumptable", UNUSED },
    { "_uartr_req", UNUSED },
    { "StartRecModeMenu", UNUSED },
    { "LogCameraEvent", UNUSED|DONT_EXPORT },
    { "getImageDirName", UNUSED|DONT_EXPORT },

    { "AllocateMemory", UNUSED|LIST_ALWAYS },
    { "AllocateUncacheableMemory" },
    { "Close" },
    { "CreateBinarySemaphore", UNUSED|LIST_ALWAYS },
    { "CreateCountingSemaphore", UNUSED|LIST_ALWAYS },
    { "CreateTask" },
    { "DebugAssert", OPTIONAL|LIST_ALWAYS },
    { "DeleteDirectory_Fut" },
    { "DeleteFile_Fut" },
    { "DeleteSemaphore", UNUSED|LIST_ALWAYS },
    { "DoAELock" },
    { "DoAFLock" },
    { "EnterToCompensationEVF" },
    { "ExecuteEventProcedure" },
    { "ExitFromCompensationEVF" },
    { "ExitTask" },
    { "ExpCtrlTool_StartContiAE" },
    { "ExpCtrlTool_StopContiAE" },
    { "Fclose_Fut" },
    { "Feof_Fut" },
    { "Fflush_Fut" },
    { "Fgets_Fut" },
    { "Fopen_Fut" },
    { "Fread_Fut" },
    { "FreeMemory", UNUSED|LIST_ALWAYS },
    { "FreeUncacheableMemory" },
    { "Fseek_Fut" },
    { "Fwrite_Fut" },
    { "GetBatteryTemperature" },
    { "GetCCDTemperature" },
    { "GetCurrentAvValue" },
    { "GetDrive_ClusterSize" },
    { "GetDrive_FreeClusters" },
    { "GetDrive_TotalClusters" },
    { "GetFocusLensSubjectDistance" },
    { "GetFocusLensSubjectDistanceFromLens" },
    { "GetImageFolder", OPTIONAL },
    { "GetKbdState" },
    { "GetMemInfo" },
    { "GetOpticalTemperature" },
    { "GetParameterData" },
    { "GetPropertyCase" },
    { "GetSystemTime" },
    { "GetVRAMHPixelsSize" },
    { "GetVRAMVPixelsSize" },
    { "GetZoomLensCurrentPoint" },
    { "GetZoomLensCurrentPosition" },
    { "GiveSemaphore", OPTIONAL|LIST_ALWAYS },
    { "IsStrobeChargeCompleted" },
    { "LEDDrive", OPTIONAL },
    { "LocalTime" },
    { "LockMainPower" },
    { "Lseek", UNUSED|LIST_ALWAYS },
    { "MakeDirectory_Fut" },
    { "MakeSDCardBootable", OPTIONAL },
    { "MoveFocusLensToDistance" },
    { "MoveIrisWithAv", OPTIONAL },
    { "MoveZoomLensWithPoint" },
    { "NewTaskShell", UNUSED },
    { "Open" },
    { "PB2Rec" },
    { "PT_MoveDigitalZoomToWide", OPTIONAL },
    { "PT_MoveOpticalZoomAt", OPTIONAL },
    { "PT_PlaySound" },
    { "PostLogicalEventForNotPowerType" },
    { "PostLogicalEventToUI" },
    { "PutInNdFilter", OPTIONAL },
    { "PutOutNdFilter", OPTIONAL },
    { "Read" },
    { "ReadFastDir" },
    { "Rec2PB" },
    { "RefreshPhysicalScreen" },
    { "Remove", OPTIONAL|UNUSED },
    { "RenameFile_Fut" },
    { "Restart" },
    { "ScreenLock" },
    { "ScreenUnlock" },
    { "SetAE_ShutterSpeed" },
    { "SetAutoShutdownTime" },
    { "SetCurrentCaptureModeType" },
    { "SetFileAttributes" },
    { "SetFileTimeStamp" },
    { "SetLogicalEventActive" },
    { "SetParameterData" },
    { "SetPropertyCase" },
    { "SetScriptMode" },
    { "SleepTask" },
    { "TakeSemaphore" },
    { "TurnOffBackLight" },
    { "TurnOnBackLight" },
    { "TurnOnDisplay" },
    { "TurnOffDisplay" },
    { "UIFS_WriteFirmInfoToFile" },
    { "UnlockAE" },
    { "UnlockAF" },
    { "UnlockMainPower" },
    { "UnsetZoomForMovie", OPTIONAL },
//    { "UpdateMBROnFlash" },
    { "VbattGet" },
    { "Write" },
    { "WriteSDCard" },

    { "_log" },
    { "_log10" },
    { "_pow" },
    { "_sqrt" },
    { "add_ptp_handler" },
    { "apex2us" },
    { "close" },
    { "err_init_task", OPTIONAL },
    { "exmem_alloc" },
    { "exmem_free", OPTIONAL|LIST_ALWAYS },
    { "free" },

    { "kbd_p1_f" },
    { "kbd_p1_f_cont" },
    { "kbd_p2_f" },
    { "kbd_read_keys" },
    { "kbd_read_keys_r2" },

    { "kbd_pwr_off", OPTIONAL },
    { "kbd_pwr_on", OPTIONAL },
    { "lseek" },
    { "malloc" },
    { "memcmp" },
    { "memcpy" },
    { "memset" },
    { "mkdir" },
    { "mktime_ext" },
    { "open" },
    { "OpenFastDir" },
    { "closedir" },
    { "get_fstype", OPTIONAL|LIST_ALWAYS },
    { "qsort" },
    { "rand" },
    { "read", UNUSED|OPTIONAL },
    { "realloc", OPTIONAL|LIST_ALWAYS },
    { "reboot_fw_update" },
    { "set_control_event" },
    { "srand" },
    { "stat" },
    { "strcat" },
    { "strchr" },
    { "strcmp" },
    { "strcpy" },
    { "strftime" },
    { "strlen" },
    { "strncmp" },
    { "strncpy" },
    { "strrchr" },
    { "strtol" },
    { "strtolx" },

    { "task_CaptSeq" },
    { "task_DvlpSeqTask", OPTIONAL },
    { "task_ExpDrv" },
    { "task_FileWrite", OPTIONAL },
    { "task_InitFileModules" },
    { "task_MovieRecord" },
    { "task_PhySw", OPTIONAL },
    { "task_RotaryEncoder", OPTIONAL },
    { "task_TouchPanel", OPTIONAL },

//    { "hook_CreateTask" },

    { "time" },
    { "vsprintf" },
    { "write", UNUSED|OPTIONAL },

    { "EngDrvIn", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "EngDrvOut", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "EngDrvRead" },
    { "EngDrvBits", OPTIONAL|UNUSED|LIST_ALWAYS },

    { "PTM_GetCurrentItem" },
    { "PTM_SetCurrentItem", UNUSED|LIST_ALWAYS },
    { "PTM_NextItem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PTM_PrevItem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PTM_SetPropertyEnable", OPTIONAL|UNUSED|LIST_ALWAYS },

    // OS functions, mostly to aid firmware analysis. Order is important!
    { "_GetSystemTime", OPTIONAL|UNUSED|LIST_ALWAYS }, // only for locating timer functions
    { "SetTimerAfter", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "SetTimerWhen", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CancelTimer", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CancelHPTimer" },
    { "SetHPTimerAfterTimeout", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "SetHPTimerAfterNow" },
    { "CreateTaskStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetSemaphoreValue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TryTakeSemaphore", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateMessageQueueStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateEventFlagStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateBinarySemaphoreStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateCountingSemaphoreStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateRecursiveLockStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TakeSemaphoreStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "ReceiveMessageQueueStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "PostMessageQueueStrictly", OPTIONAL|UNUSED|LIST_ALWAYS },    // r23+
    { "WaitForAnyEventFlagStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "WaitForAllEventFlagStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "AcquireRecursiveLockStrictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // r23+
    { "DeleteMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "PostMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "ReceiveMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TryReceiveMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "TryPostMessageQueue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetNumberOfPostedMessages", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "DeleteRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "AcquireRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "ReleaseRecursiveLock", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "WaitForAnyEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "WaitForAllEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "ClearEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "SetEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetEventFlagValue", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CreateEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "DeleteEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CheckAnyEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "CheckAllEventFlag", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "RegisterInterruptHandler", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "UnregisterInterruptHandler", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "GetSRAndDisableInterrupt", OPTIONAL|UNUSED|LIST_ALWAYS }, // disables IRQ, returns a value
    { "SetSR", OPTIONAL|UNUSED|LIST_ALWAYS }, // enables IRQ, puts back value returned by GetSR
    { "EnableInterrupt", OPTIONAL|UNUSED|LIST_ALWAYS }, // enables IRQ
    { "_divmod_signed_int", OPTIONAL|UNUSED|LIST_ALWAYS}, // division for signed integers, remainder is returned in r1
    { "_divmod_unsigned_int", OPTIONAL|UNUSED|LIST_ALWAYS}, // division for unsigned integers, remainder is returned in r1
    { "_dflt", OPTIONAL|UNUSED|LIST_ALWAYS}, // int -> double
    { "_dfltu", OPTIONAL|UNUSED|LIST_ALWAYS}, // uint -> double
    { "_dfix", OPTIONAL|UNUSED|LIST_ALWAYS}, // double -> int
    { "_dfixu", OPTIONAL|UNUSED|LIST_ALWAYS}, // double -> uint
    { "_dmul", OPTIONAL|UNUSED|LIST_ALWAYS}, // double precision float multiplication
    { "_ddiv", OPTIONAL|UNUSED|LIST_ALWAYS}, // double precision float division
    { "_dadd", OPTIONAL|UNUSED|LIST_ALWAYS}, // addition for doubles
    { "_dsub", OPTIONAL|UNUSED|LIST_ALWAYS}, // subtraction for doubles
    { "_drsb", OPTIONAL|UNUSED|LIST_ALWAYS}, // reverse subtraction for doubles (?)
    { "_dcmp", OPTIONAL|UNUSED|LIST_ALWAYS}, // comparison of 2 doubles, only updates condition flags
    { "_dcmp_reverse", OPTIONAL|UNUSED|LIST_ALWAYS}, // like _dcmp, but operands in reverse order, only updates condition flags
    { "_safe_sqrt", OPTIONAL|UNUSED|LIST_ALWAYS}, // only calls _sqrt for numbers >= 0
    { "_scalbn", OPTIONAL|UNUSED|LIST_ALWAYS}, // double scalbn (double x, long exp), returns x * FLT_RADIX ** exp
    { "_fflt", OPTIONAL|UNUSED|LIST_ALWAYS}, // int -> float
    { "_ffltu", OPTIONAL|UNUSED|LIST_ALWAYS}, // uint -> float
    { "_ffix", OPTIONAL|UNUSED|LIST_ALWAYS}, // float -> int
    { "_ffixu", OPTIONAL|UNUSED|LIST_ALWAYS}, // float -> uint
    { "_fmul", OPTIONAL|UNUSED|LIST_ALWAYS}, // single precision float multiplication
    { "_fdiv", OPTIONAL|UNUSED|LIST_ALWAYS}, // single precision float division
    { "_f2d", OPTIONAL|UNUSED|LIST_ALWAYS}, // float -> double
    { "DisplayBusyOnScreen", OPTIONAL|UNUSED|LIST_ALWAYS}, // displays full screen "busy" message
    { "UndisplayBusyOnScreen", OPTIONAL|UNUSED|LIST_ALWAYS},
    { "CreateDialogBox", OPTIONAL|UNUSED|LIST_ALWAYS},
    { "DisplayDialogBox", OPTIONAL|UNUSED|LIST_ALWAYS},
    { "add_ui_to_dialog", OPTIONAL|UNUSED|LIST_ALWAYS}, // name made up, assigns resources to a dialog
    { "get_string_by_id", OPTIONAL|UNUSED|LIST_ALWAYS}, // name made up, retrieves a localised or unlocalised string by its ID
    { "malloc_strictly", OPTIONAL|UNUSED|LIST_ALWAYS }, // name made up
    { "GetCurrentMachineTime", OPTIONAL|UNUSED|LIST_ALWAYS }, // reads usec counter, name from ixus30
    { "HwOcReadICAPCounter", OPTIONAL|UNUSED|LIST_ALWAYS }, // reads usec counter, name from ixus30

    // Other stuff needed for finding misc variables - don't export to stubs_entry.S
    { "GetSDProtect", UNUSED },
    { "DispCon_ShowBitmapColorBar", UNUSED },
    { "ResetZoomLens", OPTIONAL|UNUSED },
    { "ResetFocusLens", OPTIONAL|UNUSED },
    { "NR_GetDarkSubType", OPTIONAL|UNUSED },
    { "NR_SetDarkSubType", OPTIONAL|UNUSED },
    { "SavePaletteData", OPTIONAL|UNUSED },
    { "GUISrv_StartGUISystem", OPTIONAL|UNUSED|LIST_ALWAYS },
    { "get_resource_pointer", OPTIONAL|UNUSED|LIST_ALWAYS }, // name made up, gets a pointer to a certain resource (font, dialog, icon)
    { "CalcLog10", OPTIONAL|UNUSED|LIST_ALWAYS }, // helper

    { "MFOn", OPTIONAL },
    { "MFOff", OPTIONAL },
    { "PT_MFOn", OPTIONAL },
    { "PT_MFOff", OPTIONAL },
    { "SS_MFOn", OPTIONAL },
    { "SS_MFOff", OPTIONAL },

    { "GetAdChValue", OPTIONAL },

    {0,0,0},
};

// Return the array index of a named function in the array above
int find_saved_sig(const char *name)
{
    int i;
    for (i=0; func_names[i].name != 0; i++)
    {
        if (strcmp(name,func_names[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Save the address value found for a function in the above array
void save_sig(const char *name, uint32_t val)
{
    int i = find_saved_sig(name);
    if (i >= 0)
    {
        func_names[i].val = val;
    }
}

void add_func_name(char *n, uint32_t eadr, char *suffix)
{
    int k;

    char *s = n;
    if (suffix != 0)
    {
        s = malloc(strlen(n) + strlen(suffix) + 1);
        sprintf(s, "%s%s", n, suffix);
    }

    for (k=0; func_names[k].name != 0; k++)
    {
        if (strcmp(func_names[k].name, s) == 0)
        {
            if (func_names[k].val == 0)             // same name, no address
            {
                func_names[k].val = eadr;
                func_names[k].flags |= EV_MATCH;
                return;
            }
            else if (func_names[k].val == eadr)     // same name, same address
            {
                return;
            }
        }
    }

    func_names[next_func_entry].name = s;
    func_names[next_func_entry].flags = OPTIONAL|UNUSED;
    func_names[next_func_entry].val = eadr;
    next_func_entry++;
    func_names[next_func_entry].name = 0;
}

// process a call to an 2 arg event proc registration function
int process_reg_eventproc_call(firmware *fw, iter_state_t *is,uint32_t unused) {
    uint32_t regs[4];
    // get r0, r1, backtracking up to 4 instructions
    if((get_call_const_args(fw,is,4,regs)&3)==3) {
        // TODO follow ptr to verify code, pick up underlying functions
        if(isASCIIstring(fw,regs[0])) {
            char *nm=(char *)adr2ptr(fw,regs[0]);
            add_func_name(nm,regs[1],NULL);
            //printf("eventproc found %s 0x%08x at 0x%"PRIx64"\n",nm,regs[1],is->insn->address);
        } else {
            printf("eventproc name not string at 0x%"PRIx64"\n",is->insn->address);
        }
    } else {
        printf("failed to get export/register eventproc args at 0x%"PRIx64"\n",is->insn->address);
    }
    return 0; // always keep looking
}

// process a call to event proc table registration
int process_reg_eventproc_table_call(firmware *fw, iter_state_t *is,uint32_t unused) {
    uint32_t regs[4];
    // get r0, backtracking up to 4 instructions
    if(get_call_const_args(fw,is,4,regs)&1) {
        // include tables in RAM data
        uint32_t *p=(uint32_t*)adr2ptr_with_data(fw,regs[0]);
        //printf("found eventproc table 0x%08x\n",regs[0]);
        // if it was a valid address
        if(p) {
            while(*p) {
                uint32_t nm_adr=*p;
                if(!isASCIIstring(fw,nm_adr)) {
                    printf("eventproc name not string tbl 0x%08x 0x%08x\n",regs[0],nm_adr);
                    break;
                }
                char *nm=(char *)adr2ptr(fw,nm_adr);
                p++;
                uint32_t fn=*p;
                p++;
                //printf("found %s 0x%08x\n",nm,fn);
                add_func_name(nm,fn,NULL);
            }
        } else {
            printf("failed to get RegisterEventProcTable arg 0x%08x at 0x%"PRIx64"\n",regs[0],is->insn->address);
        }
    } else {
        printf("failed to get RegisterEventProcTable r0 at 0x%"PRIx64"\n",is->insn->address);
    }
    return 0;
}

int process_createtask_call(firmware *fw, iter_state_t *is,uint32_t unused) {
    //printf("CreateTask call at %"PRIx64"\n",is->insn->address);
    uint32_t regs[4];
    // get r0 (name) and r3 (entry), backtracking up to 10 instructions
    if((get_call_const_args(fw,is,10,regs)&9)==9) {
        if(isASCIIstring(fw,regs[0])) {
            // TODO
            char *buf=malloc(64);
            char *nm=(char *)adr2ptr(fw,regs[0]);
            // some special cases
            if(strcmp("CaptSeqTask",nm) == 0) {
                strcpy(buf,"task_CaptSeq");
            } else if(strcmp("ExpDrvTask",nm) == 0) {
                strcpy(buf,"task_ExpDrv");
            } else if(strcmp("MovieRecordTask",nm) == 0) {
                strcpy(buf,"task_MovieRecord");
            } else if(strcmp("FileWriteTask",nm) == 0) {
                strcpy(buf,"task_FileWrite");
            } else {
                sprintf(buf,"task_%s",nm);
            }
            //printf("found %s 0x%08x at 0x%"PRIx64"\n",buf,regs[3],is->insn->address);
            add_func_name(buf,regs[3],NULL);
        } else {
            printf("task name name not string at 0x%"PRIx64"\n",is->insn->address);
        }
    } else {
        printf("failed to get CreateTask args at 0x%"PRIx64"\n",is->insn->address);
    }
    return 0;
}

void find_event_procs(firmware *fw) {
    static insn_match_t reg_evp_match[]={
        {ARM_INS_MOV,2,{{ARM_OP_REG,ARM_REG_R2},{ARM_OP_REG,ARM_REG_R1}}},
        {ARM_INS_LDR,2,{{ARM_OP_REG,ARM_REG_R1},{ARM_OP_MEM,ARM_REG_INVALID}}},
        {ARM_INS_B,1,{{ARM_OP_IMM,ARM_REG_INVALID}}},
        {ARM_INS_ENDING}
    };
    uint32_t str_adr = find_str_bytes(fw,"ExportToEventProcedure");
    if(!str_adr) {
        return;
    }
    // for efficiency, could search near the string
    iter_state_t *is=disasm_iter_new(fw,fw->rom_code_search_min_adr);
    //iter_state_t *is=disasm_iter_new(fw,0xfc1e2a50);

    uint32_t e_to_evp=0;
    //while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,0,0xfc1e2a5c)) {
    //printf("find e_to_evp\n");
    while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,0)) {
        // TODO should check that R1 in prev/next got func ptr
        if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
            if(disasm_iter(fw,is)) {
                if(is->insn->id == ARM_INS_BL && is->insn->detail->arm.operands[0].type == ARM_OP_IMM) {
                    e_to_evp = ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
                    break;
                }
            }
        }
    } 
    if(!e_to_evp) {
        printf("failed to find ExportToEventProcedure, giving up\n");
        return;
    }
    save_sig("ExportToEventProcedure_FW",e_to_evp); 

    //look for the underlying RegisterEventProcedure function (not currently used)
    uint32_t reg_evp=0;
    // start at identified Export..
    disasm_iter_init(fw,is,ADR_CLEAR_THUMB(e_to_evp));
    if(insn_match_seq(fw,is,reg_evp_match)) {
        reg_evp=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
        //printf("RegisterEventProcedure found 0x%08x at %"PRIx64"\n",reg_evp,is->insn->address);
        add_func_name("RegisterEventProcedure",reg_evp,NULL);
    }

    // ref to find RegisterEventProcTable
    str_adr = find_str_bytes(fw,"DispDev_EnableEventProc"); // note this string may appear more than once, assuming want first
    uint32_t reg_evp_alt1=0;
    uint32_t reg_evp_tbl=0;
    if(str_adr) {
        disasm_iter_init(fw,is,str_adr - 512); // reset to a bit before where the string was found
        uint32_t dd_enable_p=0;
        while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+512)) {
            if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
                if(insn_match_find_next(fw,is,2,match_b_bl)) {
                    reg_evp_alt1=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
                    //printf("RegisterEventProcedure_alt1 found 0x%08x at %"PRIx64"\n",reg_evp_alt1,is->insn->address);
                    add_func_name("RegisterEventProcedure_alt1",reg_evp_alt1,NULL);

                    uint32_t regs[4];

                    // get r0 and r1, backtracking up to 4 instructions
                    if((get_call_const_args(fw,is,4,regs)&3)==3) {
                        // sanity check, arg0 was the original thing we were looking for
                        if(regs[0]==str_adr) {
                            dd_enable_p=regs[1]; // constat value should already have correct ARM/THUMB bit
                            //printf("DispDev_EnableEventProc found 0x%08x at %"PRIx64"\n",dd_enable_p,is->insn->address);
                            add_func_name("DispDev_EnableEventProc",dd_enable_p,NULL);
                            break;
                        }
                    }
                }
            }
        } 
        // found candidate function
        if(dd_enable_p) {
            disasm_iter_init(fw,is,ADR_CLEAR_THUMB(dd_enable_p)); // start at found func
            if(insn_match_find_next(fw,is,4,match_b_bl)) { // find the first bl
                // sanity check, make sure we get a const in r0
                uint32_t regs[4];
                if(get_call_const_args(fw,is,4,regs)&1) {
                    reg_evp_tbl=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
                    //printf("RegisterEventProcTable found 0x%08x at %"PRIx64"\n",reg_evp_tbl,is->insn->address);
                    add_func_name("RegisterEventProcTable",reg_evp_tbl,NULL);
                }
            }
        }
    }
    
    // Look for another alt event proc registration function
    uint32_t reg_evp_alt2=0;
    str_adr = find_str_bytes(fw,"EngApp.Delete");
    if(str_adr) {
        disasm_iter_init(fw,is,str_adr - 512); // reset to a bit before where the string was found
        while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+512)) {
            if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
                if(insn_match_find_next(fw,is,3,match_b_bl)) {
                    uint32_t regs[4];
                    // sanity check, constants in r0, r1 and r0 was the original thing we were looking for
                    if((get_call_const_args(fw,is,4,regs)&3)==3) {
                        if(regs[0]==str_adr) {
                            reg_evp_alt2=ADR_SET_THUMB(is->insn->detail->arm.operands[0].imm);
                            if(reg_evp_alt2 == reg_evp_alt1) {
                                printf("RegisterEventProcedure_alt2 == _alt1 at %"PRIx64"\n",is->insn->address);
                                reg_evp_alt2=0;
                            } else {
                                add_func_name("RegisterEventProcedure_alt2",reg_evp_alt2,NULL);
                               // printf("RegisterEventProcedure_alt2 found 0x%08x at %"PRIx64"\n",reg_evp_alt2,is->insn->address);
                                // TODO could follow alt2 and make sure it matches expected mov r2,0, bl register..
                            }
                            break;
                        }
                    }
                }
            }
        }
    }

    // Try to find CreateTask
    uint32_t create_task=0;
    // on digic 6 firmwares, the eventproc points to CreateTask in RAM, but ROM firmware code goes through an ARM wrapper
    str_adr = find_str_bytes(fw,"FileWriteTask"); // fairly unique task name early in the dump
    if(str_adr) {
        disasm_iter_init(fw,is,str_adr - 1024); // reset to a bit before where the string was found
        while(fw_search_insn(fw,is,search_disasm_const_ref,str_adr,NULL,str_adr+1024)) {
            if(is->insn->detail->arm.operands[0].reg == ARM_REG_R0) {
                if(insn_match_find_next(fw,is,4,match_b_bl_blximm)) {
                    create_task=is->insn->detail->arm.operands[0].imm;
                    if(is->insn->id != ARM_INS_BLX) {
                        // if not a BLX, thumb address
                        create_task=ADR_SET_THUMB(create_task);
                    }

                    //printf("CreateTask found 0x%08x at %"PRIx64"\n",create_task,is->insn->address);
                    add_func_name("CreateTask_arm",create_task,NULL);
                    // TODO could sanity check other args
                }
            }
        }
    }


    //printf("find e_to_evp calls\n");
    // TODO could check near where ExportToEventProcedure was found,
    // then search whole fw for refs to multiple (e.g. createtask)
    search_calls_multi_data_t match_fns[10];

    int match_fn_count=0;
    match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(e_to_evp);
    match_fns[match_fn_count].fn=process_reg_eventproc_call;
    match_fn_count++;
    if(reg_evp_alt1) {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(reg_evp_alt1);
        match_fns[match_fn_count].fn=process_reg_eventproc_call;
        match_fn_count++;
    }
    if(reg_evp_alt2) {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(reg_evp_alt2);
        match_fns[match_fn_count].fn=process_reg_eventproc_call;
        match_fn_count++;
    }
    if(reg_evp_tbl) {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(reg_evp_tbl);
        match_fns[match_fn_count].fn=process_reg_eventproc_table_call;
        match_fn_count++;
    }
    if(create_task) {
        match_fns[match_fn_count].adr=ADR_CLEAR_THUMB(create_task);
        match_fns[match_fn_count].fn=process_createtask_call;
        match_fn_count++;
    }
    match_fns[match_fn_count].adr=0;
    match_fns[match_fn_count].fn=NULL;

    // TODO should search ram CODE
    disasm_iter_init(fw,is,fw->rom_code_search_min_adr); // reset to start of fw
    fw_search_insn(fw,is,search_disasm_calls_multi,0,match_fns,0);

    disasm_iter_free(is);
}

void output_firmware_vals(firmware *fw)
{
    bprintf("// Camera info:\n");
    bprintf("//   Main firmware start: 0x%08x\n",fw->base+fw->main_offs);
    if (fw->dryos_ver == 0)
    {
        bprintf("//   Can't find DRYOS version !!!\n\n");
    } else {
        bprintf("//   DRYOS R%d (%s)\n",fw->dryos_ver,fw->dryos_ver_str);
    }
    if (fw->firmware_ver_str == 0)
    {
        bprintf("//   Can't find firmware version !!!\n\n");
    }
    else
    {
        char *c = strrchr(fw->firmware_ver_str,' ') + 1; // points after the last space char
        uint32_t j = ptr2adr(fw,(uint8_t *)fw->firmware_ver_str);
        uint32_t k = j + c - fw->firmware_ver_str;
        if ( (k>=j) && (k<j+32) )
        {
            bprintf("//   %s   // Found @ 0x%08x, \"%s\" @ 0x%08x\n",fw->firmware_ver_str,j,c,k);
        }
        else
        {
            // no space found in string (shouldn't happen)
            bprintf("//   %s   // Found @ 0x%08x, \"%s\" @ 0x%08x\n",fw->firmware_ver_str,j,fw->firmware_ver_str,j);
        }
    }
    bprintf("\n// Values for makefile.inc\n");
    bprintf("//   PLATFORMOSVER = %d\n",fw->dryos_ver);

    if (fw->memisostart) {
        bprintf("//   MEMISOSTART = 0x%x\n",fw->memisostart);
    } else {
        bprintf("//   MEMISOSTART not found !!!\n");
    }
    if (fw->data_init_start)
    {
        bprintf("//   MEMBASEADDR = 0x%x\n",fw->data_start);
        bprintf("\n// Note, init DATA :- from 0x%08x, to 0x%08x, len %d words.\n",fw->data_init_start,fw->data_start,fw->data_len/4);
    }
    if (fw->base2 != 0)
    {
        bprintf("\n// Note, ROM copied to RAM :- from 0x%08x, to 0x%08x, len %d words.\n",fw->base_copied,fw->base2,fw->size2/4);
    }

}
// copied from finsig_dryos
int compare_func_names(const func_entry **p1, const func_entry **p2)
{
    int rv = strcasecmp((*p1)->name, (*p2)->name);     // Case insensitive
    if (rv != 0)
        return rv;
    rv = strcmp((*p1)->name, (*p2)->name);          // Case sensitive (if equal with insensitive test)
    if (rv != 0)
        return rv;
    if ((*p1)->val < (*p2)->val)
        return -1;
    else if ((*p1)->val > (*p2)->val)
        return 1;
    return 0;
}

int compare_func_addresses(const func_entry **p1, const func_entry **p2)
{
    if ((*p1)->val < (*p2)->val)
        return -1;
    else if ((*p1)->val > (*p2)->val)
        return 1;
    return compare_func_names(p1,p2);
}

void write_funcs(firmware *fw, char *filename, func_entry *fns[], int (*compare)(const func_entry **p1, const func_entry **p2))
{
    int k;

    qsort(fns, next_func_entry, sizeof(func_entry*), (void*)compare);

    FILE *out_fp = fopen(filename, "w");
    for (k=0; k<next_func_entry; k++)
    {
        if (strncmp(fns[k]->name,"hook_",5) != 0)
        {
            if (fns[k]->val != 0)
            {
                if (fns[k]->flags & BAD_MATCH)
                {
                    osig* ostub2 = find_sig(fw->sv->stubs,fns[k]->name);
                    if (ostub2 && ostub2->val)
                        fprintf(out_fp, "0x%08x,%s,(stubs_entry_2.s)\n", ostub2->val, fns[k]->name);
                }
                else
                    fprintf(out_fp, "0x%08x,%s\n", fns[k]->val, fns[k]->name);
            }
#ifdef LIST_IMPORTANT_FUNCTIONS
            else if (fns[k]->flags & LIST_ALWAYS)
            {
                // helps development by listing important functions even when not found
                fprintf(out_fp, "0,%s,(NOT FOUND)\n", fns[k]->name);
            }
#endif
        }
    }
    fclose(out_fp);
}
// end copy finsig_dryos
void write_func_lists(firmware *fw) {
    func_entry *fns[MAX_FUNC_ENTRY];
    int k;
    for (k=0; k<next_func_entry; k++)
        fns[k] = &func_names[k];

    write_funcs(fw, "funcs_by_name.csv", fns, compare_func_names);
    write_funcs(fw, "funcs_by_address.csv", fns, compare_func_addresses);
}

// Output match results for function
// matches stuff butchered out for now, just using value in func_names table
void print_results(firmware *fw, const char *curr_name, int k)
{
    int i;
    int err = 0;
    char line[500] = "";

    if (func_names[k].flags & DONT_EXPORT) {
        return;
    }

    // find best match and report results
    osig* ostub2 = find_sig(fw->sv->stubs,curr_name);

    if (ostub2 && (func_names[k].val != ostub2->val))
    {
        if (ostub2->type != TYPE_IGNORE)
            err = 1;
        func_names[k].flags |= BAD_MATCH;
    }
    else
    {
        if (func_names[k].flags & UNUSED) return;
    }

    // write to header (if error) or body buffer (no error)
    out_hdr = err;

    char *macro = "NHSTUB";
    if (strncmp(curr_name,"task_",5) == 0 ||
        strncmp(curr_name,"hook_",5) == 0) macro = "   DEF";

    if (!func_names[k].val && !ostub2)
    {
        if (func_names[k].flags & OPTIONAL) return;
        char fmt[50] = "";
        sprintf(fmt, "// ERROR: %%s is not found. %%%ds//--- --- ", (int)(34-strlen(curr_name)));
        sprintf(line+strlen(line), fmt, curr_name, "");
    }
    else
    {
        if (ostub2 || (func_names[k].flags & UNUSED))
            sprintf(line+strlen(line),"//%s(%-37s,0x%08x) //%3d ", macro, curr_name, func_names[k].val, 0);
        else
            sprintf(line+strlen(line),"%s(%-39s,0x%08x) //%3d ", macro, curr_name, func_names[k].val, 0);

        /*
        if (matches->fail > 0)
            sprintf(line+strlen(line),"%2d%% ", matches->success*100/(matches->success+matches->fail));
        else
            */
            sprintf(line+strlen(line),"    ");
    }

    if (ostub2)
    {
        if (ostub2->type == TYPE_IGNORE)
            sprintf(line+strlen(line),"       Overridden");
        else if (func_names[k].val == ostub2->val)
            sprintf(line+strlen(line),"       == 0x%08x    ",ostub2->val);
        else
            sprintf(line+strlen(line),"   *** != 0x%08x    ",ostub2->val);
    }
    else
        sprintf(line+strlen(line),"                        ");

    for (i=strlen(line)-1; i>=0 && line[i]==' '; i--) line[i] = 0;
    bprintf("%s\n",line);

    /*
    for (i=1;i<count && matches[i].fail==matches[0].fail;i++)
    {
        if (matches[i].ptr != matches->ptr)
        {
            bprintf("// ALT: %s(%s, 0x%x) // %d %d/%d\n", macro, curr_name, matches[i].ptr, matches[i].sig, matches[i].success, matches[i].fail);
        }
    }
    */
}

void write_stubs(firmware *fw,int max_find_func) {
    int k;
    for (k = 0; k < max_find_func; k++)
    {
        const char *curr_name = func_names[k].name;
        print_results(fw,curr_name,k);
    }
}

int main(int argc, char **argv)
{
    clock_t t1 = clock();

    firmware fw;
    memset(&fw,0,sizeof(firmware));
    if (argc < 4) {
        fprintf(stderr,"finsig_thumb2 <primary> <base> <outputfilename>\n");
        exit(1);
    }

    for (next_func_entry = 0; func_names[next_func_entry].name != 0; next_func_entry++);
    int max_find_func = next_func_entry;

    fw.sv = new_stub_values();
    load_stubs(fw.sv, "stubs_entry_2.S", 1);
    load_stubs_min(fw.sv);

    bprintf("// !!! THIS FILE IS GENERATED. DO NOT EDIT. !!!\n");
    bprintf("#include \"stubs_asm.h\"\n\n");

    firmware_load(&fw,argv[1],strtoul(argv[2], NULL, 0),FW_ARCH_ARMv7);
    if(!firmware_init_capstone(&fw)) {
        exit(1);
    }
    firmware_init_data_ranges(&fw);

    out_fp = fopen(argv[3],"w");
    if (out_fp == NULL) {
        fprintf(stderr,"Error opening output file %s\n",argv[3]);
        exit(1);
    }
    
    output_firmware_vals(&fw);
    find_event_procs(&fw);

    write_stubs(&fw,max_find_func);

    write_output();
    fclose(out_fp);

    write_func_lists(&fw);

    firmware_unload(&fw);

    clock_t t2 = clock();

    printf("Time to generate stubs %.2f seconds\n",(double)(t2-t1)/(double)CLOCKS_PER_SEC);

    return 0;
}