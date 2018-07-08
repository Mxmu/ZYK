#include<iostream>
#include <cstdlib>
using namespace std;


struct PCB{
	char name[5];  //������
	int need_time;//��Ҫʱ��
	int privilege;//���ȼ�
	char state;  //״̬
	PCB *next;   //ָ��
};


void pcb(struct PCB *head, PCB *p,int N)
{
	PCB *s;
	int i;
	cout<<"��������̵����֡����ȼ�����Ҫʱ��"<<endl;
	for (i = 0; i < N; i++)
	{   
		s = head;
		cout<<"�������"<<i+1<<"�����̵���Ϣ:"<<endl;
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
			//cout << "�ý��������н���,�޷�����" << endl;
		} 
	}
}

void print(struct PCB *p, int N)
{
	int i;
	cout<<"������  ���ȼ� ����ʱ�� ��ǰ״̬"<<endl;
	cout<<"*****************************************"<<endl;
	//������ʾÿ�����̵�������������Ҫ������ʱ���״̬
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
	cout << "�˴����еĽ�����:" <<endl;
	cout << p->name << "��Ҫʱ��" << p->need_time << "������" << p->privilege;
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
	cout << "��������̵�����:" << endl;
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
