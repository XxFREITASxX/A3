#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include <iostream>
#include "produto.h"

class Estoque {

	private:

	vector<Produto> produtos;

	public:

		Estoque();
		void adicionarProduto();
		void removerProduto(int id);
		void exibirProdutos() const;
		void exibirCategoria(const string& categoria);

		const vector<Produto>& getProdutos() const {
			return produtos;
		}
};
#endif
