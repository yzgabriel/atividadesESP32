#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "botao.h"
#include "led.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

Botao btnA(7);
Botao btnB(6);  



uint32_t tempoAgora = 0;
uint32_t tempoAnterior = 0;
uint32_t tempoLcd = 0;

void atualizarTempoLcd();
void iniciarLcd();


void setup() 
{
  btnA.iniciar();
  btnB.iniciar();

  iniciarLcd();
}

void loop() 
{
  tempoAgora = millis();

  if(btnA.pressionou() || btnB.pressionou())
  {
    if(btnA.pressionou())
    {

    }
  }


  btnA.atualizar();
  btnB.atualizar();
}


void iniciarLcd()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Pausado");
  lcd.setCursor(0,1);
  lcd.print("mm:ss:dd");
}


void atualizarTempoLcd()
{
  const uint32_t minutos = tempoAgora / 60000;
  const uint32_t segundos = (tempoAgora / 1000) % 60;
  const uint32_t decimos = (tempoAgora / 100) % 10;

  lcd.setCursor(0,1);
  if (decimos < 10)
  {
    lcd.print("0");
  }
  lcd.print(minutos); 
  lcd.print(":");
  if (segundos < 10)
  {
    lcd.print("0");
  }
  lcd.print(segundos);
  lcd.print(":");
  if (minutos < 10)
  {
    lcd.print("0");
  }
  lcd.print(decimos);
  lcd.print(":");
}