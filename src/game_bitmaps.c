#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include "headers/main.h"
#include "headers/game_base_daryl.h"
#include "headers/game_base_zombie.h"
#include "headers/table.h"
#include "headers/game_bitmaps.h"
#include "headers/menu_base.h"

void load_game_bitmaps()
{
    daryl_bitmap = al_load_bitmap("graphics/player.png");
    zombieT[0] = al_load_bitmap("graphics/zombie1.png");
    zombieT[1] = al_load_bitmap("graphics/zombie2.png");
    zombieT[2] = al_load_bitmap("graphics/zombie3.png");
    zombieT[3] = al_load_bitmap("graphics/zombie4.png");
    zombieT[4] = al_load_bitmap("graphics/zombie5.png");
    zombieT[5] = al_load_bitmap("graphics/zombie6.png");

    bg = al_load_bitmap("graphics/background.png");
    silver_box = al_load_bitmap("graphics/silver_box.png");
    if (!silver_box || !bg || !daryl_bitmap || !zombieT[0] || !zombieT[1] || !zombieT[2])
        al_show_native_message_box(screen.display,"Error","Error","Failed to load game bitmaps.", NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void destroy_game_bitmaps()
{
    al_destroy_bitmap(daryl_bitmap);
    al_destroy_bitmap(zombieT[0]);
    al_destroy_bitmap(zombieT[1]);
    al_destroy_bitmap(zombieT[2]);
    al_destroy_bitmap(zombieT[3]);
    al_destroy_bitmap(zombieT[4]);
    al_destroy_bitmap(zombieT[5]);
    al_destroy_bitmap(bg);
    al_destroy_bitmap(silver_box);
//    int i; for(i=0; i<3; i++) { al_destroy_bitmap(zombieT[0]); }
}

void draw_win_display()
{
    al_clear_to_color(al_map_rgb(0,0,0));
    struct menu_object im;
    im.pos_x = (float) (screen.width/2.0-200);
    im.pos_y = (float) (3*screen.height/4.0-200);
    im.bitmap = al_load_bitmap("graphics/im.png");
    if(!im.bitmap) { al_show_native_message_box(screen.display, "Error", "Error", "Failed to load im.bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR); }

    struct menu_object blood;
    blood.pos_x = 0;
    blood.pos_y = 0;
    blood.bitmap = al_load_bitmap("graphics/blood_bg.png");
    if(!blood.bitmap) { al_show_native_message_box(screen.display, "Error", "Error", "Failed to load im.bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR); }

    ALLEGRO_FONT *win_game_font = al_load_ttf_font("fonts/Iron&Brine.ttf",111,0);

    char field_covered[4]; sprintf(field_covered, "%d", taken_fields*100/fields);
    char percent[] = "% COVERED";
    strcat(field_covered,percent);
    ALLEGRO_FONT *field_covered_font = al_load_font("fonts/cnr.otf", 40, 0);

    al_draw_bitmap(blood.bitmap, blood.pos_x, blood.pos_y, 0);
    al_draw_bitmap(im.bitmap, im.pos_x, im.pos_y,0);
    al_draw_text(win_game_font, al_map_rgb(255,255,255), screen.width/2, screen.height/5, ALLEGRO_ALIGN_CENTRE, "YOU WON!");
    al_draw_text(field_covered_font, al_map_rgb(255,255,255), screen.width/2, screen.height/2.2, ALLEGRO_ALIGN_CENTER, field_covered);
    al_flip_display();
    al_rest(5.0);

    al_destroy_font(win_game_font);
    al_destroy_font(field_covered_font);
    al_destroy_bitmap(im.bitmap);
    al_destroy_bitmap(blood.bitmap);
}

void draw_lost_display()
{
    al_clear_to_color(al_map_rgb(0,0,0));

    struct menu_object blood;
    blood.pos_x = 0;
    blood.pos_y = 0;
    blood.bitmap = al_load_bitmap("graphics/blood_bg.png");
    if(!blood.bitmap) { al_show_native_message_box(screen.display, "Error", "Error", "Failed to load im.bitmap!", NULL, ALLEGRO_MESSAGEBOX_ERROR); }

    ALLEGRO_FONT *lose_game_font = al_load_ttf_font("fonts/Iron&Brine.ttf",111,0);

    char field_covered[4]; sprintf(field_covered, "%d", taken_fields*100/fields);
    char percent[] = "% COVERED";
    strcat(field_covered,percent);
    ALLEGRO_FONT *field_covered_font = al_load_font("fonts/cnr.otf", 40, 0);

    al_draw_bitmap(blood.bitmap, blood.pos_x, blood.pos_y, 0);
    al_draw_text(lose_game_font, al_map_rgb(255,255,255), screen.width/2, screen.height/5, ALLEGRO_ALIGN_CENTRE, "YOU LOST!");
    al_draw_text(field_covered_font, al_map_rgb(255,255,255), screen.width/2, screen.height/2.2, ALLEGRO_ALIGN_CENTER, field_covered);
    al_flip_display();
    al_rest(1.0);

    al_destroy_font(lose_game_font);
    al_destroy_font(field_covered_font);
    al_destroy_bitmap(blood.bitmap);
}
