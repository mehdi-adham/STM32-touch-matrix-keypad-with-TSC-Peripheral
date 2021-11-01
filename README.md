# Build STM32 "Touchkey Matrix 3x4" with TSC Peripheral
TSC technology in STM32 microcontrollers with TSL library enables the designer to easily add touch sensor capability to any application.

## Configure the pins for control by the TSC library
In this project, we have used the STM32F051C8 microcontroller, which has six TSC groups. Because we want to build a 3x4 matrix keyboard with them, we need 7 pin I/O groups. Since a maximum of three channels are used for each sampling capacitor, we need three TSC groups to build the matrix keyboard, and one pin is used for each group for the sampling capacitor, which eventually becomes 10 pins. (7 channels For touch sensor and 3 pins for sampling capacitor)

Open the STM32CubeIDE software and create a new project with the STM32F051C8 microcontroller. In the Pinout field, enter the pins as shown below. Note that we have enabled the USART1 unit. We will use it to send and display the touched number in the computer monitor serial.

