#include "lolevel.h"
#include "platform.h"
#include "core.h"
#include "keyboard.h"


extern long link_bss_start;
extern long link_bss_end;
extern void boot();

void startup() {
    long *bss = &link_bss_start;
    // sanity check
    if ((long)&link_bss_end > (MEMISOSTART + MEMISOSIZE)) {
        started();
        shutdown();
    }
    // initialize .bss senment
    while (bss<&link_bss_end)
        *bss++ = 0;
    boot();
}

#define NUM_FL      101
#define NUM_DATA    2   // 2 words each entry, first is FL
//extern int focus_len_table[NUM_FL*NUM_DATA];

//asm1989 done for sx260
// Conversion factor lens FL --> 35mm equiv
// lens      35mm     CF
// ----      ----     --
// 4.5       25       ( 25/ 4.5) * 45 = 250  (min FL)
// 90.0      500      (500/90.0) * 45 = 250  (max FL)
#define CF_EFL      250
#define CF_EFL_DIV  45

const int zoom_points = NUM_FL;
extern int EFLensComGetFocalLength_my (void);

int get_effective_focal_length(int zp) {
//    return (CF_EFL*get_focal_length(zp))/CF_EFL_DIV;
	return (EFLensComGetFocalLength_my() * 1600);
}

int get_focal_length(int zp) {
    if (zp < 0) zp = 0;
    else if (zp >= NUM_FL) zp = NUM_FL-1;
//    return focus_len_table[zp*NUM_DATA];
	return (EFLensComGetFocalLength_my() * 1000);
}

int get_zoom_x(int zp) {
    //return get_focal_length(zp)*10/focus_len_table[0];
	return 1;
}

long get_vbatt_min()
{
    return 2*3300;
}


long get_vbatt_max()
{
    return 2*4168;  // 4168 original battery just charged ASM1989
}
