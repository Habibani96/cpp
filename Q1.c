//First come First Serve or also known as SJF
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void waiting_completion(int wt[],int br_time[],int n,int comp[],int tot[])
{
	int i;
	comp[0]=br_time[0]-1;
	wt[0]=0;
	wt[1]=br_time[0];
	//Waiting Time
	for(i=2;i<n;i++)
	{
		wt[i]=wt[i-1]+br_time[i-1];
	}
	//Completion Time
	for(i=1;i<n;i++)
	{
		comp[i]=comp[i-1]+br_time[i];
	}
	//Turn Around Time
	for(i=0;i<n;i++)
	{
		tot[i]=comp[i]-wt[i];
	}
}
//Calculates Average time
void calc_avg(int temp[],int n)
{
	int i;float avg=0;
	for(i=0;i<n;i++)
	{
		avg+=temp[i];
	}
	avg=avg/n;
	printf("%f",avg);
}
int main()
{
	int no;
	printf("Enter the number of processes you want to enter : ");
	scanf("%d",&no);
	int br_time[no],i,waitin[no],comp[no],tot[no];
	for(i=0;i<no;i++)
	{
		printf("Enter Burst Time for Process # %d : ",i+1);
		scanf("%d",&br_time[i]);
		if(br_time[i]<0)
			i--;
	}
	waiting_completion(waitin,br_time,no,comp,tot);
	printf("Burst Time\tWaiting\t\tCompletion\tTurn Around Time");
	for(i=0;i<no;i++)
	{
	 	printf("\n%d\t\t%d\t\t%d\t\t%d",br_time[i],waitin[i],comp[i],tot[i]);

	}
	printf("\nAverage Waiting : ");
	calc_avg(waitin,no);
	printf("\nAverage Turn Around : ");
	calc_avg(tot,no);
	printf("\n\n");
	return 0;
}

