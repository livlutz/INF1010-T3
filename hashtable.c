
/* Livia Lutz dos Santos - 2211055 */

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

	int key = hash(c);
	int col = 0, i = 1;

	if (m->tabpos[key].chave == -1) {
		m->tabpos[key].chave = c;
		strcpy(m->tabpos[key].dados, d);
		return col;
	}
	for (; m->tabpos[key + i].chave != -1; i++) {
		col++;
		if ((key + i) == 1030) {
			printf("Erro ao inserir.\n");
			return col;
		}
	}
	m->tabpos[key + i].chave = c;
	strcpy(m->tabpos[key + i].dados, d);
	m->tabpos[key + i].prox = p.prox;
	m->tabpos[key].prox = key + i;
	return col;
}

