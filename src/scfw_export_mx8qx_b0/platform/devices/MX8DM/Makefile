
objs_mx8 := system_MX8DM.o handlers_MX8DM.o

ifdef ROM
objs_mx8 += gcc/startup_rom_MX8DM.o
else
objs_mx8 += gcc/startup_MX8DM.o
endif

OBJS += \
  $(foreach object,$(objs_mx8),$(OUT)/devices/MX8DM/$(object))

DIRS += $(OUT)/devices/MX8DM/gcc

