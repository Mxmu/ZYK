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
    printf("|*****************主存储存空间的分配和回收模拟***************|\n");
    printf("*----------------------------------------------------------*\n\n");
    creatf();
    printf("\n 请输入目前空闲分区表的信息：\n");
    while(p!=0)
    {
         printf("\n 请输入空闲分区表某一行的起址和长度\n");
         scanf("%d%d",&f0[0].ad,&f0[0].len);
         f0[0].state='F';
         sort();
        // k++;
         printf("\n 如果不再进行输入，则输入0\n");
         scanf("%d",&p);
     }
    printf("\n 插入作业之前空闲分区表的信息如下：\n");
    disp(); 
    for(;;)
    { 
        printf("=================菜单===================\n");
        printf("~~~~~~1：为作业分配空间；\n");
        printf("~~~~~~2：结束作业；\n");
        printf("~~~~~~3：退出程序；\n");
        printf("========================================\n");
        printf("输入你的选择：\n"); 
        scanf("%d",&j);
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
