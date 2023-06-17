#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <vector>
#include <iostream>
#include "produto.h"

class Estoque {

	private:

	vector<Produto> produtos;

	public:

		void adicionarProduto();
		void removerProduto(int id);
		void exibirProdutos() const;

};
#endif