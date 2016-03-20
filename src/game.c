#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <stdio.h>
#include <time.h>
#include "headers/main.h"
#include "headers/table.h"
#include "headers/game_base_daryl.h"
#include "headers/game_base_zombie.h"
#include "headers/game_bitmaps.h"
#include "headers/list.h"
#include "headers/game.h"

void game()
{
	srand(time(0));

	ALLEGRO_EVENT_QUEUE *game_event_queue;
	game_event_queue = al_create_event_queue();
	al_register_event_source(game_event_queue, al_get_timer_event_source(timer));
	al_register_event_source(game_event_queue,al_get_keyboard_event_source());

	exit_game = false;
    win_game = false;
	bool draw = false;
	stop_draw = 0;
	keep_drawing = 1;
	zombie_head = 0;
	int time=0;
	short i; for(i=0; i<4; i++) { key[i] = false; keep[i] = 0; }

	load_game_bitmaps();
	start_table();
	daryl = create_player();
	int j; for(j=0; j<9; j++) create_zombie();

	char fields_covered_game[4];
	sprintf(fields_covered_game, "%d", taken_fields*100/fields);
	char percent[] = "%";
	strcat(fields_covered_game,percent);
	ALLEGRO_FONT *field_covered_font = al_load_font("fonts/cnr.otf", 40, 0);

	while(!exit_game)
	{
		ALLEGRO_EVENT game_event;
		al_wait_for_event(game_event_queue,&game_event);
		if(game_event.type == ALLEGRO_EVENT_TIMER)
		{
			check_bounce(zombie_head);
            move_daryl();
            keep_moving();
			sprintf(fields_covered_game, "%d", taken_fields*100/fields);
			strcat(fields_covered_game,percent);
			if(win_game) exit_game = true;
			draw = true;
			time++;
		}
		else if(game_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { exit_game = true; }
		else if(game_event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch( game_event.keyboard.keycode ){
				case ALLEGRO_KEY_UP:
					key[UP] = true;
					key[DOWN] = key[LEFT] = key[RIGHT] = false;
                    correct_position();
					break;
				case ALLEGRO_KEY_DOWN:
					key[DOWN] = true;
					key[UP] = key[LEFT] = key[RIGHT] = false;
                    correct_position();
					break;
				case ALLEGRO_KEY_LEFT:
					key[LEFT] = true;
					key[UP] = key[DOWN] = key[RIGHT] = false;
                    correct_position();
					break;
				case ALLEGRO_KEY_RIGHT:
					key[RIGHT] = true;
					key[UP] = key[DOWN] = key[LEFT] = false;
                    correct_position();
					break;
				case ALLEGRO_KEY_ESCAPE: 
					exit_game = true;
					break;
				default: break;
			}
		}
		else if(game_event.type == ALLEGRO_EVENT_KEY_UP) 
		{
			switch( game_event.keyboard.keycode ){
				case ALLEGRO_KEY_UP:
					key[UP] = false;
					break;
				case ALLEGRO_KEY_DOWN:
					key[DOWN] = false;
					break;
				case ALLEGRO_KEY_LEFT:
					key[LEFT] = false;
					break;
				case ALLEGRO_KEY_RIGHT:
					key[RIGHT] = false;
					break;
				default: break;
			}
		}
		if(draw && al_is_event_queue_empty(game_event_queue))
		{
			draw = false;
			al_draw_tinted_bitmap(bg, al_map_rgba_f(1,0.5,0.5,0.5),0,0,0);
			draw_table();
			draw_zombie();
			path();
			al_draw_bitmap(daryl->pointer,daryl->pos_x, daryl->pos_y,0);
			al_draw_text(field_covered_font, al_map_rgb(111,0,0), 0, 0, ALLEGRO_ALIGN_LEFT, fields_covered_game);
			al_flip_display();
		}
	}
	free(T);
	destroy_game_bitmaps();
	al_destroy_font(field_covered_font);
	list_free();
	al_destroy_event_queue(game_event_queue);
	return;
}
