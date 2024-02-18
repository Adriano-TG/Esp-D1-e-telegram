#include <Led.h>

Led led1; //Instanciando um objeto
Led led2;
Led led3;

void setup(){

led1.SetPino(13); //Escolher o pino onde o led tá ligado
led2.SetPino(12);
led3.SetPino(11);

}
void loop(){

led1.PiscaLed(500); //Tempo ligado e desligado do led em ms
led2.LigaLed();
led3.DesligaLed();

}