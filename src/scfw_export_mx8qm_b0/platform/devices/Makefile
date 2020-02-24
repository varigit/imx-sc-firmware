
ifeq ($(HW), REAL)
	objs_devices := startup.o memops.o memcpy-armv7m.o aeabi_memset-thumb2.o

	ifneq ($(T),NONE)
		objs_devices += memops_test.o
	endif

else
	objs_devices := stub.o
endif

OBJS += \
  $(foreach object,$(objs_devices),$(OUT)/devices/$(object))

DIRS += $(OUT)/devices

ifeq ($(HW), REAL)

	SUBCOMPS := $(DEVICE)

	include $(foreach subcomp,$(SUBCOMPS),$(rootdir)/$(SRC)/devices/$(subcomp)/Makefile)

endif

