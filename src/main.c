#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"
#include "mem.h"

int main(void) {

    mem_inc();
    mem_inc();
    mem_inc();
    mem_inc();

    mem_right();
    mem_inc();
    mem_inc();
    mem_inc();

    for (int i = 0; i < 16; i++) {
        mem_right();
    }
    mem_printDebug();

    return 0;
  stack_push(10);
  stack_push(8);
  stack_push(-40);

  /* Lihtsalt eemaldame pealmise väärtuse (-40) ja ei salvesta seda muutujasse. */
  stack_pop();

  /* Eemaldame pealmise väärtuse ja salvestame selle muutujasse, et saaksime seda ekraanil kuvada. */
  int a = stack_pop();
  printf("%d\n", a);

  // /* Eemaldame veel ühe elemendi ja trükime selle välja sealjuures kasutades juba eelnevalt defineeritud muutujat a. */
  a = stack_pop();
  printf("%d\n", a);

  stack_push(1);
  stack_push(2);
  stack_push(3);
  stack_push(4);
  stack_print();

  int sisend = 0;
  do
  {
    // int unused __attribute__((unused));
    // unused = scanf("%d", &sisend);
    // tegelikult peaks tegema kontrolli (vt scanf dokumentatsiooni)
    if (scanf("%d", &sisend) != 1)
    {
      // fprintf(stderr, "ei tagastanud 1 numbrit\n");
      printf("ei tagastanud 1 numbrit\n");
      // return EXIT_SUCCESS;
      return EXIT_FAILURE;
    }

    if (sisend == 0)
    {
    }
    else if (sisend == 1)
    {
    }
    else if (sisend == 2)
    {
    }
    else
    {
      printf("vale sisend\n");
    }
  } while (true);
}
