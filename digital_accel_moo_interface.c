#include "mymoo.h"
#if (ACTIVE_SENSOR == SENSOR_DIGITAL_ACCEL)

#include "digital_accel_moo_interface.h"
#include "rfid.h" /* sensor_counter */

#define BUF_SIZE 6

static uint8_t buf[BUF_SIZE];

void init_sensor() {
	digital_accel_setup_pins();
	digital_accel_init();
	digital_accel_power_on();
	/* Need to wait 5ms to power on. In the worse case, we're running at 4.75MHz
	 * so we need to wait, so 4.75MHz*5ms = 23750 cycles
	 */
	__delay_cycles(23750);
	digital_accel_set_filter(EDigitalAccelRange_4g, EDigitalAccelOdr_50Hz, 0);
	digital_accel_set_power(EDigitalAccelMode_Measurement,
                            EDigitalAccelLowNoise_low,
                            0);
}

void read_sensor(unsigned char volatile *target) {
	int i;
	
	/* We need to reverse the endianess of our data. X/Y/Z data is all two bytes,
	 * stored big endian form Accel, but we need it little endian
	 */
	if (digital_accel_spi_complete()) {
		for (i = 0; i < BUF_SIZE / 2; i++) {
			target[i*2] = buf[i*2 + 1];
			target[i*2 + 1] = buf[i*2];
		}
		digital_accel_spi_buf_mark_read();
		sensor_counter++;
  		target[7] = (sensor_counter & 0x00ff);
  		target[6]  = (sensor_counter & 0xff00) >> 8; // grab msb bits and store it
  	}
	
	if (!digital_accel_spi_in_use() && (digital_accel_read_address(DIGITAL_ACCEL_REG_STATUS) & DIGITAL_ACCEL_DATA_READY_MASK)) {
		digital_accel_spi_start(DIGITAL_ACCEL_READ, DIGITAL_ACCEL_REG_XDATA_L, buf, BUF_SIZE);
	}
}

#endif
