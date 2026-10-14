#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "botao.h"
#include "led.h"

LiquidCrystal_I2C lcd(0x27, 20, 4);

Botao btnA(7);
Botao btnB(6);

Led ledVermelho(10);
Led ledAmarelo(9);
Led ledVerde(8);

void iniciarLcd();
void subirNivel();
void descerNivel();
void atualizarLcd();

static int nivel = 0;
static int barraDeNivel = 0;

void setup()
{
  btnA.iniciar();
  btnB.iniciar();

  ledVermelho.iniciar();
  ledAmarelo.iniciar();
  ledVerde.iniciar();

  iniciarLcd();
}

void loop()
{
  if (nivel > 0 && nivel <= 3)
  {
    ledVerde.ligar();
    ledAmarelo.desligar();
  }

  if (nivel >= 4 && nivel <= 7)
  {
    ledVerde.desligar();
    ledAmarelo.ligar();
    ledVermelho.desligar();
  }
  
  if (nivel >= 8 && nivel <= 9)
  {
    ledAmarelo.desligar();
    ledVermelho.ligar();
    ledVermelho.desativarPiscar();
  }

  if (nivel == 10)
  {
    ledVermelho.ativarPiscar(200);
  }


  if (btnA.pressionou() || btnB.pressionou())
  {
    if (btnA.pressionou())
    {
      subirNivel();
      atualizarLcd();
      for (int i = 1; i <= nivel; i++)
      {
        lcd.setCursor(i, 1);
        lcd.print("#");
      }
    }
    if (btnB.pressionou())
    {
      descerNivel();
      atualizarLcd();
      for (int i = nivel + 1; i <= 10; i++)
      {
        lcd.setCursor(i, 1);
        lcd.print("-");
      }
    }
    
  }
  ledAmarelo.atualizar();
  ledVerde.atualizar();
  ledVermelho.atualizar();
  btnA.atualizar();
  btnB.atualizar();
}

void iniciarLcd()
{
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Nivel: 00%");
  lcd.setCursor(0, 1);
  lcd.print("[----------]");
}

void subirNivel()
{
  if (nivel == 10)
    return;

  nivel++;
}

void descerNivel()
{
  if (nivel == 0)
    return;

  nivel--;
}

void atualizarLcd()
{
  barraDeNivel = nivel * 10;
  lcd.setCursor(9,0);
  lcd.print("%  ");
  lcd.setCursor(7,0);
  lcd.print(nivel);
  if(barraDeNivel == 100)
  {
    lcd.setCursor(7,0);
    lcd.print("100%");
  }
}