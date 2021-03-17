#include <iostream>
#include <SDL.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
int STEP_DELAY = 10;

struct Box {
    int x;
    int y;
    int size = 10;
    int stepx = 0;
    int stepy = 0;
    Box(int _x, int _y) :x(_x), y(_y) {}
    void render(SDL_Renderer* renderer) {
        SDL_Rect filled_rect;
        filled_rect.x = x;
        filled_rect.y = y;
        filled_rect.w = size;
        filled_rect.h = size;
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &filled_rect);
    }
    void turnLeft() {
        stepx = -3;
        stepy = 0;
    }
    void turnRight() {
        stepx = 3;
        stepy = 0;
    }
    void turnDown() {
        stepy = 3;
        stepx = 0;
    }
    void turnUp() {
        stepy = -3;
        stepx = 0;
    }
    void move() {
        x += stepx;
        y += stepy;
    }
    bool inside(int minx, int miny, int maxx, int maxy)
    {
        return (minx <= x && miny <= y && x + size <= maxx && y + size <= maxy);
    }
};

void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal = false);
const string WINDOW_TITLE = "Demo";

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
void waitUntilKeyPressed();

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    Box box(10, 10);

    SDL_Event e;
    while (box.inside(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT)) {
        box.move();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //white
        SDL_RenderClear(renderer);
        box.render(renderer);
        SDL_RenderPresent(renderer);

        SDL_Delay(STEP_DELAY);
        if (SDL_PollEvent(&e) == 0) continue;
        // N?u s? ki?n là k?t thúc (nhu dóng c?a s?) thì thoát kh?i vòng l?p
        if (e.type == SDL_QUIT) break;
        // N?u có m?t phím du?c nh?n, thì xét phím dó là gì d? x? lý ti?p
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE: break; // N?u nh?n phìm ESC thì thoát kh?i vòng l?p
            // N?u phím mui tên trái, d?ch sang trái
            // (c?ng chi?u r?ng, tr? bu?c, r?i l?y ph?n du d? giá tr? luôn duong, và hi?u ?ng quay vòng)
            case SDLK_LEFT: box.turnLeft();
                break;
                // Tuong t? v?i d?ch ph?i, xu?ng và lên
            case SDLK_RIGHT: box.turnRight();
                break;
            case SDLK_DOWN:  box.turnDown();
                break;
            case SDLK_UP: box.turnUp();
                break;
            default: break;
            }
        }
    }

    quitSDL(window, renderer);
    return 0;
}
void logSDLError(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window*& window, SDL_Renderer*& renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    //Khi thông thu?ng ch?y v?i môi tru?ng bình thu?ng ? nhà
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
        SDL_RENDERER_PRESENTVSYNC);
    //Khi ch?y ? máy th?c hành WinXP ? tru?ng (máy ?o)
    //renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if (SDL_WaitEvent(&e) != 0 &&
            (e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
            return;
        SDL_Delay(100);
    }
}
