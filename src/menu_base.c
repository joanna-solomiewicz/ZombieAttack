#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include "headers/main.h"
#include "headers/menu_base.h"

void theme() {
    al_clear_to_color(al_map_rgb(0,0,0));

    struct menu_object im;
    im.pos_x = (float) (screen.width/2.0-200);
    im.pos_y = (float) (3*screen.height/4.0-200);
    im.bitmap = al_load_bitmap("graphics/im.png");
    if(!im.bitmap) { al_show_native_message_box(screen.display, "Error", "Error", "Failed to load im.bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR); }

    struct menu_object t_zombie;
    t_zombie.font = al_load_ttf_font("fonts/Iron&Brine.ttf",111,0);
    t_zombie.pos_x = (float) (screen.width/2.0);
    t_zombie.pos_y = (float) (screen.height/7.0);

    struct menu_object t_attack;
    t_attack.font = t_zombie.font;
    t_attack.pos_x = (float) (screen.width/2.0);
    t_attack.pos_y = (float) (screen.height/3.0);

    struct menu_object t_myname;
    t_myname.font = al_load_ttf_font("fonts/cnr.otf",20,0);
    t_myname.pos_x = (float) (3*screen.width/4.0);
    t_myname.pos_y = (float) (28*screen.height/30.0);

    al_draw_bitmap(im.bitmap, im.pos_x, im.pos_y,0);
    al_draw_text(t_zombie.font, al_map_rgb(255,255,255), t_zombie.pos_x, t_zombie.pos_y, ALLEGRO_ALIGN_CENTRE, "ZOMBIE");
    al_draw_text(t_attack.font, al_map_rgb(255,255,255), t_attack.pos_x, t_attack.pos_y, ALLEGRO_ALIGN_CENTRE, "ATTACK!");
    al_draw_text(t_myname.font, al_map_rgb(255,255,255), t_myname.pos_x, t_myname.pos_y, ALLEGRO_ALIGN_CENTRE, "by Joanna Solomiewicz");
    al_flip_display();
    al_rest(2.0);

    unsigned char i=0;
    while(i < 255)
    {
        al_clear_to_color(al_map_rgb(i,i,i));
        al_flip_display();
        i+=15;
    }
    al_destroy_bitmap(im.bitmap);
    al_destroy_font(t_zombie.font);
    al_destroy_font(t_myname.font);
}

struct menu_object t_title;
struct menu_object t_new_game;
struct menu_object t_exit;

void load_menu_items()
{
    t_title.font = al_load_ttf_font("fonts/Iron&Brine.ttf",111,0);
    if(!t_title.font) al_show_native_message_box(screen.display,"Error","Font","Could not load font.",NULL,ALLEGRO_MESSAGEBOX_ERROR);

    t_new_game.font = al_load_ttf_font("fonts/OakLawn.ttf",60,0);
    if(!t_new_game.font) al_show_native_message_box(screen.display,"Error","Font","Could not load font.",NULL,ALLEGRO_MESSAGEBOX_ERROR);
    t_exit.font = t_new_game.font;

    blood.bitmap = al_load_bitmap("graphics/blood.png");
}

void destroy_menu_items()
{
    al_destroy_font(t_title.font);
    al_destroy_font(t_new_game.font);
}

void build_menu(float height)
{
    t_title.pos_x = (screen.width/2);
    t_title.pos_y = (screen.height/4-30);
    t_new_game.pos_x = (screen.width/2);
    t_new_game.pos_y = (2*screen.height/4);
    t_exit.pos_x = (screen.width/2);
    t_exit.pos_y = (3*screen.height/4);

    al_clear_to_color(al_map_rgb(0,0,0));
    blood.bitmap = al_load_bitmap("graphics/blood.png");
    al_draw_bitmap(blood.bitmap, blood.pos_x, height,0);
    al_draw_text(t_title.font, al_map_rgb(255,255,255), t_title.pos_x, t_title.pos_y, ALLEGRO_ALIGN_CENTRE, "ZOMBIE ATTACK!");
    al_draw_text(t_new_game.font, al_map_rgb(255,255,255), t_new_game.pos_x, t_new_game.pos_y, ALLEGRO_ALIGN_CENTRE, "NEW GAME");
    al_draw_text(t_exit.font, al_map_rgb(255,255,255), t_exit.pos_x, t_exit.pos_y, ALLEGRO_ALIGN_CENTRE, "EXIT");
    al_destroy_bitmap(blood.bitmap);
    al_flip_display();
    return;
}

