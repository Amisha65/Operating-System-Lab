#include <stdio.h>
#include <limits.h>

struct process
{
    int pid;
    int bt;
    int art;
};

void wating_time(struct process proc[],int n, int wt[])
{
    int rt[n];
    
    for(int i=0;i<n;i++)
        rt[i]=proc[i].bt;
    
    int comp=0, t=0, shortt=0,  final_time;
    int minm=INT_MAX;
    int cheak=0;
    
    while(n!=comp)
    {
        for(int i=0;i<n;i++)
        {
            if((proc[i].art<=t) && (rt[i]<minm) && (rt[i]>0))
            {
                minm=rt[i];
                shortt=i;
                cheak=1;
            }
        }
        
        if(cheak==0)
        {
            t++;
            continue;
        }
        
        rt[shortt]--;
        minm=rt[shortt];
        
        if(minm==0)
            minm=INT_MAX;
            
        if(rt[shortt]==0)
        {
            comp++;
            cheak=0;
            
            final_time=t+1;
            
            wt[shortt]=final_time-proc[shortt].bt-proc[shortt].art;
            
            if(wt[shortt]<0)
                wt[shortt]=0;
        }
        t++;
    }
}

void turn_around_time(struct process proc[], int n, int wt[], int tat[])
{
    for(int i=0;i<n;i++)
        tat[i]=proc[i].bt+wt[i];
}

void find_avg(struct process proc[], int n)
{
    int tat[n], total_tat=0;
    int wt[n], total_wt=0;
    
    wating_time(proc,n,wt);
    
    turn_around_time(proc,n,wt,tat);
    
     printf("P\t\tArt\t\tBT\t\tWT\t\tTAT\n");
     
     for(int i=0;i<n;i++)
     {
         total_wt=total_wt+wt[i];
         total_tat=total_tat+tat[i];
         printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].art, proc[i].bt, wt[i], tat[i]);
     }
     
     printf("\nAverage of wating time: %f\n", (float)total_wt/(float)n);
     printf("Average of TAT: %f\n", (float)total_tat/(float)n);
}

int main() 
{
    struct process proc[] = { {1, 6, 2}, {2, 2, 5}, {3, 8, 1}, {4, 3, 0}, {5, 4, 4} };
    int n = sizeof(proc) / sizeof(proc[0]);
    
    find_avg(proc, n);
}


// OUTPUT-
// P		Art		BT		WT		TAT
// 1		2		6		7		13
// 2		5		2		0		2
// 3		1		8		14		22
// 4		0		3		0		3
// 5		4		4		2		6

// Average of wating time: 4.600000
// Average of TAT: 9.200000

