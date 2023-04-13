#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <NTPtimeESP.h>
#define DEBUG_ON

NTPtime NTPch("a.st1.ntp.br"); 
char *ssid      = "Net";               
char *password  = "44643904";  

strDateTime dateTime;
LiquidCrystal_I2C lcd(0x3f,16,2);

void rellcd(){
  
  lcd.setCursor(4, 0);
if(dateTime.hour <=9){
  lcd.print(0);
  }
  lcd.print(dateTime.hour);
 lcd.print(":");   

if(dateTime.minute <=9){
  lcd.print(0);
  }
  lcd.print(dateTime.minute);
  lcd.print(":");
if(dateTime.second <=9){
  lcd.print(0);
  }
  lcd.print(dateTime.second);

  lcd.setCursor(1, 1);
if(dateTime.dayofWeek==7){
  lcd.print("Sab.");
}
if(dateTime.dayofWeek==6) {
  lcd.print("Sex.");
 }
if(dateTime.dayofWeek==5) {
  lcd.print("Qui.");
  }
if(dateTime.dayofWeek==4) {
   lcd.print("Qua.");
  }
if(dateTime.dayofWeek==3) {
   lcd.print("Ter.");
  }
if(dateTime.dayofWeek==2) {
   lcd.print("Seg.");
  }
if(dateTime.dayofWeek==1) {
   lcd.print("Dom.");
  }

if(dateTime.day <=9){ //data
   lcd.print(0);
  }
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

void setup() {
  Serial.begin(115200);
 
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  Serial.println();
  Serial.println("Iniciando");
  Serial.println("Connecting to Wi-Fi");

  WiFi.mode(WIFI_STA);
  WiFi.begin (ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("WiFi connected");
}

void loop() {
   dateTime = NTPch.getNTPtime(-3.0,0);
   
  if(dateTime.valid){
   Serial.print(dateTime.hour);
   Serial.print(":");
   Serial.print(dateTime.minute);
   Serial.print(":"); 
   Serial.print(dateTime.second);
   Serial.println();
   // NTPch.printDateTime(dateTime); data e hora na serial
     rellcd();
  }

 

    }
   // byte actualHour = dateTime.hour;
    //byte actualMinute = dateTime.minute;
    //byte actualsecond = dateTime.second;
   // int actualyear = dateTime.year;
   // byte actualMonth = dateTime.month;
   // byte actualday =dateTime.day;
   // byte actualdayofWeek = dateTime.dayofWeek;
  

