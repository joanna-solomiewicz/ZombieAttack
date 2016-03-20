/* PLIK ZAWIERAJĄCY FUNKCJE DOTYCZĄCE OPERACJI NA LIŚCIE */
#pragma once

/* Struktura listy dynamicznej przechowującej obiekty - wróg. */
struct list{
    struct character *enemy;
    struct list *next;
};
/* Wskaźnik na listę wrogów. */
struct list *zombie_head;

/* Dodaje nowo stworzonego wroga do listy.
 * Wywoływana w funkcji create_zombie. */
void list_add(struct character *name);

/* Usuwa wszystkich wrogów z listy.
 * Wywoływana na końcu funkcji game.*/
void list_free();
