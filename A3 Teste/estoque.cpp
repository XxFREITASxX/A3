#include "Estoque.h"
#include <iostream>
#include <string>

using namespace std;

Estoque::Estoque() {

	Produto produto1(1, "Calca ...", 50.9, "M", "Preto", "Nike", 5, "Calca");
	Produto produto2(2, "Camiseta ...", 50.9, "M", "Preto", "Nike", 5, "Camiseta");
	Produto produto3(3, "Meia ...", 59.9, "M", "Preto", "Nike", 5, "Meia");
	Produto produto4(4, "Moletom ...", 59.9, "M", "Preto", "Nike", 5, "Moletom");
	Produto produto5(5, "Camiseta ...", 59.9, "M", "Preto", "Nike", 5, "Camiseta");

	produtos.push_back(produto1);
	produtos.push_back(produto2);
	produtos.push_back(produto3);
	produtos.push_back(produto4);
	produtos.push_back(produto5);

}

void Estoque::adicionarProduto() {

	string nome, tamanho, cor, marca, categoria;
	double preco;
	int quantidade, id;

	do {
		cout << "\nID do produto: ";
		cin >> id;
		cin.ignore();

		if (id <= 0) {
			cout << "ID invalido! O ID deve ser um valor inteiro maior que zero.\n";
		} else {
			bool idDuplicado = false;
			for (const auto& produto : produtos) {
				if (produto.getId() == id) {
					idDuplicado = true;
					cout << "\nJa existe um produto com este ID cadastrado. Por favor, escolha outro ID.\n";
					break;
				}
			}
			if (!idDuplicado) {
				break;
			}
		  }
	} while (true);

	cout << "Nome do produto: ";
	getline(cin, nome);

	cout << "Preco do produto: R$";
	cin >> preco;
	cin.ignore();


	cout << "Tamanho do produto: ";
	cin >> tamanho;

	cout << "Cor do produto: ";
	cin.ignore();
	getline(cin, cor);

	cout << "Marca do produto: ";
	getline(cin, marca);

	cout << "Quantidade do produto: ";
	cin >> quantidade;
	cin.ignore();

	do {
		cout << "Categoria do produto (Camiseta, Meia, Calca, Moletom): ";
		cin >> categoria;

		if (categoria == "Camiseta" || categoria == "camiseta" || categoria == "Meia" || categoria == "meia" || categoria == "Calca" || categoria == "calca" || categoria == "Moletom" || categoria == "moletom") {
			break;
		}
		else {
			cout << "Categoria invalida! Por favor, digite uma categoria valida (Camiseta/camiseta | Meia/meia | Calca/calca | Moletom/moletom).";
		}
	} while (true);

	Produto produto(id, nome, preco, tamanho, cor, marca, quantidade, categoria);  // Cria o objeto do tipo produto e passa os valores fornecidos como argumentos para o construtor 'Produto'
	produtos.push_back(produto);									          // Adiciona o objeto 'produto' ao final do vetor de produtos

	cout << "\nProduto adicionado ao estoque!\n";
}

void Estoque::removerProduto(int id) {
	bool produtoRemovido = false;
	for (auto it = produtos.begin(); it != produtos.end(); ++it) { // Aponta o primeiro e ultimo elemento do vetor, se o iterador 'it' não chegou no final do vetor, incrimenta o iterador com ++it, colocando-o no próximo elemento do vetor
		if (it->getId() == id){									   // Verifica se o ID do produto é igual ao fornecido
		produtos.erase(it);										   // Remove o produto
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
		cout << "\nItens disponiveis no estoque: " << endl;
		cout << "\n=-=-=-=-=-=-=-=-=-=-=-=-=";
		for (const auto& produto : produtos) {
			
			cout << "\nID: " << produto.getId() << endl;
			cout << "Nome: " << produto.getNome() << endl;
			cout << "Preco: R$ " << produto.getPreco() << endl;
			cout << "Tamanho: " << produto.getTamanho() << endl;
			cout << "Cor: " << produto.getCor() << endl;
			cout << "Marca: " << produto.getMarca() << endl;
			cout << "Quantidade: " << produto.getQuantidade() << endl;
			cout << "Categoria: " << produto.getCategoria() << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=";
		}
	}
}

void Estoque::exibirCategoria(const string& categoria) {
	for (const auto& produto : produtos) {
		if (produto.getCategoria() == categoria) {
			produto.exibirInfo();
		}
	}
}