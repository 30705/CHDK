# sx60hs - 100g uses 100f source (identical firmware)

TARGET_FW:=$(PLATFORMSUB)

override PLATFORMSUB=100f

include $(camfw)/makefile.inc
