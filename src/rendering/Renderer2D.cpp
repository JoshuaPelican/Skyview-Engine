#include "Renderer2D.h"
#include <stdio.h>

Renderer2D::Renderer2D()
{

}

Renderer2D::~Renderer2D()
{
    SDL_FreeSurface(surface);
    surface = NULL;
}

bool Renderer2D::LoadMedia(char* filePath)
{
    bool success = true;

    surface = SDL_LoadBMP(filePath);
    if (surface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", filePath, SDL_GetError());
        success = false;
    }

    return success;
}
