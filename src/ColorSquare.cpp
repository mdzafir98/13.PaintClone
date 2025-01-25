#include "../include/ColorSquare.h"

ColorSquare::ColorSquare(Color color, Vector2 position)
{
    m_position=position;
    m_color=color;
}

void ColorSquare::init()
{
}

void ColorSquare::draw()
{
    DrawRectangle(m_position.x,m_position.y,30,30,m_color);
}

void ColorSquare::stateColor(){
    std::cout << "COLOR CHOSEN: " << m_color.r << " " << m_color.g << " " << m_color.b << "\n";
}

Rectangle ColorSquare::getRect() const
{
    return {m_position.x,m_position.y,30,30};
}

Color ColorSquare::getColor()
{
    return m_color;
}

void ColorSquare::showColorDetails()
{
    DrawText(TextFormat("%u,%u,%u",m_color.r,m_color.g,m_color.b),GetMousePosition().x-20,GetMousePosition().y-20,20,RAYWHITE);
    // DrawText("R,G,B",GetMousePosition().x,GetMousePosition().y-10,18,RAYWHITE);
}
