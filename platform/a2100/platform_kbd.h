#ifndef PLATFORM_KBD_H
#define PLATFORM_KBD_H
// plaform specific keyboard defines, see core/kbd_common.c for documentation

#define KEYS_MASK0 (0x00000000)
#define KEYS_MASK1 (0x1F000000)
#define KEYS_MASK2 (0xF3C) 

#define SD_READONLY_FLAG    0x00020000 // Found @0xffe7172c, levent 0x90a
#define SD_READONLY_IDX     2
#define USB_MASK            0x00040000 // Found @0xffe71738, levent 0x902
#define USB_IDX             2

#endif
