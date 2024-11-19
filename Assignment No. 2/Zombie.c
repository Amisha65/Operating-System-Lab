zombie:
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

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process with PID: %d\n", getpid());
        exit(0); // Child process exits
    } else {
        // Parent process
        printf("Parent process with PID: %d\n", getpid());

        // Sleep for some time to keep the parent alive and allow child to become a zombie
        sleep(10);

        // Now the parent waits for the child to prevent it from being a zombie forever
        wait(NULL);
    }

    return 0;
}


//output:

// Parent process with PID: 3465
// Child process with PID: 3466
