#include "courseManage.h"
#include <iostream>
#include <vector>
#include "chooseCourse.h"
#include <graphics.h>
#include <string>
using namespace std;

int convert(string time)
{
    int day;
    int hour = stoi(time.substr(2, 2));
    int minute = stoi(time.substr(4, 2));
    int ans;
    if (time.substr(0, 2) == "Mo") day = 0;
    if (time.substr(0, 2) == "Tu") day = 1;
    if (time.substr(0, 2) == "We") day = 2;
    if (time.substr(0, 2) == "Th") day = 3;
    if (time.substr(0, 2) == "Fr") day = 4;
    if (time.substr(0, 2) == "Sa") day = 5;
    if (time.substr(0, 2) == "Su") day = 6;

    ans = day*24*60+hour*60+minute;

    return ans;
}

vector<int> timemessage(string t){
    vector<int> time;
    int plus=-1;
    for (int i = 0; i < t.length(); ++i) {
        if(t.substr(i,1)=="+"){
            plus=i;
        }
    }
    if(plus==-1){
        time.push_back(convert(t.substr(0,6)));
        time.push_back(convert(t.substr(7,6)));
        return time;
    }else{
        time.push_back(convert(t.substr(0,6)));
        time.push_back(convert(t.substr(7,6)));
        time.push_back(convert(t.substr(14,6)));
        time.push_back(convert(t.substr(21,6)));
        return time;
    }
}
class lesson{
public:
    string name;
    vector<int> time;
    lesson(string m,string t){//��ʼ���γ���Ϣ��ʱ����Ϣ
        name=m;
        time=timemessage(t);
    };

};
void output(vector<lesson> lessons){//����2������γ̱�
    for (int i = 0; i < lessons.size(); ++i) {
        cout<<lessons[i].name<<" "<<lessons[i].time[0]<<" "<<lessons[i].time[1]<< " "<<lessons[i].time[2]<<" "<<lessons[i].time[3]<<endl;//�޸ģ����ˡ�1���Է���������Ҫ�޸ĳɾ���ʱ��
    }
    cout<<endl;
};

void outputall(vector<vector<lesson>> schedules){//����3��������пγ̱���������Ϊ�������ǰȥ���ظ��Ŀγ̱����Ը��ݿγ̱�ʱ���������
    for (int i = 0; i < schedules.size(); ++i) {
        output(schedules[i]);
    }
}
bool istimesame(vector<int> t1,vector<int> t2){//����
    if(t1.size()==2 && t2.size()==2){
        if(t1[0]>t2[1] || t1[1]<t2[0]){
            return false;
        }
    }else if(t1.size()==4 && t2.size()==2){
        if(t1[3]<t2[0] || t1[0]>t2[1] ||(t1[1]<t2[0] && t1[2]>t2[1])){
            return false;
        }
    }else if(t1.size()==2 && t2.size()==4){
        if(t1[1]<t2[0] || t1[0]>t2[3] ||(t2[1]<t1[0] && t2[3]>t1[1])){
            return false;
        }
    }else if(t1.size()==4 && t2.size()==4){
        if(t1[3]<t2[0] || t1[0]>t2[3]){//?
            return false;
        }
        if((t1[0]>t2[1] && t1[3]<t2[2]) || (t2[0]>t1[1] && t2[3]<t1[2])){
            return false;
        }
        if((t1[1]<t2[0] && t2[1]<t1[2] && t1[3]<t2[2]) || (t2[1]<t1[0] && t1[1]<t2[2] && t2[3]<t1[2])){
            return false;
        }
    }
    return true;
}
bool isvalid(vector<lesson> schedule){//���ʱ����߿γ��Ƿ��ظ�������ɸѡ�����˳��ͬ��������ͬ�Ŀγ̱�
    for (int i = 0; i < schedule.size(); ++i) {
        for (int j = 0; j < schedule.size(); ++j) {
            if(i!=j && (istimesame(schedule[i].time,schedule[j].time)==true || schedule[i].name==schedule[j].name)){
                return false;
            }
        }
    }
    return true;
}
void create_schedules(vector<vector<lesson>>& schedules,vector<lesson>& schedule,vector<lesson> lessons,int n,int num){
    if(n==num){
        //output(schedule);
        schedules.push_back(schedule);
        return;
    }
    for (int i = 0; i < lessons.size(); ++i) {
        schedule.push_back(lessons[i]);
        if(isvalid(schedule)){
            create_schedules(schedules,schedule,lessons,n+1,num);
        }
        schedule.pop_back();
        if(i==lessons.size()-1){
            return;
        }
    }
}

