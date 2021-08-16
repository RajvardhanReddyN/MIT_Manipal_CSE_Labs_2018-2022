#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
FILE *fp,*fp2;
char filename[100], c;
printf("Enter the filename to open for reading: \n");
scanf("%s", filename);
fp = fopen(filename, "r");
if (fp == NULL)
{
printf("Cannot open file %s \n", filename);
exit(0);
}
printf("Enter the filename to open for writing: \n");
scanf("%s", filename);
fp2 = fopen(filename, "w+");
fseek(fp, 0, SEEK_END);
int f1Size = ftell(fp);
printf("Size of file: %d bytes\n", f1Size);
fseek(fp, f1Size-1, SEEK_SET);
fseek(fp2, 0, SEEK_SET);
for (int i = 0; i < f1Size-1; i++)
{
c = fgetc(fp);
if (c == EOF)
{
printf("Breaking: %d\n", i);
break;
}
fputc(c, fp2);
fseek(fp, f1Size-(i+2), SEEK_SET);
}
printf("File content reversed and stored in destination.\n");
fclose(fp);
fclose(fp2);
return 0;
}