/*
 * Zmienne.h
 *
 *  Created on: 30.12.2019
 *      Author: Pawel
 */

#ifndef ZMIENNE_H_
#define ZMIENNE_H_

#include "main.h"




//unsigned char ssid[]     	  = {"ASUS"};                  // Nazwa sieci
//unsigned char password[] 	  = {"Hubabubaz41220"};    // Haslo do sieci
//unsigned char Ip_Domoticz[]   = {"192.168.1.100"};
//unsigned char Port_Domoticz[] = {"9090"};

uint8_t OUT_1_STATUS,
		OUT_2_STATUS,
		OUT_3_STATUS;



char 				buforRxUART[25];
volatile uint8_t 	odebranoDane;

uint8_t 			WiFi_Conection_Ok,
					Domoticz_Conection_Ok;



volatile uint8_t 	Flaga_Odczyt_DS18B20,
					Flaga_Odczyt_ADC,
					Flaga_Send_Domoticz;
int Temperatura[6];
int ROM_ADD[8];
volatile uint16_t 	TIM_uSekundy,
					TIM_mSekundy,
					TIM_Sekundy,
					TIM_Odczyt_DS18B20,
					TIM_Odczyt_ADC,
					TIM_Send_Domoticz;

#endif /* ZMIENNE_H_ */
