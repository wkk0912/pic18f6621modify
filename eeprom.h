#ifndef __EEPROM
#define __EEPROM


void write_data_to_eeprom(unsigned int addr,unsigned char data);
unsigned char read_data_from_eeprom(unsigned int addr);
void record_a_err(unsigned char err_style);
void read_a_err(void);

#endif
