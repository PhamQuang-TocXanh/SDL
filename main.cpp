#include"Common.h"

using namespace std;

int main(int argc, char* argv[]){
    SDL_Event e;
    if(!initSDL()){
        cout << "Failed to initialize!" << endl;
    }else{
        if(!loadMedia()){
            cout << "Failed to load image" << endl;
        }else{
            //screen = picture[Default];
            bool quit = false;
            while(!quit){
                while(SDL_PollEvent(&e)!=0){
                    if(e.type == SDL_QUIT){
                        quit = true;
                    }
                }
                switch(e.key.keysym.sym){
                case SDLK_UP:
                    screen = picture[Up]; break;
                case SDLK_RIGHT:
                    screen = picture[Right]; break;
                case SDLK_DOWN:
                    screen = picture[Down]; break;
                case SDLK_LEFT:
                    screen = picture[Left]; break;
                case SDLK_d:
                    screen = picture[Dragon]; break;
                default:
                    screen = picture[Default]; break;
                }
                SDL_RenderClear(render);
                SDL_RenderCopy(render, screen, NULL, NULL);
                SDL_RenderPresent(render);
            }
        }
    }
    close();
    return 0;
}
