cmake_minimum_required(VERSION 3.2)
project(ZombieAttack)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES
    src/base.c
        src/headers/base.h
    src/game.c
        src/headers/game.h
    src/main.c
        src/headers/main.h
    src/menu.c
        src/headers/menu.h)

add_executable(ZombieAttack ${SOURCE_FILES} src/headers/table.h src/table.c src/headers/menu_base.h src/menu_base.c src/headers/game_base_daryl.h src/game_base_daryl.c src/headers/list.h src/list.c src/headers/game_base_zombie.h src/game_base_zombie.c src/headers/fill.h src/fill.c src/headers/game_bitmaps.h src/game_bitmaps.c)

link_directories(/usr/include/allegro5)

set(game_LIBS liballegro.so liballegro_dialog.so liballegro_image.so liballegro_font.so liballegro_ttf.so liballegro_primitives.so)

target_link_libraries(ZombieAttack ${game_LIBS})
