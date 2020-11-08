/*
 * ESP8266_WiFi_Domoticz.h
 *
 *  Created on: 30.12.2019
 *      Author: Pawel
 */

#ifndef ESP8266_WIFI_DOMOTICZ_H_
#define ESP8266_WIFI_DOMOTICZ_H_
int Pobierz_Status_Z_Domoticza(int IDX);
void Reset_ESP(void);
void Domoticz_Conection(void);
void WiFi_Conection(void);
void Wyslij_Dane_Do_Domoticza(int CEL,int IDX,int DANE);
void Zmiana_Wyjscia_Z_Domoticza(void);
#endif /* ESP8266_WIFI_DOMOTICZ_H_ */
