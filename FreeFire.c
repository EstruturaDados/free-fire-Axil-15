#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO_MAX 10 // definir um tamanho p/ cadastro nao passar de 10 itens

// primeira struct para vetor
struct Item {
    char nome [30];
    char tipo [20];
    int quantidade;
};

// struct para lista encadeada
struct No {
    struct Item dados;  // armazena os dados do item
    struct No* proximo;  // ponteiro para o próximo nó
};

void inserirLista(struct No** mochila, struct Item novoItem);
void listarLista(struct No* mochila);
bool removerLista(struct No** mochila, const char* nome);
struct No* buscarLista(struct No* mochila, const char* nome);

//submenu vetor
void menuVetor(){
    struct Item meuItem[TAMANHO_MAX];
    int quantidadeItens = 0;
    int opcao;

    //criação do menu para a mochilar vetor com opcoes selecionaveis
    while (1){
        printf("\n--- MENU (Vetor) ---\n");
        printf("1. Cadastrar item\n");
        printf("2. Listar itens\n");
        printf("3. Excluir itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
       
        if (opcao == 1){
            if (quantidadeItens >= TAMANHO_MAX){
                printf("Limite de itens atingido!\n");
                continue;
            }
            printf("\n--- Cadastro do item %d ---\n", quantidadeItens + 1);
            printf("Nome: ");
            getchar(); // limpa buffer do teclado
            fgets(meuItem[quantidadeItens].nome, sizeof (meuItem[quantidadeItens].nome), stdin); //permite espaços
            meuItem[quantidadeItens].nome[strcspn(meuItem[quantidadeItens].nome, "\n")] = '\0'; // remove '\n'
           
            printf("Tipo: ");
            fgets(meuItem[quantidadeItens].tipo, sizeof (meuItem[quantidadeItens].tipo), stdin); //permite espaços
            meuItem[quantidadeItens].tipo[strcspn(meuItem[quantidadeItens].tipo, "\n")] = '\0'; // remove '\n'
           
            printf("Quantidade: ");
            scanf("%d", &meuItem[quantidadeItens]. quantidade);
           
            quantidadeItens++;
        }
        else if(opcao == 2){
            if(quantidadeItens == 0){
                printf("Nenhum item cadastrado.\n");
                continue;
            }
            printf("\n--- Itens Cadastrados ---\n");
            for (int i = 0; i <quantidadeItens; i++){
                printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n", i + 1, meuItem[i].nome, meuItem[i].tipo, meuItem[i].quantidade);
            }
           
        else if (opcao == 3){
            if (quantidadeItens == 0){
                printf("Nenhum item para excluir");
                continue;
            }
            int excluir;
            char nomeExcluir[30];
            printf("\nDigite o nome do item ou o número a excluir (1 a %d): ", quantidadeItens);
            getchar(); //limpa buffer
            fgets(nomeExcluir, sizeof(nomeExcluir), stdin);
            nomeExcluir[strcspn(nomeExcluir, "\n")] = '\0';
            
            // se for um numero
            if (isdigit(nomeExcluir[0])) {
                excluir = atoi(nomeExcluir); // converte para inteiro
                
                if (excluir < 1) {
                    printf("Número inválido! Digite um valor entre 1 e %d.\n", quantidadeItens);
                    continue;
                }    
           
            excluir --;
            //deslocar itens para "tapar buracos"
            for (int i = excluir; i < quantidadeItens - 1; i++){
                meuItem[i] = meuItem [i+1];
            }
            quantidadeItens --; //diminui quantidade de itens
            printf ("Item excluido com sucessso.\n");
            }
            
        // se for nome
        else{
            bool encontrado = false;
            for (int i = 0; i < quantidadeItens; i++) {
                if (strcmp(meuItem[i].nome, nomeExcluir) == 0){
                    for (int j = i; j <quantidadeItens - 1; j++){
                        meuItem[j] = meuItem[j + 1];
                    }
                    quantidadeItens--;
                    printf ("Item '%s' excluido com sucesso \n", nomeExcluir);
                    encontrado = true;
                    break;
                }
            }   
            if (!encontrado){
                printf ("Item '%s' não encontrado.\n", nomeExcluir);
            }
        }    
                
            
    }
        }
        else if (opcao == 0){
            printf ("Saindo...\n");
            break;
        }
        else {
            printf ("Opção inválida!");
        }

    }
}

void menuLista(){
    struct No* mochila = NULL;
    int opcao;

    while(1){
                printf("\n--- MENU (Lista Encadeada) ---\n");
        printf("1. Cadastrar item\n");
        printf("2. Listar itens\n");
        printf("3. Excluir itens\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        //adicionar as funcoes da lista
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
        } else if (opcaoPrincipal == 2) {
            menuLista();
        } else if (opcaoPrincipal == 0) {
            printf("Saindo...\n");
            break;
        } else {
            printf("Opção inválida!\n");
        }
    }

    return 0;
}
