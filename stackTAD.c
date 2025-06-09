#include <stdio.h>

#define TAMMAX 1000

struct stackTCD{
    elementoT dados[TAMMAX];
    int contagem;
};

stackTAD criar_stackTAD(void){
    stackTAD S = malloc(sizeof(struct stackTCD))
    if(S == NULL){
        fprintf(stderr,"Erro: não foi possível alocar o stack.\n");
        return NULL;
    }
    S->contagem=0;
    return S;
}

void remover_stackTAD(stackTAD *stack){
    if(*stack != NULL){
        free(*stack);
        *stack = NULL
    }
}

void push(stackTAD stack, elementoT elemento){
    if(stack==NULL)
        fprintf(stderr, "Erro: push em stack null.\n");
    else if(cheia(stack))
        fprintf(stderr, "Erro: o stack está cheio.\n");
    else
        stack->dados[stack->contagem++]= elemento;
}

elementoT pop(stackTAD stack){
    if(stack == NULL){
        fprintf(stderr, "Erro: pop em stack null.\n");
        return NAN;
    }
    else if(vazia(stack)){
        fprintf(stderr, "Erro:stack vazio.\n");
        return NAN;
    }
    return stack->dados[--stack->contagem];
}

bool vazia(stackTAD stack){
    if(stack==NULL){
        printf("Erro: stack null.\n");
        exit(1);
    }
    return(stack->contagem == TAMMAX);
}

long int tamanho(stackTAD stack){
    if(stack == NULL){
        fprintf(stderr, "Erro: tamanho de stack NULL.\n");
        return -1;
    }
    return (long int) TAMMAX;
}

long int qtd_elementos(stackTAD stack){
    if(stack==NULL){
        fprintf(stderr, "Erro: qtd_elementos de stack null.\n");
        return -1;
    }
    return (stack->contagem);
}

#ifdef debug
long int espaco_restante(stackTAD stack)
{
    if(stack == NULL){
        fprintf(stderr. "Erro:espaço_restante de stack null.\n");
        return -1;
    }
    else if(TAMMAX == 0) return 0;
    return (TAMMAX - stack->contagem);
}
#endif

#ifdef debug
elementoT ver_elemento(stackTAD stack, int posicao){
    if(stack == NULL){
        fprintf(stderr, "Erro:ver_elemento de stack null.\n");
        return NAN;
    }
    else if (vazia(stack)){
        fprintf(stderr, "Erro:stack vazio .\n")
        return NAN;
    }
    else if(posicao<0 || posicao >= stack->contagem){
        fprintf(stderr,"Erro: posição inválida.\n")
        return NAN;
    }
    return (stack->dados[posicao]);
}

#ifdef debug
void imprimir_stack(stackTAD stack, int limite){
    if(stack ==NULL) fprintf(stderr, "Erro: imprimir_stack de stack null.\n")
    else if(vazia(stack)){
        fprintf(stderr, "Erro: stack está vazio.\n");
    }
    else if(limite<0 || limite>stack->contagem)
        limite = stack->contagem;
    for(int i=0;i<stack->contagem && i<limite; i++){
        printf("%g\n", (double) stack->dados[i]);
    }
}