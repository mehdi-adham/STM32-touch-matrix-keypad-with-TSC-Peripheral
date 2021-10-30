/**
  ******************************************************************************
  * @file    RFID.h
  * @created 11/02/1398 9:01:22 AM
  * @author  HSA R&D Team - Mehdi Adham
  * @brief   This file contains all the functions RFID & password
  ******************************************************************************
  @verbatim     
  ==============================================================================      
                        ##### How to use this Library #####
  ============================================================================== 

  mode -> 

  Login ,
  NewCard ,
  NewPass ,
  DeleteCard ,
  DeleteAllCard ,
  DeletePass ,
  DeleteAllPass ,
  New_Admin_Card ,
  Change_Pass ,
  Change_Admin_Pass

  Example :
  if(mode == NewCard 
    New_Card();

  extern uint8_t Detect_card  varible in main.c or our file

  When you near the card Detect_card = 1 

  Add RFID_getCode(code)  Function in USART IRQ Handler 

  RFID Control:
   _________________________________________________________________________
  |      Command Name         |                     code                    |
  |___________________________|_____________________________________________|
  |         NewCard           |               *1#Near Card                  |
  |        DeleteCard         |               *3#Near Card                  |
  |       DeleteAllCard       |               *4#Near AdminCard             |
  |       New_Admin_Card      |                  ----------                 |
  |          NewPass          |               *2#Near yourCard|beep|pass    |
  |         DeletePass        |               *5#Pass#            |
  |       DeleteAllPass       |               *6#AdminPass#                 |
  |        Change_Pass        |               *8#Oldpass#NewPass#           |
  |      Change_Admin_Pass    |               *9#AdminPass#NewAdminPass#    |


  ******************************************************************************
  @endverbatim
  */
#ifndef __RFID_H
#define __RFID_H




/////////////////// Parameters ///////////////

//#define   TIMER_STEP         50
//#define   UART_STEP           2


/////////////////// Void ////////////////////
/*#define					EM_18*/
//#define					RDM_630
#define RFID_TIMEOUT			1000//ms
#define OPEN_Delay      		500 //ms
#define Default         		0xff
#define OPEN()          		(HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_SET))
#define CLOSE()         		(HAL_GPIO_WritePin(RELAY_GPIO_Port, RELAY_Pin, GPIO_PIN_RESET))

#define _lock_time				5 //minute
#define _unsuccess_login_num		5



typedef enum{
  Login = 0U,
  NewCard ,
  NewPass ,
  DeleteCard ,
  DeleteAllCard ,
  DeletePass ,
  DeleteAllPass ,
  New_Admin_Card ,
  Change_Pass ,
  Change_Admin_Pass
}RFID_ModeTypedef;


typedef enum{
  CardAndPass = 1U,
  CardOrPass ,
  CardOnly,
  PassOnly
}RFID_ModeWorkTypedef;


int Get_FREE_ADD_PASS(void);
int Get_FREE_ADD(void);
void RFID_getCode(uint8_t rcv);
uint8_t Get_USER_Card_nn(void);
uint8_t Update_USER_Card_nn(void);
uint8_t New_Card(void);
HAL_StatusTypeDef Card_Authentication(uint8_t *USERnn);
void Delete_AllCard(void);
HAL_StatusTypeDef Delete_Card(uint8_t *USERnn);
HAL_StatusTypeDef IS_Admin_Card(void);
uint8_t Get_Admin_Card_nn(void);
void Set_Admin_Card(void);
uint8_t New_Pass(uint16_t pass_val,uint8_t USERnn);
void Delete_AllPass(void);
HAL_StatusTypeDef Delete_Pass(uint8_t *USERnn ,uint16_t PASSWORD);
HAL_StatusTypeDef Pass_Authentication(uint8_t *USERnn ,uint16_t PASSWORD);
uint8_t Get_USER_Pass_nn(void);
uint8_t Update_USER_Pass_nn(void);
HAL_StatusTypeDef Change_Password(uint8_t *USERnn ,uint16_t Oldpassword ,uint16_t Newpassword);
uint8_t Get_Admin_Pass_nn(void);
void Set_Admin_Pass(uint16_t password);
HAL_StatusTypeDef IS_Admin_Pass(uint16_t PASSWORD);
void checksum(uint8_t val);

#endif


