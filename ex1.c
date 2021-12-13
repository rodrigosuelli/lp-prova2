#include <stdio.h>
#include <string.h>

typedef struct
{
  int matricula;
  char respostas[50];
  int pontos;
} Candidato;

int main()
{
  const int QTD_RESPOSTAS = 50;
  const int NUMERO_MAX_MATRICULAS = 99999; // limitar matricula em 5 digitos
  const char GABARITO[50] = "abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba";

  puts("================================================================");

  // Recece qtd de candidatos
  int QTD_CANDIDATOS;
  do
  {
    puts("Insira a quantidade de candidatos:");
    scanf("%d", &QTD_CANDIDATOS);
  } while (QTD_CANDIDATOS <= 0);

  Candidato candidatos[QTD_CANDIDATOS];

  // Recebe candidatos
  for (int i = 0; i < QTD_CANDIDATOS; i++)
  {
    puts("----------------------------------------------------------------");
    printf("Dados do candidato numero %d:\n", i + 1);

    // Recebe matricula
    int matricula;
    do
    {
      puts("Exemplo: 21995");
      puts("Insira o numero de matricula:");
      scanf("%d", &matricula);

      if (matricula > NUMERO_MAX_MATRICULAS)
      {
        puts("Erro, a matricula deve ter no maximo 5 digitos.");
      }
    } while (matricula > NUMERO_MAX_MATRICULAS || matricula <= 0); // limitar matricula em 5 digitos

    // Recebe respostas
    char respostas[QTD_RESPOSTAS];
    do
    {
      puts("Exemplo: abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba");
      puts("Insira as respostas:");
      scanf("%s", respostas); // scanf does not read strings with spaces

      if (((int)strlen(respostas)) != QTD_RESPOSTAS) // verificar se a resposta tem 50 caracteres
      {
        puts("Erro, a resposta deve ter 50 caracteres");
      }
    } while (((int)strlen(respostas)) != QTD_RESPOSTAS); // verificar se a resposta tem 50 caracteres

    // Popular o array candidatos
    candidatos[i].matricula = matricula;
    strcpy(candidatos[i].respostas, respostas);
    candidatos[i].pontos = 0;
  }

  puts("================================================================");

  // Calcular pontos
  for (int i = 0; i < QTD_CANDIDATOS; i++)
  {
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
      Candidato temp_i = candidatos[i];
      candidatos[i] = candidatos[max];
      candidatos[max] = temp_i;
    }
  }

  // Exibir resultados
  for (int i = 0; i < QTD_CANDIDATOS; i++)
  {
    puts("Matricula | Pontuacao");
    printf("%d          |     %d\n", candidatos[i].matricula, candidatos[i].pontos);
  }

  return 0;
}
