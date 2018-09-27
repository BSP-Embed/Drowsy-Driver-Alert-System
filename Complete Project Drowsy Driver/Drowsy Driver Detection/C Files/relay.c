#include "relay.h"

void rlyinit(void) {
	RLY_DDR		|= _BV(RLY_PIN);
	RLY_PORT 	&= ~_BV(RLY_PIN);
}
