#pragma once
#include <raylib.h>

class InputBox{
public:
    InputBox(Vector2 position,Color color,int inputLength,int width, int height);
    void draw();
    void update();
    void drawText();
    Rectangle getRect() const;
    char input[50]="\0";
    bool mouseOnBox{false};
private:
    Vector2 m_position;
    Color m_color{DARKGRAY};
    int m_inputLength;
    int maxSize{4};
    int count;
    int m_height, m_width;
};