#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

const char *keywords[33] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register", "typedef", "char", "extern", "return", "union", "continue", "for", "signed", "void", "do", "if", "static", "while", "default", "goto", "sizeof", "volatile", "const", "float", "short", "unsigned", "printf"};

int isKeyword (char *word)
{
    for (int i=0; i<33; i++)
    {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main (int argc, const char * argv [])
{
    printf("Enter file name: ");
    char input[256];
    scanf("%s",input);
    FILE *f = fopen(input, "r");
    if (f == NULL)
    {
        printf("Cannot open file\n");
        exit(0); 
    }

    char buffer[1024];
    const char delimiters[] = " .,;:!?-_(){}[]\n\t";

    while (fgets(buffer, 1024, f))
    {
        char *cp = (char *)malloc(1024 * sizeof(char));
        strcpy(cp, buffer);
            
        char *token = (char *)malloc(256 * sizeof(char));

        while((token = strsep(&cp, delimiters)))
        {
            if(isKeyword(token))
            {
                for (int i=0; i<strlen(token); i++)
                    printf("%c", toupper(token[i]));
                printf("\n");
            }
        }
    }
    fclose(f);
    return 0;
}