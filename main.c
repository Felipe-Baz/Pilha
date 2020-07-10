#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int codigo;
    struct elemento *ant;
} tipoElemento;
typedef struct pilha{
int tamanhoPilha;
tipoElemento *topo;
} tipoPilha;

void inicializaPilha (tipoPilha *pilhaAux){
    pilhaAux->topo = NULL;
    pilhaAux->tamanhoPilha = 0;
}

void Push (tipoPilha *pilhaAux, int code){
    tipoElemento *Novo = (tipoElemento*)malloc(sizeof(tipoElemento));
    Novo->codigo = code;
    if(pilhaAux->tamanhoPilha == 0){
        Novo->ant = NULL;
    }else{
        Novo->ant = pilhaAux->topo;
    }
    pilhaAux->topo = Novo;
    pilhaAux->tamanhoPilha++;
}

void Pop (tipoPilha *pilhaAux){ //so retira se houver
    tipoElemento *Aux = pilhaAux->topo;
    pilhaAux->topo = Aux->ant;
    free(Aux);
    pilhaAux->tamanhoPilha--;
}

int Peek (tipoPilha *pilhaAux, int code){  //retorna 1 se ta no topo, 0 se n
    if(pilhaAux->tamanhoPilha == 0){
        return 0;
    }else if(pilhaAux->topo->codigo == code){
        return 1;
    }else{
        return 0;
    }
}

void List(tipoPilha *pilhaAux){
    tipoElemento *Aux = pilhaAux->topo;
    while(Aux->ant != NULL){
        printf("%d ", Aux->codigo);
        Aux = Aux->ant;
    }
    printf("%d\n", Aux->codigo);
}

int main()
{
    int quant, i, op, code, resp;
    tipoPilha Mypilha;
    inicializaPilha(&Mypilha);
    scanf("%d", &quant);
    for (i = 0; i < quant; i++)
    {
        scanf("%d %d", &op, &code);
        if (op == 1){
            Push(&Mypilha, code);
            List(&Mypilha);
        }else{
            resp = Peek(&Mypilha, code);
            if (resp == 1)
            {
                Pop(&Mypilha);
                List(&Mypilha);
            }else
            {
                printf("Não foi possível remover esse carro agora\n");
                List(&Mypilha);
            }            
        }
    }
    return 0;
}
