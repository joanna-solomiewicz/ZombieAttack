cmake_minimum_required(VERSION 3.2)
project(Gra_Asia)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

set(SOURCE_FILES
    src/base.c
    src/base.h
    src/game.c
    src/game.h
    src/main.c
    src/main.h
    src/menu.c
    src/menu.h)

add_executable(Gra_Asia ${SOURCE_FILES} src/table.h src/table.c src/menu_base.h src/menu_base.c src/game_base_daryl.h src/game_base_daryl.c src/list.h src/list.c src/game_base_zombie.h src/game_base_zombie.c src/fill.h src/fill.c src/game_bitmaps.h src/game_bitmaps.c)

link_directories(/usr/include/allegro5)

set(game_LIBS liballegro.so liballegro_dialog.so liballegro_image.so liballegro_font.so liballegro_ttf.so liballegro_primitives.so)

target_link_libraries(Gra_Asia ${game_LIBS})
