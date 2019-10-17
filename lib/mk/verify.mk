LIBS          = libc
SHARED_LIB    = yes
JDK_BASE      = $(call select_from_ports,jdk)/src/app/jdk/jdk/src/java.base
VERIFY_BASE   = $(JDK_BASE)/share/native/libverify

SRC_C        += check_code.c
SRC_C        += check_format.c

INC_DIR      += $(JDK_BASE)/share/native/include \
                 $(JDK_BASE)/share/native/libjava \
                 $(JDK_BASE)/share/native/libverify \
                 $(JDK_BASE)/unix/native/libjava \
                 $(JDK_BASE)/unix/native/include

CC_C_OPT = -D_ALLBSD_SOURCE

vpath %.c $(VERIFY_BASE)
