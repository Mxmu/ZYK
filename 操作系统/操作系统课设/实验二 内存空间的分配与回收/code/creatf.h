void creatf()//空闲分区表初始化
{int i;

 for(i=0;i<m;i++)
     {
          fr[i].ad=0;
          fr[i].len=0;
          fr[i].state='M';
     }
 }
