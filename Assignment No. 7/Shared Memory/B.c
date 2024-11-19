#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

int main()
{
    void *shared_memory;
    int buff[100];
    
    int shmId;
    
    shmId=shmget((key_t)2345,1024,0666|IPC_CREAT);
    
    printf("Key of the shared segment: %d",shmId);
    
    shared_memory=shmat(shmIdm,Null,0);
    
    printf("the address atached at: %p/n",shared_memory);
    
    printf("the data already written: ", (char*)shared_memory);
    
}
  