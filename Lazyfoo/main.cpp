// sử dung SDL và IO cơ bả
#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

//kích thước cố định của cửa sổ
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main () {
    // cửa sổ sẽ hiển thị
    SDL_Window* window = NULL;

    // cửa sổ sẽ chứa
    SDL_Surface* screenSurface = NULL;

    // khởi động SDL
    if (SDL_Init( SDL_INIT_VIDEO) < 0 ) {
        cout << "SDL không thể khởi động SDL_Error: %s\n " << SDL_GetError() << endl;
    } else {
        // tạo cửa sổ
        window = SDL_CreateWindow ("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            cout << "Window không thể khởi tạo!" << SDL_GetError();
        } else {
            // khởi tạo bề mặt cửa sổ
            screenSurface = SDL_GetWindowSurface(window);

            // tô màu trắng toàn bộ cửa sổ
            SDL_FillRect (screenSurface, NULL, SDL_MapRGB(screenSurface-> format,0xFF,0xFF,0xFF));

            //cập nhật bề mặt cửa sổ
            SDL_UpdateWindowSurface(window);

            // giữ cửa sổ
            SDL_Event e;
            bool quit = false;
            while (quit == false) {
                while (SDL_PollEvent(&e)) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
            }
        }
    }

    // hủy cửa sổ và giải phóng bộ nhớ
    SDL_DestroyWindow(window);

    //thoát SDL
    SDL_Quit;
    return 0;
}