#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include "main.h"
#include "base.h"

void load_lib()
{
	al_init();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
}

void make_base()
{
	screen.display = al_create_display(screen.width,screen.height);
	timer = al_create_timer(1.0/screen.FPS);
}

/* Dodaje element do stosu. */
void push(char *a, char *b)
{
	struct stack *new;
	new = malloc(sizeof(struct stack));
	new->next = stack_root;
	new->name = a;
	new->value = b;
	stack_root = new;
}

/* Ściąga element ze stosu. */
struct stack *pull()
{
	struct stack * val;
	val = stack_root;
	if (stack_root)
		stack_root = stack_root->next;
	return val;
}

void read_config_file()
{
	char nazwa[20], wartosc[20];
	char *nowa_nazwa=0, *nowa_wartosc=0;
	char wczytywany_znak;
	short i=0, j=0;
	short pstryczek=0;
	short linijka=1;

	stack_root = 0;
	FILE *plik;
	if ( !(plik = fopen("config", "r")) ){
		plik = fopen("config", "w");
		fprintf(plik, "screen.width=1024\n");
		fprintf(plik, "screen.height=640\n");
		fprintf(plik, "screen.FPS=60\n");
		fclose(plik);
	}
	else fclose(plik);
	plik = fopen("config", "r");
    while ( (wczytywany_znak = fgetc(plik)) != EOF )
    {
        while (wczytywany_znak != '\n')
        {
            if ( (wczytywany_znak != '=') && (pstryczek == 0) )
            {
                nazwa[i++] = wczytywany_znak;
                break;
            }
            if ( (wczytywany_znak == '=') )
            {
                pstryczek = 1;
                break;
            }
            if ( (wczytywany_znak != '=') && (pstryczek == 1) )
            {
                wartosc[j++] = wczytywany_znak;
                break;
            }
        }
        if ( (wczytywany_znak == '\n') )
        {
            if (pstryczek == 1)
            {
                nowa_nazwa = strndup(nazwa, i);
                nowa_wartosc = strndup(wartosc, j);
                push (nowa_nazwa, nowa_wartosc);
            }
            else fprintf(stderr, "Błąd przy wczytywaniu pliku w %d linijce. Popraw! %s.\n", linijka, strerror(errno));
            i=0;
            j=0;
            pstryczek = 0;
            linijka++;
        }
    }
//	else { fprintf(stderr, "Błąd przy otwieraniu pliku. %s.", strerror(errno)); }
	fclose(plik);

	struct stack *wsk;
	for (wsk=pull(); wsk != 0; wsk=pull())
	{
		if(strcmp(wsk->name, "screen.width") == 0) screen.width = atoi(wsk->value);
		else if(strcmp(wsk->name,"screen.height") == 0) screen.height = atoi(wsk->value);
		else if(strcmp(wsk->name, "screen.FPS") == 0) screen.FPS = atoi(wsk->value);
		free(wsk->name);
		free(wsk->value);
		free(wsk);
	}
}
