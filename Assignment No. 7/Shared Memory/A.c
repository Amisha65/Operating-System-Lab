#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    void *shared_mem;
    int buff[100];
    
    int shmId;
    shmId=shmget((key_t)2345,1024,IPC_CREAT);
    
    printf("The key of the shared segment: %d",shmId);
    
    shared_mem=shmat(shmId,NULL,0);
    printf("The process attached at: %p",shared_mem);
    
    printf("Write the some data to the shared memory: ");
    
    read(0,buf,100);
    crtcpy=(shared_mem,buf);
    printf("the Data: ",(char*)shared_mem);
    
    
}



