#ifndef STARTINGMENU_TOOLS_H
#define STARTINGMENU_TOOLS_H

#include <string>
#include <windows.h>
#include <vector>

static int width = int (GetSystemMetrics(SM_CXSCREEN) * 0.5);
static int height = int (GetSystemMetrics(SM_CYSCREEN) * 0.5);

class tools {
public:
    static bool isButton(int x, int y, int w, int h, const char* text);
    static bool inArea(int mx, int my, int x, int y, int w, int h);
    static void setText(int x, int y, int w, int h, const char* str);
    static std::basic_string<char> setInputBox(int x, int y, int w, int h);
    static bool isValidInput(const std::string& input);
};


#endif //STARTINGMENU_TOOLS_H
