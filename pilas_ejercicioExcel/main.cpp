/*
UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
NOMBRES					: TNTE ARCOS JHON, TNTE ESPIN ROBERTO
FECHA DE CREACION		: 17 DIC 2017
FECHA DE MODIFICACION	: 18 DIC 2017
DOCENTE					: ING FERNANDO SOLIS
CARRERA					: INGENIERIA EN SISTEMAS
DESCRIPCION				: Ejercicio de pila implementacion del push y pop,
						  implementacion de atencion de un banco con ejercicio en excel.
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "listaSimple.h"

void Membrete() {
	system("cls");
	printf("					UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n\n");
	printf("NOMBRE					: TNTE ARCOS JHON, TNTE ESPIN ROBERTO\n");
	printf("FECHA DE CREACION			: 17 DIC 2017\n");
	printf("FECHA DE MODIFICACION			: 18 DIC 2017\n");
	printf("DOCENTE					: ING FERNANDO SOLIS\n");
	printf("CARRERA					: INGENIERIA EN SISTEMAS\n");
	printf("DESCRIPCION				: Ejercicio de pila implementacion del push y pop,\n");
	printf("					  implementacion de atencion de un banco con ejercicio en excel.\n");
	getchar();
}

void valSalida(char *salida)
{
	int  i = 0, c=0;
	while ((c = _getch() != 13))
	{
		if (((c <= 78) && (c >= 83)) || ((c <= 110) && (c >= 115)))
		{
			*(salida + i) = c;
			printf("%c", c);
			i++;
		}
		*(salida + i) = '\0';
	}
}

int main()
{
	Membrete();
	listaSimple *user = new listaSimple();
	listaSimple *auxNodo = NULL;
	char ex = 'N',aux[10]="F";
	srand(time_t(NULL));
	int numUser = 0, llegada, espera, desCajero, servicio, salida, entreLlegada;
	printf("\nPresione 'S' para ingresar un nuevo usuario o cualquier otra para salir\n");
	gets_s(aux);
	while ((strcmp(aux, "S") == 0) || (strcmp(aux, "s") == 0)) {
		llegada = 0; espera = 0; desCajero = 0; servicio = 0; salida = 0; entreLlegada = 0;
		if (numUser == 0)
		{
			llegada = rand() % 25;
			espera = 0;
			desCajero = 0;
			servicio = rand() % 16;
			salida = espera + servicio;
			entreLlegada = llegada;
			user = user[numUser].push(user, numUser, llegada, espera, desCajero, servicio, salida, entreLlegada);
			numUser++;
		}
		else
		{
			llegada = auxNodo->getLlegada();
			llegada += 1 + rand() % 25;
			if (auxNodo->getSalida()>llegada)
			{
				espera = auxNodo->getSalida() - llegada;
			}
			if (llegada > auxNodo->getSalida())
			{
				desCajero = llegada - auxNodo->getSalida();
			}
			servicio = 1 + rand() % 16;
			salida = llegada + espera + servicio;
			entreLlegada = llegada - auxNodo->getLlegada();
			user = user->push(user, numUser, llegada, espera, desCajero, servicio, salida, entreLlegada);
			numUser++;
		}
		auxNodo = user;
		printf("Se ha ingresado correctamente el siguiente usuario:\n");
		printf("Cliente\t\tLlegada\t\tEspera\t\tDescanso\tServicio\tSalida\t\tEntre\n");
		printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", numUser,
			llegada,
			espera,
			desCajero,
			servicio,
			salida,
			entreLlegada);
		
		printf("\nPresione 'S' para ingresar un nuevo usuario o cualquier otra para salir\n");
		gets_s(aux);
	}
	if (numUser==0) {
		printf("No se han ingresado usuarios\n");
	}
	else {
		printf("Numero total de usuarios: %d\n", numUser);
		printf("Cliente\t\tLlegada\t\tEspera\t\tDescanso\tServicio\tSalida\t\tEntre\n");
		while (numUser >= 0) {
			auxNodo->imprimirLista(user, numUser);
			numUser--;
		}
	}
	system("pause");
}