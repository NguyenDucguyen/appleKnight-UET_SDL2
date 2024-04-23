#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"
#include "src/include/SDL2/SDL_mixer.h"
#include "Math.h"
#include "Background.h"
#include "Button.h"
#include "Player.h"
#include "King.h"



// khởi tạo sdl
bool InitSDL()
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else
	{
		gWindow = SDL_CreateWindow("ShowTimeBruhKa",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			cout << "Window was not created. Error : " << SDL_GetError();
			return false;
		}
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer != NULL)
	{
		int imageFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imageFlags) & imageFlags))
		{
			cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
			return false;
		}

	}

	else
	{
		cout << "Renderer could not initialise. Error: " << SDL_GetError();
		return false;
	}

	return true;


}
// đóng sdl
void CloseSDL()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();

	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	Mix_CloseAudio();
	Mix_Quit();
}
// load ảnh
SDL_Texture* LoadTextureFromFile(string path)
{
	SDL_Texture* pTexture = NULL;

	SDL_Surface* pSurface = IMG_Load(path.c_str());
	if (pSurface != NULL)
	{
		pTexture = SDL_CreateTextureFromSurface(gRenderer, pSurface);
		if (pTexture == NULL)
		{
			cout << "Unable to create texture from surface. Error: " << SDL_GetError() << endl;
		}
		SDL_FreeSurface(pSurface);
	}
	else
	{
		cout << "Unable to create texture from surface. Error: " << IMG_GetError() << endl;
	}
	return pTexture;
}
void Play(); // chơi
void Menu(); // menu


 



class Audio {
public:
	static void Play(int value) {
		string path = "./Sounds/";
		string name[] = { "gun.wav", "bom.wav" };
		Mix_Chunk* sound2 = Mix_LoadWAV((path + name[value]).c_str());
		Mix_PlayChannel(-1, sound2, 0);
	}
};

int main(int argc, char* argv[])
{
	if (InitSDL())
	{
		srand(time(0)); 
		Mix_Chunk* sound = Mix_LoadWAV("./Sounds/BackGround.wav"); // phát nhạc
		Mix_PlayChannel(-1, sound, 0);
		Menu();
		//Play();
	}
	CloseSDL();
	return 0;
}

void Play() {
	SDL_Event e;
	BackGround bg(gRenderer, -1); // tạo bg
	
	Button quit(gRenderer, 1, Vector2D(850, 40), 0.15f); // tạo nút thoát

	Player *player = new Player(gRenderer, Vector2D(-150, 385)); // tạo ng chơi
	King* king = new King(gRenderer, Vector2D(100, 440)); // tạo king
	Slider* slider = new Slider(gRenderer, Vector2D(200, 50)); // tạo slider (cái thanh đo trên đầu nhân vật)
	bool endGame = false;
	float deltatime = 0; 
	while (!endGame) {
		gOldTime = SDL_GetTicks(); 
		SDL_PollEvent(&e); 
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

		bg.Update(); 


		if (!quit.isActive)
			endGame = true;

		king->Update(e, deltatime); // update king
		if (king->state != 2 && player->state != 3 && player->frame != 6) // nếu king k tấn công và người chơi không chết thì update người chơi
			player->Update(e, deltatime);

		if (player->state == 2 && player->frame >= 1 && king->state == 0) { // nếu ng chơi tấn công tại frame 1 và king quay lại
			king->Attack(); // king tấn công
			player->Death(); // player die
			slider->value = 0; // reset value
		}
		if ((king->state == 1 && king->frame == 11) || (king->state == 3 && king->frame == 10)) break; // king tấn công xong và kết thúc hoặc king die
		if (king->state != 2) { // king không taasn công
			slider->Update(deltatime); // cập nhật slider
			if (slider->value == slider->maxValue) { // nếu đầy thì tấn công
				player->Attack();
				if (player->frame == 3) // nếu đến frame 3 thì king die
					king->Death();
			}
		}
		quit.Update(e);
		SDL_zero(e);
		SDL_RenderPresent(gRenderer); 
		deltatime = (float)(SDL_GetTicks() - gOldTime) / 1000.0f; 
	}
	bg.Free();
}
void Menu() {
	SDL_Event e;
	BackGround bg(gRenderer);

	Button play(gRenderer, 0, Vector2D(250, 400), 0.2f);
	Button quit(gRenderer, 1, Vector2D(650, 400), 0.2f);
	float deltatime = 0;
	while (true) {
		SDL_PollEvent(&e); 
		gOldTime = SDL_GetTicks(); 
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(gRenderer);

		bg.Update();
		play.Update(e);
		quit.Update(e);

		SDL_RenderPresent(gRenderer);
		if (!play.isActive) {
			Play();
			play.isActive = true;
			e.button.x = -1;
		}
		else
			if (!quit.isActive) {
				return;
			}
		deltatime = (float)(SDL_GetTicks() - gOldTime) / 1000.0f; 
	}
}
