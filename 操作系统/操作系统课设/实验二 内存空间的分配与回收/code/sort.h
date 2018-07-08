void sort()
{
	int i,q,j;
    i=0;
    q=0;

     
    if(fr[0].ad!=0)
    { 
         do
	     {
             if(f0[0].ad>fr[i].ad)
             i=i+1;
             else q=1;
    	 }while(fr[i].state!='M'&&q==0);
   
        for(j=m-1;j>i;j--)
 	    {
             fr[j].ad=fr[j-1].ad;
             fr[j].len=fr[j-1].len;
             fr[j].state=fr[j-1].state;
    	}
        fr[i].ad=f0[0].ad;
        fr[i].len=f0[0].len;
        fr[i].state=f0[0].state;
   }
   if(fr[0].ad==0)
    {
        fr[0].ad=f0[0].ad;
        fr[0].len=f0[0].len;
        fr[0].state=f0[0].state;
    }
}

void sort1()
{
	int i;
    i=0;
    while(fr[i].state!='M')
	{i++;}
    if(fr[i+1].state!='M')
	{
		do
		{
	    	fr[i].ad=fr[i+1].ad;
            fr[i].len=fr[i+1].len;
            fr[i].state=fr[i+1].state;
            i++;
		}while(fr[i+1].state!='M');
		fr[i].ad=0;
		fr[i].len=0;
		fr[i].state='M';
	}
 
}
