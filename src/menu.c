#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include "main.h"
#include "game.h"
#include "menu_base.h"
#include "menu.h"

void menu()
{
	ALLEGRO_EVENT_QUEUE *event_queue;
	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue,al_get_keyboard_event_source());

	blood.pos_x = screen.width/2 - 250/2;
	float pic_pos[2] = { 2*screen.height/4 - 50, 3*screen.height/4 - 50 };
	blood.pos_y = pic_pos[0];
	bool exit = false;
	bool draw = false;

	load_menu_items();

	while(!exit)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue,&event);
		if(event.type == ALLEGRO_EVENT_TIMER){ draw = true;}
		else if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch( event.keyboard.keycode ){
				case ALLEGRO_KEY_DOWN:
					if(blood.pos_y == pic_pos[0]) blood.pos_y = pic_pos[1];
					break;
				case ALLEGRO_KEY_UP:
					if(blood.pos_y == pic_pos[1]) blood.pos_y = pic_pos[0];
					break;
				case ALLEGRO_KEY_ESCAPE: 
					exit = true;
					break;
				case ALLEGRO_KEY_ENTER:
					if(blood.pos_y == pic_pos[0]) {
						game();
						blood.pos_x = screen.width/2 - 250/2;
						blood.pos_y = pic_pos[0];
						al_flush_event_queue(event_queue);
					}
					else if(blood.pos_y == pic_pos[1]) exit=true;
					break;
				default: break;
			}
		}
		if(draw && al_is_event_queue_empty(event_queue))
		{
			draw = false;
			build_menu(blood.pos_y);
		}
	}
	destroy_menu_items();
	al_destroy_event_queue(event_queue);
	return;
}
