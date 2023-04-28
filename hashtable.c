
/* Livia Lutz dos Santos - 2211055 */

#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

#define TAMINICIAL 1031 //primo ap�s 1024 

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

unsigned int hash(char* s) {
	unsigned int hashval;
	for (hashval = 0; *s; s++) {
		hashval = *s + 31 * hashval;
	}
	return hashval % TAMINICIAL;
}

Mapa* cria(void) {
	int i;
	Mapa* m = (Mapa*)malloc(sizeof(Mapa));

	if (m == NULL) { 
		printf("erro na aloca��o! \n"); 
		exit(1); 
	}

	m->tabpos = (ttabpos*)malloc(TAMINICIAL * sizeof(ttabpos));
	if (m->tabpos == NULL) {
		printf("erro na aloca��o! \n");
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

