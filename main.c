// Rafaela Altheman de Campos (24.123.010-1) e Manuella Filipe Peres (24.123.036-6)
#include <stdio.h>
#include <string.h>
#include "projfunc.h"

int main(){

    listadeclientes c;   // declara uma "listadeclientes" chamada de "c".
    c.qtd = 0;   // inicia a quantidade da lista com 0.

    int cod;   
    char arquivo[] = "arquivo";  // declara um arquivo com nome de "arquivo".

    carregarlista(&c, "arquivo.txt"); // Chama uma função do arquivo "projfunc.c" para carregar dados de um arquivo chamado "arquivo.txt".
    
    while (1){  // loop infinito para rodar o menu.
        int opcao; 
        // prints de como aparece as opção para o usuário.
        printf("Bem-vindo ao menu do banco QuemPoupaTem: ");
        printf("\n1. Novo Cliente\n");
        printf("2. Apagar Cliente\n");
        printf("3. Listar Clientes\n");
        printf("4. Débito\n");
        printf("5. Depósito\n");
        printf("6. Extrato\n");
        printf("7. Transfência entre contas\n");
        printf("0. Sair\n");

        printf("Escolha uma opção:");
        scanf("%d", &opcao);

        if (opcao==1){
            criarcliente(&c); // se o cliente escolher a ooção 1, chama a função "criarcliente".
        } else if (opcao==2){
            char cpf[12]; 
            apagacliente(&c,cpf); // Se o cliente escolher a ooção 2, chama a função "apagacliente".
        } else if (opcao==3){
            listacliente(c);  // Se o cliente escolher a ooção 3, chama a função "listarcliente".
        } else if (opcao==4){
            debitacliente(&c); // Se o cliente escolher a ooção 4, chama a função "debitacliente".
        } else if (opcao==5){
            depositacliente(&c); // Se o cliente escolher a ooção 5, chama a função "depositacliente".
        } else if (opcao==6){
            extrato(&c, "arquivoextrato.txt"); // Se o cliente escolher a ooção 6, chama a função "extrato".
        } else if (opcao==7){
            transferencia(&c); // Se o cliente escolher a ooção 7, chama a função "transferencia".
        } else if (opcao==0){
            salvar(&c, "arquivo.txt"); // Se o cliente escolher a ooção 0, chama a função "salvar".
            break;
    } 
    }
    cod = salvar(&c,arquivo); //Salva as informações na lista
    if (cod !=0) //Se o "return" for diferente de zero, o cliente não é cadastrado
        printf("Erro ao cadastrar os clientes!");
}