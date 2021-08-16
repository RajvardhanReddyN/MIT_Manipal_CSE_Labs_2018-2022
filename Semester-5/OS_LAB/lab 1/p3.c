#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
// extern int errno;
 
int main()
{
    int a=81;
    float b=9.1;
    char c='p';
    char str[]="OS Lab";
  printf("a=%d b=%f c=%c str=%s hexadecimal for a=%x \n",a,b,c,str,a);
    errno=EPERM;
    printf("Error Access Errno= %m\n");
}