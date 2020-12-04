#include "Usuario.h"
#include "Sobrecarga_login.h"

using namespace std;

/*nomeUsuario = chefe
  senha = 12345678

  nomeUsuario = gerente
  senha = 87654321  */

// CONSTRUTOR DEFAULT
Usuario::Usuario()
{
    carregarUsuarios();
}

bool Usuario::verificarLogin()
{

	string usuario, senha;
	cout << "Digite o Login: " << endl;
	cin >> usuario;
	cout << "Digite a senha: " << endl;
	cin >> senha;
	system("cls");
	try//Try para o caso de senha ou usuario errado
	{
        if((usuario == "chefe" || usuario == "C" || usuario == "CHEFE") && senha == "1")
        {
            cout << setfill('-');
            cout << setw(30) << "-" << endl;
            cout << "Olá Chefe, você já está ativo." << endl;
            cout << "Status: online." << endl;
            cout << "O que você deseja fazer?" << endl;
            cout << setw(30) << "-" << endl;
            cout << setfill(' ');
            return 1;
        }
        // FOR PARA COMPARAR TODOS OS USER E SENHAS GUARDADAS
        for (unsigned i(0); i < lista_gerente.size(); i++)
        {
            if(usuario == lista_gerente[i].getUser() && senha == lista_gerente[i].getSenha())
            {
                cout << setfill('-');
                cout << setw(32) << "-" << endl;
                cout << "Olá Gerente, você já está ativo." << endl;
                cout << "Status: online." << endl;
                cout << "O que você deseja fazer?" << endl;
                cout << setw(32) << "-" << endl;
                cout << setfill(' ');
                return 0;
            }

        }
        throw "Login ou senha errada, deseja tentar novamente?\n(1)Sim.\n(2)Não.";
	}
	catch(const char* erro)
	{
		int decisao;
		cout << erro << endl;
		cin >> decisao;
		system("cls");
		if(decisao == 1)
		{
			return verificarLogin();
		}
		else
		{
			//JA FINALIZA O PROGRAMA AQUI
			exit(2);
			return 2;
		}
	}

}

// FUNCAO PARA VERIFICAR SE JÁ EXISTE UM GERENTE COM O MESMO CPF ID DE USUÁRIO
bool Usuario::inserirGerente(Gerencia g)
{
    for (unsigned i(0); i < lista_gerente.size(); i++)
    {
        if (lista_gerente[i].getUser() == g.getUser())
            return false;
    }

    lista_gerente.push_back(g);
    return true;
}

// FUNCAO PARA GRAVAR A LISTA DE USUARIOS NO DOCUMENTO TEXTO
void Usuario::salvarCadastro()
{
    ofstream arquivo_login;

    /* Utilizando o modo de abertura trunc, que abre e apaga os dados anteriores armazenados nele. Como toda a lista
	foi carregada no vector se utilizassemos o modo de abertura app o arquivo iria ficar com objetos repetidos.*/
    arquivo_login.open("Lista_de_usuarios.txt", std::ios::trunc);

    if (arquivo_login.is_open())
    {
        for (unsigned i(0); i < lista_gerente.size(); i++)
        {
            // Utilizando a sobrecarga do operador << para gravar o objeto no arquivo.
			arquivo_login << lista_gerente[i];
        }
    }
    arquivo_login.close(); // fecha o arquivo
}

void Usuario::carregarUsuarios()
{
    Gerencia geren;
    ifstream arquivo_login;
    arquivo_login.open("Lista_de_usuarios.txt");

    if(arquivo_login.is_open())
    {
        while(!arquivo_login.eof())
        {
            arquivo_login.sync();
            arquivo_login >> geren;
            lista_gerente.push_back(geren);
        }
    }
    arquivo_login.close();
}
