#define _CRT_SECURE_NO_WARNINGS
/*
Desarollador: Victor Balbas
En este programa se realizara un sistema para administrar N plazas de garaje
y ver de esta manera si estan libres, u ocupadas, y por quien
*/
#include<stdio.h>
#include<string.h>

#define NPLAZAS 10


struct plaza {
	int plaza; //si plaza=0, plaza libre; si plaza=1, plaza ocupada
	char matricula [10], matricula1[10];
};





int main() {

	//variable para el registro de usuario
	char usuario[50] = "admin";
	char usuario1[50];
	char contrasena[50] = "12345";
	char contrasena1[50];
	int intentos = 0;
	int orden, orden1;

	//variable para el switch
	char elige;

	//variable para las plazas
	struct plaza parking[NPLAZAS];
	int i,j; //variables para bucles

	//algoritmo para introducir usuario y contraseña
	do {
		printf("Bienvenido al sistema de gestion de usuarios del parking\n");
		printf("Introduce el usuario: ");
		scanf("%s", usuario1);
		orden = strcmp(usuario, usuario1);
		if (orden == 0) {
			printf("Introduce la contrasena: ");
			scanf("%s", contrasena1);
			orden1 = strcmp(contrasena, contrasena1);
			if (orden1 == 0) {
				printf("Usuario y contraseña introducidos correctamente \n");
				intentos = 3;
				break;
			}
			else {
				printf("introduce la contrasena correctamente \n");
				intentos = intentos + 1;
				printf("Llevas %d intentos \n", intentos);
				if (intentos == 3) {
					printf("Numero de intentos superados, el programa se detendra \n");
					system("pause");
					return;
				}
			}
		}
		else {
			printf("Introduce el usuario correctamente: \n");
			intentos = intentos + 1;
			printf("Llevas %d intentos \n", intentos);
			if (intentos == 3) {
				printf("Numero de intentos superados, el programa se detendra \n");
				system("pause");
				return;
			}

		}


	} while (intentos < 4);

	system("cls");

	// nos aseguramos que las plazas estan vacias antes de empezar el bucle del aparcamiento
	for (i = 0; i <= NPLAZAS; i++) {
		
		parking[i].plaza = 0;
		parking[i].matricula[10] = "NNNNLLL";
		parking[i].matricula1[10] = "NNNNLLL";
	}

	
	do {

		printf("ASISTENTE DE APARCAMIENTO \n");
		printf("Desde este menu se podra comprobar si queda alguna plaza libre para poder aparcar, y en caso contrario, \nver quien la ocupa: \n\n");
		printf("Si desea aparcar su vehiculo -> A \n");
		printf("Si desea retirar su vehiculo -> R \n");
		printf("Si desea buscar un vehiculo por su maticula -> B \n");
		printf("Si desea ver el estado del parking -> E \n");
		printf("Si desea salir del parking -> S \n");
		getchar();
		scanf("%c", &elige);

		switch (elige) {
	
		case 'A':
		case 'a':
			for (i = 0; i <= NPLAZAS; i++) {
				if (parking[i].plaza == 0) {
					printf("Hay sitio para aparcar, Introduzca su matricula: \n");
					getchar();
					scanf("%S", parking[i].matricula);
					for (j = 0; j <= NPLAZAS; j++) {
						orden = strcmp(parking[i].matricula, parking[j].matricula);
						if (orden == 0) {
							parking[i].plaza = 1;
							printf("Su vehiculo ha sido aparcado correctamente \n");
							break;
						}
						else {
							printf("La matricula introducida ya esta registrada, por favor, introduzca otra. Gracias \n");
						}
					}
					break;
				}
				else {
					printf("El parking esta lleno, lo sentimos \n");
				}
			}
			system("pause");

			break;
		case 'e':
		case 'E': 
			for (i = 0; i < NPLAZAS; i++) {
				if (parking[i].plaza == 1) {
					printf("Plaza %d ocupada: matricula -> %S \n", i+1, parking[i].matricula);
				}
				else {
					printf("Plaza %d libre \n", i+1);
				}
			}
			system("pause");
			break;

		case 'r':
		case 'R':
			system("cls");

			//muestra todas las plazas, para saber cual elegir
			for (i = 0; i <= NPLAZAS; i++) {
				if (parking[i].plaza == 1) {
					printf("Plaza %d ocupada: matricula -> %S \n", i, parking[i].matricula);
				}
				else {
					printf("Plaza %d libre \n", i);
				}
			}
			//vacia todas los parking[].matricula1
			for (i = 0; i <= NPLAZAS; i++) {
				parking[i].matricula1[10] = "NNNNLLL";
			}
			//para retirar el vehiculo, la matricula introducida se guarda en el espacio 3 del parking[].matricula1
			printf("Introduzca la matricula del coche que se desea retirar: \n");
			getchar();
			scanf("%S", parking[3].matricula1);

			for (i = 0; i < NPLAZAS; i++) {
				orden = strcmp(parking[i].matricula, parking[3].matricula1); //comparar dos cadenas (libreria string.h)
				if (orden == 0) {
					printf("Se retirara el coche de la plaza %d, matricula -> %S \n", i+1, parking[i].matricula);
					parking[i].plaza = 0;
				}
				else {
					if (parking[i].plaza == 1)
						parking[i].plaza = 1;
					else
						parking[i].plaza = 0;

				}
			}

			system("pause");
			break;

		case 's':
		case 'S':
			printf("Ha pulsado salir\n");
			system("pause");
			exit(0); //para salir del programa
			//con return; el proframa no funciona, sale cuadro de error

		case 'B':
		case 'b':
			//vacia todas los parking[].matricula1
			for (i = 0; i <= NPLAZAS; i++) {
				parking[i].matricula1[10] = "NNNNLLL";
			}

			printf("Buscar coche aparcado por matricula: \n");
			printf("Introduce una matricula, y se comprobara si esta aparcado en el parking o no \n");
			getchar();
			scanf("%S", parking[3].matricula1);

			for (i = 0; i < NPLAZAS; i++) {
				orden = strcmp(parking[i].matricula, parking[3].matricula1); //comparar dos cadenas (libreria string.h)
				if (orden == 0) {
					printf("El coche con matricula %S, se encuentra en la plaza %d \n", parking[i].matricula, i + 1);
					
				}
				else {
					//printf("La matricula introducida no corresponde a ningun coche del parking \n");
				}
			}
			break;


		

		default:
			printf("La opcion elegida no es valida, Intentelo de nuevo");
			system("pause");

		}

		system("cls");

	}while (elige != 1);


	

	system("pause");

}