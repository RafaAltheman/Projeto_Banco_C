// Rafaela Altheman de Campos (24.123.010-1) e Manuella Filipe Peres (24.123.036-6)
#include "projfunc.h"
#include <stdio.h>
#include <string.h>

void clearbuffer(){ //função que limpa o buffer de entrada para receber novas informações do usuário
   int c; 
   while((c = getchar()) != '\n' && c != EOF); 
}

int criarcliente(listadeclientes *c){ //função de criar cliente
    if (c-> qtd < 1000){ // determina um limite de 1000 clientes como máximo para a lista.
        clearbuffer();
        printf("Nome: "); 
        scanf("%[^\n]s", c->clientes[c->qtd].nome); // Pede o nome do cliente e guarda na variável "nome" do struct "cliente".
        clearbuffer();
        printf("CPF: ");
        scanf("%[^\n]s", c->clientes[c->qtd].cpf); // Pede o cpf do cliente e guarda na variável "cpf" do struct "cliente".
        clearbuffer();
        printf("Tipo de conta: ");
        scanf("%[^\n]s", c->clientes[c->qtd].tipoconta); // Pede o tipo de conta do cliente e guarda na variável "tipoconta" do struct "cliente".
        clearbuffer();
        printf("Valor inicial: ");
        scanf("%lf", &c->clientes[c->qtd].valori); // Pede o valor inicial do cliente e guarda na variável "valori" do struct "cliente".
        clearbuffer();
        printf("Senha: ");
        scanf("%[^\n]s", c->clientes[c->qtd].senha); // Pede o senha do cliente e guarda na variável "senha" do struct "cliente".
        clearbuffer();
        c->qtd++; // Soma um cliente na lista
        printf("Cliente cadastrado!\n");
     } else { // caso já tenha atingido o limite de 1000, esta mensagem aparece
        printf("Número de clientes cadastrados ultrapassou o limite!\n");
     }
     return 0;
};


int apagacliente(listadeclientes *c, const char *cpf){ //função de apagar o cliente
   int escolhido = 0;
   char cpf_deletar[12]; // declara o cpf do cliente que quer ser deletado.
   clearbuffer();
   printf("Digite o CPF que deseja deletar: ");
   scanf("%s", cpf_deletar); // pede o cpf que deseja deletar 
   int indice = buscacpfdeletar(c, cpf_deletar); // chama a função buscacpfdeletar para comparar o cpf original com o que quer ser deletado 

    if (indice != -1) { // se a funcao de buscacpfdeletar não retornar -1, o programa roda
        for (int i = indice; i < c->qtd - 1; i++) { // ele itera na quantidade de clientes e apaga um da quantidade
            c->clientes[i] = c->clientes[i + 1]; // Apos apagá-lo, o cliente abaixo do apagado, sobe uma posição na lista de clientes.
        }
        c->qtd--; // retira um elemento da lista de clientes
        printf("Cliente com CPF %s apagado com sucesso.\n", cpf_deletar);
    } else {
        printf("CPF %s não encontrado na lista de clientes.\n", cpf_deletar); // caso a função buscacpfdeletar não retornar -1, o cpf ta errado e o programa não roda
    }
}

int listacliente(listadeclientes c){ //função de listar clientes
   if (c.qtd == 0) { // se a quantidade de clientes na lista for 0, o programa exibe a mensagem de lista vazia.
        printf("A lista de clientes esta vazia.\n");
    } else {
        printf("Lista de Clientes:\n");
        for (int i = 0; i < c.qtd; i++) { // itera sobre a quantidade de clientes
            printf("Nome: %s\n", c.clientes[i].nome); // chama o nome que esta no struct na posição que esta na lista do cliente selecionado
            printf("CPF: %s\n", c.clientes[i].cpf); // chama o cpf que esta no struct na posição que esta na lista do cliente selecionado
            printf("Tipo de conta: %s\n", c.clientes[i].tipoconta); // chama o tipo de conta que esta no struct na posição que esta na lista do cliente selecionado
            printf("Valor: %lf\n", c.clientes[i].valori); // chama o valor inicial que esta no struct na posição que esta na lista do cliente selecionado
            printf("Senha: %s\n", c.clientes[i].senha); // chama o senha que esta no struct na posição que esta na lista do cliente selecionado
            printf("\n"); 
        }
    }
    return 0;
}

