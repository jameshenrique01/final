#include <funcoes.h>

int menu() 
{
	int opcao = 0;
	char text, path[100];
    ifstream infile;

      cout<<"\t ================================"<<endl;
      cout<<"\t| Escolha a opcao:               |"<<endl;
      cout<<"\t| 1) Cadastrar perfil de aluno.  |"<<endl;
      cout<<"\t| 2) Selecionar perfil de aluno. |"<<endl;
      cout<<"\t| 3) Sair.                       |"<<endl;         
      cout<<"\t ==============================="<<endl;
      cout<<endl;
      cout<<endl;
      system ("cls")
      return opcao;
}

bool cadastrarAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.txt", std::fstream::app);
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}

bool realizaLeituraArquivo () {
	std::ifstream arquivo;
	arquivo.open("database.txt");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
//		std::cout << linha << "\n"; string == array char
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	for (int i = 0; i < 100; i++) {
		std::cout << "Aluno n " << i+1 << "\n";
		std::cout << "Nome: " << alunos[i].nome << "\n";
		std::cout << "Matricula: " << alunos[i].matricula << "\n";
	}
	
	return true;
}

void funcao1() {
	std::cout << "Cadastrando aluno... \n";
}

void funcao2() {
	std::cout << "Cadastro finalizado, registrando notas ... \n";
}

void funcao3() {
	std::cout << "Aluno selecionado ... \n";
}

void funcao4() {
	std::cout << "Programa finalizado ... \n";
}



switch (opcao)
{
case 1:
	funcao1 ();
	aluno aluno1;
	cout << "1 -> Insira o primeiro nome do aluno: ";
	cin  >> aluno1.nome;
	cout << "2 -> Insira o sobrenome do aluno: ";
	cin  >> aluno1.sobrenome;
	cout << "3 -> Insira o numero de matricula do aluno: ";
	cin  >> aluno1.matricula;
	cout << "Aluno: " << aluno1.nome << " " << aluno1.sobrenome << "\n";
	cout << "Matricula: " << aluno1.matricula << "\n"; 
break;
}


