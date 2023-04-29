
/* Livia Lutz dos Santos - 2211055 */
/* Luiza Marcondes Paes Leme - 2210275 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TAMINICIAL 1031 //primo após 1024 

//encadeamento interior

typedef struct {
	int chave;
	char dados[8];
	int prox;
} ttabpos;

struct smapa {
	int tam;
	ttabpos* tabpos;
};

int hash(int key) {
	key *= key;
	key *= 14;
	key = key & 0x3FFF;
	key = key >> 4;
	return key % TAMINICIAL;
}

Mapa* cria(void) {
	int i;
	Mapa* m = (Mapa*)malloc(sizeof(Mapa));

	if (m == NULL) { 
		printf("erro na alocação! \n"); 
		exit(1); 
	}

	m->tabpos = (ttabpos*)malloc(TAMINICIAL * sizeof(ttabpos));
	if (m->tabpos == NULL) {
		printf("erro na alocação! \n");
		exit(1);
	}

	m->tam = TAMINICIAL;

	for (i = 0; i < TAMINICIAL; i++) {
		m->tabpos[i].chave = -1;
		m->tabpos[i].prox = -1;
	}

	return m;
}

int insere(Mapa* m, int c, char* d) {

	int pos = hash(c);
	int col = 0, i = 1;

	if (m->tabpos[pos].chave == -1) {
		m->tabpos[pos].chave = c;
		strcpy(m->tabpos[pos].dados, d);
		return col;
	}
	for (; m->tabpos[pos + i].chave != -1; i++) {
		col++;
		if ((pos + i) == 1030) {
			printf("Erro ao inserir.\n");
			return col;
		}
	}
	m->tabpos[pos + i].chave = c;
	strcpy(m->tabpos[pos + i].dados, d);
	m->tabpos[pos + i].prox = p.prox;
	m->tabpos[pos].prox = pos + i;
	return col;
}

