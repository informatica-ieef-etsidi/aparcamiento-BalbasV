/*
Desarollador: Victor Balbas
En este programa se realizara un sistema para administrar 2 plazas de garaje
y ver de esta manera si estan libres, u ocupadas, y por quien
*/
#include<stdio.h>

int main() {

	int plaza1 = 0;			 //variable para la ocupacion de las plazas
	int plaza2 = 0;			 //si plaza=0, plaza libre; si plaza=1, plaza ocupada
	char elige;				 //variable para el switch
	char matricula1[10];	 //matricula del coche de la plaza 1
	char matricula2[10];	 //matricula del coche de la plaza 2
	int retirar = 0;		 //se utilizara para ver que coche se quiere retirar

	do {

		printf("ASISTENTE DE APARCAMIENTO \n");
		printf("Desde este menu se podra comprobar si queda alguna plaza libre para poder aparcar, y en caso contrario, \nver quien la ocupa: \n\n");
		printf("Si desea aparcar su vehiculo -> A \n");
		printf("Si desea retirar su vehiculo -> R \n");
		printf("Si desea ver el estado del parking -> E \n");
		
		scanf_s("%c", &elige);

		switch (elige) {
		case 'a':
		case 'A':
			if (plaza1 == 0 || plaza2 == 0) {
					if (plaza1 == 0) {
						printf("Hay sitio para aparcar, Introduzca su matricula: \n");
						scanf_s("%S", matricula1, 10);
						if (matricula1 != matricula2) {
							plaza1 = 1;
						}
						else {
							printf("La matricula introducida ya esta registrada, por favor, introduzca otra. Gracias \n");
						}
					}
					else {
						
						printf("Hay sitio para aparcar, Introduzca su matricula: \n");
						scanf_s("%S", matricula2, 10);
						if (matricula1 != matricula2) {
							plaza2 = 1;
						}
						else {
							printf("La matricula introducida ya esta registrada, por favor, introduzca otra. Gracias \n");
						}
					}
				
			}
			else {
				printf("Lo sentimos, el parking esta lleno \n");
			}
			system("pause");
			break;
			 
		case 'r':
		case 'R':
			if (plaza1 == 1 || plaza2 == 1) {
				if (plaza1 == 1 && plaza2 == 0) {
					printf("se retirara el vehiculo de la plaza 1, matricula: %S \n", matricula1);
					plaza1 = 0;
				}
				else if (plaza2 == 1 && plaza1 == 0) {
					printf("se retirara el vehiculo de la plaza 2, matricula: %S \n", matricula2);
					plaza2 = 0;
				}
				else if (plaza1 == 1 && plaza2 == 1) {
					printf("Plaza 1 -> Ocupada, matricula: %S \n", matricula1);
					printf("Plaza 2 -> Ocupada, matricula: %S \n", matricula2);
					
					printf("Introduzca la plaza del vehiculo que se desea retirar: \n");
					scanf_s("%d", retirar, 10); //seguir aqui
											// para compararlas matriculas, poner un getchar(), y asi borrar el \0

					if (retirar == 1) {
						printf("Se retirara el vehiculo de la plaza 1, matrucula: %S \n", matricula1);
						plaza1 = 0;
					}
					else if (retirar == 2) {
						printf("Se retirara el vehiculo de la plaza 2, matricula: %S \n", matricula2);
					}
					else {
						printf("La matricula introducida no coincide con ningun coche aparcado \n");
					}

					

				}
			}
			else {
				printf("Lo sentimos, no hay ningun coche aparcado \n");
			}
			system("pause");
			break;

		case 'e':
		case 'E':
			if (plaza1 == 0) {
				printf("Plaza 1 -> Libre \n");
			}
			else {
				printf("Plaza 1 -> Ocupada, matricula: %S \n", matricula1);
			}

			if (plaza2 == 0) {
				printf("Plaza 2 -> Libre \n");
			}
			else {
				printf("Plaza 2 -> Ocupada, matricula: %S \n", matricula2);
			}

			printf("Gracias por su visita al parking \n");

			system("pause");
			break;

		default:
			printf("La opcion elegida no es valida");

		}
		
		system("cls");

	} while (elige != 'x' || elige != 'X');
	system("pause");
}