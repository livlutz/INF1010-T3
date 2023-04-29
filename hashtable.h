//inclusão,busca e remoção

typedef struct ttabpos;
typedef struct smapa Mapa;
Mapa* cria(void);
Mapa* insere(Mapa* m, int chave, char* dados);
int hash(int key);
