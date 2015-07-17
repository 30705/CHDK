#include "platform.h"
#include "lolevel.h"

void shutdown()
{
    volatile long *p = (void*)0xc02200a0;
        
    asm(
         "MRS     R1, CPSR\n"
         "AND     R0, R1, #0x80\n"
         "ORR     R1, R1, #0x80\n"
         "MSR     CPSR_cf, R1\n"
         :::"r1","r0");
        
    *p = 0x44;

    while(1);
}



#define LED_BRIGHTNESS  200
#define LED_GREEN       4
#define LED_YELLOW      5
#define LED_ORANGE      7
#define LED_BLUE        8
#define LED_AF_BEAM     9
#define LED_TIMER       10

  
static void led_on(const int led, const int brightness)
{

    if (led < 4 || led > 10 || led == 6) return;
    static void* addr;
    addr = led_table + (led * 0x40);
    _UniqueLedOn(addr,brightness);

}
 
static void led_off(const int led)
{

    if (led < 4 || led > 10 || led == 6) return;
    static void* addr;
    addr = led_table + (led * 0x40);
    _UniqueLedOff(addr);

}

void debug_led(int state)
{

    if (state)
        led_on(LED_BLUE, LED_BRIGHTNESS);
    else
        led_off(LED_BLUE);

}

void set_led(int led, int state)
{
    if (state)
        led_on(led, LED_BRIGHTNESS);
    else
        led_off(led);

}

void camera_set_led(int led, int state, int bright)
{
	if (state) {
		if (bright > LED_BRIGHTNESS) bright = LED_BRIGHTNESS;
        led_on(led, bright);
	}
    else
        led_off(led);
}

int get_flash_params_count(void){
 return 111;
}

void *vid_get_bitmap_active_buffer()
{
    //???
    return (void*)(*(int*)0x8478);  // in sub_ffa387ac for 101b
}

void *vid_get_bitmap_active_palette() {
    return (void *)0x64ac8; // in sub_ffa387ac for 101b
}

int vid_get_palette_type() { return 1; }
int vid_get_palette_size() { return 16*4; }
