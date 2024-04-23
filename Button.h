#ifndef BUTTON_H_
#define BUTTON_H_
#include "CommonFunc.h"
#include "Vector2D.h"
#include "Texture2D.h"
#include "Slider.h"
#include "Player.h"
class Button {
public:
	Character* img;
	Vector2D size;
	Vector2D position;
	int type;
	bool isActive;
	Button(SDL_Renderer* renderer, int type, Vector2D p, float k) {
		img = new Character(renderer, "");
		this->type = type;
		this->isActive = true;
		string path = "./Images/UI/";
		string linksTxt[] = { "txtPlay.png", "txtQuit.png" };
		img->texture->LoadFromFile(path + linksTxt[type]);
		img->texture->mHeight *= k;
		img->texture->mWidth *= k;
		size = Vector2D(img->texture->mWidth, img->texture->mHeight);
		position = p;
		img->texture->mPosition = p - Vector2D(img->texture->mWidth, img->texture->mHeight)*0.5f;
	}
	~Button() {
		delete img;
	}
	void OnMouse(SDL_Event e) { // kiểm tra sự kiện
		int x = e.button.x;
		int y = e.button.y;
		if (x >= img->texture->mPosition.x && x <= img->texture->mPosition.x + img->texture->mWidth
			&& y >= img->texture->mPosition.y && y <= img->texture->mPosition.y + img->texture->mHeight) { // chuột ngang qua
			OnHigh();  // hiệu ứng phóng to
			switch (e.type)
			{
			case SDL_MOUSEBUTTONUP: {
				OnClick(); // gọi sk click
				break;
			}
			}

		}
		else {
			// trả về size ban đầu
			img->texture->mWidth = size.x;
			img->texture->mHeight = size.y;
			img->texture->mPosition = position - Vector2D(img->texture->mWidth, img->texture->mHeight) * 0.5f;
		}

	}
	void OnClick() {
		isActive = false;
	}
	void OnHigh() {
		float value = 1;
		img->texture->mWidth = Math::Clamp(img->texture->mWidth + 10, 0, size.x*1.2f); // Tăng chiều rộng lên 10 pixel
		img->texture->mHeight = Math::Clamp(img->texture->mHeight + 10, 0, size.y * 1.2f); // Tăng chiều cao lên 10 pixel
		img->texture->mPosition = position - Vector2D(img->texture->mWidth, img->texture->mHeight) * 0.5f;
	}
	void Update(SDL_Event e) {
		OnMouse(e);
		Render();
	}
	void Render() {
		img->texture->Render(Vector2D(-1, -1));
	}
};
#endif