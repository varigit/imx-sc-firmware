
ifneq ($(UPPER_T), NONE)
    objs_test += test.o test_$(LOWER_T).o
endif

ifeq ($(LOWER_T), all)
    objs_test += test_a5x.o     	\
                 test_audio.o   	\
                 test_cci.o			\
                 test_conn.o		\
                 test_db.o			\
                 test_dblogic.o		\
                 test_dc.o			\
                 test_ddr.o			\
                 test_ddr_stress.o	\
                 test_dma.o			\
                 test_drc.o			\
                 test_drv.o			\
                 test_dsc.o			\
                 test_examples.o	\
                 test_gpu.o			\
                 test_hexdump.o		\
                 test_hsio.o		\
                 test_img.o			\
                 test_lsio.o		\
                 test_m4.o			\
                 test_otp.o 		\
                 test_pm.o			\
                 test_pmic.o		\
                 test_profile.o		\
                 test_reboot.o		\
                 test_misc.o		\
                 test_rm.o			\
                 test_temp.o		\
                 test_timer.o		\
                 test_uboot.o		\
                 test_vpu.o			\
                 test_isi.o			\
                 test_smmu.o		\
		 test_ddr_selfrefresh.o	\
		 test_ddr_retention.o
endif

OBJS += \
  $(foreach object,$(objs_test),$(OUT)/test/$(object))

DIRS += $(OUT)/test

