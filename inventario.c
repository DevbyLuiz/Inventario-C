#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// =============================================
//  TRABALHO ADS - SISTEMA DE INVENTÁRIO COMPLETO
//  Feito de forma simples e didática (nível 2º semestre)
// =============================================

// ----------------------------
// STRUCTS DO PROJETO
// ----------------------------

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// ----------------------------
// VARIÁVEIS GLOBAIS DO VETOR
// ----------------------------
Item mochilaVetor[10];
int totalItensVetor = 0;

// Contadores para comparaçoes
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// ----------------------------
// FUNÇÕES DO VETOR
// ----------------------------
void inserirItemVetor() {
    if (totalItensVetor >= 10) {
        printf("\nMochila cheia (10 itens).\n");
        return;
    }

    Item novo;

    printf("\nNome do item: ");
    scanf("%s", novo.nome);

    printf("Tipo do item: ");
    scanf("%s", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    mochilaVetor[totalItensVetor] = novo;
    totalItensVetor++;

    printf("\nItem adicionado ao vetor com sucesso!\n");
}

// Remover item pelo nome
void removerItemVetor() {
    if (totalItensVetor == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    char nome[30];
    printf("\nItem a remover (nome): ");
    scanf("%s", nome);

    int i;
    for (i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < totalItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            totalItensVetor--;
            printf("\nItem removido com sucesso.\n");
            return;
        }
    }

    printf("\nItem nao encontrado.\n");
}

// Listagem geral
void listarItensVetor() {
    printf("\n=== ITENS NO VETOR ===\n");

    if (totalItensVetor == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    for (int i = 0; i < totalItensVetor; i++) {
        printf("%d) Nome: %s | Tipo: %s | Qtd: %d\n",
               i + 1,
               mochilaVetor[i].nome,
               mochilaVetor[i].tipo,
               mochilaVetor[i].quantidade);
    }
}

// Busca sequencial
void buscarSequencialVetor() {
    if (totalItensVetor == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    char nome[30];
    printf("\nNome do item para busca sequencial: ");
    scanf("%s", nome);

    comparacoesSequencial = 0;

    for (int i = 0; i < totalItensVetor; i++) {
        comparacoesSequencial++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("\nItem encontrado! Nome: %s | Tipo: %s | Qtd: %d\n",
                   mochilaVetor[i].nome,
                   mochilaVetor[i].tipo,
                   mochilaVetor[i].quantidade);
            printf("Comparacoes: %d\n", comparacoesSequencial);
            return;
        }
    }

    printf("\nItem nao encontrado. Comparacoes: %d\n", comparacoesSequencial);
}

// Ordenação por nome para busca binária
void ordenarVetor() {
    for (int i = 0; i < totalItensVetor - 1; i++) {
        for (int j = i + 1; j < totalItensVetor; j++) {
            if (strcmp(mochilaVetor[i].nome, mochilaVetor[j].nome) > 0) {
                Item temp = mochilaVetor[i];
                mochilaVetor[i] = mochilaVetor[j];
                mochilaVetor[j] = temp;
            }
        }
    }
    printf("\nVetor ordenado por nome.\n");
}

// Busca binária
void buscarBinariaVetor() {
    if (totalItensVetor == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    char nome[30];
    printf("\nNome para busca binaria: ");
    scanf("%s", nome);

    int inicio = 0, fim = totalItensVetor - 1;
    comparacoesBinaria = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        comparacoesBinaria++;

        int cmp = strcmp(nome, mochilaVetor[meio].nome);

        if (cmp == 0) {
            printf("\nItem encontrado! Nome: %s | Tipo: %s | Qtd: %d\n",
                   mochilaVetor[meio].nome,
                   mochilaVetor[meio].tipo,
                   mochilaVetor[meio].quantidade);
            printf("Comparacoes: %d\n", comparacoesBinaria);
            return;
        }

        if (cmp > 0) inicio = meio + 1;
        else fim = meio - 1;
    }

    printf("\nItem nao encontrado. Comparacoes: %d\n", comparacoesBinaria);
}

// -------------------------------------------
//                MENU PRINCIPAL
// -------------------------------------------

int main() {
    int op;

    do {
        printf("\n====================================\n");
        printf("      SISTEMA DE INVENTARIO ADS      \n");
        printf("====================================\n");
        printf("1 - Inserir item (vetor)\n");
        printf("2 - Remover item (vetor)\n");
        printf("3 - Listar itens (vetor)\n");
        printf("4 - Busca sequencial\n");
        printf("5 - Ordenar vetor por nome\n");
        printf("6 - Busca binaria\n");
        printf("0 - Sair\n");

        printf("\nEscolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: inserirItemVetor(); break;
            case 2: removerItemVetor(); break;
            case 3: listarItensVetor(); break;
            case 4: buscarSequencialVetor(); break;
            case 5: ordenarVetor(); break;
            case 6: buscarBinariaVetor(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (op != 0);

    return 0;
}
