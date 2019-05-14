#ifndef RIDER_H
#define RIDER_H
#include "tools.h"
#include "point.h"
#include "menu.h"
#include "list.h"

class Rider{
  private:
    int exist;
    int x,y;
    Point A(x,y);
    Menu* waitlist;
    List Path;
    int receive;//���ֵĽӵ���
    int achieve;//���ֵ������
    int overtime;//���ֳ�ʱ��

    //�˶���Χ;

  public:
    Point A(int x,int y):x(x),y(y);
    Rider() {}
    Rider(int x,int y):x(x),y(y);
    void CalculatePath(Menu* newlist);
    int Manhatten(Point x,Point y);
    void GeneratePath(Point A,int id);
    void PrintState();
    int AllThingsDone();//�����������һ����ʱ��
    ~Rider() {}
    friend class Menu;
}

#endif //RIDER_H
