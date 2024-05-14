#include <graphics.h>
#include "chooseCourse.h"
#include "tools.h"
#include "courseManage.h"
#include <iostream>

std::string chooseCourse::allCourse;

chooseCourse::chooseCourse() {
    initgraph(width, height);
    setbkcolor(WHITE);
    cleardevice();
    setbkmode(TRANSPARENT);
    int n = 15;

    while(n > 0){
        n--;
        tools::setText(650, 100, 35, 0, "Please input a course:");
        tools::setText(650, 150, 15, 0, "e.g. CSC3002 Mo0830-Mo1020+We0830-We1020 ");
        tools::setText(650, 170, 15, 0, " Or  CEC3000 Fr1400-Fr1720");

        std::string input = tools::setInputBox(100, 200, 625, 175);
        if (!input.empty() && tools::isValidInput(input) && input != "end") {
            allCourse += input +  ' ';
        }

        while(input == "end"){
            BeginBatchDraw();

            if (tools::isButton(634, 400, 100, 50, "Submit")) {
                allCourse += "end ";
                std::cout << allCourse << std::endl;
                courseManage();
                closegraph();
                break;
            }

            EndBatchDraw();
        }
    }
}