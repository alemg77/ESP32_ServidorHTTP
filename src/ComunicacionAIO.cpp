#include <Arduino.h>
#include <Hardware.h>
#include <ComunicacionAIO.h>

unsigned int contador_buffer_rx_serial2 = 0;
unsigned int overflow_buffer_rx_serial2 = 0;
char buffer_rx_serial2[BUFFER_RX_SERIAL2_SIZE];





void Leer_paquete_AIO(char *vector_)
{
  long codigoControl = 0;
  int16_t i;

  //uint8_t bytes = strlen(vector_);
  switch (vector_[0])
  {
  case ENCABEZADO_CONTROL_REMOTO:
    codigoControl = atol(&vector_[1]);
    for ( i = 1 ; vector_[i] != 95 ; i++ ) {
      if ( i >= BUFFER_RX_SERIAL2_SIZE ){
        Recepcion_control_remoto(codigoControl,0);
      }
    }
    Recepcion_control_remoto(codigoControl, atol(&vector_[i+1]));
    break;

  case ENCABEZADO_ESTADO:
    Serial.println("Llego un paquete de Estado");
    break;

  default:
    Serial.printf("Encabezado: %d\n", vector_[0]);
    break;
  }
}

unsigned long clock_;

void Task_ComunicacionAIO()
{

  if ((millis() - clock_) > 10000)
  {
    clock_ = millis();
    Serial2.print("Soy el ESP32\n\r");
  }

  if (Serial2.available())
  {
    char inChar = (char)Serial2.read();
    if (inChar == 13)
    {
      TOGLE_LED_AZUL;
      buffer_rx_serial2[contador_buffer_rx_serial2] = 0;
      Leer_paquete_AIO(buffer_rx_serial2);
      contador_buffer_rx_serial2 = 0;
    }
    else
    {
      buffer_rx_serial2[contador_buffer_rx_serial2] = inChar;
      contador_buffer_rx_serial2++;
      if (contador_buffer_rx_serial2 >= BUFFER_RX_SERIAL2_SIZE)
      {
        Serial.println("ERROR: Se lleno el buffer de recepcion Serial2");
        Serial.print("RX Serial2: ");
        Serial.println(buffer_rx_serial2);
        overflow_buffer_rx_serial2 = 1;
        contador_buffer_rx_serial2 = 0;
      }
    }
  }
}
