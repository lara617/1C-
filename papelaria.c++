#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;


struct Produto {
    string nome;
    double precoCompra;
    double precoVenda;
    int quantidadeEstoqueInicial;
    int quantidadeVendida;
    int quantidadeAdicionada;
};


void exibirTabelaProdutos(const vector<Produto>& produtos) {
    cout << "Detalhes dos produtos:" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Nome" << setw(20) << "Preço Compra (€)" << setw(20) << "Preço Venda (€)" << setw(25) << "Quantidade Stock" << endl;
    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;

    for (const Produto& p : produtos) {
        int estoqueAtual = p.quantidadeEstoqueInicial - p.quantidadeVendida + p.quantidadeAdicionada;

        cout << setw(15) << left << p.nome << setw(20) << fixed << setprecision(2) << p.precoCompra << setw(20) << p.precoVenda << setw(25) << estoqueAtual << endl;
    }

    cout << "---------------------------------------------------------------------------------------------------------------------" << endl;
}

int main() {
   
    vector<Produto> produtos = {
        {"1-Caderno", 2.00, 5.00, 50, 20, 0},
        {"2-Borracha", 0.20, 0.50, 100, 50, 30},
        {"3-Caneta", 0.50, 1.50, 100, 50, 30},
        {"4-Afia", 0.50, 1.00, 100, 53, 10},
        {"5-Lápis", 0.20, 1.00, 100, 50, 10}
    };

    bool continuar = true;
    double lucroTotal = 0.0; 
    vector<Produto> carrinho; 

    
    exibirTabelaProdutos(produtos);

    while (continuar) {
       
        int opcao;
        cout << "\n1. Comprar produto\n2. Ver o lucro\n3. Ver o carrinho\n4. Finalizar compra\n5. Sair\nEscolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1: {
               
                exibirTabelaProdutos(produtos);

                
                int escolha;
                int quantidade;

                cout << "Digite o número do produto que deseja comprar: ";
                cin >> escolha;

                if (escolha < 1 || escolha > produtos.size()) {
                    cout << "Opção inválida. Tente novamente." << endl;
                    break;
                }

                cout << "Digite a quantidade que deseja comprar: ";
                cin >> quantidade;

                Produto produtoEscolhido = produtos[escolha - 1];
                int estoqueDisponivel = produtoEscolhido.quantidadeEstoqueInicial - produtoEscolhido.quantidadeVendida + produtoEscolhido.quantidadeAdicionada;

                if (quantidade > estoqueDisponivel) {
                    cout << "Stock insuficiente. Quantidade disponível: " << estoqueDisponivel << endl;
                } else {
                    produtoEscolhido.quantidadeAdicionada = quantidade;
                    carrinho.push_back(produtoEscolhido); 
                    cout << "Produto adicionado ao carrinho." << endl;
                }
                break;
            }
            case 2:
                
                cout << "Lucro total: €" << fixed << setprecision(2) << lucroTotal << endl;
                break;
            case 3:
               
                if (carrinho.empty()) {
                    cout << "Carrinho vazio." << endl;
                } else {
                    cout << "Produtos no carrinho:" << endl;
                    exibirTabelaProdutos(carrinho);
                }
                break;
            case 4: {
               
                double totalCompra = 0.0;
                double lucroCompra = 0.0;
                for (const Produto& p : carrinho) {
                    totalCompra += p.precoVenda * p.quantidadeAdicionada;
                    lucroCompra += (p.precoVenda - p.precoCompra) * p.quantidadeAdicionada; 
                    produtos[&p - &carrinho[0]].quantidadeVendida += p.quantidadeAdicionada; 
                }
                lucroTotal += lucroCompra; 
                carrinho.clear(); 

                
                double valorPago;
                cout << "Total a pagar: €" << fixed << setprecision(2) << totalCompra << endl;
                cout << "Digite o valor pago: €";
                cin >> valorPago;

                if (valorPago < totalCompra) {
                    cout << "Valor insuficiente. A compra não pode ser concluída." << endl;
                } else {
                    double troco = valorPago - totalCompra;
                    cout << "Troco: €" << fixed << setprecision(2) << troco << endl;
                    cout << "Compra realizada com sucesso." << endl;
                }

                for (Produto& p : produtos) {
                    p.quantidadeEstoqueInicial = p.quantidadeEstoqueInicial - p.quantidadeVendida + p.quantidadeAdicionada;
                    p.quantidadeAdicionada = 0; 
                    p.quantidadeVendida = 0; 
                }

            
                exibirTabelaProdutos(produtos);
                break;
            }
            case 5:
                continuar = false;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    }

    return 0;
}