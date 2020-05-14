#include <Arduino.h>
#include "Hardware.h"
#include "ComunicacionAIO.h"

void Recepcion_control_remoto ( uint16_t codigo, uint8_t canal ){
  // TODO: Cambiar esta funcion para que haga lo que tenga que hacer cuando llega un control remto
  Serial.print("LLego un paquete de control remoto, ");
  Serial.printf("Codigo %d, canal %d \n", codigo, canal);
}


void setup()
{
  Serial.begin(115200);
  Serial2.begin(48000);

  pinMode(PIN_LED_AZUL, OUTPUT);
  pinMode(PIN_LED_ROJO, OUTPUT);
  pinMode(PIN_LED_VERDE, OUTPUT);

  APAGAR_LED_AZUL;
  APAGAR_LED_VERDE;

  PRENDER_LED_ROJO;
  delay(650);
  APAGAR_LED_ROJO;

  PRENDER_LED_VERDE;
  delay(650);
  APAGAR_LED_VERDE;

  PRENDER_LED_AZUL;
  delay(650);
  APAGAR_LED_AZUL;

  Serial.println("Inicio del Soft EnsayoAtomESP32");
}

void loop() {
    Task_ComunicacionAIO();
}
