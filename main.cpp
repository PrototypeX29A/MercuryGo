#include <iostream>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include "include/map_part.h"

using namespace std;

SDL_Surface *ship = NULL;
SDL_Surface *screen = NULL;

void put_pixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    Uint32 *pixels = (Uint32 *)surface->pixels;
    int w = surface->w;
    Uint32 *target = &pixels[ ( y * w) + x ];
    *target = pixel;
}

SDL_Surface *load_sprite(std::string filename)
{
    SDL_Surface* image = NULL;
    SDL_Surface* result = NULL;

    image = IMG_Load(filename.c_str());

    if (image != NULL)
    {
        result = SDL_DisplayFormat(image);
        SDL_FreeSurface(image);
    }

    return result;
}

void draw_sprite(SDL_Surface* target, SDL_Surface* image, int x, int y)
{
    SDL_Rect offset;

    offset.x = x;
    offset.y = y;

    SDL_BlitSurface(image, NULL, target, &offset);
}

bool init()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

    if (screen == NULL)
    {
        return false;
    }

    SDL_WM_SetCaption("Go!", NULL);

    return true;
}

int main()
{
    bool quit=false;

    init();
    ship = load_sprite("ship.bmp");
    if (ship == NULL)
    {
        cout << "Couldn't load ship.bmp" << endl;
        return -1;
    }
    map_part* map = new map_part();



    SDL_Event event;

    uint32_t last_game_tick = SDL_GetTicks();
    uint32_t ship_y = 0x10000;
    while (!quit)
    {
        for (int x=0; x<640; x++)
            for (int y=0; y<480; y++) {

            put_pixel(screen, x, y, map->get_pixel(x,y+ship_y));

        }
        draw_sprite(screen, ship, 320, 240);


        if (SDL_Flip(screen)==-1)
        {
            return 1;
        }

        while (SDL_PollEvent(&event))
        {
            if (event.type==SDL_QUIT)
            {
                quit = true;
            }
        }
        SDL_Delay(20);
        ship_y-=4;
    }

    SDL_FreeSurface(ship);

    SDL_Quit();




    return 0;
}
