#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10


// STRUCT DO ITEM
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor global para armazenar até 10 itens
Item mochila[MAX_ITENS];
int totalItens = 0;

// FUNÇÃO: INSERIR ITEM

void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("\nA mochila está cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("\n--- Cadastro de Item ---\n");
    printf("Nome do item: ");
    scanf(" %29[^\n]", novo.nome);  // Lê até 29 caracteres, evitando overflow

    printf("Tipo do item (arma, municao, cura...): ");
    scanf(" %19[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochila[totalItens] = novo;
    totalItens++;

    printf("\nItem cadastrado com sucesso!\n");
}


// FUNÇÃO: REMOVER ITEM PELO NOME

void removerItem() {
    if (totalItens == 0) {
        printf("\nNão há itens na mochila para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("\nInforme o nome do item que deseja remover: ");
    scanf(" %29[^\n]", nomeRemover);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {

            // Move todos os itens seguintes uma posição para trás
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            totalItens--;
            printf("\nItem removido com sucesso!\n");
            return;
        }
    }

    printf("\nItem não encontrado!\n");
}


// FUNÇÃO: LISTAR ITENS

void listarItens() {
    printf("\n--- Itens na Mochila ---\n");

    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("\nItem %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n", mochila[i].quantidade);
    }
}


// FUNÇÃO: BUSCAR ITEM POR NOME (BUSCA SEQUENCIAL)

void buscarItem() {
    if (totalItens == 0) {
        printf("\nA mochila está vazia.\n");
        return;
    }

    char nomeBusca[30];
    printf("\nInforme o nome do item que deseja buscar: ");
    scanf(" %29[^\n]", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\n--- Item encontrado! ---\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            return;
        }
    }

    printf("\nItem não encontrado.\n");
}


// PROGRAMA PRINCIPAL

int main() {
    int opcao;

    do {
        printf("\n==============================\n");
        printf("   Itens Mochila\n");
        printf("==============================\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Buscar item\n");
        printf("4 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                break;
            case 2:
                removerItem();
                listarItens();
                break;
            case 3:
                buscarItem();
                break;
            case 4:
                listarItens();
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
