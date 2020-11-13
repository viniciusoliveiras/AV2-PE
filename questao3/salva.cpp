#include <stdio.h>
#include <stdlib.h>

typedef struct { char nome[20], rua[20]; int idade;}cadastro;
int main()
{
  FILE *f = fopen("arquivo.txt","wb");
  if (f == NULL)
  {
    printf("Erro na abertura\n");
    system("pause");
    exit(1);
  }

  cadastro cad[4] = {
    "MATEUS","Rua 1", 22,
    "RHUAN", "Rua 2", 21,
    "VINI REI DELAS", "Rua 3", 21,
    "GABRIEL", "Rua 4", 21
  };

  fwrite(cad, sizeof(cadastro), 4, f);
  fclose(f);

  system("pause");
  return 0;
}