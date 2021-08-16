#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main()
{
	char pwd[256];
	if(!getcwd(pwd, sizeof(pwd)))
		printf("Directory name exceeds size of buffer or is removed or permissions are changed.");
	DIR *dp;
	struct dirent *entry;
	struct stat fileStat;
	if((dp = opendir(pwd))==NULL)
		printf("Can not open directory.");
	else
	{
		while((entry = readdir(dp))!=NULL)
		{
			if(strcmp(".", entry->d_name)==0 || strcmp("..", entry->d_name)==0 || entry->d_name[0]=='.') continue;
			else
			{
				printf("%s\t", entry->d_name);
				 lstat(entry->d_name, &fileStat); 
				printf((S_ISDIR(fileStat.st_mode))  ? "d" : "-");
				printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
				printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
				printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
				printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
				printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
				printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
				printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
				printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
				printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
				printf("\t%d",fileStat.st_size);
              	printf("\t%s",ctime(&fileStat.st_ctime));
			}
		}
		closedir(dp);
	}
	return 0;
}