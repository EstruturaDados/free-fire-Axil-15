#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define TAMANHO_MAX 10 // definir um tamanho p/ cadastro nao passar de 10 itens

// criação de struct para o programa
struct Item {
    char nome [30];
    char tipo [20];
    int quantidade;
};

int main (){
    struct Item meuItem[TAMANHO_MAX];
    int quantidadeItens = 0;
    int opcao;
   
   //criação do menu do programa com opcoes selecionaveis
    while (1){
        printf("\n--- MENU ---\n");
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
            scanf("%s", meuItem[quantidadeItens].nome); //nao perimite espaços
           
            printf("Tipo: ");
            scanf("%s", meuItem[quantidadeItens].tipo); //nao permite espaços
           
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
       
        }    
        else if (opcao == 3){
            if (quantidadeItens == 0){
                printf("Nenhum item para excluir");
                continue;
            }
            int excluir;
            printf("\nDigite p número do item a excluir (1 a %d): ", quantidadeItens);
            scanf ("%d", &excluir);
           
            if (excluir < 1 || excluir > quantidadeItens){
                printf ("Número invalido!\n");
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
        else if (opcao == 0){
            printf ("Saindo...\n");
            break;
        }
        else {
            printf ("Opção inválida!");
        }
    }
   

    return 0;
}
