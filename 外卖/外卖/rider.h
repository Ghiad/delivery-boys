#ifndef RIDER_H
#define  RIDER_H

#include<stdio.h>
#include<stdlib.h>
#define ridernum 10
#define menunum 20
	typedef struct menu{
		int x1;//骑手接餐地址横坐标
		int y1;//骑手接餐地址纵坐标
		int x2;//骑手送餐地址横坐标
		int y2;//骑手送餐地址纵坐标	
		int endtime;//这一单截止的时间 
		int *p;//指向骑手的指针
		struct menu *nextmenu;
	}Menu;
	typedef struct rider{
		int exist;//判断该骑手存在 
		int x;//骑手当前位置横坐标
		int y;//骑手当前位置纵坐标
		int t1;//骑手这一单截止时间
		int receive;//骑手的接单数
		int achieve;//骑手的完成数 
		int overtime;//骑手超时数 
		Menu *nextmenuptr; //骑手订单链表
	}Rider;
	
	//骑手行驶路径的算法函数
	void allocatemenu(Menu,Rider []); //分配订单函数 
	void performance(Rider []);//打印每位骑手的接单数、完成数、超时数
	void buyrider(Rider [],int *money);//买骑手 
	Rider* creatmenulist(int,Rider []);
	void addmenulist();
	
	extern Menu menu[menunum];
	extern Rider rid[ridernum];
#endif 
