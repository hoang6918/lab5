/*
 * command.h
 *
 *  Created on: Dec 1, 2022
 *      Author: Admin
 */

#ifndef INC_COMMAND_FSM_H_
#define INC_COMMAND_FSM_H_

#include "main.h"
#include "timer.h"


extern  char INDEX;
extern  char FINISH;
extern char line_of_command[50];

void command_parser();
#endif /* INC_COMMAND_FSM_H_ */