int debitacliente(listadeclientes *c){ //função para debitar um valor da conta selecionada a partir do cpf e senha
   char senha_verificar[20]; //variável que será utilizada para comparar a senha do usuário
   char cpf_verificar[12]; //variável que será utilizada para comparar o cpf do usuário
   float valor_debitado; //variável que determina o valor a ser debitado

   clearbuffer();
   printf("Digite o CPF: ");
   scanf("%s", cpf_verificar); // pede o cpf do cliente para ser verificado posteriormente
   clearbuffer();
   printf("Digite a senha: ");
   scanf("%s", senha_verificar); // pede a senha do cliente para ser verificada posteriormente

   int cpfencontrado = buscacpf(c, cpf_verificar); //chama a função buscacpf para conferir o cpf

   if(cpfencontrado != -1 && strcmp(c->clientes[cpfencontrado].senha, senha_verificar)==0){ //verifica se o cpf e a senha estão corretos, caso positivo, o programa roda
      printf("Usuário localizado! Digite o valor a ser debitado: "); 
      scanf("%f", &valor_debitado); //guarda o valor a ser debitado na variável valor_debitado
      if(strcmp(c->clientes[cpfencontrado].tipoconta , "comum")==0){ // caso a conta for comum, entra nesse laço
         if(c->clientes[cpfencontrado].valori >= valor_debitado){ //se o valor inicial for maior que o valor debitado, o laço é acionado
            float taxa = valor_debitado * 0.05; //declaração da taxa de 5% para clientes comuns
            if(c->clientes[cpfencontrado].valori - valor_debitado - taxa >= -1000){ //caso o valor total da conta após o debito for menor que -1000 reais a transação não ocorre
               c->clientes[cpfencontrado].valori -= valor_debitado;//se o valor estiver dentro do limite, o valor é debitado
               c->clientes[cpfencontrado].valori -= taxa;//aplica a taxa no valor debitado
               modificaextrato(valor_debitado,taxa,"Débito", &c->clientes[cpfencontrado]); //atualiza esta operação no extrato com base no valor debitado
            printf("Debito realizado com sucesso!\n");
            }
         }else {
            printf("Saldo insuficiente para realizar a transação\n"); //caso o valor esteja fora do limite, não é realizado o débito
         }
      }else if (strcmp(c->clientes[cpfencontrado].tipoconta, "plus")==0){  //caso a conta for plus, entra nesse laço
         float taxa = valor_debitado * 0.03; //declara a taxa de 3% para clientes plus
         if(c->clientes[cpfencontrado].valori - valor_debitado - taxa >= -5000){ //caso o valor total da conta após o debito for menor que -5000 reais a transação não ocorre
            c->clientes[cpfencontrado].valori -= valor_debitado;//se o valor estiver dentro do limite, o valor é debitado
            c->clientes[cpfencontrado].valori -= taxa;//aplica a taxa no valor debitado
            modificaextrato(valor_debitado,taxa,"Débito", &c->clientes[cpfencontrado]); //atualiza esta operação no extrato com base no valor debitado
            printf("Debito realizado com sucesso!\n");
         }else{
            printf("Saldo insuficiente para realizar a transação\n"); //caso o valor esteja fora do limite, não é realizado o débito
         }
      }
      }
   else{
         printf("CPF ou senha incorretos!\n"); //caso a senha ou cpf estiverem errados, essa mensagem aparece e não é realizado o débito
      }
}

