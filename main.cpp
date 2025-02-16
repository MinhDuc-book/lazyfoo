// sử dung SDL và IO cơ bả
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

using namespace std;

//kích thước cố định của cửa sổ
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// cửa sổ được kết xuất
SDL_Window *gWindow = NULL;

// bề mặt của cửa sổ
SDL_Surface *gScreenSurface = NULL;

// hình ảnh sẽ được load lên cửa sổ
SDL_Surface *gHelloWorld = NULL;

// khởi động SDL và tạo cửa sổ
bool init () {
    // thông báo khởi tạo
    bool success = true;

    // khởi tạo SDL
    if (SDL_Init (SDL_INIT_VIDEO) < 0) {
        cout << "SDL không thể khởi tạo! SDL_Error: %s\n" << SDL_GetError << endl;
        success = false;
    } else {
        // tạo cửa sổ 
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            cout << "Cửa sổ không thể khởi tạo! SDL_Error: %s\n" << SDL_GetError << endl;
            success = false;
        } else {
            // tạo bề mặt cửa sổ
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }

    return success;
}

//tải media
bool loadMedia() {
    // báo hiệu tải lên hoàn thành
    bool success = true;

    // tải hình ảnh, có thể sử dụng SDL_BMG để tải ảnh định dạng BMG
    gHelloWorld = IMG_Load("tim.JPG"); // dùng IMG_Load cho các ảnh không được hỗ trợ
    if (gHelloWorld == NULL) {
        cout << "Không thể tải ảnh! %s\n" << "D:/project/Lazyfoo/hehe.JPG" << SDL_GetError() ;
        success = false;
    }

    return success;
}

//giải phóng media và tắt SDL
void close() {
    // giải phóng bề mặt
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    // Tắt cửa sổ
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Thoát SDL
    SDL_Quit();
}

int main (int argv, char *argc[]) {
    // khởi động SDL và tạo cửa sổ
    if (init() == false) {
        cout << "Không thể khởi động cửa sổ" << endl;
    } else {
        // tải ảnh lên
        if (loadMedia() == false) {
            cout << "Không thể tải ảnh lên" << endl;
        } else {
            // tải ảnh lên
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            //cập nhật bề mặt cửa sổ
            SDL_UpdateWindowSurface (gWindow);
            
            // giữ cửa sổ mở
            SDL_Event e;
            bool quit = false;
            while (quit == false) {
                while (SDL_PollEvent(&e) == true) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }
            }
        }
    }
    // giải phóng tài nguyên và đóng SDL
    close();
    return 0;
}