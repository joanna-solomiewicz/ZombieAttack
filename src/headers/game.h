/* PLIK WYWOŁUJĄCY FUNKCJĘ GAME */
#pragma once
#include <allegro5/allegro.h>

/* Główna funkcja obsługująca game */
void game();

/* Zmienna pomocnicza przy rysowaniu ścieżki postaci */
int stop_draw;

/* Zmienna warunku wyjścia z gry */
bool exit_game;

/* Pomocniczy typ wyliczeniowy klawiszy */
enum KEYS { UP,DOWN,LEFT,RIGHT };

/* Tablica przechowująca informacje o stanie
 * klawisza (czy naduszony) */
bool key[4];

/* Struktura tworząca obiekt wykorzystwany jako postać
 * lub przeciwnik zawierająca:
 * - wskaźnik na bitmapę,
 * - pozycję na osi x,
 * - pozycję na osi y,
 * - przesunięcie na osi x,
 * - przesunięcie na osi y,
 * - rozmiar. */
struct character {
    ALLEGRO_BITMAP *pointer;
    int pos_x;
    int pos_y;
    double dx;
    double dy;
    int size;
};
