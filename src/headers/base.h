/* PLIK WYWOŁUJĄCY POCZĄTKOWE FUNKCJE TWORZĄCE */
#pragma once

/* Struktura stosu potrzebna przy odczytywaniu pliku
 * konfiguracyjnego */
struct stack
{
    struct stack *next;
    char *name;
    char *value;
};
struct stack *stack_root;

/* Ładuje wszystkie potrzebne biblioteki allegro,
 * Wywoływana na początku funkcji main. */
void load_lib();

/* Odczytuje wartości zmiennych z pliku konfiguracyjnego
 * i przypisuje je.
 * Wywoływana w funkcji main. */
void read_config_file();

/* Tworzy wyświetlacz i timer.
 * Wywoływana w funkcji main. */
void make_base();
