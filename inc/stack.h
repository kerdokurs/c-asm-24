#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>

struct stack_st {
    int length;
    int size;
    int *arr;
};

#define EMPTY_STACK (struct stack_st) { 0, 0, NULL }

/*
 * Funktsioon stack_push saab parameetriks int tüüpi väärtuse, mille lisab globaalsesse pinusse, kui
 * selles on veel ruumi. Vastasel korral trükib ekkraanile vea. Funktsioon ei tagasta midagi.
 */
void stack_push(struct stack_st *, int);

/*
 * Funktsioon stack_pop ei saa ühtegi parameetrit ja tagastab globaalse pinu pealmise elemendi, mille ta
 * pinust eemaldab. Kui pinu on juba tühi, siis funktsioon tagastab väärtuse 0.
 */
int stack_pop(struct stack_st *);

/*
 * Funktsioon stack_peek tagastab pinu pealmise elemendi ilma seda eemaldamata.
 * Kui pinu on tühi, siis see tagastab 0 väärtuse.
 */
int stack_peek(struct stack_st *);

/*
 * Funktsioon stack_isEmpty tagastab tõeväärtuse (0-vale ja mitte 0 tõene) vastavalt sellele kas
 * pinu on tühi või mitte.
 */
bool stack_isEmpty(struct stack_st *);

/*
 * Funktsioon stack_print trükib ekraanile kõik pinu elemendid eraldi reale alustades ülemisest.
 */
void stack_print(struct stack_st *);

#endif
