//inclus�o,busca e remo��o

typedef struct ttabpos;
typedef struct smapa Mapa;
Mapa* cria(void);
Mapa* insere(Mapa* m, int chave, int dados);
unsigned int hash(char* s);
