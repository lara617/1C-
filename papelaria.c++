#include <iostream>
#include <iomanip>
#include <string>
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

// Função para vender um produto
void venderProduto(Produto& produto, int quantidade) {
    if (quantidade <= produto.quantidadeEstoqueInicial - produto.quantidadeVendida + produto.quantidadeAdicionada) {
        produto.quantidadeVendida += quantidade;
        cout << "Venda realizada com sucesso!" << endl;
    } else {
        cout << "Quantidade insuficiente em estoque." << endl;
    }
}

// Função para mostrar o estoque de um produto
void mostrarEstoque(const Produto& produto) {
    int estoqueAtual = produto.quantidadeEstoqueInicial - produto.quantidadeVendida + produto.quantidadeAdicionada;
    cout << "Quantidade em estoque do produto " << produto.nome << ": " << estoqueAtual << endl;
}

// Função para mostrar o lucro total de um produto
void mostrarLucroTotal(const Produto& produto) {
    double lucroTotal = (produto.precoVenda - produto.precoCompra) * (produto.quantidadeEstoqueInicial - produto.quantidadeVendida);
    cout << "Lucro total do produto " << produto.nome << ": €" << lucroTotal << endl;
}

// Função para comprar produto para repor o estoque
void comprarProduto(Produto& produto, int quantidade) {
    produto.quantidadeAdicionada += quantidade;
    cout << "Compra realizada com sucesso!" << endl;
}

int main() {
    // Definição dos produtos
    Produto produtos[5] = {
        {"1-Caderno", 2.00, 5.00, 60, 20, 10},
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

    // Exemplo de uso das funções
    Produto produtoSelecionado = produtos[3]; // Por exemplo, selecionamos o primeiro produto
    venderProduto(produtoSelecionado, 100); // Vender 10 unidades do produto selecionado
    mostrarEstoque(produtoSelecionado); // Mostrar o estoque atual do produto selecionado
    mostrarLucroTotal(produtoSelecionado); // Mostrar o lucro total do produto selecionado
    comprarProduto(produtoSelecionado, 30); // Comprar 30 unidades do produto selecionado para repor o estoque

    return 0;
}
