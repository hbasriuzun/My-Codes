#include <stdio.h>
#include <string.h>
typedef struct {
    int grade;
    int number;
    char exam_solution[10];
}student;

int main()
{
    student a,b,c;
    a.number = 100;
    b.number = 101;
    c.number = 102;
    int i,count=0;
    char exam_answer_key[10] = {'A','C','D','B','D','C','A','D','C','B','\0'};
    
    printf("\nEnter the student a answer");
    for ( i = 0; i < 10; i++)
    {
        scanf("%c",&a.exam_solution[i]);
        if (a.exam_solution[i] == exam_answer_key[i])
        {
            a.grade++;
        }
        else
        {
            count++;
            if (count == 4)
            {
                a.grade--;
                count=0;
            }
            
        }
    }
    printf("\nStudent who is number %d is grade %d",a.number,a.grade);
    count = 0;
    printf("\nEnter the student b answer");
    for ( i = 0; i < 10; i++)
    {
        scanf("%c",&a.exam_solution[i]);
        if (b.exam_solution[i] == exam_answer_key[i])
        {
            b.grade++;
        }
        else
        {
            count++;
            if (count == 4)
            {
                b.grade--;
                count=0;
            }
            
        }
    }
    printf("\nStudent who is number %d is grade %d",b.number,b.grade);
    count = 0;
    printf("\nEnter the student c answer");
    for ( i = 0; i < 10; i++)
    {
        scanf("%c",&c.exam_solution[i]);
        if (c.exam_solution[i] == exam_answer_key[i])
        {
            c.grade++;
        }
        else
        {
            count++;
            if (count == 4)
            {
                c.grade--;
                count=0;
            }
            
        }
    }
    printf("\nStudent who is number %d is grade %d",c.number,c.grade);
    

    
    return 0;
}