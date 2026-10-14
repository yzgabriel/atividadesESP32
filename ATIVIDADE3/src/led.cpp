#include "led.h"

Led::Led(uint8_t pino) : _pinoLed(pino)
{

}

void Led::ligar()
{
    _estadoLed = 1;
}

void Led::desligar()
{
    _estadoLed = 0;
}

void Led::alternar()
{
    _estadoLed = !_estadoLed;
}

void Led::ativarPiscar(uint32_t tempo_ms)
{
    _estaPiscando = HIGH;
    _intervaloPiscar_ms = tempo_ms;
}

    void Led::atualizar()
    {
        if(_estaPiscando == 1)
        {
            _tempoAgora_ms = millis();
            if(_tempoAgora_ms - _tempoAnterior_ms >= _intervaloPiscar_ms)    
            {
                alternar();     
                _tempoAnterior_ms = _tempoAgora_ms;
            } 
        }
        digitalWrite(_pinoLed, _estadoLed);
    }

void Led::desativarPiscar()
{
    _estaPiscando = LOW;
}


// void Led::setIntervaloPiscar(uint32_t tempo_ms)
// {
//     _intervaloPiscar_ms = tempo_ms;
// }