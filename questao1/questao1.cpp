#include <stdlib.h>
#include <iostream>
using namespace std;

/*  QUESTÃO

Faça um algoritmo que crie e implemente uma agenda eletrônica. Agenda deverá armazenar no máximo 100 elementos, contendo nome, idade, telefone e e-mail cada. O programa deve ter um menu com as seguintes opções (UTILIZE FUNÇÕES):

     Adicionar:
Adiciona uma entrada na agenda com o nome, idade, telefone e e-mail de uma pessoa

     Pesquisar:
Pesquisar pelo nome de um usuário. Exiba todas as informações de pessoas com o nome pesquisado

     Exibir:
Exiba todas as informações de pessoas da agenda eletrônica.
*/

void Adicionar()
{
    system("cls");
    cout << "AGENDA" << endl;
    cout << endl;
    cout << "Function Adicionar () is working, bitch" << endl;
    system("pause");
}

void Pesquisar()
{
    system("cls");
    cout << "AGENDA" << endl;
    cout << endl;
    cout << "Function Pesquisar () is working, bitch" << endl;
    system("pause");
}

void Exibir()
{
    system("cls");
    cout << "AGENDA" << endl;
    cout << endl;
    cout << "Function Exibir () is working, bitch" << endl;
    system("pause");
}

main()
{
    int op;

    do
    {
        system("cls");
        cout << "AGENDA" << endl;
        cout << endl;
        cout << "[1] Adicionar" << endl;
        cout << "[2] Pesquisar" << endl;
        cout << "[3] Exibir" << endl;
        cout << "[0] Sair" << endl;
        cout<<endl;
        cout << "OPCAO: ";
        cin >> op;

        switch (op)
        {
        case 1:
            Adicionar();
            break;
        case 2:
            Pesquisar();
            break;
        case 3:
            Exibir();
            break;
        }
    } while (op != 0);
}