#include "CTBot.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <NTPtimeESP.h>
#define DEBUG_ON
NTPtime NTPch("gps.ntp.br"); 
CTBot myBot;
LiquidCrystal_I2C lcd(0x3f,16,2);
strDateTime dateTime;

 void setup() {
  lcd.begin();
  lcd.backlight();
  lcd.clear(); 
  Serial.begin(115200);
  lcd.print("TelegramBot...");
  myBot.wifiConnect("Net","44643904");
  myBot.setTelegramToken("1084311211:xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
  
  if (myBot.testConnection())
  {
  lcd.clear();
  lcd.print("Conexao OK");
  delay(500);
  }
  else
  {
  lcd.clear();
  lcd.print("Sem conexao");
  }
  
}

void loop() {
rellcd();
TBMessage msg;
   
if (myBot.getNewMessage(msg))
{
if(msg.text=="Teste" || msg.text=="teste")
{
myBot.sendMessage(msg.sender.id,"Comando execudado");
lcd.clear();
lcd.print("Execudado");
delay(1000);
lcd.clear();
}
if (msg.text=="Acender"||msg.text=="acender")

  lcd.backlight();

else if(msg.text=="Apagar"|| msg.text=="apagar")

  lcd.noBacklight();


else

myBot.sendMessage(msg.sender.id,"Digite um comando correto.");


}

    } 
    

void rellcd(){
  dateTime = NTPch.getNTPtime(-3.0,0);

if(dateTime.valid){
  lcd.setCursor(8, 0);
if(dateTime.hour <=9){
  lcd.print(0);
  }
  lcd.print(dateTime.hour);
 lcd.print(":");   

if(dateTime.minute <=9){
  lcd.print(0);
  }
  lcd.print(dateTime.minute);

  lcd.setCursor(0,0);
if(dateTime.dayofWeek==7){
  lcd.print("Sabado");
}
if(dateTime.dayofWeek==6) {
  lcd.print("Sexta");
 }
if(dateTime.dayofWeek==5) {
  lcd.print("Quinta");
  }
if(dateTime.dayofWeek==4) {
   lcd.print("Quarta");
  }
if(dateTime.dayofWeek==3) {
   lcd.print("Terca");
  }
if(dateTime.dayofWeek==2) {
   lcd.print("Segunda");
  }
if(dateTime.dayofWeek==1) {
   lcd.print("Domingo");
  }

if(dateTime.day <=9){ //data
   lcd.print(0);
  }
 lcd.setCursor(3,1);
 lcd.print(dateTime.day);
 lcd.print("/");
if(dateTime.month <=9){
   lcd.print(0);
  }
    lcd.print(dateTime.month);
 lcd.print("/");
if(dateTime.year <=9){
   lcd.print(0);
  }
    lcd.print(dateTime.year);
    

lcd.home();

/*if(dateTime.minute == 0){
lcd.backlight();
}

if(dateTime.minute > 15){
lcd.noBacklight();
} */
}
}




