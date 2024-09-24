#pragma once

#include <stdint.h>

/**
 * Funksioon mem_inc suurendab indeksiga viidatud
 * massiivi elemendi väärtust ühe võrra.
 * Tagastab uue väärtuse.
 */
int mem_inc(void);

/**
 * Funktsioon mem_dec vähendab indeksiga viidatud
 * massiivi elemendi väärtust ühe võrra.
 * Tagastab uue väärtuse.
 */
int mem_dec(void);

/**
 * Funktsioon mem_left liigutab indeksit vasakuke
 * (vähendab selle väärtust ühe võrra).
 * Kui indeks muutub negatiivseks, siis liiguta
 * see massiivi lõppu.
 * Tagastab indeksi uue väärtuse.
 */
int mem_left(void);

/**
 * Funktsioon mem_right liigutab indeksit paremale
 * (suurendab selle väärtust ühe võrra).
 * Kui indeks läheb üle massiivi piiri, siis liiguta
 * indeks massiivi algusesse.
 * Tagastab indeksi uue väärtuse.
 */
int mem_right(void);

/**
 * Funktsioon mem_get tagastab antud indeksil oleva väärtuse.
 */
int8_t mem_get(void);

/**
 * Funktsioon mem_set salvestab väärtuse praegusele indeksile
 * ja tagastab selle väärtuse.
 */
int8_t mem_set(int8_t v);

/**
 * Funktsioon mem_printDebug trükib välja indeksi väärtuse,
 * mälu väärtuse sellel indeksil ja sellele järgnevad 9 väärtust
 * (kui massiivi piir tuleb ette, siis liigu tagasi algusesse).
 */
void mem_printDebug(void);

