void insertu(int i)
{
	int j,p;
    p=0;
    printf("\n�������%d����ҵ�ĳ��ȣ�\n",i);
    scanf("%d",&us[i].len);
    us[i].ad=0;
    us[i].state='U';
    j=0;
    p=0;
    if(fr[0].ad==0)
    printf("\n ���п������Ѿ�ȫ��������ϣ�\n");
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
            printf("\nû���ʵ��Ŀռ���Բ��룡\n");
        }
       if(p!=0)
       {
           printf("\n��%d����ҵ����ռ�󣬿��б�Ϊ��\n",i);
           disp();
       }
}
