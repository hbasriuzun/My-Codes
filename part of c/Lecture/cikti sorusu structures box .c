#include <stdio.h>
#include <stdlib.h>
struct box {
int width;
int length;
};
void f1(int *a,int *b) {
*a = *a-1;
*b = *b+3;
}
struct box f2(struct box b){
b.width = b.width + 2;
b.length = b.length - 3;
return b;
}
int main(void)
{
struct box box1;
int i;
box1.width=6;
box1.length=2;
for(i=0;i<5;++i) {
if (box1.width>box1.length)
f1(&box1.width,&box1.length);
else
box1=f2(box1);
printf("%3d%3d\n",box1.width,box1.length);
}
return 0;
}