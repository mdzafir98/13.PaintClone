#include "../include/Game.h"

int main(){
    InitWindow(512,512,"13_PAINT_APP");
    SetTargetFPS(30);
    Game game;

    while(WindowShouldClose()==false){
        //1. player event handling
        game.handleInput();

        //2. game loop
        game.update();

        //3. game draw loop
        BeginDrawing();
            ClearBackground(RAYWHITE);
            game.draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}