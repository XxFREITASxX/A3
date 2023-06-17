#include <iostream>
#include <vector>
#include "sistema.h"

using namespace std;

int main() {

	Sistema sistema;

	string login, senha;
	int opcao;
	int selecao;
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
			cout << "\nDigite sua senha: ";
			cin >> senha;

			if (sistema.autenticarCliente(login, senha)) {
				cout << "\nLogin realizado com sucesso!\n";
			} else {
				cout << "\nLogin inválido!\n";
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

			cout << "Digite o nome de usuario: ";
			cin >> login;
			cout << "\nDigite a senha: ";
			cin >> senha;

			if (sistema.autenticarFuncionario(login, senha)) {
				cout << "\nLogin realizado com sucesso!\n";
			}
			else {
				cout << "\nLogin inválido!\n";
			}

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
