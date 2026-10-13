/*
  Projeto: Dois LEDs, dois ritmos
  Descrição: Cada led pisca ritmos diferentes, sem delay, com millis.
  Autor: Gabriel Chinaglia
  Data: 12/10/2026
  Versão 0.1
*/

#include <Arduino.h>

const int pinledVermelho = 10;
const int pinledVerde = 8;

static bool estadoLedVermelho = false;
static bool estadoLedVerde = false;

const int intervaloLedVermelho = 500;
const int intervaloLedVerde = 1300;

unsigned long tempoAtual = 0;
static unsigned long tempoAnteriorVermelho = 0;
static unsigned long tempoAnteriorVerde = 0;


void setup() 
{
  pinMode(pinledVermelho, OUTPUT);
  pinMode(pinledVerde, OUTPUT);
  

}
void loop()
{
  tempoAtual = millis();

  if(tempoAtual > tempoAnteriorVermelho + intervaloLedVermelho)
  {
    estadoLedVermelho = !estadoLedVermelho;
    tempoAnteriorVermelho = tempoAtual;
  }

  if(tempoAtual > tempoAnteriorVerde + intervaloLedVerde)
  {
    estadoLedVerde = !estadoLedVerde;
    tempoAnteriorVerde = tempoAtual;
  }


  digitalWrite(pinledVermelho, estadoLedVermelho);
  digitalWrite(pinledVerde, estadoLedVerde);
}