/*
 * RGB.h
 *
 *  Created on: May 30, 2019
 *      Author: Mehdi
 */

#ifndef RGB_H_
#define RGB_H_

#define htim_LED_R	htim16
#define htim_LED_B	htim17

#define TIM_CHANNEL_LED_R	TIM_CHANNEL_1
#define TIM_CHANNEL_LED_B	TIM_CHANNEL_1
//#define TIM_CHANNEL_LED_G

void custom_colors(uint8_t RED_val, uint8_t GREEN_val ,uint8_t BLUE_val);

void My_color(void);




#endif /* RGB_H_ */
