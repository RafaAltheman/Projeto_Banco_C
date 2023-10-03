#include "projfunc.h"
#include <stdio.h>

void clearbuffer(){
   int c;
   while((c = getchar()) != '\n' && c != EOF);
}

int criarcliente(listadeclientes *c){
    if (c-> qtd <= 1000){
        clearbuffer();
        printf("Nome: ");
        scanf("%[^\n]s", c->clientes[c->qtd].nome);
        clearbuffer();
        printf("CPF: ");
        scanf("%[^\n]s", c->clientes[c->qtd].cpf);
        clearbuffer();
        printf("Tipo de conta: ");
        scanf("%[^\n]s", c->clientes[c->qtd].tipoconta);
        clearbuffer();
        printf("Valor inicial: ");
        scanf("%lf", &c->clientes[c->qtd].valori);
        clearbuffer();
        printf("Senha: ");
        scanf("%[^\n]s", c->clientes[c->qtd].senha);
        clearbuffer();
        c->qtd++;
        printf("Cliente cadastrado!\n");
     } else {
        printf("Número de clientes cadastrados ultrapassou o limite!\n");
     }
     return 0;
};


int apagacliente(listadeclientes *c, const char *cpf){
   int escolhido = 0;
   int x,y;
   clearbuffer();
   printf("Digite o CPF que deseja deletar: ");
   scanf("%d", &escolhido);
   clearbuffer();
   for (int i = 0; i < c -> qtd; i++){
      for(int x = 0; c -> clientes[i].cpf[x] != '\0' && cpf[x] != '\0'; x++){
         if(c -> clientes[i].cpf[x] != cpf[x]){
            break; // cpf diferente ele nâo realiza a operaçâo
         }
      }
      if (c -> clientes[i].cpf[x] == '\0' && cpf[x] == '\0'){
         escolhido = 1;
         for (int y = i; y < c-> qtd - 1; y++){
            c -> clientes[y] = c -> clientes[y+1];
         }
         c -> qtd--;
         printf("O cliente foi removido com sucesso!");
         break;
      }
   }
   if (!escolhido){
      printf("Cliente nâo encontrado. CPF inexistente");
   }
   return 0;
}


