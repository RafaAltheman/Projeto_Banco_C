#include <stdio.h>
#include <string.h>
#include "projfunc.h"

int main(){

    listadeclientes c;
    c.qtd = 0;

    int cod;
    char arquivo[] = "arquivo";

    carregarlista(&c, "arquivo.txt");
    
    while (1){
        int opcao;
        
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
            criarcliente(&c);
        } else if (opcao==2){
            char cpf[12];
            apagacliente(&c,cpf);
        } else if (opcao==3){
            listacliente(c);
        } else if (opcao==4){
            debitacliente(&c);
        } else if (opcao==5){
            depositacliente(&c);
        } else if (opcao==6){
            extrato(&c, "arquivoextrato.txt");
        } else if (opcao==7){
            transferencia(&c);
        } else if (opcao==0){
            salvar(&c, "arquivo.txt");
            break;
    } 
    }
    cod = salvar(&c,arquivo); //Salva as informações na lista
    if (cod !=0) //Se o "return" for diferente de zero, o cliente não é cadastrada
        printf("Erro ao cadastrar os clientes!");
}