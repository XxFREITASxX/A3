#include "Estoque.h"
#include <iostream>

using namespace std;

void Estoque::adicionarProduto(const Produto& produto) {
	produtos.push_back(produto);
}

void Estoque::removerProduto(int indice) {
	if (indice >= 0 && indice < produtos.size()) {
		produtos.erase(produtos.begin() + indice);
	}
}

void Estoque::exibirProdutos() const {
	if (produtos.empty()) {
		cout << "Nenhum produto em estoque!" << endl;
	}else {
		cout << "Itens disponiveis no estoque: " << endl;
		for (const auto& produto : produtos)
			cout << "\nNome: " << produto.getNome() << endl;
		    cout << "\nPreço: " << produto.getPreco() << endl;
			cout << "\nTamanho: " << produto.getTamanho() << endl;
			cout << "\nCor: " << produto.getCor() << endl;
			cout << "\nMarca: " << produto.getMarca() << endl;
			cout << "\nQuantidade: " << produto.getQuantidade() << endl;
	}
}
