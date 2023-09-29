include $(REP_DIR)/lib/import/import-ldns.mk
LDNS_SRC_DIR := $(LDNS_PORT_DIR)/src/lib/ldns

LIBS += libc libssl

SRC_LDNS_C := $(notdir $(wildcard $(LDNS_SRC_DIR)/*.c))

SRC_C += $(filter-out linktest.c,$(SRC_LDNS_C))
SRC_C += $(notdir $(wildcard $(LDNS_SRC_DIR)/compat/b64*.c))
SRC_CC +=  getproto.cc

CC_C_OPT += -DHAVE_DSA_GET0_PQG -DHAVE_DSA_SIG_GET0 -DHAVE_DSA_SIG_SET0
CC_C_OPT += -DHAVE_EVP_MD_CTX_NEW -DHAVE_ECDSA_SIG_GET0 -DHAVE_DSA_GET0_KEY
CC_C_OPT += -Wno-stringop-truncation -Wno-array-parameter
CC_C_OPT += -Wno-int-conversion -Wno-stringop-overflow
CC_C_OPT += -Wno-implicit-function-declaration

vpath %.c $(LDNS_SRC_DIR) $(LDNS_SRC_DIR)/compat
vpath %.cc $(REP_DIR)/src/lib/ldns
