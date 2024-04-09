#ifndef TEXTURE2D_H_
#define TEXTURE2D_H_
#include "CommonFunc.h"
#include "Vector2D.h" 
class Texture2D
{
public:
    float mWidth;
    float mHeight;
    SDL_Renderer* mRenderer;
    Vector2D mPosition;
    SDL_Texture* mTexture;

    Texture2D();
    Texture2D(SDL_Renderer* renderer);
    ~Texture2D();
    void Free();
    bool LoadFromFile(std::string path);
    void Render(Vector2D p = { -1, -1 }, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0.0f, SDL_Rect* srcRect = nullptr, SDL_Rect* renderLocation = nullptr);
};

#endif