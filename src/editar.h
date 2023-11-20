#include "buscar.h"

// Atualizar evento

Evento* editar_evento(Evento *raiz, int dia, int mes, char descricao[100]){

    // Para buscar o elemento a ser atualizado

    Evento *editar_evento = buscar_evento(raiz, dia, mes);

    // Se o evento não for encontrado, retorna o próprio evento

    if(editar_evento == NULL) {
        printf("Atualização falhou.\n Evento não cadastrado!\n");
        return raiz;
    }

    int esc;
    int novo_dia;
    int novo_mes;

    // Definição do que o usuário quer editar

    while (editar_evento != NULL){
        printf("\nO que deseja atualizar?\n");
        printf("1. Atualizar dia.\n");
        printf("2. Atualizar mês.\n");
        printf("3. Atualizar descrição.\n");
        printf("4. Atualizar Tudo.\n");
        printf("5. Sair.\n");

        printf("Escolha uma opção: ");
        scanf("%d", &esc);
        fflush(stdin);

        switch(esc)
        {
        case 1:
            printf("Informe o novo dia (1-31): \n");
            scanf("%d", &novo_dia);
            fflush(stdin);
            editar_evento->dia = novo_dia;
            printf("Dia atualizado com sucesso! \n");
            break;
        case 2:
            printf("Informe o novo mês (1-31): \n");
            scanf("%d", &novo_mes);
            fflush(stdin);
            editar_evento->mes = novo_mes;
            printf("Mês atualizado com sucesso! \n");
            break; 
        case 3:
            printf("Informe a nova descrição: \n");
            fgets(descricao, sizeof(descricao), stdin);
            fflush(stdin);
            strcpy(editar_evento->descricao, descricao);
            printf("Descrição atualizada com sucesso! \n");
            break; 
        case 4:
            printf("Informe o novo dia (1-31): \n");
            scanf("%d", &novo_dia);
            fflush(stdin);
            editar_evento->dia = novo_dia;
            printf("Informe o novo mês (1-31): \n");
            scanf("%d", &novo_mes);
            fflush(stdin);
            editar_evento->mes = novo_mes;
            printf("Informe a nova descrição: \n");
            fgets(descricao, sizeof(descricao), stdin);
            fflush(stdin);
            strcpy(editar_evento->descricao, descricao);
            printf("Evento atualizado com sucesso!\n");
            break; 
        case 5:
            printf("Atualização cancelada.\n");
            exit(0);
        default:
            printf("Opção inválida. Tente novamente.\n");
        } 
    }

    return raiz;
}