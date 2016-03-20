#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include "base.h"
#include "menu.h"
#include "menu_base.h"
#include "main.h"

int main(int argc, char **argv)
{
	load_lib();
	read_config_file();
	make_base();

	theme();
	al_start_timer(timer);
	menu();

	al_destroy_display(screen.display);
	al_destroy_timer(timer);

	return 111;
}
