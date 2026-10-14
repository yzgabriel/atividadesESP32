#include <Arduino.h>
#include "botao.h"
#include "led.h"
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

Botao btnA(7);
Botao btnB(6);

Led ledVermelho(10);
Led ledAmarelo(9);
Led ledVerde(8);

void iniciarLcd();

void setup()
{
  btnA.iniciar();
  btnB.iniciar();

  iniciarLcd();
}

void loop()
{
  static int contador = 0;

  if (btnB.pressionou())
  {
    contador = 0;
  }
  if (btnA.pressionou())
  {
    if (contador <= 3)
    {
      contador++;
      contador > 3
      ? contador = 0
      : contador = contador;
    }
  }
  if(btnA.pressionou() || btnB.pressionou())
  {
    switch (contador)
    {
    case 0:
      ledVermelho.desativarPiscar();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Modo 0");
      lcd.setCursor(0, 1);
      lcd.print("Desligado");
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Modo 1");
      lcd.setCursor(0, 1);
      lcd.print("Todos acesos ");
      ledVermelho.ligar();
      ledAmarelo.ligar();
      ledVerde.ligar();
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Modo 2");
      lcd.setCursor(0, 1);
      lcd.print("Todos piscando ");
      ledVermelho.desligar();
      ledAmarelo.desligar();
      ledVerde.desligar();
      ledVermelho.ativarPiscar(500);
      ledAmarelo.ativarPiscar(500);
      ledVerde.ativarPiscar(500);
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Modo 3");
      lcd.setCursor(0, 1);
      lcd.print("Alerta ");
      ledVermelho.desativarPiscar();
      ledAmarelo.desativarPiscar();
      ledVerde.desativarPiscar();

      ledVermelho.ativarPiscar(150);
      break;

    default:
      break;
    }
  }
  btnA.atualizar();
  btnB.atualizar();
  ledVermelho.atualizar();
  ledAmarelo.atualizar();
  ledVerde.atualizar();
}

void iniciarLcd()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Modo 0");
  lcd.setCursor(0, 1);
  lcd.print("Desligado");
}