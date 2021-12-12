#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "get_input.h"

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
      text[i] = text[i] + 3;
    }
  }

  // Step 2
  for (int i = 0; i < text_length / 2; i++)
  {
    int temp_i = text[i];
    text[i] = text[text_length - i - 1];
    text[text_length - i - 1] = temp_i;
  }

  // // // Step 3
  for (int i = text_length / 2; i < text_length; i++)
  {
    text[i] = text[i] - 1;
  }

  // Print ciphertext
  printf("Texto Criptografado: ");
  printf("%s\n", text);
  return 0;
}