int depositacliente(listadeclientes *c){ //função de depositar um valor na conta selecionada a partir do cpf indicado
   char cpf_verificar[12]; //declaração da variável de verificar cpf
   double valor; //declaração da variável do valor a ser debitado

   clearbuffer();
   printf("Digite o CPF: ");//pede o cpf
   scanf("%s", cpf_verificar);//guarda o cpf digitado na variável para verificar posteriormente
   
   int cpfencontrado = buscacpf(c, cpf_verificar); //chama a função que verifica o cpf

   if(cpfencontrado != -1){ //caso a função não retorne -1 (indica que o cpf está correto) o programa roda
      printf("Usuário localizado! Digite o valor a ser depositado: ");
      scanf("%lf", &valor); //pede o valor a ser depositado e guarda na variável valor
         if(valor > 0){ //se o valor for maior que 0 acontece o depósito
            c->clientes[cpfencontrado].valori += valor; //deposita o valor
            modificaextrato(valor,0,"Deposito", &c->clientes[cpfencontrado]); //atualiza esta operação no extrato com base no valor depositado
            printf("Deposito realizado com sucesso!\n");
         } else {
            printf("Digite um valor maior que 0."); //caso o valor for menor que 0 o depósito não é feito e aparece essa mensagem
         }
      }else{
         printf("CPF incorretos!\n"); //caso o cpf estiver incorreto o depósito não é feito e aparece essa mensagem
      }
}

int extrato(listadeclientes *c, char nome[]){ //função de extrato do cliente a partir da senha e cpf desse
   char senha_verificar[20]; //declaração da variável de verificar senha
   char cpf_verificar[12]; //declaração da variável de verificar cpf
   float valor_transferencia; //declaração da variável do valor da transferencia

   clearbuffer();
   printf("Digite o CPF: ");
   scanf("%s", cpf_verificar); //guarda o cpf digitado na variável para verificar posteriormente
   clearbuffer();
   printf("Digite a senha: ");
   scanf("%s", senha_verificar); //guarda a senha digitado na variável para verificar posteriormente
   
   int cpfencontrado = buscacpf(c, cpf_verificar); //chama a função que verifica o cpf

   if (cpfencontrado != -1 && strcmp(c->clientes[cpfencontrado].senha, senha_verificar)==0){ //caso a função não retorne -1 (indica que o cpf está correto após verificar) e a partir da ferramenta da biblioteca de comparar strings (strcmp) verifica se a senha está correta, caso as duas estejam corretas o programa roda
      gerarextrato(c->clientes[cpfencontrado]); //puxa a função gerar extrato, criando um novo arquivo para o cliente
   }
   else{
      printf("CPF ou senha errado!"); //caso o cpf ou a senha estejam errados, o extrato não é realizado e aparece essa mensagem
   }
}

