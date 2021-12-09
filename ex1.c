#include <stdio.h>
#include <string.h>

#include "get_input.h"

typedef struct
{
  int matricula;
  char *respostas;
  int pontos;
} candidato;

int main()
{
  const int QTD_RESPOSTAS = 50;
  const int NUMERO_MAX_MATRICULAS = 99999; // limitar matricula em 5 digitos
  const char GABARITO[50] = "abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba";

  puts("================================================================");
  const int QTD_CANDIDATOS = get_positive_int("Insira a quantidade de candidatos:");

  candidato candidatos[QTD_CANDIDATOS];

  // Recebe candidatos
  for (int i = 0; i < QTD_CANDIDATOS; i++)
  {
    puts("----------------------------------------------------------------");
    printf("Dados do candidato número %d:\n", i + 1);

    // Recebe matricula
    int matricula;
    do
    {
      puts("Exemplo: 21995");
      matricula = get_positive_int("Insira o numero de matricula:");

      if (matricula > NUMERO_MAX_MATRICULAS)
      {
        puts("Erro, a matricula deve ter no máximo 5 digitos.");
      }
    } while (matricula > NUMERO_MAX_MATRICULAS); // limitar matricula em 5 digitos

    // Recebe respostas
    char *respostas;
    do
    {
      puts("Exemplo: abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba");
      respostas = get_string("Insira as respostas:");
    } while (((int)strlen(respostas) - 1) != QTD_RESPOSTAS); // verificar se a resposta tem 50 caracteres

    if (((int)strlen(respostas) - 1) != QTD_RESPOSTAS) // verificar se a resposta tem 50 caracteres
    {
      puts("Erro, a resposta deve ter 50 caracteres");
    }

    // Popular o array candidatos
    candidatos[i].matricula = matricula;
    candidatos[i].respostas = respostas;
    candidatos[i].pontos = 0;
  }

  puts("================================================================");

  // Calcular pontos
  for (int i = 0; i < QTD_CANDIDATOS; i++)
  {
    // printf("%s", candidatos[i].respostas);
    for (int j = 0; j < QTD_RESPOSTAS; j++)
    {
      if (candidatos[i].respostas[j] == GABARITO[j])
      {
        candidatos[i].pontos++;
      }
    }
  }

  // Ordenar candidatos por pontuação (decrescente) - Selection sort
  for (int i = 0; i < QTD_CANDIDATOS - 1; i++)
  {
    // Find smallest item between i'th item and last item
    int max = i;
    for (int j = i + 1; j < QTD_CANDIDATOS; j++)
    {
      if (candidatos[j].pontos > candidatos[max].pontos)
      {
        max = j;
      }
    }

    // Swap smallest item with i'th item
    if (i != max)
    {
      candidato temp_i = candidatos[i];
      candidatos[i] = candidatos[max];
      candidatos[max] = temp_i;
    }
  }

  // Exibir resultados
  for (int i = 0; i < QTD_CANDIDATOS; i++)
  {
    puts("Matrícula | Pontuação");
    printf("%d          |     %d\n", candidatos[i].matricula, candidatos[i].pontos);
  }

  return 0;
}
