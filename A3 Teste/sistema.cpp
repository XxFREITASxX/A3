#include "Sistema.h"
#include <string>

Sistema::Sistema() {}

void Sistema::cadastrarCliente() {

    cout << "\n =-= Cadastro do Cliente =-=" << endl;

    string nome, email, cpf, login, senha, endereco;

    // Nome

    do {
        cout << "\nNome: ";
        cin >> nome;

        if (nome.size() < 3) { // Obriga o nome a ter 3 ou mais letras.
            cout << "\nInsira um nome valido com mais de 3 letras!\n";
        }
    } while (nome.size() < 3);

    // Email

    do {
        cout << "Email: ";
        cin >> email;

        bool emailEmUso = false;

        for (const auto& cliente : clientes) {
            if (cliente.getEmail() == email) {
                cout << "\nEmail ja registrado! Por favor, escolha um email diferente.\n\n";
                emailEmUso = true;
                break;
            }
        }

        if (!emailEmUso) {
            break; 
        }

    } while (true);

    // CPF

    do {
        cout << "CPF: ";
        cin >> cpf;

        if (cpf.size() != 11) {
            cout << "\nInsira um CPF valido com 11 numeros!\n";
        }
        else {
            bool cpfExistente = false;

            for (const auto& cliente : clientes) {
                if (cliente.getCpf() == cpf) {
                    cout << "\nCPF ja registrado! Por favor, digite um CPF nao cadastrado.\n\n";
                    cpfExistente = true;
                    break;
                }
            }

            if (!cpfExistente) {
                break;
            }
        }
    } while (true);

    // Login

    do {
        cout << "Login: ";
        cin >> login;

        bool loginExistente = false;

        for (const auto& cliente : clientes) {
            if (cliente.getLogin() == login) {
                cout << "\nLogin já existente. Por favor, escolha um login diferente.\n\n";
                loginExistente = true;
                break;
            }
        }

        if (!loginExistente) {
            break;
        }
    } while (true);

    // Senha

    cout << "Senha: ";
    cin >> senha;

    cin.ignore(); // Descarta os caracteres para não misturar com o próximo

    // Endereco

    cout << "Endereco: ";
    getline(cin, endereco); // Garante que todos os caracteres da linha sejam lidos.
    

    Cliente cliente(nome, email, cpf, login, senha, endereco); // Cria um objeto e passa os parâmetros para ele.
    clientes.push_back(cliente);                               // Adiciona o objeto criado no final do vetor de clientes.

    cout << "\nCadastro realizado com sucesso!\n";
}

void Sistema::cadastrarFuncionario() {

    cout << "\n =-= Cadastro do Funcionario =-=" << endl;

    string nome, email, cpf, login, senha;
    int id_funcionario;

    // Nome

    do {

        cout << "\nNome: ";
        cin >> nome;

        if (nome.size() < 3) { // Obriga o nome a ter 3 ou mais letras.
            cout << "Insira um nome valido com no minimo 3 letras!";
        }
    } while (nome.size() < 3);

    // Email

    do {
        cout << "Email: ";
        cin >> email;

        bool emailEmUso = false;

        for (const auto& funcionario : funcionarios) {
            if (funcionario.getEmail() == email) {
                cout << "\nEmail ja registrado! Por favor, escolha um email diferente.\n\n";
                emailEmUso = true;
                break;
            }
        }

        if (!emailEmUso) {
            break;
        }

    } while (true);

    // CPF

    do {
        cout << "CPF: ";
        cin >> cpf;

        if (cpf.size() != 11) {
            cout << "\nInsira um CPF valido com 11 numeros!\n";
        }
        else {
            bool cpfExistente = false;

            for (const auto& funcionario : funcionarios) {
                if (funcionario.getCpf() == cpf) {
                    cout << "\nCPF ja registrado! Por favor, digite um CPF nao cadastrado.\n\n";
                    cpfExistente = true;
                    break;
                }
            }

            if (!cpfExistente) {
                break;
            }
        }
    } while (true);

    // Login

    do {
        cout << "Login: ";
        cin >> login;

        bool loginExistente = false;

        for (const auto& funcionario : funcionarios) { // Checa o vetor dos funcinários.
            if (funcionario.getLogin() == login) {     // Checa se o login ja esta em uso.
                cout << "\nLogin já existente. Por favor, escolha um login diferente.\n\n";
                loginExistente = true;
                break;
            }
        }

        if (!loginExistente) {
            break;
        }
    } while (true);

    // Senha

    cout << "Senha: ";
    cin >> senha;

    // ID

    cout << "ID: ";
    cin >> id_funcionario;

    Funcionario funcionario(nome, email, cpf, login, senha, id_funcionario); // Cria um objeto e passa os parâmetros para ele.
    funcionarios.push_back(funcionario);                                     // Adiciona o objeto criado no final do vetor de funcionarios.

    cout << "\nCadastro realizado com sucesso!\n";
}

bool Sistema::autenticarFuncionario(const string& login, const string& senha) {

    for (auto& funcionario : funcionarios) {                            // Checa o vetor dos funcionários.
        if (funcionario.autenticar(login, senha)) {                     // Faz autenticação do login e senha.
            return true;                                                // Retorna true caso a autenticação seja sucedida.
        }
    }

    return false;
}

bool Sistema::autenticarCliente(const string& login, const string& senha) {

    for (auto& cliente : clientes) {               // Checa o vetor dos clientes.
        if (cliente.autenticar(login, senha)) {    // Faz autenticação do login e senha.
            return true;                           // Retorna true caso a autenticação seja sucedida.
        }
    }

    return false; // Retorna false caso a autenticação falhe.
}