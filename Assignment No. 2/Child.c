#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void rev(int arr[],int n)
{
       	 for(int i=0;i<n-1;i++)
       	 {
       	        	 for(int j=0;j<n-i-1;j++)
       	        	 {
       	        	        	 int temp=arr[j+1];
       	        	        	 arr[j+1]=arr[j];
       	        	        	 arr[j]=temp;
       	        	 }
       	 }
}
int main(int argc, char *argv[])
{
       	 int n=argc-1;
       	 int arr[n];

       	 for(int i=0;i<n;i++)
       	 {
       	        	 arr[i]=atoi(argv[i+1]); //converts the argument from a string to an integer
       	 }

       	 printf("\nThe array which is passed to the Child: \n");
       	 for(int i=0;i<n;i++)
       	 {
       	        	 printf("%d ",arr[i]);
       	 }
       	 printf("\n");

       	 rev(arr,n);

       	 printf("The reversed array: \n");
       	 for(int i=0;i<n;i++)
       	 {
       	        	 printf("%d ",arr[i]);
       	 }
       	 printf("\n");
} 

//  OUTPUT:

// admin1@SL16:~$ gcc -o parent  parent.c
// admin1@SL16:~$ gcc -o child child.c
// admin1@SL16:~$ ./parent

// Enter the how many numbers: 5
// Enter the numbers: 2 99 5 8 44

// Sorted array: 2 5 8 44 99

// The array which is passed to the Child:
// 2 5 8 44 99
// The reversed array:
// 99 44 8 5 2
