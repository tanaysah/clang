#include <stdio.h>
int main()
{ 
 int s1,s2,s3;
 printf("Enter the first side of triangle:");
 scanf("%d",&s1);
 printf("Enter the second side of triangle:");
 scanf("%d",&s2);
 printf("Enter the third side of triangle:");
 scanf("%d",&s3);

 if(s1+s2>s3 && s1+s3>s2 && s2+s3>s1)
 {
  printf("The triangle is valid \n");
 }
 else
 {
  printf("The triangle is not valid \n");
 }
 if("s1==s2 && s2==s3")
 {
  printf("The triangle is isoceles\n");
 }
 else if(s1==s2 || s2==s3 || s1==s3)
 {
  printf("The triangle is equilateral \n");
 }
 else
 
  printf("The triangle is scalene\n");
  
 if(s1*s1 + s2*s2 == s3*s3 || s1*s1 + s3*s3 == s2*s2 || s2*s2 + s3*s3 == s1*s1)
 {
  printf("The triangle is right-angled \n");
 }
 else
 {
  printf("The triangle is not right-angled \n");
  return 0;
 }
}
