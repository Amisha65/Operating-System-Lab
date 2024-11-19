#include<stdio.h>
int absoluteValue(int); 

void main()
{
    int queue[25],headposition;
    int n,i,j,k;
    int seek=0, maxrange,difference,temp;
    int queue1[20],queue2[20];
    int temp1=0,temp2=0;
    float averageSeekTime;

    printf("Enter the maximum range of Disk: ");
    scanf("%d",&maxrange);
    
    printf("Enter the number of queue requests: ");
    scanf("%d",&n);
    
    printf("Enter the initial head position: ");
    scanf("%d",&headposition);
    
    printf("Enter the disk positions to be read(queue): ");
    for(i=1;i<=n;i++)   
    {
        scanf("%d",&temp);  
        
        if(temp>headposition)
        {
            queue1[temp1]=temp; 
            temp1++; 
        }
        else    
        {   
            queue2[temp2]=temp; 
            temp2++;
        }
    }
    
    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    
    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(queue2[i]>queue2[j])
            {
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }    
    
    for(i=1,j=0;j<temp1;i++,j++)
    {
        queue[i]=queue1[j]; 
    }
    
    queue[i]=queue2[0]; 
    
    for(i=temp1+1,j=0;j<temp2;i++,j++)
    {
        queue[i]=queue2[j];
    }

    queue[0]=headposition;
    
    for(j=0; j<n; j++)
    {   
        difference = absoluteValue(queue[j+1]-queue[j]);
    
        seek = seek + difference;
        
        printf("Disk head moves from position %d to %d with Seek %d \n", 
        queue[j], queue[j+1], difference);
    }
    
    averageSeekTime = seek/(float)n;
    
    printf("Total Seek Time= %d\n", seek);
    printf("Average Seek Time= %f\n", averageSeekTime);
}

int absoluteValue(int x)
{
    if(x>0)
    {
        return x;
    }
    else
    {
        return x*-1;
    }
}


// Enter the Size: 199
// Enter the No: 7
// Enter the Initial Head: 50
// Enter seq: 82 170 43 140 24 16 190
// Head DIsk moves from 50 to the 82 with seek 32
// Head DIsk moves from 82 to the 140 with seek 58
// Head DIsk moves from 140 to the 170 with seek 30
// Head DIsk moves from 170 to the 190 with seek 20
// Head DIsk moves from 190 to the 16 with seek 174
// Head DIsk moves from 16 to the 24 with seek 8
// Head DIsk moves from 24 to the 43 with seek 19

// Total seek: 341
// Avg seek: 48.714287
