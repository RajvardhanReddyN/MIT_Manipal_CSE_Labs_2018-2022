#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
FILE *fp;
char filename[100], c;
int lines = 0;
int characters = 0;
printf("Enter the filename to open for reading: \n");
scanf("%s", filename);
fp = fopen(filename, "r");
if (fp == NULL)
{
printf("Cannot open file %s \n", filename);
exit(0);
}
c = fgetc(fp);
while (c != EOF)
{
characters++;
if (c == '\n')
{
lines++;
}
c = fgetc(fp);
}
printf("Total characters: %d\n", characters);
printf("Total lines: %d\n", lines);
fclose(fp);
return 0;
}