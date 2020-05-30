#include <stdio.h>

struct process
{
	int pid; int btime; int pri; int wtime; int ttime;
} p[10], temp;

int main()
{
	int i,j,k,n,ttur,twat;
	float awat,atur,cpu_util,totaltime,throughput;

	printf("Enter no. of process : ");
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		printf("Burst time for process P%d (in ms) : ", (i+1));
		scanf("%d", &p[i].btime);
		p[i].pid = i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("Priority for process P%d : ", (i+1));
		scanf("%d", &p[i].pri);
	}

	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if((p[i].pri > p[j].pri) || (p[i].pri == p[j].pri && p[i].pid > p[j].pid) )
			{
				temp = p[i]; p[i] = p[j]; p[j] = temp;
			}

		}
	}
	
	p[0].wtime = 0;
	for(i=0; i<n; i++)
	{
		p[i+1].wtime = p[i].wtime + p[i].btime;
		p[i].ttime = p[i].wtime + p[i].btime;
	}

	ttur = twat = 0;
	for(i=0; i<n; i++)
	{
		ttur += p[i].ttime;
		twat += p[i].wtime;
		totaltime += p[i].btime;
	}


	printf("\n\nGANTT Chart\n");
	printf("-");
	for(i=1; i<n*8+2; i++)
	{
		printf("-");		 	 	 
	}
	printf("\n|");
	for(i=0; i<n; i++)
	{	
		k = p[i].btime/2;
		printf(" P%d\t",p[i].pid);
		printf("|");
	}
	printf("\n-");
	for(i=1; i<n*8+2; i++)
	{
		printf("-");		 	 	 
	}
	printf("\n0");
	for(i=0; i<n; i++)
		{
			printf("	%d",p[i].ttime);
		}
		
	awat = (float)twat / n;
	atur = (float)ttur / n;

	printf("\n\t Priority Scheduling\n\n");
	for(i=0; i<=65; i++)
	{
		printf("-");
	}
	printf("\nTime   Process  Priority   T-Time=         W-Time=               |\n");
	printf("     	 name               t(PC)-t(PS)    T.T - T(Process time) |\n");
	for(i=0; i<=65; i++)
	{
	printf("-");
	}
	printf("\n 0   |     -   |   -    |       -       |              -         |");
	printf("\n------------------------------------------------------------------");
	for (i=0; i<n; i++)
	{	
		printf("\n %2d  |    P%-2d  |  %2d    |       %-2d      | \t%8d\t |",p[i].btime,p[i].pid,p[i].pri,p[i].ttime,p[i].wtime);
		printf("\n------------------------------------------------------------------");
	}
/*	for(i=0; i<=65; i++)
	{
		printf("-");
	}	
*/		printf("\n");
	
	printf("\n\nAverage waiting time given by: total waiting time / no. of processes \nSo here:  ");
	for(i=1; i<=n; i++)
	{
		printf("%d",p[i].wtime);
		for(j=0; j<n-1; j++) 
		{
			printf("+");
			break;
		}
	}
	printf("/ %d = %5.2f ms \n",n,awat);

	printf("\n\nAverage Turn-around time given by: total turn-around time / no. of processes \nSo here:  ");
	for(i=1; i<=n; i++)
	{
		printf("%d",p[i].ttime);
		for(j=0; j<n-1; j++) 
		{
			printf("+");
			break;
		}
	}
	printf("/ %d = %5.2f ms \n",n,atur);
	
	cpu_util= ( totaltime/ (totaltime + 0)  ) * 100;
	printf("\n\nCPU utilization, given by: (cpu busy time)/(cpu busytime+ idle time) \nSo here it is %5.2f / (%5.2f + 0) = %d\n\n",totaltime,totaltime, cpu_util);
	throughput= n/ ( totaltime); 
	printf("\nThroughput, given by:  No. of Processes/ Totaltime,\nSo here it is:  %d / %5.2f = %5.2f  processes per ms",n,totaltime,throughput);
	
return 1;
}



