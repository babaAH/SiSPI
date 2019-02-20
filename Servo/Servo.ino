#include <Servo.h>//подключение библеотеки для работы с сервами
#define red 2//с этой строчки к пину 2 на плате обращаемся как red
Servo servo1;//объект класса servo1

int water;//переменная для записи значения уровня воды

void setup() 
{
  pinMode(A0,INPUT);// пин А0 в режим ВХОД
  pinMode(red, OUTPUT);//пин 2 в режим ВЫХОД
  servo1.attach(4);//"вешаем" на 4й пин серву
  Serial.begin(9600);//общаемся с серийным портом на 9600 бод(?)
}

void loop() 
{
  water = (analogRead(A0));//считываем значение из датчика уровня
  //servo1.write(0);//
  Serial.println(water);//вывод в серийный порт
  
  if(water >= 250)
  {
    servo1.write(90);//поворот сервы на 90 градусов
    delay(1000);//простой МК на 1 сек.
    digitalWrite(red, HIGH);//на пин 2 подать 5 вольт
  }
  else
  {
    servo1.write(0);//повернуть серву на 0 градусов
    delay(1000);//пауза в 1 сек
    digitalWrite(red, LOW);//подать на пин 2 нуль вотльт
  }
  //delay(1000);
}
