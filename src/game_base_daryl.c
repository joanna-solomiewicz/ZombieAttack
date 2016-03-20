#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <stdio.h>
#include "main.h"
#include "table.h"
#include "menu_base.h"
#include "game.h"
#include "fill.h"
#include "game_bitmaps.h"
#include "game_base_daryl.h"

struct character *create_player()
{
    struct character *player;
    player= malloc(sizeof(struct character));
    player->size = 32;
    player->pos_x = 0;
    player->pos_y = 0;
    player->dx = 4.0;
    player->dy = 4.0;
    player->pointer = daryl_bitmap;
    return player;
}

void correct_position()
{
    int x = daryl->pos_x;
    int y = daryl->pos_y;
    int size = daryl->size;
    int x_middle = x+size/2;
    int y_middle = y+size/2;

    if(x_middle % size < 16) daryl->pos_x = (x/size+1) * T_size;
    else daryl->pos_x = (x/size) * T_size;

    if(y_middle % size < 16) daryl->pos_y = (y/size+1) * T_size;
    else daryl->pos_y = (y/size) * T_size;
}

void move_daryl()
{
    int x = daryl->pos_x;
    int y = daryl->pos_y;
    int size = daryl->size;
    int x_middle = x+size/2;
    int y_middle = y+size/2;

    if(T[y_middle/size][x_middle/size] != 1)
    {
        if(key[UP] && !keep[DOWN]) { keep[UP] = 1; keep[DOWN] = 0; keep[LEFT] = 0; keep[RIGHT] = 0;}
        if(key[DOWN] && !keep[UP]) { keep[UP] = 0; keep[DOWN] = 1; keep[LEFT] = 0; keep[RIGHT] = 0;}
        if(key[LEFT] && !keep[RIGHT]) { keep[UP] = 0; keep[DOWN] = 0; keep[LEFT] = 1; keep[RIGHT] = 0;}
        if(key[RIGHT] && !keep[LEFT]) { keep[UP] = 0; keep[DOWN] = 0; keep[LEFT] = 0; keep[RIGHT] = 1;}
    }
    else
    {
        int i; for(i=0; i<4; i++) keep[i] = 0;
        if(key[UP] && y >= size/4) daryl->pos_y -= size/4;
        else if(key[DOWN] && y <= screen.height-size-size/4) daryl->pos_y += size/4;
        else if(key[LEFT] && x >= size/4) daryl->pos_x -= size/4;
        else if(key[RIGHT] && x <= screen.width-size-size/4) daryl->pos_x += size/4;
        else { correct_position(); }
    }
}

void keep_moving()
{
    if(keep[UP]) daryl->pos_y -= daryl->size/daryl->dy;
    if(keep[DOWN]) daryl->pos_y += daryl->size/daryl->dy;
    if(keep[LEFT]) daryl->pos_x -= daryl->size/daryl->dx;
    if(keep[RIGHT]) daryl->pos_x += daryl->size/daryl->dx;
}

void path()
{
    int size = daryl->size;
    int x_middle = daryl->pos_x+size/2;
    int y_middle = daryl->pos_y+size/2;

    if(stop_draw != 2)
    {
        if(T[y_middle / size][x_middle / size] <= 0)
        {
            if (keep_drawing){
                if(keep[UP] && (y_middle-size/4) % size == 0) {
                    T[y_middle/size][x_middle/size] = 2;
                    if(T[y_middle/size][(x_middle/size) - 1] == 0) T[y_middle/size][(x_middle/size) - 1] = -2;
                    if(T[y_middle/size][(x_middle/size) + 1] == 0) T[y_middle/size][(x_middle/size) + 1] = -1;
                }
                else if(keep[DOWN] && (y_middle+size/4) % size == 0) {
                    T[y_middle/size][x_middle/size] = 2;
                    if(T[y_middle/size][(x_middle/size) - 1] == 0) T[y_middle/size][(x_middle/size) - 1] = -1;
                    if(T[y_middle/size][(x_middle/size) + 1] == 0) T[y_middle/size][(x_middle/size) + 1] = -2;
                }
                else if(keep[LEFT] && (x_middle-size/4) % size == 0) {
                    T[y_middle / size][x_middle / size] = 2;
                    if(T[(y_middle/size) - 1][x_middle/size] == 0) T[(y_middle/size) - 1][x_middle/size] = -1;
                    if(T[(y_middle/size) + 1][x_middle/size] == 0) T[(y_middle/size) + 1][x_middle/size] = -2;
                }
                else if(keep[RIGHT] && (x_middle+size/4) % size == 0) {
                    T[y_middle/size][x_middle/size] = 2;
                    if(T[(y_middle/size) - 1][x_middle/size] == 0) T[(y_middle/size) - 1][x_middle/size] = -2;
                    if(T[(y_middle/size) + 1][x_middle/size] == 0) T[(y_middle/size) + 1][x_middle/size] = -1;
                }
            }
            stop_draw = 1;
        }
        if (T[y_middle / size][x_middle / size] == 1 && stop_draw == 1)
            stop_draw = 2;
    }

    if(stop_draw == 2)
    {
        fill();
        keep_drawing = 1;
        stop_draw = 0;
        if(taken_fields >= 0.8*fields) {
            draw_win_display();
            win_game = true;
        }
    }

    if(keep[UP] && T[(y_middle - size/2 - 1)/size][x_middle/size] == 2) {
        draw_lost_display();
        exit_game = true;
    }
    else if(keep[DOWN] && T[(y_middle + size/2 + 1)/size][x_middle/size] == 2) {
        draw_lost_display();
        exit_game = true;
}
    else if(keep[LEFT] && T[y_middle/size][(x_middle - size/2 - 1)/size] == 2) {
        draw_lost_display();
        exit_game = true;
    }
    else if(keep[RIGHT] && T[y_middle/size][(x_middle + size/2 + 1)/size] == 2) {
        draw_lost_display();
        exit_game = true;
    }
}

