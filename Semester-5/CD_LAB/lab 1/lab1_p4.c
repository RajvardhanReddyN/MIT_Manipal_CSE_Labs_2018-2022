#include <stdio.h>
#include <stdlib.h> // For exit()
int main()
{
FILE *f1,*f2,*f3;
char fn1[100], fn2[100], fn3[100], c;
printf("Enter the file1, file2, file3 : \n");
scanf("%s", fn1);
scanf("%s", fn2);
scanf("%s", fn3);
f1 = fopen(fn1, "r");
f2 = fopen(fn2, "r");
f3 = fopen(fn3, "w+");
if (f1 == NULL || f2 == NULL)
{
printf("Cannot open files.\n");
exit(0);
}
char ch1, ch2;
ch1 = ch2 = 'a';
while (1)
{
if (ch1 != EOF)
{
ch1 = fgetc(f1);
while (ch1 != '\n')
{
if (ch1 == EOF)
break;
fputc(ch1, f3);
ch1 = fgetc(f1);
}
fputc('\n', f3);
}
if (ch2 != EOF)
{
ch2 = fgetc(f2);
while (ch2 != '\n')
{
if (ch2 == EOF)
break;
fputc(ch2, f3);
ch2 = fgetc(f2);
}
fputc('\n', f3);
}
if (ch1 == EOF && ch2 == EOF)
break;
}
printf("Done");
fclose(f1);
fclose(f2);
fclose(f3);
return 0;
}