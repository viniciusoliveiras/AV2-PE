#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
#define NUMERO_ALUNO 3

void Adicionar();
void Carregar();

typedef struct
{
  char nome[20], sexo[20];
  int matricula, idade, ID;
} DADOS;

DADOS aluno[NUMERO_ALUNO];

float notas[NUMERO_ALUNO][4];
int quantidade_alunos_registrados = 0;

int carregarOuCriarFuncionario()
{
  if (quantidade_alunos_registrados == 0)
  {
    char opcao_tentativa;

    cout << "  NENHUM ALUNO ESTA CADASTRADO.\n\nDESEJA FAZER UM NOVO CADASTRO ? (S/n): ";
    cin >> opcao_tentativa;
    if (opcao_tentativa == 'S' || opcao_tentativa == 's')
    {
      Adicionar();
      return 1;
    }

    cout << "DESEJA CARREGAR DADOS A PARTIR DE UM ARQUIVO EXTERNO? (S/n): ";
    cin >> opcao_tentativa;
    if (opcao_tentativa == 'S' || opcao_tentativa == 's')
    {
      Carregar();
      return 1;
    }
  }
  else
  {
    return 0;
  }

  return 1;
}

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
  if (problemaExecucao)
    return;

  cout << "INSIRA A MATRICULA DO ALUNO A SER ADICIONADO: ";
  cin >> aluno[novato].matricula;

  problemaExecucao = verificaMatricula(novato);
  if (problemaExecucao) return;
  else quantidade_alunos_registrados += 1;

  fflush(stdin); // Limpo o Buffer do teclado
  cout << "DIGITE O NOME DO ALUNO: ";
  cin >> aluno[novato].nome;

  cout << "SEXO DO ALUNO: ";
  cin >> aluno[novato].sexo;

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

  aluno[novato].ID = novato;

  cout << "MEDIA: " << media << endl << endl;

  system("pause");
}

