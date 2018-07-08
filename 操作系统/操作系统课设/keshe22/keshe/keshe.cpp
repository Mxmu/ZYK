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
void creatf()//空闲分区表初始化
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
	cout<<'\n'<<"起址"<<'\t'<<"长度"<<'\t'<<"状态"<<'\n';
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
    cout<<'\n'<<"请输入第"<<i<<"个作业的长度：\n";
    cin>>us[i].len;
    us[i].ad=0;
    us[i].state='U';
    j=0;
    p=0;
    if(fr[0].ad==0)
    cout<<"\n 所有空闲区已经全部分配完毕！\n";
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
            cout<<"\n没有适当的空间可以插入！\n";
        }
       if(p!=0)
       {
           cout<<"\n第"<<i<<"个作业分配空间后，空闲表为：\n";
           disp();
       }
}

void over()
{ 
     int d,i,j,p,k;
     p=0;
     i=0; 
     cout<<"\n 输入要结束第几个作业：\n";
     cin>>d;
     cout<<"\n 要结束作业的信息为：\n";
     cout<<"\n起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
     cout<<"\n"<<us[d].ad<<'\t'<<us[d].len<<'\t'<<us[d].state;
     if(us[d].state=='N')//如果要结束作业的状态为'N'，说明此作业没有被分配空间
     cout<<"\n 此作业没有分配内存！\n";
     if(us[d].state=='Y')//如果要结束作业的状态为'Y'，说明此作业已经被结束
     cout<<"\n 此作业已经结束 ！\n";
     if(us[d].state=='U')//如果要结束作业的状态为'U'，说明此作业没有被结束
     { 
      while(fr[i].state!='M')
      {
         if(us[d].ad==fr[i].ad+fr[i].len)
	     //如果被结束作业的起始地址和一个空闲分区的结束地址相邻，则合并两者
         {
             fr[i].len=fr[i].len+us[d].len;
             if(fr[i].ad+fr[i].len==fr[i+1].ad)
             //合并完之后的空闲分区的结束地址和相邻的空闲分区的起始地址也相连，则继续合并
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
             us[d].state='Y';//修改已经结束作业的信息
             p=1;
             break;
         }
         if(us[d].ad+us[d].len==fr[i].ad)
         //如果被结束作业的结束地址和一个空闲分区的起始地址相邻，则合并两者
         {
             fr[i].len=us[d].len+fr[i].len;
             fr[i].ad=us[d].ad;
             fr[i].state='F';
             p=1;
             us[d].state='Y';
           break;
         }

         if(us[d].ad<fr[i].ad)
         //如果结束作业不是以上两种情况，且介于两个空闲分区之间，则按起址的大小插入
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
     if(p==0)//如果结束作业不是以上三种情况，且其址最大，则插入到空闲分区表的末尾
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
    cout<<"|*****************主存储存空间的分配和回收模拟***************|\n";
    cout<<"*----------------------------------------------------------*\n\n";
    creatf();
    cout<<"\n 请输入目前空闲分区表的信息：\n";
    while(p!=0)
    {
         cout<<"\n 请输入空闲分区表某一行的起址和长度\n";
         cin>>f0[0].ad>>f0[0].len;
         f0[0].state='F';
         sort();
        // k++;
         cout<<"\n 如果不再进行输入，则输入0\n";
         cin>>p;
     }
    cout<<"\n 插入作业之前空闲分区表的信息如下：\n";
    disp(); 
    for(;;)
    { 
        cout<<"=================菜单===================\n";
        cout<<"1：为作业分配空间；\n";
        cout<<"2：结束作业；\n";
        cout<<"3：退出程序；\n";
        cout<<"========================================\n";
        cout<<"输入你的选择：\n"; 
        cin>>j;
        switch(j)
        {
            case 1:insertu(i);//为作业分配空间
				   i++;
                   break;
            case 2:over();//作业的回收
                   break;
            case 3:exit(0);
         }
     }
    return 0;

}
