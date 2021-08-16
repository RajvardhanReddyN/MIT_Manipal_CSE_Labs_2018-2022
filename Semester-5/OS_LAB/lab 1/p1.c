#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
 
    int sfd,i=0,k=0;
    char ch[100],chr;
 
  if(argc!=3)
  {
        printf("Insufficient Arguments\n");
        exit(1);
    }
 
  if( (sfd=open(argv[2],O_RDONLY))==-1)
  {
        printf("File not found\n");
        exit(1);
    }
 
  // printf("File Contents=%s and Number of characters are=%d",buffer, nread);
    while((read(sfd,&chr,1))>0)
  {
        if(chr!='\n')
    {
            ch[i]=chr;
            i++;
 
        }
 
    else
    {
            k++;
            ch[i]='\0';
            i=0;
            if(strstr(ch,argv[1])!=NULL){
                printf("Line:%d \t %s \n", k,ch);
            }
        }
    }
 
    exit(0);
 
}