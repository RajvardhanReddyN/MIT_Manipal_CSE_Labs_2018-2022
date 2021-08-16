
#include <stdio.h>
void main()
{
FILE *fopen(), *fp;
int c ;
fp = fopen( “prog.c”, “r” ); 12c = getc( fp ) ;
while ( c
!=
EOF )
{
putchar( c );
c = getc ( fp );
}

fclose(
fp );
}