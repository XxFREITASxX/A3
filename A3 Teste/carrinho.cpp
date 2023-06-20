#include "Carrinho.h"

#include <iostream>
#include <vector>
#include "Estoque.h"
#include "Produto.h"

using namespace std;

Carrinho::Carrinho() {}

void Carrinho::addProduto(const vector<Produto>& estoque, int id) {
    for (const auto& produto : estoque) { // Percorre os produtos do estoque.
        if (produto.getId() == id) { // Checa se o ID do produto é igual ao ID fornecido.
            produtos.push_back(produto); // Adiciona o produto no vetor de produtos do carrinho.
            cout << "\nProduto adiconado ao carrinho com sucesso!\n";
            return;
        }
    }
    cout << "\nProduto nao encontrado no estoque.\n";
}

void Carrinho::removeProduto(const vector<Produto>& estoque, int id) {
        for (auto it = produtos.begin(); it != produtos.end(); ++it) { // Percorre os produtos do carrinho, começando pelo inicio do vetor.
            if (it->getId() == id) { // Checa se o ID do produto é igual ao ID que foi fornecido.
                produtos.erase(it); // Remove o produto do carrinho.
                cout << "\nProduto removido do carrinho com sucesso!\n";
                return;
            }
        }
        cout << "\nProduto nao encontrado no carrinho!\n";
    }

void Carrinho::exibeCarrinho() {
        cout << "\n=-=-= Carrinho de Compras =-=-=\n";
        if (produtos.empty()) { // Verifica se o carrinho está vazio.
            cout << "\nO carrinho esta vazio.\n";
        }
        else {
            for (int i = 0; i < produtos.size(); i++) {
                cout << "Produto " << i + 1 << ":\n";
                produtos[i].exibirInfo(); // Exibe as informações do produto.
                cout << "\n";
            }
        }
 }


