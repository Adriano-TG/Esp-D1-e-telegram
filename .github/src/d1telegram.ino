#include "CTBot.h"
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define on "Liga" 
#define off "Desligado"

CTBot myBot;
CTBotInlineKeyboard myKbd;
LiquidCrystal_I2C lcd(0x3f,16,2);
TBMessage msg;

void setup() {
   lcd.begin();
   lcd.backlight();
   lcd.clear(); 
   Serial.begin(115200);
   lcd.print("TelegramBot...");
   myBot.wifiConnect("Net","44643904"); 
   myBot.setTelegramToken("1084311211:AAGyuARTxFoe-Dvy2FEmuJ8a5vjygL90Gbw"); 
   
   myKbd.addButton("Ligar",on,CTBotKeyboardButtonQuery);
   myKbd.addButton("Desligar",off,CTBotKeyboardButtonQuery);
   Serial.print("digite 1 ou 2:");
}

void loop() 
{
 telegram();
}
    





void telegram()
{
	
	// se houver uma mensagem recebida ...
	if (myBot.getNewMessage(msg)) 
  {
    if (msg.text == "Ligar")
  {
        lcd.clear();
				lcd.print("Luz acessa");
        
  }

	if (msg.text == "Luz")
	{	
		myBot.sendMessage(msg.sender.id,"Lampada do quarto o que deseja fazer?",myKbd);

	}

		
	if (msg.messageType == CTBotMessageQuery)// Se for uma mensagem de consulta de retorno de chamada
  {
	if (msg.callbackQueryData.equals(on)) 
  {
        lcd.clear();
				lcd.print("Luz acessa");
				myBot.endQuery(msg.callbackQueryID, "A luz está acessa!");
        lcd.backlight();
	}
	if (msg.callbackQueryData.equals(off)) 
  {
        lcd.clear();
				lcd.print("Luz Apagada");
				myBot.endQuery(msg.callbackQueryID, "A luz está apagada!");
        lcd.noBacklight();
	}
	} 	
  if(msg.text =="Ajuda")
	{
  myBot.sendMessage(msg.sender.id,"Digite os seguintes comando:\n-Luz\n-Ligar");
  }
 
	}
  delay(500);
}