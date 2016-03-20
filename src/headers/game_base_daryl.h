/* PLIK ZAWIERAJĄCY FUNKCJE DOTYCZĄCE POSTACI */
#include <allegro5/allegro.h>
#pragma once

/* Obiekt - postać */
struct character *daryl;

/* Tworzy obiekt - postać
 * Wywoływana na początku funkcji game. */
struct character *create_player();

/* Zmienna warunku wygrania gry */
bool win_game;

/* Tablica przechowująca informacje o kierunku
 * poruszania się postaci w trybie bez zatrzymywania. */
bool keep[4];

/* Zmienna kontynuowania rysowania ścieżki. */
int keep_drawing;

/* Poprawia pozycję postaci po każdym przesunięciu tak,
 * aby zawsze poruszała się między kratkami.
 * Wywoływana w funkcji move_daryl po puszczeniu przycisku
 * w trybie z zatrzymywaniem. */
void correct_position();

/* Określa poruszanie postaci w zależności od
 * pola, na którym się znajduje (różne rodzaje ruchu).
 * Wywoływana w funkcji game. */
void move_daryl();

/* Zmiana pozycji postaci w trybie bez zatrzymywania.
 * Wywoływana w funkcji game. */
void keep_moving();

/* Obsługa rysowania ścieżki, sprawdzania kolizji postaci
 * z własną ścieżką oraz sprawdzania warunku wygranej.
 * Wywoływana przy każdym ponownym rysowaniu w funkcji game. */
void path();

