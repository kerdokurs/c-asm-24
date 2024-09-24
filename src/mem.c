#include "mem.h"

#include <stdbool.h>
#include <stdio.h>

#define MEM_SIZE 40

struct mem_st {
    int index;
    int8_t array[MEM_SIZE];
};

struct mem_st mem = {
    .index = 0,
    .array = {0},
};

int mem_inc(void) {
    return ++mem.array[mem.index];
}

int mem_dec(void) {
    return --mem.array[mem.index];
}

int mem_left(void) {
    mem.index--;
    // FIXME: test
    mem.index %= (MEM_SIZE - 1);
    return mem.index;
}

int mem_right(void) {
    mem.index++;
    mem.index %= MEM_SIZE;
    return mem.index;
}

int8_t mem_get(void) {
    return mem.array[mem.index];
}

int8_t mem_set(int8_t v) {
    mem.array[mem.index] = v;
    return v;
}

void mem_printDebug(void) {
    int windowSize = 10;
    int index = mem.index;

    printf("index: %d [%d..%d]: ", index, index, (index + windowSize - 1) % MEM_SIZE);

    while (windowSize--) {
        printf("%d ", mem.array[index]);
        index++;
        index %= MEM_SIZE;
    }
    printf("\n");
}
