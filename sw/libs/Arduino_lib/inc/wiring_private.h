/*
  wiring_private.h - Internal header file.
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2005-2006 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA

  $Id: wiring.h 239 2007-01-12 17:58:39Z mellis $
*/

#ifndef WiringPrivate_h
#define WiringPrivate_h


#include <stdio.h>
//#include <stdarg.h>

#include "Arduino.h"
#include "int.h"
#include "timer.h"
#include "utils.h"
#include "gpio.h"


#define PWM_FREQ 200	//PWM frequency
#define	PWM_PRE 3	//PWM prescision if 0 precision will be 256, if 1 precision will be 255/2 and so on.
#define PWM_MAX_COUNT ((256 >> PWM_PRE)-1)	//maximum number ISR will count then overflow to zero

typedef struct{
uint8_t PWM_enabled;
uint8_t PWM_value;
}PWM_status;
extern PWM_status PWM_status_arr[NUM_DIGITAL_PINS];
extern uint8_t PWM_global_en;
extern uint8_t PWM_count;



#ifdef __cplusplus
extern "C"{
#endif


#define cbi(sfr, bit) ((sfr) &= ~(bit))
#define sbi(sfr, bit) ((sfr) |= (bit))
#define bit_is_clear(sfr,bit) \
	(!((sfr) & (bit))) 
#define bit_is_set(sfr,bit) \
	((sfr) & (bit)) 

// ###check later###
//unsigned int countPulseASM(volatile uint8_t *port, uint8_t bit, uint8_t stateMask, unsigned int maxloops);

// we have all GPIOs with interrupts, ###check later###
/*
#define EXTERNAL_INT_0 0
#define EXTERNAL_INT_1 1
#define EXTERNAL_INT_2 2
#define EXTERNAL_INT_3 3
#define EXTERNAL_INT_4 4
#define EXTERNAL_INT_5 5
#define EXTERNAL_INT_6 6
#define EXTERNAL_INT_7 7
*/

//these are AVR definitions for AVR varient ICs, ###check later###
/*
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__) || defined(__AVR_ATmega128RFA1__) || defined(__AVR_ATmega256RFR2__)
#define EXTERNAL_NUM_INTERRUPTS 8
#elif defined(__AVR_ATmega1284__) || defined(__AVR_ATmega1284P__) || defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)
#define EXTERNAL_NUM_INTERRUPTS 3
#elif defined(__AVR_ATmega32U4__)
#define EXTERNAL_NUM_INTERRUPTS 5
#else
#define EXTERNAL_NUM_INTERRUPTS 2
#endif
*/
////////////////////////end///////////////////////

typedef void (*voidFuncPtr)(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif
