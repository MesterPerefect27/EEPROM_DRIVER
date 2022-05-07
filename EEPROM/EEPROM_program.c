/*
 * EEPROM_program.c
 *
 *  Created on: Apr 22, 2022
 *      Author: INTEL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../../MCAL/I2C_Master/I2C_interface.h"
#include"EEPROM_interface.h"
#include"EEPROM_privet.h"
void EEPROM_voidInit(void)
{
	I2C_voidInit();
}
void EEPROM_voidWrite(U16 Copy_u16Address,U8 Copy_u8Data)
{

	U8 Status=I2C_enumStartCondition();
	if(Status==I2C_OK){
		Status=I2C_enum_Master_Send_Slave_Address_With_Write((EEPROM_Fixed_Address)|((Copy_u16Address&0X0700)>>8) );
		if(Status==I2C_OK){
			Status=I2C_enum_Master_Write_Byte_TO_Slave((U8)Copy_u16Address);
			if(Status==I2C_OK){
				Status=I2C_enum_Master_Write_Byte_TO_Slave(Copy_u8Data);
				if(Status==I2C_OK){
					I2C_voidStopCondition();
				}
			}
		}
	}



}
U8   EEPROM_u8Read(U16 Copy_u16Address)
{

	U8 Status=I2C_enumStartCondition();
	U8 LOC_u8Data;
	if(Status==I2C_OK){
		Status=I2C_enum_Master_Send_Slave_Address_With_Write((EEPROM_Fixed_Address)|((Copy_u16Address&0X0700)>>8));
		if(Status==I2C_OK){
			Status=I2C_enum_Master_Write_Byte_TO_Slave((U8)Copy_u16Address);
			if(Status==I2C_OK){
				Status=I2C_enumRepeatedStart();
				if(Status==I2C_OK){
					Status=I2C_enum_Master_Send_Slave_Address_With_Read((EEPROM_Fixed_Address)|((Copy_u16Address&0X0700)>>8));
					if(Status==I2C_OK){
						Status=I2C_enum_Master_Read_Byte_From_Slave_NAK(&LOC_u8Data);
						if(Status==I2C_OK){
							I2C_voidStopCondition();
						}
					}
				}
			}
		}
	}
return LOC_u8Data;
}
