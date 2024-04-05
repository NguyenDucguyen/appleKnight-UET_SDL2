#ifndef BACKGROUND_H_
#define BACKGROUND_H_
#include "CommonFunc.h"
#include "Vector2D.h"
#include "Texture2D.h"
#include "Slider.h"
#include "Player.h"

class BackGround {
public:
	vector<Character*> BG; //các biến lưu ảnh
	float speed = 0.01f; //tốc độ chạy của ảnh
	bool isRunning = false; // ảnh chạy
	BackGround(SDL_Renderer* renderer, int type = 0) {
		string part = "./Images/Map/";
		string duoi = ".png";
		string names[] = { "BG1", "BG2"};
		for (int i = 0; i < 2; i++) {
			Character* bg = new Character(renderer, "");
			bg->texture->LoadFromFile(part + names[i] + duoi);
			bg->texture->mHeight = SCREEN_HEIGHT;
			bg->texture->mWidth = SCREEN_WIDTH;

			BG.push_back(bg);
		}
		if (type == 0) {
			Character* t = new Character(renderer, "");
			t->texture->LoadFromFile(part + "Salt" + duoi);
			t->texture->mHeight /= 0.75f;
			t->texture->mWidth /= 0.75f;
			//cout << t->texture->mHeight << " " << t->texture->mWidth;
			t->texture->mPosition = Vector2D(SCREEN_WIDTH / 2 - t->texture->mWidth / 2, SCREEN_HEIGHT - t->texture->mHeight);
			BG.push_back(t);
		}
		else {
			Character* t = new Character(renderer, "");
			t->texture->LoadFromFile(part + "BG3" + duoi);
			t->texture->mHeight /= 0.75f;
			t->texture->mWidth /= 0.5f;
			//cout << t->texture->mHeight << " " << t->texture->mWidth;
			t->texture->mPosition = Vector2D(SCREEN_WIDTH / 2 - t->texture->mWidth / 2, SCREEN_HEIGHT - t->texture->mHeight);
			BG.push_back(t);

			Character* t2 = new Character(renderer, "");
			t2->texture->LoadFromFile(part + "BG3" + duoi);
			t2->texture->mHeight /= 0.75f;
			t2->texture->mWidth /= 0.5f;
			//cout << t->texture->mHeight << " " << t->texture->mWidth;
			t2->texture->mPosition = Vector2D(SCREEN_WIDTH / 2 + t2->texture->mWidth / 2, SCREEN_HEIGHT - t2->texture->mHeight);
			BG.push_back(t2);
		}
	}
	void Update() {
		for (int i = 0; i < BG.size(); i++) {
			BG[i]->texture->Render(Vector2D(-1, -1), SDL_FLIP_NONE); // hiển thị ảnh 
		}
		if(isRunning)
			Move();
	}
	void Move() {
		Move(2);
		Move(3);
	}
	void Move(int index) { // giảm vị trí x của đối tượng tại chỉ số index
		if (index < BG.size()) {
			BG[index]->texture->mPosition.x -= speed;
			if (BG[index]->texture->mPosition.x <= -SCREEN_WIDTH) //tạo vòng lặp
				BG[index]->texture->mPosition.x = SCREEN_WIDTH;
		}
	}
	void Free() {
		for (int i = 0; i < BG.size(); i++){
			BG[i]->texture->Free();
		}
		BG.clear();
	}
};

#endif