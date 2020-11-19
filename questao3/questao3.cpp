#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream> 
using namespace std; 
#define NUMERO_DE_FUNCIONARIO 3

void adicionar();
void carregaArquivo();

typedef struct {
  int CPF, idade, ID;
  char nome[50], sexo[10];
  float horas_trabalhadas, valor_hora_trabalhada, salario_liquido;
}FUNCIONARIO;

FUNCIONARIO servidor[NUMERO_DE_FUNCIONARIO];
int quantidade_funcionarios_registrados = 0;

int carregarOuCriarFuncionario()
{
  if (quantidade_funcionarios_registrados == 0)
  {
    char opcao_tentativa;

    cout << "  NENHUM FUNCIONARIO ESTA CADASTRADO.\n\nDESEJA FAZER UM NOVO CADASTRO ? (S/n): ";
    cin >> opcao_tentativa;
    if (opcao_tentativa == 'S' || opcao_tentativa == 's') 
      adicionar();

    cout << "DESEJA CARREGAR DADOS A PARTIR DE UM ARQUIVO EXTERNO? (S/n): ";
    cin >> opcao_tentativa;
    if (opcao_tentativa == 'S' || opcao_tentativa == 's') 
      carregaArquivo();
  }
  else
    return 0;
  
  return 1;
}

float calculaDescontoInss(float salario_mensal)
{
  const float valor_maximo_de_oito_por_cento = 1751.82, valor_maximo_de_nove_por_cento = 2919.73, valor_maximo_de_onze_por_cento = 5839.45;
  float desconto_do_inss;

  if (salario_mensal < valor_maximo_de_oito_por_cento)
    desconto_do_inss = (salario_mensal * 8) / 100;
    
  else if (salario_mensal < valor_maximo_de_nove_por_cento)
    desconto_do_inss = (salario_mensal * 9) / 100;
    
  else if (salario_mensal <= valor_maximo_de_onze_por_cento)
    desconto_do_inss = (salario_mensal * 11) / 100;

  else
    desconto_do_inss = (valor_maximo_de_onze_por_cento * 11) / 100;

  return desconto_do_inss;
}

float calculaSalarioLiquido(float horas, float valor_das_horas)
{
  const float diaria_de_trabalho = horas * valor_das_horas;
  const float mes_comercial = 30;
  const float salario_bruto_mensal = diaria_de_trabalho * mes_comercial;
  const float salario_liquido_mensal = salario_bruto_mensal - calculaDescontoInss(salario_bruto_mensal);

  return salario_liquido_mensal;
}

int possoAdicionar()
{
  if (quantidade_funcionarios_registrados >= NUMERO_DE_FUNCIONARIO)
  {
    cout << "\n[ERROR 500] NAO E POSSIVEL ADICIONAR NOVOS FUNCIONARIOS. LIMITE ATINGIDO\n" << endl;
    system("pause");
    return 1;
  }

  return 0;
}

int verificaCPF(int registrado)
{
  for (int analisado = 0; analisado < registrado; analisado++)
  {
    if (servidor[analisado].CPF == servidor[registrado].CPF)
    {
      cout << "\nCPF JA CADASTRADO - FUNCIONARIO CONSTA NOS REGISTROS\n" << endl;
      system("pause");
      return 1;
    }
  }

  return 0;
}

void adicionar()
{
  system("cls");
  cout << "MENU PARA ADICIONAR UM NOVO FUNCIONARIO" << endl << endl;
  int estreado = quantidade_funcionarios_registrados;
  int problemaExecucao = 0;

  problemaExecucao = possoAdicionar();
  if (problemaExecucao) return;

  cout << "\tINFORME OS DADOS DO FUNCIONARIO\n\n";
  cout << "DIGITE O CPF DO FUNCIONARIO: ";
  cin >> servidor[estreado].CPF;

  problemaExecucao = verificaCPF(estreado);
  if (problemaExecucao) return;
  else quantidade_funcionarios_registrados += 1;

  fflush(stdin); // Limpo o Buffer do teclado
  cout << "NOME: ";
  cin >> servidor[estreado].nome; // Armazeno o primeiro nome.

  cout << "SEXO: ";
  cin >> servidor[estreado].sexo;

  cout << "IDADE: ";
  cin >> servidor[estreado].idade;

  cout << "HORAS TRABALHADAS POR DIA: ";
  cin >> servidor[estreado].horas_trabalhadas;

  cout << "VALOR DA HORA TRABALHADA POR DIA: ";
  cin >> servidor[estreado].valor_hora_trabalhada;

  float horas_trabalhadas = servidor[estreado].horas_trabalhadas;
  float valor_hora_trabalhada = servidor[estreado].valor_hora_trabalhada;

  servidor[estreado].salario_liquido = calculaSalarioLiquido(horas_trabalhadas, valor_hora_trabalhada);
  servidor[estreado].ID = estreado;
  
  cout << endl;
  system("pause");
}

