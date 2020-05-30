#include<stdio.h>
#include<conio.h>
int main()
{
    int frame_size, no_of_pages, flag1, flag2, flag3, i, j, k, pos, max, page_faults = 0, hit = 0;
    int pri[20][30], frames[10], pages[30], temp[10];
    char x[20];

    printf("Enter number of pages: ");
    scanf("%d", &no_of_pages);
    
	printf("Enter the pages: ");
	for(i = 0; i < no_of_pages; ++i)
	{
		scanf("%d", &pages[i]);
 	}
 	
 	printf("Enter number of frames: ");
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
			   flag1 = flag2 = 1;
			   x[i]='*';
			   break;
		    }
		}	

		if(flag1 == 0)
		{
		    for(j = 0; j < frame_size; ++j)
			{
				if(frames[j] == -1)
				{
			   		page_faults++;
			   		//x[j]='*';
			    	frames[j] = pages[i];
			    	flag2 = 1;
				    break;
				}
	    	}
		}

		if(flag2 == 0)
		{
		    flag3 =0;
	
		    for(j = 0; j < frame_size; ++j)
			{
				temp[j] = -1;
	
				for(k = i + 1; k < no_of_pages; ++k)
				{
				    if(frames[j] == pages[k])
					{
					temp[j] = k;
						break;
			 	   }
				}
		    }

		    for(j = 0; j < frame_size; ++j)
			{
				if(temp[j] == -1)
				{
			   		pos = j;
			    	flag3 = 1;
			    	break;
				}
		    }
	
		    if(flag3 ==0)
			{
				max = temp[0];
				pos = 0;
	
				for(j = 1; j < frame_size; ++j)
				{
				    if(temp[j] > max)
					{
						max = temp[j];
						pos = j;
				    }
				}
	    	}

	   		frames[pos] = pages[i];
	    	page_faults++;
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
	
	
	
    for(i=0;i<frame_size;i++)
    {
    	printf("| %2d",i);
      	printf("\t|");
      	
		for(j = 0; j < no_of_pages; j++)
		{
			if(pri[i][j]== -1)
			{
				printf("  - |");
			}
			else
		    printf(" %2d |",pri[i][j]);
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
	//printf("\033[0m")
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{	
		printf("-");
	}
	
	hit = no_of_pages-page_faults;
	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,hit,page_faults);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults,hit);


    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults,no_of_pages,((float)page_faults/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",(no_of_pages-page_faults),no_of_pages,((float)no_of_pages-page_faults)/no_of_pages);
    getch();
    return 0;
    getch();
    return 0;
}
