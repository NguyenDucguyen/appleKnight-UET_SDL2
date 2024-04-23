#include "Slider.h"

int Slider::dau = 0;

Slider::Slider(SDL_Renderer* renderer, Vector2D index) {
    bg = new Texture2D(renderer);
    bg->LoadFromFile("./Images/UI/Slider.png");
    mPosition = index;
    minValue = 0;
    maxValue = 18; // vì có 18 frame ảnh
    value = 0;
    dau = 0;
}

void Slider::Update(float deltaTime) {
    if (_deltaDelay <= 0) { // tạo độ delay để tăng/giảm giá trị
        _deltaDelay = deltaDelay;
        value = Math::Clamp(value + dau, minValue, maxValue);
        if (value == 0 && dau == -1)
            dau = 0;
    }
    else {
        _deltaDelay -= deltaTime;
    }
    Show();
}

void Slider::Show() { // hiển thị ảnh vì ảnh w = 16, h = độ dài ảnh/18 frame
    SDL_Rect t = { 0, 16 * static_cast<int>(value), 64, bg->mHeight / 17 };
    SDL_Rect t2 = { static_cast<int>(mPosition.x), static_cast<int>(mPosition.y), 500, 50 }; // vị trí hiển thị
    bg->Render(mPosition, SDL_FLIP_NONE, 0, &t, &t2);
}