#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define Buffer_size 5

void *producer(void *t_no);
void *consumer(void *t_no);

pthread_mutex_t m;
int c=0, in=0, out=0, a[Buffer_size];

sem_t full,empty;

int main()
{
    int i,p,c_cnt;
    pthread_t pth[10],cth[10];
    int prod_num[10],cons_num[10];
    
    pthread_mutex_init(&m,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,Buffer_size);
    
    printf("\nEnter the number of producers: ");
    scanf("%d",&p);
    printf("\nEnter the number of consumer: ");
    scanf("%d",&c_cnt);
    
    for(i=0;i<p;i++)
    {
        prod_num[i]=i+1;
        pthread_create(&pth[i], NULL, producer, &prod_num[i]);
    }
    
    for(i=0;i<c_cnt;i++)
    {
        cons_num[i]=i+1;
        pthread_create(&cth[i], NULL, consumer, &cons_num[i]);
    }
    
    for(i=0; i<p;i++)
    {
        pthread_join(pth[i], NULL);
    }
    
    for(i=0;i<c_cnt;i++)
    {
        pthread_join(cth[i], NULL);
    }
    
    pthread_mutex_destroy(&m);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}

void *producer(void *t_no)
{
    int th_no=*(int*)t_no;
    
    while(1)
    {
        sem_wait(&empty);
        pthread_mutex_lock(&m);
        
        if(c>=Buffer_size)
            printf("Buffer size");
        else
        {
            a[in]=rand()%10;
            printf("\nProducer %d produces %d",th_no, a[in]);
            in=(in+1) % Buffer_size;
            c++;
        }
        
        pthread_mutex_unlock(&m);
        sem_post(&full);
        sleep(1);
    }
    pthread_exit(0);
}

void *consumer(void *t_no)
{
    int th_no=*(int *)t_no;
    
    while(1)
    {
        sem_wait(&full);
        pthread_mutex_lock(&m);
        
        if(c<=0)
            printf("Empty Buffer");
        else
        {
            int item=a[out];
            printf("\nConsumer %d consumed: %d ",th_no,item);
            out=(out+1)%Buffer_size;
            c--;
        }
        
        pthread_mutex_unlock(&m);
        sem_post(&empty);
        sleep(1);
    }
    pthread_exit(0);
}


// OUTPUT:
// Enter the number of producers: 2
// Enter the number of consumer: 4

// Producer 1 produces 3
// Producer 2 produces 6
// Consumer 1 consumed: 3 
// Consumer 2 consumed: 6 
// Producer 1 produces 7
// Consumer 3 consumed: 7 
// Producer 2 produces 5
// Consumer 4 consumed: 5 
// Producer 1 produces 3
// Consumer 1 consumed: 3 
// Producer 2 produces 5
// Consumer 2 consumed: 5

