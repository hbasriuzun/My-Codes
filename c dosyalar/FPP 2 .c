#include <stdio.h>
#include <stdlib.h>
main()
{
char ch;
int k;
FILE *f;
f = fopen("FOF.txt", "r");
if(f==NULL) {
puts("The file could not be opened.");
exit(1);
}
fseek(f, 0, SEEK_END);
printf("The size of data in the file is %d. (Excluding EOF)\n", ftell(f));

fseek(f, 0, SEEK_SET);
printf("%c\n", fgetc(f) );

fseek(f, 3, SEEK_SET);
printf("%c\n", fgetc(f) );

fseek(f, 1, SEEK_CUR);
printf("%c\n", fgetc(f) );

fseek(f, -1, SEEK_END);
printf("%c\n", fgetc(f) );

fclose(f);
return 0;
}