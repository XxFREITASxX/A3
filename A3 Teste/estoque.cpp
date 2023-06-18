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

	cout << "Nome do produto: ";
	getline(cin, nome);

	cout << "Preco do produto: R$";
	cin >> preco;

	cout << "Tamanho do produto: ";
	cin >> tamanho;

	cout << "Cor do produto: ";
	cin >> cor;

	cout << "Marca do produto: ";
	cin >> marca;

	cout << "Quantidade do produto: ";
	cin >> quantidade;

	Produto produto(id, nome, preco, tamanho, cor, marca, quantidade);
	produtos.push_back(produto);

	cout << "\nProduto adicionado ao estoque!\n";
}

void Estoque::removerProduto(int id) {
	bool produtoRemovido = false;
	for (auto it = produtos.begin(); it != produtos.end(); ++it) {
		if (it->getId() == id){
		produtos.erase(it);
		produtoRemovido = true;
		break;
	}
}
if (produtoRemovido) {

	cout << "\nProduto removido do estoque!";
} else {
		cout << "\nProduto nao encontrado no estoque!";
	}
}

void Estoque::exibirProdutos() const {
	if (produtos.empty()) {
		cout << "\nNenhum produto em estoque!" << endl;
	}else {
		cout << "Itens disponiveis no estoque: " << endl;
		cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=";
		for (const auto& produto : produtos) {
			
			cout << "\nID: " << produto.getId() << endl;
			cout << "Nome: " << produto.getNome() << endl;
			cout << "Preço: " << produto.getPreco() << endl;
			cout << "Tamanho: " << produto.getTamanho() << endl;
			cout << "Cor: " << produto.getCor() << endl;
			cout << "Marca: " << produto.getMarca() << endl;
			cout << "Quantidade: " << produto.getQuantidade() << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=";
		}
	}
}
