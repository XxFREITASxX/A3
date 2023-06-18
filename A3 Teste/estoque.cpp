#include "Estoque.h"
#include <iostream>
#include <string>

using namespace std;

Estoque::Estoque() {

	Produto produto1(1, "Camiseta ...", 50.9, "M", "Preto", "Nike", 5, "");
	Produto produto2(2, "Camiseta ...", 50.9, "M", "Preto", "Nike", 5, "");
	Produto produto3(3, "Camiseta ...", 59.9, "M", "Preto", "Nike", 5, "");
	Produto produto4(4, "Camiseta ...", 59.9, "M", "Preto", "Nike", 5, "");
	Produto produto5(5, "Camiseta ...", 59.9, "M", "Preto", "Nike", 5, "");

	produtos.push_back(produto1);
	produtos.push_back(produto2);
	produtos.push_back(produto3);
	produtos.push_back(produto4);
	produtos.push_back(produto5);

}

void Estoque::adicionarProduto() {

	string nome, tamanho, cor, marca, tipo;
	double preco;
	int quantidade, id;

	cout << "\nID do produto: ";
	cin >> id;

	for (const auto& produto : produtos) { // Percorre os produtos que estao no vetor de produtos
		if (produto.getId() == id) {       // Checa se já existe um produto cadastrado com esse ID
			cout << "\nJa existe um produto com este ID cadastrado. Porfavor, escolha outro ID.";
			return;
		}
	}

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

	do {
		cout << "Tipo do produto (Camiseta, Meia, Calca, Moletom): ";
		cin >> tipo;

		if (tipo == "Camiseta" || tipo == "camiseta" || tipo == "Meia" || tipo == "meia" || tipo == "Calca" || tipo == "calca" || tipo == "Moletom" || tipo == "moletom") {
			break;
		}
		else {
			cout << "Tipo inválido! Por favor, digite um tipo válido (Camiseta/camiseta | Meia/meia | Calca/calca | Moletom/moletom).";
		}
	} while (true);

	Produto produto(id, nome, preco, tamanho, cor, marca, quantidade, tipo);  // Cria o objeto do tipo produto e passa os valores fornecidos como argumentos para o construtor 'Produto'
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
			cout << "Preco: " << produto.getPreco() << endl;
			cout << "Tamanho: " << produto.getTamanho() << endl;
			cout << "Cor: " << produto.getCor() << endl;
			cout << "Marca: " << produto.getMarca() << endl;
			cout << "Quantidade: " << produto.getQuantidade() << endl;
			cout << "Tipo: " << produto.getTipo() << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=";
		}
	}
}
