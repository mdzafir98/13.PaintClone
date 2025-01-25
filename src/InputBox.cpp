#include "../include/InputBox.h"

InputBox::InputBox(Vector2 position, Color color, int inputLength, int width, int height)
{
    m_position=position;
    m_color=color;
    m_inputLength=inputLength;
    m_height=height;
    m_width=width;
}

void InputBox::draw()
{
    DrawRectangle(m_position.x, m_position.y, m_width, m_height, m_color);
    drawText();
}

void InputBox::update()
{
    if (mouseOnBox==true){
        int key=GetCharPressed();
        while(key>0 && count<maxSize){
            if (key>=48 && key<=57){
                input[count]=(char)key;
                input[count+1]='\0';
                count++;
            }
            key=GetCharPressed();
        }

        if(IsKeyPressed(KEY_BACKSPACE)){
            count--;
            if(count<0){
                count=0;
            }
            input[count]='\0';
        }
    }
}

void InputBox::drawText()
{
    DrawText(input,m_position.x,m_position.y,20,RAYWHITE);
}

Rectangle InputBox::getRect() const
{
    return {m_position.x,m_position.y,m_width,m_height};
}
