#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
      int rs[30],i,f,n,s,pages,p,frame_size,l=0,flag=0;
      int page_faults = 0;
      float fault_ratio;
      char x[20];
      int frame[30],pri[20][30];
	
      printf("\nEnter number of pages:");
      scanf("%d", &pages);
      
      l=pages;
      printf("\nEnter the number of pages:\n");
      for(i = 0; i < pages; i++)
      {
	    scanf("%d", &rs[i]);
      }
    	
      printf("\nEnter number of frames:");
      {
	    scanf("%d", &frame_size);
      }
      p=frame_size;
      frame[p];
      
   	  for(i=0; i< pages; i++)
   	  {
   	  	x[i]='X';
	}
      for(i = 0; i < frame_size; i++)
      {
	    frame[i] = -1;
      }
      
      for(i = 0; i < pages; i++)
      {
	    s = 0;
	    
	    for(n = 0; n < frame_size; n++)
	    {
		  if(rs[i] == frame[n])
		  {
			s++;
			page_faults--;
			x[i]='*';
		  }
	    }
	    
	    page_faults++;
	    
	    if((page_faults <= frame_size) && (s == 0))
	    {
		  frame[flag++] = rs[i];
	    }
	    else if(s == 0)
	    {
		  frame[(page_faults - 1) % frame_size] = rs[i];
	    }
		  for(f=0;f<frame_size;f++)
		  {
			pri[f][i]=frame[f];
		  }
      }
	  	printf("\n");
	  	
	  	
	  	for(i = 0 ; i < pages*5+10; i ++)
		{
			printf("-");
		}
		printf("\n|Frames |");
		
		for(i=0; i<= 2*pages ; i++)
		{
			printf(" ");	
		}
		printf("Pages");
		for(i=0; i<= 2*pages ; i++)
		{
			printf(" ");	
		}
		
		printf("|\n\t");
			for(i = 0 ; i < pages*5+2*frame_size - 5; i ++)
		{
			printf("-");
		}
		printf("\n|\t|");
		
		
		
		for(i=0 ; i < pages ; i++)
		{
			printf(" %2d |",rs[i]);
		}
		printf("\n|\t");
		for(i = 0 ; i < pages*5+2*frame_size - 5; i ++)
		{
			printf("-");
		}
		printf("\n");
		
      	for(i=0;i<frame_size;i++)
      	{
      		
      		printf("| %2d",i);
      		printf("\t|");
    		for(f = 0; f < pages; f++)
			{
				if(pri[i][f]== -1)
				{
					printf("  - |");
				}
				else
		    		printf(" %2d |",pri[i][f]);
			}
			printf("\n");
		}
		
		for(i = 0 ; i < pages*5+2*frame_size+3; i ++)
		{
			printf("-");
		}
		
		printf("\n\t|");
		
		for(i = 0; i< pages; i++)
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
		
		printf("\n");
		for(i = 0 ; i < pages*5+2*frame_size+3; i ++)
		{
			printf("-");
		}
      	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here it is %d - %d =\t%d\n\n", pages,(pages-page_faults),page_faults);
      	printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here it is %d - %d =\t%d\n\n", pages,page_faults,(pages-page_faults));
     	
     	fault_ratio=((float)page_faults/pages);
     	printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here it is %d / %d =\t%5.2f\n\n",page_faults,pages,fault_ratio);
      	
		printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here it is %d / %d =\t%5.2f\n\n",(pages-page_faults),pages,((float)pages-page_faults)/pages);  
		  
      	return 0;
}
