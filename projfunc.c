#include "projfunc.h"
#include <stdio.h>

int criarcliente(listadeclientes *c){
    if (c-> qtd <= 1000){
        printf("Nome: ");
        scanf("%[^]", c->clientes[c->qtd].nome);
        printf("CPF: ");
        scanf("%[^]", c->clientes[c->qtd].cpf);
        printf("Tipo de conta: ");
        scanf("%[^]", &c->clientes[c->qtd].tipoconta);
        printf("Valor inicial: ");
        scanf("%[^]", &c->clientes[c->qtd].valori);
        printf("Senha: ");
        scanf("%[^]", c->clientes[c->qtd].senha);
        c->qtd++;
        printf("Cliente cadastrado!\n");
     } else {
        printf("Número de clientes cadastrados ultrapassou o limite!\n");
     }
     return 0;
};
