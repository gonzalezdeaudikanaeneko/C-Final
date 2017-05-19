/*
 * main.cpp
 *
 *  Created on: 18 de may. de 2017
 *      Author: Eneko
 */




#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

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




	sqlite3 *db;
	char *zErrMsg = 0;
	int  rc;
	char *sql;

	const char* data = "Callback function called";


	/* Open database */
	rc = sqlite3_open("test.db", &db);
	if( rc ){
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	return(0);
	}else{
	fprintf(stdout, "Opened database successfully\n");
	}
	/* Create SQL statement */
	sql = "CREATE TABLE CUENTA("  \
	"ID_CUENTA   INT PRIMARY KEY     NOT NULL," \
	"NOMBRE           VARCHAR(20)    NOT NULL," \
	"CONTRASENA       VARCHAR(20)   NOT NULL," \
	"DNI            INT     NOT NULL," \
	"SUELDO        INT," \
	"DEUDAS         INT );";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
	fprintf(stderr, "SQL error: %s\n", zErrMsg);
	sqlite3_free(zErrMsg);
	}else{
	fprintf(stdout, "Table created successfully\n");
	}
	sqlite3_close(db);




	/* Open database */
	rc = sqlite3_open("test.db", &db);
	if( rc ){
	  fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	  return(0);
	}else{
	  fprintf(stderr, "Opened database successfully\n");
	}

	/* Create SQL statement */
	sql = "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) "  \
		 "VALUES (1, 'Paul', 32, 111, 20000, 0); " \
		 "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS) "  \
		 "VALUES (2, 'Allen', 25, 222, 15000, 0); "     \
		 "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS)" \
		 "VALUES (3, 'Teddy', 23, 333, 20000, 500);" \
		 "INSERT INTO CUENTA (ID_CUENTA,NOMBRE,CONTRASENA,DNI,SUELDO,DEUDAS)" \
		 "VALUES (4, 'Mark', 25, 444, 65000, 1000);";

	 sql = "SELECT * from COMPANY";

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if( rc != SQLITE_OK ){
	  fprintf(stderr, "SQL error: %s\n", zErrMsg);
	  sqlite3_free(zErrMsg);
	}else{
	  fprintf(stdout, "Records created successfully\n");
	}
	sqlite3_close(db);





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
	Cuenta *c,*c1,*c2;
	c->setContrasena("123");c->setDe(0);c->setID(1);c->setLiquidacion(222);c->setNombre("Eneko");c->setNumeroId(1);
//	c1->setContrasena("123");c1->setDe(0);c1->setID(1);c1->setLiquidacion(222);c1->setNombre("Eneko");c1->setNumeroId(01);
//	c2->setContrasena("123");c2->setDe(0);c2->setID(1);c2->setLiquidacion(222);c2->setNombre("Eneko");c2->setNumeroId(01);
//	CB->push_front(c);
//	CB->push_front(c1);
//	CB->push_front(c2);
	//CB = b.LeerFichero(); //TODO
	CB = b.LeerFichero(); //TODO
	fflush(stdin);
	int modificacion, modificacion1;
	do {//
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

