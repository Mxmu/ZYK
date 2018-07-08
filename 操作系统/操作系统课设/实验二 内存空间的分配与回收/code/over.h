void over()
{ 
     int d,i,j,p,k;
     p=0;
     i=0; 
     printf("\n 输入要结束第几个作业：\n");
     scanf("%d",&d);
     printf("\n 要结束作业的信息为：\n");
     printf("\n\taddress\t\tlength\t\tstate\n");
     printf("\n\t%d\t\t%d\t\t  %c\n",us[d].ad,us[d].len,us[d].state);
     if(us[d].state=='N')//如果要结束作业的状态为'N'，说明此作业没有被分配空间
     printf("\n 此作业没有分配内存！\n");
     if(us[d].state=='Y')//如果要结束作业的状态为'Y'，说明此作业已经被结束
     printf("\n 此作业已经结束 ！\n");
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
