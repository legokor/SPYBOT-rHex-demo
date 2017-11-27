
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"
#include "servolib.h"


int main(void)
{
	initPins();
	initTim();
	initPWM(51);

	int driveState = 0;

    while(1)
    {
    	if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) {
    		// button is pushed down
    		if (driveState == 0) {
    			driveState = 1;
    			initPWM(99);
    		}
    	}
    	else {
    		// button is not pushed down
    		if (driveState == 1) {
    			driveState = 0;
    			initPWM(51);
    		}
    	}

    }// end of while(1)
}
