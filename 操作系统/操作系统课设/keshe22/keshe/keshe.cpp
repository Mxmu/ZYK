#include<iostream>
using namespace std;

#define m 10
#define n 10
#define Q 1024
 struct free
 {
	 int ad;
     int len;
     char state;
 }fr[m];
       
 struct use
 {
	 int ad;
     int len;
     char state;
 }us[10];
 struct free0
 {
	 int ad;
     int len;
     char state;
 }f0[1];
/*
struct Job									
{int jno;									
 int jstart;									 
 int jlen;										 
}jt[10];									


struct
{ int fstart;
  int flen;
  char fstatus;
}ft[10];
*/
void creatf()//���з������ʼ��
{
    int i;
	for(i=0;i<m;i++)
     {
          fr[i].ad=0;
          fr[i].len=0;
          fr[i].state='M';
     }
 }

void disp()
{
	int i;
	cout<<'\n'<<"��ַ"<<'\t'<<"����"<<'\t'<<"״̬"<<'\n';
    for(i=0;i<m;i++)
    cout<<'\n'<<fr[i].ad<<'\t'<<fr[i].len<<'\t'<<fr[i].state<<endl;
} 

void sort()
{
	int i,q,j;
    i=0;
    q=0;

     
    if(fr[0].ad!=0)
    { 
         do
	     {
             if(f0[0].ad>fr[i].ad)
             i=i+1;
             else q=1;
    	 }while(fr[i].state!='M'&&q==0);
   
        for(j=m-1;j>i;j--)
 	    {
             fr[j].ad=fr[j-1].ad;
             fr[j].len=fr[j-1].len;
             fr[j].state=fr[j-1].state;
    	}
        fr[i].ad=f0[0].ad;
        fr[i].len=f0[0].len;
        fr[i].state=f0[0].state;
   }
   if(fr[0].ad==0)
    {
        fr[0].ad=f0[0].ad;
        fr[0].len=f0[0].len;
        fr[0].state=f0[0].state;
    }
}

void sort1()
{
	int i;
    i=0;
    while(fr[i].state!='M')
	{i++;}
    if(fr[i+1].state!='M')
	{
		do
		{
	    	fr[i].ad=fr[i+1].ad;
            fr[i].len=fr[i+1].len;
            fr[i].state=fr[i+1].state;
            i++;
		}while(fr[i+1].state!='M');
		fr[i].ad=0;
		fr[i].len=0;
		fr[i].state='M';
	}
 
}

void insertu(int i)
{
	int j,p;
    p=0;
    cout<<'\n'<<"�������"<<i<<"����ҵ�ĳ��ȣ�\n";
    cin>>us[i].len;
    us[i].ad=0;
    us[i].state='U';
    j=0;
    p=0;
    if(fr[0].ad==0)
    cout<<"\n ���п������Ѿ�ȫ��������ϣ�\n";
    while(fr[j].state!='M'&&p==0)
	{
         if( us[i].len<fr[j].len)
	     {
             us[i].ad=fr[j].ad;
             fr[j].ad=us[i].len+fr[j].ad;             
             fr[j].len=fr[j].len-us[i].len;
             p=1;
             break;
	     }
         if(us[i].len==fr[j].len)
         {
             us[i].ad=fr[j].ad;
             fr[j].ad=0;
             fr[j].len=0;
             fr[j].state='M';
             sort1();
             p=1;
             break;
	     }
        j++;
    }
       if(p==0)
       {
            us[i].state='N';
            cout<<"\nû���ʵ��Ŀռ���Բ��룡\n";
        }
       if(p!=0)
       {
           cout<<"\n��"<<i<<"����ҵ����ռ�󣬿��б�Ϊ��\n";
           disp();
       }
}

