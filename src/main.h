/* PLIK WYWOŁUJĄCY WSZYSTKIE GŁÓWNE FUNKCJE */
#pragma once

/* Struktura zawierająca dane na temat wyświetlacza:
 * - wskaźnik na wyświetlacz,
 * - szerokość,
 * - wysokość,
 * - FPS.
 * Wartości wczytywane z pliku konfiguracyjnego "config" */
struct resolution {
	ALLEGRO_DISPLAY *display;
	int width;
	int height;
	int FPS;
};
struct resolution screen;

ALLEGRO_TIMER *timer;

