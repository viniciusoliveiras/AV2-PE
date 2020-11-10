#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
using namespace std; 
#define NUMERO_DE_FUNCIONARIO 3

typedef struct {
  int CPF, idade;
  char nome[50], sexo[10];
  float horas_trabalhadas, valor_hora_trabalhada, salario_liquido;
}FUNCIONARIO;

FUNCIONARIO servidor[NUMERO_DE_FUNCIONARIO];
int quantidade_funcionarios_registrados = 0;

int possoAdicionar()
{
  int registrado = quantidade_funcionarios_registrados;
  
  for (int analisado = 0; analisado < registrado; analisado++)
  {
    if (servidor[analisado].CPF == servidor[registrado].CPF)
    {
      cout << "\nCPF JA CADASTRADO - FUNCIONARIO CONSTA NOS REGISTROS\n" << endl;
      system("pause");
      return 0;
    }
  }

  if (quantidade_funcionarios_registrados >= NUMERO_DE_FUNCIONARIO)
  {
    cout << "\n[ERROR 500] NAO E POSSIVEL ADICIONAR NOVOS FUNCIONARIOS. LIMITE ATINGIDO\n" << endl;
    system("pause");
    return 0;
  }

  return 1;
}

void adicionar()
{
  int estreado = quantidade_funcionarios_registrados;
  system("cls");
  cout << "ADICIONAR FUNCIONARIO" << endl << endl;
  cout << "DIGITE O CPF DO FUNCIONARIO: ";
  cin >> servidor[estreado].CPF;

  int problemaExecucao = 0;

  possoAdicionar() ? quantidade_funcionarios_registrados += 1 : problemaExecucao = 1;
  if (problemaExecucao == 1) return;

  fflush(stdin); // Limpo o Buffer do teclado
  cout << "\n\tINFORME OS DADOS DO FUNCIONARIO\n\n";
  cout << "NOME: ";
  fgets(servidor[estreado].nome, 50, stdin); // Armazeno o nome completo, inclusive com espaços.

  cout << "SEXO: ";
  cin >> servidor[estreado].sexo;

  cout << "IDADE: ";
  cin >> servidor[estreado].idade;

  cout << "HORAS TRABALHADAS: ";
  cin >> servidor[estreado].horas_trabalhadas;

  cout << "VALOR DA HORA TRABALHADA: ";
  cin >> servidor[estreado].valor_hora_trabalhada;
  
  system("pause");
}

void pesquisar()
{
  system("cls");
  char opcao_pesquisa;
  int pesquisa_CPF;

  cout << "PESQUISAR FUNCIONARIOS" << endl << endl;
  cout << "DIGITE O CPF DO FUNCIONARIO QUE DESEJA PESQUISAR: ";
  cin >> pesquisa_CPF;

  system("cls");
  
  for (int analisado = 0; analisado <= quantidade_funcionarios_registrados; analisado++)
  {
    if (servidor[analisado].CPF == pesquisa_CPF)
    {
      cout << "\tPESQUISAR FUNCIONARIOS" << endl << endl;
      cout << "CPF JA CADASTRADO - FUNCIONARIO CONSTA NOS REGISTROS\n" << endl;
      cout << "   NOME: "<< servidor[analisado].nome;
      cout << endl;
      system("pause");
      break;
    }
    else 
    {
      cout << "PESQUISAR FUNCIONARIOS" << endl << endl;
      cout << "    FUNCIONARIO NAO ESTA CADASTRADO.\n\nDESEJA FAZER UM NOVO CADASTRO ? (S/n): ";
      cin >> opcao_pesquisa;

      if (opcao_pesquisa == 'S' || opcao_pesquisa == 's') adicionar();  
      break;
    }
  }
}

main()
{
  int opcao_usuario;

  do
  {
    system("cls");
    cout << "CONTROLE DE FUNCIONARIO\n" << endl;
    cout << "[1] ADICIONAR" << endl;
    cout << "[2] PESQUISAR" << endl;
    cout << "[3] EXIBIR" << endl;
    cout << "[4] SALVAR / CARREGAR" << endl;
    cout << "[0] SAIR" << endl;
    cout << endl;
    cout << "OPCAO: ";
    cin >> opcao_usuario;

    switch (opcao_usuario)
    {
    case 1:
      adicionar();
      break;

    case 2:
      pesquisar();
      break;
    
    default:
      break;
    }
    
  } while (opcao_usuario != 0);
  
  return 0; 
}