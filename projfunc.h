typedef struct{
    char nome;
    char cpf;
    char tipoconta;
    float valori;
    char senha;
}cliente;

typedef struct {
    cliente clientes[1000];
    int qtd;
} listadeclientes;

int criarcliente(listadeclientes *c);
int apagacliente(listadeclientes *c);
int listacliente(listadeclientes *c);
int debitacliente(listadeclientes *c);
int depositacliente(listadeclientes *c);
int extrato(listadeclientes *c);
int transferencia(listadeclientes *c);
