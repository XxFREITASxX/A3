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
    void cadastrarCliente();
    void cadastrarFuncionario();
    void logarCliente();
    void logarFuncionario();
    bool autenticarCliente(const string& login, const string& senha);
    bool autenticarFuncionario(const string& login, const string& senha);
};

#endif