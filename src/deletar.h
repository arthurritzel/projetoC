void remover_folha(no *no_print, no *ant){
    if(ant->mes > no_print->mes || (ant->mes == no_print->mes && ant->dia > no_print->dia)){
        ant->esquerda = NULL;
        free(no_print);
    }else{
        ant->direita = NULL;
        free(no_print);
    }
}

void remover_umFilho(no *no_print, no *ant){
    if(ant->mes > no_print->mes || (ant->mes == no_print->mes && ant->dia > no_print->dia)){
        if(no_print->direita != NULL){
            ant->esquerda = no_print->direita;
            free(no_print);
        }else{
            ant->esquerda = no_print->esquerda;
            free(no_print);
        }
    }else{
        if(no_print->direita != NULL){
            ant->direita = no_print->direita;
            free(no_print);
        }else{
            ant->direita = no_print->esquerda;
            free(no_print);
        }   
    }
}

void remover_interno(no *no_print, no *ant){
    no *atual2; 
    no *anterior2;
    atual2 = no_print->esquerda;
    anterior2 = no_print->esquerda;
    printf("passei"); 
    while(atual2->direita != NULL){
        anterior2 = atual2;
        atual2 = atual2->direita;
    }
    printf("passei2");
    anterior2->direita = NULL;
    atual2->direita = no_print->direita;
    if(atual2 == no_print->esquerda){
        atual2->esquerda = NULL;
    }else{
        atual2->esquerda = no_print->esquerda;
    }
    if(ant->mes > no_print->mes || (ant->mes == no_print->mes && ant->dia > no_print->dia)){
         ant->esquerda = atual2;
    }else{
        ant->direita = atual2;
    }
    free(no_print);
    return;
}

void acha_no(no *no_print, int dia, int mes, no *ant){
    int confirma = 0;
    if(no_print == NULL){
        return;
    }else{
        acha_no(no_print->esquerda, dia, mes, no_print);
        acha_no(no_print->direita, dia, mes, no_print);
        if(no_print->dia == dia && no_print->mes == mes){
            printf("Data: %d/%d - Descricao: %s\n", no_print->dia, no_print->mes, no_print->descricao);
            printf("Tem certeza que deseja remover esse evento?\n[1]-SIM\n[2]-CANCELAR\n->");
            scanf("%i", &confirma);
            if (confirma == 1){
                if(no_print->esquerda == NULL && no_print->direita == NULL){
                    remover_folha(no_print, ant);
                    return;
                }else if((no_print->esquerda == NULL && no_print->direita != NULL) || (no_print->esquerda != NULL && no_print->direita == NULL)){
                    remover_umFilho(no_print, ant);
                    return;
                }else{
                    remover_interno(no_print, ant);
                    return;
                }
                system("clear");
                printf("Elemento removido!");
            }else{
                printf("Operacao cancelada");
            }
        }
    }
}

int remove_no(Evento *raiz, int dia, int mes){
    if(raiz == NULL){
        return 0;
    }else if((*raiz)->mes == mes && (*raiz)->dia == dia){
        
    }else{
        acha_no(*raiz, dia, mes, *raiz);
    }

}