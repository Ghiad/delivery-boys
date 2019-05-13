#include "rider.h"
#include "list.h"
#include "menu.h"
#include "controller.h"
#define INF 0x3f3f3f3f

Rider::int Manhatten(Point A,Point B)
{
    return  abs(A.x-B.x)+abs(A.y-B.y);
}

void Rider::GeneratePath(Point Now,int id ��int T)
{
//T ��Ҫ��� 
    if(!menu[id].get)
     {
            int disx = abs(Now.x-menu[id].x1);
                int disy = abs(Now.y-menu[id].y1);
                int Length = disx + disy;
                for(int i = 0 ;i<=Length;i++)//����·��
                    {
                        //���ϻ�������
                        for(int dx=0;dx<=disx;dx++)
                            {
                                if(Now.x-menu[id].x1<0)
                                    ListNode* temp = new ListNode(x+dx,y,i+T);
                                else if(Now.x-menu[id].x1>0)
                                    ListNode* temp = new ListNode(x+dx,y,i+T);
                                Path->InsertAsl(temp);
                            }
                        //����������
                        for(int dy=1;dy<=disy;dy++)
                            {
                                if(Now.y-menu[id].y1<0)
                                    ListNode* temp = new ListNode(x+disx,y+dy,i+T);
                                else if(Now.y-menu[id].y1>0)
                                    ListNode* temp = new ListNode(x+disx,y-dy,i+T);
                                Path->InsertAsl(temp);
                            }
                          
                    } 
     }
     else {
            int disx = abs(Now.x-menu[id].x2);
                int disy = abs(Now.y-menu[id].y2);
                int Length = disx + disy;
                for(int i = 0 ;i<=Length;i++)//����·��
                    {
                       for(int dx=0;dx<=disx;dx++)
                            {
                                if(Now.x-menu[id].x1<0)
                                    ListNode* temp = new ListNode(x+dx,y,i+T);
                                else if(Now.x-menu[id].x1>0)
                                    ListNode* temp = new ListNode(x+dx,y,i+T);
                                Path->InsertAsl(temp);
                            }
                        //����������
                        for(int dy=1;dy<=disy;dy++)
                            {
                                if(Now.y-menu[id].y1<0)
                                    ListNode* temp = new ListNode(x+disx,y+dy,i+T);
                                else if(Now.y-menu[id].y1>0)
                                    ListNode* temp = new ListNode(x+disx,y-dy,i+T);
                                Path->InsertAsl(temp);
                            }
                    } 
     }
}


Rider::void CalculatePath(Menu* newlist){
    // ��newlist �ӵ�waitlistĩβ
    int Nowx = this->x;
    int Nowy = this->y;
    Point* ts = new Point(Nowx,Nowy);
    Menu* temp = waitlist->next;
    int cnt=0;
    while(temp!=tailer){
        cnt++;
        temp = temp->next;
    }
    int T = systemclock;
    if(cnt==1){  
        //ȡ��menu[0]
        //����õ�δ��ȡ
                //�͹ݵ�����menu[0].x1,menu[0].y1;
            //�Ͳ͵�ַ������ menu[0].x2,menu[0].y2;
            GeneratePath(ts,0��T); 

    }// �������һ������ȷ��֮�� ������Ķ������Ѿ���������ˣ����ǲ�һ�������Ѿ�ȡ���˲ͣ�������Ҫ��һ���Ѿ�ȡ���͵Ķ��� ,Ҳ����˵����Ҫ��������û�е����ĵ�ʹ��ʱ����̲���ÿ���㰴ʱ����
    else if(cnt >1){
        //menu ����ǵ���Ŀǰ��δ���͵��Ķ���
        //����֪��Ŀǰ����Щ���������Ѿ�ȡ������ ������m �� ��ô 2*n-m��Ϊʣ�µĵ��� ���� n-m�������͹� ֻ���ȵ�����n-m���� ���ܵ����Ӧ��Ŀ�ĵ�
        //����list[]�����
        for(int i =0 ;i<=cnt;i++)
            {
                //�����пɴ�ĵ� ����Сֵ Ȼ�����Path���� ,������
                int minid=0;
                int mind=INF;
                for(int i=0;i<cnt;i++)
                    {
                        if(menu[i].get&&!menu[i].reach)//�����Ѿ�ȡ���͵Ķ���
                            {
                                if(mind<Manhatten(ts,(Point)(menu[i].x2,menu[i].y2)))
                                    minid = i;
                                mind=Manhatten(ts,(Point)(menu[i].x2,menu[i].y2));
                            }
                        else if(!menu[i].get){//����δȡ���Ķ���
                                if(mind<Manhatten(ts,(Point)(menu[i].x1,menu[i].y1)))
                                    minid = i;
                               mind = min(mind,Manhatten(ts,(Point)(menu[i].x1,menu[i].y1)));      
                        }
                    }
                GeneratePath(ts,minid,T);
                if(menu[minid].get)
                    {
                        T += Manhatten(ts,(Point)(menu[minid].x2,menu[minid].y2));
                        ts = (Point)(menu[minid].x2,menu[minid].y2);
                        menu[minid].reach=1;
                    }
                else 
                    {
                        T += Manhatten(ts,(Point)(menu[minid].x1,menu[minid].y1));
                        ts = (Point)(menu[minid].x1,menu[minid].y1);
                        menu[minid].get=1;
                    }
                   
            }
    }
}

int Rider::AllThingsDone(){
    int total = systemclock ;
    ListNode* temp = header->next;
    while(temp!=tailer){
        total++;
        temp = temp->next;
    }
    return total;
}

//����ʱ�䲻���Ķ��� ���ܰ���������������.
