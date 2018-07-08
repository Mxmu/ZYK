#include<iostream>
#include <cstdlib>
using namespace std;


struct PCB {
	char name[5];  //进程名
	int need_time;//需要时间
	int privilege;//优先级
	char state;  //状态
	PCB *next;   //指针

};

struct NODE {
	PCB data;
	NODE *next;
};

void Input(PCB *p, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "输入第" << i + 1 << "个进程的进程名" << ' ' << "需要时间" << ' ' << "优先数" << endl;
		cin >> p[i].name >> p[i].need_time >> p[i].privilege;
		if (p[i].need_time <= 0)
		{
			p[i].state = 'E';
		}
		else
		{
			p[i].state = 'R';
		}
	
	}
}
int MAX(PCB *p, int N)
{
	//max为最大优先数，初始化为-10
	int max = -10;
	int i, key;
	for (i = 0; i < N; i++)
	{
		//r表示正在运行
	//从就绪进程中选取优先数最大的进程
			if (max < p[i].privilege && p[i].state == 'R')
			{
				//max存放每次循环中的最大优先数
				max = p[i].privilege;
				key = i;
			
		}
	}
	//具有最大优先数的进程若已运行完毕
	if (p[key].state == 'E')
		return -1;
	else
		return key;
}
int sum(PCB *p, int N)
{
	int sum=0;
	for (int i = 0; i < N; i++)
	{
		sum += p[i].need_time;
	}
	return sum;
}
void run(PCB *p)
{
	p[0].need_time--;
	p[0].privilege--;
	if (p[0].need_time <= 0)
	{
		p[0].state = 'E';
	}
	else
	{
		p[0].state = 'R';
	}
}
void print(PCB *p, int N)
{
	int i;
	//NODE *p = *hpt;
	cout<<"\n进程名  需要时间 优先数 当前状态\n";
	cout<<"*****************************************\n";
	//依次显示每个进程的名、优先数、要求运行时间和状态
	for (i = 0; i < N; i++)
	{
		cout<<p[i].name<<'\t'<<p[i].need_time<<'\t'<< p[i].privilege<<'\t'<< p[i].state<<endl;
		
	}
int k = MAX(p, N);
		cout << "下个要运行的进程为:" << p[k].name << endl;
}

void Bubblesort(PCB *p, int N)
{
	PCB t;
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			if (p[j].privilege < p[j + 1].privilege)
			{
				t = p[j]; p[j] = p[j + 1]; p[j + 1] = t;
			}
		}
	}
}

int main()
{
	int N; 
	cout << "请输入进程的数量:" << endl;
	cin >> N;
	PCB *p = new struct PCB[N];
	Input(p, N);
	Bubblesort(p, N);
	print(p, N);
	int s=sum(p, N);
	for (int i = 0; i <s ; i++)
	{
		Bubblesort(p, N);
		run(p);
		print(p, N);
	}
	system("pause");
	return 0;
}
