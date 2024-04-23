#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"
#include "src/include/SDL2/SDL_mixer.h"
#include <iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include<fstream>
#include <random>
#include <ctime>
using namespace std;
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 700
SDL_Window* gWindow = NULL; // cá»­a sá»• game
SDL_Renderer* gRenderer = NULL; // mÃ n hÃ¬nh xá»­ lÃ½
Uint32 gOldTime; // tho
float deltaTime = 0; // chênh lệch 2 frame 

#endif