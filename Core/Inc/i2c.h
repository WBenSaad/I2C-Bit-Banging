#include "stm32f1xx_hal.h"

typedef enum {
    
    True    =0x1,
    False   =0x0,
}Bool;

typedef enum  {

    NACK        =0x0,
    ACK         =0x1,
    Arb_Lost    =0x2,        
}I2C_ret;

#define I2C_SDA_PIN            GPIO_PIN_7
#define I2C_SCL_PIN            GPIO_PIN_6

#define I2C_MASTER_WRITE       (uint8_t) 0x01
#define I2C_MASTER_Read        (uint8_t) 0x00


#define I2C_SET_SDA()          HAL_GPIO_WritePin(GPIOB,I2C_SDA_PIN,1);
#define I2C_SET_SCL()          HAL_GPIO_WritePin(GPIOB,I2C_SCL_PIN,1);
#define I2C_CLEAR_SDA()        HAL_GPIO_WritePin(GPIOB,I2C_SDA_PIN,0);
#define I2C_CLEAR_SCL()        HAL_GPIO_WritePin(GPIOB,I2C_SCL_PIN,0);
#define I2C_READ_SDA           HAL_GPIO_ReadPin(GPIO1,I2C_SDA_PIN);
#define I2C_READ_SCL           HAL_GPIO_ReadPin(GPIO1,I2C_SCL_PIN);


void delay_ms(uint16_t);
void i2c_init(void);
void i2c_Start_Condition(void);
void i2C_Stop_Condition(void);
void i2c_Read_Bit(void);
void i2c_Read_Byte(Bool Stop);
void i2c_Read_Sequence(uint8_t Address,uint8_t* buffer,uint8_t size);
void i2c_Write_Bit(uint8_t bit);
void i2c_Write_Byte(uint8_t byte,Bool Start,Bool Stop);
void i2c_Write_Sequence(uint8_t Adress,uint8_t* buffer,uint8_t size);


