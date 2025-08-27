#include <stdio.h>
int main()
{ 
    float bmi, weight, height;
    printf("Enter weight in kg: ");
    scanf("%f", &weight);
    printf("Enter height in cm: ");
    scanf("%f", &height);
    bmi=(weight)/(height*height);
    printf("BMI is: %f\n", bmi);
    if(bmi<15)
    printf("Starvation");
    else if(bmi>=15.1 && bmi<17.5)
    printf("Anorexic");
    else if(bmi>=17.6 && bmi<18.5)
    printf("Underweight");
    else if(bmi>=18.6 && bmi<24.9)
    printf("Ideal");
    else if(bmi>=25.0 && bmi<25.9)
    printf("Overweight");
    else if(bmi>=30.0 && bmi<39.9)
    printf("Obese");
    else if(bmi>=40.0)
    printf("Morbidly Obese");
    return 0;
}