#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void procura()
{
  cout << "Funciona";
  system("pause");
}

main()
{
  float salario[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000};
  int opcao_exibicao;

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
      procura();
      break;
    
    default:
      break;
    }
  } while (opcao_exibicao != 0);
}