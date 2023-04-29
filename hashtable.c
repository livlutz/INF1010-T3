
/* Livia Lutz dos Santos - 2211055 */

#include <stdio.h>
#include <stdlib.h>
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

int insere(Mapa* m, int c, int d) {

	int key = hash(c);
	ttabpos p = m->tabpos[key];
	int col = 0, i = 1;
	
	if (p.chave == -1) {
		p.chave = c;
		p.dados = d;
		m->ocupadas++;
		return col;
	}
	for (;m->tabpos[key + i].chave != -1; i++){
		col++;
		if((key + i) == 1030){
			printf("Erro ao inserir.\n");
			return col;
		}
	}
	m->tabpos[key + i].chave = c;
	m->tabpos[key + i].dados = d;
	m->tabpos[key + i].prox = p.prox;
	p.prox = key + i;
	m->ocupadas++;
	return col;


}

