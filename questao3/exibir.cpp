#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

float salario[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000};

void exibiSalarioFuncionario(int opcao_desejada, float valor_estabelecido)
{
  int quantidade_registrado = 20;

  if (opcao_desejada == 1 || opcao_desejada == 2)
  {
    for (int cadastrado = 0; cadastrado < quantidade_registrado; cadastrado++)
    {
      if (salario[cadastrado] < valor_estabelecido)
        cout << salario[cadastrado] << endl;
    }
  }
  else if (opcao_desejada == 3)
  {
    for (int cadastrado = 0; cadastrado < quantidade_registrado; cadastrado++)
    {
      if (salario[cadastrado] > valor_estabelecido)
        cout << salario[cadastrado] << endl;
    }
  }
  else
  {
    for (int cadastrado = 0; cadastrado < quantidade_registrado; cadastrado++)
    {
      if (salario[cadastrado] >= valor_estabelecido)
        cout << salario[cadastrado] << endl;
    }
  }

  system("pause");
}

void exibiTodosSalariosFuncionario()
{
  int quantidade_registrado = 20;
  
  for (int cadastrado = 0; cadastrado < quantidade_registrado; cadastrado++)
    cout << salario[cadastrado] << endl;
}

main()
{
  int opcao_exibicao;
  const float menor_de_500 = 500, menor_de_1K = 1000, maior_de_4K = 4000, maior_ou_igual_5K = 5000, maior_ou_igual_7K = 7000, maior_ou_igual_10K = 10000;

  do
  {
    system("cls");
    cout << "MENU DE EXIBICAO DOS FUNCIONARIOS \n" << endl;
    cout << "[1] FUNCIONARIOS COM SALARIO INFERIOR A R$ 500" << endl;
    cout << "[2] FUNCIONARIOS COM SALARIO INFERIOR A R$ 1000" << endl;
    cout << "[3] FUNCIONARIOS COM SALARIO SUPERIOR A R$ 4000" << endl;
    cout << "[4] FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 5000" << endl;
    cout << "[5] FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 7000" << endl;
    cout << "[6] FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 10000" << endl;
    cout << "[7] TODOS OS FUNCIONARIOS" << endl;
    cout << "[0] VOLTAR" << endl << endl;
    cout << "OPCAO: ";
    cin >> opcao_exibicao;

    switch (opcao_exibicao)
    {
      case 1:
        cout << "Servido ate 500\n";
        exibiSalarioFuncionario(opcao_exibicao, menor_de_500);
        break;
      
      case 2:
        cout << "Servido ate 1000\n";
        exibiSalarioFuncionario(opcao_exibicao, menor_de_1K);
        break;
        
      case 3:
        cout << "Servido acima de 4000\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_de_4K);
        break;
        
      case 4:
        cout << "Servido acima ou igual a 5000\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_ou_igual_5K);
        break;
        
      case 5:
        cout << "Servido acima ou igual a 7000\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_ou_igual_7K);
        break;
        
      case 6:
        cout << "Servido acima ou igual a 10000\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_ou_igual_10K);
        break;

      case 7:
        cout << "Todos os servidores\n";
        exibiTodosSalariosFuncionario();
        system("pause");
        break;

      case 0:
        break; 
      
      default:
        cout << "\n\t*** OCORREU UM ERRO NA ENTRADA DA OPCAO ***" << endl << endl;
        system("pause");
        break;
    }
  } while (opcao_exibicao != 0);
}