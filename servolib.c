
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "stm32f4xx_rcc.h"
#include "servolib.h"


void initPins(void) {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	// TIM3_CH1 -> PC6
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource6, GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource7, GPIO_AF_TIM3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource8, GPIO_AF_TIM3);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);

	GPIO_InitTypeDef initStruct;
	initStruct.GPIO_Mode = GPIO_Mode_AF;
	initStruct.GPIO_OType = GPIO_OType_PP;
	initStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	initStruct.GPIO_Speed = GPIO_Speed_100MHz;
	initStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
	GPIO_Init(GPIOD, &initStruct);

	initStruct.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_Init(GPIOC, &initStruct);
}

void initTim(void) {
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	TIM_TimeBaseInitTypeDef initStruct;
	initStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	initStruct.TIM_CounterMode = TIM_CounterMode_Up;
	initStruct.TIM_Period = 336 - 1;
	initStruct.TIM_Prescaler = 1000 - 1; // tim_tick = 16 800 Hz
	initStruct.TIM_RepetitionCounter = 0;

	TIM_TimeBaseInit(TIM3, &initStruct);
	TIM_TimeBaseInit(TIM4, &initStruct);
	TIM_Cmd(TIM3, ENABLE);
	TIM_Cmd(TIM4, ENABLE);
}

void initPWM(void) {
	/*
	 * mi lenne ha az initStruct-ot pointerkent kapna a fuggveny parameterben
	 * igy a strukturat lehetne globalis valtozoban tartani
	 * es lehetne PWM/kitoltesi tenyezo allito fuggvenyeket is irni
	 */
	TIM_OCInitTypeDef initStruct;
	initStruct.TIM_OCMode = TIM_OCMode_PWM2;
	initStruct.TIM_OutputState = TIM_OutputState_Enable;
	initStruct.TIM_OCPolarity = TIM_OCPolarity_Low;

	// periodus = 336 - 1
	// 50% = 168 - 1

	initStruct.TIM_Pulse = 168 - 1;

	// init all channel to 50% PWM
	// ----------------- TIM3 ------------------------
	TIM_OC1Init(TIM3, &initStruct);
	TIM_OC1PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM3, &initStruct);
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM3, &initStruct);
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);

	// ----------------- TIM4 ------------------------
	TIM_OC1Init(TIM4, &initStruct);
	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC2Init(TIM4, &initStruct);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	TIM_OC3Init(TIM4, &initStruct);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);


}








