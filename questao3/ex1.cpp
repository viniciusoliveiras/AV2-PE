#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int main()
{
  typedef struct { char nome[20], rua[20]; int idade;}cadastro;
  cadastro pessoa[2];
  
  printf("Nome0: "); scanf("%s", pessoa[0].nome);
  printf("Rua: "); scanf("%s", pessoa[0].rua);
  printf("Idade: "); cin >> pessoa[0].idade;
  printf("OLHA A IDADE: %d", pessoa[0].idade);

  // printf("Nome1: "); scanf("%s", pessoa[1].nome);
  // printf("Rua: "); scanf("%s", pessoa[1].rua);
  // printf("Idade: "); scanf("%d", pessoa[1].idade);


  FILE *arquivo = fopen("arquivo.txt", "a+");

  if (arquivo == NULL)
  {
    printf("\n*** ERRO NA GRAVACAO DO ARQUIVO EXTERNO ***\n\n");
    system("pause");
    exit(1);
  }
  else
  {
    fprintf(arquivo, "NOME: %s\n", pessoa[0].nome);
    fprintf(arquivo, "RUA: %s\n", pessoa[0].rua);
    fprintf(arquivo, "IDADE: %d\n", pessoa[0].idade);
  }
  fclose(arquivo);

  return 0;
}