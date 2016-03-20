#include <stdlib.h>
#include "game_base_daryl.h"
#include "list.h"

void list_add(struct character *name)
{
    struct list *new_enemy;
    new_enemy = malloc(sizeof(struct list));
    new_enemy->enemy = name;
    new_enemy->next = NULL;

    struct list *tmp = zombie_head;
    if(zombie_head == NULL) zombie_head = new_enemy;
    else { while(tmp->next != NULL) tmp = tmp->next; tmp->next = new_enemy; }
}

void list_free()
{
    struct list *tmp;
    tmp = zombie_head;
    while(tmp)
    {
        struct list *prev;
        prev = tmp;
        tmp = tmp->next;
        free(prev->enemy);
        free(prev);
    }
    zombie_head = NULL;
}
