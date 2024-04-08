#ifndef TEXTURE2D_H_
#define TEXTURE2D_H_
#include "CommonFunc.h"
#include "Vector2D.h" 
// class lưu trữ khi load ảnh lên
class Texture2D
{
public:
	// size
	float mWidth;
	float mHeight;

	SDL_Renderer* mRenderer; // màn hình hienr thị
	Vector2D mPosition; // vị trí
	SDL_Texture* mTexture; // biến lưu thông tin
	Texture2D() {
		mRenderer = NULL;
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
	Texture2D(SDL_Renderer* renderer) { // khởi tạo
		mRenderer = renderer;
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
	}
	void Free() { // xóa bộ nhớ
		if (mTexture != NULL)
		{
			SDL_DestroyTexture(mTexture);
			mTexture = NULL;
		}
		mWidth = 0;
		mHeight = 0;
	}
	~Texture2D() { // giải phóng bộ nhớ
		Free();

		mRenderer = NULL;
	}
	bool LoadFromFile(string path) { // load ảnh
		Free(); // giải phóng cũ
		SDL_Surface* pSurface = IMG_Load(path.c_str());

		if (pSurface != NULL)
		{
			SDL_SetColorKey(pSurface, SDL_TRUE, SDL_MapRGB(pSurface->format, 0, 0xFF, 0xFF)); // xóa nền

			mWidth = pSurface->w; // giảm kích thước ban đầu
			mHeight = pSurface->h;

			mTexture = SDL_CreateTextureFromSurface(mRenderer, pSurface); 
			if (mTexture == NULL)
			{
				cout << "Unable to create texture from surface. Error: " << SDL_GetError() << endl;
			}
			SDL_FreeSurface(pSurface);
		}
		else
		{
			cout << "Unable to create texture from surface. Error: " << IMG_GetError() << endl;
		}
		return mTexture != NULL;
	}
	// hiển thị đối tượng: vị trí, cách lấy đối xứng, góc xoay, phạm vi lấy, khung hiển thị
	void Render(Vector2D p = { -1, -1 }, SDL_RendererFlip flip = SDL_FLIP_NONE, double angle = 0.0f, SDL_Rect* srcRect = nullptr, SDL_Rect* renderLocation = nullptr) { // load ảnh lên màn hình xử lý
		SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0x00);
		// vẽ đối tượng lên màn hình xử lý, với khung vừa có, góc xoay angle, và cách lấy đối xứng flip
		if (p.x == -1)
			p = mPosition;
		if (renderLocation == nullptr){
			SDL_Rect r = { p.x, p.y, mWidth, mHeight };
			SDL_RenderCopyEx(mRenderer, mTexture, srcRect, &r, angle, NULL, flip);
		}
		else {
			SDL_RenderCopyEx(mRenderer, mTexture, srcRect, renderLocation, angle, NULL, flip);
		}
	}
};

#endif