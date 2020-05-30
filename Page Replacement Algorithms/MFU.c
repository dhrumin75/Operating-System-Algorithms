#include<stdio.h>

int main()
{
	int frame_size, no_of_pages, hit,s=0;
    int pages[25], frame[10], arr[25],pri[20][20], time[25];
    int m, n, page, flag, k, minimum_time, temp,i,j,page_faults=0,target;
    char x[20];
    hit = 0;
      
	printf("\nEnter Total Number of Pages:\t");
    scanf("%d", &no_of_pages); 
      
    printf("\nEnter the pages:\n");
    for(m = 0; m < no_of_pages; m++)
    {
        scanf("%d", &pages[m]);
    }
    
    
    printf("\nEnter Total Number of Frames:\t");
    scanf("%d", &frame_size);
      
      
    for(i=0; i< no_of_pages; i++)
   	{
   		x[i]='X';
	}
    for(m = 0; m < frame_size; m++)
    {
        frame[m] = -1;
    }
    printf("\n");
    
    for(i = 0; i < no_of_pages ; i++)
    {
	    flag = 0;
	    
	    for(n = 0; n < frame_size ; n++)
	    {
		  if(pages[i] == frame[n])
		  {
			flag++;
			page_faults--;
			hit++;
			x[i]='*';
		  }
	    }
	    page_faults++;
	    
	    
	    
	    if((page_faults <= frame_size) && (flag == 0))
	    {
		  frame[s++] = pages[i];
	    }
	    else if(flag == 0)
	    {
			for(m=0; m < frame_size; m++)
	    	{
	    		if(frame[m]==pages[i-1])
	    		{
	    			target=m;
	    			break;
				}
			}
			frame[target]=pages[i];
	   }
	    
		for(k=0; k <frame_size ; k++)
		{ 
			pri[k][i]=frame[k];
		}
    }
    
    printf("\n");
    for(i = 0 ; i < no_of_pages*5+2*frame_size+2; i ++)
		{
			printf("-");
		}
		printf("\n|Frames |");
		
		for(i=0; i<= 2* no_of_pages + 6; i++)
		{
			printf(" ");	
		}
		printf("Pages");
		for(i=0; i<= 2*no_of_pages + 6; i++)
		{
			printf(" ");	
		}
		
		printf("|\n\t");
			for(i = 0 ; i < no_of_pages*5+2*frame_size - 5; i ++)
		{
			printf("-");
		}
		printf("\n|\t|");
		
		
	for(i=0 ; i < no_of_pages ; i++)
	{
		printf(" %2d |",pages[i]);
	}
	printf("\n|\t");
	for(i = 0 ; i < no_of_pages*5+2*frame_size - 5; i ++)
	{
		printf("-");
	}
	printf("\n");
    
    for(m=0; m < frame_size ; m++ )
    {
    	printf("| %2d",m);
      		printf("\t|");
		for(j = 0; j < no_of_pages; j++)
		{
			if(pri[m][j]== -1)
			{
				printf("  - |");
			}
			else
		    printf(" %2d |",pri[m][j]);
		}
		printf("\n");
    }
    
    for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{
		printf("-");
	}
    
	printf("\n\t|");
	for(i = 0; i< no_of_pages; i++)
	{
		if(x[i]=='X')
		{
			//printf("\033[0;31m");
			printf(" %2c |",x[i]);
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %2c |",x[i]);
		}
	}
	//printf("\033[0m");
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{	
		printf("-");
	}
	
	page_faults= no_of_pages - hit;
	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,hit,page_faults);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults,hit);

    
    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults,no_of_pages,((float)page_faults/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",hit,no_of_pages,((float)hit)/no_of_pages);
    getch();
    

	return 0;
}
