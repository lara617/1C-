#include <iostream>
#include <iomanip> // Para usar setw()
#include <string>
#include <map>
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

int main() {
    // Definição dos produtos
    Produto produtos[5] = {
        {"1-Caderno", 2.00, 5.00, 50, 20, 0},
        {"2-Borracha", 0.20, 0.50, 100, 50, 30},
        {"3-Caneta", 0.50, 1.50, 100, 50, 30},
        {"4-Afia", 0.50, 1.00, 100, 53, 10},
        {"5-Lápis", 0.20, 1.00, 100, 50, 10}
    };

    // Exibição dos detalhes dos produtos em forma de tabela
    cout << "Detalhes dos produtos:" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Nome" << setw(20) << "Preço Compra" << setw(20) << "Preço Venda" << setw(20) << "Lucro Total" << setw(25) << "Quantidade Stock" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++) {
        Produto p = produtos[i];
        int estoqueAtual = p.quantidadeEstoqueInicial - p.quantidadeVendida + p.quantidadeAdicionada;
        double lucroTotal = (p.precoVenda - p.precoCompra) * (p.quantidadeEstoqueInicial - p.quantidadeVendida);

        cout << setw(15) << left << p.nome << setw(20) << fixed << setprecision(2) << p.precoCompra << setw(20) << p.precoVenda << setw(20) << lucroTotal << setw(25) << estoqueAtual << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    return 0;
}