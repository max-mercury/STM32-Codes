#include "linefollower.h"

/*
 * left motor dir:PD8 pwm:PD12
 * right motor dir:PD9 pwm:PD13
 * upper motor:dir:PD10 pwm:PD14
 * down motor : dir:PD11 pwm:PD15
 */
 
 int sen1_1,sen1_2,sen1_3,sen1_4,sen1_5,sen1_6,sen1_7,sen1_8;
 int sen2_1,sen2_2,sen2_3,sen2_4,sen2_5,sen2_6,sen2_7,sen2_8;
  
void pwminit()
{
	/*Structures used in the configuration*/
	  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	  TIM_OCInitTypeDef  TIM_OCInitStructure;
	  GPIO_InitTypeDef GPIO_InitStructure;

	  /* Enable TIM4 Clock */
	  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	  /* Enable GPIOD Pins that are used for on board LED's */
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);

	  //Enabled GPIOB we are going to use PB6 which is linked to TIM4_CH1 according to the
	  //documentation
	  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	  /* Initialise  pins 13, 14 and 15 D - relating to on board LED's*/
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL ;
	  GPIO_Init(GPIOD, &GPIO_InitStructure);

	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	  GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);

	  /* Setup PWM */
	  uint16_t PrescalerValue = 0;
	  PrescalerValue = (uint16_t) ((SystemCoreClock /2) / 21000000) - 1;

	  /* Setup timer defaults */
	  TIM_TimeBaseStructure.TIM_Period = 100;
	  TIM_TimeBaseStructure.TIM_Prescaler = PrescalerValue;
	  TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;

	  TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

 	  /* Configure timer for PWM - channel 1*/
	  TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	  TIM_OCInitStructure.TIM_Pulse = 0;
	  TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	  //notice the number 1 in TIM_OC1Init
	  TIM_OC1Init(TIM4, &TIM_OCInitStructure);
	  TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);

	  /* Configure timer for PWM - channel 2 */
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	  TIM_OCInitStructure.TIM_Pulse = 0;
	  TIM_OC2Init(TIM4, &TIM_OCInitStructure);
	  TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);

	  /* Configure timer for PWM - channel 3*/
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	  TIM_OCInitStructure.TIM_Pulse = 0;
	  TIM_OC3Init(TIM4, &TIM_OCInitStructure);
	  TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);

	  /* Configure timer for PWM - channel 4 */
	  TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	  TIM_OCInitStructure.TIM_Pulse = 0;
	  TIM_OC4Init(TIM4, &TIM_OCInitStructure);
	  TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);

	  TIM_ARRPreloadConfig(TIM4, ENABLE);

	  /* Start timer*/
	  TIM_Cmd(TIM4, ENABLE);

}

void dir1_init()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOD, &GPIO_InitDef);

}


void dir2_init()
{
		RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
		GPIO_InitTypeDef GPIO_InitDef;

		GPIO_InitDef.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
		GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
		GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
		GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;

		GPIO_Init(GPIOD, &GPIO_InitDef);

}

void dir3_init()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOD, &GPIO_InitDef);
}

void dir4_init()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_11;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOD, &GPIO_InitDef);

}

void motor1fwd(int pwm)
{

	  GPIO_SetBits(GPIOD, GPIO_Pin_8);//PD8
	  TIM4 -> CCR1 = pwm;//PD12
}

void motor1bwd(int pwm)
{

	  GPIO_ResetBits(GPIOD, GPIO_Pin_8);//PD8
	  TIM4 -> CCR1 = pwm;//PD12
}

void motor1stop()
{
	TIM4->CCR1=0;
}

void motor2fwd(int pwm)
{

	  GPIO_ResetBits(GPIOD, GPIO_Pin_9);//PD9
	  TIM4 -> CCR2 = pwm;//PD13
}

void motor2bwd(int pwm)
{

	  GPIO_SetBits(GPIOD, GPIO_Pin_9);//PD9
	  TIM4 -> CCR2 = pwm;//PD13
}

void motor2stop()
{
	TIM4->CCR2=0;
}


void motor3left(int pwm)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_10);//PD10
	TIM4 -> CCR3 = pwm;//PD14
}

void motor3right(int pwm)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_10);//PD8
	TIM4 -> CCR3 = pwm;//PD14
}

void motor3stop()
{
	TIM4 -> CCR3 = 0;//PD14
}

