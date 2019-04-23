#include <fcntl.h>
#include<sys/type.h>
#include<sys/stat.h>
#include <stdio.h>
#include<errno.h> 
extern int errno;


void creatFile (const char* fileName)
{
    // if file does not have in directory  
    // then file foo.txt is created. 
    int fd = creat(filename, S_IRUSR | S_IWUSR);  
      
    printf("fd = %d/n", fd); 
      
    if (fd ==-1) 
    { 
         perror("creat() error");                 
    } 
}

void openFile (const char* fileName)
{
    // if file does not have in directory  
    // then file foo.txt is created. 
    int fd = open(filename, O_RDONLY | O_CREAT);  
      
    printf("fd = %d/n", fd); 
      
    if (fd ==-1) 
    { 
        // print which type of error have in a code 
        printf("Error Number % d\n", errno);  
          
        // print program detail "Success or failure" 
        perror("Program");                  
    } 
}

void closeFile (const char* fileName)
{
   int fd1 = open(filename, O_RDONLY); 
    if (fd1 < 0)  
    { 
        perror("c1"); 
        exit(1); 
    } 
    printf("opened the fd = % d\n", fd1); 
      
    // Using close system Call 
    if (close(fd1) < 0)  
    { 
        perror("c1"); 
        exit(1); 
    }  
    printf("closed the fd.\n"); 
}




int main ()
{
   const char fileName [] = "anc.txt";
   creatFile(fileName);
   openFile (fileName);
   closeFile (fileName);
   return 0;
}
