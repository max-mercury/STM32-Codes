#include "encoder.h"

int aLastState1,aLastState2,aLastState3,aLastState4;

void encoder1_config()
{
	//right motor
	//PB8 encoder pin A ie CLK
	//PB7 encoder pin B ie DT

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	aLastState1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);//channel A
}

void encoder2_config()
{
	//left motor
	//PB11 encoder pin A ie CLK
	//PB12 encoder pin B ie DT

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	aLastState2 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);//channel A
}

void encoder3_config()
{
	//up motor
	//PB4 encoder pin A ie CLK
	//PB5 encoder pin B ie DT

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	aLastState3 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);//channel A
}

void encoder4_config()
{
	//down motor
	//PC8 encoder pin A ie CLK
	//PC9 encoder pin B ie DT

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	aLastState4 = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);//channel A
}

int encoder1()
{
	int aState = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);//channel A
	int count;

	if (aState != aLastState1)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) != aState )//channel B
			{
	    		count++;
	    	}
	    else
	    	{
	    		count--;
	    	}
	 }
	 aLastState1 = aState;
	 return count;
}

int encoder2()
{
	int aState = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);//channel A
	int count;

	if (aState != aLastState2)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_7) != aState )//channel B
			{
	    		count++;
	    	}
	    else
	    	{
	    		count--;
	    	}
	 }
	 aLastState2 = aState;
	 return count;
}

int encoder3()
{
	int aState = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_4);//channel A
	int count;

	if (aState != aLastState3)
	{
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_5) != aState )//channel B
			{
	    		count++;
	    	}
	    else
	    	{
	    		count--;
	    	}
	 }
	 aLastState3 = aState;
	 return count;
}

int encoder4()
{
	int aState = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_8);//channel A
	int count;

	if (aState != aLastState4)
	{
		if(GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_9) != aState )//channel B
			{
	    		count++;
	    	}
	    else
	    	{
	    		count--;
	    	}
	 }
	 aLastState4 = aState;
	 return count;
}
