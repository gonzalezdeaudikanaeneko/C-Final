/*
 * main.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */

#include "Cuenta.h"
#include "Banco.h"
#include "Usuario.h"
#include "Trabajador.h"
#include "Director.h"
#include "Funciones.h"
#include "sqlite3.h"
#include "AdministradorCuentas.h"

#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include <list>
#include <sstream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <list>
#include <typeinfo>

using namespace std;

int main(void) {
	char funcMenu, menuT, menuA, menuD, menuC;
	bool repetir;
	char nombre[20], nombre1[20], nombre2[20], nombre3[20], nombre4[20];
	string statement;
	string result;
	char *csql3;
	const char *csql2;

	string Result1, Result;			//string which will contain the result

	stringstream convert1, convert; // stringstream used for the conversion
	Trabajador t;
	Director d;
	Banco b;
	list<Cuenta*>* CB;
	CB = b.LeerFichero(); //TODO
	int modificacion, modificacion1;
	do {
		repetir = true;
		funcMenu = mostrarMenu();
		switch (funcMenu) {
		case '1': {
			menuT = mostrarMenuTrabajador();
			switch (menuT) {
			case '1': {
				menuD = mostrarMenuDirector();
				if (menuD == '1') {

					printf("Introduce la cantidad del prestamo: \n");
					fflush(stdout);
					scanf("%s", nombre2);
					fflush(stdin);
					printf("%s", nombre2);

					printf("Introduce la CUENTA: \n");
					fflush(stdout);
					scanf("%s", nombre3);
					fflush(stdin);
					printf("%s", nombre3);

					statement = "UPDATE CUENTA SET SUELDO = ";
					statement.append(nombre2);
					statement.append(
							"+(SELECT SUELDO FROM CUENTA WHERE N_IDENT = ");
					statement.append(nombre3);
					statement.append(") WHERE N_IDENT = ");
					statement.append(nombre3);
					statement.append(";");
					ejecutarComando(&statement[0u]);


					string statement2;
					statement = "UPDATE CUENTA SET DEUDA = ";
					statement.append(nombre2);
					statement.append("*");
					statement.append(nombre2);
					statement.append("/10 +(SELECT DEUDA FROM CUENTA WHERE N_IDENT = ");
					statement.append(nombre3);
					statement.append(") WHERE N_IDENT = ");
					statement.append(nombre3);
					statement.append(";");
					ejecutarComando(&statement[0u]);

				}
			}
				break;
			case '2': {
				menuA = mostrarMenuAdmin();
				switch (menuA) {
				case '1': { //Añadir cuenta
					almacenarCuentaBD(nuevaCuenta());
				}
					break;
				case '2': { //Eliminar cuenta
					printf("Introduce N_IDENT de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nombre);
					fflush(stdin);
					printf("%s", nombre);
					statement = "DELETE * from CUENTAS where N_IDENT like '";
					statement.append(nombre);
					statement.append("';");
					csql2 = statement.c_str();
					csql3 = (char*) csql2;
					ejecutarComando(csql3);
					printf("\n");
				}
					break;
				case '3': //mover saldo
					//b.transaccion(CB, 123, 123, 350);
					break;
				case '4':						//MOstra 1
					printf("Introduce N_IDENT de la Cuenta: \n");
					fflush(stdout);
					scanf("%s", nombre);
					fflush(stdin);
					printf("%s", nombre);
					statement = "SELECT * from CUENTAS where N_IDENT like '";
					statement.append(nombre);
					statement.append("';");
					csql2 = statement.c_str();
					csql3 = (char*) csql2;
					ejecutarComando(csql3);
					printf("\n");
					break;
				case '5':						//Mostrar todas
					statement = "SELECT * from XML;";
					csql2 = statement.c_str();
					csql3 = (char*) csql2;
					ejecutarComando(csql3);
					break;
				case '6':						//salir
					break;
				default:
					break;
				}
			}
				break;
			case '3': {
				printf("Saliendo ...");
			}
				break;
			default:
				printf("Opcion incorrecta!\n\n");
				break;
			}
		}
			break;
		case '2': {
			menuC = mostrarMenuCliente();
			switch (menuC) {
			case '1':
				//ingresar dinero;
				//ingresarDinero(122, get(CB, 2));
				cout << "\nIntroduzca el numero de cuenta : ";
				cin >> modificacion;

				convert1 << modificacion1; //add the value of Number to the characters in the stream

				Result1 = convert1.str(); //set Result to the content of the stream

				cout << "\nIntroduzca el importe a introducir : ";
				cin >> modificacion;

				convert << modificacion; //add the value of Number to the characters in the stream

				Result = convert.str(); //set Result to the content of the stream

				statement = "UPDATE CUENTA SET SUELDO = '";
				statement.append(Result);
				statement.append("' WHERE N_IDENT = ");
				statement.append(Result1);
				statement.append(";");
				//ejecutarComandoBD(&statement[0u]);
				break;
			case '2':
				//sacar dinero;
				cout << "\nIntroduzca el numero de cuenta : ";
				cin >> modificacion;

				convert1 << modificacion1; //add the value of Number to the characters in the stream

				Result1 = convert1.str(); //set Result to the content of the stream

				cout << "\nIntroduzca el importe a sacar : ";
				cin >> modificacion;

				convert << modificacion; //add the value of Number to the characters in the stream

				Result = convert.str(); //set Result to the content of the stream

				statement = "UPDATE CUENTA SET SUELDO = '";
				statement.append(Result);
				statement.append("' WHERE N_IDENT = ");
				statement.append(Result1);
				statement.append(";");
				//ejecutarComandoBD(&statement[0u]);
				break;
			default:
				break;
			}
		}
			break;
		case '3': {
			printf("Saliendo del programa...\n\n");
			repetir = false;
		}
			break;
		default:
			printf("\Opcion incorrecta!\n\n");
			break;
		}
	} while (repetir);

	return 0;
}