int transferencia(listadeclientes *c){ //função de transferência a partir do cpf e senha do remetente para o cpf do destinatário
   char senha_verificar[20]; //declaração da variável de verificar senha
   char cpf_verificar[12]; //declaração da variável de verificar o cpf do remetente
   char cpf_destino[12]; //declaração da variável de verificar o cpf do destino
   float valor_transferencia; //declaração da variável do valor da transferencia

   clearbuffer();
   printf("Digite o CPF de origem: ");
   scanf("%s", cpf_verificar); //guarda o cpf (do remetente) digitado na variável para verificar posteriormente
   clearbuffer();
   printf("Digite a senha: ");
   scanf("%s", senha_verificar); //guarda a senha digitada na variável para verificar posteriormente
   clearbuffer();
   printf("Digite o CPF do destinatário: ");
   scanf("%s", cpf_destino); //guarda o cpf (do destinatario) digitado na variável para verificar posteriormente

   int cpfencontrado = buscacpf(c, cpf_verificar); //chama a função que verifica o cpf do remetente
   int cpfdestino = buscacpfdestino(c, cpf_destino); //chama a função que verifica o cpf do destinatário

   if(cpfencontrado != -1 && strcmp(c->clientes[cpfencontrado].senha, senha_verificar)==0 && cpfdestino != -1){  //caso as funções não retornem -1 (indica que o cpf tanto do remetente quanto do destinatário estão corretos após verificar) e a partir da ferramenta da biblioteca de comparar strings (strcmp) verifica se a senha do remetente está correta, caso as duas estejam corretas o programa roda
      printf("Usuários localizados! Digite o valor a ser transferido: "); //pede o valor a ser transferido
      scanf("%f", &valor_transferencia); //guarda o valor na variável valor_transferencia
      if(strcmp(c->clientes[cpfencontrado].tipoconta , "comum")==0){ //checa se o tipo de conta é comum
         float taxa = valor_transferencia * 0.05; //aplica a taxa de 5% caso for um cliente comum
         if(c->clientes[cpfencontrado].valori - valor_transferencia - taxa >= -1000){//caso o valor total da conta após o debito for menor que -1000 reais a transação não ocorre
            c->clientes[cpfencontrado].valori -= valor_transferencia; //se o valor estiver dentro do limite, o valor é debitado
            c->clientes[cpfencontrado].valori -= taxa; //aplica a taxa no valor debitado
            c->clientes[cpfdestino].valori += valor_transferencia; //adiciona o valor para a conta do destinatário
            modificaextrato(valor_transferencia,taxa,"Tranferência", &c->clientes[cpfencontrado]); //atualiza esta operação no extrato a partir das informações obtidas nas transferências
            printf("Transferência realizada com sucesso!\n");
         }else {
            printf("Saldo insuficiente para realizar a transação\n"); //caso o valor total ultrapasse o limite, não é realizada a transferência e aparece essa mensagem
         }
      } else if (strcmp(c->clientes[cpfencontrado].tipoconta, "plus")==0){ //checa se o tipo de conta é plus
         float taxa = valor_transferencia * 0.03; //aplica a taxa de 3% caso for um cliente comum
         if(c->clientes[cpfencontrado].valori - valor_transferencia - taxa >= -5000){//caso o valor total da conta após o debito for menor que -5000 reais a transação não ocorre
            c->clientes[cpfencontrado].valori -= valor_transferencia; //se o valor estiver dentro do limite, o valor é debitado
            c->clientes[cpfencontrado].valori -= taxa; //aplica a taxa no valor debitado
            c->clientes[cpfdestino].valori += valor_transferencia; //adiciona o valor para a conta do destinatário
            modificaextrato(valor_transferencia,taxa,"Tranferência", &c->clientes[cpfdestino]); //atualiza esta operação no extrato a partir das informações obtidas nas transferências
            printf("Transferência realizada com sucesso!\n");
         }else {
            printf("Saldo insuficiente para realizar a transação\n"); //caso o valor total ultrapasse o limite, não é realizada a transferência e aparece essa mensagem
         }
         }
   } else {
      printf("Usuário não encontrado!\n"); //caso o cpf do remetente ou sua senha ou o cpf do destinatário estiverem incorretos a transferência não é realizada e aparece essa mensagem
   }
}

int salvar(listadeclientes *c, char nome[]){ //salvar as informações do cliente no arquivo binário quando ele escolher a opção sair no menu
   FILE *f = fopen(nome, "wb");  //abre um arquivo binário
   if (f == NULL){  //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
      printf("Erro ao abrir o arquivo. \n"); 
      return 1;
   }
   fwrite(c, sizeof(listadeclientes), 1, f); //escreve as informações do cliente no arquivo
   fclose(f); //fecha o arquivo
   return 0;
}

