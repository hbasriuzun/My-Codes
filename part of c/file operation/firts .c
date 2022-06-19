#include <stdio.h>
#include <stdlib.h>
main()
{
unsigned int account; // account number
char name[ 30 ]; // account name
double balance; // account balance
FILE *cfPtr;
cfPtr = fopen( "clients.txt", "r" );
if (cfPtr == NULL ) {
puts( "File could not be opened" );
exit(1);
printf( "%-10s%-13s%s\n", "Account", "Name", "Balance");
fscanf( cfPtr, "%d %29s %lf", &account, name, &balance);
while (!feof(cfPtr)) {
printf("%-10d%-13s%7.2f\n", account, name, balance);
fscanf(cfPtr, "%d %29s %lf", &account, name, &balance);
}
fclose(cfPtr);
return 0;
}