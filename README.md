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

