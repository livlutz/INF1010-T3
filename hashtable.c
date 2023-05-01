
/* Livia Lutz dos Santos - 2211055 */
/* Luiza Marcondes Paes Leme - 2210275 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TAMINICIAL 1031 //Primo após 1024 

//Usamos encadeamento interior

//Struct do array de informações da placa

typedef struct {
	int chave; // Chave da placa no array
	char dados[8]; //Placa
	int prox; //Número da próxima posição livre no array
} ttabpos;

//Struct da hastable 

struct smapa {
	int tam; //Tamanho da hashtable
	ttabpos* tabpos; //Ponteiro para o array de placas
};

//Função de hash por método da multiplicação ("meio do quadrado") 

int hash(int key) {
	key *= key;
	key *= 14;
	key = key & 0x3FFF;
	key = key >> 4;
	return key % TAMINICIAL;
}

//Função de criar a hashtable

Mapa* cria(void) {
	
	//Cria hashtable
	
	int i;
	Mapa* m = (Mapa*)malloc(sizeof(Mapa));

	if (m == NULL) { 
		printf("erro na alocação! \n"); 
		exit(1); 
	}
	
	//Cria array de placas

	m->tabpos = (ttabpos*)malloc(TAMINICIAL * sizeof(ttabpos));
	if (m->tabpos == NULL) {
		printf("erro na alocação! \n");
		exit(1);
	}

	m->tam = TAMINICIAL;
	
	//inicializa as chaves e os próximos com -1

	for (i = 0; i < TAMINICIAL; i++) {
		m->tabpos[i].chave = -1;
		m->tabpos[i].prox = -1;
	}
	
	//retorna a hashtable

	return m;
}

int insere(Mapa* m, int c, char* d) {
	
	//calcula posição da chave no array usando hash()

	int pos = hash(c);
	
	//contador de colisões e posições
	
	int col = 0, i = 1;
	
	//se houver espaço para alocar os dados no índice calculado, insere normalmente retornando 0 colisões

	if (m->tabpos[pos].chave == -1) {
		m->tabpos[pos].chave = c;
		strcpy(m->tabpos[pos].dados, d);
		m->tabpos[pos] = m->tabpos[pos];
		return col;
	}
	
	//senão buscamos a próxima posição livre no índice e adicionamos as informações dos parâmetros lá
	//adicionamos 1 na colisão para cada posição nao livre no array
	
	for (; m->tabpos[pos + i].chave != -1; i++) {
		col++;
		
		//se chegarmos ao fim dos índices da hashtable, exibimos uma mensagem de erro e retornamos o número de colisões
		
		if ((pos + i) == 1030) {
			printf("Erro ao inserir.\n");
			return col;
		}
	}
	
	//Fazemos a inserção das informações dos parâmetros na posição livre encontrada e retornamos o número de colisões
	
	m->tabpos[pos + i].chave = c;
	strcpy(m->tabpos[pos + i].dados, d);
	m->tabpos[pos + i].prox = p.prox;
	m->tabpos[pos].prox = pos + i;
	return col;
}

int busca(Mapa*m,int c){
	
	//Pegamos o índice da chave procurada no array e inicializamos o contador de posições

	int pos = hash(c);
	int i = 1;
	
	//Se a primeira posição do índice for a buscada, retornamos o valor da posição

	if (m->tabpos[pos].chave == c) {
		return pos;
	}
	
	//senão buscamos dentro da posição até encontrar a chave procurada

	else {
		for (; m->tabpos[pos+i].prox != -1; i++) {
			
			//se for encontrada, retornamos sua posição
			
			if (m->tabpos[pos + i].chave == c) {
				return pos + i;
			}
		}
	}
	
	//caso chegue na última posição (-1) retornamos pos + i

	if (m->tabpos[pos + i].chave == c) {
		return pos + i;
	}
	
	//se não encontrou a chave, retornamos -1

	return -1;
	
}

int exclui(Mapa*m,int c){
	//buscamos a posição na qual o elemento a ser removido está
	int pos = busca(m, c);
	
	//caso não seja encontrado, a função retorna -1
	if (pos == -1)
		return -1;
	
	//senão definimos seu valor de chave como -1 e como não há placas, a string é alterada para \0
	m->tabpos[pos].chave = -1;
	strcpy(m->tabpos[pos].dados, "\0");
	
	//retorna a posição do elemento removido
	return pos;
}

