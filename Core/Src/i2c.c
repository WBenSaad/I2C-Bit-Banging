#include "i2c.h"

void delay_ms(uint16_t delay_value){

    __HAL_TIM_SET_COUNTER(&htim1,0);
    while(__HAL_TIM_GetCounter(&htim1 < delay_value));
}

void i2c_init()
{
    i2c_SET_SDA();
    i2C_SET_SCL();
}

void i2C_Start_Condition(){
    i2c_init();
    I2C_CLEAR_SDA();
    delay_ms(1);
    I2C_CLEAR_SCL();
    delay_ms(1);
}

void i2C_Stop_Condition(void){
    I2C_CLEAR_SDA();
    delay_ms(1);
    I2C_SET_SCL();
    delay_ms(1);
    I2C_SET_SDA();
    delay_ms(1);

}
uint8_t i2c_Read_Bit(void){
    uint8_t bit;
    I2C_SET_SDA
    delay_ms(1);
    I2C_SET_SCL();
    delay_ms(1);
    bit=I2C_READ_SDA();
    I2C_CLEAR_SCL();
    delay_ms(2);
    
    return bit;
}
void i2c_Read_Byte(Bool Stop ){

    for(int i=0;i<8;i++){
        byte = (byte << 1) | (i2c_Read_Bit());
    }
    if(Stop){
        i2C_Stop_Condition();
    }
}

void i2c_Read_Sequence(uint8_t Address,uint8_t Reg,uint8_t* buffer,uint8_t size ){
    uint8_t byte;
    I2C_Write_Byte((Address << 1 ) | I2C_MASTER_WRITE ,true,false);
    I2C_Write_Byte(Reg,false,false);
    I2C_Write_Byte((Address << 1 ) | I2C_MASTER_Read ,true,false);

    for(int i=0 ;i < size; i++){

        buffer[i]=i2c_Read_Byte(false);
    }

    i2C_Stop_Condition();
}

void i2c_Write_Bit(uint8_t bit) {
  if (bit) {
    set_SDA();
  } else {
    clear_SDA();
  }
  delay_ms(1);
  I2C_SET_SCL();
  delay_ms(1);
  I2C_CLEAR_SCL();
  delay_ms(2);

}

void i2C_Write_Byte(uint8_t Byte,Bool Start,Bool Stop){
    unsigned char mask =0x80
    if(Start){
        i2C_Start_Condition();
    }
    for(int i=0;i < 8 ;i++){

        i2c_Write_Bit(Byte & (mask) != 0);
        mask >>= 1; 
    }
    if(Stop){
        i2C_Stop_Condition();
    }
}

void i2c_Write_Sequence(uint8_t Address,uint8_t Reg,uint8_t* buffer,uint8_t size ){

    I2C_Write_Byte((Address << 1 ) | I2C_MASTER_WRITE ,true,false);
    I2C_Write_Byte(Reg,false,false);

    for(int i=0 ;i < size; i++){

        i2c_Write_Byte(buffer[i],false,false);
    }

    i2C_Stop_Condition();
}