#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include <iostream>
#include "produto.h"

class Estoque {

	private:

	vector<Produto> produtos;

	public:

		void adicionarProduto(const Produto& produto);
		void removerProduto(int indice);
		void exibitProdutos() const;



};
#endif