// Arquivo destinado as sobrecargas no login.
#include "Gerencia.h"

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo_login, Gerencia& g)
{
    arquivo_login << g.getNome() << endl;
    arquivo_login << g.getCPF() << endl;
    arquivo_login << g.getUser() << endl;
    arquivo_login << g.getSenha() << endl;
    arquivo_login << g.getIdade() << endl;
    arquivo_login << g.getSexo();

    return arquivo_login;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo_login, Gerencia& g)
{
    string nome, cpf, user, senha;
    int idade;
    bool sexo;

    getline(arquivo_login, nome);
    g.setNome(nome);
    getline(arquivo_login, cpf);
    g.setCPF(cpf);
    getline(arquivo_login, user);
    g.setUser(user);
    getline(arquivo_login, senha);
    g.setSenha(senha);
    arquivo_login >> idade;
    g.setIdade(idade);
    arquivo_login >> sexo;
    g.setSexo(sexo);

    return arquivo_login;
}
