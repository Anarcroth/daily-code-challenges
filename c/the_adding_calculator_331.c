// Description
//
// Make a calculator that lets the user add, subtract, multiply and divide integers. It should allow exponents too. The user can only enter integers and must expect the result to be integers. The twist is that YOU, the programmer, can only let the program calculate expressions using addition. Only addition. The user can enter 3*2 however you cannot calculate it using multiplication.
// Basically, the programmer is not allowed to multiply, divide and subtract using the operations provided by a programming language. To the programmer, the only accessible direct operation is addition.
// Your calculator should be able to handle addition, subtraction, division, multiplication and exponents. No modulo operation (to obtain the remainder for two given operands) too.
// Please note that
// You are not allowed to use any functions (other than user-defined functions) to work with exponents. Basically, don't cheat by allowing pre-defined functions from a library for the dirty work.
// You can use logical operators.
// The only binary arithmetic operator that you can use is + (addition).
// The only unary operator that you can use is ++ (increment operator).
// No bitwise operations are allowed.
// Input description
//
// Allow the user to enter two integers and the operation symbol.
// Let's use ^ for exponents i.e. 2^3 = 23 = 8
// Output description
//
// If the answer is an integer, display the answer. If the answer is not an integer, display a warning message. Handle errors like 1/0 appropriately.
// Challenge Inputs and Outputs
//
// Input	Output
// 12 + 25	37
// -30 + 100	70
// 100 - 30	70
// 100 - -30	130
// -25 - 29	-54
// -41 - -10	-31
// 9 * 3	27
// 9 * -4	-36
// -4 * 8	-32
// -12 * -9	108
// 100 / 2	50
// 75 / -3	-25
// -75 / 3	-25
// 7 / 3	Non-integral answer
// 0 / 0	Not-defined
// 5 ^ 3	125
// -5 ^ 3	-125
// -8 ^ 3	-512
// -1 ^ 1	-1
// 1 ^ 1	1
// 0 ^ 5	0
// 5 ^ 0	1
// 10 ^ -3	Non-integral answer
// Bonus
//
// Modify your program such that it works with decimals (except for ^ operation) with a minimum precision of 1 decimal place.

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
