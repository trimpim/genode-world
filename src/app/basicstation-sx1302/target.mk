TARGET  := basicstation-sx1302

PORT_DIR     := $(call select_from_ports,basicstation-sx1302)/src/app/basicstation-sx1302
LIBGW_DIR    := $(PORT_DIR)/deps/lgw1302/platform-genode/libloragw
LIBTOOL_DIR  := $(PORT_DIR)/deps/lgw1302/platform-genode/libtools

LIBS     += base
LIBS     += libc
LIBS     += posix
LIBS     += mbedtls

CC_OPT   += -DCFG_linux -DCFG_argp -DCFG_no_leds -DCFG_no_rmtsh
CC_OPT   += -DCFG_lgw1
CC_OPT   += -DCFG_ral_lgw
CC_OPT   += -DCFG_version=\"2.0.6\"
CC_OPT   += -DCFG_platform_genode -DCFG_platform=\"genode\"
CC_OPT   += -DCFG_variant_std -DCFG_variant=\"std\"
CC_OPT   += -DCFG_bdate='"$(shell date -u '+%Y-%m-%d %H:%M:%S')"'
CC_OPT   += -DCFG_sx1302

CC_OPT   += -DDEBUG_MCU=0

#
# libloragw
#
LGW_FILTERS += loragw_i2c.c
LGW_FILTERS += loragw_spi.c
LGW_FILTERS += sx1250_i2c.c
LGW_FILTERS += sx1250_spi.c
LGW_FILTERS += sx125x_i2c.c
LGW_FILTERS += sx125x_spi.c
LGW_FILTERS += sx1261_i2c.c
LGW_FILTERS += sx1261_spi.c

LGW_SRC_C   += $(notdir $(wildcard $(LIBGW_DIR)/src/*.c))
SRC_C       += $(filter-out $(LGW_FILTERS),$(LGW_SRC_C))

#
# basicstation
#
BS_FILTERS  += lgwsim.c

BS_SRC_C    := $(notdir $(wildcard $(PORT_DIR)/src/*.c))
SRC_C       += $(filter-out $(BS_FILTERS),$(BS_SRC_C))

SY_SRC_C    := $(notdir $(wildcard $(PORT_DIR)/src-linux/*.c))
SRC_C       += $(SY_SRC_C)

INC_DIR     += $(PORT_DIR)/src
INC_DIR     += $(PORT_DIR)/src-linux
INC_DIR     += $(LIBGW_DIR)
INC_DIR     += $(LIBTOOL_DIR)/inc
INC_DIR     += $(LIBGW_DIR)/inc

vpath        %.c $(PORT_DIR)/src-linux
vpath loragw_%.c $(LIBGW_DIR)/src
vpath sx12%.c    $(LIBGW_DIR)/src

#
# genode specific random implementation
#
SRC_CC     += dummies.cc

INC_DIR    += $(PRG_DIR)

CC_CXX_WARN_STRICT =

vpath %.c $(PORT_DIR)/src

