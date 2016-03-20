/* PLIK ZAWIERAJĄCY FUNKCJE WYKORZYSTYWANE W MENU */
#pragma once

/* Struktura tworząca obiekty wykorzystywane jako napis
 * lub obrazek w menu zawierająca:
 * - pozycję na osi x,
 * - pozycję na osi y.
 * - wskaźnik na bitmapę (dla obrazków),
 * - wskaźnik na czcionkę (dla tekstów). */
struct menu_object {
    float pos_x;
    float pos_y;
    ALLEGRO_BITMAP *bitmap;
    ALLEGRO_FONT *font;
};


/*  Wyświetla theme na początku gry */
void theme();

/* Obiekt - obrazek określający obecnie wybraną opcję menu */
struct menu_object blood;

/* Ładuje czcionki i bitmapy menu.
 * Wywoływana na początku funkcji menu. */
void load_menu_items();

/* Usuwa załadowane czcionki i bitmapy menu.
 * Wywoływana na końcu funkcji menu. */
void destroy_menu_items();

/* Rysuje menu.
 * Wywoływana przy każdym ponownym rysowaniu w funkcji menu. */
void build_menu(float height);
