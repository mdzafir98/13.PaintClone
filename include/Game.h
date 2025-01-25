#pragma once
#include <raylib.h>
#include <vector>

#include "ColorSquare.h"
#include "InputBox.h"

class Game{
public:
    Game();
    ~Game();
    void init();
    void draw();
    void update();
    void handleInput();
    void drawUI();
    void initColorPallete();
    void drawColorPallete();
    void drawRGBInputBox();
    void drawBrushCursor();
    void initInputBox();
    void getInputColor();
    void drawColorValue();
private:
    std::vector<Color> colors{RAYWHITE, YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN,
        SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN,
        LIGHTGRAY, GRAY, DARKGRAY, BLACK};
    std::vector<ColorSquare*> colorUnits;
    Vector2 mousePos;
private:
    int brushSize{10};
    Color brushColor{0,0,0};
    Color inputColor{0,0,0};

    //RGB inputbox
    InputBox* r_inputBox = new InputBox({450,412},DARKGRAY,4,60,25);
    InputBox* g_inputBox = new InputBox({450,512-70},DARKGRAY,4,60,25);
    InputBox* b_inputBox = new InputBox({450,512-40},DARKGRAY,4,60,25);
    std::vector<InputBox*> inputBoxVector;

    //rgb input textbox
    bool mouseOnText{false};
    
    char rInput[4]="\0";
    char gInput[4]="\0";
    char bInput[4]="\0";
};