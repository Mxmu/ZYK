#include<iostream>
using namespace std;
struct Job{
	int jno;
	int jstart;
	int jlen;
	}jt[10];

struct fspace{
	int fstart;
	int flen;
	char fstatus;
	}ft[10];




void printmenu()
{
//	clrscr();
	cout<<"========================"<<endl;
//	gotoxy(26,2);
	cout<<"主存储器空间的分配与回收\n";
		
//	gotoxy(30,2);
	cout<<"1. 初始化\n";
	
	//gotoxy(30,1);
	cout<<"2. 内存分配\n";
	
	//gotoxy(30,1);
	cout<<"3. 后退\n";

//	gotoxy(30,1);
	cout<<"4. 离开\n";

//	gotoxy(30,1);
	cout<<"5. 错误信息\n";
//	gotoxy(0,10);
}

void init()
{
	int i = 0;
	struct Job tempj;
	struct fspace tempf;
	
	cout<<"请输入作业号"<<'\t'<<"起址"<<'\t'<<"长度"<<endl;
	i = 0;
	cin>>tempj.jno>>tempj.jstart>>tempj.jlen;
	while(tempj.jno != 0)
	{	
		while(i < 10 && jt[i].jno != 0)i++;
		if(i < 10)
			jt[i] = tempj ;
		else 
		{
   			cout<<"作业表已满\n";
			break;
		}
		cin>>tempj.jno>>tempj.jstart>>tempj.jlen;
	}
	
	cout<<"请输入起址"<<'\t'<<"长度\n";
    i = 0;
	cin>>tempf.fstart>>tempf.flen;
	while(tempf.fstart != 0)
	{
		while(i < 10 && ft[i].fstatus == 'F') i++;
		if(i < 10)
		{
			tempf.fstatus = 'F';
			ft[i] = tempf ;
		}else
		{
		cout<<"文件表已满\n";
			break;
		}
		cin>>tempf.fstart>>tempf.flen;
	}
	
	cout<<"作业表"<<'\n'<<"作业号"<<'\t'<<"起址"<<'\t'<<"长度\n";	//显示
	for(i = 0; i < 10; i++)
	{
		if(jt[i].jno != 0)
			cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen;
	}

	cout<<"空闲区说明表"<<'\n'<<"起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
	i = 0;
	while(ft[i].fstatus != 'N')
	{
		cout<<"ft[i].fstart"<<'\t'<<ft[i].flen<<'\t'<<ft[i].fstatus;
		i++ ;
	}
}

void alloc()
{
	int i,j;
	int jno;
	int jlen;
	
	cout<<"请输入作业号和长度"<<endl;
	cin>>jno>>jlen;	//输入作业号和需要量
	while(jno != 0)
	{
		i = 0;
		while(i < 10 && ft[i].flen < jlen) i++;	//寻找第一个满足需要量的表目
		if(i == 10)		//不存在
		{
			cout<<"没有足够内存\n";
		}else
		{
			j = 0;	//填写作业登记表
			while(j < 10 && jt[j].jno != 0) j++;
			jt[j].jno = jno;
			jt[j].jlen = jlen;
			jt[j].jstart = ft[i].fstart;
		
			if((ft[i].flen - jlen) < 0.25)	//修改空闲区说明表
				ft[i].fstatus = 'N';
			else {				
				ft[i].fstart = ft[i].fstart +  jlen;
				ft[i].flen = ft[i].flen - jlen;
			}
		}
		cout<<"请输入作业号和长度\n";
		cin>>jno>>jlen;
	}

	for(i = 0; i < 10; i++)	//紧缩空闲区说明表
		if(ft[i].fstatus == 'N')
		{
			for(j = i; j < 9; j++) ft[j] = ft[j + 1];
			ft[j].fstatus = 'N';
		}

	cout<<"作业表内容\n"<<"作业号"<<'\t'<<"起址"<<'\t'<<"长度\n";	//显示
	for(i = 0; i < 10; i++)
	{
		if(jt[i].jno != 0)
			cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen;
	}

	cout<<"空闲区说明表\n"<<"起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
	i = 0;
	while(ft[i].fstatus != 'N')
	{
		cout<<ft[i].fstart<<'\t'<<ft[i].flen<<'\t'<<ft[i].fstatus;
		i++ ;
	}
}

