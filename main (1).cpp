/******************************************************************************
Trabalho – Implementação de um Sistema de
Registro e Gestão de Contas Bancárias (ETAPA 2)

Aluno: João Lucas Ladeira dos Reis
Matricula: 28509
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

int main()
{
// Defini o limite máximo de 100 contas e 500 movimentações para caber tudo na memória
const int MAX_CONTAS = 100;
const int MAX_MOVIMENTACOES = 500;


// Variável que vai guardar a opção que eu digitar no menu
int opcao;

// Vetores para guardar os dados de todas as contas cadastradas
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];

// Aqui começa com zero contas cadastradas
int quantidadeContas = 0;

// Vetores para guardar o histórico das movimentações (saques, depósitos, etc.)
int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];
int quantidadeMovimentacoes = 0;

// Usei o do-while para o menu rodar pelo menos uma vez e continuar até eu escolher sair
do {
    cout << "***********************" << endl;
    cout << "** MENU - BANCO REIS **" << endl;
    cout << "***********************" << endl;
    cout << "1 - Cadastrar conta" << endl;
    cout << "2 - Listar contas" << endl;
    cout << "3 - Consultar conta" << endl;
    cout << "4 - Realizar deposito" << endl;
    cout << "5 - Realizar saque" << endl;
    cout << "6 - Realizar transferencia" << endl;
    cout << "7 - Exibir extrato" << endl;
    cout << "8 - Alterar tipo da conta" << endl;
    cout << "9 - Ativar/Desativar conta" << endl;
    cout << "10 - Sair" << endl;
    
    cout << "Digite uma opcao: ";
    cin >> opcao;
    
    switch(opcao) {
        
        // Opção 1: Aqui faço o cadastro de uma nova conta no sistema
    case 1:
        // Verifico se já bati o limite de 100 contas
        if (quantidadeContas >= MAX_CONTAS) {
            cout << "Limite maximo de contas atingido." << endl;
            break;
        }
            
        cout << "=== CADASTRO DE CONTA ===" << endl;
            
        // Valido se o número da conta é positivo
        do {
            cout << "Digite o numero da conta: ";
            cin >> numeroConta[quantidadeContas];
                
            if (numeroConta[quantidadeContas] <= 0) {
                cout << "Erro: o numero deve ser positivo." << endl;
            }
        } while (numeroConta[quantidadeContas] <= 0);
            
        cin.ignore();
            
        cout << "Digite o nome do titular: ";
        getline(cin, nomeCliente[quantidadeContas]);
            
        cout << "Digite o CPF do titular: ";
        cin >> cpf[quantidadeContas];
            
        // Valido o tipo de conta: 1 para Corrente ou 2 para Poupança
        do {
            cout << "Digite o tipo da conta (1 = Corrente, 2 = Poupanca): ";
            cin >> tipoConta[quantidadeContas];
                
            if (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                cout << "Erro: Tipo de conta inexistente." << endl;
            }
        } while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2);
            
        cout << "Digite o saldo inicial: ";
        cin >> saldo[quantidadeContas];
            
        // Toda conta nova já nasce ativa por padrão
        contaAtiva[quantidadeContas] = true;
            
        cout << "CONTA CADASTRADA COM SUCESSO." << endl;
        quantidadeContas++;
        break;
            
    // Opção 2: Mostro a lista com todas as contas que já cadastrei
    case 2:
    {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        cout << "\n----- LISTA DE CONTAS CADASTRADAS -----" << endl;
        for (int i = 0; i < quantidadeContas; i++) {
            cout << "Numero: " << numeroConta[i] << " | Titular: " << nomeCliente[i] << " | Saldo: R$ " << saldo[i];
        if (contaAtiva[i]) {
            cout << " | Status: Ativa" << endl;
        } else {
            cout << " | Status: Desativada" << endl;
                }
            }
        }
        break;
            
    // Opção 3: Procuro uma conta específica pelo número e exibo os dados dela
    case 3:
    {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        int numeroBusca;
        int posicao = -1;
                
        cout << "Digite o numero da conta para consulta: ";
        cin >> numeroBusca;
                
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == numeroBusca) {
            posicao = i;
        break;
            }
        }
                
        if (posicao == -1) {
            cout << "Conta nao encontrada." << endl;
        } else {
            cout << "----- DADOS DA CONTA -----" << endl;
            cout << "Numero da conta: " << numeroConta[posicao] << endl;
            cout << "Nome do titular: " << nomeCliente[posicao] << endl;
            cout << "CPF: " << cpf[posicao] << endl;
                    
            if (tipoConta[posicao] == 1) {
                cout << "Tipo: Corrente" << endl;
            } else {
                cout << "Tipo: Poupanca" << endl;
            }
                    
            cout << "Saldo: R$ " << saldo[posicao] << endl;
                    
            if (contaAtiva[posicao]) {
                cout << "Status: Ativa" << endl;
            } else {
                cout << "Status: Desativada" << endl;
                }
            }
        }
        break;
            
        // Opção 4: Faço o depósito somando no saldo e registrando no histórico
    case 4:
        {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        int numeroBusca;
        int posicao = -1;
        double valor;
                
        cout << "Digite o numero da conta para deposito: ";
        cin >> numeroBusca;
                
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == numeroBusca) {
            posicao = i;
         break;
            }
        }
                
        if (posicao == -1) {
            cout << "Conta nao encontrada." << endl;
        } else if (!contaAtiva[posicao]) {
            cout << "Erro: A conta esta desativada." << endl;
        } else {
            cout << "Digite o valor do deposito: ";
        cin >> valor;
                    
        if (valor <= 0) {
            cout << "Erro: O valor deve ser positivo." << endl;
        } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
            cout << "Erro: Limite de movimentacoes atingido." << endl;
        } else {
        // Atualizo o saldo e jogo o depósito 'D' lá no vetor de histórico
        saldo[posicao] = saldo[posicao] + valor;
                        
        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
        valorMovimentacao[quantidadeMovimentacoes] = valor;
        quantidadeMovimentacoes++;
                        
        cout << "DEPOSITO REALIZADO COM SUCESSO." << endl;
                }
            }
        }
            break;
            
    // Opção 5: Faço o saque conferindo se tenho saldo e registro a saída 'S'
    case 5:
        {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        int numeroBusca;
        int posicao = -1;
        double valor;
                
        cout << "Digite o numero da conta para saque: ";
        cin >> numeroBusca;
                
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == numeroBusca) {
            posicao = i;
        break;
            }
        }
                
        if (posicao == -1) {
            cout << "Conta nao encontrada." << endl;
        } else if (!contaAtiva[posicao]) {
            cout << "Erro: A conta esta desativada." << endl;
        } else {
            cout << "Digite o valor do saque: ";
        cin >> valor;
                    
        if (valor <= 0) {
            cout << "Erro: O valor deve ser positivo." << endl;
        } else if (valor > saldo[posicao]) {
            cout << "Erro: Saldo insuficiente." << endl;
        } else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
            cout << "Erro: Limite de movimentacoes atingido." << endl;
        } else {
        // Desconto do saldo e registro o saque no histórico
        saldo[posicao] = saldo[posicao] - valor;
                        
        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posicao];
        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
        valorMovimentacao[quantidadeMovimentacoes] = valor;
        quantidadeMovimentacoes++;
                        
        cout << "SAQUE REALIZADO COM SUCESSO." << endl;
                }
            }
        }
        break;
            
    // Opção 6: Faço a transferência entre duas contas gerando dois registros no histórico
    case 6:
        {
        if (quantidadeContas < 2) {
            cout << "Sao necessarias pelo menos duas contas cadastradas para transferencia." << endl;
        break;
        }
                
        int contaOrigem, contaDestino;
        int posOrigem = -1, posDestino = -1;
        double valor;
                
        cout << "Digite o numero da conta de origem: ";
        cin >> contaOrigem;
        cout << "Digite o numero da conta de destino: ";
        cin >> contaDestino;
                
        if (contaOrigem == contaDestino) {
            cout << "Erro: A conta de origem e destino nao podem ser a mesma." << endl;
        break;
        }
                
        // Acho onde estão a conta de origem e a de destino nos vetores
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == contaOrigem) {
        posOrigem = i;
            }
            if (numeroConta[i] == contaDestino) {
            posDestino = i;
            }
        }
                
        if (posOrigem == -1 || posDestino == -1) {
            cout << "Erro: Uma ou ambas as contas nao foram encontradas." << endl;
        } else if (!contaAtiva[posOrigem] || !contaAtiva[posDestino]) {
            cout << "Erro: Ambas as contas precisam estar ativas." << endl;
        } else {
        cout << "Digite o valor da transferencia: ";
        cin >> valor;
                    
        if (valor <= 0) {
            cout << "Erro: O valor deve ser positivo." << endl;
        } else if (valor > saldo[posOrigem]) {
            cout << "Erro: Saldo insuficiente na conta de origem." << endl;
        } else if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
            cout << "Erro: Espaco insuficiente no historico de movimentacoes." << endl;
        } else {
                
        // Mexo nos saldos: tiro da origem e ponho no destino
        saldo[posOrigem] = saldo[posOrigem] - valor;
        saldo[posDestino] = saldo[posDestino] + valor;
                        
        // Registro a saída na conta de origem ('S')
        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posOrigem];
        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
        valorMovimentacao[quantidadeMovimentacoes] = valor;
        quantidadeMovimentacoes++;
        
        // Registro a entrada na conta de destino ('D')
        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[posDestino];
        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
        valorMovimentacao[quantidadeMovimentacoes] = valor;
        quantidadeMovimentacoes++;
                            
        cout << "TRANSFERENCIA REALIZADA COM SUCESSO." << endl;
                }
            }
        }
        break;
            
    // Opção 7: Exibo o extrato filtrando apenas as movimentações daquela conta
    case 7:
        {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        int numeroBusca;
        int posicao = -1;
                
        cout << "Digite o numero da conta para exibir o extrato: ";
        cin >> numeroBusca;
            
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == numeroBusca) {
        posicao = i;
        break;
                }
            }
                
        if (posicao == -1) {
            cout << "Conta nao encontrada." << endl;
        } else {
        cout << "\n===== EXTRATO DA CONTA: " << numeroConta[posicao] << " =====" << endl;
        cout << "Titular: " << nomeCliente[posicao] << endl;
                    
        bool encontrouMovimentacao = false;
                    
        // Passo por todo o histórico procurando o que bate com essa conta
        for (int i = 0; i < quantidadeMovimentacoes; i++) {
        if (contaMovimentacao[i] == numeroConta[posicao]) {
        encontrouMovimentacao = true;
        if (tipoMovimentacao[i] == 'D') {
            cout << "Deposito: R$ " << valorMovimentacao[i] << endl;
        } else if (tipoMovimentacao[i] == 'S') {
            cout << "Saque: R$ " << valorMovimentacao[i] << endl;
                }
            }
        }
                    
        if (!encontrouMovimentacao) {
            cout << "Nenhuma movimentacao registrada para esta conta." << endl;
        }
                    
        cout << "Saldo atual: R$ " << saldo[posicao] << endl;
        cout << "===========================================" << endl;
            }
        }
        break;
            
    // Opção 8: Altero o tipo da conta (de corrente para poupança ou vice-versa)
    case 8:
        {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        int numeroBusca;
        int posicao = -1;
        int novoTipo;
        
        cout << "Digite o numero da conta: ";
        cin >> numeroBusca;
                
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == numeroBusca) {
        posicao = i;
        break;
            }
        }
                
        if (posicao == -1) {
            cout << "Conta nao encontrada." << endl;
        } else {
            cout << "Digite o novo tipo da conta (1 = Corrente, 2 = Poupanca): ";
        cin >> novoTipo;
                    
        if (novoTipo == 1 || novoTipo == 2) {
        tipoConta[posicao] = novoTipo;
            cout << "Tipo da conta alterado com sucesso." << endl;
        } else {
            cout << "Tipo de conta inexistente." << endl;
                }
            }
        }
        break;
            
        // Opção 9: Ativo ou desativo a conta invertendo o booleano
    case 9:
        {
        if (quantidadeContas == 0) {
            cout << "Nenhuma conta cadastrada." << endl;
        break;
        }
                
        int numeroBusca;
        int posicao = -1;
                
        cout << "Digite o numero da conta: ";
        cin >> numeroBusca;
                
        for (int i = 0; i < quantidadeContas; i++) {
            if (numeroConta[i] == numeroBusca) {
            posicao = i;
        break;
            }
        }
                
        if (posicao == -1) {
            cout << "Conta nao encontrada." << endl;
        } else {
            if (contaAtiva[posicao] == true) {
            contaAtiva[posicao] = false;
            cout << "Conta desativada com sucesso." << endl;
        } else {
            contaAtiva[posicao] = true;
            cout << "Conta ativada com sucesso." << endl;
                }
            }
        }
        break;
            
    // Opção 10: Encerro o loop e saio do programa
    case 10:
        cout << "SAINDO DO SISTEMA..." << endl;
        break;
            
        default:
            cout << "OPCAO INVALIDA." << endl;
            break;
    }
    
} while (opcao != 10);

return 0;



}