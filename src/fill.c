#include "headers/game.h"
#include "headers/game_base_daryl.h"
#include "headers/table.h"
#include "headers/list.h"
#include "headers/fill.h"

void fill()
{
    int i,j;
    int smth_changed = 1;
    int l_field=0, r_field=0;
    int is_zombie_on_l_field = 0;
    int is_zombie_on_r_field = 0;

    while (smth_changed)
    {
        smth_changed = 0;
        for(i=1; i<T_height-1; i++) {
            for (j = 1; j < T_width; j++) {
                if (T[i][j] == 0){
                    if (T[i - 1][j] == -1 ||
                        T[i + 1][j] == -1 ||
                        T[i][j - 1] == -1 ||
                        T[i][j + 1] == -1) {
                        T[i][j] = -1;
                        smth_changed = 1;
                    }
                    else if (T[i - 1][j] == -2 ||
                             T[i + 1][j] == -2 ||
                             T[i][j - 1] == -2 ||
                             T[i][j + 1] == -2) {
                        T[i][j] = -2;
                        smth_changed = 1;
                    }
                }
            }
        }
    }
    for(i=1; i<T_height-1; i++) {
        for (j = 1; j < T_width; j++) {
            if (T[i][j] == -1)  l_field++;
            else if (T[i][j] == -2) r_field++;
        }
    }

    struct list *tmp = zombie_head;
    while(tmp)
    {
        int x_middle_field = (tmp->enemy->pos_x+tmp->enemy->size/2) / T_size;
        int y_middle_field = (tmp->enemy->pos_y+tmp->enemy->size/2) / T_size;
        if(T[y_middle_field][x_middle_field] == -1) is_zombie_on_l_field = 1;
        if(T[y_middle_field][x_middle_field] == -2) is_zombie_on_r_field = 1;
        tmp = tmp->next;
    }


    for(i=1; i<T_height-1; i++) {
        for (j=1; j<T_width; j++){
            if (l_field <= r_field){
                if (is_zombie_on_l_field == 0) {
                    if (T[i][j] == -1) {
                        T[i][j] = 1;
                        taken_fields++;
                    }
                    if (T[i][j] == -2) { T[i][j] = 0; }
                }
                else if(is_zombie_on_r_field == 0) {
                    if (T[i][j] == -2) {
                        T[i][j] = 1;
                        taken_fields++;
                    }
                    if (T[i][j] == -1) { T[i][j] = 0; }
                }
                else { if(T[i][j] == -1 || T[i][j] == -2) T[i][j] = 0; }
            }
            else if (l_field > r_field){
                if (is_zombie_on_r_field == 0) {
                    if (T[i][j] == -2) {
                        T[i][j] = 1;
                        taken_fields++;
                    }
                    if (T[i][j] == -1) { T[i][j] = 0; }
                }
                else if(is_zombie_on_l_field == 0) {
                    if (T[i][j] == -1) {
                        T[i][j] = 1;
                        taken_fields++;
                    }
                    if (T[i][j] == -2) { T[i][j] = 0; }
                }
                else { if(T[i][j] == -1 || T[i][j] == -2) T[i][j] = 0; }
            }
            if(T[i][j] == 2) { T[i][j] = 1; taken_fields++; }
        }
    }
}

