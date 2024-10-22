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
    struct stack_st stack = EMPTY_STACK;

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
                    stack_push(&stack, i);
                }
                break;
            }
            case BF_END_LOOP: {
                i = stack_pop(&stack) - 1;
                break;
            }
            default:
                break;
                /* Ignoreerime sümboleid, mida me ei tunne. */
        }

        i++;
    }
}

typedef struct player_t {
    int x;
    int y;

    void (*move)(struct player_t *this, int dx, int dy);
    void (*update)(struct player_t *this, float dt);
} player_t;

void player_move(player_t *this, int dx, int dy) {
    this->x += dx;
    this->y += dy;
}

void player_update(player_t *this, float dt) {
    this->x *= dt;
    this->y *= dt;
}

void enemy_move(player_t *this, int dx, int dy) {
    this->x -= dx;
    this->y -= dy;
}

#include <stdlib.h>

player_t *player_new(int x, int y) {
    player_t *player = malloc(sizeof(player_t));
    player->x = x;
    player->y = y;
    player->move = player_move;
    return player;
}

player_t *enemy_new(int x, int y) {
    player_t *player = malloc(sizeof(player_t));
    player->x = x;
    player->y = y;
    player->move = enemy_move;
    return player;
}

int driver_init(void) {
    int err = 0;
    int *ptr = alloc();
    if (!ptr) {
        return -1;
    }
    int *ptr1 = alloc2();
    if (!ptr1) {
        err = PTR1_FAILED;
        goto cleanup;
    }
    int *ptr2 = alloc2();
    if (!ptr1) {
        err = PTR2_FAILED;
        goto cleanup;
    }

    return OK;

finish_alloc:
    ...
    ptr1;
    ptr2;

    if (!ptr1) {
        goto cleanup;
    }

cleanup:
    free(ptr);
    free(ptr1);
    free(ptr2);
    return err;
}

struct x_st {
    union {
        int x;
        char xs[4];
    } xy;
};

int main(int argc, char **argv, char **envp) {
    player_t *player = player_new(0, 0);
    player_t *enemy = enemy_new(5, 5);
    printf("(%d, %d)\n", player->x, player->y);
    printf("(%d, %d)\n", enemy->x, enemy->y);
    player->move(player, 10, 10);
    enemy->move(enemy, 10, 10);
    printf("(%d, %d)\n", player->x, player->y);
    printf("(%d, %d)\n", enemy->x, enemy->y);

    struct x_st x = { 5 };
    printf("int: %d\n", x.xy.x);
    printf("char[]: %d %d %d %d\n", x.xy.xs[0], x.xy.xs[1], x.xy.xs[2], x.xy.xs[3]);
    printf("%ld\n", sizeof(struct x_st));

    return 0;

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
