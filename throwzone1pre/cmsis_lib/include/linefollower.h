#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H
 
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

 /*
 * left motor dir:PD8 pwm:PD12
 * right motor dir:PD9 pwm:PD13
 * upper motor:dir:PD10 pwm:PD14
 * down motor : dir:PD11 pwm:PD15
 */

 void pwminit();
 
 void dir1_init();
 void dir2_init();
 void dir3_init();
 void dir4_init();
 
 void motor1fwd(int pwm);
 void motor1bwd(int pwm);
 void motor1stop();
 
 void motor2fwd(int pwm);
 void motor2bwd(int pwm);
 void motor2stop();
 
 void motor3left(int pwm);
 void motor3right(int pwm);
 void motor3stop();
 
 void motor4left(int pwm);
 void motor4right(int pwm);
 void motor4stop();
 
 void motorfwd(int pwm1,int pwm2);
 void motorbwd(int pwm1,int pwm2);
 void motorleft(int pwm1,int pwm2);
 void motorright(int pwm1,int pwm2);
 void motorstop();
 
 void sensorinit();
 void senread1();
 void senread2();
 
 void lineflw1(int pwm1,int pwm2,int t);
 void lineflw2(int pwm1,int pwm2,int t);
 void lineflw1rev(int pwm1,int pwm2,int t);
 
#endif