void aluno_aprovado(int opcao_usuario)
{
  system("cls");

  int mensagem_erro = 1;

  if (opcao_usuario == 1)
  {
    printf("ALUNOS APROVADOS COM MEDIA SUPERIOR OU IGUAL A 9\n");

    for (int cadastrado = 0; cadastrado < quantidade_alunos_registrados; cadastrado++)
    {
      if (notas[cadastrado][3] >= 9)
      {
        printf("\nAluno: %d\n", aluno[cadastrado].matricula);
        printf("Media: %.1f\n\n", notas[cadastrado][3]);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "NENHUM ALUNO ENCONTRADO";
  }
  else if (opcao_usuario == 2)
  {
    printf("ALUNOS APROVADOS COM MEDIA SUPERIOR OU IGUAL A 7\n");
    for (int cadastrado = 0; cadastrado < quantidade_alunos_registrados; cadastrado++)
    {
      if (notas[cadastrado][3] >= 7)
      {
        printf("\nAluno: %d\n", aluno[cadastrado].matricula);
        printf("Media: %.1f\n\n", notas[cadastrado][3]);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "NENHUM ALUNO ENCONTRADO";
  }
  system("pause");
}

void aluno_reprovado(int opcao_usuario)
{
  system("cls");

  int mensagem_erro = 1;

  if (opcao_usuario == 3)
  {
    printf("ALUNOS REPROVADOS COM MEDIA INFERIOR A 7\n");
    for (int cadastrado = 0; cadastrado < quantidade_alunos_registrados; cadastrado++)
    {
      if (notas[cadastrado][3] < 7)
      {
        printf("\nAluno: %d\n", aluno[cadastrado].matricula);
        printf("Media: %.1f\n\n", notas[cadastrado][3]);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "NENHUM ALUNO ENCONTRADO";
  }
  else if (opcao_usuario == 4)
  {
    printf("ALUNOS REPROVADOS COM MEDIA INFERIOR A 5\n");
    for (int cadastrado = 0; cadastrado < quantidade_alunos_registrados; cadastrado++)
    {
      if (notas[cadastrado][3] < 5)
      {
        printf("\nAluno: %d\n", aluno[cadastrado].matricula);
        printf("Media: %.1f\n\n", notas[cadastrado][3]);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "NENHUM ALUNO ENCONTRADO";
  }
  system("pause");
}

void Exibir()
{
  int opcao_exibir;
  do
  {
    system("cls");
    cout << "EXIBIR APROVADOS E REPROVADOS\n" << endl;
    cout << "[1] Alunos aprovados com media superior ou igual a 9" << endl;
    cout << "[2] Alunos aprovados (com media superior ou igual 7)" << endl;
    cout << "[3] Alunos reprovados (com media inferior a 7)" << endl;
    cout << "[4] Alunos reprovados com media inferior a 5" << endl;
    cout << "[5] Todos Alunos" << endl << endl;
    cout << "[0] VOLTAR" << endl << endl;
    cout << "OPCAO: ";
    cin >> opcao_exibir;
    switch (opcao_exibir)
    {
      case 1:
        aluno_aprovado(opcao_exibir);
        break;

      case 2:
        aluno_aprovado(opcao_exibir);
        break;

      case 3:
        aluno_reprovado(opcao_exibir);
        break;

      case 4:
        aluno_reprovado(opcao_exibir);
        break;

      case 5:
        system("cls");
        printf("TODOS OS ALUNOS\n");
        for (int cadastrado = 0; cadastrado < quantidade_alunos_registrados; cadastrado++)
          printf("\n\tAluno: %d\n", aluno[cadastrado].matricula);
        system("pause");
        break;

      case 0:
        break;

      default:
        cout << "\n\t*** OCORREU UM ERRO NA ENTRADA DA OPCAO ***" << endl << endl;
        system("pause");
        break;
    }
  } while (opcao_exibir != 0);
}

void Salvar()
{
  system("cls");
  cout << "PROGRAMA PARA SALVAR ARQUIVO EXTERNO" << endl;
  cout << "\t *SALVAR ARQUIVO*" << endl << endl;

  if (carregarOuCriarFuncionario())
    return;

  FILE *arquivo;
  char nome_arquivo[50];

  cout << "Digite o nome do arquivo externo: ";
  cin >> nome_arquivo;
  strcat(nome_arquivo, ".txt");

  arquivo = fopen(nome_arquivo, "w+");

  if (arquivo == NULL)
  {
    cout << "ERRO NA GRAVACAO DO ARQUIVO EXTERNO" << endl;
    system("pause");
    return;
  }
  else
  {
    for (int armazenado = 0; armazenado < quantidade_alunos_registrados; armazenado++)
    {
      fprintf(arquivo, "NOME: %s\n", aluno[armazenado].nome);
      fprintf(arquivo, "MATRICULA: %d\n", aluno[armazenado].matricula);
      fprintf(arquivo, "IDADE: %d\n", aluno[armazenado].idade);
      fprintf(arquivo, "SEXO: %s\n", aluno[armazenado].sexo);
      fprintf(arquivo, "AV1: %.1f\n", notas[armazenado][0]);
      fprintf(arquivo, "AV2: %.1f\n", notas[armazenado][1]);
      fprintf(arquivo, "AV3: %.1f\n", notas[armazenado][2]);
      fprintf(arquivo, "MEDIA: %.1f\n", notas[armazenado][3]);
      fprintf(arquivo, "ID: %d\n\n", aluno[armazenado].ID);
    }
  }

  fclose(arquivo);
  cout << "\n*** ARQUIVO SALVO COM SUCESSO ***" << endl << endl;
  system("pause");
}

int atualizaQuantidade(char *nome)
{
  int tamanho_total;
  FILE *id;
  id = fopen(nome, "r");
  if (id == NULL)
  {
    cout << "\n*** ERRO NO CARREGAMENTO DO ARQUIVO EXTERNO ***" << endl << endl;
    system("pause");
  }
  else
  {
    fseek(id, -5, SEEK_END);
    fscanf(id, "%d", &tamanho_total);
  }
  fclose(id);
  return tamanho_total + 1;
}

void Carregar()
{
  system("cls");
  cout << "PROGRAMA PARA CARREGAR ARQUIVO EXTERNO" << endl;
  cout << "CARREGAR ARQUIVO" << endl;

  FILE *arquivo;
  char nome_arquivo[50];

  cout << "Nome do arquivo externo: ";
  cin >> nome_arquivo;
  arquivo = fopen(nome_arquivo, "r");

  if (arquivo == NULL)
  {
    cout << "\n*** ERRO NO CARREGAMENTO DO ARQUIVO EXTERNO ***" << endl << endl;
    system("pause");
    return;
  }
  else
  {
    quantidade_alunos_registrados = atualizaQuantidade(nome_arquivo);
    
    for (int gravado = 0; gravado < quantidade_alunos_registrados; gravado++)
    {
      if (gravado == 0)
      {
        fseek(arquivo, 6, SEEK_SET); fscanf(arquivo, "%s\n", aluno[gravado].nome);
        fseek(arquivo, 11, SEEK_CUR); fscanf(arquivo, "%d\n", &aluno[gravado].matricula);
        fseek(arquivo, 7, SEEK_CUR); fscanf(arquivo, "%d\n", &aluno[gravado].idade);
        fseek(arquivo, 6, SEEK_CUR); fscanf(arquivo, "%s\n", aluno[gravado].sexo);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][0]);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][1]);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][2]);
        fseek(arquivo, 7, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][3]);
        fseek(arquivo, 4, SEEK_CUR); fscanf(arquivo, "%d\n", &aluno[gravado].ID);
      }
      else
      {
        fseek(arquivo, 6, SEEK_CUR); fscanf(arquivo, "%s\n", aluno[gravado].nome);
        fseek(arquivo, 11, SEEK_CUR); fscanf(arquivo, "%d\n", &aluno[gravado].matricula);
        fseek(arquivo, 7, SEEK_CUR); fscanf(arquivo, "%d\n", &aluno[gravado].idade);
        fseek(arquivo, 6, SEEK_CUR); fscanf(arquivo, "%s\n", aluno[gravado].sexo);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][0]);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][1]);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][2]);
        fseek(arquivo, 7, SEEK_CUR); fscanf(arquivo, "%f\n", &notas[gravado][3]);
        fseek(arquivo, 4, SEEK_CUR); fscanf(arquivo, "%d\n", &aluno[gravado].ID);
      }
    }
  }

  fclose(arquivo);
  cout << "\n*** ARQUIVO EXTERNO CARREGADO COM SUCESSO ***" << endl << endl;
  system("pause");
}

void Menu_arquivo_externo()
{
  int opcao_arquivo_externo;

  do
  {
    system("cls");
    cout << "[1] SALVAR ARQUIVO EXTERNO" << endl;
    cout << "[2] CARREGAR ARQUIVO EXTERNO" << endl << endl;
    cout << "[0] VOLTAR" << endl << endl;
    cout << "OPCAO: ";
    cin >> opcao_arquivo_externo;

    switch (opcao_arquivo_externo)
    {
    case 1:
      Salvar();
      break;

    case 2:
      Carregar();
      break;

    case 0:
      break;

    default:
      cout << "\n\t*** OCORREU UM ERRO NA ENTRADA DA OPCAO ***" << endl << endl;
      system("pause");
      break;
    }
  } while (opcao_arquivo_externo != 0);
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