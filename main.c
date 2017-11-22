
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "servolib.h"


int main(void)
{
	initPins();
	initTim();
	initPWM();

    while(1)
    {

    }
}
