#include "../headerFiles/checkmatePage.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

// #include "global.h"
// #include "starter.h"
// #include "credit.h"
// #include "../headerFiles/chess.h"
// #include "../headerFiles/chessAI.h"
// #include "chess.h"
int WINDOW_WIDTH5 = 640;
int WINDOW_HEIGHT5 = 640;

SDL_Window *xwindow5 = NULL;
SDL_Renderer *xrenderer5 = NULL;
SDL_Texture *xtexturer5 = NULL;
char *new_font2 = "../font/Monaco.ttf";

void start5(SDL_Renderer *xrenderer)
{
    /* Clear the screen with selected color */
    SDL_SetRenderDrawColor(xrenderer, 100, 10, 90, 255);
    SDL_RenderClear(xrenderer);
    char *workingButton = "Checkmate";
    TTF_Font *monaco = TTF_OpenFont(new_font2, 28);
    if (monaco == NULL)
    {
        printf("Error opening font: %s\n", SDL_GetError());
        return;
    }
    SDL_Color blue = {0, 100, 255};
    SDL_Surface *workingSurface = TTF_RenderText_Blended(monaco, workingButton, blue);
    SDL_Texture *workingTexture = SDL_CreateTextureFromSurface(xrenderer, workingSurface);
    if (!workingTexture)
    {
        printf("error creating texture: %s\n", SDL_GetError());
        SDL_FreeSurface(workingSurface);
        TTF_CloseFont(monaco);
        return;
    }
    SDL_Rect working_rect;
    working_rect.x = (WINDOW_WIDTH5 - workingSurface->w) / 2;
    working_rect.y = (WINDOW_HEIGHT5 - workingSurface->h) / 2 + 5;
    working_rect.w = workingSurface->w;
    working_rect.h = workingSurface->h;

    SDL_RenderCopy(xrenderer, workingTexture, NULL, &working_rect);

    SDL_FreeSurface(workingSurface);
    SDL_DestroyTexture(workingTexture);
    TTF_CloseFont(monaco);
}
// initial
void initSDLs5()
{
    SDL_Init(SDL_INIT_VIDEO);
    xwindow5 = SDL_CreateWindow("CHESS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    xrenderer5 = SDL_CreateRenderer(xwindow5, -1, SDL_RENDERER_ACCELERATED);
    TTF_Init();
}
// chess game working
int checks()
{
    initSDLs5();

    int quit = 0;
    SDL_Event e;
    start5(xrenderer5);
    SDL_RenderPresent(xrenderer5);
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {

            start5(xrenderer5);
            SDL_RenderPresent(xrenderer5);
        }
        SDL_Delay(3000);
        quit = 1;
        start5(xrenderer5);
        SDL_RenderPresent(xrenderer5);
    }

    SDL_DestroyRenderer(xrenderer5);
    SDL_DestroyWindow(xwindow5);
    SDL_Quit();
    TTF_Quit();

    return 0;
}