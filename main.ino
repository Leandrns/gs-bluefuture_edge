#include <DallasTemperature.h>
#include <OneWire.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define TFT_DC 9
#define TFT_CS 10

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

int potOxi = A0;
int potPh = A1;
int potTurbidez = A2;
int potSal = A3;
int potMicroPlastics = A4;
int dadosTemp = 2;

OneWire oneWire(dadosTemp);   // Protocolo OneWire
DallasTemperature sensors(&oneWire);    // Encaminha referências OneWire para o sensor

void setup() {
  Serial.begin(9600);
  sensors.begin();
  tft.begin();
  pinMode(potOxi, INPUT);
  pinMode(potPh, INPUT);
  pinMode(potTurbidez, INPUT);
  pinMode(potSal, INPUT);
  pinMode(dadosTemp, INPUT);
  pinMode(potMicroPlastics, INPUT);
}

void loop() {
  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(3);
  tft.setCursor(20, 5);
  tft.print("SEA CONNECT");
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  // Dados do Oxigênio
  int valorOxigenio = analogRead(potOxi);
  valorOxigenio = map (valorOxigenio, 0, 1023, 0, 10);
  tft.setCursor(5, 32);
  tft.print("Oxigenio: ");
  tft.setCursor(5, 52);
  tft.print(valorOxigenio);
  tft.print("mg/L");
  if (valorOxigenio >= 5 && valorOxigenio <= 7) {
    tft.setTextColor(ILI9341_GREEN);
    tft.println("    OK");
  }
  else {
    tft.setTextColor(ILI9341_RED);
    tft.println("    RUIM");
  }

  // Dados do pH
  tft.setTextColor(ILI9341_WHITE);
  int valorPh = analogRead(potPh);
  valorPh = map(valorPh, 0, 1023, 0, 14);
  tft.setCursor(5, 82);
  tft.print("pH: ");
  tft.setCursor(5, 102);
  tft.print(valorPh);
  if (valorPh >= 8 && valorPh <= 9) {
    tft.setTextColor(ILI9341_GREEN);
    tft.println("    OK");
  }
  else {
    tft.setTextColor(ILI9341_RED);
    tft.println("    RUIM");
  }

  // Dados da turbidez
  tft.setTextColor(ILI9341_WHITE);
  int valorTurbidez = analogRead(potTurbidez);
  valorTurbidez = map(valorTurbidez, 0, 1023, 0, 1000);
  tft.setCursor(5, 132);
  tft.print("Turbidez: ");
  tft.setCursor(5, 152);
  tft.print(valorTurbidez);
  tft.print("NTU");
  if (valorTurbidez <= 100) {
    tft.setTextColor(ILI9341_GREEN);
    tft.println("    OK");
  }
  else {
    tft.setTextColor(ILI9341_RED);
    tft.println("    RUIM");
  }

  // Dados da salinidade
  tft.setTextColor(ILI9341_WHITE);
  int valorSalinidade = analogRead(potSal);
  valorSalinidade = map (valorSalinidade, 0, 1023, 0, 100);
  tft.setCursor(5, 182);
  tft.print("Salinidade: ");
  tft.setCursor(5, 202);
  tft.print(valorSalinidade);
  tft.print("%");
  if (valorSalinidade >= 33 && valorSalinidade <= 37) {
    tft.setTextColor(ILI9341_GREEN);
    tft.println("    OK");
  }
  else {
    tft.setTextColor(ILI9341_RED);
    tft.println("    RUIM");
  }

  // Dados do Microplástico
  tft.setTextColor(ILI9341_WHITE);
  int valorMicroPlastics = analogRead(potMicroPlastics);
  valorMicroPlastics = map(valorMicroPlastics, 0, 1023, 0, 10000);
  tft.setCursor(5, 232);
  tft.print("Microplasticos: ");
  tft.setCursor(5, 252);
  tft.print(valorMicroPlastics);
  tft.print("g");
  if (valorMicroPlastics <= 500) {
    tft.setTextColor(ILI9341_GREEN);
    tft.println("    OK");
  }
  else {
    tft.setTextColor(ILI9341_RED);
    tft.println("    RUIM");
  }

  // Dados da temperatura
  tft.setTextColor(ILI9341_WHITE);
  sensors.requestTemperatures();    // Envia o comando para leitura da temperatura
  int valorTemp = sensors.getTempCByIndex(0);
  tft.setCursor(5, 282);
  tft.print("Temperatura: ");
  tft.setCursor(5, 302);
  tft.print(valorTemp);
  tft.print((char)9);
  tft.print("C");
  if (valorTemp >= 25 && valorTemp <= 27) {
    tft.setTextColor(ILI9341_GREEN);
    tft.println("    OK");
  }
  else {
    tft.setTextColor(ILI9341_RED);
    tft.println("    RUIM");
  }
  delay(2000);
  tft.fillScreen(ILI9341_BLACK);
}
