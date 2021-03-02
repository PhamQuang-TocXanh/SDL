#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include<cstring>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

const std::string title = "QuangDepTrai";
const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

enum pic{Default, Up, Down, Right, Left, Dragon, total};

SDL_Renderer* initSDL();
void logError(std::ostream& out, const std::string& ms, bool fatal);
void close(SDL_Texture* screen);
bool loadMedia(SDL_Texture* picture[]);
SDL_Texture* loadIMG(const std::string& path);

#endif // COMMON_H
