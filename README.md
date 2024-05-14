这个程序是用C++写的，要想实用UI，还得下载Easyx。有效输入大概长这样：CSC3002 “Tu0830-0930+Th0830-0930”。
如果下载Easyx太麻烦了，你也可以下载 "Lesson_Arrange_4.cpp" 并运行这个文件（该文件和其他文件无关）。但是这个程序不会在你输入错误格式时提醒你。
我让"Lesson_Arrange_4.cpp"这个代码只输出前五项课程表，以防过多的输出让你的终端很难看，如果你需要更多可能的课程表（比如输入了20学分的课但并不准备报那么多），那么你可以修改代码（把main的最后一个if判断修改为"outputall(schedules)"），然后查看后面的课程表。越后面课程越少。
The program is based on C++, and if you want to use UI, you also need a tool called Easyx. The vaild format is "lessonname time"(such as "CSC3002 Tu0830-0930+Th0830-0930"). 
If you are unwilling to download Easyx, you can only download the program called "Lesson_Arrange_4.cpp", which can also print the schedule. But you may not be warned if you input the wrong message.
In order to make your output in "Lesson_Arrange_4.cpp" short, I only allow it to print five schedules. If you need more, please change "if......else......" to "outputall(schedules)" in the final of main.
