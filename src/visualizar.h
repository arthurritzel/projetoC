
void visualizar_arvore(Evento raiz) {
    if (raiz != NULL) {
        visualizar_arvore(raiz->esquerda);
        printf("Data: %d/%d - Descricao: %s\n", raiz->dia, raiz->mes, raiz->descricao);
        visualizar_arvore(raiz->direita);
    }
}


visualizar_arvore_filtro(Evento raiz, int dia, int mes, int *achou){
    if (raiz != NULL) {
        if (raiz->dia == dia && raiz->mes == mes){
            printf("Data: %d/%d - Descricao: %s\n", raiz->dia, raiz->mes, raiz->descricao);
            *achou = 1;
        }
        visualizar_arvore_filtro(raiz->esquerda, dia, mes, achou);
        visualizar_arvore_filtro(raiz->direita, dia, mes, achou);
    }
}
