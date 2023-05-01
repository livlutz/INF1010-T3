
/* Lívia Lutz dos Santos - 2211055 */
/* Luiza Marcondes Paes Leme - 2210275 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashtable.h"

int main(void) {

	//caracteres de numeros nas placas

	char numerais[10] = { '0','1','2','3','4','5','6','7','8','9'};

	//placa do carro
	
	char placa[8];

	//caracteres a serem inseridos em placas

	char c1,c2,c3,n,ch;

	//variaveis contadoras

	int c = 0,j,d = 0,e = 0;

	//variaveis para calcular o tempo total

	double elapsed,elapsed1,elapsed2;

	//arquivo

	FILE* f;

	//variaveis de tempo

	clock_t t0,t1,t2,t3;

	//abrindo o arquivo para escrita

	f = fopen("Placas.txt", "w");

	//tornando a funcao rand() completamente aleatoria

	srand(time(NULL));

	//inserindo as placas no arquivo

	for (int i = 0; i < 512; i++) {

		//gera 3 caracteres ASCII e inclui em placas
		
		c1 = rand() % 26 + 65;
		c2 = rand() % 26 + 65;
		c3 = rand() % 26 + 65;
		placa[0] = '\0';
		strncat(placa, &c1, 1);
		strncat(placa, &c2, 1);
		strncat(placa, &c3, 1);

		//gera 4 caracteres numericos e insere em placas

		for (int i = 0; i < 4; i++) {
			n = numerais[rand() % 10];
			strncat(placa, &n,1);
		}

		//escreve a placa no arquivo

		fwrite(&placa,sizeof(placa)-1, 1, f);
		ch = '\n';
		fwrite(&ch, sizeof(ch), 1, f);

	}

	//fecha o arquivo

	fclose(f);

	//cria os mapas para cada teste

	Mapa* m = cria();
	Mapa* m1 = cria();
	Mapa* m2 = cria();

	// ------------------------- 128 placas ----------------------//

	//abre o arquivo para leitura

	f = fopen("Placas.txt", "r");

	//comeca a contar o tempo de insercao

	t0 = clock();

	//para 128 placas

	for (j = 0; j < 128; j++) {

		//le a placa do arquivo

		fread(placa,sizeof(placa), 1, f);

		placa[7] = '\0';

		//insere a placa no mapa

		c += insere(m,j,placa);

	}

	//termina a contagem

	t1 = clock();

	printf("%d colisoes para 128 placas\n", c);

	//fecha o arquivo

	fclose(f);

	//calcula o tempo total de insercao

	elapsed = 1000 * ((double)t1 - (double)t0 / CLOCKS_PER_SEC);
	printf("tempo usado pra inserir 128 placas em milisegundos: %.2f\n",elapsed);

	//comeca a contar o tempo de busca

	t2 = clock();

	//busca cada placa no mapa

	for (j = 0; j < 128; j++) {
		c = busca(m, j);
	}

	//termina a contagem do tempo de busca

	t3 = clock();

	//calcula o tempo total de busca

	elapsed1 = 100 * ((double)t3 - (double)t2 / CLOCKS_PER_SEC);
	printf("tempo usado para buscar 128 placas em mililsegundos:%.2f\n", elapsed1);
	
	//calcula o tempo total de busca + insercao
	
	elapsed2 = elapsed + elapsed1;

	printf("Tempo de busca e insercao de 128 placas em ms: %.2f\n", elapsed2);


	// --------------------- 256 placas ---------------------//


	f = fopen("Placas.txt", "r");

	//comeca a contar o tempo de insercao

	t0 = clock();

	//para 256 placas

	for (j = 0; j < 256; j++) {

		//le a placa do arquivo

		fread(placa, sizeof(placa), 1, f);

		placa[7] = '\0';

		//insere a placa no mapa

		d += insere(m1, j, placa);

	}

	//termina a contagem

	t1 = clock();

	printf("%d colisoes para 256 placas\n", d);

	//fecha o arquivo

	fclose(f);

	//calcula o tempo total de insercao

	elapsed = 1000 * ((double)t1 - (double)t0 / CLOCKS_PER_SEC);
	printf("tempo usado pra inserir 256 placas em milisegundos: %.2f\n",elapsed);

	//comeca a contar o tempo de busca

	t2 = clock();

	//busca cada placa no mapa

	for (j = 0; j < 256; j++) {
		d = busca(m1, j);
	}

	//termina a contagem do tempo de busca

	t3 = clock();

	//calcula o tempo total de busca

	elapsed1 = 100 * ((double)t3 - (double)t2 / CLOCKS_PER_SEC);
	printf("tempo usado para buscar 256 placas em mililsegundos:%.2f\n", elapsed1);

	//calcula o tempo total de busca + insercao

	elapsed2 = elapsed + elapsed1;

	printf("Tempo de busca e insercao de 256 placas em ms: %.2f\n", elapsed2);


	// ----------------------------- 512 placas --------------------//


	f = fopen("Placas.txt", "r");

	//comeca a contar o tempo de insercao

	t0 = clock();

	//para 512 placas

	for (j = 0; j < 512; j++) {

		//le a placa do arquivo

		fread(placa, sizeof(placa), 1, f);

		placa[7] = '\0';

		//insere a placa no mapa

		e += insere(m2, j, placa);

	}

	//termina a contagem

	t1 = clock();

	printf("%d colisoes para 512 placas\n", e);

	//fecha o arquivo

	fclose(f);

	//calcula o tempo total de insercao

	elapsed = 1000 * ((double)t1 - (double)t0 / CLOCKS_PER_SEC);
	printf("tempo usado pra inserir 512 placas em milisegundos: %.2f\n",elapsed);

	//comeca a contar o tempo de busca

	t2 = clock();

	//busca cada placa no mapa

	for (j = 0; j < 512; j++) {
		e = busca(m2, j);
	}

	//termina a contagem do tempo de busca

	t3 = clock();

	//calcula o tempo total de busca

	elapsed1 = 100 * ((double)t3 - (double)t2 / CLOCKS_PER_SEC);
	printf("tempo usado para buscar 512 placas em mililsegundos:%.2f\n", elapsed1);

	//calcula o tempo total de busca + insercao

	elapsed2 = elapsed + elapsed1;

	printf("Tempo de busca e insercao de 512 placas em ms: %.2f\n", elapsed2);


	return 0;
}

