// Grupo 5
//Thiago Vilani
//Jonathan Ehrhorn
//Juam Pablo Juarez

#include <LiquidCrystal.h>

#define RS A0
#define ENABLE A1
#define D4 A2
#define D5 A3
#define D6 A4
#define D7 3
#define P1 7
#define P2 6
#define P3 5
#define P4 4
#define VERDE 2
#define AZUL 9
#define ROJO 8
#define SENSOR_TEMP A5
#define TEMP_COLUMNAS 16
#define TEMP_FILAS 2

LiquidCrystal lcd(RS, ENABLE, D4, D5, D6, D7);

void setup()
{
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(ROJO, OUTPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(P4, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

String estadoUno = "Sin hacer";
String estadoDos = "Hecha";
String estadoTres = "Quemada";
String pulsadorUno = "1";
String pulsadorDos = "2";
String pulsadorTres = "3";
String pulsadorCuatro = "4";

int temperatura;

void loop()
{
  int pUno;
  int pDos;
  int pTres;
  int pCuatro;
  
  temperatura = analogRead(SENSOR_TEMP);
  temperatura = map(temperatura, 0, 1023, -50, 450);
  
  Serial.println(temperatura);
  
  pUno=digitalRead(P1);
  pDos=digitalRead(P2);
  pTres=digitalRead(P3);
  pCuatro=digitalRead(P4);
  
  if(pUno==HIGH)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(pulsadorUno);
    if(temperatura<20)
    {
      lcd.setCursor(0, 1);
      lcd.print(estadoUno);
    }
    else
    {
      if(temperatura<80)
      {
        lcd.setCursor(0, 1);
        lcd.print(estadoDos);
      }
      else
      {
        lcd.setCursor(0, 1);
        lcd.print(estadoTres);
      }
    }
  }
  else
  {
    if(pDos==HIGH)
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(pulsadorDos);
      if(temperatura<20)
      {
        lcd.setCursor(0, 1);
        lcd.print(estadoUno);
      }
      else
      {
        if(temperatura<80)
        {
          lcd.setCursor(0, 1);
          lcd.print(estadoDos);
        }
        else
        {
          lcd.setCursor(0, 1);
          lcd.print(estadoTres);
        }
      }
    }
    else
    {
      if(pTres==HIGH)
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(pulsadorTres);
        if(temperatura<20)
        {
          lcd.setCursor(0, 1);
          lcd.print(estadoUno);
        }
        else
        {
          if(temperatura<80)
          {
        lcd.setCursor(0, 1);
        lcd.print(estadoDos);
      }
      else
      {
        lcd.setCursor(0, 1);
        lcd.print(estadoTres);
      }
    }
      }
      else
      {
        if(pCuatro==HIGH)
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print(pulsadorCuatro);
          if(temperatura<20)
    {
      lcd.setCursor(0, 1);
      lcd.print(estadoUno);
    }
    else
    {
      if(temperatura<80)
      {
        lcd.setCursor(0, 1);
        lcd.print(estadoDos);
      }
      else
      {
        lcd.setCursor(0, 1);
        lcd.print(estadoTres);
      }
    }
        }
      }
    }
  }
}