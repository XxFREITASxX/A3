#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Cliente.h"
#include "Funcionario.h"
#include <vector>

using namespace std;

class Sistema {

private:

    vector<Funcionario> funcionarios;
    vector<Cliente> clientes;

public:

    Sistema();

    // Cadastro e Login
    void cadastrarCliente();
    void cadastrarFuncionario();
    bool autenticarCliente(const string& login, const string& senha);
    bool autenticarFuncionario(const string& login, const string& senha);
};

#endif