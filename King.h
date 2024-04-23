#ifndef KING_H_
#define KING_H_
#include "CommonFunc.h"
#include "Vector2D.h"
#include "Texture2D.h"
#include "Slider.h"

int Slider::dau = 0;
class Character {
public:
	Texture2D *texture;
	string link; // đường dẫn file tổng
	int frame; // frame đang hiển thị
	float tiLe = 0.02f;
	bool isActive = true;
	bool flipX = false;
	Character(SDL_Renderer* renderer, string link) { // khởi tạo
		texture = new Texture2D(renderer);
		this->link = link;
		frame = 0;
	}
	~Character() {
		texture->Free();
		delete texture;
	}
	
	virtual void Update(SDL_Event e, float deltaTime = 0){}
};

class King : public Character {
public:
 
	Vector2D move;
	vector<Texture2D*> textureStates;
	Vector2D mPosition;
	Vector2D mScale;
	int state; // 0: idle, 1: run, 2: attack, 3: die
	float next_frame = 0.2f;
	float _next_frame = 0.2f;

	float deltaRandom = 0;
	bool flip;

	King(SDL_Renderer* renderer, Vector2D p) : Character(renderer, "") {
		string path = "./Images/King/";
		string name[] = { "Idle", "Run", "Attack", "Death" };
		string duoi = ".png";
		state = 0;
		flip = true;
		for (int i = 0; i < 4; i++) {
			Texture2D* t = new Texture2D(renderer);
			t->LoadFromFile(path + name[i] + duoi);
			textureStates.push_back(t);
		}
		this->mPosition = p;
		this->mScale = Vector2D(textureStates[0]->mWidth * 0.5f, textureStates[0]->mHeight * 0.8f);
	}
	~King() {
		texture->Free();
	}
	void Attack() {
		if (state == 2) return;
		state = 2;
		frame = 0;
	
	}
	void Death() {
		if (state == 3) return;
		state = 3;
		frame = 0;
	}

	void Update(SDL_Event e, float deltaTime = 0) override {
		RandomState(deltaTime);
		UpdateAnimation(deltaTime);
	}
	void RandomState(float deltaTime = 0) {
		if (state == 2) return;// nếu đang tấn công thì kết thúc
		deltaRandom -= deltaTime; // giảm thời gian tạo biến ngẫu nhiên
		if (deltaRandom <= 0) {// nếu thời gian chạy <= 0
			if (deltaRandom <= -1.0f) { // nếu thời gian quay mặt <= -1
				std::mt19937_64 rng(std::time(nullptr)); // Khởi tạo generator ngẫu nhiên với seed từ thời gian hiện tại
				std::uniform_real_distribution<double> dist(0.0, 5.0); // Phạm vi từ 0 đến 5
				deltaRandom = dist(rng);
				state = 1; // run
				frame = 0;
				flip = false; // run thì sẽ k lật ảnh theo trục Y
			}
			else {
				if (state != 0) {// trạng thái khác đứng
					flip = true;  // lật ảnh
					state = 0; // trạng thái đứng
					frame = 0;
				}
			}
		}
	}
	void UpdateAnimation(float deltaTime) {
		int frameMax[] = { 6, 8, 6, 11};

		if (_next_frame <= 0) {
			_next_frame = next_frame;
			if (frame >= frameMax[state] - 1) {
				frame = 0;
				switch (state)
				{
				case 2: {
					state = 0;
					break;
				}
				case 3: {
					frame = 10;
					break;
				}
				}
			}
			else {
				frame++;
			}
		}
		else {
			_next_frame -= deltaTime;
		}

		SDL_Rect t = { 155 * frame, 0, 155, textureStates[state]->mHeight }; // size 155*155
		SDL_Rect t2 = { mPosition.x, mPosition.y, mScale.x, mScale.y };
		textureStates[state]->Render(mPosition, !flip ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL, 0, &t, &t2);
	}
};
#endif