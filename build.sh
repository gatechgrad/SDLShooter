#!/bin/bash
#gcc -o test_game test_game.c `sdl2-config --cflags --libs`
#gcc -o test_game test_game.c `sdl2-config --cflags --libs` -lSDL2_ttf
#gcc -o test_game test_game.c `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_mixer
#gcc -o test_game test_game.c enemy.c `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_mixer
gcc -o test_game test_game.c enemy.c level_reader.c `sdl2-config --cflags --libs` -lSDL2_ttf -lSDL2_mixer -mconsole
