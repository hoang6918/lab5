/*
 * uart.c
 *
 *  Created on: Dec 1, 2022
 *      Author: Admin
 */
#include <uart_fsm.h>

UART_HandleTypeDef huart2;
ADC_HandleTypeDef hadc1;

int STATE = 0;
int ADC_value;

char str[50];

void UART_FSM(){
	switch(STATE){
	case 0:
		if(FINISH == 1){
			FINISH = 0;
			if(strcmp(line_of_command,"RST") == 0 || strcmp(line_of_command,"rst") == 0){
				ADC_value = HAL_ADC_GetValue(&hadc1);
				STATE = 1;
				setTimer1(3000);
			}
			if(strcmp(line_of_command,"RST") != 0 && strcmp(line_of_command,"rst") != 0){
				STATE = 3;
			}
		}
		break;
	case 1:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n!ADC = %d#", ADC_value),1000);
		STATE = 2;
		break;
	case 3:
		HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\nWrong begin command", 0),1000);
		STATE = 0;
		break;
	case 2:
		if(FINISH == 1){
			FINISH = 0;
			if(strcmp(line_of_command,"OK") != 0 && strcmp(line_of_command,"ok") != 0){
					HAL_UART_Transmit(&huart2, (void*)str, sprintf(str, "\r\n Wrong end command", 0),1000);
				}
				if(strcmp(line_of_command,"OK") == 0 || strcmp(line_of_command,"ok") == 0){
					STATE = 0;
					line_of_command[0] = '\0';
					setTimer1(3000);
				}

		}
		if(timer1_flag==1){
			STATE = 1;
			setTimer1(3000);
		}
		break;
	default:
		break;
	}
}
