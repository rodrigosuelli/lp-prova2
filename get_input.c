#include <stdio.h>

#include "get_input.h"

int get_int(char message[])
{
  int n;
  char enter_key;

  while (1)
  {
    puts(message);

    if (scanf("%d%c", &n, &enter_key) != 2 || enter_key != '\n')
    {
      scanf("%*s"); // clear buffer
    }
    else
    {
      return n;
    }
  }
}

int get_unsigned_int(char message[])
{
  int n;
  do
  {
    n = get_int(message);
  } while (n < 0);

  return n;
}

int get_positive_int(char message[])
{
  int n;
  do
  {
    n = get_int(message);
  } while (n <= 0);

  return n;
}

float get_float(char message[])
{
  float n;
  char enter_key;

  while (1)
  {
    puts(message);

    if (scanf("%f%c", &n, &enter_key) != 2 || enter_key != '\n')
    {
      scanf("%*s"); // clear buffer
    }
    else
    {
      return n;
    }
  }
}

float get_unsigned_float(char message[])
{
  float n;
  do
  {
    n = get_float(message);
  } while (n < 0);

  return n;
}

float get_positive_float(char message[])
{
  float n;
  do
  {
    n = get_float(message);
  } while (n <= 0);

  return n;
}
