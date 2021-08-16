#include <stdlib.h>
#include <stdio.h>

int main()
{
	FILE *fa, *fb;
	char input[256];
	printf("Enter file name: ");
	scanf("%s",input);
	fa = fopen(input, "r");
	fb = fopen("output.txt", "w");
	if(fa==NULL || fb==NULL) printf("Invalid files\n");
	else
	{
		int c;
		while((c = getc(fa))!=EOF)
		{
			if(c==' ' || c=='\t') 
			{
				while(c==' ' || c=='\t') c= getc(fa);
				putc(' ',fb);
			}
			putc(c,fb);
		}
		fclose(fa);
		fclose(fb);
	}
	return 0;
}