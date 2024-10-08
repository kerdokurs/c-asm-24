#include <stdio.h>

#include "mem.h"
#include "stack.h"

#ifdef DEBUG
  #define PRINT_PARAMS "'%c' (kood = %d)\n", c, c
#else
  #define PRINT_PARAMS "%c", c
#endif

/* Selles enumeratsioonis on toodud kõik Brainfuck'i keele sümbolid. */
enum instructions_e {
    /* Liiguta mälu indeksit paremale. */
    BF_RIGHT      = '>',

    /* Liiguta mälu indeksit vasakule. */
    BF_LEFT       = '<',

    /* Suurenda mälu indeksil olevat väärtust. */
    BF_INCREASE   = '+',

    /* Vähenda mälu indeksil olevat väärtust. */
    BF_DECREASE   = '-',

    /* Loe kasutajalt sisendit ja salvesta see mäluindeksile. */
    BF_READ       = ',',

    /* Trüki välja mälu indeksil olev väärtus char'ina. */
    BF_PRINT      = '.',

    /* Tsükli algus. */
    BF_START_LOOP = '[',

    /* Tsükli lõpp. */
    BF_END_LOOP   = ']',

    /* Trüki silumise informatsioon. */
    BF_DEBUG      = '#'
};

void interpret(const char *program) {
    int i = 0;
    while (program[i] != 0 ) {
        switch (program[i]) {
            case BF_INCREASE:
                mem_inc();
                break;
            case BF_DECREASE:
                mem_dec();
                break;
            case BF_RIGHT:
                mem_right();
                break;
            case BF_LEFT:
                mem_left();
                break;
            case BF_DEBUG:
                mem_printDebug();
                break;
            case BF_READ: {
                char c = getc(stdin);

                // Võimalik, et Windows'i süsteemidel on see vajalik
                /* while (c == '\n' || c == '\r') {
                    c = getc(stdin);
                } */
                mem_set(c);
                break;
            }
            case BF_PRINT: {
                char c = mem_get();
                printf(PRINT_PARAMS);
                break;
            }
            case BF_START_LOOP: {
                if (mem_get() == 0) {
                    int loop = 1;
                    while (loop > 0) {
                        i++;
                        if (program[i] == BF_START_LOOP) {
                            loop++;
                        } else if (program[i] == BF_END_LOOP) {
                            loop--;
                        }
                    }
                } else {
                    stack_push(i);
                }
                break;
            }
            case BF_END_LOOP: {
                i = stack_pop() - 1;
                break;
            }
            default:
                break;
                /* Ignoreerime sümboleid, mida me ei tunne. */
        }

        i++;
    }
}

int main(int argc, char **argv, char **envp) {
    if (argc != 2) {
        fprintf(stderr, "Programmil peab olema üks parameeter, milleks on BF programm!\n");
        return 1;
    }

    interpret(argv[1]);
    return 0;
    /*
    printf("Argumendid:\n");
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("Keskkonnamuutujad:\n");
    for (int i = 0; envp[i] != NULL; i++) {
        printf("envp[%d] = %s\n", i, envp[i]);
    }
    */
}
