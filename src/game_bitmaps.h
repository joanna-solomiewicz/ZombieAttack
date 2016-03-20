/* PLIK ZAWIERAJĄCY FUNKCJE DOTYCZĄCE BITMAPY GRY */
#pragma once

/* Ładuje bitmapy wykorzystywane w grze.
 * Wywoływana na początku funkcji game. */
void load_game_bitmaps();

/* Usuwa bitmapy wykorzystywane w grze.
 * Wywoływana na końcu funkcji game. */
void destroy_game_bitmaps();

/* Wskaźniki na bitmapy gry:
 * - postać,
 * - tablica wskaźników na zombie,
 * - tło,
 * - zajęte komórki. */
ALLEGRO_BITMAP *daryl_bitmap;
ALLEGRO_BITMAP *zombieT[3];
ALLEGRO_BITMAP *bg;
ALLEGRO_BITMAP *silver_box;

/* Wyświetla ekran po przegranej */
void draw_lost_display();

/* Wyświetla ekran po wygranej */
void draw_win_display();
