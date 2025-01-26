#pragma once
#include <raylib.h>
#include <iostream>

class ColorSquare{
public:
    ColorSquare(Color color, Vector2 position);
    void init();
    void draw();
    void stateColor();
    void showColorDetails();
    void drawChosenBorder();
    Rectangle getRect() const;
    Color getColor();
private:
    Vector2 m_position;
public:
    Color m_color;
    bool selected{false};
};