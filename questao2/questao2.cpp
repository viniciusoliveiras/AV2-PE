#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define NUMERO_ALUNO 3

typedef struct {
  char nome[20], sexo[20];
  int matricula, idade;
} DADOS;

DADOS aluno[NUMERO_ALUNO];

float notas[NUMERO_ALUNO][4];
int quantidade_alunos_registrados = 0;

int possoAdicionar()
{
  if (quantidade_alunos_registrados >= NUMERO_ALUNO)
  {
    cout << "\n[ERROR] SISTEMA LOTADO" << endl;
    system("pause");
    return 1;
  }

  return 0;
}

int verificaMatricula(int registrado)
{
  for (int analisado = 0; analisado < registrado; analisado++)
  {
    if (aluno[analisado].matricula == aluno[registrado].matricula)
    {
      cout << "\nALUNO JA ESTA PRESENTE NO SISTEMA" << endl;
      system("pause");
      return 1;
    }
  }

  return 0;
}

float calculaMedia(float av1, float av2, float av3)
{
  float media;
  
  if (av3 > av1 && av2 > av1)
    media = (av3 + av2) / 2;

  else if (av3 > av2 && av1 > av2)
    media = (av3 + av1) / 2;

  else if (av1 == av2 && av1 < av3)
    media = (av3 + av1) / 2;

  else
    media = (av1 + av2) / 2;
  
  return media;
}

void Adicionar()
{
  system("cls");
  cout << "PROGRAMA DE MATRICULA" << endl << endl;
  int novato = quantidade_alunos_registrados;
  int problemaExecucao = 0;

  problemaExecucao = possoAdicionar();
  if (problemaExecucao) return;
  
  cout << "INSIRA A MATRICULA DO ALUNO A SER ADICIONADO: ";
  cin >> aluno[novato].matricula;

  problemaExecucao = verificaMatricula(novato);
  if (problemaExecucao) return;
  else quantidade_alunos_registrados += 1;

  fflush(stdin); // Limpo o Buffer do teclado
  cout << "DIGITE O NOME DO ALUNO: ";
  cin >> aluno[novato].nome;

  cout << "IDADE DO ALUNO: ";
  cin >> aluno[novato].idade;

  cout << "INSIRA A NOTA DA AV1: ";
  cin >> notas[novato][0];

  cout << "INSIRA A NOTA DA AV2: ";
  cin >> notas[novato][1];

  cout << "INSIRA A NOTA DA AV3: ";
  cin >> notas[novato][2];

  float av1 = notas[novato][0], av2 = notas[novato][1], av3 = notas[novato][2]; 
  float media = notas[novato][3] = calculaMedia(av1, av2, av3);

  cout << "MEDIA: " << media << endl << endl;

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
    for (int armazenado = 0; armazenado < quantidade_alunos_registrados; armazenado++)
    {
      fprintf(arquivo,"MATRICULA: %d\n",aluno[armazenado].matricula);
      fprintf(arquivo,"NOME: %s\n",aluno[armazenado].nome);
      fprintf(arquivo,"IDADE: %d\n",aluno[armazenado].idade);
      fprintf(arquivo,"SEXO: %s\n",aluno[armazenado].sexo);
      fprintf(arquivo,"MEDIA: %f\n\n",notas[armazenado][3]);
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
  int opcao_usuario;

  do
  {
    system("cls");
    cout << "PROGRAMA DE MATRICULA" << endl << endl;
    cout << "[1] ADICIONAR" << endl;
    cout << "[2] EXIBIR" << endl;
    cout << "[3] SALVAR / CARREGAR" << endl << endl;
    cout << "[0] SAIR" << endl << endl;
    cout << "OPCAO: ";
    cin >> opcao_usuario;

    switch (opcao_usuario)
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

      case 0:
        break;

      default:
        system("cls");
        cout << "\n\t*** OCORREU UM ERRO NA ENTRADA DA OPCAO ***" << endl << endl;
        system("pause");
        break;
    }

  } while (opcao_usuario != 0);
  
  getchar();
  return 0;
}