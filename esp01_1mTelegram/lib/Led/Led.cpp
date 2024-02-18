#include "Arduino.h"
#include "Led.h"

void Led::SetPino(byte val){
    pino = val;
    pinMode(pino,OUTPUT);

}
void Led::LigaLed(){
    estado = 1;
    digitalWrite(pino,estado);

}
void Led::DesligaLed(){
    estado = 0;
    digitalWrite(pino,estado);
}

void Led::PiscaLed(int t){
    tempo = t;
    LigaLed();
    delay(tempo);
    DesligaLed();
    delay(tempo);

}