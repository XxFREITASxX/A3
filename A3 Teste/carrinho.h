#ifndef CARRINHO_H
#define CARRINHO_H

#include <iostream>
#include <vector>
#include "Produto.h"
#include "Estoque.h"

using namespace std;

class Carrinho {

	private:

	vector<Produto> produtos;

	public:

	Carrinho();

	void addProduto(const vector<Produto>& estoque, int id);
	void removeProduto(const vector<Produto>& estoque, int id);
	void exibeCarrinho();

};

#endif