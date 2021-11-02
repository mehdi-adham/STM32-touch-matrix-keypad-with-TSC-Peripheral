/**
 ******************************************************************************
 * @file    touchkey.h
 * @created 11/02/1398 9:01:22 AM
 * @author  Mehdi Adham
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

#include "main.h"
#include "touchkey.h"
#include "touchsensing.h"


#define detect_type TSL_STATEID_PROX
#define release_type TSL_STATEID_RELEASE

#define get_row_mtx4X3(NB) ((NB>=1 && NB<=3)?0:(NB>=4 && NB<=6)?4:(NB>=7 && NB<=9)?5:6)
#define get_column_mtx4X3(NB) ((NB==1 || NB==4 || NB==7 || NB=='*')?1:(NB==2 || NB==5 || NB==8 || NB==0)?2:3)
#define TKEY(NB) ((MyTKeys[get_row_mtx4X3(NB)].p_Data->StateId == detect_type) && (MyTKeys[get_column_mtx4X3(NB)].p_Data->StateId == detect_type))


uint16_t touch_flage[16]={0x0fff};

tsl_user_status_t touch_status = TSL_USER_STATUS_BUSY;
char GET_KEY = ' ';



void touchkey_scan(void){

	/*********************************touchkey_scan();**************************/

	/*	touch_status = tsl_user_Exec();
	if(TSL_USER_STATUS_BUSY == touch_status){TSL_STATUS_OK
		// Nothing to do
		if(cnt++%50==0){
		}
		HAL_Delay(1);
	}
	else*/
	if(touch_flage[0]==0x0fff /*  &&  touch_status == TSL_USER_STATUS_OK_ECS_ON*/){

		/*--1--*/

		if(TKEY(1)){
			touch_flage[0]=0;
			GET_KEY = '1';
		}

		/*--2--*/

		else if(TKEY(2)){
			touch_flage[0]=0;
			GET_KEY = '2';
		}

		/*--3--*/

		else if(TKEY(3)){
			touch_flage[0]=0;
			GET_KEY = '3';
		}


		//**************************************row 2******************************/

		/*--4--*/

		else if(TKEY(4)){
			touch_flage[0]=0;
			GET_KEY = '4';
		}


		/*--5--*/

		else if(TKEY(5)){
			touch_flage[0]=0;
			GET_KEY = '5';
		}


		/*--6--*/

		else if(TKEY(6)){
			touch_flage[0]=0;
			GET_KEY = '6';
		}


		//    //**************************************row 3******************************/
		/*--7--*/

		else if(TKEY(7)){
			touch_flage[0]=0;
			GET_KEY = '7';
		}



		/*--8--*/

		else if(TKEY(8)){
			touch_flage[0]=0;
			GET_KEY = '8';
		}



		/*--9--*/

		else if(TKEY(9)){
			touch_flage[0]=0;
			GET_KEY = '9';
		}


		//
		//    //**************************************row 4******************************/
		/*--
		 * --*--*/

		else if(TKEY('*')){
			touch_flage[0]=0;
			GET_KEY = '*';
		}


		/*--0--*/

		else if(TKEY(0)){
			touch_flage[0]=0;
			GET_KEY = '0';
		}

		/*--#--*/

		else if(TKEY('#')){
			touch_flage[0]=0;
			GET_KEY = '#';
		}

	}


	if((MyTKeys[6].p_Data->StateId == release_type) && (MyTKeys[3].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0001;
	}
	if((MyTKeys[6].p_Data->StateId == release_type) && (MyTKeys[2].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0002;
	}
	if((MyTKeys[6].p_Data->StateId == release_type) && (MyTKeys[1].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0004;
	}
	if((MyTKeys[5].p_Data->StateId == release_type) && (MyTKeys[3].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0008;
	}
	if((MyTKeys[5].p_Data->StateId == release_type) && (MyTKeys[2].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0010;
	}
	if((MyTKeys[5].p_Data->StateId == release_type) && (MyTKeys[1].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0020;
	}
	if((MyTKeys[4].p_Data->StateId == release_type) && (MyTKeys[3].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0040;
	}
	if((MyTKeys[4].p_Data->StateId == release_type) && (MyTKeys[2].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0080;
	}
	if((MyTKeys[4].p_Data->StateId == release_type) && (MyTKeys[1].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0100;
	}
	if((MyTKeys[0].p_Data->StateId == release_type) && (MyTKeys[3].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0200;
	}
	if((MyTKeys[0].p_Data->StateId == release_type) && (MyTKeys[2].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0400;
	}
	if((MyTKeys[0].p_Data->StateId == release_type) && (MyTKeys[1].p_Data->StateId == release_type)){
		touch_flage[0]|=0x0800;
	}

}

