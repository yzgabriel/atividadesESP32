#include <Arduino.h>
#include "botao.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

Botao btnA(7);
Botao btnB(6);

const int pinLedVermelho = 10;
const int pinLedVerde = 8;

static bool estadoLedVermelho;
static bool estadoLedVerde;

static int contador = 0;

static bool ehImparOuPar = 0;

void lcdIniciar();
void atualizarContador();

void setup() 
{   
  btnA.iniciar();
  btnB.iniciar();

  pinMode(pinLedVermelho, OUTPUT);
  pinMode(pinLedVerde, OUTPUT);

  lcdIniciar();
}

void loop()
{
  bool precisaAtualizarTela = false;

  if(btnA.pressionou())
  {
    precisaAtualizarTela = true;
    contador++;
    if(!precisaAtualizarTela)
    {
      return; 
    }

    lcd.setCursor(0,7);
    contador % 2 == 0
    ? ehImparOuPar = 0
    : ehImparOuPar = 1;
    lcd.setCursor(7, 1);
    lcd.print("      ");
    atualizarContador();
  }

  if(btnB.pressionou())
  {
    contador = 0;
    ehImparOuPar = 0;

    atualizarContador();
  }

  if(ehImparOuPar == 0)
  {
    digitalWrite(pinLedVermelho, LOW);
    digitalWrite(pinLedVerde, HIGH);

  }

  if(ehImparOuPar == 1)
  {
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedVermelho, HIGH);

  }

  precisaAtualizarTela = false;
  lcd.setCursor(7, 1);
  lcd.print("      ");
  btnA.atualizar();
  btnB.atualizar();
}



void lcdIniciar()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Cliques");
  lcd.setCursor(8, 0);
  lcd.print(contador);
  lcd.setCursor(0,1);
  lcd.print("Numero");
  lcd.setCursor(7, 1);
  lcd.print("Par");

}

void atualizarContador()
{
  lcd.setCursor(8, 0);
  lcd.print(contador);
  if(ehImparOuPar == 0)
  {
    lcd.setCursor(7, 1);
    lcd.print("Par");
  }
  else
  {
    lcd.setCursor(7, 1);
    lcd.print("Impar");
  }
}