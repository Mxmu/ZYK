#include "stdio.h" 
#include "stdlib.h" 
#include "dy.h"
#include "disp.h"
#include "creatf.h"

#include "sort.h"

#include "insertu.h"
#include "over.h"
int main()
{
    int i,j,k,p;
	i=1;
	k=0;
	p=1;
    printf("\n*----------------------------------------------------------*\n");
    printf("|*****************���洢��ռ�ķ���ͻ���ģ��***************|\n");
    printf("*----------------------------------------------------------*\n\n");
    creatf();
    printf("\n ������Ŀǰ���з��������Ϣ��\n");
    while(p!=0)
    {
         printf("\n ��������з�����ĳһ�е���ַ�ͳ���\n");
         scanf("%d%d",&f0[0].ad,&f0[0].len);
         f0[0].state='F';
         sort();
        // k++;
         printf("\n ������ٽ������룬������0\n");
         scanf("%d",&p);
     }
    printf("\n ������ҵ֮ǰ���з��������Ϣ���£�\n");
    disp(); 
    for(;;)
    { 
        printf("=================�˵�===================\n");
        printf("~~~~~~1��Ϊ��ҵ����ռ䣻\n");
        printf("~~~~~~2��������ҵ��\n");
        printf("~~~~~~3���˳�����\n");
        printf("========================================\n");
        printf("�������ѡ��\n"); 
        scanf("%d",&j);
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
