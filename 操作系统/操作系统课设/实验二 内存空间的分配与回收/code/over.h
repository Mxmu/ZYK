void over()
{ 
     int d,i,j,p,k;
     p=0;
     i=0; 
     printf("\n ����Ҫ�����ڼ�����ҵ��\n");
     scanf("%d",&d);
     printf("\n Ҫ������ҵ����ϢΪ��\n");
     printf("\n\taddress\t\tlength\t\tstate\n");
     printf("\n\t%d\t\t%d\t\t  %c\n",us[d].ad,us[d].len,us[d].state);
     if(us[d].state=='N')//���Ҫ������ҵ��״̬Ϊ'N'��˵������ҵû�б�����ռ�
     printf("\n ����ҵû�з����ڴ棡\n");
     if(us[d].state=='Y')//���Ҫ������ҵ��״̬Ϊ'Y'��˵������ҵ�Ѿ�������
     printf("\n ����ҵ�Ѿ����� ��\n");
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
