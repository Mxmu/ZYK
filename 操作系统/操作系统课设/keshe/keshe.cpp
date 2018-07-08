#include <stdio.h>
#include <stdlib.h>


typedef struct{
	char name[5];  //������
	int need_time;//��Ҫʱ��
	int privilege;//���ȼ�
	char state;  //״̬
	}NODE;

typedef struct node{
	NODE data;
	struct node *link;
	}LNODE;

/*void delay(int i)  //�ӳ�delay
{
	int x,y;

	while(i--)
	{
		x=0 ;
		while(x < 10000)
		{
			y = 0;
			while(y < 40000) y++;
			x++ ;
		}
	}
}
*/
void len_queue(LNODE **hpt, NODE x)
{
	LNODE *q,*r,*p;
	q = *hpt;
	r = *hpt;

	p = (LNODE *)malloc(sizeof(LNODE));  //malloc�ڴ����
	p->data = x;
	p->link = NULL;
	
	if(*hpt == NULL) *hpt = p;
	else 
	{
		while(q!=NULL && (p->data).privilege < (q->data).privilege)
		{
			r = q;
			q = q->link;
		}

		if(q == NULL) 
			r->link = p;
			
		else if(r == q)
					{	p->link = *hpt;
					*hpt = p;
				}else 
				{
					r->link = p;
					p->link = q;
				}
	}
}

void lde_queue(LNODE **hpt, NODE *cp)
{
	LNODE *p = *hpt;
	*cp = (*hpt)->data;
	*hpt = (*hpt)->link;
	free(p);
	printf("��Ҫ���еĽ�����:%s\n",cp->name);
	
}

void output(LNODE **hpt)
{
	LNODE *p = *hpt;
	printf("������\t��Ҫ��ʱ��\t������\t״̬\n");
	do
	{
		printf("%s \t %d \t\t %d \t\t %c \n",
			(p->data).name,(p->data).need_time,(p->data).privilege,(p->data).state);
		p = p->link;
	}while(p!= NULL);
//	delay(1);
}

int main()
{
	LNODE *head = NULL;
    NODE curr,temp;

	//printf("����ʱ����4��\n");
	printf("������\n");
	printf("�����Ҫ��ʱ��Ϊ0���������\n");
	printf("������\t��Ҫ��ʱ��\t������\n");
	while(1)
	{
	    scanf("%s %d %d", temp.name,&temp.need_time,&temp.privilege); 
        if(temp.need_time == 0)
			break;
		temp.state = 'R';
		len_queue(&head,temp);
	}
 
	while(head != NULL)
	{
		output(&head);
		lde_queue(&head,&curr);
		curr.need_time-- ;
		curr.privilege-- ;
		if(curr.need_time != 0) 
		len_queue(&head,curr);
	}
	return 0;
}
 
