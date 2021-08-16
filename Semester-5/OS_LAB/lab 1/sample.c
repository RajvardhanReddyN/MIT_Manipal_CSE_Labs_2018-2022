#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
 
int main()
{
    char c;
    int in, out;
  char buffer[128];
  int nread;
  in=open("sample.txt",O_RDWR);
    nread=read(in,buffer,128);
  printf("File Content is : %sand Number of characters are = %d\n",buffer, nread);
    exit(0);
 
}