#ifndef _APP_H
#define _APP_H

/* Main settings */

/*comment below line for release*/
//#define TESTING

#ifdef TESTING
	#define OPhNum	 "PH_NUMBER"
#else
	#define OPhNum	 "PH_NUMBER"
#endif

#define EEPROM_DISPLAY				0

/******** MAIN CONFIGURATION ENDS ****************/

/* LCD CONFIGURATION */
#define LCD_DDR           	   		DDRB 
#define LCD_DATA_PORT          		PORTB
#define LCD_ENABLE_PIN        		PB3 
#define LCD_REGISTER_SELECT_PIN     PB2
#define DISPLAY_INIT				1
#define LCD_NSCRL					3
#define FLOAT_T0_STRING				1
#define DECIMAL_PRECISION			10

/******** LCD CONFIGURATION ENDS ****************/

/* BUZZER: CONFIGURATION */
#define	BUZ_DDR						DDRC
#define	BUZ_PORT					PORTC
#define	BUZ_PIN						PC1
#define OFF_TIME					100
/******** BUZZER CONFIGURATION ENDS ****************/

/* LED: CONFIGURATION */

#define	LED_DDR			DDRC
#define	LED_PORT		PORTC
#define	LED_PIN			PC0

#define OFF_TIME		100
/******** LED CONFIGURATION ENDS ****************/

/* GSM: CONFIGURATION */

#define MSG_START					""
#define MSG_END						". Automated SMS By: DDD&AS."

/******** ADC CONFIGURATION ENDS ****************/
#define REF_VOL_256

/******** GSM CONFIGURATION ENDS ****************/

/******** EEPROM CONFIGURATION ****************/
#define EEPROM_DISPLAY		0

/******** RFID  CONFIGURATION ****************/
//#define DISPLAY_TAGNUMBER	1

/******** MOTOR CONFIGURATION   ****************/
#define MOT_PORT			PORTC
#define MOT_DDR				DDRC
#define MOT1_AN				PC3
#define MOT1_CA				PC4
/******** MOTOR CONFIGURATION ENDS  ****************/

/******* SERVO CONFIGURATION ********************/
#define SERVO_DDR			DDRD
#define SERVO_PORT			PORTD
#define SERVO1				PD5
/******** SERVO CONFIGURATION ENDS **************/

/******* ULTRASONIC SENSOR CONFIGURATION ********/
#define	ULTSEN_DDR			DDRB
#define	ULTSEN_PORT			PORTB
#define	ULTSEN_PIN			PINB
#define ECHO_PIN			PB0
#define TRIG_PIN			PB1
/****** ULTRASONIC CONFIGURATION ENDS **********/

/****** HX711 24-BIT ADC CONFIGURATIONS *******/
#define HX711_DDR			DDRD
#define HX711_PORT			PORTD
#define HX711_INPIN			PIND
#define HX711_CLK_PIN		PD3
#define HX711_DIN_PIN		PD2
/****** HX711 24-BIT ADC CONFIGURATIONS ENDS*******/

/******* ALCOHOL SENSOR CONFIGURATION ***********/
#define ALCO_SENS_DDR		DDRD
#define ALCO_SENS_PORT		PORTD
#define ALCO_SENS_PPIN		PIND
#define ALCO_SENS_PIN		PD3
/******* ALCOHOL SENSOR CONFIGURATION ENDS *****/

/******** FIRE SENSOR CONFIGURATION ******/
#define FIRE_SENS_DDR		DDRD
#define FIRE_SENS_PORT		PORTD
#define FIRE_SENS_PPIN		PIND
#define FIRE_SENS_PIN		PD2
/******** FIRE SENSOR CONFIGURATION END ****/

/******** RELAY PINS CONFIGURATION    *****/
#define RLY_DDR				DDRC
#define RLY_PORT			PORTC
#define RLY_PIN				PC2
/******* RELAY PINS CONFIGURATION ENDS ****/

#endif
