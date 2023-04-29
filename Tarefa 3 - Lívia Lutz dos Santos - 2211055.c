
/* Lívia Lutz dos Santos - 2211055 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashtable.h"

int main(void) {

	char numerais[10] = { '0','1','2','3','4','5','6','7','8','9'};

	char placa[8];

	char c1,c2,c3,n,ch;
	FILE* f;

	f = fopen("Placas.txt", "w");

	srand(time(NULL));

	for (int i = 0; i < 128; i++) {
		
		c1 = rand() % 26 + 65;
		c2 = rand() % 26 + 65;
		c3 = rand() % 26 + 65;
		placa[0] = '\0';
		strncat(placa, &c1, 1);
		strncat(placa, &c2, 1);
		strncat(placa, &c3, 1);

		for (int i = 0; i < 4; i++) {
			n = numerais[rand() % 10];
			strncat(placa, &n,1);
		}

		fwrite(&placa,sizeof(placa)-1, 1, f);
		ch = '\n';
		fwrite(&ch, sizeof(ch), 1, f);

	}

	fclose(f);

	Mapa* m = cria();


	f = fopen("Placas.txt", "r");

	for (int j = 0; j < 512; j++) {

		fread(placa,sizeof(placa), 1, f);

		placa[7] = '\0';

		c += insere(m,j,placa);
	
	}

	printf("%d\n", c);

	fclose(f);

	return 0;
}

