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

	Slider(SDL_Renderer* renderer, Vector2D index) {
		bg = new Texture2D(renderer);
		bg->LoadFromFile("./Images/UI/Slider.png");
		mPosition = index;
		minValue = 0;
		maxValue = 17; // vì có 17 frame ảnh
		value = 0;
		dau = 0;
	}
	void Update(float deltaTime = 0) {
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
	void Show() { // hiển thị ảnh vì ảnh w = 16, h = độ dài ảnh/17 frame
		SDL_Rect t = { 0, 16*value, 64, bg->mHeight/17 };
		SDL_Rect t2 = { mPosition.x, mPosition.y, 500, 50 }; // vị trí hiển thị
		bg->Render(mPosition, SDL_FLIP_NONE, 0, &t, &t2);
	}

};


#endif