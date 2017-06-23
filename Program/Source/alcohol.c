#include "alcohol.h"

void AlcoSensInit(void)
{
	ALCO_SENS_DDR &= ~_BV(ALCO_SENS_PIN);
	ALCO_SENS_PORT |= _BV(ALCO_SENS_PIN);
	
	lcdclrr(1);
	lcdws("Sensor Init:");
	while ((ALCO_SENS_PPIN & _BV(ALCO_SENS_PIN)) == 0);
	lcdws("Ok");
	dlyms(DISP_DLY);
	
}