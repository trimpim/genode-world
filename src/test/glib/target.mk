TARGET = test-glib
LIBS = libc pthread glib posix
SRC_C = main.c

# Strength through pointer arithmetic
main.c: $(call select_from_ports,glib)/src/lib/glib/tests/testglib.c
	$(VERBOSE)sed 's/gintptr/int/' $< > $@
