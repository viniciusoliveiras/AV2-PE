#include <stdio.h>
#include <stdlib.h>

typedef struct { char nome[20], rua[20]; int idade;}cadastro;
cadastro pessoa[2];
int main()
{
  FILE *f = fopen("arquivo.txt","r");
  if (f == NULL)
  {
    printf("Erro na abertura\n");
    system("pause");
    exit(1);
  }
  char texto0[20], texto1[20], texto2[20];
  fscanf(f, "%s %s\n",texto0, pessoa[0].nome);
  fscanf(f, "%s %s\n",texto1, pessoa[0].rua);
  fscanf(f, "%s %d\n",texto2, &pessoa[0].idade);
  
  for (int i = 0; i < 1; i++)
    printf("%s %s\n %s\n %d\n", texto0, pessoa[i].nome, texto1, pessoa[i].rua, texto2, pessoa[i].idade);

  fclose(f);
  system("pause");
  return 0;
}