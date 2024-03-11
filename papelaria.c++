#include <iostream>
#include <iomanip>
using namespace std;

// Função para calcular o troco
void calcularTroco(double valorTotal, double valorPago) {
    // Verifica se o valor pago é suficiente
    if (valorPago < valorTotal) {
        cout << "Valor pago insuficiente." << endl;
        return;
    }

    // Calcula o troco
    double troco = valorPago - valorTotal;

    // Exibe o troco com duas casas decimais
    cout << "Troco: R$ " << fixed << setprecision(2) << troco << endl;
}

int main() {
    double valorTotal, valorPago;

    // Solicita o valor total da compra
    cout << "Digite o valor total da compra: R$ ";
    cin >> valorTotal;

    // Solicita o valor pago pelo cliente
    cout << "Digite o valor pago pelo cliente: R$ ";
    cin >> valorPago;

    // Chama a função para calcular o troco
    calcularTroco(valorTotal, valorPago);

    return 0;
}