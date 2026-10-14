#ifndef __LED_H__
#define __LED_H__

#include <Arduino.h>

class Led
{
    private:
        uint8_t _pinoLed;
        bool _estadoLed = 0;
        uint32_t _tempoAgora_ms = 0;
        uint32_t _tempoAnterior_ms = 0;
        uint32_t _intervaloPiscar_ms = 500;
        bool _estaPiscando = 0;

    public:
        Led(uint8_t pino);

        void iniciar();
        void atualizar();
        void ligar();
        void desligar();
        void alternar();
        void ativarPiscar(uint32_t tempo_ms);
        void desativarPiscar();
        //void setIntervaloPiscar(uint32_t tempo_ms);
};
#endif