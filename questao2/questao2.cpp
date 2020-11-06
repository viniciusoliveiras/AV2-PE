#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define NUMERO_ALUNO 3

/*  QUESTÃO 2
Faça um programa, utilizando o Dev-C++, para armazenar os dados de um aluno(a), contendo os seguintes dados:

Variáveis	            Tipos
Matricula	            inteiro
Nome	                caractere
Sexo	                caractere
Idade	                inteiro
AV1, AV2, AV3 e Media	real
(UTILIZE UMA MATRIZ PARA ARMAZENAR AS NOTAS)

O usuário poderá armazenar no máximo 50 alunos. O programa terá a opção de adicionar, exibir ou salvar/carregar os dados. O programa deverá ter as seguintes condições:

  Adicionar:
Efetua uma pesquisa para saber se o aluno(a) existe ou não no vetor através da matrícula do mesmo:
 • Se existir, informar que o aluno(a) já se encontra presente e não adicione
 • Caso não exista, verifique se o sistema está ou não lotado antes de inseri
Ao armazenar as notas utilize o mesmo critério de avaliação da UniCarioca para calcular a média, está não deve ser informada pelo aluno (Soma das 2 maiores notas divididos pela quantidade).

  Exibir:
O usuário poderá exibir os alunos(as) com os seguintes critérios de média:
 • Alunos reprovados com média inferior a 5
 • Alunos reprovados com média inferior a 7
 • Alunos reprovados

 • Alunos aprovados com média superior ou igual a 7
 • Alunos aprovados com média superior ou igual a 9
 • Alunos aprovados
 • Todos os alunos

  Salvar/Carregar
O usuário irá escolher entre salvar ou carregar um arquivo externo
 • Colocar um campo para o usuário informar o nome do arquivo externo, tanto na opção de salvar quanto carregar
 • Ao selecionar a opção de carregar dados, o sistema deve ler todas as informações do arquivo externo e adicionar no programa
*/

typedef struct {
  char nome[20], sexo[20];
  int matricula, idade;
} DADOS;

DADOS aluno[NUMERO_ALUNO];

float notas[NUMERO_ALUNO][4];
int counter = 0;

void Adicionar()
{
    system("cls");
    cout << "PROGRAMA DE MATRICULA" << endl << endl;
    cout << "INSIRA A MATRICULA DO ALUNO A SER ADICIONADO: ";
    cin >> aluno[counter].matricula;
    for (int i = 0; i < counter; i++)
    {
      if (counter != 0 && aluno[counter].matricula == aluno[i].matricula)
      {
        cout << "\nALUNO JA ESTA PRESENTE NO SISTEMA" << endl;
        system("pause");
        return;
      }
    }
    if (counter >= NUMERO_ALUNO)
    {
      cout << "\n[ERROR] SISTEMA LOTADO" << endl;
      system("pause");
      return;
    }

    cout << "INSIRA A NOTA DA AV1: ";
    cin >> notas[counter][0];
    cout << "INSIRA A NOTA DA AV2: ";
    cin >> notas[counter][1];
    cout << "INSIRA A NOTA DA AV3: ";
    cin >> notas[counter][2];

    float av1 = notas[counter][0], av2 = notas[counter][1], av3 = notas[counter][2];

    if (av3 > av1 && av2 > av1)
    {
      av1 = av3;
    }
    else if (av3 > av2 && av1 > av2)
    {
      av2 = av3;
    }

    cout << "MAIOR NOTA 1: " << av1 << endl;
    cout << "MAIOR NOTA 2: " << av2 << endl;

    notas[counter][3] = (av1 + av2) / 2;
    cout << "MEDIA: " << notas[counter][3] << endl << endl;

    counter++;
    system("pause");
}

void aluno_aprovado(int opcao_usuario)
{
  system("cls");
  if (opcao_usuario == 1)
  {
    printf("ALUNOS APROVADOS COM MEDIA SUPERIOR OU IGUAL A 9\n");
    for (int i = 0; i < NUMERO_ALUNO; i++)
    {
      if (notas[i][3] >= 9)
      {
        printf("\n\tAluno: %d\n", aluno[i].matricula);
        printf("\tMedia: %2.f\n", notas[i][3]);
      }
      else if (i == NUMERO_ALUNO)
      {
        printf("NENHUM ALUNO ENCONTRADO");
      }
    }
  }
  else if (opcao_usuario == 2)
  {
    printf("ALUNOS APROVADOS COM MEDIA SUPERIOR OU IGUAL A 7\n");
    for (int i = 0; i < NUMERO_ALUNO; i++)
    {
      if (notas[i][3] >= 7)
      {
        printf("\n\tAluno: %d\n", aluno[i].matricula);
        printf("\tMedia: %2.f\n", notas[i][3]);
      }
      else if (i == NUMERO_ALUNO)
      {
        printf("NENHUM ALUNO ENCONTRADO");
      }
    }
  }
  system("pause");
}

