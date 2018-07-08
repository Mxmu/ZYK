void disp()
{
	int i;
	printf("\n\taddress\t\tlength\t\tstate\n");
    for(i=0;i<m;i++)
    printf("\n\t%d\t\t%d\t\t  %c\n",fr[i].ad,fr[i].len,fr[i].state);
} 
