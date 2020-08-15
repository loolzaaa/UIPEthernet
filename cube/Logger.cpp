#include <cube/Logger.h>


Logger::Logger() {
}

void Logger::setUartHandle(UART_HandleTypeDef *uartHandle) {
	Logger::uart = *uartHandle;
}

HAL_StatusTypeDef Logger::uart_send_str(const char* x) {
	sprintf(uartString, "%s", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_strln(const char* x) {
	sprintf(uartString, "%s\r\n", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_dec(int x) {
	sprintf(uartString, "%d", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_decln(int x) {
	sprintf(uartString, "%d\r\n", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_hex(int x) {
	sprintf(uartString, "%X", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_hexln(int x) {
	sprintf(uartString, "%X\r\n", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_bin(uint8_t x) {
	sprintf(uartString, "%B", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_binln(uint8_t x) {
	sprintf(uartString, "%B\r\n", x);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

HAL_StatusTypeDef Logger::uart_send_buf_len(uint8_t *buf, size_t len) {
	sprintf(uartString, "%.*s", len, (char*)buf);
	return HAL_UART_Transmit(&uart, (uint8_t*)uartString, strlen(uartString), 32);
}

UART_HandleTypeDef Logger::uart;

Logger logger;
