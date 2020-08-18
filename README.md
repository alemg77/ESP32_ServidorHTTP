Servidor HTTP para el modulo ESP32

Toda pedidos HTTP y los envia por la UART

Espera un segundo como maximo a tener una respuesta por la UART

Si la obtiene la usa para responde el pedido HTTP.

Si no tiene respuesta por la UART, responde un mensaje fijo por HTTP.
