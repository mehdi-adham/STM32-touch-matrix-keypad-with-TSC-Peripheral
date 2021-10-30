#ifndef __EEPROM_H
#define __EEPROM_H


extern I2C_HandleTypeDef hi2c2;


#define EEPROM_ADDRESS                          0xA0
#define EEPROM_MAXPKT                           32              //(page size)
#define EEPROM_WRITE                            10              //time to wait in ms
#define EEPROM_TIMEOUT                          5*EEPROM_WRITE  //timeout while writing
#define EEPROM_SECTIONSIZE                      64

#define USER_nn                                 0
#define LOG_nn                                  2
#define MAX_Byte_Card                           12
#define MAX_Byte_Pass                           2
#define MAX_Byte_log                            9
#define Max_user                                255
#define Max_log                                 255
#define LOGIN_PASS_START                        16


#define USER_PASS_START(nn)                     (LOGIN_PASS_START+((nn)*MAX_Byte_Pass))
#define USER_PASS_END()                         (LOGIN_PASS_START+((Max_user)*MAX_Byte_Pass))//526

#define Card_START                              USER_PASS_END()
#define USER_CARD_START(nn)                     (Card_START+((nn)*MAX_Byte_Pass))
#define USER_CARD_END()                         (Card_START+((Max_user)*MAX_Byte_Card))//3586

#define LOG_START                               USER_CARD_END() 
#define LOG_Type_START(nn)                      (LOG_START+((nn)*MAX_Byte_log))
#define LOG_END()                               (LOG_START+((Max_log)*MAX_Byte_log))//5881




void begin(I2C_HandleTypeDef* i2cPort);
HAL_StatusTypeDef readEEPROM(uint16_t address, uint8_t* MemTarget,uint16_t Size);
HAL_StatusTypeDef writeEEPROM(uint16_t address, uint8_t* MemTarget,uint16_t Size);








#endif