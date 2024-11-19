#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd,fd1;
    char buf[521];
    	
    char *myfifo="myfifo";
    char *myfifo1="myfifo1";
    
    mkfifo(myfifo,0666);
    mkfifo(myfifo1,0777);
    
    fd=open(myfifo,O_WRONLY);
        write(fd,"Hello Frinds \nghd ",1024);
        printf("The data wrote in FIFO1 by writer");
    close(fd);
    unlink(myfifo);
    
    fd1=open(myfifo1, O_RDONLY);
        read(fd1,buf,sizeof(buf));
        printf("The data read in FIFO2 by writer");
        printf("%s",buf);
    close(fd1);
    unlink(myfifo1);
    
    return 0;
}


#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd,fd1;
    char buf[512], ch[512];
    FILE *ft;
    
    int word=1,lines=1, i=0;
    
    char *myfifo="myfifo";
    char *myfifo1="myfifo1";
    
    mkfifo(myfifo1,0777);
      
    fd=open(myfifo,O_RDONLY);
        read(fd,buf,1024);
        printf("The data read in FIFO1 by reader: \n\s\n",buf);
        sleep(2);
        
        while(buf[i]!='\0')
        {
            if(buf[i]==' ')
                word++;
            else if(buf[i]=='\n')
                lines++;
            i++;
        }
        
        printf("The analysed data: ");
        printf("Total words: %d",word);
        printf("Total lines: %d",lines);
        printf("Total character: %d",i);
        sleep(2);
        
        ft=fopen("test.txt","w")
            fprintf(ft,"Total words: %d",word);
            fprintf(ft,"Total lines: %d",lines);
            fprintf(ft,"Total character: %d",i);
        fclose(ft);
        printf("the analyed data writen in the test file");
        
        sleep(2);
        i=0;    
        ft=fopen("test.txt","r");
            while(!feof(ft))
            {
                ch[i++]=fgetc(ft);
            }
        fclose(ft);
     
    close(fd);
    unlink(myfifo);  
    
    
    fd1=open(myfifo1,O_WRONLY);
        write(fd1,ch,sizeof(ch));
        printf("the data write by fifo2 by reader");
        sleep(2);
    close(fd);
    
    return 0;
}
