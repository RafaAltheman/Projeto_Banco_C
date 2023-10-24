// Rafaela Altheman de Campos (24.123.010-1) e Manuella Filipe Peres (24.123.036-6)
typedef struct{ // Definição de uma estrutura 'historico' para armazenar informações que irao aparecer no extrato de cada cliente.
    double valor; 
    double taxa;
    char descricao[15];
}historico; 

typedef struct{  // Definição de uma estrutura 'cliente' para armazenar informações de cada cliente e a quantidade de operações que ele realizou. 
    char nome[100];
    char cpf[12];
    char tipoconta[30];
    double valori;
    char senha[20];
    historico operacoes[100];
    int quantidadeop;
}cliente; 

typedef struct { // Definição de uma estrutura 'listadeclientes' para armazenar uma lista de clientes que tem limite de armazenar no máximo 1000 clientes.
    cliente clientes[1000];
    int qtd;
} listadeclientes;

void clearbuffer(); // limpa o buffer de entrada, para que o scanf funcione de forma correta.
int criarcliente(listadeclientes *c); // declaração da função de criar cliente
int apagacliente(listadeclientes *c,const char *cpf); // declaração da função de apaga cliente
int listacliente(listadeclientes c); // declaração da função de listar clientes 
int debitacliente(listadeclientes *c); // declaração da função de debita cliente
int depositacliente(listadeclientes *c); // declaração da função de deposita cliente
int extrato(listadeclientes *c, char nome[]); // declaração da função de salvar as informaçoes do extrato
int transferencia(listadeclientes *c); // declaração da função de tranferencia entre contas.
int salvar(listadeclientes *c, char nome[]); // declaração da função de salvar as informaçoes no arquivo
int carregarlista(listadeclientes *c, char nome[]); // declaração da função de carregar as informaçoes de cada cliente do arquivo
int buscacpfdeletar(listadeclientes *c, char cpf_deletar[]); // declaração da função de buscar um cpf para deletar um cliente específico
int achasenha(listadeclientes *c, char senha[]); // declaração da função de achar uma senha específica e conferí-la
int buscacpf(listadeclientes *c, char cpf_verificar[]); // declaração da função de buscar cpf para conferí-lo
int buscacpfdestino(listadeclientes *c, char cpf_destino[]); // declaração da função de buscar o cpf de destino da transferencia.
int gerarextrato(cliente c); // declaração da função de escrever as informaçoes das operacoes realizadas pelo cliente e mostrar no extrato
int modificaextrato(double valor, double taxa, char descricao[], cliente *c); // declaração da função de atualizar as informações do extrato
