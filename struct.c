#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

struct myData
{
    int age;
    char *name;
    int year;
    char course[10];
    struct birthdate
    {
        int day;
        int month;
        int year;
    } bdate;
};

void printmyData(struct myData stud);

int main()
{
    static struct myData student[3];
    student[0].age = 17;
    student[0].name = "Misha";
    student[0].year = 2024;
    mystrcpy(student[0].course, "PX-24");
    student[0].bdate.day = 18;
    student[0].bdate.month = 8;
    student[0].bdate.year = 2001;

    student[1].age = 18;
    student[1].name = "Zhytomer";
    student[1].year = 2024;
    mystrcpy(student[1].course, "PX-24");
    student[1].bdate.day = 20;
    student[1].bdate.month = 9;
    student[1].bdate.year = 2000;

    student[2].age = 19;
    student[2].name = "Gosha";
    student[2].year = 2024;
    mystrcpy(student[2].course, "PX-24");
    student[2].bdate.day = 25;
    student[2].bdate.month = 12;
    student[2].bdate.year = 2002;


    int min, mid, max;
    minmax(student[0].bdate.year, student[1].bdate.year, student[2].bdate.year, &min, &mid, &max);

    printf("Students: \n");
    for (int i = 0; i < 3; i++)
    {
        
        printmyData(student[i]);
    }

    printf("Sorted students by birth date: \n");
    printmyData(student[max]);
    printmyData(student[mid]);
    printmyData(student[min]);


    char decision;
    printf("Do you want to enter new students? (y/n):");
    scanf(" %c", &decision);
    if (decision == 'y')
    {
        int n;
        printf("\nEnter how many students you want add:");
        scanf("%d", &n);
        n += 3;
        struct myData *studentnew = malloc(n * sizeof(struct myData));
        for(int i = 0; i < 3; i++)
        {
            studentnew[i] = student[i];
        }
        printf("enter student data in format: age name year course day month birthyear:\n");
        for (int i = 3; i < n; i++)
        {
            scanf("%d %s %d %s %d %d %d", studentnew[i].age, studentnew[i].name, studentnew[i].year, studentnew[i].course, studentnew[i].bdate.day, studentnew[i].bdate.month, studentnew[i].bdate.year);
        }
        printf("new students structure: \n");
        for(int i = 0; i < n; i++)
        {
            printmyData(studentnew[i]);
        }
        
    }


    return 0;
}

void printmyData(struct myData stud)
{
    printf("Age: %d\nName: %s\nYear: %d\nCourse: %s\nBirthdate: %d/%d/%d\n\n",
           stud.age, stud.name, stud.year, stud.course,
           stud.bdate.day, stud.bdate.month, stud.bdate.year);
}
