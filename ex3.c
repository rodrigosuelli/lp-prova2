#include <stdio.h>
#include <string.h>

typedef struct
{
  char nome[256];
  char cpf[11];
} Cliente;

typedef struct
{
  int numero_da_conta;
  Cliente cliente;
  float saldo;
} Conta;

int main(void)
{
  // Cria uma conta
  Conta conta;
  conta.numero_da_conta = 1;
  conta.saldo = 0;

  puts("Criando Conta");

  // Recebe nome do cliente
  do
  {
    puts("Insira o primeiro nome do cliente:");
    scanf("%s", conta.cliente.nome);        // scanf does not read strings with spaces
    if ((strlen(conta.cliente.nome)) > 256) // verificar se o nome é maior que 256 caracteres
    {
      puts("Erro, o nome deve ter no maximo 256 caracteres"); // mensagem de erro
    }
  } while ((strlen(conta.cliente.nome)) > 256); // loop se o nome for maior que 256 caracteres

  // Recebe cpf do cliente
  do
  {
    puts("Insira o cpf do cliente:");
    scanf("%s", conta.cliente.cpf);        // scanf does not read strings with spaces
    if ((strlen(conta.cliente.cpf)) != 11) // verificar se o cpf tem 11 caracteres
    {
      puts("Erro, o cpf deve ter 11 caracteres"); // mensagem de erro
    }
  } while ((strlen(conta.cliente.cpf)) != 11); // loop se o cpf nao tem 11 caracteres

  // Recebe operacao
  int operacao = 0;
  do
  {
    // Printar dados da conta
    puts("=====================");
    printf("Bem vindo, %s\n", conta.cliente.nome);
    printf("Numero da conta: %d\n", conta.numero_da_conta);
    printf("Saldo: R$ %.2f\n", conta.saldo);
    puts("=====================");

    // Printar operações
    puts("Operações disponíveis:");
    puts("1. Deposito");
    puts("2. Saque");
    puts("3. Sair");
    puts("Insira a operacao desejada:");
    scanf("%d", &operacao);
    if (operacao != 1 && operacao != 2 && operacao != 3)
    {
      puts("Erro, operação invalida."); // mensagem de erro
    }
    else
    {
      // Executa operacao selecionada
      switch (operacao)
      {
      case 1:
        puts("Deposito");
        // Recebe valor de deposito
        int valor_deposito;
        do
        {
          puts("Insira o valor que deseja depositar:");
          scanf("%d", &valor_deposito);
          if (valor_deposito <= 0)
          {
            puts("Erro, valor de deposito tem que ser positivo");
          }
          else
          {
            conta.saldo += valor_deposito;
          }
        } while (valor_deposito <= 0);

        break;
      case 2:
        puts("Saque");
        // Recebe valor de saque
        int valor_saque;
        do
        {
          puts("Insira o valor que deseja sacar:");
          scanf("%d", &valor_saque);
          if (valor_saque <= 0)
          {
            puts("Erro, valor de saque tem que ser positivo");
          }
          else if (conta.saldo < valor_saque)
          {
            puts("Erro, voce nao tem saldo suficiente para realizar o saque");
          }
          else
          {
            conta.saldo -= valor_saque;
          }
        } while (valor_saque <= 0);

        break;
      case 3:
        puts("Sair");
        puts("Tchau Tchau!");
        break;
      default:
        puts("Operação invalida!");
        break;
      }
    }
  } while (operacao != 3); // loop se a operacao for diferente de 3

  return 0;
}
