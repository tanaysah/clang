
// for calcualting division of a studetn based on the marks of 5 differnt subjects. 

#include <stdio.h>
int main()
{
    float science, math, english, hindi, computer;
    float total, percentage;
    printf("marks of science:");
    scanf("%f", &science);
    if (science < 0 || science > 100)
    {
        printf("ienter marks below 100");
        return 0;
    }
    printf("marks of math:");
    scanf("%f", &math);
    if (math < 0 || math > 100)
    {
        printf("enter marks below 100");
        return 0;
    }
    printf("marks of english:");
    scanf("%f", &english);
    if (english < 0 || english > 100)
    {
        printf("enter marks below 100");
        return 0;
    }
    printf("marks of hindi:");
    scanf("%f", &hindi);
    if (hindi < 0 || hindi > 100)
    {
        printf("enter marks below 100");
        return 0;
    }
    printf("marks of computer science:");
    scanf("%f", &computer);
    if (computer < 0 || computer > 100)
    {
        printf("enter marks below 100");
        return 0;
    }
    total = science + math + english + hindi + computer;
    percentage = (total / 500) * 100;
    
      printf("percentage is %f\n", percentage);
    
    if (percentage >= 80)
    {
        printf("first division\n");
    }
    else if (percentage >= 60 || percentage <= 79)
    {
        printf("second division\n");
    }
    else if (percentage >= 40 || percentage <= 59)
    {
        printf("third division\n");
    }
    else
    {
        printf("fail");
    }
return 0;


}