bool issame(vector<lesson> lesson1,vector<lesson> lesson2){//������
    if(lesson1.size()!=lesson2.size()){
        return false;
    }
    for (int i = 0; i < lesson2.size(); ++i) {
        if(!istimesame(lesson1[i].time,lesson2[i].time) || lesson1[i].name!=lesson2[i].name){//�޸�
            return false;
        }
    }
    return true;

}
void bubblesort(vector<lesson>& lesson){
    for (int i = 0; i < lesson.size()-1; ++i) {
        for (int j = 0; j < lesson.size()-1-i; ++j) {
            if(lesson[j].time[0]>lesson[j+1].time[0]){
                swap(lesson[j+1],lesson[j]);
            }
        }
    }
}
void norepitition(vector<vector<lesson>>& schedules){
    for (int i = 0; i < schedules.size(); ++i) {
        bubblesort(schedules[i]);
    }
    bool finish=false;
    bool out= false;
    while(!finish){
        int index=-1;
        finish= true;
        out= false;
        for (int i = 0; i < schedules.size(); ++i) {
            for (int j = i+1; j < schedules.size(); ++j) {
                if(issame(schedules[i],schedules[j])){
                    finish=false;
                    index=j;
                    out=true;
                    break;
                }
            }
            if(out){
                break;
            }
        }
        if(index!=-1){
            schedules.erase(schedules.begin()+index);
        }
    }
}

ExMessage mssg = {0};



void text1(){
    settextstyle(160,0,"Times New Roman");
    settextcolor(WHITE);
    setbkmode(TRANSPARENT);
    outtextxy((1200-textwidth("Class Schedule"))/2,30,"Class Schedule");
}

bool inArea(int mx,int my,int x,int y,int w,int h){
    if(mx>x && mx<x+w && my>y && my<y+h){
        return true;
    }
    return false;
}

bool button(int x,int y,int w,int h,const char* text){

    fillroundrect(x,y,x+w,y+h,5,5);

    settextstyle(30,0,"Times New Roman");
    settextcolor(BLACK);

    int wtext = (w-textwidth(text))/2;
    int htext = (h-textheight(text))/2;
    outtextxy(x+wtext,y+htext,text);
    setfillcolor(RGB(195,195,195));
    if(inArea(mssg.x,mssg.y,x,y,w,h) && mssg.message == WM_LBUTTONDOWN){
        return true;
    }
    return false;
}



void basictable(int x,int y,int w,int h){
    setfillcolor(RGB(195,195,195));
    fillrectangle(x,y,x+w,y+h);

}


void fillcell(string text,int begin,int end){
    int day = begin/1440;
    int x = 100+day*200;
    int y = 200+(begin-day*1440)-480;
    int w = 200;
    int h = end-begin;

    int starthour = (begin - day*1440)/60;
    int endhour = (end - day*1440)/60;
    int startmin = (begin - day*1440)-starthour*60;
    int endmin = (end - day*1440)-endhour*60;

    string sh = to_string(starthour);
    string eh = to_string(endhour);
    string sm = to_string(startmin);
    string em = to_string(endmin);

    string start = sh + " : " + sm;
    string endd = eh + " : " + em;
    string time = start + " - " + endd;

    const char* t = text.c_str();
    const char* timechar = time.c_str();


    setfillcolor(RGB(35,122,43));
    fillrectangle(x,y,x+w,y+h);

    settextstyle(30,0,"Times New Roman");
    settextcolor(BLACK);

    int wtext = (w-textwidth(t))/2;
    int htext = (h-textheight(t))/2;
    int wtime = (w-textwidth(timechar))/2;
    int htime = (h-textheight(timechar))/2;
    outtextxy(x+wtext,y+htext-20,t);
    outtextxy(x+wtime,y+htime+20,timechar);
}

void drawtable(int i,vector<vector<lesson>> schedules){
    initgraph(1200,900);
    setbkcolor(RGB(38,95,163));
    cleardevice();
    setbkmode(TRANSPARENT);

    while(true){
        if(peekmessage(&mssg,EX_MOUSE)){

        }
        BeginBatchDraw();
        cleardevice();

        basictable(100,200,1000,600);


        for(int j = 0;j < schedules[i].size();j++){
            string classname = schedules[i][j].name;
            vector<int> Time;
            Time = schedules[i][j].time;
            if(Time.size() == 2){
                fillcell(classname,Time[0],Time[1]);
            }
            if(Time.size() == 4){
                fillcell(classname,Time[0],Time[1]);
                fillcell(classname,Time[2],Time[3]);
            }
        }
        setfillcolor(RGB(195,195,195));
        if(button(1050,830,100,50,"next")){
            i++;
        }


        text1();

        EndBatchDraw();
        mssg.message = 0;
    }
}

int i;

courseManage::courseManage(){
    vector<vector<lesson>> schedules;
    vector<lesson> lessons;
    vector<lesson> schedule;
    string name;
    string times;
    string part;
    int types=0;//�м��ֿγ�
    string all = chooseCourse::allCourse;//��ʱ��ʼ
    vector<string> messages;
    for (int i = 0; i < all.length(); i++) {
        if(all.substr(i,1)==" "){
            messages.push_back(part);
            part="";
            types++;
        }else{
            part+=all.substr(i,1);
        }
    }
    for (int i = 0; i < messages.size()/2; ++i) {
        if(messages[i]!="end"){
            lessons.push_back(lesson(messages[i*2],messages[i*2+1]));
        }else{
            break;
        }
    }//��ʱ����
    while(types>0 && schedules.size()==0){
        create_schedules(schedules,schedule,lessons,0,types);
        types--;
    }
    norepitition(schedules);
    outputall(schedules);

    i = 0;

    while (i <= schedules.size()) {
        drawtable(i,schedules);
    }

    getchar();
}

