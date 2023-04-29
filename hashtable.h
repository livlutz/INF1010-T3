/* Lívia Lutz dos Santos - 2211055 */
/* Luiza Marcondes Paes Leme - 2210275 */

//Struct do array de placas

typedef struct ttabpos;

//Struct da hash table

typedef struct smapa Mapa;

//Função que cria a hashtable

Mapa* cria(void);

//Função que insere infromações das placas na hashtable

Mapa* insere(Mapa* m, int chave, char* dados);

//Função de hash que gera o índice de cada chave das placas no array

int hash(int key);

//Função que busca uma chave de placa na hash table

int busca(Mapa* m, int c);
