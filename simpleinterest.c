#include <stdio.h>
int main()
{
float principle, rate, time, simpleInterest;
printf("Enter : your loan principle amount");
scanf("%f",&principle);
printf("Enter : your loan rate of interest");
scanf("%f",&rate);
printf("Enter : your loan time in years");
scanf("%f",&time);
simpleInterest = (principle * rate * time) / 100;
printf("Your simple interest is : %f\n", simpleInterest);
return 0;   

}