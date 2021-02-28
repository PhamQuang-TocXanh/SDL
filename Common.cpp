#include"Common.h"
using namespace std;


bool initSDL(){
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        logError(cout, "Init", true);
        return false;
    }else{
        window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if(window == NULL){
            logError(cout, "Window", false);
            return false;
        }else{
            render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(render == NULL){
                logError(cout, "Render", false);
                return false;
            }else{
                SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
                int Flag = IMG_INIT_PNG;
                if(!(IMG_Init(Flag)&Flag)){
                    logError(cout, "Init PNG", false);
                    return false;
                }
            }
        }
    }
    //SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderSetLogicalSize(render, SCREEN_WIDTH, SCREEN_HEIGHT);
    return true;
}
SDL_Texture* loadIMG(const string& path){// thay cho SDL_Surface* loadIMG(const string& path)
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL){
        cout << "Unable to load image! SDL_Image Error: " << IMG_GetError() << endl;
    }else{
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(render,loadedSurface);
        if(newTexture == NULL){
            logError(cout, "Texture", false);
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}
bool loadMedia(){
    picture[Default] = loadIMG("press.bmp");
    if(picture[Default] == NULL){
        cout << "Failed to load texture image!\n";
        return false;
    }
    picture[Up] = loadIMG("up.bmp");
    if(picture[Up] == NULL){
        cout << "Failed to load texture image!\n";
        return false;
    }
    picture[Down] = loadIMG("down.bmp");
    if(picture[Down] == NULL){
        cout << "Failed to load texture image!\n";
        return false;
    }
    picture[Left] = loadIMG("left.bmp");
    if(picture[Left] == NULL){
        cout << "Failed to load texture image!\n";
        return false;
    }
    picture[Right] = loadIMG("right.bmp");
    if(picture[Right] == NULL){
        cout << "Failed to load texture image!\n";
        return false;
    }
    picture[Dragon] = loadIMG("DRAGON.jpg");
    if(picture[Dragon] == NULL){
        cout << "Failed to load texture image!\n";
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
void close(){
    SDL_DestroyTexture(screen);
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

