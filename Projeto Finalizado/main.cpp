
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

#include "Empresa.cpp"
#include "Funcionario.cpp"
#include "Pessoa.cpp"
#include "Usuario.cpp"
#include "Gerencia.cpp"

int main() {
	setlocale(LC_ALL, "");

	string nome, cpf, user, senha;
	int opcao, opcaoCadastro, idade;
	bool condicao, sexo;

	Empresa empresa;
	Funcionario funcionario;
	Usuario usuario;
	Gerencia gerencia;

    // LACO PARA ESCOLHER OPCAO DO LOGIN
    while(1)
    {
        system("cls");
        // texto de apresentacao do nome e do cnpj da empresa:
        cout << "Empresa: " << "Empres.getNome()" << setw(20) << " " << "CNPJ: " << "Empresa.getCNPJ()" << endl << endl;

        cout << "Bem Vindo! Escolha uma opção de acesso." <<endl;
        cout << "Fazer login...[1]." << endl
             << "Criar conta...[2]." << endl
             << "Encerrar......[3]." << endl;
        cin >> opcao;

        if(cin.fail())
        {
            cout << endl << "A opção deve ser valores inteiros entre 1 e 3!" << endl;
            cin.clear();
            cin.ignore(100, '\n');
            system("pause");
        }

        else if (opcao == 1)
        {
            system("cls");
            //usuario.verificarLogin();

            //LOGIN DO CHEFE OU GERENTE.
            switch(usuario.verificarLogin()) {

            case 0://Case para a classe gerente.
                condicao = false;
                while(condicao == false) {
                    cout << "1 - Contratar funcionário." << endl
                             << "2 - Salvar a lista em um arquivo txt." << endl
                             << "3 - Mostrar lista de funcionários da Empresa." << endl
                             << "4 - Pesquisar funcionário." << endl
                             << "5 - Imprimir funcionários." << endl
                             << "6 - Encerrar." << endl;

                    // OBTER OPÇAO SELECIONADA:
                    while(1) // While para verificar se opcao inserida é somente inteiro
                    {
                        cout << endl << "Digite a opção: ";
                        cin >> opcao;

                        if (!(cin.fail()))
                        {
                            break;
                        }

                        cout << endl << "Opção deve ser um valor inteiro!" << endl;
                        system("pause");
                        system("cls");

                        // Limpar o buffer do cin
                        cin.clear();
                        cin.ignore(256, '\n');

                        cout << "1 - Contratar funcionário." << endl
                             << "2 - Salvar a lista em um arquivo txt." << endl
                             << "3 - Mostrar lista de funcionários da Empresa." << endl
                             << "4 - Pesquisar funcionário." << endl
                             << "5 - Imprimir funcionários." << endl
                             << "6 - Encerrar." << endl;
                    }
                    system("cls");

                    // SWITCH PARA VERIFICAR OPÇÃO INSERIDA:
                    switch(opcao) {

                        // CASO 1: INSERIR/CONTRATAR FUNCIONÁRIO:
                    case 1:

                        gerencia.contratarFunc();
                        system("pause");
                        system("cls");
                        break;


                        // CASO 2: SALVAR NO .TXT A LISTA DE FUNCIONÁRIO INSERIDA:
                    case 2:

                        gerencia.salvarLista();
                        system("pause");
                        system("cls");
                        break;


                        // CASO 3: IMPRIMIR TODOS OS FUNCIONÁRIOS:
                    case 3:

                        gerencia.listaFunc();
                        system("pause");
                        system("cls");
                        break;

                        // CASO 4: PROCURA FUNCIONÁRIO PELO NOME:
                    case 4:

                        gerencia.imprimirFunc();
                        system("pause");
                        system("cls");
                        break;

                        // CASO 5: PROCURA FUNCIONÁRIO PELO CPF:
                    case 5:

                        gerencia.showFunc();
                        system("pause");
                        system("cls");
                        break;

                        // VERIFICAR SE USUÁRIO PEDIU PARA ENCERRAR MOSTRA QUE O USUÁRIO NÃO ESTÁ ONLINE.
                    case 6:

                        condicao = true;
                        cout.fill('-');
                        cout << setw(28) << " " << endl;
                        cout << "Conta da gerência deslogada." << endl;
                        cout << "Status : offline." << endl;
                        cout << setw(28) << " " << endl;
                        condicao = true; // condicao para sair do primeiro while do login
                        system("pause");
                        system("cls");
                        break;

                    default:

                        cout << "Opção inválida!!!" << endl;
                        break;
                    }
                }
                break;

            // CASO LOGIN DO CHEFE
            case 1:
                condicao = false;
                while(condicao == false)
                {
                        cout << "1 - Contratar funcionário." << endl
                             << "2 - Demitir funcionário." << endl
                             << "3 - Imprimir funcionarios desativados." << endl
                             << "4 - Salvar a lista em um arquivo txt." << endl
                             << "5 - Mostrar lista de funcionários da Empresa." << endl
                             << "6 - Pesquisar funcionário." << endl
                             << "7 - Imprimir funcionários." << endl
                             << "8 - Aumento salárial." << endl
                             << "9 - Encerrar." << endl;

                    // OBTER OPÇAO SELECIONADA:
                    while(1) // While para verificar se opcao inserida é somente inteiro
                    {
                        cout << endl << "Digite a opção: ";
                        cin >> opcao;

                        if (!(cin.fail()))
                        {
                            break;
                        }

                        cout << endl << "Opção deve ser um valor inteiro!" << endl;
                        system("pause");
                        system("cls");

                        // Limpar o buffer do cin
                        cin.clear();
                        cin.ignore(256, '\n');

                        cout << "1 - Contratar funcionário." << endl
                             << "2 - Demitir funcionário." << endl
                             << "3 - Imprimir funcionarios desativados." << endl
                             << "4 - Salvar a lista em um arquivo txt." << endl
                             << "5 - Mostrar lista de funcionários da Empresa." << endl
                             << "6 - Pesquisar funcionário." << endl
                             << "7 - Imprimir funcionários." << endl
                             << "8 - Aumento salárial." << endl
                             << "9 - Encerrar." << endl;
                    }
                    system("cls");

                    // SWITCH PARA VERIFICAR OPÇÃO INSERIDA:
                    switch(opcao) {

                        // CASO 1: INSERIR/CONTRATAR FUNCIONÁRIO:
                    case 1:

                        gerencia.contratarFunc();
                        system("pause");
                        system("cls");
                        break;

                    //
                    case 2:
                        gerencia.demitirFunc();
                        system("pause");
                        system("cls");
                        break;

                    case 3:
                        gerencia.imprimirDesa();
                        system("pause");
                        system("cls");
                        break;

                        // CASO 2: SALVAR NO .TXT A LISTA DE FUNCIONÁRIO INSERIDA:
                    case 4:

                        gerencia.salvarLista();
                        system("pause");
                        system("cls");
                        break;


                        // CASO 3: IMPRIMIR TODOS OS FUNCIONÁRIOS:
                    case 5:

                        gerencia.listaFunc();
                        system("pause");
                        system("cls");
                        break;

                        // CASO 4: PROCURA FUNCIONÁRIO PELO NOME:
                    case 6:

                        gerencia.imprimirFunc();
                        system("pause");
                        system("cls");
                        break;

                        // CASO 5: PROCURA FUNCIONÁRIO PELO CPF:
                    case 7:

                        gerencia.showFunc();
                        system("pause");
                        system("cls");
                        break;

                    case 8:

                        gerencia.aumentoSalarial();
                        system("pause");
                        system("cls");
                        break;


                        // VERIFICAR SE USUÁRIO PEDIU PARA ENCERRAR MOSTRA QUE O USUÁRIO NÃO ESTÁ ONLINE.
                    case 9:

                        condicao = true;
                        cout.fill('-');
                        cout << setw(28) << " " << endl;
                        cout << "Conta da gerência deslogada." << endl;
                        cout << "Status : offline." << endl;
                        cout << setw(28) << " " << endl;
                        condicao = true; // condicao para sair do primeiro while do login
                        system("pause");
                        system("cls");
                        break;

                    default:

                        cout << "Opção inválida!!!" << endl;
                        break;
                    }
                }
            }
        }

        else if (opcao == 2)
        {
            system("cls");

            cout << endl << "CADASTRO DE USUÁRIO." << endl << endl;

            while(1)
            {
                cout << endl << "Cadastar gerente [1]" << endl;
                cin >> opcao;

                // VERIFICA SE INSERIU SOMENTE VALORES INTEIROS
                if(cin.fail())
                {
                    cout << endl << "Deve digitar apenas inteiros 1 ou 2" << endl;
                    cin.clear();
                    cin.ignore(10, '\n');
                }

                // OPCÃO DE INSERIR GERENTE - AQUI INSERIR DADOS DO GERENTE
                if (opcao == 1)
                {
                    system("cls");
                    cout << endl << "INSERIR DADOS DO GERENTE." << endl << endl;
                    cout << "Digite o nome do Gerente: ";
                    cin.sync();
                    getline(cin, nome);
                    gerencia.setNome(nome);

                    cout << endl << "Digite o cpf do gerencia: ";
                    cin.sync();
                    getline(cin, cpf);
                    gerencia.setCPF(cpf);

                    cout << endl << "Digite o sexo de MASCULINO(0) ou FEMININO(1) do gerencia: ";
                    cin >> sexo;
                    gerencia.setSexo(sexo);

                    cout << endl << "Digite a idade do gerencia: ";
                    cin >> idade;
                    gerencia.setIdade(idade);

                    cout << endl << "Digite o ID de usuário: ";
                    cin.sync();
                    getline(cin, user);
                    gerencia.setUser(user);

                    cout << endl << "Digite a senha do gerente: ";
                    cin.sync();
                    getline(cin, senha);
                    gerencia.setSenha(senha);

                    // WHILE DE CONFIRMACAO DA TAREFA DE CADASTRO
                    while(1)
                    {
                        cout << endl << "Confirmar cadastro. SIM[1] | NÃO[2]";
                        cin >> opcaoCadastro;
                        cout << endl;

                        if (cin.fail()) // verifica se foi digitado apenas numeros
                        {
                            cout << endl << "Deve digitar apenas inteiros 1 ou 2" << endl;
                            cin.clear();
                            cin.ignore(10, '\n');
                        }
                        else if (opcaoCadastro == 1) // verifica se usuário confima cadastrar novo gerente-usuario
                        {
                            // VAI VERIFICAR SE CONTA PODE SER CRIADA COM ESSES VALORES INSERIDOS:
                            if(usuario.inserirGerente(gerencia))// IRÁ ADCIONAR OBJETO NO ARRAY DE GERENTE NA CLASSE USUÁRIO
                            {
                                cout << "Conta cadastrada com sucesso!" << endl;
                                usuario.salvarCadastro(); // já salva as informações no bloco txt
                                //system("pause");
                            }
                            else
                            {
                                cout << "O cadastro não pode ser realizado!" << endl;
                            }
                            break;
                        }
                        else if (opcaoCadastro == 2) // cancela a tarefa de cadastro do gerente
                        {
                            cout << endl << "Tarefa Cancelada!" << endl;
                            system("pause");
                            break;
                        }
                        else
                        {
                            cout << endl << "Opcção inválida!" << endl;
                            system("pause");
                        }
                    }

                    break;
                }
                else
                    cout << endl << "Opção inválida!" << endl;
            }
            system("pause");
        }
        else
        {
            condicao = true;
            break;
        }
    }

    system("cls");
	cout << "Encerrando..." << endl;
	system("pause");

	return 0;
}
