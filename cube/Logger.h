#ifndef UIPETHERNET_CUBE_LOGGER_H_
#define UIPETHERNET_CUBE_LOGGER_H_

#include <string.h>
#include <stdio.h>

#include "stm32f1xx_hal.h"

class Logger {
private:
	char uartString[256];
	static UART_HandleTypeDef uart;
public:
	Logger();
	static void setUartHandle(UART_HandleTypeDef *uartHandle);
	HAL_StatusTypeDef uart_send_str(const char* x);
	HAL_StatusTypeDef uart_send_strln(const char* x);
	HAL_StatusTypeDef uart_send_dec(int x);
	HAL_StatusTypeDef uart_send_decln(int x);
	HAL_StatusTypeDef uart_send_hex(int x);
	HAL_StatusTypeDef uart_send_hexln(int x);
	HAL_StatusTypeDef uart_send_bin(uint8_t x);
	HAL_StatusTypeDef uart_send_binln(uint8_t);
	HAL_StatusTypeDef uart_send_buf_len(uint8_t *buf, size_t len);
};

extern Logger logger;

#endif /* UIPETHERNET_CUBE_LOGGER_H_ */
