#include "CTBot.h"
#define on "Liga" 
#define off "Desligado"

CTBotInlineKeyboard myKbd;
CTBot myBot;
TBMessage msg;

int Id = 692208821;
int Pino = 0;
int i;

 void setup() {
   
  Serial.begin(115200);
  pinMode(Pino, OUTPUT);
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


void loop() {

telegram();

} 


    
void piscaled(){
  digitalWrite(Pino, HIGH); 
  delay(1000);                      
  digitalWrite(Pino, LOW);  
  delay(1000);                      
}



void telegram()
{
if (myBot.getNewMessage(msg)){

if(msg.text=="Ligar"|| msg.text=="ligar"){  
  digitalWrite(Pino, HIGH);
  myBot.sendMessage(Id,"Ok Ligado!");
}
else if(msg.text=="Desligar"||msg.text=="desligar") {
  digitalWrite(Pino, LOW);
  myBot.sendMessage(Id,"Ok Desligado!");
}

else if(msg.text=="Piscar"||msg.text=="piscar")
{
myBot.sendMessage(Id,"Comando sendo executado");
for ( i = 0; i < 9; i++)
   piscaled();
}
else if (msg.text == "Luz"||msg.text=="luz"){
	myBot.sendMessage(Id,"Lampada do quarto o que deseja fazer?",myKbd);
}
else if (msg.messageType == CTBotMessageQuery)
{
  if (msg.callbackQueryData.equals(on)){
  myBot.endQuery(msg.callbackQueryID, "A luz está acessa!");
  digitalWrite(Pino, HIGH);
  } 
	if (msg.callbackQueryData.equals(off)) {
   myBot.endQuery(msg.callbackQueryID, "A luz está apagada!");
   digitalWrite(Pino, LOW);
  }
  } 
else
   myBot.sendMessage(Id,"Olá! Digite uma das opções:\n-Ligar\n-Desligar\n-Piscar\n-Luz");

  	
}
delay(500);
}