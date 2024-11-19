
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

//func to implement bubblesort
void bubblesort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;i<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
        }

        
    }
}
//func to imple selection sort
void selectionsort(int arr[],int n)
{
    int i,j,mid,temp;
    for(i=0;i<n-1;i++)
    {
        mid=i;
        for(j= i+1;j<n;j++)
        {
            if(arr[j]<arr[mid])
            {
                mid=j;
            }
        }    
        temp=arr[mid];
        arr[mid]=arr[i];
        arr[i]=temp;
        
    }
}
void printarray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
}

int main()
{
    int arr[10],n,i;
    pid_t pid;

    //accepting int frm user
    printf("enter no of elements: ");
    scanf("%d",&n);
    printf("Enter the int: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",arr[i]);
    }

    //creating child pro
    pid=fork();

    if(pid==0)//child process
    {
        printf("***Child process:SElectionsort ***\n");
        printf("Child process id:PID=%d \n",getpid());

        //simulating orphan stage by sleeping to allow the parent to terminate
        
        sleep(5);
        printf("Child pro parent id after becoming orphan:PPID =%d\n",getppid());
        selctionsort(arr,n);
        printarray(arr,n);
    }
    else if(pid>0)//parent process
    {
        printf("***parent process:bubblesort ***\n");
        wait(NULL); //wait for the child pro to complete
        printf("parent process:child pro finished\n");
        printf("parent process id:PID=%d\n",getpid());
        bubblesort(arr,n);
        printarray(arr,n);

    }
    return 0;
}


//output:

// Enter number of elements: 5
// Enter the int: 3 1 4 1 5
// ***parent process:bubblesort ***
// parent process:child pro finished
// parent process id:PID=35543
// ***Child process:SElectionsort ***
// Child Process id: PID = 35544
// Child Pro parent id after becoming orphan:  PPID = 1
