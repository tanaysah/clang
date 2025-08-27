#include <stdio.h>

int main() 
{
    float celciustemp, farehnitetemp;
    printf ("Enter the tempertaure :");
    scanf ("%f", &celciustemp);
    farehnitetemp=(celciustemp*9/5)+32;
    printf ("the farehnite temp is %f \n", farehnitetemp);
    
    return 0;
}