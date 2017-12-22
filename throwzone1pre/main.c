#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

#include "encoder.h"
#include "linefollower.h"
#include "lcd_hd44780.h"

int ef1=100;//start line right align; right motor
int ef2=100;//left motor

int ef11=100;//throwing align right motor
int ef21=100;//left motor

int efr1=100;//rev after throwing right motor
int efr2=100;//left motor

int ef3=100;//part2 node pick up motor
int ef4=100;//down motor

int e1,e2,e3,e4;

int pwm1=20,pwm2=20;

void pick()
{
	//something to pick
}

void throw()
{
	//something to throw
}

void throwzone1(int time)
{
				e1=0;e2=0;

				while (e1 <= ef1 && e2 <= ef2)
				{
					motorfwd(pwm1,pwm2);//move forward
					e1=encoder1();//right motor encoder read
					e2=encoder2();//left motor encoder read
				}
				e1=0;e2=0;

				lineflw2(pwm1,pwm2,time*2);//left line follower
				//if all white in lineflw2() then stop/break

				while (e3 <= ef3 && e4 <= ef4)
				{
					motorright(pwm1,pwm2);//move right
					e3=encoder3();//upward motor encoder read
					e4=encoder4();//downward motor encoder read
				}
				e3=0;e4=0;

		here:	pick();

				lineflw1(pwm1,pwm2,time*2);//fwd line follower
				//if all white in lineflw1() then stop/break

				while (e1 <= ef11 && e2 <= ef21)
				{
					motorfwd(pwm1,pwm2);//move forward
					e1=encoder1();//right motor encoder read
					e2=encoder2();//left motor encoder read
				}
				e1=0;e2=0;

				throw();

				lineflw1rev(pwm1,pwm2,time*2);//fwd line follower reversed
				//if all white in lineflw1() then stop/break

				while (e1 <= efr1 && e2 <= efr2)
				{
					motorfwd(pwm1,pwm2);//move forward
					e1=encoder1();//right motor encoder read
					e2=encoder2();//left motor encoder read
				}
				e1=0;e2=0;
				time--;
				if(time > 0)
				{
					goto here;
				}
				else
					return;
}

void msdelay(unsigned int time){
    unsigned i,j ;
    for(i=0;i<time;i++)
    for(j=0;j<1275;j++);
}

int main(void)
{
	pwminit();
	dir1_init();
	dir2_init();
	dir3_init();
	dir4_init();
	sensorinit();
	encoder1_config();
	encoder2_config();
	encoder3_config();
	encoder4_config();
	lcd_init();
	int c1,c2,c3,c4;

	while(1)
	{
		//throwzone1(5);
		motorfwd(pwm1,pwm2);

		c1 = encoder1();
		lcd_locate(0,0);
		lcd_str("E1=");
		lcd_int(c1);

		c2 = encoder2();
		lcd_locate(7,0);
		lcd_str("E2=");
		lcd_int(c1);

		msdelay(1000);
	}
}

