#include "Estoque.h"
#include <iostream>
#include <string>

using namespace std;

void Estoque::adicionarProduto() {

	string nome, tamanho, cor, marca;
	float preco;
	int quantidade, id;

	cout << "\nID do produto: ";
	cin >> id;

	cin.ignore();

	cout << "\nNome do produto: ";
	getline(cin, nome);

	cout << "\nPreco do produto: R$";
	cin >> preco;

	cout << "\nTamanho do produto: ";
	cin >> tamanho;

	cout << "\nCor do produto: ";
	cin >> cor;

	cout << "\nMarca do produto: ";
	cin >> marca;

	cout << "\nQuantidade do produto: ";
	cin >> quantidade;

	Produto produto(id, nome, preco, tamanho, cor, marca, quantidade);
	produtos.push_back(produto);

	cout << "\nProduto adicionado ao estoque!\n";
}

void Estoque::removerProduto(int id) {
	if (id >= 0 && id < produtos.size()) {
		produtos.erase(produtos.begin() + id);
		cout << "\nProduto removido do estoque!";
	}	else {
		cout << "\nProduto nao encontrado no estoque!";
	}
}

void Estoque::exibirProdutos() const {
	if (produtos.empty()) {
		cout << "Nenhum produto em estoque!" << endl;
	}else {
		cout << "Itens disponiveis no estoque: " << endl;
		for (int i = 0; i < produtos.size(); i++) {
			const Produto& produto = produtos[i];
			cout << "ID: " << i << endl;
			cout << "\nNome: " << produto.getNome() << endl;
			cout << "\nPreço: " << produto.getPreco() << endl;
			cout << "\nTamanho: " << produto.getTamanho() << endl;
			cout << "\nCor: " << produto.getCor() << endl;
			cout << "\nMarca: " << produto.getMarca() << endl;
			cout << "\nQuantidade: " << produto.getQuantidade() << endl;
		}
	}
}
