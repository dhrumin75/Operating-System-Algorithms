#include<stdio.h>
 
int main()
{
	int fragment[20],b[20],p[20],i,j,nh,np,temp,lowest=9999;
	static int barray[20],parray[20];
	char ans;
	label:
	printf("\n\t\tBest Fit");
	printf("\nEnter the number of holes:");
	scanf("%d",&nh);	
	printf("\nEnter the size of the hole:-\n");
	for(i=1;i<=nh;i++)
    {
		printf("H%d:",i);
        scanf("%d",&b[i]);
    }
	
	printf("Enter the number of processes:");
	scanf("%d",&np);

	printf("\nEnter the size of the processes :-\n");
	for(i=1;i<=np;i++)
    {
        printf("Process P%d:",i);
        scanf("%d",&p[i]);
    }
	
	for(i=1;i<=np;i++)
	{
		for(j=1;j<=nh;j++)
		{
			if(barray[j]!=1)
			{
				temp=b[j]-p[i];
				if(temp>=0)
					if(lowest>temp)
					{
						parray[i]=j;
						lowest=temp;
					}
			}
		}
		
		fragment[i]=lowest;
		barray[parray[i]]=1;
		lowest=10000;
	}
	for(i=0;i<65;i++)
	{
		printf("-");
	}
	printf("\n|Process|  Process_size  |   Hole_no  |   Size   |  Available  |\n");
	for(i=0;i<65;i++)
	{
		printf("-");
	}
	for(i=1;i<=np;i++)
	{
		if(parray[i]!=0)
		{
			printf("\n|  P%d   |       %d        |     H%d     |    %d    |       %d      |",i,p[i],parray[i],b[parray[i]],fragment[i]);
			printf("\n------------------------------------------------------------------");
		}
		else
		{	
			printf("\n|  P%d   |       %d        |     N.A     |     0    |       0        |",i,p[i],parray[i]);
			printf("\n-------------------------------------------------------------------");
		}
	}
	printf( "\nDo you want to continue (Y/N)?\n");
	printf( "You must type a 'Y' or an 'N':");
    scanf(" %c",&ans);
	if( ans=='y' || ans=='Y')
	{
		goto label;
	}
	else
	{
	return 0;
	}
}
