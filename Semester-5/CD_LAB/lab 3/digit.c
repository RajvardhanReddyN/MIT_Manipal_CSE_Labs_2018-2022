#include <stdio.h>
int main(int argc, char const *argv[])
{
    int a[100],b=0,c=0,i=0;
    for(i=0;i<100;i++){
        a[i] = i+1;
    }
    for (i=0;i<100;i++){
        if(a[i]%2==0){
            b+=a[i];
        }
        else c+=a[i];
    }
    printf("The even and odd sums of first 100 natural numbers are: %d, %d\n",b,c);
    return 0;
}