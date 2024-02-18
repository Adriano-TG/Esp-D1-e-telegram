#ifndef Led_H_
#define Led_H_
#include "Arduino.h"

class Led
{
private:
    byte pino;
    byte estado;
    int tempo;
public:
    
    void DesligaLed();
    void LigaLed();
    void SetPino(byte);
    void PiscaLed(int);

};

#endif
