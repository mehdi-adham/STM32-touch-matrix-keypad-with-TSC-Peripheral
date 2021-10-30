#ifndef	_24XXCONFIG_H
#define	_24XXCONFIG_H

extern I2C_HandleTypeDef hi2c2;

#define		_EEPROM_SIZE_KBIT                       128/*1    2       4     8       16      32      64      128*/
#define		_EEPROM24XX_I2C                         hi2c2			
#define		_EEPROM_FREERTOS_IS_ENABLE              0




#endif

