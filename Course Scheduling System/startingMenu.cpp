#include <graphics.h>
#include "startingMenu.h"
#include "tools.h"
#include "chooseCourse.h"

startingMenu::startingMenu() {
    initgraph(width, height);
    setbkcolor(WHITE);

    // Set the title of the window
    HWND hwnd = GetHWnd(); // Get the window handle
    SetWindowTextW(hwnd, L"Course Scheduling System"); // Set the window title (directly use wide string)

    // Load the image
    IMAGE img;
    loadimage(&img, _T("E:\\Year 2 Summer Semester\\CSC3002\\Group Project\\Course Scheduling System\\BGP2.png"));

    setbkmode(TRANSPARENT);

    while(true){
        BeginBatchDraw();
        cleardevice();
        putimage(0, 0, &img);


        if (tools::isButton(325, 300, 200, 80, "START")){
            chooseCourse();
            closegraph();
            break;
        }

        tools::setText(725, 160, 60, 0, "Course Scheduling System");
        EndBatchDraw();
    }
}