int carregarlista(listadeclientes *c, char nome[]){ //lê as informações do arquivo
    FILE *f = fopen(nome, "rb"); //abre o arquivo e lê ele em formato binário
    if (f == NULL) { //caso o arquivo f não abrir (não existir) aparece a seguinte mensagem
        printf("Arquivo nao encontrado.\n"); 
        return 1;
    }
    fread(c, sizeof(listadeclientes), 1, f); //escreve as informações do cliente no arquivo
    fclose(f); //fecha o arquivo
    return 0;
}

int buscacpfdeletar(listadeclientes *c, char cpf_deletar[]){ //função para buscar o cpf do cliente a partir do que for escrito no scanf, comparando-o com o já existente (feita para a função deletar) 
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) { //itera sobre a quantidade de clientes na lista
        if (strcmp(c->clientes[i].cpf, cpf_deletar) == 0) { //compara o cpf digitado com o já existente para ver se existe ou não
            return i;
     }
    }
   return -1;
}

int achasenha(listadeclientes *c, char senha_verificar[]){ //função para buscar a senha do cliente a partir do que for escrito no scanf, comparando-o com a já existente 
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) { //itera sobre a quantidade de clientes na lista
        if (strcmp(c->clientes[i].senha, senha_verificar) == 0) { //compara a senha digitada com a já existente para ver se existe ou não
            return i;
     }
    }
   return -1;
}

int buscacpf(listadeclientes *c, char cpf_verificar[]){ //função para buscar o cpf do cliente remetente a partir do que for escrito no scanf, comparando-o com a já existente 
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) { //itera sobre a quantidade de clientes na lista
        if (strcmp(c->clientes[i].cpf, cpf_verificar) == 0) { //compara o cpf digitado com a já existente para ver se existe ou não
            return i;
     }
    }
   return -1;
}

int buscacpfdestino(listadeclientes *c, char cpf_destino[]){ //função para buscar o cpf do cliente destinário a partir do que for escrito no scanf, comparando-o com a já existente 
   int encontrado = 0;
    for (int i = 0; i < c->qtd; i++) { //itera sobre a quantidade de clientes na lista
        if (strcmp(c->clientes[i].cpf, cpf_destino) == 0) { //compara o cpf digitado com a já existente para ver se existe ou não
            return i;
     }
    }
   return -1;
}

int gerarextrato(cliente c){ //função que escreve as informações do cliente no arquivo do extrato
   FILE *f = fopen("extrato.txt", "w"); //abre o arquivo com as informações obtidas
   
   for(int i=0; c.quantidadeop > i; i++){ // itera sobre a quantidade de operações realizadas pelo cliente e escreve a descrição, valor e taxas utilizadas com base no que foi salvo nas respectivas variáveis
      fprintf(f,"Descrição: %s\n", c.operacoes[i].descricao);
      
      fprintf(f,"Valor: %lf\n", c.operacoes[i].valor);
      fprintf(f,"Taxa: %lf\n", c.operacoes[i].taxa);
      fprintf(f,"\n");
   }

   fclose(f); //fecha o arquivo
   return 0;
}

int modificaextrato(double valor, double taxa, char descricao[], cliente *c){ //função para atualizar as informações do cliente no extrato quando a opção sair for selecionada
   if (c->quantidadeop > 99){ //se a quantidade de operações for menor que 100 é realizada a atualização das informações das operações do cliente e aumenta em um a quantidade na lista
      for(int i=0; i < c->quantidadeop - 1; i++){
         c->operacoes[i] = c->operacoes[ i + 1 ];
      }

   }

   c->operacoes[c->quantidadeop].valor = valor; //iguala o valor da operação ao valor que irá aparecer no extrato

   c->operacoes[c->quantidadeop].taxa = taxa; //iguala a taxa utilizada a que irá aparecer no extrato

   strcpy(c->operacoes[c->quantidadeop].descricao, descricao); //descreve qual a operação realizada no extrato a partir das informações guardadas na variável

   c->quantidadeop++; //aumenta a quantidade de operações na lista
}