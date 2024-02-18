#include "CTBot.h"
#include <Led.h>

#define on "Liga" 
#define off "Desligado"

CTBotInlineKeyboard myKbd;
CTBot myBot;
Led led;

int Id = 692208821;
int i;

void telegram();

 void setup() {
   
  Serial.begin(115200);
  led.SetPino(0);
  myBot.wifiConnect("Net","44643904");
  myBot.setTelegramToken("1084311211:AAGyuARTxFoe-Dvy2FEmuJ8a5vjygL90Gbw");

  myKbd.addButton("Ligar",on,CTBotKeyboardButtonQuery);
  myKbd.addButton("Desligar",off,CTBotKeyboardButtonQuery);

  if (myBot.testConnection()){
		Serial.println("\nConexão OK");
    myBot.sendMessage(Id,"Conexão OK");
  }
	else{
	Serial.println("\nErro de conexão");
  }
 
  
}


void loop() 
{
telegram();


}
    
void telegram()
{
  TBMessage msg;
if (myBot.getNewMessage(msg))
{

  if(msg.text=="Ligar"|| msg.text=="ligar")
  {  
    led.LigaLed();
    myBot.sendMessage(Id,"Ok Ligado!");
  }
  else if(msg.text=="Desligar"||msg.text=="desligar") 
  {
    led.DesligaLed();
    myBot.sendMessage(Id,"Ok Desligado!");
    }

  else if(msg.text=="Piscar"||msg.text=="piscar")
  {
    myBot.sendMessage(Id,"Comando sendo executado");
    for ( i = 0; i < 9; i++)
    led.PiscaLed(500);
}
  else if (msg.text == "Luz"||msg.text=="luz")
  {
	  myBot.sendMessage(Id,"Lampada do quarto o que deseja fazer?",myKbd);
}
  else if (msg.messageType == CTBotMessageQuery)
{
  if (msg.callbackQueryData.equals(on)){
    myBot.endQuery(msg.callbackQueryID, "A luz está acessa!");
    led.LigaLed();
  } 
	if (msg.callbackQueryData.equals(off)) {
    myBot.endQuery(msg.callbackQueryID, "A luz está apagada!");
    led.DesligaLed();
  }
  } 
  else
    myBot.sendMessage(Id,"Olá! Digite uma das opções:\n-Ligar\n-Desligar\n-Piscar\n-Luz");

  	
}
delay(500);

}