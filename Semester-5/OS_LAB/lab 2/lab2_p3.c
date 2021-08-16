#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char* argv[])
{
    DIR *dp = opendir(argv[1]);
    struct dirent *entry;

    while((entry = readdir(dp)) != NULL) 
    {   
        if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) continue;      
        printf("%s\n", entry->d_name);
    }
    closedir(dp);
}