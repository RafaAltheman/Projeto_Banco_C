# Projeto2_C
Rafaela Altheman de Campos (24.123.010-1) e Manuella Filipe Peres (24.123.036-6)

Projeto do backend de um banco em C, feito com o uso de funções que analisam o cpf, senha, e todas as operações realizadas pelo usuário.
A partir das informações, foram criadas funções que simulam todos os processos realizados por bancos, tendo as seguintes funções:
1. Criar Cliente
2. Apaga Cliente
3. Listar Cliente
4. Debitar
5. Depositar
6. Extrato
7. Transferência
0. Sair (para salvar as informações de todas as operações do cliente e encerrar sua sessão).
Ao realizar essas operações são levadas em conta alguns tópicos, sendo o principal o tipo de conta. Clientes com o tipo de conta "comum" possuem uma taxa de 5% em débitos e transferências e limite de -1000 reais e clientes com o tipo de conta "plus" possuem a taxa de 3% e limite de -5000 em suas respectivas contas.
Além disso, são verificados o cpf e senha tanto do remetente quanto do destinatário em algumas funções, evitando erros nas operações e garantindo a segurança dos nossos clientes.