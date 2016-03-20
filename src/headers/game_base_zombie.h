/* PLIK ZAWIERAJĄCY FUNKCJE DOTYCZĄCE WROGÓW */
#pragma once

/* Tworzy obiekt - wróg.
 * Wywoływana na początku funkcji game. */
void create_zombie();

/* Sprawdza kolizję wroga z rysowaną ścieżką, postacią
 * oraz ze ścianą.
 * Wywoływana w funkcji game. */
void check_bounce(struct list *tmp);

/* Rysuje wszystkich wrogów.
 * Wywoływana przy każdym ponownym rysowaniu w funkcji game. */
void draw_zombie();

