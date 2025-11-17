#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>   // necessário para isdigit()
#define TAMANHO_MAX 10

struct Item {
    char nome[30];
    char tipo[20];
    int quantidade;
};

struct No {
    struct Item dados;
    struct No* proximo;
};

void inserirLista(struct No** mochila, struct Item novoItem);
void listarLista(struct No* mochila);
bool removerLista(struct No** mochila, const char* nome);
struct No* buscarLista(struct No* mochila, const char* nome);

void menuVetor() {
    struct Item meuItem[TAMANHO_MAX];
    int quantidadeItens = 0;
    int opcao;

    while (1) {
        printf("\n--- MENU (Vetor) ---\n");
        printf("1. Cadastrar item\n");
        printf("2. Listar itens\n");
        printf("3. Excluir itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            if (quantidadeItens >= TAMANHO_MAX) {
                printf("Limite de itens atingido!\n");
                continue;
            }

            printf("\n--- Cadastro do item %d ---\n", quantidadeItens + 1);
            printf("Nome: ");
            getchar();
            fgets(meuItem[quantidadeItens].nome, sizeof(meuItem[quantidadeItens].nome), stdin);
            meuItem[quantidadeItens].nome[strcspn(meuItem[quantidadeItens].nome, "\n")] = '\0';

            printf("Tipo: ");
            fgets(meuItem[quantidadeItens].tipo, sizeof(meuItem[quantidadeItens].tipo), stdin);
            meuItem[quantidadeItens].tipo[strcspn(meuItem[quantidadeItens].tipo, "\n")] = '\0';

            printf("Quantidade: ");
            scanf("%d", &meuItem[quantidadeItens].quantidade);

            quantidadeItens++;
        }

        else if (opcao == 2) {
            if (quantidadeItens == 0) {
                printf("Nenhum item cadastrado.\n");
                continue;
            }

            printf("\n--- Itens Cadastrados ---\n");
            for (int i = 0; i < quantidadeItens; i++) {
                printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
                       i + 1, meuItem[i].nome, meuItem[i].tipo, meuItem[i].quantidade);
            }
        }

        else if (opcao == 3) {
            if (quantidadeItens == 0) {
                printf("Nenhum item para excluir\n");
                continue;
            }

            int excluir;
            char nomeExcluir[30];

            printf("\nDigite o nome do item ou o número a excluir (1 a %d): ", quantidadeItens);
            getchar();
            fgets(nomeExcluir, sizeof(nomeExcluir), stdin);
            nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0';

            if (isdigit(nomeExcluir[0])) {
                excluir = atoi(nomeExcluir);

                if (excluir < 1 || excluir > quantidadeItens) {
                    printf("Número inválido! Digite um valor entre 1 e %d.\n", quantidadeItens);
                    continue;
                }

                excluir--;

                for (int i = excluir; i < quantidadeItens - 1; i++) {
                    meuItem[i] = meuItem[i + 1];
                }

                quantidadeItens--;
                printf("Item excluido com sucessso.\n");
            }

            else {
                bool encontrado = false;
                for (int i = 0; i < quantidadeItens; i++) {
                    if (strcmp(meuItem[i].nome, nomeExcluir) == 0) {

                        for (int j = i; j < quantidadeItens - 1; j++) {
                            meuItem[j] = meuItem[j + 1];
                        }

                        quantidadeItens--;
                        printf("Item '%s' excluido com sucesso \n", nomeExcluir);
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    printf("Item '%s' não encontrado.\n", nomeExcluir);
                }
            }
        }

        else if (opcao == 0) {
            printf("Saindo...\n");
            break;
        }

        else {
            printf("Opção inválida!");
        }
    }
}

void menuLista() {
    struct No* mochila = NULL;
    int opcao;

    while (1) {
        printf("\n--- MENU (Lista Encadeada) ---\n");
        printf("1. Cadastrar item\n");
        printf("2. Listar itens\n");
        printf("3. Excluir itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // você ainda vai implementar essas funções aqui
        if (opcao == 0) {
            printf("Saindo...\n");
            break;
        }
    }
}

int main() {
    int opcaoPrincipal;

    while (1) {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1. Mochila com vetor\n");
        printf("2. Mochila com lista encadeada\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoPrincipal);

        if (opcaoPrincipal == 1) {
            menuVetor();
        } 
        else if (opcaoPrincipal == 2) {
            menuLista();
        } 
        else if (opcaoPrincipal == 0) {
            printf("Saindo...\n");
            break;
        } 
        else {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
