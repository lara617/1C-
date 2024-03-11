#include <iostream>
#include <string>
using namespace std;

int main() {
    // Definição das variáveis do produto 1
    string nomeProduto1 = "Caderno";
    double precoCompra1 = 0.50;
    double precoVenda1 = 0.70;
    int quantidadeEstoqueInicial1 = 50;
    int quantidadeVendida1 = 20;
    int quantidadeAdicionada1 = 0;

    // Cálculo do estoque atual do produto 1
    int estoqueAtual1 = quantidadeEstoqueInicial1 - quantidadeVendida1 + quantidadeAdicionada1;

    // Cálculo do lucro total do produto 1
    double lucroTotal1 = (precoVenda1 - precoCompra1) * (quantidadeEstoqueInicial1 - quantidadeVendida1);

    // Exibição dos detalhes do produto 1
    cout << "Detalhes do produto 1:" << endl;
    cout << "Nome: " << nomeProduto1 << endl;
    cout << "Preço de compra: €" << precoCompra1 << endl;
    cout << "Preço de venda: €" << precoVenda1 << endl;
    cout << "Lucro total: €" << lucroTotal1 << endl;
    cout << "Quantidade em estoque: " << estoqueAtual1 << endl << endl;

    // Definição das variáveis do produto 2
    string nomeProduto2 = "Borracha";
    double precoCompra2 = 0.20;
    double precoVenda2 = 0.30;
    int quantidadeEstoqueInicial2 = 100;
    int quantidadeVendida2 = 50;
    int quantidadeAdicionada2 = 30;

    // Cálculo do estoque atual do produto 2
    int estoqueAtual2 = quantidadeEstoqueInicial2 - quantidadeVendida2 + quantidadeAdicionada2;

    // Cálculo do lucro total do produto 2
    double lucroTotal2 = (precoVenda2 - precoCompra2) * (quantidadeEstoqueInicial2 - quantidadeVendida2);

    // Exibição dos detalhes do produto 2
    cout << "Detalhes do produto 2:" << endl;
    cout << "Nome: " << nomeProduto2 << endl;
    cout << "Preço de compra: €" << precoCompra2 << endl;
    cout << "Preço de venda: €" << precoVenda2 << endl;
    cout << "Lucro total: €" << lucroTotal2 << endl;
    cout << "Quantidade em estoque: " << estoqueAtual2 << endl << endl;

    // Definição das variáveis do produto 3
    string nomeProduto3 = "Caneta";
    double precoCompra3 = 0.25;
    double precoVenda3 = 0.30;
    int quantidadeEstoqueInicial3 = 100;
    int quantidadeVendida3 = 50;
    int quantidadeAdicionada3 = 30;

    // Cálculo do estoque atual do produto 3
    int estoqueAtual3 = quantidadeEstoqueInicial3 - quantidadeVendida3 + quantidadeAdicionada3;

    // Cálculo do lucro total do produto 3
    double lucroTotal3 = (precoVenda3 - precoCompra3) * (quantidadeEstoqueInicial3 - quantidadeVendida3);

    // Exibição dos detalhes do produto 3
    cout << "Detalhes do produto 3:" << endl;
    cout << "Nome: " << nomeProduto3 << endl;
    cout << "Preço de compra: €" << precoCompra3 << endl;
    cout << "Preço de venda: €" << precoVenda3 << endl;
    cout << "Lucro total: €" << lucroTotal3 << endl;
    cout << "Quantidade em estoque: " << estoqueAtual3 << endl << endl;

    // Definição das variáveis do produto 4
    string nomeProduto4 = "Afia";
    double precoCompra4 = 0.50;
    double precoVenda4 = 1.0;
    int quantidadeEstoqueInicial4 = 100;
    int quantidadeVendida4 = 53;
    int quantidadeAdicionada4 = 10;

    // Cálculo do estoque atual do produto 4
    int estoqueAtual4 = quantidadeEstoqueInicial4 - quantidadeVendida4 + quantidadeAdicionada4;

    // Cálculo do lucro total do produto 4
    double lucroTotal4 = (precoVenda4 - precoCompra4) * (quantidadeEstoqueInicial4 - quantidadeVendida4);

    // Exibição dos detalhes do produto 4
    cout << "Detalhes do produto 4:" << endl;
    cout << "Nome: " << nomeProduto4 << endl;
    cout << "Preço de compra: €" << precoCompra4 << endl;
    cout << "Preço de venda: €" << precoVenda4 << endl;
    cout << "Lucro total: €" << lucroTotal4 << endl;
    cout << "Quantidade em estoque: " << estoqueAtual4 << endl << endl;

    // Definição das variáveis do produto 5
    string nomeProduto5 = "Lápis";
    double precoCompra5 = 1.50;
    double precoVenda5 = 2.50;
    int quantidadeEstoqueInicial5 = 100;
    int quantidadeVendida5 = 50;
    int quantidadeAdicionada5 = 10;

    // Cálculo do estoque atual do produto 5
    int estoqueAtual5 = quantidadeEstoqueInicial5 - quantidadeVendida5 + quantidadeAdicionada5;

    // Cálculo do lucro total do produto 5
    double lucroTotal5 = (precoVenda5 - precoCompra5) * (quantidadeEstoqueInicial5 - quantidadeVendida5);

    // Exibição dos detalhes do produto 5
    cout << "Detalhes do produto 5:" << endl;
    cout << "Nome: " << nomeProduto5 << endl;
    cout << "Preço de compra: €" << precoCompra5 << endl;
    cout << "Preço de venda: €" << precoVenda5 << endl;
    cout << "Lucro total: €" << lucroTotal5 << endl;
       cout << "Quantidade em estoque: " << estoqueAtual5 << endl << endl;

    return 0;
}
