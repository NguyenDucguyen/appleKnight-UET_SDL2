#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "CommonFunc.h"
#include "Vector2D.h"
#include "Texture2D.h"
#include "Slider.h"

class Character {
public:
    Texture2D* texture;
    string link;
    int frame;
    float tiLe;
    bool isActive;
    bool flipX;

    Character(SDL_Renderer* renderer, string link) : texture(nullptr), link(link), frame(0), tiLe(0.02f), isActive(true), flipX(false) {
        texture = new Texture2D(renderer);
    }

    virtual ~Character() {
        if (texture) {
            texture->Free();
            delete texture;
        }
    }

    virtual void Update(SDL_Event e, float deltaTime = 0) {}
};



class Player : public Character {
public:
    vector<Texture2D*> textureStates;
    Vector2D mPosition;
    Vector2D mScale;
    int state;
    float next_frame;
    float _next_frame;

   Player(SDL_Renderer* renderer, Vector2D p) : Character(renderer, "") {
		string path = "./Images/Thief/";
		string name[] = { "Idle", "Run", "Attack", "Death" };
		string duoi = ".png";
		state = 0;
		for (int i = 0; i < 4; i++) { 
			Texture2D* t = new Texture2D(renderer);
			t->LoadFromFile(path + name[i] + duoi);
			/*t->mHeight = 100;
			t->mWidth = 50;*/
			//cout << t->mWidth << " " << t->mHeight << endl;
			textureStates.push_back(t);
		}
		this->mPosition = p; 
		this->mScale = Vector2D(textureStates[0]->mWidth*0.8f, textureStates[0]->mHeight* 1.2f);
	}
	~Player() {
		texture->Free();
	}

    void CheckInput(SDL_Event& e) {
        switch (e.type) {
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_RETURN:
                        if ( state == 2 ) break;
                        state = 1;
                        Slider::dau = 1;
                        frame = 0;
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (e.key.keysym.sym) {
                    case SDLK_RETURN:
                        state = 0;
                        Slider::dau = -1;
                        frame = 0;
                        break;
                }
                break;
        }
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
        CheckInput(e);
        UpdateAnimation(deltaTime);
    }

    void UpdateAnimation(float deltaTime) {
        int frameMax[] = { 4, 8, 4, 7 };

        if (_next_frame <= 0) {
            _next_frame = next_frame * (state == 3 ? 2 : 1);
            if (frame >= frameMax[state] - 1) {
                frame = 0;
                switch (state) {
                    case 2:
                        state = 0;
                        break;
                    case 3:
                        frame = 6;
                        break;
                }
            } else {
                frame++;
            }
        } else {
            _next_frame -= deltaTime;
        }

        SDL_Rect t = { 200 * frame, 0, 200, textureStates[state]->mHeight };
        SDL_Rect t2 = { mPosition.x, mPosition.y, mScale.x, mScale.y };
        textureStates[state]->Render(mPosition, SDL_FLIP_NONE, 0, &t, &t2);
    }
};

#endif