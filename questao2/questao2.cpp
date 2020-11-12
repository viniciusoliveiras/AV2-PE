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
int counter = 0 /*,quant_aluno[]*/;

void Adicionar()
{
    system("cls");
    cout << "PROGRAMA DE MATRICULA" << endl << endl;
    cout << "INSIRA A MATRICULA DO ALUNO A SER ADICIONADO: "; cin >> aluno[counter].matricula;
    cout << "DIGITE O NOME DO ALUNO: "; cin >> aluno[counter].nome;
    cout << "IDADE DO ALUNO: "; cin >> aluno[counter].idade;
    
    
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

    float *av1 = &notas[counter][0], *av2 = &notas[counter][1], *av3 = &notas[counter][2], *media = &notas[counter][3];

    if (*av3 > *av1 && *av2 > *av1)
      *media = (*av3 + *av2) / 2;

    else if (av3 > av2 && av1 > av2)
      *media = (*av3 + *av1) / 2;

    else if (av1 == av2 && av1 < av3)
      *media = (*av3 + *av1) / 2;

    else
      *media = (*av1 + *av2) / 2;

    cout << "MEDIA: " << *media << endl << endl;

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
        printf("\nAluno: %d\n", aluno[i].matricula);
        printf("Media: %.1f\n\n", notas[i][3]);
       /* quant_aluno[]++;*/
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
        printf("\nAluno: %d\n", aluno[i].matricula);
        printf("Media: %.1f\n\n", notas[i][3]);
        /* quant_aluno[]++;*/
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
  system("cls");
  if (opcao_usuario == 3)
  {
    printf("ALUNOS REPROVADOS COM MEDIA INFERIOR A 7\n");
    for (int i = 0; i < NUMERO_ALUNO; i++)
    {
      if (notas[i][3] < 7)
      {
        printf("\nAluno: %d\n", aluno[i].matricula);
        printf("Media: %.1f\n\n", notas[i][3]);
        /* quant_aluno[]++;*/
        
      }
      else if (i == NUMERO_ALUNO)
      {
        printf("NENHUM ALUNO ENCONTRADO");
      }
    }
  }
  else if (opcao_usuario == 4)
  {
    printf("ALUNOS REPROVADOS COM MEDIA INFERIOR A 5\n");
    for (int i = 0; i < NUMERO_ALUNO; i++)
    {
      if (notas[i][3] < 5)
      {
        printf("\nAluno: %d\n", aluno[i].matricula);
        printf("Media: %.1f\n\n", notas[i][3]);
        /* quant_aluno[]++;*/
      }
      else if (i == NUMERO_ALUNO)
      {
        printf("NENHUM ALUNO ENCONTRADO");
      }
    }
  }
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
    cout << "[3] Alunos reprovados (com media inferior a 7)" << endl;
    cout << "[4] Alunos reprovados com media inferior a 5" << endl;
    cout << "[5] Todos Alunos" << endl;
    cout << "[0] VOLTAR" << endl;
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
      case 3:
        aluno_reprovado(opcao);
        break;
      case 4:
        aluno_reprovado(opcao);
        break;
      case 5:
        system("cls");
        printf("TODOS OS ALUNOS\n");
        for (int i = 0; i < NUMERO_ALUNO; i++)
          printf("\n\tAluno: %d\n", aluno[i].matricula);
        system("pause");
      default:
        break;
    }
  } while (opcao != 0);
}

void Salvar()
{
  system("cls");
  cout << "PROGRAMA PARA SALVAR ARQUIVO EXTERNO" << endl;
  cout << "SALVAR ARQUIVO" << endl;
  
  FILE *arquivo;
  char nome_arquivo[50];

  cout << "Digite o nome do arquivo externo: "; cin >> nome_arquivo;
  strcat (nome_arquivo,".txt");

  arquivo = fopen(nome_arquivo, "a+");

  if (arquivo != NULL){
    for (int i = 0; i < counter; i++)
    {
      fprintf(arquivo,": %d\n",aluno[i].matricula);
      fprintf(arquivo,": %d\n",aluno[i].nome);
      fprintf(arquivo,": %d\n",aluno[i].idade);
      fprintf(arquivo,": %d\n\n",aluno[i].sexo);
    }
  }
  else
    cout << "ERRO NA GRAVACAO DO ARQUIVO EXTERNO" << endl;

  fclose(arquivo);
  cout << "ARQUIVO SALVO COM SUCESSO" << endl << endl;
  system("pause");
}

 /*void carregar()
 {
   system("cls");
   cout << "PROGRAMA PARA CARREGAR ARQUIVO EXTERNO" << endl;
   cout << "CARREGAR ARQUIVO" << endl;

   FILE *arquivo;
   char nome_arquivo[50];

   cout << "Nome do arquivo externo: "; cin >> nome_arquivo;
   arquivo = fopen(nome_arquivo, "r");
   
   if (arquivo == NULL)
    	cout << "ERRO AO CARREGAR ARQUIVO EXTERNO" << endl;
   else
   		fseek(arquivo, 42, 0); fscanf(arquivo, "%d\n", quant_aluno[]);
		fseek(arquivo, 42, 1); fscanf(arquivo, "%d\n", quant_aluno[]);
		fseek(arquivo, 19, 1); fscanf(arquivo, "%d\n", quant_aluno[]);
		fseek(arquivo, 41, 1); fscanf(arquivo, "%d\n", quant_aluno[]);
		fseek(arquivo, 41, 1); fscanf(arquivo, "%d\n", quant_aluno[]);
		fseek(arquivo, 18, 1); fscanf(arquivo, "%d\n", quant_aluno[]);
		fseek(arquivo, 17, 1); fscanf(arquivo, "%d\n", quant_aluno[]);	
		
	fclose(arquivo);
  	cout << "ARQUIVO EXTERNO CARREGADO" << endl << endl;
  	system("pause");
} */

void Menu_arquivo_externo()
{
  int opcao = 0;
  do
  {
    system("cls");
    cout << "[1] SALVAR ARQUIVO EXTERNO" << endl;
    cout << "[2] CARREGAR ARQUIVO EXTERNO" << endl;
    cout << "[0] VOLTAR" << endl;
    cout << endl;
    cout << "OPCAO: "; cin >> opcao;

    switch (opcao)
    {
      case 1:
        Salvar();
        break;
      case 2:
        // Carregar();
        break;
	default:
		break;  
    }
  } while (opcao != 0);
}

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
       Menu_arquivo_externo();
      break;
    }
  } while (op != 0);
  
  getchar();
  return 0;
}