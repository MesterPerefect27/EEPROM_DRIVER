/*
 * EEPROM_interface.h
 *
 *  Created on: Apr 22, 2022
 *      Author: INTEL
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidWrite(U16 Copy_u16Address,U8 Copy_u8Data);
U8   EEPROM_u8Read(U16 Copy_u16Address);

#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
