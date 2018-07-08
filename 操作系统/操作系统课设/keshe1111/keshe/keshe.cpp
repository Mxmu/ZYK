#include<iostream>
#include <cstdlib>
using namespace std;


struct PCB {
	char name[5];  //������
	int need_time;//��Ҫʱ��
	int privilege;//���ȼ�
	char state;  //״̬
	PCB *next;   //ָ��

};

struct NODE {
	PCB data;
	NODE *next;
};

void Input(PCB *p, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "�����" << i + 1 << "�����̵Ľ�����" << ' ' << "��Ҫʱ��" << ' ' << "������" << endl;
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
	//maxΪ�������������ʼ��Ϊ-10
	int max = -10;
	int i, key;
	for (i = 0; i < N; i++)
	{
		//r��ʾ��������
	//�Ӿ���������ѡȡ���������Ľ���
			if (max < p[i].privilege && p[i].state == 'R')
			{
				//max���ÿ��ѭ���е����������
				max = p[i].privilege;
				key = i;
			
		}
	}
	//��������������Ľ��������������
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
	cout<<"\n������  ��Ҫʱ�� ������ ��ǰ״̬\n";
	cout<<"*****************************************\n";
	//������ʾÿ�����̵�������������Ҫ������ʱ���״̬
	for (i = 0; i < N; i++)
	{
		cout<<p[i].name<<'\t'<<p[i].need_time<<'\t'<< p[i].privilege<<'\t'<< p[i].state<<endl;
		
	}
int k = MAX(p, N);
		cout << "�¸�Ҫ���еĽ���Ϊ:" << p[k].name << endl;
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
	cout << "��������̵�����:" << endl;
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
