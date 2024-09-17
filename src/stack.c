#include "stack.h"

#include <stdio.h>

#define STACK_SIZE 100

struct stack_st
{
  int length;
  int array[STACK_SIZE];
};

struct stack_st stack = {
    .length = 0,
    .array = {0},
};

void stack_push(int element)
{
  if (stack.length >= STACK_SIZE)
  {
    printf("Viga: pinusse rohkem elemente ei mahu\n");
    return;
  }

  stack.array[stack.length] = element;
  stack.length++;
}

int stack_pop(void)
{
  if (stack_isEmpty())
  {
    return 0;
  }

  int element = stack.array[stack.length - 1];
  stack.length--;
  return element;
}

bool stack_isEmpty(void)
{
  return !(stack.length > 0);
}

int stack_peek(void)
{
  if (stack_isEmpty())
  {
    return 0;
  }

  return stack.array[stack.length - 1];
}

void stack_print(void)
{
  for (int i = stack.length - 1; i >= 0; i--)
  {
    printf("%d\n", stack.array[i]);
  }
}
