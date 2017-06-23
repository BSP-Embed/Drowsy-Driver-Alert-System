#ifndef MAIN_H
#define MAIN_H

#include "includes.h"

#define EYEBLINK_SENS_DDR	DDRD
#define EYEBLINK_SENS_PORT	PORTD
#define EYEBLINK_SENS_PPIN	PIND
#define EYEBLINK_SENS_PIN	PD4

//DEFINE MACROS
#define eyeblink()			(EYEBLINK_SENS_PPIN & _BV(EYEBLINK_SENS_PIN))

//FUNCTION PROTOTYPES
static	void	init		(void);
static	void 	disptitl 	(void);
static	void 	tmr2init	(void);
static	void	flagsinit	(void);
		void	EyeBlinkInit(void);
		
		
#endif
