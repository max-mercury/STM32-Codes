#ifndef ENCODER_H
#define ENCODER_H
 
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

void encoder1_config();
void encoder2_config();
void encoder3_config();
void encoder4_config();


int encoder1();
int encoder2();
int encoder3();
int encoder4();

#endif