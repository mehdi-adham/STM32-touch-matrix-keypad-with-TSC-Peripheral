/**
  ******************************************************************************
  * @file    touchkey.h
  * @created 11/02/1398 9:01:22 AM
  * @author  HSA R&D Team - Mehdi Adham
  * @brief   This file contains all the functions touchkey
  ******************************************************************************
  @verbatim     
  ==============================================================================      
                        ##### How to use this Library #####
  ============================================================================== 

  extern char GET_KEY  varible in main.c or our file
 
  Add touchkey_scan() Function in main.c or our file

  When you touched the RFID KeyPad, The value of GET_KEY changes
  ******************************************************************************
  @endverbatim
  */
#ifndef __TOUCHKEY
#define __TOUCHKEY




void touchkey_scan(void);





#endif