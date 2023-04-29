
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
	
	int c = 0,j=0;

	double elapsed,elapsed1;
	
	FILE* f;
	
	clock_t t0, t1,t2,t3;

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
	
	t0 = clock();

	for (; j < 512; j++) {

		fread(placa,sizeof(placa), 1, f);

		placa[7] = '\0';

		c += insere(m,j,placa);
	
	}
	
	printf("%d colisoes para %d placas\n", c, j);

	t1 = clock();

	fclose(f);

	elapsed = 1000 * ((double)t1 - (double)t0 / CLOCKS_PER_SEC);
	printf("tempo usado pra inserir em milisegundos: %f\n", elapsed);

	t2 = clock();

	for (; j < 512; j++) {
		c = busca(m, j);
	}

	t3 = clock();

	elapsed1 = 100 * ((double)t3 - (double)t2 / CLOCKS_PER_SEC);
	printf("tempo usado para buscar todos os elementos em mililsegundos: %f\n", elapsed1);

	return 0;
}

