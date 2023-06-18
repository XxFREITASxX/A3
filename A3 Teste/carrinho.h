#include <iostream>
#include <vector>
#include "Produto.h"

using namespace std;

class Carrinho {

    private:

    vector<Produto> produtos;

    public:

    void addProduto(const Produto& produto) {
        produtos.push_back(produto);
        cout << "Produto adicionado ao carrinho.\n";
    }

    void removeProduto(int indice) {
        if (indice >= 0 && indice < produtos.size()) {
            produtos.erase(produtos.begin() + indice);
            cout << "Produto removido do carrinho.\n";
        }
        else {
            cout << "Índice inválido. Produto não removido.\n";
        }
    }

    void exibeCarrinho() {
        cout << "\n=== Carrinho de Compras ===\n";
        if (produtos.empty()) {
            cout << "O carrinho está vazio.\n";
        }
        else {
            for (int i = 0; i < produtos.size(); i++) {
                cout << "Produto " << i + 1 << ":\n";
                produtos[i].exibirInfo();
                cout << "\n";
            }
        }
    }
};