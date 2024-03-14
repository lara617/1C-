#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// Estrutura para armazenar os detalhes de um produto
struct Produto {
    string nome;
    double precoCompra;
    double precoVenda;
    int quantidadeEstoqueInicial;
    int quantidadeVendida;
    int quantidadeAdicionada;
};

// Estrutura para armazenar o caixa
struct Caixa {
    int notas5;
    int notas10;
    int notas20;
    int moedas1;
    int moedas5;
    int moedas10;
    int moedas25;
    int moedas50;
};

// Função para exibir os detalhes dos produtos em forma de tabela
void exibirTabelaProdutos(Produto produtos[], int size) {
    cout << "Detalhes dos produtos:" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Nome" << setw(20) << "Preço Compra" << setw(20) << "Preço Venda" << setw(25) << "Quantidade Stock" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < size; i++) {
        Produto p = produtos[i];
        int estoqueAtual = p.quantidadeEstoqueInicial - p.quantidadeVendida + p.quantidadeAdicionada;

        cout << setw(15) << left << p.nome << setw(20) << fixed << setprecision(2) << p.precoCompra << setw(20) << p.precoVenda << setw(25) << estoqueAtual << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
}

// Função para verificar se há troco suficiente na caixa
bool verificarTrocoSuficiente(double troco, Caixa &caixa) {
    // Calcular o valor total em caixa
    double totalCaixa = caixa.notas5 * 5 + caixa.notas10 * 10 + caixa.notas20 * 20 + caixa.moedas1 + caixa.moedas5 * 0.05 + caixa.moedas10 * 0.10 + caixa.moedas25 * 0.25 + caixa.moedas50 * 0.50;

    return troco <= totalCaixa;
}

// Função para realizar a compra dos produtos
void comprarProdutos(Produto produtos[], int size, double &lucroTotal, Caixa &caixa) {
    string entrada;
    cout << "Digite o número do produto(s) que deseja comprar (ou 0 para sair), separados por espaço: ";
    cin.ignore();
    getline(cin, entrada);

    if (entrada == "0") {
        return;
    }

    stringstream ss(entrada);
    vector<int> produtosEscolhidos;
    int produto;
    while (ss >> produto) {
        produtosEscolhidos.push_back(produto);
    }

    double valorTotalAPagar = 0.0;

    for (int produto : produtosEscolhidos) {
        if (produto >= 1 && produto <= size) {
            int quantidade;
            cout << "Digite a quantidade que deseja comprar do produto " << produto << ": ";
            cin >> quantidade;

            Produto &produtoEscolhido = produtos[produto - 1];
            int estoqueDisponivel = produtoEscolhido.quantidadeEstoqueInicial - produtoEscolhido.quantidadeVendida + produtoEscolhido.quantidadeAdicionada;

            if (quantidade <= estoqueDisponivel) {
                double valorAPagar = quantidade * produtoEscolhido.precoVenda;
                lucroTotal += (produtoEscolhido.precoVenda - produtoEscolhido.precoCompra) * quantidade;

                produtoEscolhido.quantidadeVendida += quantidade;

                valorTotalAPagar += valorAPagar;

                cout << "Compra do produto " << produto << " realizada com sucesso." << endl;
            } else {
                cout << "Stock insuficiente. Quantidade disponível para o produto " << produto << ": " << estoqueDisponivel << endl;
            }
        } else {
            cout << "Opção inválida para o produto: " << produto << endl;
        }
    }

    // Mostrar o valor total a ser pago pelo cliente
    cout << "Valor total a ser pago: R$" << fixed << setprecision(2) << valorTotalAPagar << endl;

    // Receber o valor pago
    double valorPago;
    cout << "Digite o valor total pago pelo cliente: ";
    cin >> valorPago;

    // Calcular e exibir o troco
    double troco = valorPago - valorTotalAPagar;
    if (troco >= 0) {
        cout << "Troco a ser devolvido: R$" << fixed << setprecision(2) << troco << endl;

        // Verificar se há troco suficiente na caixa
        if (verificarTrocoSuficiente(troco, caixa)) {
            cout << "Troco suficiente na caixa." << endl;
        } else {
            cout << "Troco insuficiente na caixa. O cliente precisa pagar com valor exato ou com um valor menor." << endl;
        }
    } else {
        cout << "Valor insuficiente. Faltam R$" << fixed << setprecision(2) << -troco << " para completar o pagamento." << endl;
    }
}

// Função para exibir o lucro total e o lucro por produto
void exibirLucro(Produto produtos[], int size, double lucroTotal) {
    cout << "Lucro total: R$" << fixed << setprecision(2) << lucroTotal << endl;
    cout << "Lucro por produto:" << endl;
    for (int i = 0; i < size; ++i) {
        Produto &produto = produtos[i];
        double lucroProduto = (produto.precoVenda - produto.precoCompra) * produto.quantidadeVendida;
        cout << produto.nome << ": R$" << fixed << setprecision(2) << (produto.quantidadeVendida > 0 ? lucroProduto : 0.0) << endl;
    }
}

// Função principal para iniciar o sistema
void iniciarSistema(Produto produtos[], int size) {
    bool continuar = true;
    double lucroTotal = 0.0; // Variável para armazenar o lucro total

    // Caixa inicial
    Caixa caixa = {3, 4, 1, 100, 10, 20, 50, 30}; // Exemplo: 3 notas de 5, 4 de 10, 1 de 20, 100 moedas de 1 real, 10 de 5 centavos, 20 de 10 centavos, 50 de 25 centavos, 30 de 50 centavos

    // Exibição dos detalhes dos produtos em forma de tabela
    exibirTabelaProdutos(produtos, size);

    while (continuar) {
        // Opções iniciais
        int opcao;
        cout << "\n1. Comprar produto\n2. Ver o lucro\n3. Ver o stock\n4. Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                comprarProdutos(produtos, size, lucroTotal, caixa);
                break;
            case 2:
                exibirLucro(produtos, size, lucroTotal);
                break;
            case 3:
                exibirTabelaProdutos(produtos, size);
                break;
            case 4:
                continuar = false;
                cout << "Sistema encerrado." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }
}

int main() {
    // Definição dos produtos
    Produto produtos[5] = {
        {"1-Caderno", 2.00, 5.00, 50, 20, 0},
        {"2-Borracha", 0.20, 0.50, 100, 50, 30},
        {"3-Caneta", 0.50, 1.50, 100, 50, 30},
        {"4-Afia", 0.50, 1.00, 100, 53, 10},
        {"5-Lápis", 0.20, 1.00, 100, 50, 10}
    };

    iniciarSistema(produtos, 5);

    return 0;
}
