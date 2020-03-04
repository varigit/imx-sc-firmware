#ifndef DRV_EEPROM_H
#define DRV_EEPROM_H

#define EEPROM_I2C_ADDRESS	0x52

#define CTL_CODE(function, method) ((4 << 16) | ((function) << 2) | (method))

#define METHOD_BUFFERED		0
#define METHOD_NEITHER		3

#define SOMINFO_READ_EEPROM	CTL_CODE(2100, METHOD_BUFFERED)
#define SOMINFO_WRITE_EEPROM	CTL_CODE(2101, METHOD_BUFFERED)

extern void eeprom_i2c_init(void);
extern status_t eeprom_i2c_write(uint8_t device_addr, uint8_t reg, const void *data, uint32_t dataLength);
extern status_t eeprom_i2c_read(uint8_t device_addr, uint8_t reg, void *data, uint32_t dataLength);

#endif
