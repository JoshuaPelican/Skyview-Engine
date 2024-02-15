#include "Sprite.h"

Sprite::Sprite(string mediaPath)
{
    SetMedia(mediaPath);
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(texture);
    texture = NULL;

    width = 0;
    height = 0;
}

void Sprite::SetMedia(string mediaPath)
{
    this->mediaPath = mediaPath;
    isLoaded = false;
}

bool Sprite::LoadMedia(SDL_Renderer* renderer)
{
    if (texture)
        SDL_DestroyTexture(texture);

    //Convert surface to screen format
    texture = IMG_LoadTexture(renderer, mediaPath.c_str());
    if (texture == NULL)
    {
        printf("Unable to load texture at %s! SDL Error: %s\n", mediaPath.c_str(), SDL_GetError());
        return false;
    }

    printf("Loaded texture at path: %s\n", mediaPath.c_str());
    isLoaded = true;

    SDL_QueryTexture(texture, NULL, NULL, &width, &height);

    return true;
}