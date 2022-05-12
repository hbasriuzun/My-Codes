#include <stdio.h>
#include <stdlib.h>
typedef struct{
int x;
int y;
}cartesian;

typedef struct{
    cartesian centerel_point;
    int radius;
}circle;

int area_of_a_circle(circle a) {
    int area = a.radius * a.radius * 3;
    return area;
}
int circumference(circle b){
 int c = 2 * b.radius * 3;
return c;
}
void point_s_inside_or_outside(circle b){
    int x,y;
    printf("Enter the point x and y");
    scanf("%d%d",&x,&y);
    if (b.centerel_point.x > x && b.centerel_point.y > y)
    {
        printf("\nthe point is inside");
    }
    else
    {
        printf("\nthe point in outside");
    }
}
int main(void)
{
circle circle1;
int i;
printf("Enter the cartesian of circle and radius.");
scanf("%d%d%d",&circle1.centerel_point.x,&circle1.centerel_point.y,&circle1.radius);

printf("\nArea of circle is %d",area_of_a_circle(circle1));
printf("\nircumference of circle is %d",circumference(circle1));
printf("\nFind the point inside or outside");
point_s_inside_or_outside(circle1);

return 0;
}
4 options (A,B,C,D) to answer. Each correct question has 1 points and four incorrect questions eliminates 1 point. Write a C program that reads the answer key as a string and the number and answers of 3 students, then prints each student’s number and grade. Use an appropriate struct.