/**
  ******************************************************************************
  * @file    log.h
  * @created 11/02/1398 9:01:22 AM
  * @author  HSA R&D Team - Mehdi Adham
  * @brief   This file contains all the log
  ******************************************************************************
  */

#ifndef __LOG_H
#define __LOG_H



typedef enum{
  Successful_login  = 0U,
  UnSuccessful_login  ,
  NewCard_register ,
  NewPass_register ,
  RemoveCard ,
  RemoveAllCard ,
  RemovePass ,
  RemoveAllPass ,
  Save_Admin_Card ,
  Reset_Pass ,
  Reset_Admin_Pass
}logTypedef;



  
  
void ADD_log(logTypedef logType ,uint8_t USERnn);

uint8_t Update_LOG_nn(void);

uint8_t Get_log_nn(void);

void reset_LOG_nn(void);


#endif