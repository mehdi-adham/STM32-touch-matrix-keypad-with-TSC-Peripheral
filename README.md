# Build STM32 "Touchkey Matrix 3x4" with TSC Peripheral
TSC technology in STM32 microcontrollers with TSL library enables the designer to easily add touch sensor capability to any application.

## Configure the pins for control by the TSC library
In this project, we have used the STM32F051C8 microcontroller, which has six TSC groups. Because we want to build a 3x4 matrix keyboard with them, we need 7 pin I/O groups. Since a maximum of three channels are used for each sampling capacitor, we need three TSC groups to build the matrix keyboard, and one pin is used for each group for the sampling capacitor, which eventually becomes 10 pins. (7 channels For touch sensor and 3 pins for sampling capacitor)

Open the STM32CubeIDE software and create a new project with the STM32F051C8 microcontroller. In the Pinout field, setup the pins as shown below. Note that we have enabled the USART1 unit. We will use it to send and display the touched number in the computer monitor serial.

![pinout](https://user-images.githubusercontent.com/39982694/139670395-a7f2861b-53cb-4b64-b6b7-6492499cecbf.png)

Then go to the System core in TSC and set the TSC parameters in the settings as shown below.

![config](https://user-images.githubusercontent.com/39982694/139673330-174e4614-2cda-4f9b-8049-aeb624e16ac3.png)

In the GPIO settings, the pin for the CS sampling capacitor should be set to alternate output open-drain mode, as shown in the figure below.In this project, we have selected pins PB0, PB7, PB14 for the CS sampling capacitor, so they are set to alternate output open-drain mode.

The I/O channel must be set to alternate output push-pull mode. Therefore, the other 7 channels used for the matrix key are set in alternate output push-pull mode, as shown in the figure below.

![config-GPIO](https://user-images.githubusercontent.com/39982694/139673666-ec774add-4bd7-4f32-844f-c705b45cdd37.png)

Now go to the Middleware section to use the TSL library in the program and check Enable to activate it

In the Sensor Selection tab, the type of sensor (proximity, touchkey, linear and rotary) that we use in this project, we set the touchkey and its related pins as shown below.

![TSL-Sensor Selection](https://user-images.githubusercontent.com/39982694/139673992-86ea0e98-d8fe-4293-896c-9b5cf4d769bd.jpg)

In the Config parameter tab, configure the important parameters for the Touchkey exactly as shown below. Touch sensor settings completed.

![TSL-config param](https://user-images.githubusercontent.com/39982694/139674241-802b6acd-4fe7-4bf7-b75c-9cbacd9cfe1c.jpg)

In the connectivity settings section, go to the USART1 section and set the Baud Rate of the serial connection to 9600.

![CONNECTIVITY](https://user-images.githubusercontent.com/39982694/139674476-800a4002-f18b-4798-8f37-09a2f8e37aee.png)

Now save the project and finally click Code Generation to generate the config code.

## Introduction to TSL Library
I will explain about the project code and the TSL library. The TSL library detects Touch and we can use it in our application.
**How to use TSL library functions in your application.**
One of the most important libraries is tsl_user, which contains the user configuration file for TOUCHSENSING MiddleWare. This library is available in the src folder.
An important function of this library is tsl_user_Exec (void), which is used to run the STMTouch driver, and if it reports a touch, its return value will be TSL_STATUS_OK.

So it is enough to use this function in the program whether the return value of this function is equal to TSL_STATUS_OK or not.
```
if(tsl_user_Exec() == TSL_STATUS_OK){

}
```
**Which channel or PIN has been touched?**
The tsl_user library has another important variable called MyTKeys[] of type TSL_TouchKey_T, which is an array of touch pin lists (we used seven pins in this project) from which touch detection information can be extracted.

**TSL_TouchKey_T** is a structure of the touch key sensor variables.
```
/** Contains definition of a TouchKey sensor.
  * Variables of this structure type can be placed in RAM or ROM.
  */
typedef struct
{
  TSL_TouchKeyData_T          *p_Data;    /**< Data (state id, counter, flags, ...) */
  TSL_TouchKeyParam_T         *p_Param;   /**< Parameters (thresholds, debounce, ...) */
  TSL_ChannelData_T           *p_ChD;     /**< Channel Data (Meas, Ref, Delta, ...) */
  CONST TSL_State_T           *p_SM;      /**< State Machine */
  CONST TSL_TouchKeyMethods_T *p_Methods; /**< Methods */
}
TSL_TouchKey_T;
```
We need the value p_Data*, which is of type TSL_TouchKeyData_T. Which contains all the data related to the touch key sensor.
Variables of this type of structure should only be in RAM.
```
/** Contains all data related to TouchKey sensor.
  * Variables of this structure type must be placed in RAM only.
  */
typedef struct
{
  TSL_StateId_enum_T StateId;         /**< Current state identifier */
  TSL_tCounter_T     CounterDebounce; /**< Counter for debounce and calibration management */
  unsigned int       CounterDTO : 6;  /**< Counter for DTO management (TSL_tCounter_T) */
  unsigned int       Change     : 1;  /**< The State is different from the previous one (TSL_StateChange_enum_T) */
  unsigned int       DxSLock    : 1;  /**< The State is locked by the DxS (TSL_Bool_enum_T) */
}
TSL_TouchKeyData_T;
```
The value of StartId indicates the current state of the touch pin, and if it is equal to detect_type, it means that it has detected the touch pin, so it is enough to compare the value of StartId seven pins with detect_type, if it is equal, it means the same pin is touched.
```
if(tsl_user_Exec() == TSL_STATUS_OK){
  if(MyTKeys[1].p_Data->StateId == detect_type)
    //...
  else if(MyTKeys[2].p_Data->StateId == detect_type)
    //...
  else if(MyTKeys[3].p_Data->StateId == detect_type)
   //...
}
```
Because in this project we want to make a 3x4 touch matrix key, we have designed it to use a maximum of seven pins (not 12 pins) of the microcontroller, which means that each touch will cause the user to touch two pins together.

![Touchkey matrix sensor](https://user-images.githubusercontent.com/39982694/139678854-59d9df0d-8581-4da8-ad18-71902b07dfaa.jpg)

So we need to check two pins, (matrix key number) as in the following code example:
```
if(tsl_user_Exec() == TSL_STATUS_OK){
  if(MyTKeys[1].p_Data->StateId == detect_type && MyTKeys[4].p_Data->StateId == detect_type)
  //...
}
```
I created a library for this project called **touchkey.c**, which is for managing the touch matrix keyboard.
This library has a function called **touchkey_scan(void)** that you just need to use in your application. Whenever a key is touched, it puts the number of that key in the GET_KEY variable.

**Note:** that you must first include the **touchkey.h** library in your application and extern the **GET_KEY** variable.
```
/* USER CODE BEGIN Includes */
#include "touchkey.h"
.
.
/* USER CODE BEGIN PV */
extern char GET_KEY ;
```
Finally the program code will be as follows:
```
/* USER CODE BEGIN WHILE */

	HAL_Delay(500);
	uint8_t key;
	while (1)
	{
		touchkey_scan();
		key =  GET_KEY;

		if(key != ' '){
			HAL_UART_Transmit(&huart1, &key, 1, 100);
			key = '\n';
			HAL_UART_Transmit(&huart1, &key, 1, 100);
                        GET_KEY = ' ';
		}

		// HAL_Delay(1);
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */

	}
	/* USER CODE END 3 */
```
**Important Note:** The tsl_user_Exec (void) function is in the timer interrupt and runs during the timer period. Therefore, we do not need to use this function in the program, and if it detects a touch, the variable touch_status changes.
