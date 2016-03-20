#include <allegro5/allegro.h>
#include <stdlib.h>
#include "headers/game.h"
#include "headers/main.h"
#include "headers/table.h"
#include "headers/list.h"
#include "headers/game_bitmaps.h"
#include "headers/game_base_daryl.h"
#include "headers/game_base_zombie.h"

void create_zombie()
{
    struct character *name;
    name= malloc(sizeof(struct character));
    name->size = 32;
    name->pos_x = ((3*T_size + rand() % (screen.width - 6*T_size)) / 32 ) * 32;
    name->pos_y = ((3*T_size + rand() % (screen.height - 6*T_size)) / 32 ) * 32;
    if(rand() % 2) name->dx = 2.0;
    else name->dx = -2.0;
    if(rand() % 2) name->dy = 2.0;
    else name->dy = -2.0;
    name->pointer = zombieT[rand() % 6];
    list_add(name);
}

void check_bounce(struct list *tmp)
{
    if(tmp){
        check_bounce(tmp->next);

        int x = tmp->enemy->pos_x;
        int y = tmp->enemy->pos_y;
        int size = tmp->enemy->size;

        if(tmp->enemy->dy > 0) {
            if(T[(y+1+size)/size][(x+1)/size] == 2 || T[(y+1+size)/size][(x-1+size)/size] == 2) {
                int i,j; for(i=0; i<T_height; i++) for(j=0; j<T_width; j++) { if(T[i][j] == 2 || T[i][j] < 0) T[i][j] = 0; }
                keep_drawing = 0;
            }
        }
        else if(T[(y-1)/size][(x+1)/size] == 2 || T[(y-1)/size][(x-1+size)/size] == 2) {
            int i,j; for(i=0; i<T_height; i++) for(j=0; j<T_width; j++) { if(T[i][j] == 2 || T[i][j] < 0) T[i][j] = 0;}
            keep_drawing = 0;
        }
        if(tmp->enemy->dx > 0) {
            if(T[(y+1)/size][(x+1+size)/size] == 2 || T[(y-1+size)/size][(x+1+size)/size] == 2) {
                int i,j; for(i=0; i<T_height; i++) for(j=0; j<T_width; j++) { if(T[i][j] == 2 || T[i][j] < 0) T[i][j] = 0; }
                keep_drawing = 0;
            }
        }
        else if(T[(y+1)/size][(x-1)/size] == 2 || T[(y-1+size)/size][(x-1)/size] == 2) {
            int i,j; for(i=0; i<T_height; i++) for(j=0; j<T_width; j++) { if(T[i][j] == 2 || T[i][j] < 0) T[i][j] = 0;}
            keep_drawing = 0;
        }

        if (T[(daryl->pos_y+daryl->size/2)/T_size][(daryl->pos_x+daryl->size/2)/T_size] != 1){
            if(abs((daryl->pos_x + daryl->size/2) - (x + size/2)) <= 32 && abs((daryl->pos_y + daryl->size/2) - (y + size/2)) <= 32) {
                draw_lost_display();
                exit_game = true;
                int i,j; for(i=0; i<T_height; i++) for(j=0; j<T_width; j++) { if(T[i][j] == 2 || T[i][j] < 0) T[i][j] = 0;}
                return;
            }
        }

        int bounced=0;
        if(tmp->enemy->dx > 0) {
            if(!bounced && T[(y+1)/size][(x+1+size)/size] == 1 || T[(y-1+size)/size][(x+1+size)/size] == 1) {
                tmp->enemy->dx *= -1; bounced=1;
            }
        }
        else {
            if(!bounced && T[(y + 1) / size][(x - 1) / size] == 1 || T[(y - 1 + size) / size][(x - 1) / size] == 1) {
                tmp->enemy->dx *= -1; bounced = 1;
            }
        }
        if(tmp->enemy->dy > 0) {
            if(!bounced && T[(y+1+size)/size][(x+1)/size] == 1 || T[(y+1+size)/size][(x-1+size)/size] == 1) {
                tmp->enemy->dy *= -1; bounced = 1;
            }
        }
        else {
            if(!bounced && T[(y-1)/size][(x+1)/size] == 1 || T[(y-1)/size][(x-1+size)/size] == 1) {
                tmp->enemy->dy *= -1; bounced = 1;
            }
        }

        tmp->enemy->pos_x += tmp->enemy->dx;
        tmp->enemy->pos_y += tmp->enemy->dy;
    }
}

void draw_zombie() {
    struct list *tmp = zombie_head;
    while (tmp) {
        al_draw_bitmap(tmp->enemy->pointer, tmp->enemy->pos_x, tmp->enemy->pos_y, 0);
        tmp = tmp->next;
    }
}

