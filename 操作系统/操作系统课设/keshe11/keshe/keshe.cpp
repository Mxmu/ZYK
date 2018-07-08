#include<iostream>
#include <cstdlib>
using namespace std;


struct PCB{
	char name[5];  //进程名
	int need_time;//需要时间
	int privilege;//优先级
	char state;  //状态
	PCB *next;   //指针
};


void pcb(struct PCB *head, PCB *p,int N)
{
	PCB *s;
	int i;
	cout<<"请输入进程的名字、优先级、需要时间"<<endl;
	for (i = 0; i < N; i++)
	{   
		s = head;
		cout<<"请输入第"<<i+1<<"个进程的信息:"<<endl;
		cin >> p->name >> p->privilege >> p->need_time;
		if (p->need_time > 0)
		{
			p->state = 'R';
			while (s->next)
			{
				if (p->privilege > s->next->privilege)
					break;
				s = s->next;
			}
			p->next = s->next;
			s->next = p;
		}
		else {
			p->state = 'E';
			//cout << "该进程已运行结束,无法加入" << endl;
		} 
	}
}

void print(struct PCB *p, int N)
{
	int i;
	cout<<"进程名  优先级 运行时间 当前状态"<<endl;
	cout<<"*****************************************"<<endl;
	//依次显示每个进程的名、优先数、要求运行时间和状态
	for (i = 0; i < N; i++)
	{
		cout << p->name << '\t' << p->privilege << '\t' << p->need_time << '\t' << p->state;
	}
}


int run(PCB *head, PCB *p, int N)
{
	PCB *s;
	s = head;
	p = s->next;
	p->privilege--;
	p->need_time--;
	cout << "此次运行的进程是:" <<endl;
	cout << p->name << "需要时间" << p->need_time << "优先数" << p->privilege;
	if (p->need_time <= 0) 
	{ 
		p->state = 'E';
	}
	else
	{
		while (s->next)
		{
			if (p->privilege > s->next->privilege)
				break;
			s = s->next;
		}
		p->next = s->next;
		s->next = p;
	}
	print(p, N);
	return 0;
}
int main()
{
	int N;
	cout << "请输入进程的数量:" << endl;
	cin >> N;
	PCB *Head = new PCB;
	struct PCB *p = new struct PCB[N];
	pcb(Head,p, N);
	while(Head->next)
	{run(Head,p, N);}
	//delete[] p;
	system("pause");
	return 0;
}
