#include "main.h"

const char *MSG[] = { "Fire Detected",
					  "Alcohol Consumed by the driver",
					};

volatile struct  {
	volatile int8u EyeBlink:1;
	volatile int8u Meas:1;
}Flags;

int main(void)
{
	init();
	
	while (TRUE) {
		
		if (Flags.Meas) {
			Flags.Meas = FALSE;
			
			if (Flags.EyeBlink) {
				Flags.EyeBlink = FALSE;
				lcdclrr(1);
				lcdws("Please Wake Up..");
				beep(5,100);
				dlyms(DISP_DLY);
				lcdclrr(1);
			}
			
			if (alcodet()) {
				lcdclrr(1);
				lcdws("Alcohol Detected");
				rlyon();
				beep(2,100);
				GSMsndmsg(OPhNum, MSG[1]);
				lcdclrr(1);
				lcdws("****BLOCKED*****");
				ledon();
				sleep();
				cli();
				for(;;);
			}
			
			if (firedet()) {
				lcdclrr(1);
				lcdws(" Fire Detected");
				beep(2,100);
				rlyon();
				MotClk();
				dlyms(2000);
				MotStop();
				GSMsndmsg(OPhNum, MSG[0]);
				lcdclrr(1);
				lcdws("****BLOCKED*****");
				ledon();
				sleep();
				cli();
				for(;;);
			}
		}
		sleep();
	}
	
	return 0;
}
static void init(void)
{
	buzinit();
	beep(2,100);
	ledinit();
	EyeBlinkInit();
	flagsinit();	
	lcdinit();
	uartinit();
	tmr2init();
	motorinit();
	FireSensInit();
	GSMinit();
	AlcoSensInit();
	rlyinit();
	disptitl();
	sei();
}
static void flagsinit(void)
{
	Flags.EyeBlink = FALSE;
	Flags.Meas = FALSE;
}
void EyeBlinkInit(void)
{
	EYEBLINK_SENS_DDR &= ~_BV(EYEBLINK_SENS_PIN);
	EYEBLINK_SENS_PORT |= _BV(EYEBLINK_SENS_PIN);
}
static void disptitl(void)
{
	lcdclr();
	lcdws(" SMART VEHICLE");
}
static void tmr2init(void)
{
	TCNT2   = 75;
	TIMSK   |= _BV(TOIE2);			//ENABLE OVERFLOW INTERRUPT
	TCCR2  |=  _BV(CS22) | _BV(CS21) | _BV(CS20); /* PRESCALAR BY 256 */
}

/* overflows at every 25msec */
ISR(TIMER2_OVF_vect)
{
	static int8u i,j,k,pulses;
	
	TCNT2 = 75;

	if (++i >= 200) i = 0;
	switch(i) {
		case 0: case 5: ledon(); break;
		case 1: case 6: ledoff(); break;
	}
	
	if(++k >= 20) {
		Flags.Meas = TRUE;
		k = 0;
	}
	
	if (++j >= 80) {
		j = 0;
		pulses = 0;
	}
	if (eyeblink()) {
		if(++pulses >= 4){
			Flags.EyeBlink = TRUE;
			pulses = j = 0;
		}
	}
}



