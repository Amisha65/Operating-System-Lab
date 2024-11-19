#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void sor(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j+1]<arr[j])
   			{
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}

int main()
{
	printf("Enter the how many numbers: ");
	int n;
	scanf("%d",&n);

	printf("Enter the numbers: ");
	int arr[n];

	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	sor(arr, n);
	printf("\nSorted array: ");
        	for (int i = 0; i < n; i++)
	{
        		printf("%d ", arr[i]);
        	}
        	printf("\n");
       
       	pid_t pid=fork();
       
       	 if(pid==0)
        	{
        		char* args[n+2];
        		args[0]="./child";
       
        		for(int i=0;i<n;i++)
       	 	{
        			args[i+1]=malloc(10);
        			sprintf(args[i+1],"%d",arr[i]);
        		}
        		args[n+1]=NULL;
       
        		execve(args[0],args,NULL);
       
       		 perror("execve");
        		exit(1);
       	 }
        	else
        		wait(NULL);
}

