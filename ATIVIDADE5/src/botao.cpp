#include "botao.h"

Botao::Botao(uint8_t pino) : _pinoBotao(pino)
{

}

void Botao::iniciar()
{
    pinMode(_pinoBotao, INPUT_PULLUP);
}

void Botao::atualizar()
{
    _pressionou = false;
    _soltou = false;

    _estadoAtualBotao = digitalRead(_pinoBotao);
    if(_estadoAtualBotao != _estadoAnteriorBotao)
    {
        _estadoAnteriorBotao = _estadoAtualBotao;
        
        if(_estadoAnteriorBotao == LOW)
            _pressionou = true;
        else
            _soltou = true;
    }  
}

bool Botao::pressionou()
{
    return _pressionou;
}

bool Botao::soltou()
{
    return _soltou;
}




