#include <iostream>
#include <vector>
#include "sistema.h"
#include "estoque.h"

using namespace std;

int main() {

	Sistema sistema;
	Estoque estoque;

	string login, senha;
	int opcao;
	int opcao2;
	int selecao;
	int categoria;
	bool sair = false;

	while (true) {
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

			if (sistema.autenticarCliente(login, senha)) {
				cout << "\nLogin realizado com sucesso!\n";
			}
			else {
				cout << "\nLogin invalido! Nome de usuario ou senha incorretos.\n";
			}

			cout << "\n =-=-= Selecao de Categorias =-=-=";
			cout << "\n (1) Camisetas";
			cout << "\n (2) Calcas";
			cout << "\n (3) Meias";
			cout << "\n (4) Moletons";
			cin >> categoria;

			switch (categoria) {

			case 1:

				cout << "\n=-=-= Produtos da Categoria selecionada =-=-=\n";
				for (const auto& produto : estoque.getProdutos()) {
					if (categoria == 1 && produto.getCategoria() == "Camiseta") {
						produto.exibirInfo();
					}

				}
			}


			break;

		case 2:

			cout << "\nSelecione o cadastro: \n" << endl;
			cout << " (1) Cliente" << endl;
			cout << " (2) Funcionario\n" << endl;
			cin >> selecao;

			switch (selecao) {

			case 1:

				sistema.cadastrarCliente();

				break;

			case 2:

				sistema.cadastrarFuncionario();

				break;
			}
			break;

		case 3:

			cout << "\nDigite o nome de usuario: ";
			cin >> login;
			cout << "Digite a senha: ";
			cin >> senha;

			if (sistema.autenticarFuncionario(login, senha)) {
				cout << "\nLogin realizado com sucesso!\n";
			}
			else {
				cout << "\nLogin inválido!\n";
			}

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
						estoque.adicionarProduto();

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

					estoque.removerProduto(id);

					break;

				case 3:

					estoque.exibirProdutos();

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

		case 4:

			sair = true;
			break;

		default:

			cout << "Opção inválida. Escolha uma opção válida." << endl;
			break;
		}

		if (opcao != 4) {
			cout << "\nPressione qualquer tecla para voltar ao menu inicial ou digite 4 para sair: ";
			cin >> opcao;
		}
	}
}