void motor4left(int pwm)
{
	GPIO_SetBits(GPIOD, GPIO_Pin_11);//PD11
	TIM4 -> CCR4 = pwm;//PD15
}

void motor4right(int pwm)
{
	GPIO_ResetBits(GPIOD, GPIO_Pin_11);//PD11
	TIM4 -> CCR4 = pwm;//PD15
}

void motor4stop()
{
	TIM4 -> CCR4 = 0;//PD15
}

void motorfwd(int pwm1,int pwm2)
{
	motor1bwd(pwm1);
	motor2bwd(pwm2);
	motor3stop();
	motor4stop();
}

void motorbwd(int pwm1,int pwm2)
{
	motor1fwd(pwm1);
	motor2fwd(pwm2);
	motor3stop();
	motor4stop();
}


void motorleft(int pwm1,int pwm2)
{
	motor1stop();
	motor2stop();
	motor3left(pwm1);
	motor4left(pwm2);
}

void motorright(int pwm1,int pwm2)
{
	motor1stop();
	motor2stop();
	motor3right(pwm1);
	motor4right(pwm2);
}

void motorstop()
{
	motor1stop();
	motor2stop();
	motor3stop();
	motor4stop();
}

void sensorinit()
{
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitTypeDef GPIO_InitDef;

	GPIO_InitDef.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitDef.GPIO_OType = GPIO_OType_PP;
	GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitDef.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitDef.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOC, &GPIO_InitDef);

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	GPIO_InitTypeDef GPIO_Init2Def;

	GPIO_Init2Def.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;
	GPIO_Init2Def.GPIO_OType = GPIO_OType_PP;
	GPIO_Init2Def.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init2Def.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init2Def.GPIO_Speed = GPIO_Speed_2MHz;

	GPIO_Init(GPIOE, &GPIO_Init2Def);

}


void senread1()
{
	sen1_1 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_0);
	sen1_2 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_1);
	sen1_3 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2);
	sen1_4 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3);
	sen1_5 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4);
	sen1_6 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5);
	sen1_7 = GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_6);
}

void senread2()
{
	sen2_1 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_0);
	sen2_2 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1);
	sen2_3 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2);
	sen2_4 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3);
	sen2_5 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4);
	sen2_6 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5);
	sen2_7 = GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_6);
}

void lineflw1(int pwm1,int pwm2,int t)//fwd sensor
{
	 senread1();
	 if(sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorleft(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorleft(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		  motorleft(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorfwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorfwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && sen1_4 && sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorfwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && sen1_7 && sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && sen1_3 && sen1_4 && sen1_5 && sen1_6 && sen1_7 && sen1_8)
	 {
		 t--;
		 if (t > 0)
		 {
			 motorfwd(pwm1,pwm2);
		 }
		 else
		 {
			motorstop();
		 }
	 }
	 else
	 {
		 motorstop();
	 }
}

void lineflw2(int pwm1,int pwm2,int t)//right sensor
{
	 senread2();
	 if(sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorfwd(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorfwd(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		  motorfwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && sen1_4 && sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && sen1_7 && !sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && sen1_7 && !sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && sen1_7 && sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && sen1_3 && sen1_4 && sen1_5 && sen1_6 && sen1_7 && sen1_8)
	 {
		 t--;
		 if (t > 0)
		 {
			 motorfwd(pwm1,pwm2);
		 }
		 else
		 {
			motorstop();
		 }
	 }
	 else
	 {
		 motorstop();
	 }
}

void lineflw1rev(int pwm1,int pwm2,int t)//fwd rev sensor
{
	 senread1();
	 if(sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorleft(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorleft(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		  motorleft(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && sen1_4 && sen1_5 && !sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorbwd(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && !sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && !sen1_6 && !sen1_7 && sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && sen1_7 && !sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(!sen1_1 && !sen1_2 && !sen1_3 && !sen1_4 && !sen1_5 && sen1_6 && sen1_7 && sen1_8)
	 {
		 motorright(pwm1,pwm2);
	 }
	 else if(sen1_1 && sen1_2 && sen1_3 && sen1_4 && sen1_5 && sen1_6 && sen1_7 && sen1_8)
	 {
		 t--;
		 if (t > 0)
		 {
			 motorfwd(pwm1,pwm2);
		 }
		 else
		 {
			motorstop();
		 }
	 }
	 else
	 {
		 motorstop();
	 }
}
