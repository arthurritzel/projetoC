// struct Node{
//     Evento evento;
//     struct Node *prox;
// };
// typedef struct Node node;
// typedef node *lista;


// lista* criarlistta(){
//     lista *inicio = (lista*) malloc(sizeof(lista));
//     if (inicio != NULL){
//         *inicio = NULL;
//     }else{
//         printf("Erro na alocaçãooo");
//     }
//     return inicio;
// }

// int inserenofinal(lista *inicio, Evento nodeArv){
//     node *novo = (node*)malloc(sizeof(node));
//     if(novo == NULL){
//         printf("Erro na alocacao");
//         return 0;
//     }else{
//         if((*inicio) == NULL){
//             *inicio = novo;
//         }else{
//             node *temp;
//             temp = (*inicio);
//             while (temp->prox != NULL){
//                 temp = temp->prox;
//             }
//             temp->prox = novo;
//             novo->prox = NULL;
//         }
//         novo->evento = nodeArv;
//     }
// }

// void exibelista(lista*inicio){
    
//     if(*inicio == NULL){
//         printf("Lista vazia");
//     }else{
//         node *temp;
//         temp = (*inicio);

//         while (temp != NULL){
//             printf("%s\n", temp->evento->descricao);
//             temp = temp->prox;
//         }
//     }
// }

// int construirLista(Evento nodeArv, lista *list){
//     construirLista(nodeArv->esquerda, list);
//     inserenofinal(list, nodeArv);
//     construirLista(nodeArv->direita, list);
// }

// Evento balancearArvore(Evento raiz){
//     if(raiz != NULL){
//         lista *list = criarlistta();
//         construirLista(raiz, list);
//         exibelista(list);
//     }
// }

struct Node {
    Evento evento;
    struct Node* prox;
};

typedef struct Node node;
typedef node* lista;

lista* criarlista(){
    lista *inicio = (lista*) malloc(sizeof(lista));
    if (inicio != NULL){
        *inicio = NULL;
    }else{
        printf("Erro na alocaçãooo");
    }
    return inicio;
}

int inserenofinal(lista* inicio, Evento nodeArv) {
    node* novo = (node*)malloc(sizeof(node));
    if (novo == NULL) {
        printf("Erro na alocação\n");
        return 0;
    } else {
        if ((*inicio) == NULL) {
            *inicio = novo;
        } else {
            printf("node desc: %s", nodeArv->descricao);
            node* temp;
            temp = (*inicio);
            while (temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
            novo->prox = NULL;
        }
        novo->evento = nodeArv;
        return 1;
    }
}

void exibelista(lista*inicio){
    
    if(*inicio == NULL){
        printf("Lista vazia");
    }else{
        node *temp;
        temp = (*inicio);

        while (temp != NULL){
            printf("%s\n", temp->evento->descricao);
            temp = temp->prox;
        }
    }
}

int construirLista(Evento nodeArv, lista* list) {
    if (nodeArv == NULL) {
        return 1;
    }
    construirLista(nodeArv->esquerda, list);
    inserenofinal(list, nodeArv);
    construirLista(nodeArv->direita, list);
    return 1;
}

Evento* balancearArvore(Evento* raiz) {
    if (raiz != NULL) {
        lista* inicio = criarlista();
        construirLista(raiz, inicio);
        exibelista(inicio);
        // Implemente a lógica para equilibrar a árvore e retorne a raiz equilibrada
        return raiz;
    }
    return NULL;
}