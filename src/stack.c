#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

void stack_push(struct stack_st *s, int element) {
    if (s->size == 0 || s->arr == NULL) {
        s->size = 1;
        
        int *arr = malloc(sizeof(int) * s->size);
        s->arr = arr;

        if (s->arr == NULL) {
           fprintf(stderr, "Mälu otsas!\n");
           return;
        }

        s->length = 0;
    } else if (s->length == s->size) {
        int tmp_size = s->size * 2;
        int *tmp_arr = realloc(s->arr, sizeof(int) * tmp_size);

        if (tmp_arr == NULL) {
            fprintf(stderr, "Mäluala suuruse muutmine ebaõnnestus.\n");
            return;
        }

        s->arr = tmp_arr;
        s->size = tmp_size;
    }

    s->arr[s->length] = element;
    s->length++;
}

int stack_pop(struct stack_st *s) {
    if (stack_isEmpty(s)) {
        return 0;
    }

    int element = s->arr[s->length - 1];
    s->length--;

    if (s->length == 0) {
        s->size = 0;
        free(s->arr);
        s->arr = NULL;
    } else if (s->length <= s->size / 4) {
        int tmp_size = s->size / 2;
        int *tmp_arr = realloc(s->arr, sizeof(int) * tmp_size);

        if (tmp_arr == NULL) {
            fprintf(stderr, "Mäluala suuruse muutmine ebaõnnestus.\n");
            return -1;
        }

        s->arr = tmp_arr;
        s->size = tmp_size;
    }

    return element;
}

bool stack_isEmpty(struct stack_st *s) {
    return !(s->length > 0);
}

int stack_peek(struct stack_st *s) {
    if (stack_isEmpty(s)) {
        return 0;
    }

    return s->arr[s->length - 1];
}

void stack_print(struct stack_st *s) {
    for (int i = s->length - 1; i >= 0; i--) {
        printf("%d\n", s->arr[i]);
    }
}
