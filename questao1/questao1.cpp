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

typedef struct
{
    char nome[20], email[50];
    int idade, telefone;
} user;

user contato[2];
int counter = 0;

void Adicionar()
{
    system("cls");
    cout << "AGENDA" << endl;
    cout << endl;

    cout << "ADICIONAR NOVO CONTATO" << endl;
    cout << endl;
    cout << endl;

    cout << "Nome: ";
    cin >> contato[counter].nome;

    cout << endl;
    cout << "Idade: ";
    cin >> contato[counter].idade;

    cout << endl;
    cout << "Telefone: ";
    cin >> contato[counter].telefone;

    cout << endl;
    cout << "E-mail: ";
    cin >> contato[counter].email;

    counter++;

    cout << endl;
    system("pause");
}

void Pesquisar()
{
    system("cls");
    cout << "AGENDA" << endl;
    cout << endl;
    cout << "[ERROR] Function unavailable. Try again later" << endl;
    system("pause");
}

void Exibir()
{
    system("cls");
    cout << "AGENDA" << endl;
    cout << endl;
    cout << "EXIBIR TODOS OS CONTATOS" << endl;
    cout << endl;
    cout << endl;

    if (contato[0].idade == NULL)
    {
        cout << "Nao ha contatos salvos na agenda."<<endl;
        cout<<endl;
    }
    else
    {
        for (int i = 0; i < counter; i++)
        {
            cout << "NOME: " << contato[i].nome << endl;
            cout << "IDADE: " << contato[i].idade << endl;
            cout << "TELEFONE: " << contato[i].telefone << endl;
            cout << "E-MAIL: " << contato[i].email << endl;
            cout << endl;
            cout << "------------------------" << endl;
            cout << endl;
        }
    }

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
        cout << endl;
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