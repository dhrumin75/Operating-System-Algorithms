#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
	
int  no_of_pages , frame_size, l = 0 , i , j , k , m , n, p , f, s, victim = 0, flag;
int flag1, flag2, flag3, counter = 0, pos, max, minimum_time, temp_lfu, target;
int page_faults = 0,page_faults_lru = 0, page_faults_op = 0, page_faults_lfu = 0, page_faults_mfu = 0, page_faults_sec = 0;
int hit = 0, hit_op = 0, hit_lfu = 0, hit_mfu = 0,hit_sec = 0;
float fault_ratio;
char x[20], x_lru[20], x_op[20], x_lfu[20], x_mfu[20], x_sec[20];
int frames[30], frames_lru[20], frames_op[20], frames_lfu[20], frames_mfu[20], frames_sec[20];
int pri[20][30], pri_lru[20][20], pri_op[20][20], pri_lfu[20][20], pri_mfu[20][20], pri_sec[20][20];
int pages[30], time[20], temp[10], stamp=0, time_lfu[20], arr[20], r_bit[20];

void display();
int findLRU(int time[], int n);

int main()
{
	printf("\nEnter number of Pages:");
    scanf("%d", &no_of_pages);
      
    l=no_of_pages;
    printf("\nEnter the Pages:\n");
    for(i = 0; i < no_of_pages; i++)
    {
	scanf("%d", &pages[i]);
    }
    	
    printf("\nEnter number of frames:");
    {
	scanf("%d", &frame_size);
    }
    p=frame_size;
    frames[p];
    frames_lru[p];
	frames_op[p];
	frames_mfu[p];
	frames_sec[p];
	
	for(i=0; i< no_of_pages; i++)
	{
		x[i]='X';
		x_lru[i]='X';
		x_op[i]= 'X';
		x_lfu[i]= 'X';
		x_mfu[i]='X';
		x_sec[i]= 'X';
	}
    for(i = 0; i < frame_size; i++)
    {
	    frames[i] = -1;
	    frames_lru[i]=-1;
	    frames_op[i]= -1;
	    frames_lfu[i]= -1;
	    frames_mfu[i]=-1;
	    frames_sec[i]=-1;
    }
    for(m = 0; m < 20; m++)
    {
        arr[m] = 0;
        r_bit[m]=0;
    }
      
    for(i = 0; i < no_of_pages; i++)
    {
		s = 0;
		    
		for(n = 0; n < frame_size; n++)
		{
			if(pages[i] == frames[n])
			{
				s++;
				page_faults--;
				x[i]='*';
				hit++;
			  }
		}
		page_faults++;
		    
		if((page_faults <= frame_size) && (s == 0))
		{
			frames[k++] = pages[i];
		}
		else if(s == 0)
		{
			frames[(page_faults - 1) % frame_size] = pages[i];
		}
		for(f=0;f<frame_size;f++)
		{
			pri[f][i]=frames[f];
		}
	}
	printf("\n");
	printf("\n................FIFO Page Replacement................\n\n");
	display();
	s = 0;
	
	for(i=0;i<frame_size;i++)
      	{
      		
      		printf("| %2d",i);
      		printf("\t|");
    		for(f = 0; f < no_of_pages; f++)
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
		
		printf("\n");
		for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
		{
			printf("-");
		}
      	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here it is %d - %d =\t%d\n\n", no_of_pages,(no_of_pages-page_faults),page_faults);
      	printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here it is %d - %d =\t%d\n\n", no_of_pages,page_faults,(no_of_pages-page_faults));
     	
     	fault_ratio=((float)page_faults/no_of_pages);
     	printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here it is %d / %d =\t%5.2f\n\n",page_faults,no_of_pages,fault_ratio);
      	
		printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here it is %d / %d =\t%5.2f\n\n",(no_of_pages-page_faults),no_of_pages,((float)no_of_pages-page_faults)/no_of_pages);  
		
	
	
	 printf("\n................LRU Page Replacement................\n\n");
	for(i = 0; i < no_of_pages; ++i)
    {
		flag1 = flag2 = 0;
	
		for(j = 0; j < frame_size; ++j)
		{
		    if(frames_lru[j] == pages[i])
		    {
				counter++;
				x_lru[i]='*';
				time[j] = counter;
			   flag1 = flag2 = 1;
			   break;
		    }
		}
	
		if(flag1 == 0)
		{
		    for(j = 0; j < frame_size; ++j)
			{
				if(frames_lru[j] == 0)
				{
				    counter++;
				    page_faults_lru++;
				    //x[j]= '*';
				    frames_lru[j] = pages[i];
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
		    page_faults_lru++;
		    //x[j]= '*';
		    frames_lru[pos] = pages[i];
		    time[pos] = counter;
		}
	
		for(j = 0; j < frame_size; j++)
		{
		    pri_lru[j][i]=frames_lru[j];
		}
    }
    
    display();
    for(i=0;i<frame_size;i++)
    {
    	printf("| %2d",i);
      	printf("\t|");
    	for(f = 0; f < no_of_pages; f++)
		{
			if(pri_lru[i][f]== -1)
			{
				printf("  - |");
			}
			else
		   		printf(" %2d |",pri_lru[i][f]);
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
		if(x_lru[i]=='X')
		{
			//printf("\033[0;31m");
			printf(" %2c |",x_lru[i]);
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %2c |",x_lru[i]);
		}
	}
		
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{
		printf("-");
	}
    printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,(no_of_pages-page_faults_lru),page_faults_lru);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults_lru,(no_of_pages-page_faults_lru));

    
    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults_lru,no_of_pages,((float)page_faults_lru/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",(no_of_pages-page_faults_lru),no_of_pages,((float)no_of_pages-page_faults_lru)/no_of_pages);
    
    
    
    //op
    
    printf("\n................Optimal Page Replacement................\n\n");
    for(i = 0; i < no_of_pages; ++i)
	{
		flag1 = flag2 = 0;

		for(j = 0; j < frame_size; ++j)
		{
		    if(frames_op[j] == pages[i])
			{
			   flag1 = flag2 = 1;
			   x_op[i]='*';
			   break;
		    }
		}	

		if(flag1 == 0)
		{
		    for(j = 0; j < frame_size; ++j)
			{
				if(frames_op[j] == -1)
				{
			   		page_faults_op++;
			   		//x[j]='*';
			    	frames_op[j] = pages[i];
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
				    if(frames_op[j] == pages[k])
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

	   		frames_op[pos] = pages[i];
	    	page_faults_op++;
		}	

		for(j = 0; j < frame_size; j++)
		{
		    pri_op[j][i]=frames_op[j];
		}
    }
    
    display();
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
			if(pri_op[i][j]== -1)
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
		if(x_op[i]=='X')
		{
			//printf("\033[0;31m");
			printf(" %2c |",x_op[i]);
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %2c |",x_op[i]);
		}
	}
	//printf("\033[0m")
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{	
		printf("-");
	}
	
	hit_op = no_of_pages-page_faults_op;
	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,hit_op,page_faults_op);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults_op,hit_op);


    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults_op,no_of_pages,((float)page_faults_op/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",(no_of_pages-page_faults_op),no_of_pages,((float) hit_op)/no_of_pages);
    
    
    
    
    //LFU
    
    printf("\n...........LFU Page Replacement algorithm...........\n\n");printf("\n");
    for(m = 0; m < no_of_pages; m++)
    {
        arr[pages[m]]++;
        time_lfu[pages[m]] = m;
        flag1 = 1;
        k = frames_lfu[0];
        for(n = 0; n < frame_size; n++)
        {
            if(frames_lfu[n] == -1 || frames_lfu[n] == pages[m])
            {
                if(frames_lfu[n] != -1)
                {
                    hit_lfu++;
                    x_lfu[m]='*';
                }
                flag1 = 0;
                frames_lfu[n] = pages[m];
                
                break;
            }
            if(arr[k] > arr[frames_lfu[n]])
            {
            	k = frames_lfu[n];
            }
        }
            if(flag1)
            {
                minimum_time = 25;
                for(n = 0; n < frame_size; n++)
                {
                	if(arr[frames_lfu[n]] == arr[k] && time_lfu[frames_lfu[n]] < minimum_time)
                    {
                    	temp_lfu = n;
                        minimum_time = time_lfu[frames_lfu[n]];
                    }
                }
                arr[frames_lfu[temp_lfu]] = 0;
                frames_lfu[temp_lfu] = pages[m];
            }
            
            for(n=0; n < frame_size ; n++)
            {
            	pri_lfu[n][m] = frames_lfu[n];
			}
            
    }
    
    display();
    for(m=0; m < frame_size ; m++ )
    {
    	printf("| %2d",m);
      		printf("\t|");
		for(j = 0; j < no_of_pages; j++)
		{
			if(pri_lfu[m][j]== -1)
			{
				printf("  - |");
			}
			else
		    printf(" %2d |",pri_lfu[m][j]);
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
		if(x_lfu[i]=='X')
		{
			//printf("\033[0;31m");
			printf(" %2c |",x_lfu[i]);
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %2c |",x_lfu[i]);
		}
	}
	//printf("\033[0m");
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{	
		printf("-");
	}
	
	page_faults_lfu= no_of_pages - hit_lfu;
	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,hit_lfu,page_faults_lfu);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults_lfu,hit_lfu);

    
    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults_lfu,no_of_pages,((float)page_faults_lfu/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",hit_lfu,no_of_pages,((float)hit_lfu)/no_of_pages);
    
    
    
    //MFU
    printf("\n...........MFU Page Replacement algorithm..........\n\n");
    for(i = 0; i < no_of_pages ; i++)
    {
	    flag1 = 0;
	    
	    for(n = 0; n < frame_size ; n++)
	    {
		  if(pages[i] == frames_mfu[n])
		  {
			flag1++;
			page_faults_mfu--;
			hit_mfu++;
			x_mfu[i]='*';
		  }
	    }
	    page_faults_mfu++;
	    
	    
	    
	    if((page_faults_mfu <= frame_size) && (flag1 == 0))
	    {
		  frames_mfu[s++] = pages[i];
	    }
	    else if(flag1 == 0)
	    {
			for(m=0; m < frame_size; m++)
	    	{
	    		if(frames_mfu[m]==pages[i-1])
	    		{
	    			target=m;
	    			break;
				}
			}
			frames_mfu[target]=pages[i];
	   }
	    
		for(k=0; k <frame_size ; k++)
		{ 
			pri_mfu[k][i]=frames_mfu[k];
		}
    }
    
    display();
    
    for(m=0; m < frame_size ; m++ )
    {
    	printf("| %2d",m);
      		printf("\t|");
		for(j = 0; j < no_of_pages; j++)
		{
			if(pri_mfu[m][j]== -1)
			{
				printf("  - |");
			}
			else
		    printf(" %2d |",pri_mfu[m][j]);
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
		if(x_mfu[i]=='X')
		{
			//printf("\033[0;31m");
			printf(" %2c |",x_mfu[i]);
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %2c |",x_mfu[i]);
		}
	}
	//printf("\033[0m");
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{	
		printf("-");
	}
	
	page_faults_mfu= no_of_pages - hit_mfu;
	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,hit_mfu,page_faults_mfu);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults_mfu,hit_mfu);

    
    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults_mfu,no_of_pages,((float)page_faults_mfu/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",hit_mfu,no_of_pages,((float)hit_mfu)/no_of_pages);
    
	s=0;
	//SECOND CHANCE
	printf("\n................Second Chance Page Replacement................\n\n");
	for(i = 0; i < no_of_pages ; i++)
    {
	    flag = 0;
	    
	    for(n = 0; n < frame_size ; n++)
	    {
		  if(pages[i] == frames_sec[n])
		  {
			flag++;
			page_faults_sec--;
			hit_sec++;
			x_sec[i]='*';
			r_bit[n]++;
		  }
	    }
	    page_faults_sec++;
	    
	    
	    
	    if((page_faults_sec <= frame_size) && (flag == 0))
	    {
		  frames_sec[s++] = pages[i];
		  flag++;
	    }
	    else if(flag == 0)
	    {
			if(r_bit[victim]==0)
			{
				victim++; 

			}
			else
			{
				r_bit[victim]=0;
				victim++;
				
			}
			//frame[ (victim) % frame_size] = pages[i];			
			
			if(victim > 11)
			{
				victim = 0;
			}
			
			frames_sec[ victim % frame_size]=pages[i];
		}
		for(k=0; k <frame_size ; k++)
		{ 
			pri_sec[k][i]=frames_sec[k];
		}
    }
	
	display();
    for(m=0; m < frame_size ; m++ )
    {
    	printf("| %2d",m);
      		printf("\t|");
		for(j = 0; j < no_of_pages; j++)
		{
			if(pri_sec[m][j]== -1)
			{
				printf("  - |");
			}
			else
		    printf(" %2d |",pri_sec[m][j]);
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
			printf(" %2c |",x_sec[i]);
		}
		else
		{
			//printf("\033[0;32m");
			printf(" %2c |",x_sec[i]);
		}
	}
	//printf("\033[0m");
	printf("\n");
	for(i = 0 ; i < no_of_pages*5+2*frame_size+3; i ++)
	{	
		printf("-");
	}
	
	page_faults_sec= no_of_pages - hit_sec;
	printf("\n\nPage Faults, given by: No of pages - Pages hits\nSo here :  %d - %d =\t%d\n\n", no_of_pages,hit_sec,page_faults_sec);
    printf("\nPage Hits , given by: No of pages - Pages Miss\nSo here :  %d - %d =\t%d\n\n", no_of_pages,page_faults_sec,hit_sec);

    
    printf("\nPage Fault ratio, given by: Page faults/Total pages \nSo here : %d / %d =\t%5.2f\n\n",page_faults_sec,no_of_pages,((float)page_faults_sec/no_of_pages));
    printf("\nPage Hit ratio, given by: Page hits/Total pages \nSo here : %d / %d =\t%5.2f\n\n",hit_sec,no_of_pages,((float)hit_sec)/no_of_pages);
    

	
	return 0;		

}





void display()
{
	for(i = 0 ; i < no_of_pages*5+2*frame_size+2; i ++)
	{
		printf("-");
	}
	printf("\n|Frames |");
	
	for(i=0; i<= 2*no_of_pages + 6; i++)
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
