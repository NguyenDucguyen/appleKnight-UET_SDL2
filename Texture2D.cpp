#include "Texture2D.h"

Texture2D::Texture2D()
{
    mRenderer = nullptr;
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

Texture2D::Texture2D(SDL_Renderer* renderer)
{
    mRenderer = renderer;
    mTexture = nullptr;
    mWidth = 0;
    mHeight = 0;
}

Texture2D::~Texture2D()
{
    Free();
    mRenderer = nullptr;
}

void Texture2D::Free()
{
    if (mTexture != nullptr)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = nullptr;
    }
    mWidth = 0;
    mHeight = 0;
}

bool Texture2D::LoadFromFile(std::string path)
{
    Free();
    SDL_Surface* pSurface = IMG_Load(path.c_str());

    if (pSurface != nullptr)
    {
        SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0xFF, 0xFF));
        mWidth = pSurface->w;
        mHeight = pSurface->h;
        mTexture = SDL_CreateTextureFromSurface(mRenderer, pSurface);
        if (mTexture == nullptr)
        {
            std::cout << "Unable to create texture from surface. Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(pSurface);
    }
    else
    {
        std::cout << "Unable to create texture from surface. Error: " << IMG_GetError() << std::endl;
    }
    return mTexture != nullptr;
}

void Texture2D::Render(Vector2D p, SDL_RendererFlip flip, double angle, SDL_Rect* srcRect, SDL_Rect* renderLocation)
{
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0x00);
    if (p.x == -1)
        p = mPosition;
    if (renderLocation == nullptr)
    {
        SDL_Rect r = { p.x, p.y, static_cast<int>(mWidth), static_cast<int>(mHeight) };
        SDL_RenderCopyEx(mRenderer, mTexture, srcRect, &r, angle, nullptr, flip);
    }
    else
    {
        SDL_RenderCopyEx(mRenderer, mTexture, srcRect, renderLocation, angle, nullptr, flip);
    }
}