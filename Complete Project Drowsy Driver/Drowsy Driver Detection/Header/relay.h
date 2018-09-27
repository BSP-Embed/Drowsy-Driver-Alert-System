#ifndef _RELAY_H
#define _RELAY_H

#include "includes.h"

#define rlyon()		RLY_PORT |= _BV(RLY_PIN)
#define rlyoff()	RLY_PORT &= ~_BV(RLY_PIN) 

void	rlyinit	(void);


#endif
