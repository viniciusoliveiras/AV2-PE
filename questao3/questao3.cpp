#include<stdio.h>
#include<stdlib.h>
#include<iostream> 
using namespace std; 
#define NUMERO_DE_FUNCIONARIO 3

typedef struct {
  int CPF, idade;
  char nome, sexo;
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

  quantidade_funcionarios_registrados;
  int problemaExecucao = 0;

  possoAdicionar() ? quantidade_funcionarios_registrados += 1 : problemaExecucao = 1;
  if (problemaExecucao == 1) return;

  cout << "\n\tINFORME OS DADOS DO FUNCIONARIO\n\n";
  cout << "NOME: ";
  cin >> servidor[estreado].nome;

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
    
    default:
      break;
    }
    
  } while (opcao_usuario != 0);
  
  
  return 0; 
}