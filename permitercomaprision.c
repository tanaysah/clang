#include <stdio.h>
int main()
{
    int rectangle1, rectangle2, rectangle3;
    int width1, width2, width3;
    int length1, length2, length3;
    int permiter1, permiter2, permiter3;
    printf("Enter the length ofrectangle 1: ");
    scanf("%d", &length1);
    printf("Enter the width of rectangle 1: ");
    scanf("%d", &width1);
    permiter1 = 2 * (length1+width1);
    printf("The perimeter of rectangle 1 is: %d\n", permiter1);
    printf("Enter the length of rectangle 2: ");
    scanf("%d", &length2);
    printf("Enter the width of rectangle 2: ");
    scanf("%d", &width2);
    permiter2 = 2 * (length2+width2);
    printf("The perimeter of rectangle 2 is: %d\n", permiter2);
    printf("Enter the length of rectangle 3: ");
    scanf("%d", &length3);
    printf("Enter the width of rectangle 3: ");
    scanf("%d", &width3);
    permiter3 = 2 * (length3+width3);
    printf("The perimeter of rectangle 3 is: %d\n", permiter3);

    if (permiter1 > permiter2 && permiter1 > permiter3)
    {
        printf("Rectangle 1 has the largest perimeter: %d\n", permiter1);
    }
    else if (permiter2 > permiter1 && permiter2 > permiter3)
    {
        printf("Rectangle 2 has the largest perimeter: %d\n", permiter2);
    }
    else
    {
        printf("Rectangle 3 has the largest perimeter: %d\n", permiter3);
    }
    return 0;
}