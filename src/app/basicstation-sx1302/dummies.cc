
/* Genode includes */
#include <base/log.h>
#include <os/backtrace.h>
#include <base/sleep.h>

/* libc includes */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


extern "C" __attribute__((noreturn)) void lx_emul_trace_and_stop(const char * func)
{
	Genode::error("Function ", func, " not implemented yet!");
	Genode::backtrace();
	Genode::log("Will sleep forever...");
	Genode::sleep_forever();
}


extern "C" __attribute__((noreturn)) void print_backtrace(void) {
	Genode::backtrace();
	Genode::log("Will sleep forever...");
	Genode::sleep_forever();
}


extern "C"
{
	/* basicstation includes */
	#include <s2e.h>
	#include <xq.h>
	#include <ral.h>
	#include <sx1250_defs.h>

	int lgw_spi_close(void *) { lx_emul_trace_and_stop(__func__); }
	int lgw_spi_w(void *, uint8_t , uint8_t , uint8_t , uint8_t) { lx_emul_trace_and_stop(__func__); }
	int lgw_spi_r(void *, uint8_t , uint8_t , uint8_t , uint8_t *) { lx_emul_trace_and_stop(__func__); }
	int lgw_spi_wb(void *, uint8_t , uint8_t , uint8_t , uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }
	int lgw_spi_rb(void *, uint8_t , uint8_t , uint8_t , uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }

	int i2c_linuxdev_close(int) { lx_emul_trace_and_stop(__func__); }
	int i2c_linuxdev_open(const char *, uint8_t, int *) { lx_emul_trace_and_stop(__func__); };
	int i2c_linuxdev_read(int, uint8_t, uint8_t, uint8_t *) { lx_emul_trace_and_stop(__func__); }
	int i2c_linuxdev_write(int, uint8_t, uint8_t, uint8_t) { lx_emul_trace_and_stop(__func__); }
	int i2c_linuxdev_write_buffer(int, uint8_t, uint8_t *, uint8_t) { lx_emul_trace_and_stop(__func__); }

	uint16_t lgw_spi_chunk_size(void) { lx_emul_trace_and_stop(__func__); }
	int lgw_spi_open(void **) { lx_emul_trace_and_stop(__func__); }
	int lgw_spi_rmw(void *, uint8_t, uint16_t, uint8_t, uint8_t, uint8_t) { lx_emul_trace_and_stop(__func__); }
	int sx1250_spi_r(void *, uint8_t, sx1250_op_code_t, uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }
	int sx1250_spi_w(void *, uint8_t, sx1250_op_code_t, uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }
	int sx125x_spi_r(void *, uint8_t, sx1250_op_code_t, uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }
	int sx125x_spi_w(void *, uint8_t, sx1250_op_code_t, uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }
	int sx1261_spi_r(void *, uint8_t, sx1250_op_code_t, uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }
	int sx1261_spi_w(void *, uint8_t, sx1250_op_code_t, uint8_t *, uint16_t) { lx_emul_trace_and_stop(__func__); }


	/*
	 * there in no getpgid on Genode
	 */
	int getpgid(int) { return 0; }

}
