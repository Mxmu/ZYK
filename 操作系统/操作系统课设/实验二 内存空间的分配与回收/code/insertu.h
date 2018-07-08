void insertu(int i)
{
	int j,p;
    p=0;
    printf("\n请输入第%d个作业的长度：\n",i);
    scanf("%d",&us[i].len);
    us[i].ad=0;
    us[i].state='U';
    j=0;
    p=0;
    if(fr[0].ad==0)
    printf("\n 所有空闲区已经全部分配完毕！\n");
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
            printf("\n没有适当的空间可以插入！\n");
        }
       if(p!=0)
       {
           printf("\n第%d个作业分配空间后，空闲表为：\n",i);
           disp();
       }
}
