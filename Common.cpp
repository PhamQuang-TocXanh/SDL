#include"Common.h"
using namespace std;

SDL_Window* window = NULL;
SDL_Renderer* render = NULL;

SDL_Renderer* initSDL(){
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        logError(cerr, "Init", true);
        return nullptr;
    }else{
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if(window == NULL){
            logError(cerr, "Window", false);
            return nullptr;
        }else{
            render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(render == NULL){
                logError(cerr, "Render", false);
                return nullptr;
            }else{
                SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
                int Flag = IMG_INIT_PNG;
                if(!(IMG_Init(Flag)&Flag)){
                    logError(cerr, "Init PNG", false);
                    return nullptr;
                }
            }
        }
    }
    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderSetLogicalSize(render, SCREEN_WIDTH, SCREEN_HEIGHT);
    return render;
}
SDL_Texture* loadIMG(const string& path){// thay cho SDL_Surface* loadIMG(const string& path)
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL){
        cerr << "Unable to load image! SDL_Image Error: " << IMG_GetError() << endl;
    }else{
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(render,loadedSurface);
        if(newTexture == NULL){
            logError(cerr, "Texture", false);
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
bool loadMedia(SDL_Texture* picture[]){
    picture[Default] = loadIMG("press.bmp");
    if(picture[Default] == NULL){
        cerr << "Failed to load texture image!\n";
        return false;
    }
    picture[Up] = loadIMG("up.bmp");
    if(picture[Up] == NULL){
        cerr << "Failed to load texture image!\n";
        return false;
    }
    picture[Down] = loadIMG("down.bmp");
    if(picture[Down] == NULL){
        cerr << "Failed to load texture image!\n";
        return false;
    }
    picture[Left] = loadIMG("left.bmp");
    if(picture[Left] == NULL){
        cerr << "Failed to load texture image!\n";
        return false;
    }
    picture[Right] = loadIMG("right.bmp");
    if(picture[Right] == NULL){
        cerr << "Failed to load texture image!\n";
        return false;
    }
    picture[Dragon] = loadIMG("DRAGON.jpg");
    if(picture[Dragon] == NULL){
        cerr << "Failed to load texture image!\n";
        return false;
    }
    return true;
}
void logError(ostream& out, const string& ms, bool fatal){
    out << ms << " Error: " << SDL_GetError() << endl;
    if(fatal){
        SDL_Quit();
        exit(1);
    }
}
void close(SDL_Texture* screen){
    SDL_DestroyTexture(screen);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

