// Arquivo destinado as sobrecargas utilizadas no projeto.

#include "Funcionario.h"

// Sobrecarregando o operador de saída << para que possa gravar um objeto inteiro em um arquivo.
ofstream& operator << (ofstream& arquivo, Funcionario& f)
{
	arquivo << f.getNome() << endl;
	arquivo << f.getCPF() << endl;
	arquivo << f.getMatricula() << endl;
	arquivo << f.getServico() << endl;

	arquivo << f.getEndereco().rua << endl;
	arquivo << f.getEndereco().bairro << endl;
	arquivo << f.getEndereco().cidade << endl;
	arquivo << f.getEndereco().numero << endl;
	arquivo << f.getEndereco().CEP << endl;

	arquivo << f.getData().dia << endl;
	arquivo << f.getData().mes << endl;
	arquivo << f.getData().ano << endl;

	arquivo << f.getIdade() << endl;
	arquivo << f.getSexo() << endl;
	arquivo << f.getDepartamento() << endl;
	arquivo << f.getSalario() << endl;
	arquivo << f.getStatus();

	return arquivo;
}

// Sobrecarregando o operador de entrada >> para que possa ler um objeto inteiro de um arquivo.
ifstream& operator >> (ifstream& arquivo, Funcionario& f)
{
	string nome, cpf, servico, matricula, rua, bairro, cidade;
	int idade, departamento, numero, cep, dia, mes, ano;
	bool sexo, status;
	double salario;

	getline(arquivo, nome);
	f.setNome(nome);
	getline(arquivo, cpf);
	f.setCPF(cpf);
    getline(arquivo, matricula);
	f.setMatricula(matricula);
	getline(arquivo, servico);
	f.setServico(servico);

	getline(arquivo, rua);
	f.setRua(rua);
	getline(arquivo, bairro);
	f.setBairro(bairro);
	getline(arquivo, cidade);
	f.setCidade(cidade);
	arquivo >> numero;
	f.setNumero(numero);
	arquivo >> cep;
	f.setCEP(cep);

	arquivo >> dia;
	f.setDia(dia);
	arquivo >> mes;
	f.setMes(mes);
	arquivo >> ano;
	f.setAno(ano);

	arquivo >> idade;
	f.setIdade(idade);
	arquivo >> sexo;
	f.setSexo(sexo);
	arquivo >> departamento;
	f.setDepartamento(departamento);
	arquivo >> salario;
	f.setSalario(salario);
	arquivo >> status;
	f.setStatus(status);

	return arquivo;
}
