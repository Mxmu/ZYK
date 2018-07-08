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


void menu()
{
	
	cout<<"************************************"<<endl;
	cout<<"* 可变分区管理方式主存的分配与回收 *"<<endl;
	cout<<"* 1.初始化作业登记表和空闲区说明表 *"<<endl;
	cout<<"* 2. 主内存分配                    *"<<endl;
	cout<<"* 3. 主内存回收                    *"<<endl;
	cout<<"* 4. 退出                          *"<<endl;
	cout<<"* 5. 显示输入出错                  *"<<endl;
	cout<<"************************************"<<endl;
}

void Init()
{
	int i=0,j=0;
	Job j1;
	fspace f1;
	cout<<"初始化作业表:"<<endl;
	cout<<"请输入作业表中作业个数:"<<endl;
	int n;
	cin>>n;
	cout<<"请输入作业号\t起址\t长度"<<endl;

	for(;i<n;i++)
	{
		cin>>j1.jno>>j1.jstart>>j1.jlen;
		if(i<10&&j1.jno!=0)
		{
			jt[i]=j1;
			cout<<"成功填入作业表"<<endl;
		}
		else if(i==10)
		{
			cout<<"作业表已满,无法输入作业!!!"<<endl;
		}else if(j1.jno==0)
		{
			cout<<"输入错误,作业号不能为0!!!"<<endl;
		}

	}
	cout<<"初始化空闲区说明表:"<<endl;
	cout<<"请输入空闲区说明表中空闲区个数:"<<endl;
	int m;
	cin>>m;

	cout<<"请输入起址"<<'\t'<<"长度\n";
  
	for(;j<m;j++)
	{
		cin>>f1.fstart>>f1.flen;
		if(j<10&&f1.flen!=0)
		{
			f1.fstatus='F';
			ft[j]=f1;
			cout<<"成功填入空闲区"<<endl;
		}else if(j==10)
		{
			cout<<"空闲区已满!!"<<endl;
		}else if(f1.fstart==0||f1.flen==0)
		{
			cout<<"起址为0或长度为0!!!不能初始化"<<endl;
		}
	}
	cout<<endl;
	cout<<"初始化后作业表显示为:"<<endl;
	cout<<"作业表:"<<'\n'<<"作业号"<<'\t'<<"起址"<<'\t'<<"长度\n";	//显示
	for(i = 0; i < n; i++)
	{
			cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen;
	}
	cout<<endl;
	cout<<"初始化后空闲区说明表显示为:"<<endl;
	cout<<"空闲区说明表:"<<'\n'<<"起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
	
	for(j=0;j<m;j++)
	{
		cout<<ft[j].fstart<<'\t'<<ft[j].flen<<'\t'<<ft[j].fstatus;
     	cout<<endl;
	}
	cout<<endl;
}

void allot()
{
	int n;
	int jno;
	int jlen;
	cout<<"主内存分配:"<<endl;
	cout<<"请输入要分配内存的作业号\t需要内存:"<<endl;  
	{	int j=0;
		cin>>jno>>jlen;	//输入作业号和需要量
		if(jno==0){cout<<"错误,作业号不能为0!"<<endl;}
		while(j<=10&&j<10&&ft[j].flen<jlen) j++;
		{
			if(j==10)
			{
				cout<<"内存不足!!!不能分配!!!\n"<<endl;
			}
			else
			{
				int k=0;
				while(k<10&&jt[k].jno!=0) k++;
				{
					jt[k].jno=jno;
					jt[k].jlen=jlen;
					jt[k].jstart=ft[j].fstart;
					if((ft[j].flen-jlen)<0.25)
					{
						ft[j].fstatus='N';
					}
					else
					{
						ft[j].fstart=ft[j].fstart+jlen;
						ft[j].flen=ft[j].flen-jlen;
					}
				}
			}
		}				
	for(int i = 0; i < 10; i++)	//紧缩空闲区说明表
	if(ft[i].fstatus == 'N')
		{
			for(j = i; j < 9; j++) 
			ft[j] = ft[j + 1];
			ft[j].fstatus = 'N';
		}
	cout<<endl;
	cout<<"内存分配后作业表:\n"<<"作业号"<<'\t'<<"起址"<<'\t'<<"长度\n";	//显示
	for(i = 0; i < 10; i++)
	{
		if(jt[i].jno != 0)
			cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen<<'\n';
	}
	cout<<endl;
	cout<<"内存分配后空闲区说明表:\n"<<"起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
	i = 0;
	while(ft[i].fstatus != 'N'&&ft[i].fstatus)
	{
		cout<<ft[i].fstart<<'\t'<<ft[i].flen<<'\t'<<ft[i].fstatus<<'\n';
		i++ ;
	}
	}
	}





void reco()
{
	int jno,i,j,k,m;
	cout<<"请输入要回收的作业号\n";
	cin>>jno;
		
		k=0;
		while(k < 10 && jt[k].jno!=jno) k++;
		if(k==10) 
		{
			cout<<"没有此作业,无法回收!!!\n";
		}else
		{
			jt[k].jno = 0;	//撤消作业
			i = 0;
			while(i < 10 && ft[i].fstatus == 'F') i++;
			i-- ;
			if((jt[k].jstart + jt[k].jlen)< ft[0].fstart) //放在第一个的位置
			{
				for(j=i; j>=0; j--) 
					ft[j+1]= ft[j];
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

		cout<<"回收后作业表内容:\n"<<"作业号"<<'\t'<<"起址"<<'\t'<<"长度\n";	//显示
		for(i = 0; i < 10; i++)
		{
			if(jt[i].jno != 0)
				cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen<<endl;
		}

		cout<<"回收后空闲区说明表:\n"<<"起址"<<'\t'<<"长度"<<'\t'<<"状态\n";
		i = 0;
		while(ft[i].fstatus != 'N'&&ft[i].fstatus)
		{
			cout<<ft[i].fstart<<'\t'<<ft[i].flen<<'\t'<<ft[i].fstatus<<'\n';
			i++ ;
		}
	}
}

int main()
{
	while(1)
	{	

		int n;
		menu();
		cout<<"请输入要进行的操作:"<<endl;
		cin>>n;
		switch(n)
		{
			case 1: 
				Init();
				break;
			case 2:
				allot();
				break;
			case 3: 
				reco();
				break;
			case 4:
				return 0; 
			default:
				cout<<"无效操作!!!请重输"<<endl;
				break;
		}
		getchar();
}return 0;
}