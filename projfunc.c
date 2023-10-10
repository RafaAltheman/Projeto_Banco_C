#include "projfunc.h"
#include <stdio.h>
#include <string.h>

void clearbuffer(){
   int c;
   while((c = getchar()) != '\n' && c != EOF);
}

int criarcliente(listadeclientes *c){
    if (c-> qtd < 1000){
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
        scanf("%2lf", &c->clientes[c->qtd].valori);
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
   char cpf_deletar[12];
   clearbuffer();
   printf("Digite o CPF que deseja deletar: ");
   scanf("%s", cpf_deletar);
   clearbuffer();
   for (int i = 0; i < c->qtd; i++) {
      if (strcmp(c->clientes[i].cpf, cpf) == 0) {
         escolhido = 1;
         if (i < c-> qtd -1){
            c -> clientes[i] = c -> clientes[c->qtd -1];
         }
         c->qtd--;
         printf("O cliente foi removido com sucesso!\n");
         break;
      }
   }
   if (!escolhido) {
      printf("Cliente não encontrado. CPF inexistente.\n");
   }

   return 0;
}

int listacliente(listadeclientes c){
   if (c.qtd == 0) {
        printf("A lista de clientes esta vazia.\n");
    } else {
        printf("Lista de Clientes:\n");
        for (int i = 0; i < c.qtd; i++) {
            printf("Nome %s:\n", c.clientes[i].nome);
            printf("CPF: %s\n", c.clientes[i].cpf); 
            printf("Tipo de conta: %s\n", c.clientes[i].tipoconta); 
            printf("Valor inicial: %lf\n", c.clientes[i].valori); 
            printf("Senha: %s\n", c.clientes[i].senha);
            printf("\n"); 
        }
    }
    return 0;
}

int debitacliente(listadeclientes *c){
   char cpfdestinatario[12];
   float valordebito;
   clearbuffer();
   printf("CPF: ");
   scanf("%[^\n]s", c->clientes[c->qtd].cpf);
   clearbuffer();
   printf("Senha: ");
   scanf("%[^\n]s", c->clientes[c->qtd].senha);
   clearbuffer();
   printf("CPF do Destinatário: ");
   scanf("%[^\n]s",cpfdestinatario);
   clearbuffer();
   for(int i=0; i<c->qtd; i++){
      int j;
      for(j=0; c->clientes[i].cpf[j] !='\0' && c->clientes[i].cpf[j]!='\0'; j++){
         if(c->clientes[i].cpf[j] != c->clientes[i].cpf[j]){
            break;
         }
      }
      if(c->clientes[i].cpf[j] == '\0' && c->clientes[i].cpf[j] == '\0'){
         clearbuffer();
         printf("CPF do destinatário: ");
         scanf("%[^\n]s", c->clientes[c->qtd].cpf);
         clearbuffer();
         printf("Valor a ser debitado: ");
         scanf("%3f", &valordebito);
         

      }
   }
}

/////////////////////////////////////////////////

int salvar(listadeclientes *c, char nome[]){
   FILE *f = fopen(nome, "wb");
   if (f == NULL){
      printf("Erro ao abrir o arquivo. \n");
      return 1;
   }
   fwrite(c, sizeof(listadeclientes), 1, f);
   fclose(f);
   return 0;
}

int carregarlista(listadeclientes *c, char nome[]){ 
    FILE *f = fopen(nome, "rb"); 
    if (f == NULL) {
        printf("Arquivo nao encontrado.\n"); 
        return 1;
    }
    fread(c, sizeof(listadeclientes), 1, f);
    fclose(f); 
    return 0;
}
