#include "projfunc.h"
#include <stdio.h>

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
        scanf("%.2lf", &c->clientes[c->qtd].valori);
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
         if()
         printf("Valor a ser debitado: ");
         scanf("%.3f", &valordebito);
         

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

