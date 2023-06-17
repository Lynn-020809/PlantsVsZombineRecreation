#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv){
    bool quit = false;
    int x=320;
    int y=240;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("PvZ", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* image = IMG_Load("test.jpeg");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    while(!quit){
        SDL_Delay(20);
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_LEFT: x--; break;
                    case SDLK_RIGHT: x++; break;
                    case SDLK_UP: y--; break;
                    case SDLK_DOWN: y++; break;
                }
                break;
        }

        SDL_Rect dstrect = {x, y, 235, 235};
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}