void pesquisar()
{
  system("cls");
  char opcao_pesquisa;
  int pesquisa_CPF;

  cout << "MENU DE PESQUISA" << endl << endl;

  if (carregarOuCriarFuncionario()) return;

  cout << "DIGITE O CPF DO FUNCIONARIO QUE DESEJA PESQUISAR: ";
  cin >> pesquisa_CPF;

  system("cls");
  
  for (int analisado = 0; analisado < quantidade_funcionarios_registrados; analisado++)
  {
    int funcionario_nao_encontrado = (quantidade_funcionarios_registrados - 1);
    
    if (servidor[analisado].CPF == pesquisa_CPF)
    {
      cout << "\tPESQUISAR FUNCIONARIOS" << endl << endl;
      cout << "CPF JA CADASTRADO - FUNCIONARIO CONSTA NOS REGISTROS\n" << endl;
      cout << "\tNOME: "<< servidor[analisado].nome << endl;
      cout << "\tIDADE: "<< servidor[analisado].idade << endl;
      cout << "\tSEXO: "<< servidor[analisado].sexo << endl;
      printf("\tSALARIO BRUTO: R$ %.2f\n", (servidor[analisado].horas_trabalhadas * servidor[analisado].valor_hora_trabalhada) * 30);
      printf("\tSALARIO LIQUIDO: R$ %.2f\n\n", servidor[analisado].salario_liquido);
      system("pause");
      break;
    }
    else if (analisado == funcionario_nao_encontrado)
    {
      cout << "PESQUISAR FUNCIONARIOS" << endl << endl;
      cout << "    FUNCIONARIO NAO ESTA CADASTRADO.\n\nDESEJA FAZER UM NOVO CADASTRO ? (S/n): ";
      cin >> opcao_pesquisa;

      if (opcao_pesquisa == 'S' || opcao_pesquisa == 's') adicionar();  
      break;
    }
  }
}

