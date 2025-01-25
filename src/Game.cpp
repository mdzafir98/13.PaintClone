#include "../include/Game.h"

Game::Game()
{
    init();
}

Game::~Game()
{
}

void Game::init()
{
    initColorPallete();
    initInputBox();
}

void Game::draw()
{
    DrawRectangle(0,GetScreenHeight()-100,GetScreenWidth(),100,{29,27,27,255});
    drawColorPallete();
    drawRGBInputBox();
    drawUI();
    drawBrushCursor();
    drawColorValue();
}

void Game::update()
{
}

void Game::handleInput()
{
    mousePos={GetMousePosition()};

    //select color from using pallete
    for (auto& unit:colorUnits){
        if (CheckCollisionPointRec(mousePos,unit->getRect())){
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                unit->stateColor();
                brushColor=unit->getColor();
            }
        }
    }

    //BRUSHSIZE WRT MOUSE-SCROLL
    brushSize += GetMouseWheelMove();
    if(brushSize<2){
        brushSize=2;
    } else if(brushSize>50){
        brushSize=50;
    }

    //ERASER FUNCTION
    if (IsKeyPressed(KEY_E)){
        brushColor=RAYWHITE;
    }

    for (auto& box:inputBoxVector){
        if (CheckCollisionPointRec(mousePos,box->getRect())){
            box->mouseOnBox=true;
        } else{
            box->mouseOnBox=false;
        }
        box->update();
    }

    if (CheckCollisionPointRec(mousePos,r_inputBox->getRect()) || CheckCollisionPointRec(mousePos,g_inputBox->getRect()) || CheckCollisionPointRec(mousePos,b_inputBox->getRect())){
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
    } else{
        SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    }

    if (IsKeyPressed(KEY_R)){
        std::cout << "R-VALUE: " << r_inputBox->input << "\n";
    } else if(IsKeyPressed(KEY_G)){
        std::cout << "G-VALUE: " << g_inputBox->input << "\n";
    } else if(IsKeyPressed(KEY_B)){
        std::cout << "B-VALUE: " << b_inputBox->input << "\n";
    }

    if (IsKeyPressed(KEY_ENTER)){
        getInputColor();
        brushColor = inputColor;
    }


    // if (mouseOnText){
    //     SetMouseCursor(MOUSE_CURSOR_IBEAM);
    //     int key=GetCharPressed();
    //     while(key>0){
    //         if ((key>=48) && (key<=57)){
    //             rInput[count]=(char)key;
    //             rInput[count+1]='\0';
    //             count++;
    //         }
    //         key=GetCharPressed();
    //     }
    //     if(IsKeyPressed(KEY_BACKSPACE)){
    //         count--;
    //         if(count<0){
    //             count=0;
    //         }
    //         rInput[count]='\0';
    //     }
    // } else{
    //     SetMouseCursor(MOUSE_CURSOR_DEFAULT);
    // }
}

void Game::drawUI()
{
    DrawText(TextFormat("BRUSH SIZE: %i  | ",brushSize),0,(float)GetScreenHeight()-25,20,RAYWHITE);
    DrawText("COLOR: ",200,(float)GetScreenHeight()-25,20,RAYWHITE);
    DrawRectangle(280,(float)GetScreenHeight()-25,50,20,brushColor);
}

void Game::initColorPallete()
{
    for (int i=0; i<colors.size(); i++){
        if (i<10){
            ColorSquare* unit = new ColorSquare(colors.at(i),{(float)i*32,(float)GetScreenHeight()-98});
            colorUnits.push_back(unit);
        } else if (i>10){
            ColorSquare* unit = new ColorSquare(colors.at(i),{(float)(i-11)*32,(float)GetScreenHeight()-66});
            colorUnits.push_back(unit);
        }
    }
}

void Game::drawColorPallete()
{
    for (auto& unit:colorUnits){
        unit->draw();
    }
}

void Game::drawRGBInputBox()
{
    for (auto& box:inputBoxVector){
        box->draw();
    }
    //rgb textbox
    DrawText("R:", 420, GetScreenHeight()-100, 20, RED);
    DrawText("G:", 420, GetScreenHeight()-70, 20, GREEN);
    DrawText("B:", 420, GetScreenHeight()-40, 20, BLUE);
}

void Game::drawBrushCursor()
{
    DrawCircle(mousePos.x,mousePos.y,brushSize,brushColor);
}

void Game::initInputBox()
{
    inputBoxVector.push_back(r_inputBox);
    inputBoxVector.push_back(g_inputBox);
    inputBoxVector.push_back(b_inputBox);
}

void Game::getInputColor()
{
    unsigned char r_uint = reinterpret_cast<unsigned char>(r_inputBox->input);
    unsigned char g_uint = reinterpret_cast<unsigned char>(g_inputBox->input);
    unsigned char b_uint = reinterpret_cast<unsigned char>(b_inputBox->input);
    inputColor = {r_uint,g_uint,b_uint,255};
}

void Game::drawColorValue()
{
    for (auto& unit:colorUnits){
        if ((CheckCollisionPointRec(mousePos,unit->getRect()))){
            unit->showColorDetails();
        }
    }
}