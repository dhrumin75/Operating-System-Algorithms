#include<stdio.h>
#include<conio.h>


int findLRU(int time[], int n);


int main()
{
    int frame_size, no_of_pages, counter = 0, flag1, flag2, i, j, m, pos, page_faults = 0;
    int frames[10], pages[30], time[10], pri[20][20];
    char x[20];
    printf("\nEnter number of pages: ");
    scanf("%d", &no_of_pages);
	
	
	printf("\nEnter the pages: ");
	for(i = 0; i < no_of_pages; ++i)
	{
		scanf("%d", &pages[i]);
	}
	      
    printf("\nEnter number of frames: ");
    scanf("%d", &frame_size);
	
	
	for(i=0; i< no_of_pages; i++)
   	{
   	  	x[i]='X';
	}

    for(i = 0; i < frame_size; ++i)
	{
		frames[i] = -1;
    }

    for(i = 0; i < no_of_pages; ++i)
    {
		flag1 = flag2 = 0;
	
		for(j = 0; j < frame_size; ++j)
		{
		    if(frames[j] == pages[i])
		    {
				counter++;
				x[i]='*';
				time[j] = counter;
			   flag1 = flag2 = 1;
			   break;
		    }
		}
	
		if(flag1 == 0)
		{
		    for(j = 0; j < frame_size; ++j)
			{
				if(frames[j] == 0)
				{
				    counter++;
				    page_faults++;
				    //x[j]= '*';
				    frames[j] = pages[i];
				    time[j] = counter;
				    flag2 = 1;
				    break;
				}
			}
		}
	
		if(flag2 == 0)
		{
		    pos = findLRU(time, frame_size);
		    counter++;
		    page_faults++;
		    //x[j]= '*';
		    frames[pos] = pages[i];
		    time[pos] = counter;
		}
	
		for(j = 0; j < frame_size; j++)
		{
		    pri[j][i]=frames[j];
		}
    }
    
    
    
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

	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,(no_of_pages-page_faults),page_faults);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults,(no_of_pages-page_faults));

    
    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults,no_of_pages,((float)page_faults/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",(no_of_pages-page_faults),no_of_pages,((float)no_of_pages-page_faults)/no_of_pages);
    getch();
    return 0;
}


int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for(i = 1; i < n; ++i)
	{
		if(time[i] < minimum)
		{
	   		minimum = time[i];
	    	pos = i;
		}
    }

    return pos;
}

