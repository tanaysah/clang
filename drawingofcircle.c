#include <stdio.h>
#include <math.h>

int main(void) 
{
    int r;
    printf("radius (in px): ");
    if (scanf("%d", &r) != 1 || r <= 0) return 0;

    const double stroke = 3.0;
    const int margin = (int)(stroke * 4) + 8;
    const int cx = r + margin;
    const int cy = r + margin;
    const int W  = 2 * r + 2 * margin;
    const int H  = 2 * r + 2 * margin;


    printf("----- COPY BELOW THIS LINE -----\n");
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n", W, H, W, H);
    printf("  <rect width=\"100%%\" height=\"100%%\" fill=\"white\"/>\n");
    printf("  <circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"none\" stroke=\"black\" stroke-width=\"%.2f\"/>\n", cx, cy, r, stroke);
    printf("</svg>\n");
    printf("----- COPY ABOVE THIS LINE -----\n");

    return 0;
}
