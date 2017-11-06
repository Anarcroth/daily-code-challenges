#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int add(int x, int y)
{
  return x + y;
}

int subtract(int x, int y)
{
  short min = SHRT_MIN;

  while (min + y != 0)
    {
      min++;
    }

  return x + min;
}

short multiply(int x, int y)
{
  if (x > 0 && y < 0)
    {
      return multiply(y, x);
    }
  else if (x < 0 && y < 0)
    {
      return multiply(subtract(0, x), subtract(0, y));
    }

  short result = 0;

  for (short i = 0; i < y; i++)
    {
      result = add(result, x);
    }

  return result;
}

short divide(int x, int y)
{
  if (x == 0)
    {
      return 0;
    }
  else if (y == 0)
    {
      return -1;
    }

  if (x < 0 && y > 0)
    {
      return subtract(0, divide(subtract(0, x), y));
    }
  else if (x > 0 && y < 0)
    {
      return subtract(0, divide(x, subtract(0, y)));
    }
  else if (x < 0 && y < 0)
    {
      return divide(subtract(0, x), subtract(0, y));
    }

  short n = 0;

  while (1)
    {
      x = subtract(x, y);

      if (x == 0)
        {
          return n + 1;
        }
      else if (x < 0)
        {
          return -1;
        }

      n++;
    }
}

short power(int x, int y)
{
  short result = 1;

  for (int i = 0; i < y; i++)
    {
      result = multiply(result, x);
    }

  return result;
}

int main()
{
  int x, y;
  char sign;

  printf("%s\n", "Enter the first number: ");
  scanf("%d", &x);
  printf("%s\n", "Add (+), Subtract (-), Multiply (*), Divide (/), Power(^)");
  scanf("%s", &sign);
  printf("%s\n", "Enter the second number: ");
  scanf("%d", &y);

  short result = 0;

  switch (sign)
    {
    case '+':
      result = add(x, y);
      break;
    case '-':
      result = subtract(x, y);
      break;
    case '*':
      result = multiply(x, y);
      break;
    case '/':
      result = divide(x, y);
      break;
    case '^':
      result = power(x, y);
      break;
    default:
      printf("%s\n", "null");
    }

  printf("%d\n", result);
}
