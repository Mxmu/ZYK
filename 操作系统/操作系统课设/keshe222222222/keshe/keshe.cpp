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
	cout<<"* �ɱ��������ʽ����ķ�������� *"<<endl;
	cout<<"* 1.��ʼ����ҵ�ǼǱ�Ϳ�����˵���� *"<<endl;
	cout<<"* 2. ���ڴ����                    *"<<endl;
	cout<<"* 3. ���ڴ����                    *"<<endl;
	cout<<"* 4. �˳�                          *"<<endl;
	cout<<"* 5. ��ʾ�������                  *"<<endl;
	cout<<"************************************"<<endl;
}

void Init()
{
	int i=0,j=0;
	Job j1;
	fspace f1;
	cout<<"��ʼ����ҵ��:"<<endl;
	cout<<"��������ҵ������ҵ����:"<<endl;
	int n;
	cin>>n;
	cout<<"��������ҵ��\t��ַ\t����"<<endl;

	for(;i<n;i++)
	{
		cin>>j1.jno>>j1.jstart>>j1.jlen;
		if(i<10&&j1.jno!=0)
		{
			jt[i]=j1;
			cout<<"�ɹ�������ҵ��"<<endl;
		}
		else if(i==10)
		{
			cout<<"��ҵ������,�޷�������ҵ!!!"<<endl;
		}else if(j1.jno==0)
		{
			cout<<"�������,��ҵ�Ų���Ϊ0!!!"<<endl;
		}

	}
	cout<<"��ʼ��������˵����:"<<endl;
	cout<<"�����������˵�����п���������:"<<endl;
	int m;
	cin>>m;

	cout<<"��������ַ"<<'\t'<<"����\n";
  
	for(;j<m;j++)
	{
		cin>>f1.fstart>>f1.flen;
		if(j<10&&f1.flen!=0)
		{
			f1.fstatus='F';
			ft[j]=f1;
			cout<<"�ɹ����������"<<endl;
		}else if(j==10)
		{
			cout<<"����������!!"<<endl;
		}else if(f1.fstart==0||f1.flen==0)
		{
			cout<<"��ַΪ0�򳤶�Ϊ0!!!���ܳ�ʼ��"<<endl;
		}
	}
	cout<<endl;
	cout<<"��ʼ������ҵ����ʾΪ:"<<endl;
	cout<<"��ҵ��:"<<'\n'<<"��ҵ��"<<'\t'<<"��ַ"<<'\t'<<"����\n";	//��ʾ
	for(i = 0; i < n; i++)
	{
			cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen;
	}
	cout<<endl;
	cout<<"��ʼ���������˵������ʾΪ:"<<endl;
	cout<<"������˵����:"<<'\n'<<"��ַ"<<'\t'<<"����"<<'\t'<<"״̬\n";
	
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
	cout<<"���ڴ����:"<<endl;
	cout<<"������Ҫ�����ڴ����ҵ��\t��Ҫ�ڴ�:"<<endl;  
	{	int j=0;
		cin>>jno>>jlen;	//������ҵ�ź���Ҫ��
		if(jno==0){cout<<"����,��ҵ�Ų���Ϊ0!"<<endl;}
		while(j<=10&&j<10&&ft[j].flen<jlen) j++;
		{
			if(j==10)
			{
				cout<<"�ڴ治��!!!���ܷ���!!!\n"<<endl;
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
	for(int i = 0; i < 10; i++)	//����������˵����
	if(ft[i].fstatus == 'N')
		{
			for(j = i; j < 9; j++) 
			ft[j] = ft[j + 1];
			ft[j].fstatus = 'N';
		}
	cout<<endl;
	cout<<"�ڴ�������ҵ��:\n"<<"��ҵ��"<<'\t'<<"��ַ"<<'\t'<<"����\n";	//��ʾ
	for(i = 0; i < 10; i++)
	{
		if(jt[i].jno != 0)
			cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen<<'\n';
	}
	cout<<endl;
	cout<<"�ڴ����������˵����:\n"<<"��ַ"<<'\t'<<"����"<<'\t'<<"״̬\n";
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
	cout<<"������Ҫ���յ���ҵ��\n";
	cin>>jno;
		
		k=0;
		while(k < 10 && jt[k].jno!=jno) k++;
		if(k==10) 
		{
			cout<<"û�д���ҵ,�޷�����!!!\n";
		}else
		{
			jt[k].jno = 0;	//������ҵ
			i = 0;
			while(i < 10 && ft[i].fstatus == 'F') i++;
			i-- ;
			if((jt[k].jstart + jt[k].jlen)< ft[0].fstart) //���ڵ�һ����λ��
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
							cout<<"�ļ�������\n";
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

				if(j==i)	//�������
				{
					if((ft[j].fstart + ft[j].flen) == jt[k].jstart)
						ft[j].flen = ft[j].flen + jt[k].jlen;
				 	else
					{
						if(j==9) 
							cout<<"�ļ�������\n";
						else
						{
							ft[i+1].fstart = jt[k].jstart;
							ft[i+1].flen = jt[k].jlen;
							ft[i+1].fstatus = 'F';
						}
					}
				}
			
		}

		cout<<"���պ���ҵ������:\n"<<"��ҵ��"<<'\t'<<"��ַ"<<'\t'<<"����\n";	//��ʾ
		for(i = 0; i < 10; i++)
		{
			if(jt[i].jno != 0)
				cout<<jt[i].jno<<'\t'<<jt[i].jstart<<'\t'<<jt[i].jlen<<endl;
		}

		cout<<"���պ������˵����:\n"<<"��ַ"<<'\t'<<"����"<<'\t'<<"״̬\n";
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
		cout<<"������Ҫ���еĲ���:"<<endl;
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
				cout<<"��Ч����!!!������"<<endl;
				break;
		}
		getchar();
}return 0;
}