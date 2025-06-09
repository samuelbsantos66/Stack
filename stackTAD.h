//DADOS:
typedef double elementoT;

typedef struct stackTCD *stackTAD;

//COMPORTAMENTOS:
stackTAD criar_stackTAD(void);

void remover_stackTAD(stacKTAD *stack);

void push(stackTAD stack, elementoT elemento);

elementoT pop(stackTAD stack);

bool vazia(stackTAD stack);

bool cheia(stackTAD stack);

long int tamanho(stackTAD stack);

long int qtd_elementos(stackTAD stack);

#ifdef debug
long int espaco_restante(stackTAD stack)
#endif

#ifdef debug
elementoT ver_elemento(stackTAD stack, int posicao);
#endif
