/*
 * uart.h
 *
 *  Created on: Dec 1, 2022
 *      Author: Admin
 */

#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_
#include "main.h"
#include "timer.h"
#include "command_fsm.h"


extern uint8_t buffer_flag;
extern uint8_t temp ;

extern int ADC_value;

void UART_FSM();

#endif /* INC_UART_FSM_H_ */
