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
  tft.println("mg/L");

  // Dados do pH
  int valorPh = analogRead(potPh);
  valorPh = map(valorPh, 0, 1023, 0, 14);
  tft.setCursor(5, 82);
  tft.print("pH: ");
  tft.setCursor(5, 102);
  tft.println(valorPh);

  // Dados da turbidez
  int valorTurbidez = analogRead(potTurbidez);
  valorTurbidez = map(valorTurbidez, 0, 1023, 0, 1000);
  tft.setCursor(5, 132);
  tft.print("Turbidez: ");
  tft.setCursor(5, 152);
  tft.print(valorTurbidez);
  tft.println("NTU");

  // Dados da salinidade
  int valorSalinidade = analogRead(potSal);
  valorSalinidade = map (valorSalinidade, 0, 1023, 0, 100);
  tft.setCursor(5, 182);
  tft.print("Salinidade: ");
  tft.setCursor(5, 202);
  tft.print(valorSalinidade);
  tft.println("%");

  // Dados do Microplástico
  int valorMicroPlastics = analogRead(potMicroPlastics);
  valorMicroPlastics = map(valorMicroPlastics, 0, 1023, 0, 10000);
  tft.setCursor(5, 232);
  tft.print("Microplasticos: ");
  tft.setCursor(5, 252);
  tft.print(valorMicroPlastics);
  tft.println("g");

  // Dados da temperatura
  sensors.requestTemperatures();    // Envia o comando para leitura da temperatura
  int valorTemp = sensors.getTempCByIndex(0);
  tft.setCursor(5, 282);
  tft.print("Temperatura: ");
  tft.setCursor(5, 302);
  tft.print(valorTemp);
  tft.print((char)9);
  tft.println("C");
  delay(2000);
  tft.fillScreen(ILI9341_BLACK);
}
