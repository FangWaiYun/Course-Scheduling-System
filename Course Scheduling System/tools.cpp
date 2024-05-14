#include "tools.h"
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <windows.h>
#include <regex>

ExMessage msg{0};

bool tools::isButton(int x, int y, int w, int h, const char *text) {
    fillroundrect(x,y,x+w,y+h,5,5);

    settextstyle(30,0,"微软雅黑");
    settextcolor(BLACK);

    int w_text = (w - textwidth(text)) / 2;
    int h_text = (h - textheight(text)) / 2;
    outtextxy(x + w_text, y + h_text, text);
    setfillcolor(RGB(195,195,195));

    if(peekmessage(&msg,EX_MOUSE)){

    }


    // Check if the mouse is in the area of the button
    if(inArea(msg.x, msg.y, x, y, w, h) && msg.message == WM_LBUTTONDOWN){
        return true;
    }

    msg.message = 0;

    return false;
}

bool tools::inArea(int mx, int my, int x, int y, int w, int h) {
    if(mx>x && mx<x+w && my>y && my<y+h){
        return true;
    }
    return false;
}

void tools::setText(int x, int y, int h, int w, const char *str) {
    settextstyle(h,w,"微软雅黑");
    settextcolor(BLUE);
    setbkmode(TRANSPARENT);
    outtextxy((width - x) / 2,y,str);
}

std::basic_string<char> tools::setInputBox(int x, int y, int w, int h) {
    setfillcolor(BLACK);
    fillrectangle(x, y, x + w, y + h);
    settextcolor(WHITE);
    settextstyle(30, 0, "Arial"); // Change the font to Arial

    std::string input;
    char ch;
    int textOffsetX = 10; // Offset for the text in the x direction
    int textOffsetY = 10; // Offset for the text in the y direction
    while (true) {
        if (_kbhit()) {
            ch = char(_getch());
            if (ch == '\r') { // Enter key pressed
                break;
            }
            else if (ch == '\b' && !input.empty()) { // Backspace key pressed
                input.pop_back();
            }
            else {
                input.push_back(ch);
            }
            setbkcolor(BLACK); // Set the background color to the color of the input box
            clearrectangle(x, y, x + w, y + h);
            setbkcolor(WHITE); // Reset the background color
            outtextxy(x + textOffsetX, y + textOffsetY, input.c_str()); // Add the offset to the text position
        }

        // Draw the cursor
        int cursorX = x + textOffsetX + textwidth(input.c_str());
        int cursorY = y + textOffsetY;
        int cursorWidth = textwidth(" "); // Width of a single character
        solidrectangle(cursorX, cursorY, cursorX + cursorWidth, cursorY + textheight(input.c_str()));

        FlushBatchDraw(); // Update the window

        // Blink the cursor
        Sleep(200);
        setfillcolor(BLACK);
        solidrectangle(cursorX, cursorY, cursorX + cursorWidth, cursorY + textheight(input.c_str()));
        setfillcolor(WHITE);
        Sleep(200);
    }

    // Check if the input is empty or invalid
        if (input.empty()) {
            MessageBox(nullptr, "Please enter a course.", "Warning", MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL);
            } else if (!isValidInput(input)) {
            MessageBox(nullptr, "Please enter a course in the correct format.", "Warning", MB_OK | MB_ICONWARNING | MB_SYSTEMMODAL);
            }
        return input;
}

bool tools::isValidInput(const std::string& input) {
    // Pattern for the first type of input
    std::regex pattern1("[A-Z]{3}[0-9]{4} [A-Za-z]{2}[0-9]{4}-[A-Za-z]{2}[0-9]{4}\\+[A-Za-z]{2}[0-9]{4}-[A-Za-z]{2}[0-9]{4}");
    // Pattern for the second type of input
    std::regex pattern2("[A-Z]{3}[0-9]{4} [A-Za-z]{2}[0-9]{4}-[A-Za-z]{2}[0-9]{4}");

    // Check if the input matches either of the patterns or is "quit"
    return std::regex_match(input, pattern1) || std::regex_match(input, pattern2) || input == "end";
}