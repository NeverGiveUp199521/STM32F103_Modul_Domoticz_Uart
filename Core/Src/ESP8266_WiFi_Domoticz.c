/*
 * ESP8266_WiFi_Domoticz.c
 *
 *  Created on: 30.12.2019
 *      Author: Pawel
 */
#include "ESP8266_WiFi_Domoticz.h"
#include "Zmienne.h"
#include "main.h"

const unsigned char ssid[]     	  	= {"FunBox2-361E"};                  // Nazwa sieci
const unsigned char password[] 	  	= {"1CD1A5A19AD79CE35F7313943C"};    // Haslo do sieci
const unsigned char Ip_Domoticz[]   = {"192.168.1.19"};                  // Nazwa sieci
const unsigned char Port_Domoticz[] = {"8080"};    // Haslo do sieci

void Reset_ESP(void){
	HAL_GPIO_WritePin(RESET_ESP_GPIO_Port,RESET_ESP_Pin,GPIO_PIN_RESET);
	HAL_Delay(10);
	HAL_GPIO_WritePin(RESET_ESP_GPIO_Port,RESET_ESP_Pin,GPIO_PIN_SET);
	HAL_Delay(10);
};

void WiFi_Conection(void){
	if(odebranoDane == SET){
	if(strcmp(buforRxUART, "WIFI CONECTION") == 0)
	{
		odebranoDane = RESET;
		WiFi_Conection_Ok = SET;

	}
	if(strcmp(buforRxUART, "NAZWA") == 0)
	{

		  odebranoDane = RESET;
		  		  }
	if(strcmp(buforRxUART, "HASLO")  == 0)
	{

		 	odebranoDane = RESET;
	}

	}

}




























int Pobierz_Status_Z_Domoticza(int IDX){
	Wyslij_Dane_Do_Domoticza(3,IDX,0);
	if(odebranoDane == 1){
	if(strcmp(buforRxUART, "On") == 0)
	{
	return 1;
	odebranoDane = 0;
	}
	if(strcmp(buforRxUART, "Off") == 0)
	{
	return 0;
	odebranoDane = 0;
	}
	}

}

void Zmiana_Wyjscia_Z_Domoticza(void){
	if(odebranoDane == 1){
	if(strcmp(buforRxUART, "OUTPUT1_ON") == 0)
	{
	OUT_1_STATUS = 1;
	Zerowanie();
	odebranoDane = 0;
	}
	if(strcmp(buforRxUART, "OUTPUT1_OFF") == 0)
	{
		OUT_1_STATUS = 0;
		LED_OFF();
	odebranoDane = 0;
	}


	if(strcmp(buforRxUART, "JASNOSC 0") == 0)
		{
		PCA9685_SetPwm(7,0,0);
		odebranoDane = 0;
		}
	if(strcmp(buforRxUART, "JASNOSC 25") == 0)
			{
			PCA9685_SetPwm(7,0,1024);
			odebranoDane = 0;
			}
	if(strcmp(buforRxUART, "JASNOSC 50") == 0)
			{
			PCA9685_SetPwm(7,0,2048);
			odebranoDane = 0;
			}
	if(strcmp(buforRxUART, "JASNOSC 75") == 0)
			{
			PCA9685_SetPwm(7,0,3072);
			odebranoDane = 0;
			}
	if(strcmp(buforRxUART, "JASNOSC 100") == 0)
			{
			PCA9685_SetPwm(7,0,4090);
			odebranoDane = 0;
			}




	}

}



void Wyslij_Dane_Do_Domoticza(int CEL,int IDX,int DANE){

printf("%d,ADDRES:%d,DANE:%d\n",CEL,IDX,DANE);

}
void Domoticz_Conection(void){
	if(odebranoDane == 1){
	if(strcmp(buforRxUART, "ADRES IP DOMOTICZ") == 0)
	{
	//HAL_UART_Transmit_IT(&huart1, Ip_Domoticz, strlen(Ip_Domoticz));
		  odebranoDane = 0;
		  		  }
	if(strcmp(buforRxUART, "PORT DOMOTICZ")  == 0)
	{
	//HAL_UART_Transmit_IT(&huart1, Port_Domoticz, strlen(Port_Domoticz));
		 odebranoDane = 0;
	}
	if(strcmp(buforRxUART, "DOMOTICZ CONECTION") == 0)
		{
			odebranoDane = 0;
			Domoticz_Conection_Ok = 1;
	}

	}

}


