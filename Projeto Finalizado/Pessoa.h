#ifndef PESSOA_H
#define PESSOA_H

struct Endereco{
	string rua;
    int numero;
    string bairro;
    int CEP;
    string cidade;
};

struct Data{
	int dia;
    int mes;
    int ano;
};

class Pessoa {
	string nomePessoa;
    string CPF;
    int idade;
    bool sexo; // 0 - Masculino/ 1 - Feminino
	Endereco endereco;
    Data data;
public:
	Pessoa();
	Pessoa(const string&, const string&, const int&, bool , Endereco , Data );

	//MÉTODOS SETTERS//
    void setNome(const string&);
    void setCPF(const string&);
    void setIdade(const int&);
    void setSexo(bool);

    //MÉTODOS GETTERS//
    string getNome(void) const;
    string getCPF(void) const;
    int getIdade(void) const;
    bool getSexo(void) const;

    //MÉTODOS PARA O STRUCT
    //void setEndereco(Endereco);
    void setRua(string);
    void setNumero(int);
    void setBairro(string);
    void setCEP(int);
    void setCidade(string);

    void setDia(int);
    void setMes(int);
    void setAno(int);

    Endereco getEndereco(void) const;
    Data getData(void) const;
};


#endif // PESSOA_H
