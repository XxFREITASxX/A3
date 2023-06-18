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
		cout << "Nenhum produto em estoque!" << endl;
	}else {
		cout << "Itens disponiveis no estoque: " << endl;
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=";
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