void back()
{
	int jno,i,j,k,m;

	cout<<"请输入\n";
	cin>>jno;
	
	while(jno != 0)
	{	
		k = 0;
		while(k < 10 && jt[k].jno != jno) k++;

		if(k == 10) 
		{
			cout<<"没有此作业\n";
		}else
		{
			jt[k].jno = 0;	//撤消作业

			i = 0;
			while(i < 10 && ft[i].fstatus == 'F') i++;
			
			i-- ;

			if((jt[k].jstart + jt[k].jlen)< ft[0].fstart) //放在第一个的位置
			{
				for(j=i; j>=0; j--) ft[j+1]= ft[j];
				ft[j+1].fstart = jt[k].jstart;
				ft[j+1].flen = jt[k].jlen;
				ft[j+1].fstatus = 'F';
			}else if((jt[k].jstart + jt[k].jlen) == ft[0].fstart)
			{
				ft[0].fstart = jt[k].jstart ;
				ft[0].flen = ft[0].flen + jt[k].jlen;
			}
			else 
			{
				for(j = 0; j < i; j++)	
				{
					if((ft[j].fstart + ft[j].flen) < jt[k].jstart && ft[j+1].fstart > (jt[k].jstart + jt[k].jlen))
					{
						if(j == 8)	//j+1=9
						{
							cout<<"文件表已满\n";
						}else
						{
							for(m = i; m > j; m--) ft[m+1]=ft[m];	//m=j+1
							ft[j+1].fstart = jt[k].jstart;
							ft[j+1].flen = jt[k].jlen;
							ft[j+1].fstatus = 'F';
						}
						break;
					}
					else if((ft[j].fstart + ft[j].flen) == jt[k].jstart && ft[j+1].fstart != (jt[k].jstart + jt[k].jlen))
					{
						ft[j].flen = ft[j].flen + jt[k].jlen ;
						break;
					}
					else if((ft[j].fstart + ft[j].flen) != jt[k].jstart && ft[j+1].fstart == (jt[k].jstart + jt[k].jlen))
					{
						ft[j+1].fstart = jt[j].jstart ;
						ft[j+1].flen = ft[j+1].flen + jt[k].jlen ;
						break;
					}
					else if((ft[j].fstart +ft[j].flen) == jt[k].jstart && ft[j+1].fstart == (jt[k].jstart + jt[k].jlen))
					{
						ft[j].flen = ft[j].flen + jt[k].jlen + ft[j+1].flen ;
						for(; j < 8; j++)
							ft[j+1] = ft[j+2];	//j=7
						ft[j+1].fstatus = 'N'; 
						break;
					}
				}

				if(j==i)	//最后的情况
				{
					if((ft[j].fstart + ft[j].flen) == jt[k].jstart)
						ft[j].flen = ft[j].flen + jt[k].jlen;
				 	else
					{
						if(j==9) 
							cout<<"文件表已满\n";
						else
						{
							ft[i+1].fstart = jt[k].jstart;
							ft[i+1].flen = jt[k].jlen;
							ft[i+1].fstatus = 'F';
						}
					}
				}
			}
		}

		cout<<"作业表内容\n"<<"作业号"<<'\t'<<"起址"<<'\t'<<"长度\n";	//显示
		for(i = 0; i < 10; i++)
		{
			if(jt[i].jno != 0)
				cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen;
		}

		cout<<"空闲区说明表\n"<<"起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
		i = 0;
		while(ft[i].fstatus != 'N')
		{
			cout<<ft[i].fstart<<'\t'<<ft[i].flen<<'\t'<<ft[i].fstatus;
			i++ ;
		}
		cout<<"请输入作业号\n";
		cin>>jno;
	}
}



int main()
{
	int n = 0;
	int i;
	
	for(i = 0; i < 10; i++) 
		jt[i].jno = 0;
	for(i = 0; i < 10; i++) 
		ft[i].fstatus = 'N';
	
	while(1)
	{	

		printmenu();
		cout<<"请输入要进行的操作:"<<endl;
		cin>>n;
		switch(n)
		{
			case 1: 
				init();
				break;
			case 2:
				alloc();
				break;
			case 3: 
				back();
				break;
			case 4:
				return 0; 
			case 5:
				printf("INPUT WRONG\n");
				break;
		}
		getchar();
	//	printf("Press any key to continue...");
		getchar();
	}
	return 0;
}