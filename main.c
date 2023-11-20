#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No
{
    int mes;
    int dia;
    char descricao[100];
    struct No *esquerda;
    struct No *direita;
};
typedef struct No no;

typedef struct No *Evento;

#include "src/deletar.h"
#include "src/editar.h"
#include "src/visualizar.h"
#include "src/inserir.h"
#include "src/balancear.h"


Evento* criaArvore(){
    Evento *raiz = (Evento*) malloc (sizeof(Evento));
    if (raiz != NULL){
        *raiz = NULL;
    }else{
        printf("Erro na alocacao");
        return 0;
    };
    return raiz;
}
// ----------------------------------------
int init(Evento *raiz){
    //le os dados do arquivo banco-filmes.txt e armazena na struct, o arquivo esta sendo usado como banco de dados
    FILE *file;
    file = fopen("banco-agenda.txt", "r");
    if (file == NULL){
        printf("Problemas na consulta do banco de dados\n");
        return 0;
    }
    
    char vet[20], aux[20];
    int cont = 0, dia, mes, desc[100];

    while (fgets(vet, 100, file) != NULL){
        if(cont == 0){
            strcpy(aux, vet);
            dia = atoi(aux);
        }

        if(cont == 1){
            strcpy(aux, vet);
            mes = atoi(aux);
           
        }
        if(cont == 2){
            strcpy(aux, vet);
            strcpy(desc, aux);
           
        }
        cont++;
        if (cont >=3){
            cont = 0;
            insere_elemento(raiz, dia, mes, desc);
        }   
        
    }
    fclose(file);
    return 0;
}
int finit_print(Evento raiz, FILE *file){
    if (raiz != NULL) {
        fprintf(file, "%i\n", raiz->dia);
        fprintf(file, "%i\n", raiz->mes);
        fprintf(file, "%s", raiz->descricao);
        finit_print(raiz->esquerda, file);
        finit_print(raiz->direita, file);
    }
}
int finit(Evento raiz){
    //armazena todos os dados da struct filmes no arquivo banco-filmes.txt
    if(raiz != NULL){
        FILE *file;
        file = fopen("banco-agenda.txt", "w");
        if (file == NULL){
            printf("Problemas na gravacao do banco de dados\n");
            return 0;
        }
        finit_print(raiz, file);
        fclose(file);
    }else{
        return 0;
    }
}
// -----------------------------------------------------
int validar_data(int dia, int mes) {
        if (dia < 1 || dia > 31 || mes < 1 || mes > 12){ 
        return 1;
        }
        else{
            return 0;
        }
}

void libera_no(no *no_liberar){
    if(no_liberar == NULL){
        return;
    }else{
        libera_no(no_liberar->esquerda);
        libera_no(no_liberar->direita);
        free(no_liberar);
    }
}

int libera_arvore(Evento * raiz){
    if(raiz == NULL){
        return 0;
    }else{
        libera_no(*raiz);
    }
    free(raiz);
}

int main(){
    Evento *raiz = criaArvore();
    init(raiz);
    int esc, mes, dia, esc_filtro, dia_busca, mes_busca, achou;
    char descricao[100];
    system("clear");

    while (1){
        printf("|------------AGENDA------------|\n");
        printf("\nMenu:\n");
        printf("1. Inserir evento\n");
        printf("2. Editar evento\n");
        printf("3. Excluir evento\n");
        printf("4. Listar eventos\n");
        printf("5. Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &esc);

        switch (esc)
        {
        case 1:
            do{
                system("clear");
                printf("|------------INSERIR------------|\n");
                printf("Informe o dia (1-31): ");
                scanf("%d", &dia);
                printf("Informe o mes (1-12): ");
                scanf("%d", &mes);
                if (validar_data(dia, mes) == 1){
                        printf("Data invalida. Tente novamente.\n");
                }else{
                    printf("Informe a descricao: ");
                    fflush(stdin);
                    gets(descricao);
                }
            } while (validar_data(dia, mes) == 1);
            insere_elemento(raiz, dia, mes, descricao);
            system("clear");
            printf("Evento inserido com sucesso.\n");
            break;
        case 2:
            system("clear");
            printf("|------------EDITAR------------|\n");
            printf("Informe o dia (1-31) do evento a ser editado: ");
            scanf("%d", &dia);
            printf("Informe o mês (1-12) do evento a ser editado: ");
            scanf("%d", &mes);
           
            break;
        case 3:
            system("clear");
            printf("|------------EXCLUIR------------|\n");
            printf("Informe o dia (1-31) do evento a ser excluido: ");
            scanf("%d", &dia);
            printf("Informe o mês (1-12) do evento a ser excluido: ");
            scanf("%d", &mes);
            remove_no(raiz, dia, mes);
            break;
        case 4:
            system("clear");
            printf("|------------EXIBIR EVENTOS------------|\n");
            printf("Deseja:\n[1]-Filtrar busca\n[2]-Exibir todos os eventos\n->");
            scanf("%i", &esc_filtro);
            if (esc_filtro == 1){
                achou = 0;
                printf("Digite o dia: ");
                scanf("%i", &dia_busca);
                printf("Digite o mes: ");
                scanf("%i", &mes_busca);
                visualizar_arvore_filtro(*raiz, dia_busca, mes_busca, &achou);
                if (achou != 1){
                    printf("Elemento nao encontrado!\n");
                }
            }else if (esc_filtro == 2){
                visualizar_arvore(*raiz);
            }else{
                printf("Opcao invalida!\n");
            }
            break;
        case 5:
            finit(*raiz);
            libera_arvore(raiz);
            exit(1);
        default:
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
    finit(*raiz);
    libera_arvore(raiz);
    return 0;
}

