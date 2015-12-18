#include <Wire.h>
#include <Servo.h> 

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

const int RemotePin2 = 2; 
const int RemotePin3 = 3;
const int RemotePin4 = 6;
const int RemotePin5 = 5; 
//const int outpin6 = 6;
//const int outpin7 = 7;
//const int outpin8 = 8;
//const int outpin9 = 9;
const int servopin10 = 10;
const int servopin11 = 11;
const int servopin12 = 12;
const int servopin13 = 13;

Servo myservo10;
Servo myservo11;
Servo myservo12;
Servo myservo13;

int val0 = 0;
int val1 = 0;
int val2 = 0;
int val3 = 0;

int temp0;
int temp1;
int temp2;
int temp3;

int angle0;
int angle1;
int angle2;
int angle3;
   
void setup()
{
  Serial.begin(9600);
  pinMode(RemotePin2, INPUT);
  pinMode(RemotePin3, INPUT);
  pinMode(RemotePin4, INPUT);
  pinMode(RemotePin5, INPUT);
//  pinMode(outpin6, OUTPUT);
//  pinMode(outpin7, OUTPUT);
//  pinMode(outpin8, OUTPUT);
//  pinMode(outpin9, OUTPUT);
  myservo10.attach(servopin10);
  myservo11.attach(servopin11);
  myservo12.attach(servopin12);
  myservo13.attach(servopin13);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
}
void loop()
{
  val0= pulseIn(RemotePin2,HIGH);             //检测脉冲时间函数，时间与转轮速度成反比
  val1= pulseIn(RemotePin3,HIGH);
  val2= pulseIn(RemotePin4,HIGH);
  val3= pulseIn(RemotePin5,HIGH);
  
//  Serial.println(val0);
//  Serial.println(val1);
//  Serial.println(val2);
//  Serial.println(val3);

//  temp0=map(val0,1000,2000,0,255);   //把时间映射到0-255pwm输出，（30000不精准，还要调节）
//  temp1=map(val1,1000,2000,0,255);
//  temp2=map(val2,1000,2000,0,255);
//  temp3=map(val3,1000,2000,0,255);
  angle0=map(val0,1000,2000,0,180);
  angle1=map(val1,1000,2000,0,180);
  angle2=map(val2,1000,2000,0,180);
  angle3=map(val3,1000,2000,0,180);
//  temp0 = constrain(temp0,0,255);   //
//  temp1 = constrain(temp1,0,255);
//  temp2 = constrain(temp2,0,255);
//  temp3 = constrain(temp3,0,255);
//  analogWrite(outpin6,temp0);    //模拟量输出
//  //analogWrite(outpin7,temp1);
//  //analogWrite(outpin8,temp2);
//  analogWrite(outpin9,temp3);

  
//  for(int i = 0; i <= 50; i += 1)
//  {
    myservo10.write(angle0);
    myservo11.write(angle1);
    myservo12.write(angle2);
    myservo13.write(angle3);
//  }
//  Serial.println("val0~3");
//  Serial.println(val0);
//  Serial.println(val1);
//  Serial.println(val2);
//  Serial.println(val3);
//
//  Serial.println("temp0~3");
//  Serial.println(temp0);
//  Serial.println(temp1);
//  Serial.println(temp2);
//  Serial.println(temp3);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(val0);
  lcd.setCursor(4, 1);
  lcd.print(val1);
  lcd.setCursor(8, 0);
  lcd.print(val2);
  lcd.setCursor(12, 1);
  lcd.print(val3);
 

//  delay (10);
}