void over()
{ 
     int d,i,j,p,k;
     p=0;
     i=0; 
     cout<<"\n ����Ҫ�����ڼ�����ҵ��\n";
     cin>>d;
     cout<<"\n Ҫ������ҵ����ϢΪ��\n";
     cout<<"\n��ַ"<<'\t'<<"����"<<'\t'<<"״̬\n";
     cout<<"\n"<<us[d].ad<<'\t'<<us[d].len<<'\t'<<us[d].state;
     if(us[d].state=='N')//���Ҫ������ҵ��״̬Ϊ'N'��˵������ҵû�б�����ռ�
     cout<<"\n ����ҵû�з����ڴ棡\n";
     if(us[d].state=='Y')//���Ҫ������ҵ��״̬Ϊ'Y'��˵������ҵ�Ѿ�������
     cout<<"\n ����ҵ�Ѿ����� ��\n";
     if(us[d].state=='U')//���Ҫ������ҵ��״̬Ϊ'U'��˵������ҵû�б�����
     { 
      while(fr[i].state!='M')
      {
         if(us[d].ad==fr[i].ad+fr[i].len)
	     //�����������ҵ����ʼ��ַ��һ�����з����Ľ�����ַ���ڣ���ϲ�����
         {
             fr[i].len=fr[i].len+us[d].len;
             if(fr[i].ad+fr[i].len==fr[i+1].ad)
             //�ϲ���֮��Ŀ��з����Ľ�����ַ�����ڵĿ��з�������ʼ��ַҲ������������ϲ�
             {
                 fr[i].len=fr[i].len+fr[i+1].len;
                 for(k=i+1;k<m-1;k++)
                 {
                     fr[k].ad=fr[k+1].ad;
                     fr[k].len=fr[k+1].len;
                     fr[k].state=fr[k+1].state;
                 }
                 fr[m-1].ad=0;
                 fr[m-1].len=0;
                 fr[m-1].state='M';
             }
             us[d].state='Y';//�޸��Ѿ�������ҵ����Ϣ
             p=1;
             break;
         }
         if(us[d].ad+us[d].len==fr[i].ad)
         //�����������ҵ�Ľ�����ַ��һ�����з�������ʼ��ַ���ڣ���ϲ�����
         {
             fr[i].len=us[d].len+fr[i].len;
             fr[i].ad=us[d].ad;
             fr[i].state='F';
             p=1;
             us[d].state='Y';
           break;
         }

         if(us[d].ad<fr[i].ad)
         //���������ҵ������������������ҽ����������з���֮�䣬����ַ�Ĵ�С����
         {
             for(j=m-1;j>i;j--)
             {
                 fr[j].ad=fr[j-1].ad;
                 fr[j].len=fr[j-1].len;
                 fr[j].state=fr[j-1].state;
             }
             fr[i].ad=us[d].ad;
             fr[i].len=us[d].len;
             fr[i].state='F';	
             us[d].state='Y'; 
             break;            
         }
         i++;
     }
     if(p==0)//���������ҵ���������������������ַ�������뵽���з������ĩβ
     {
         fr[i].ad=us[d].ad;
         fr[i].len=us[d].len;
         fr[i].state='F';
         us[d].state='Y';
     }
     disp();
    }
}



int main()
{
    int i,j,k,p;
	i=1;
	k=0;
	p=1;
    cout<<"\n*----------------------------------------------------------*\n";
    cout<<"|*****************���洢��ռ�ķ���ͻ���ģ��***************|\n";
    cout<<"*----------------------------------------------------------*\n\n";
    creatf();
    cout<<"\n ������Ŀǰ���з��������Ϣ��\n";
    while(p!=0)
    {
         cout<<"\n ��������з�����ĳһ�е���ַ�ͳ���\n";
         cin>>f0[0].ad>>f0[0].len;
         f0[0].state='F';
         sort();
        // k++;
         cout<<"\n ������ٽ������룬������0\n";
         cin>>p;
     }
    cout<<"\n ������ҵ֮ǰ���з��������Ϣ���£�\n";
    disp(); 
    for(;;)
    { 
        cout<<"=================�˵�===================\n";
        cout<<"1��Ϊ��ҵ����ռ䣻\n";
        cout<<"2��������ҵ��\n";
        cout<<"3���˳�����\n";
        cout<<"========================================\n";
        cout<<"�������ѡ��\n"; 
        cin>>j;
        switch(j)
        {
            case 1:insertu(i);//Ϊ��ҵ����ռ�
				   i++;
                   break;
            case 2:over();//��ҵ�Ļ���
                   break;
            case 3:exit(0);
         }
     }
    return 0;

}
