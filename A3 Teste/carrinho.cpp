#include "Carrinho.h"

#include <iostream>
#include <vector>
#include "Estoque.h"
#include "Produto.h"

using namespace std;

Carrinho::Carrinho() {}

void Carrinho::addProduto(const vector<Produto>& estoque, int id) {
    for (const auto& produto : estoque) {
        if (produto.getId() == id) {
            produtos.push_back(produto);
            cout << "\nProduto adiconado ao carrinho com sucesso!\n";
            return;
        }
    }
    cout << "\nProduto nao encontrado no estoque.\n";
}

void Carrinho::removeProduto(const vector<Produto>& estoque, int id) {
        for (auto it = produtos.begin(); it != produtos.end(); ++it) {
            if (it->getId() == id) {
                produtos.erase(it);
                cout << "\nProduto removido do carrinho com sucesso!\n";
                return;
            }
        }
        cout << "\nProduto nao encontrado no carrinho!\n";
    }

void Carrinho::exibeCarrinho() {
        cout << "\n=-=-= Carrinho de Compras =-=-=\n";
        if (produtos.empty()) {
            cout << "\nO carrinho esta vazio.\n";
        }
        else {
            for (int i = 0; i < produtos.size(); i++) {
                cout << "Produto " << i + 1 << ":\n";
                produtos[i].exibirInfo();
                cout << "\n";
            }
        }
 }


