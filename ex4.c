#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  char text[256];

  // Get text
  printf("Texto Plano: ");
  scanf("%s", text); // scanf does not read strings with spaces

  // Get text length
  int text_length = strlen(text);

  // Step 1
  for (int i = 0; i < text_length; i++)
  {
    if (isalpha(text[i]))
    {
      text[i] = text[i] + 3; // desloca caracteres alfabéticos 3 posições para a direita
    }
  }

  // Step 2 - Inverte o texto - strrev()
  for (int i = 0; i < text_length / 2; i++)
  {
    int temp_i = text[i];
    text[i] = text[text_length - i - 1];
    text[text_length - i - 1] = temp_i;
  }

  // Step 3
  for (int i = text_length / 2; i < text_length; i++)
  {
    text[i] = text[i] - 1; // desloca caractere a partir da metade em diante (truncada) uma posição para a esquerda
  }

  // Print ciphertext
  printf("Texto Criptografado: ");
  printf("%s\n", text);
  return 0;
}
