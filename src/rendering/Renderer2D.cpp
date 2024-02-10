#include "Renderer2D.h"

Renderer2D::Renderer2D(string mediaPath)
{
    SetMedia(mediaPath);
}

Renderer2D::~Renderer2D()
{
    SDL_FreeSurface(surface);
    surface = NULL;
}

void Renderer2D::SetMedia(string mediaPath)
{
    this->mediaPath = mediaPath;
    isLoaded = false;
}

bool Renderer2D::LoadSurface(const SDL_PixelFormat* format)
{
    if(surface)
        delete surface;

    //Load image at specified path
    SDL_Surface* loadedSurface = SDL_LoadBMP(mediaPath.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", mediaPath.c_str(), SDL_GetError());
        return false;
    }
    
    //Convert surface to screen format
    surface = SDL_ConvertSurface(loadedSurface, format, 0);
    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
    if (surface == NULL)
    {
        printf("Unable to optimize image %s! SDL Error: %s\n", mediaPath.c_str(), SDL_GetError());
        return false;
    }

    printf("Loaded media at path: %s\n", mediaPath.c_str());

    isLoaded = true;
    return true;
}
