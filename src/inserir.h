int insere_elemento(Evento *raiz, int dia, int mes, char descricao[100])
{
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL )
    {
        printf("O valor é nulo");
        return 0;
    }
    else
    {
       novo->esquerda = NULL;
       novo->direita = NULL;
       novo->dia = dia;
       novo->mes = mes;
       strcat(descricao, "\n");
       strcpy(novo->descricao, descricao);

        if(*raiz == NULL)
        {
            *raiz = novo;
            return 1;
        }
        else
        {
            no *atual  = *raiz;
            no *ant = NULL;

            while(atual != NULL)
            {
                ant = atual;
                if(atual->dia == novo->dia && atual->mes == novo->mes)
                {
                    printf("Essa data já está no calendário");
                    free(novo);
                    return 0;
                }
                if(novo->mes > atual->mes || (novo->mes == atual->mes && novo->dia > atual->dia))
                {
                    atual = atual->direita;
                }else
                {
                    atual = atual->esquerda;
                }
            }
           if (novo->mes > ant->mes || (novo->mes == ant->mes && novo->dia > ant->dia))
            {
                ant->direita = novo;
            }
            else
            {
                ant->esquerda = novo;
            }

        }

    }
};
int insere_elemento_init(Evento *raiz, int dia, int mes, char descricao[100])
{
    no *novo = (no*) malloc(sizeof(no));
    if (novo == NULL )
    {
        printf("O valor é nulo");
        return 0;
    }
    else
    {
       novo->esquerda = NULL;
       novo->direita = NULL;
       novo->dia = dia;
       novo->mes = mes;
       strcpy(novo->descricao, descricao);

        if(*raiz == NULL)
        {
            *raiz = novo;
            return 1;
        }
        else
        {
            no *atual  = *raiz;
            no *ant = NULL;

            while(atual != NULL)
            {
                ant = atual;
                if(atual->dia == novo->dia && atual->mes == novo->mes)
                {
                    printf("Essa data já está no calendário");
                    free(novo);
                    return 0;
                }
                if(novo->mes > atual->mes || (novo->mes == atual->mes && novo->dia > atual->dia))
                {
                    atual = atual->direita;
                }else
                {
                    atual = atual->esquerda;
                }
            }
           if (novo->mes > ant->mes || (novo->mes == ant->mes && novo->dia > ant->dia))
            {
                ant->direita = novo;
            }
            else
            {
                ant->esquerda = novo;
            }

        }

    }
};
