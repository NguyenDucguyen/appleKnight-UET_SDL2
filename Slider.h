#ifndef SLIDER_H_
#define SLIDER_H_
#include "CommonFunc.h"
#include "Vector2D.h"
#include "Texture2D.h"
#include "Math.h"

class Slider {
public:
    float minValue, value, maxValue;
    float deltaDelay = 0.5f;
    float _deltaDelay = 0.5f;
    static int dau;
    Texture2D* bg;

    Vector2D mPosition;
    Vector2D mScale;

    Slider(SDL_Renderer* renderer, Vector2D index);
    void Update(float deltaTime = 0);
    void Show();
};


#endif