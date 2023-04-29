
/* Livia Lutz dos Santos - 2211055 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#define TAMINICIAL 1031 //primo após 1024 

//encadeamento interior

typedef struct {
	char chave[8];
	int dados;
	int prox;
} ttabpos;

struct smapa {
	int tam;
	int ocupadas;
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
	m->ocupadas = 0;

	for (i = 0; i < TAMINICIAL; i++) {
		m->tabpos[i].chave = -1;
		m->tabpos[i].prox = -1;
	}

	return m;
}

Mapa* insere(Mapa* m, char* chave, int dados) {
	if (m->ocupadas > 0.75 * m->tam) {
		redimensiona(m);
	}
	unsigned int pos = hash(chave);
}

