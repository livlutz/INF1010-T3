
/* Lívia Lutz dos Santos - 2211055 */
/* Luiza Marcondes Paes Leme - 2210275 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hashtable.h"

int main(void) {
	
	//Array de dígitos das placas

	char numerais[10] = { '0','1','2','3','4','5','6','7','8','9'};
	
	// String correspondente à placa de cada carro

	char placa[8];
	
	//Caracteres para guardar cada char da string placa

	char c1,c2,c3,n,ch;
	
	//Inteiros de contadores de colisão e número de placas, respectivamente
	
	int c = 0,j = 0;
	
	// Variaveis para calcular o tempo passado

	double elapsed,elapsed1;
	
	//Ponteiro para arquivo
	
	FILE* f;
	
	//Variaveis para guardar tempo
	
	clock_t t0, t1,t2,t3;
	
	//Abrindo o arquivo para escrever as placas de carros geradas aleatoriamente

	f = fopen("Placas.txt", "w");
	
	//Mexendo no tempo, assim a função rand gera números aleatoriamente

	srand(time(NULL));
	
	//Para 128 placas

	for (int i = 0; i < 128; i++) {
		//as 3 primeiras variaveis geram 1 caracter entre 'A' e 'Z'
		
		c1 = rand() % 26 + 65;
		c2 = rand() % 26 + 65;
		c3 = rand() % 26 + 65;
		placa[0] = '\0';
		
		//concatenamos os 3 caracteres em placas
		
		strncat(placa, &c1, 1);
		strncat(placa, &c2, 1);
		strncat(placa, &c3, 1);
		
		//geramos 4 números aleatórios e concatenamos em placas

		for (int i = 0; i < 4; i++) {
			n = numerais[rand() % 10];
			strncat(placa, &n,1);
		}
		
		//Escrevemos cada string no arquivo com enter 

		fwrite(&placa,sizeof(placa)-1, 1, f);
		ch = '\n';
		fwrite(&ch, sizeof(ch), 1, f);

	}
	
	//Fecha o arquivo de placas

	fclose(f);
	
	//Cria uma hash table

	Mapa* m = cria();
	
	//Abre o arquivo de placas para leitura

	f = fopen("Placas.txt", "r");
	
	//Inicializa a contagem do tempo para inserir cada placa na hashtable
	
	t0 = clock();
	
	//Para todas as placas no arquivo, inserimos contando o numero de colisões

	for (; j < 128; j++) {

		fread(placa,sizeof(placa), 1, f);

		placa[7] = '\0';

		c += insere(m,j,placa);
	
	}
	
	//Para a contagem do tempo de inserir

	t1 = clock();
	
	//Fecha o arquivo

	fclose(f);
	
	//Exibe o número de colisões
	
	printf("%d colisoes para %d placas\n", c, j);
	
	//Calcula o tempo total, exibindo seu resultado em milisegundos

	elapsed = 1000 * ((double)t1 - (double)t0 / CLOCKS_PER_SEC);
	printf("tempo usado pra inserir em milisegundos: %f\n", elapsed);
	
	//Começa a contagem do tempo de busca de cada chave

	t2 = clock();

	for (; j < 512; j++) {
		c = busca(m, j);
	}
	
	//Para a contagem do tempo de busca

	t3 = clock();
	
	//Calcula o tempo de busca em milisegundos e exibe seu valor

	elapsed1 = 100 * ((double)t3 - (double)t2 / CLOCKS_PER_SEC);
	printf("tempo usado para buscar todos os elementos em mililsegundos: %f\n", elapsed1);

	return 0;
}

