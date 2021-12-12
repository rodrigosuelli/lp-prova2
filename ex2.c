#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int codigo;
  char descricao;
  float precounit;
} Produto;

typedef struct
{
  int numitem;
  int codigoprod;
  int qtd;
  float *precototal;
} Carrinho;

#define MAX 100
typedef struct Produto *ptr_prod;
ptr_prod p_prod[MAX];

int main()
{

  while (opc != 2)
  {
    system("cls");
    printf("1. Cadastro do Produto \n");
    printf("2. Abrir Venda \n");
    printf("Escolha sua opcao: ");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
      while (opc != 3)
      {
        system("cls");
        printf("1. Inserir \n");
        printf("2. Listar \n");
        printf("3. Voltar \n");
        printf("Escolha sua opcao: ");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
          inserir();
          break;
        case 2:
          listar();
          break;
        case 3:
          main();
          break;
        default:
          printf("Opcao invalida \n");
        }
      }
      break;
    case 2:
      printf("VENDA\nEscolha a opcao:");
      while (opc != 3)
      {
        system("cls");
        printf("1. Incluir Item \n");
        printf("2. Fechar Venda \n");
        printf("3. Voltar\n");
        printf("Escolha sua opcao: \n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
          printf("Ïnserir venda\n");
          inserir();
          break;
        case 2:
          printf("Fechar Venda\n");
          break;
        case 9:
          main();
          break;
        default:
          printf("Opcao invalida \n");
        }
      }
    }
  }
  return 0;
}
