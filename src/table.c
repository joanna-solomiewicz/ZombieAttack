#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "headers/main.h"
#include "headers/game_bitmaps.h"
#include "headers/table.h"

void start_table()
{
	T_size = 32;
	taken_fields = 0;
	fields = 0;
    T_width = screen.width/32;
    T_height = screen.height/32;
    T = (int**)malloc(T_height*sizeof(int*));
    int k;
    for(k=0; k<T_height; k++) T[k] = (int*)malloc(T_width*sizeof(int));
	int i,j;
	for(i=0; i<T_height; i++)
	{
		for (j = 0; j < T_width; j++)
		{
			if (i == 0 || i == (T_height) - 1) { T[i][j] = 1; }
			else if ((j == 0 || j == (T_width)-1)) { T[i][j] = 1; }
			else { T[i][j] = 0; fields++; }
		}
	}
}

void draw_table()
{
	int i,j;
	for(i=0; i<T_height; i++)
		for(j=0; j<T_width; j++)
			if(T[i][j]==1)
				al_draw_tinted_bitmap(silver_box, al_map_rgba_f(1,1,1,0.65),j*T_size,i*T_size,0);
			else if(T[i][j]<=0)
				al_draw_rectangle(j*T_size,i*T_size,(j+1)*T_size,(i+1)*T_size, al_map_rgb(0,0,0),1.0);
			else if(T[i][j]==2)
				al_draw_rectangle(j*T_size,i*T_size,(j+1)*T_size,(i+1)*T_size, al_map_rgb(255,255,255),2.0);
}
