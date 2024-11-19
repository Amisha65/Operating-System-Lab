#include<stdio.h>
#include<stdbool.h>

int request[50];
long SIZE;
bool flag[50];
int dist(int,int);

struct max {
        int data;
        int dis;
        int dat; 
    }kate[50],kat;

struct max check(int head,int n)
{
    int i;
    int j=0;
    for(i=0;i<n;i++)
    {
        if(flag[i]==0)
        {
            kate[j].dis=dist(head,request[i]);
            kate[j].data=request[i];
            kate[j].dat=i;
            j++;
        }
    }

    n=j;
    for (i = 0; i < n-1; i++)      
    {     
        for (j = 0; j < n-i-1; j++) 
        {
            if (kate[j].dis > kate[j+1].dis)
            {
                int temp=kate[j].data;
                kate[j].data=kate[j+1].data;
                kate[j+1].data=temp;
        
                temp=kate[j].dis;
                kate[j].dis=kate[j+1].dis;
                kate[j+1].dis=temp;
                
                temp=kate[j].dat;
                kate[j].dat=kate[j+1].dat;
                kate[j+1].dat=temp;
            }
        }
    }
    return kate[0];
}

int dist(int a,int b)
{
    if(a>b)
        return a-b;
    return b-a;
}

void stsk(int n)
{
    int head,i;
    int seekcount=0;
    
    printf("ENTER THE CURRENT HEAD :\n");
    scanf("%d",&head);
    
    printf("SEEK SEQUENCE = ")	;
    for(i=0;i<n;i++)
    {
        if(request[i]<SIZE-1)
        {
            printf("%d ",head);
            kat=check(head,n);	
            
            seekcount=seekcount+kat.dis;
            
            head=kat.data;
            
            flag[kat.dat]=true;
        }
    }
    printf("%d\nTOTAL DISTANCE : %d",head,seekcount);	
}

int main()
{
    int n,i;
    printf("ENTER THE DISK SIZE :\n");
    scanf("%ld",&SIZE);
    
    printf("ENTER THE NO OF REQUEST SEQUENCE :\n");
    scanf("%d",&n);
    
    printf("ENTER THE REQUEST SEQUENCE :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&request[i]);
        flag[i]=0;
    }
    
    stsk(n);
}


