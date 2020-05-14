#include <Arduino.h>

#define BUFFER_RX_SERIAL2_SIZE      30

#define ENCABEZADO_CONTROL_REMOTO   82          // R
#define ENCABEZADO_ESTADO           69         // E
#define ENCABEZADO_MENSASE          77          // M

void Task_ComunicacionAIO();
void Recepcion_control_remoto ( uint16_t codigo, uint8_t canal );