void aluno_reprovado(int opcao_usuario)
{
  // for (int j = 0; j < NUMERO_ALUNO; j++)
  // {
    system("cls");
    if (notas[counter][3] < 5)
    {
      cout<<"ALUNOS REPROVADOS COM MEDIA INFERIOR A 5\n";
      for (int i = 0; i < NUMERO_ALUNO; i++)
      {
        cout<<"Aluno: "<<aluno[i].matricula<<endl;
        cout<<"Media: "<<notas[i][3]<<endl<<endl;
      }
    }
    else if (notas[counter][3] < 7)
    {
      (opcao_usuario == 1) ? cout<<"ALUNOS REPROVADOS COM MEDIA INFERIOR A 7\n" : cout<<"ALUNOS REPROVADOS\n";
      for (int i = 0; i < NUMERO_ALUNO; i++)
      {
        cout<<"Aluno: "<<aluno[i].matricula<<endl;
        cout<<"Media: "<<notas[i][3]<<endl<<endl;
      }
    }
  // }
  system("pause");
}

void Exibir()
{
  int opcao = 0;
  do
  {
    system("cls");
    cout << "EXIBIR APROVADOS E REPROVADOS\n" << endl;
    cout << "[1] Alunos aprovados com media superior ou igual a 9" << endl;
    cout << "[2] Alunos aprovados (com media superior ou igual 7)" << endl;
    cout << "[7] Todos os alunos" << endl;
    cout << endl;
    cout << "OPCAO: ";
    cin >> opcao;
    switch (opcao)
    {
      case 1:
        aluno_aprovado(opcao);
        break;
      case 2:
        aluno_aprovado(opcao);
        break;
      default:
        break;
    }
  } while (opcao != 0);
  
}

/*void Salvar()
{
  system("cls");
  cout << "PROGRAMA PARA SALVAR ARQUIVO EXTERNO" << endl;
  cout << "SALVAR ARQUIVO" << endl;
  
  FILE *arquivo;
  char nome_arquivo[50];

  cout << "Digite o nome do arquivo externo: "; cin >> nome_arquivo;
  strcat (nome_arquivo,".txt");

  arquivo = fopen(nome_arquivo, "w");

  if (arquivo != NULL){
    fprintf(arquivo,"Alunos reprovados com media inferior a 5: %d\n");
    fprintf(arquivo,"Alunos reprovados com media inferior a 7: %d\n");
    fprintf(arquivo,"Alunos reprovados: %d\n");
    fprintf(arquivo,"Alunos aprovados com media superior a 7: %d\n");
    fprintf(arquivo,"Alunos aprovados com media superior a 9: %d\n");
    fprintf(arquivo,"Alunos aprovados: %d\n");
    fprintf(arquivo,"Todos os Alunos: %d\n", counter);
  }
  else
    cout << "ERRO NA GRAVACAO DO ARQUIVO EXTERNO" << endl;

  fclose(arquivo);
  system("pause");

  // COTELLI
  // FILE *arq;
  // char nome_arq[50];
  // cout<<"Nome do arquivo externo: "; cin>>nome_arq;
  // strcat(nome_arq,".txt");
  // arq = fopen(nome_arq,"w");
}*/

int main()
{
  int op;

  do
  {
    system("cls");
    cout << "PROGRAMA DE MATRICULA" << endl;
    cout << endl;
    cout << "[1] ADICIONAR" << endl;
    cout << "[2] EXIBIR" << endl;
    cout << "[3] SALVAR / CARREGAR" << endl;
    cout << "[0] SAIR" << endl;
    cout << endl;
    cout << "OPCAO: ";
    cin >> op;

    switch (op)
    {
    case 1:
      Adicionar();
      break;
    case 2:
      Exibir();
      break;
    case 3:
      // Salvar();
      break;
    }
  } while (op != 0);
  return 0;
}