void exibiSalarioFuncionario(int opcao_desejada, float valor_estabelecido)
{
  int mensagem_erro = 1;
  
  if (opcao_desejada == 1 || opcao_desejada == 2)
  {
    for (int cadastrado = 0; cadastrado < quantidade_funcionarios_registrados; cadastrado++)
    {
      if (servidor[cadastrado].salario_liquido < valor_estabelecido)
      {
        cout << "\tNOME: " << servidor[cadastrado].nome << endl;
        printf("\tSALARIO LIQUIDO: R$ %.2f\n\n", servidor[cadastrado].salario_liquido);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "   NENHUM FUNCIONARIO FOI ENCONTRADO.\n       TENTE UMA OUTRA CATEGORIA" << endl << endl;
  }
  else if (opcao_desejada == 3)
  {
    for (int cadastrado = 0; cadastrado < quantidade_funcionarios_registrados; cadastrado++)
    {
      if (servidor[cadastrado].salario_liquido > valor_estabelecido)
      {
        cout << "\tNOME: " << servidor[cadastrado].nome << endl;
        printf("\tSALARIO LIQUIDO: R$ %.2f\n\n", servidor[cadastrado].salario_liquido);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "  \tNENHUM FUNCIONARIO FOI ENCONTRADO.\n\t    TENTE UMA OUTRA CATEGORIA" << endl << endl;
  }
  else
  {
    for (int cadastrado = 0; cadastrado < quantidade_funcionarios_registrados; cadastrado++)
    {
      if (servidor[cadastrado].salario_liquido >= valor_estabelecido)
      {
        cout << "\tNOME: " << servidor[cadastrado].nome << endl;
        printf("\tSALARIO LIQUIDO: R$ %.2f\n\n", servidor[cadastrado].salario_liquido);
        mensagem_erro = 0;
      }
    }

    if (mensagem_erro)
      cout << "  \tNENHUM FUNCIONARIO FOI ENCONTRADO.\n\t    TENTE UMA OUTRA CATEGORIA" << endl << endl;
  }

  system("pause");
}

void exibiTodosSalariosFuncionario()
{
  for (int cadastrado = 0; cadastrado < quantidade_funcionarios_registrados; cadastrado++)
  {
    cout << "\tNOME: " << servidor[cadastrado].nome << endl;
    printf("\tSALARIO LIQUIDO: R$ %.2f\n\n", servidor[cadastrado].salario_liquido);
  }

  // printf("\n TESTE QUANTIDADE: %d\n\n",quantidade_funcionarios_registrados);
}

void exibir()
{
  int opcao_exibicao;
  const float menor_de_500 = 500, menor_de_1K = 1000, maior_de_4K = 4000, maior_ou_igual_5K = 5000, maior_ou_igual_7K = 7000, maior_ou_igual_10K = 10000;

  do
  {
    system("cls");
    cout << "MENU DE EXIBICAO DOS FUNCIONARIOS" << endl << endl;

    if (carregarOuCriarFuncionario()) return;

    cout << "[1] FUNCIONARIOS COM SALARIO INFERIOR A R$ 500" << endl;
    cout << "[2] FUNCIONARIOS COM SALARIO INFERIOR A R$ 1000" << endl;
    cout << "[3] FUNCIONARIOS COM SALARIO SUPERIOR A R$ 4000" << endl;
    cout << "[4] FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 5000" << endl;
    cout << "[5] FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 7000" << endl;
    cout << "[6] FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 10000" << endl;
    cout << "[7] TODOS OS FUNCIONARIOS" << endl << endl;
    cout << "[0] VOLTAR" << endl << endl;
    cout << "OPCAO: ";
    cin >> opcao_exibicao;

    system("cls");

    switch (opcao_exibicao)
    {
      case 1:
        cout << "FUNCIONARIOS COM SALARIO INFERIOR A R$ 500\n\n";
        exibiSalarioFuncionario(opcao_exibicao, menor_de_500);
        break;
      
      case 2:
        cout << "FUNCIONARIOS COM SALARIO INFERIOR A R$ 1000\n\n";
        exibiSalarioFuncionario(opcao_exibicao, menor_de_1K);
        break;
        
      case 3:
        cout << "FUNCIONARIOS COM SALARIO SUPERIOR A R$ 4000\n\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_de_4K);
        break;
        
      case 4:
        cout << "FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 5000\n\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_ou_igual_5K);
        break;
        
      case 5:
        cout << "FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 7000\n\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_ou_igual_7K);
        break;
        
      case 6:
        cout << "FUNCIONARIOS COM SALARIO SUPERIOR OU IGUAL A R$ 10000\n\n";
        exibiSalarioFuncionario(opcao_exibicao, maior_ou_igual_10K);
        break;

      case 7:
        cout << "TODOS OS FUNCIONARIOS\n\n";
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

void salvaArquivo()
{
  system("cls");
  cout << "MENU DE SALVAMENTO OU CARREGAMENTO" << endl;
  cout << "\t *SALVAR ARQUIVO*" << endl << endl;

  if (carregarOuCriarFuncionario()) return;

  FILE *arquivo;
  char nome_arquivo[50];

  cout << "Digite o nome do arquivo externo: "; cin >> nome_arquivo;
  strcat(nome_arquivo,".txt");

  arquivo = fopen(nome_arquivo, "w+");

  if (arquivo == NULL)
  {
    cout << "\n*** ERRO NA GRAVACAO DO ARQUIVO EXTERNO ***" << endl << endl;
    system("pause");
    return;
  }
  else
  {
    for (int gravado = 0; gravado < quantidade_funcionarios_registrados; gravado++)
    {
      fprintf(arquivo, "NOME: %s\n", servidor[gravado].nome);
      fprintf(arquivo, "CPF: %d\n", servidor[gravado].CPF);
      fprintf(arquivo, "SEXO: %s\n", servidor[gravado].sexo);
      fprintf(arquivo, "IDADE: %d\n", servidor[gravado].idade);
      fprintf(arquivo, "HORAS TRABALHADAS: %.f\n", servidor[gravado].horas_trabalhadas);
      fprintf(arquivo, "VALOR HORA TRABALHADA: %.f\n", servidor[gravado].valor_hora_trabalhada);
      fprintf(arquivo, "SALARIO LIQUIDO: %.2f\n", servidor[gravado].salario_liquido);
      fprintf(arquivo, "ID: %d\n\n", servidor[gravado].ID);
    }
  }

  fclose(arquivo);
  cout << "\n*** ARQUIVO EXTERNO SALVO COM SUCESSO ***" << endl << endl;
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

void carregaArquivo()
{
  system("cls");
  cout << "MENU DE SALVAMENTO OU CARREGAMENTO" << endl;
  cout << "\t*CARREGAR ARQUIVO*" << endl << endl;

  char nome_arquivo[50];

  cout << "DIGITE O NOME DO ARQUIVO EXTERNO: "; cin >> nome_arquivo;
  strcat(nome_arquivo,".txt");

  FILE *arquivo;
  arquivo = fopen(nome_arquivo, "r");

  if (arquivo == NULL)
  {
    cout << "\n*** ERRO NO CARREGAMENTO DO ARQUIVO EXTERNO ***" << endl << endl;
    system("pause");
    return;
  }
  else
  {
    quantidade_funcionarios_registrados = atualizaQuantidade(nome_arquivo); // GAMBIARRA

    for (int gravado = 0; gravado < quantidade_funcionarios_registrados; gravado++)
    {
      if (gravado == 0)
      {
        fseek(arquivo, 6, SEEK_SET); fscanf(arquivo, "%s\n", servidor[gravado].nome);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%d\n", &servidor[gravado].CPF);
        fseek(arquivo, 6, SEEK_CUR); fscanf(arquivo, "%s\n", servidor[gravado].sexo);
        fseek(arquivo, 7, SEEK_CUR); fscanf(arquivo, "%d\n", &servidor[gravado].idade);
        fseek(arquivo, 19, SEEK_CUR); fscanf(arquivo, "%f\n", &servidor[gravado].horas_trabalhadas);
        fseek(arquivo, 23, SEEK_CUR); fscanf(arquivo, "%f\n", &servidor[gravado].valor_hora_trabalhada);
        fseek(arquivo, 17, SEEK_CUR); fscanf(arquivo, "%f\n", &servidor[gravado].salario_liquido);
        fseek(arquivo, 4, SEEK_CUR); fscanf(arquivo, "%d\n", &servidor[gravado].ID);
      }
      else
      {
        fseek(arquivo, 6, SEEK_CUR); fscanf(arquivo, "%s\n", servidor[gravado].nome);
        fseek(arquivo, 5, SEEK_CUR); fscanf(arquivo, "%d\n", &servidor[gravado].CPF);
        fseek(arquivo, 6, SEEK_CUR); fscanf(arquivo, "%s\n", servidor[gravado].sexo);
        fseek(arquivo, 7, SEEK_CUR); fscanf(arquivo, "%d\n", &servidor[gravado].idade);
        fseek(arquivo, 19, SEEK_CUR); fscanf(arquivo, "%f\n", &servidor[gravado].horas_trabalhadas);
        fseek(arquivo, 23, SEEK_CUR); fscanf(arquivo, "%f\n", &servidor[gravado].valor_hora_trabalhada);
        fseek(arquivo, 17, SEEK_CUR); fscanf(arquivo, "%f\n", &servidor[gravado].salario_liquido);
        fseek(arquivo, 4, SEEK_CUR); fscanf(arquivo, "%d\n", &servidor[gravado].ID);
      }
    }
  }

  fclose(arquivo);
  cout << "\n*** ARQUIVO EXTERNO CARREGADO COM SUCESSO ***" << endl << endl;
  system("pause");
}

void salvarCarregar()
{
  int opcao_carregar_salvar;
  
  do
  {
    system("cls");
    cout << "MENU DE SALVAMENTO OU CARREGAMENTO" << endl << endl;
    cout << "[1] SALVAR ARQUIVO" << endl;
    cout << "[2] CARREGAR ARQUIVO" << endl << endl;
    cout << "[0] VOLTAR" << endl << endl;
    cout << "OPCAO: ";
    cin >> opcao_carregar_salvar;

    system("cls");
    
    switch (opcao_carregar_salvar)
    {
      case 1:
        salvaArquivo();
        break;
        
      case 2: 
        carregaArquivo();
        break;
        
      case 0:
        break;
      
      default:
        cout << "\n\t*** OCORREU UM ERRO NA ENTRADA DA OPCAO ***" << endl << endl;
        system("pause");
        break;
    }
  } while (opcao_carregar_salvar != 0);
  
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
    cout << "[4] SALVAR / CARREGAR" << endl << endl;
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
    
    case 3:
      exibir();
      break;

    case 4:
      salvarCarregar();
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
  
  return 0; 
}