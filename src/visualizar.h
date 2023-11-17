
void visualizar_arvore(Evento raiz) {
    if (raiz != NULL) {
        visualizar_arvore(raiz->esquerda);
        printf("Dia: %d/ mes:%d \n - Descricao: %s\n------------\n", raiz->dia, raiz->mes, raiz->descricao);
        visualizar_arvore(raiz->direita);
    }
}
