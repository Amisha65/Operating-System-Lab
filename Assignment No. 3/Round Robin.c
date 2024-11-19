#include <stdio.h>
int main()
{
    int cnt,j,time;
    int flag=0;
    int wait_time=0, tat=0;
    int at[10], bt[10], rt[10];
    
    int n;
    printf("Enter Total Process: ");
    scanf("%d", &n);
    
    int remain=n;
    
    for(int i=0;i<n;i++)
    {
        printf("\nEnter AT and BT for process no. %d: ", i+1);
        scanf("%d", &at[i]);
        scanf("%d", &bt[i]);
        
        rt[i]=bt[i];
    }
    
    int time_quantum;
    printf("\nEnter Time Quantum: ");
    scanf("%d", &time_quantum);
    
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    
    for(time=0,cnt=0; remain!=0;)
    {
        if(rt[cnt]<=time_quantum && rt[cnt]>0)
        {
            time+=rt[cnt];
            rt[cnt]=0;
            flag=1;
        }
        else if(rt[cnt]>0)
        {
            rt[cnt]-=time_quantum;
            time+=time_quantum;
        }
        
        if(rt[cnt]==0 && flag==1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", cnt+1, time-at[cnt], time-at[cnt]-bt[cnt]);
            
            wait_time+=time-at[cnt]-bt[cnt];
            tat+=time-at[cnt];
            
            flag=0;
        }
        
        if(cnt==n-1)
            cnt=0;
        else if(at[cnt+1]<=time)
            cnt++;
        else
            cnt=0;
    } 
    
    printf("\nAverage wating time: %f", wait_time*1.0/n);
    printf("\nAverage Turnaround Time: %f", tat*1.0/n);
}



// OUTPUT-
// Enter Total Process: 3
// Enter AT and BT for process no. 1: 2 6
// Enter AT and BT for process no. 2: 3 4
// Enter AT and BT for process no. 3: 1 5
// Enter Time Quantum: 2

// Process |Turnaround Time|Waiting Time

// P[1]    |       8       |       2
// P[2]    |       9       |       5
// P[3]    |       14      |       9

// Average wating time: 5.333333
// Average Turnaround Time: 10.333333

