
#include<stdio.h>
int temp=0;//����һ��ȫ�ֱ��������������ܴ�����
typedef struct _BiTNode//���� �� �Ľṹ�� 
{
	int address;//�׵�ַ 
	int length;//���������� 
	bool state;//����״̬ ��1����ʾ�ѷ��䣬 ��0����ʾδ���� 
	int homework; //��ҵ�� 
	struct _BiTNode *lchild;//ָ�����ӵ�ָ�� 
	struct _BiTNode *rchild;//�Һ��� 
}BiTNode,*pBiTree;
void Init_BiTree(pBiTree l)
{		
	l->address = 5;
	l->length = 507;
	l->state = 0;	
	l->homework=NULL;
	l->lchild = NULL;
	l->rchild = NULL;
	printf("��ʼ����ɣ�\n");
} 
void Print(pBiTree p)
{	
	printf("\n\t\t%d\t%d\t",p->address,p->length);
	if(p->state==1)
		printf("Busy  \t");
	else
		printf("Free  \t");
	if(p->homework!=0)
		printf("%d\n",p->homework);
	else 
		printf("\n"); 
}
//�������  
void PreOrder(pBiTree p)  
{  	
	if(p != NULL)  
    {         
        if(!p->lchild&&!p->rchild)      
        	Print(p);  //����ý��
	   	PreOrder(p->lchild);  //����������   
        PreOrder(p->rchild); //����������  
    }  
}  
void Insert_PreOrder(pBiTree p,int length,int homework)//��������ҵ  
{  	
	if(p != NULL)  
    {     
		if((p->state==0)&&(length<p->length)&&(!p->lchild)&&(!p->rchild)&&temp==0)//�жϽڵ��Ƿ������Һ��ӣ��Ƿ�С�ڿ��������ȣ��Ƿ�״̬Ϊ0����ʾ��������ҵ���У� 
	   	{  
			pBiTree  x1 =new BiTNode;//���в��룬��̬���������ռ� x1,x2 
			pBiTree  x2 =new BiTNode;
			x1->homework=homework;//x1Ϊ��ҵ 
			x2->homework=NULL;//x2Ϊʣ��Ŀ����� 
		   	x1->address=p->address;//��ԭ���������׵�ַ����ҵ���׵�ַ 
		   	x1->state=1;//��ҵ��״̬��Ϊ1 
		   	x1->length=length;//��ҵ�ĳ���Ϊ����ĳ��� 
		   	x2->address=x1->address+length;//�¿��������׵�ַΪ x1�׵�ַ��x1����֮�� 
		   	x2->length=p->length-x1->length;
		   	p->lchild=x1;
		   	p->rchild=x2;
		   	x2->state=0;
		   	x1->lchild=NULL;
			x1->rchild=NULL;
			x2->rchild=NULL;
			x2->lchild=NULL; 
			temp=1;
		}   	
		else
		{	
			Insert_PreOrder(p->lchild,length,homework);  //����������   
        	Insert_PreOrder(p->rchild,length,homework); //����������  
    	} 
	}  
} 
void Delect_PreOrder(pBiTree p,int homework) //�����޸ģ���״̬�޸�Ϊ0����Ϊ������ 
{  	
	if(p != NULL)  
    {         
        if(p->homework==homework)//����ѯ����ҵ����ͬ����ҵ�������޸� 
        {
			p->homework=NULL;//����ҵ���޸�Ϊ�� 
			p->state=0;//����ҵ��״̬�޸�Ϊ���� 
		}	
	Delect_PreOrder(p->lchild,homework);  //����������   
    Delect_PreOrder(p->rchild,homework); //����������  
    }  
}  
int main()
{	
	BiTNode l;
	Init_BiTree(&l);
	//��ʼ�� 
	printf("\n   ��ʼ��:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
 
	PreOrder(&l);
	//������ҵ1 
	temp=0;
	Insert_PreOrder(&l,300,1);
	printf("\n������ҵ1:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l);  
	//������ҵ2 
	temp=0;
	Insert_PreOrder(&l,100,2);
	printf("\n������ҵ2:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l);
	//�ͷ���ҵ1 
 	Delect_PreOrder(&l,1); 
    printf("\n�ͷ���ҵ1:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l); 	
	//������ҵ3 
	temp=0;
	Insert_PreOrder(&l,150,3);
	printf("\n������ҵ3:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l);
	//������ҵ4 
	temp=0;
	Insert_PreOrder(&l,30,4);
	printf("\n������ҵ4:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l);
	//������ҵ5 
	temp=0;
	Insert_PreOrder(&l,40,5);
	printf("\n������ҵ5:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l);
	//������ҵ6 
	temp=0;
	Insert_PreOrder(&l,60,6);
	printf("\n������ҵ6:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l);
	//�ͷ���ҵ4 
	Delect_PreOrder(&l,4); 
    printf("\n�ͷ���ҵ4:\t�׵�ַ\t����\t״̬\t��ҵ��\n");
	PreOrder(&l); 	
	return 0;
}