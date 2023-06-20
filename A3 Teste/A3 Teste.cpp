#include <iostream>
#include <vector>
#include "sistema.h"
#include "estoque.h"
#include "carrinho.h"

using namespace std;

int main() {

	Sistema sistema;
	Estoque estoque;
	Carrinho carrinho;

	string login, senha;
	int opcarrinho;
	int opcao;
	int opcao2;
	int selecao;
	int categoria;
	bool sair;

	do {

		sair = false;

		cout << "\n";
		cout << "\t\t ===============================================\n";
		cout << "\t\t ||                                           ||\n";
		cout << "\t\t ||                 NIX STORE                 ||\n";
		cout << "\t\t ||                                           ||\n";
		cout << "\t\t ||         Bem-Vindo ao menu inicial         ||\n";
		cout << "\t\t ||                                           ||\n";
		cout << "\t\t ===============================================\n\n";
		cout << endl;
		cout << "| Pressione (1) para FAZER LOGIN               |\n";
		cout << "| Pressione (2) para REGISTRAR                 |\n";
		cout << "| Pressione (3) para ENTRAR COMO ADMINISTRADOR |\n";
		cout << "| Pressione (4) para SAIR                      |\n";
		cout << endl;
		cout << endl;
		cin >> opcao; // Variável para armazenar a opção escolhida

		switch (opcao) {

		case 1:

			cout << "\nDigite seu login: ";
			cin >> login;
			cout << "Digite sua senha: ";
			cin >> senha;

			if (sistema.autenticarCliente(login, senha)) { // Confere se o login e senha de cliente estão registrados no sistema.
				cout << "\nLogin realizado com sucesso!\n";
				cout << "\n=-=-= MENU USUARIO =-=-=" << endl;
				cout << "\n(1) ADICIONAR PRODUTO NO CARRINHO" << endl;
				cout << "(2) REMOVER PRODUTO DO CARRINHO" << endl;
				cout << "(3) EXIBIR CARRINHO" << endl;
				cout << "(4) PAGAMENTO (NAO IMPLEMENTADO)\n" << endl;

				cin >> opcarrinho;

				while (true) {
					switch (opcarrinho) {

					case 1:
						cout << "\n =-=-= Selecao de Categorias =-=-=";
						cout << "\n (1) Camisetas";
						cout << "\n (2) Calcas";
						cout << "\n (3) Meias";
						cout << "\n (4) Moletons\n" << endl;
						cin >> categoria;


						switch (categoria) {

						case 1:

							cout << "\n=-=-= Produtos da Categoria selecionada =-=-=\n";
							for (const auto& produto : estoque.getProdutos()) {                // Exibe os produtos da categoria selecionada.
								if (categoria == 1 && produto.getCategoria() == "Camiseta") {
									produto.exibirInfo();
								}

							}

							int id;

							cout << "\nDigite o ID do produto a ser adicionado ao carrinho: ";
							cin >> id;
							carrinho.addProduto(estoque.getProdutos(), id);  // Adiciona o produto que possui o ID selecionado ao carrinho.
							break;

						case 2:

							cout << "\n=-=-= Produtos da Categoria selecionada =-=-=\n";
							for (const auto& produto : estoque.getProdutos()) {
								if (categoria == 2 && produto.getCategoria() == "Calca") {
									produto.exibirInfo();
								}

							}

							cout << "\nDigite o ID do produto a ser adicionado ao carrinho: ";
							cin >> id;
							carrinho.addProduto(estoque.getProdutos(), id);

							break;

						case 3:

							cout << "\n=-=-= Produtos da Categoria selecionada =-=-=\n";
							for (const auto& produto : estoque.getProdutos()) {
								if (categoria == 3 && produto.getCategoria() == "Meia") {
									produto.exibirInfo();
								}

							}

							cout << "\nDigite o ID do produto a ser adicionado ao carrinho: ";
							cin >> id;
							carrinho.addProduto(estoque.getProdutos(), id);

							break;

						case 4:

							cout << "\n=-=-= Produtos da Categoria selecionada =-=-=\n";
							for (const auto& produto : estoque.getProdutos()) {
								if (categoria == 4 && produto.getCategoria() == "Moletom") {
									produto.exibirInfo();
								}

							}

							cout << "\nDigite o ID do produto a ser adicionado ao carrinho: ";
							cin >> id;
							carrinho.addProduto(estoque.getProdutos(), id);

							break;
						}
						break;

					case 2:

						int id;

						carrinho.exibeCarrinho(); // Exibe o carrinho com os produtos que ja foram adicionados.

						cout << "\nDigite o ID do produto a ser removido do carrinho: ";
						cin >> id;
						carrinho.removeProduto(estoque.getProdutos(), id); // Remove do carrinho o produto de acordo com o ID selecionado.

						break;

					case 3:

						carrinho.exibeCarrinho();  // Exibe o carrinho com os produtos que ja foram adicionados.

						break;

					case 4:

						cout << "\nA opcao pagamento ainda nao foi implementada.";
						break;

					default:
						cout << "Opçao Invalida. Escolha uma opcao valida.\n";
						break;
					}

					cout << "\n =-=-= MENU USUARIO =-=-=" << endl;
					cout << "\n(1) ADICIONAR PRODUTO NO CARRINHO" << endl;
					cout << "\n(2) REMOVER PRODUTO DO CARRINHO" << endl;
					cout << "\n(3) EXIBIR CARRINHO" << endl;
					cout << "\n(4) PAGAMENTO (NAO IMPLEMENTADO)\n" << endl;
					cout << "\n(0) SAIR" << endl;
					cin >> opcarrinho;

					if (opcarrinho == 0) {
						return 0;
					}

				}
			}
			else {
				cout << "\nLogin invalido! Nome de usuario ou senha incorretos.\n";
			}
			break;


		case 2:

			cout << "\nSelecione o cadastro: \n" << endl;
			cout << " (1) Cliente" << endl;
			cout << " (2) Funcionario\n" << endl;
			cin >> selecao;

			switch (selecao) {

			case 1:

				sistema.cadastrarCliente(); // Realiza o cadastro do cliente.

				break;

			case 2:

				sistema.cadastrarFuncionario(); // Realiza o cadastro do funcionario.

				break;
			}

			sair = false;
			break;

		case 3:

			cout << "\nDigite o nome de usuario: ";
			cin >> login;
			cout << "Digite a senha: ";
			cin >> senha;

			if (sistema.autenticarFuncionario(login, senha)) {  // Verifica se o login e senha de funcionario esta cadastrado no sistema
				cout << "\nLogin realizado com sucesso!\n";

			do {
				cout << "\n";
				cout << "\t\t ===============================================\n";
				cout << "\t\t ||                                           ||\n";
				cout << "\t\t ||             MENU ADMINISTRADOR            ||\n";
				cout << "\t\t ||                                           ||\n";
				cout << "\t\t ===============================================\n\n";
				cout << endl;
				cout << "| (1) Adicionar produto ao estoque |\n";
				cout << "| (2) Remover produto do estoque   |\n";
				cout << "| (3) Eixibir produtos do estoque  |\n";
				cout << "| (4) SAIR                         |\n";
				cin >> opcao2;

				switch (opcao2) {

				case 1:

					do {
						estoque.adicionarProduto(); // Permite que o funcionario adicione um item ao estoque.

						cout << "\nDejesa adicionar outro produto ao estoque? (S/N): ";
						char resposta;
						cin >> resposta;
						if (resposta != 'S' && resposta != 's') {
							opcao2 = 0;
							break;
						}
					} while (true);

					break;

				case 2:

					int id;

					cout << "\nDigite o ID do protudo a ser removido: ";
					cin >> id;

					estoque.removerProduto(id); // Permite que o funcionario remova um item do estoque.

					break;

				case 3:

					estoque.exibirProdutos(); // Exibe os produtos disponiveis no estoque.

					break;

				case 4:

					sair = true;

					break;

				default:

					cout << "Escolha uma opcao valida." << endl;

					break;

				}
			} while (!sair);

			sair = false;

			break;
		}	else {
				cout << "\nLogin invalido!\n";
			}

		case 4:

			sair = true;
			break;

		default:

			cout << "Opcao invalida. Escolha uma opcao valida." << endl;
			break;
		}
	} while (!sair);

	return 0;
}