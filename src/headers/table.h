/* PLIK ZAWIERAJĄCY FUNKCJE DOTYCZĄCE OPERACJI NA TABLICY */
#pragma once
#include <allegro5/allegro.h>

/* Zmienne dotyczące tablicy określającej stan kafelków
 * na wyświetlaczu:
 * - wskaźnik na tablicę dynamiczną,
 * - szerokość tablicy,
 * - wysokość tablicy,
 * - rozmiar komórki tablicy. */
int **T;
int T_width;
int T_height;
int T_size;

/* Zmienna określająca % zajętego pola. */
int taken_fields;

/* Zmienna określająca ilość wszystkich pól. */
int fields;

/* Tworzy początkową tablicę wypełnioną na brzegach.
 * Wywoływana na początku funkcji game. */
void start_table();

/* Rysuje kafelki w zależności od ich stanu.
 * Wywoływana przy każdym ponownym rysowaniu
 * w funkcji game. */
void draw_table();

