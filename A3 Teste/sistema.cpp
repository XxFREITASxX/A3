#include "Sistema.h"
#include <string>

Sistema::Sistema() {}

void Sistema::cadastrarCliente() {

    cout << "\n =-= Cadastro do Cliente =-=" << endl;

    string nome, email, cpf, login, senha, endereco;

    do {
        cout << "\nNome: ";
        cin >> nome;

        if (nome.size() < 3) {
            cout << "Insira um nome v�lido com mais de 3 letras!\n";
        }
    } while (nome.size() < 3);

    cout << "\nEmail: ";
    cin >> email;

    for (const auto& cliente : clientes) {
        if (cliente.getEmail() == email) {     // Checa se o email j� est� em uso.                                    
            cout << "Email j� registrado! Por favor, escolha um email diferente.\n";
            return;
        }
    }

    do {
        cout << "\nCPF: ";
        cin >> cpf;

        if (cpf.size() != 11)
            cout << "Insira um cpf v�lido com 11 n�meros!\n";
    } while (cpf.size() != 11);

    for (const auto& cliente : clientes) {
        if (cliente.getCpf() == cpf) {     // Checa se o email j� est� em uso.                                    
            cout << "CPF j� registrado! Por favor, digite um CPF n�o cadastrado.\n";
            return;
        }
    }

    cout << "\nLogin: ";
    cin >> login;

    for (const auto& cliente : clientes) {
        if (cliente.getLogin() == login) {     // Checa se o login j� est� em uso.
            cout << "Este login j� est� em uso. Por favor, escolha um login diferente.\n";
            return;
        }
    }

    cout << "\nSenha: ";
    cin >> senha;

    cin.ignore(); // Descartar os caracteres para n�o misturar com o pr�ximo

    cout << "\nEndereco: ";
    getline(cin, endereco);
    

    Cliente cliente(nome, email, cpf, login, senha, endereco);
    clientes.push_back(cliente);

    cout << "\nCadastro realizado com sucesso!\n";
}

void Sistema::cadastrarFuncionario() {

    cout << "\n =-= Cadastro do Funcionario =-=" << endl;

    string nome, email, cpf, login, senha;
    int id_funcionario;

    do {

        cout << "\nNome: ";
        cin >> nome;

        if (nome.size() < 3) {
            cout << "Insira um nome v�lido com mais de 3 letras!";
        }
    } while (nome.size() < 3);


    cout << "\nEmail: ";
    cin >> email;

    for (const auto& funcionario : funcionarios) {
        if (funcionario.getEmail() == email) {     // Checa se o email j� est� em uso.                                    
            cout << "Email j� registrado! Por favor, escolha um email diferente.\n";
            return; 
        }
    }

    do {
        cout << "\nCPF: ";
        cin >> cpf;

        if (cpf.size() != 11)
            cout << "Insira um cpf v�lido com 11 n�meros!\n";
    } while (cpf.size() != 11);

    cout << "\nLogin: ";
    cin >> login;

    for (const auto& funcionario : funcionarios) {
        if (funcionario.getLogin() == login) {     // Checa se o login j� est� em uso.
            cout << "Este login j� est� em uso. Por favor, escolha um login diferente.\n";
            return;
        }
    }

    cout << "\nSenha: ";
    cin >> senha;

    cout << "\nID: ";
    cin >> id_funcionario;

    Funcionario funcionario(nome, email, cpf, login, senha, id_funcionario);
    funcionarios.push_back(funcionario);

    cout << "\nCadastro realizado com sucesso!\n";
}

bool Sistema::autenticarFuncionario(const string& login, const string& senha) {

    for (auto& funcionario : funcionarios) {                            // Checa o vetor dos funcion�rios.
        if (funcionario.autenticar(login, senha)) {                     // Faz autentica��o do login e senha.
            return true;                                                // Retorna true caso a autentica��o seja sucedida.
        }
    }

}

bool Sistema::autenticarCliente(const string& login, const string& senha) {

    for (auto& cliente : clientes) {               // Checa o vetor dos clientes.
        if (cliente.autenticar(login, senha)) {    // Faz autentica��o do login e senha.
            return true;                           // Retorna true caso a autentica��o seja sucedida.
        }
    }

    return false; // Retorna false caso a autentica��o falhe.
}