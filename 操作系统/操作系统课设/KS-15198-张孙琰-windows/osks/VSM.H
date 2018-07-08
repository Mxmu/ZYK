#include<iostream>
#include<windows.h>
#include<string>
#include<sstream>
#include<stdio.h>
#include<vector>
#include<time.h>
using namespace std;

const int MAXCUS=20;                                     //最多创建的顾客数目
const int CUSINMAR=15;                                   //最多进入超市的顾客数目
const int MAXQUEUE=5;                                    //各种队列的最大长度(结账队列,买肉队列,进入超市队列)
const int GOODS=5;                                       //随机购物时的货物种类数
const int MAXCOUNTER=3;                                  //结账柜台的个数
const int PRICE[GOODS+1]={5,100,12,30,500,7};            //0项代表熟食的价格,1~5项代表其他五种商品的价格
const int MAXQUANTITY[GOODS+1]={5,2,10,5,1,7};           //0项代表熟食的数量，1~5项代表其他五种商品的数量
const int MILLIONS=1000;                                 //专用毫秒

//线程类、顾客类和超市管理员类的父类
class MyThread
{
protected:
	HANDLE myhandle;
	string myname;
	static DWORD WINAPI ThreadProc(LPVOID IpParam);
public:
	MyThread(string name="");
	virtual~MyThread();
	void start();
	virtual void run()=0;
	virtual void WaitForCompletion();
	int get_random();
};

class SuperMarket:public MyThread
{   //超市线程主体
public:
	void output(string os);
	SuperMarket();
	virtual void run();
	~SuperMarket();
};

class Customer:public MyThread
{
protected:
	//ThreadNumMutex:
	//CounterMutex[]:
	//AccessCounter:
	//CookMutex:
	//AccessCookCounter:
	static HANDLE ThreadNumMutex,CounterMutex [MAXCOUNTER], AccessCounter,CookMutexm,AccessCookCounter;
	//counter[]:
	static int counter[MAXCOUNTER];
	//cookcounter:
	static int cookcounter;
	int countertime;
	int cost;
	//初始化
	void static setCustomerNumber();
	//初始化
	void static setCounter();
	//初始化
	void static setCookMutex();
	//处理顾客结账排队的函数
	void handlecouter();
	/*
	
	*/
	void shopping();
public:
	Customer(int ID);
	void static initialize();                        //总初始化操作
	virtual void run();                              //顾客线程主体
	//关闭
	//关闭
	static void closehandle();
};


#endif