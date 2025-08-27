#include <stdio.h>
#include <math.h>

// Rotation (degrees)
#define AX  25.0   // tilt around X (latitude curves)
#define AZ  20.0   // spin around Z (longitude curves)

static void move_to(double x, double y) { printf("M %.2f %.2f ", x, y); }
static void line_to(double x, double y) { printf("L %.2f %.2f ", x, y); }

// projection: apply Rz(az) then Rx(ax)
void project_point(double x, double y, double z,
                   double *X, double *Y, double *Zr,
                   double caz, double saz, double cax, double sax,
                   int cx, int cy) {
    // rotate around Z
    double x1 =  x*caz - y*saz;
    double y1 =  x*saz + y*caz;
    double z1 =  z;
    // rotate around X
    double x2 =  x1;
    double y2 =  y1*cax - z1*sax;
    double z2 =  y1*sax + z1*cax;
    *X = cx + x2;
    *Y = cy - y2;
    if (Zr) *Zr = z2;
}

int main(void) {
    int r;
    printf("radius (in px): ");
    if (scanf("%d", &r) != 1 || r <= 0) return 0;

    const int margin = (int)(r * 0.7) + 30;
    const int cx = r + margin;
    const int cy = r + margin;
    const int W  = 2 * r + 2 * margin;
    const int H  = 2 * r + 2 * margin;

    const int n_lat = 8;
    const int n_lon = 12;
    const int samples = 240;

    const double PI = acos(-1.0);
    const double ax = AX * PI / 180.0;
    const double az = AZ * PI / 180.0;
    const double cax = cos(ax), sax = sin(ax);
    const double caz = cos(az), saz = sin(az);

    // shadow ellipse
    double shadow_cy = cy + r * 0.65;
    double shadow_rx = r * 0.95;
    double shadow_ry = r * 0.28;

    printf("----- COPY BELOW THIS LINE -----\n");
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    printf("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"%d\" height=\"%d\" viewBox=\"0 0 %d %d\">\n", W, H, W, H);

    // defs: style
    printf("<defs>\n");
    printf("  <style><![CDATA[\n");
    printf("    .front { stroke:#1f2950; stroke-opacity:0.85; stroke-width:1.2; fill:none; }\n");
    printf("    .back  { stroke:#2b365a; stroke-opacity:0.25; stroke-width:1.0; fill:none; }\n");
    printf("  ]]></style>\n");
    printf("</defs>\n");

    printf("<rect width=\"100%%\" height=\"100%%\" fill=\"#ffffff\"/>\n");
    printf("<ellipse cx=\"%d\" cy=\"%.2f\" rx=\"%.2f\" ry=\"%.2f\" fill=\"#000\" fill-opacity=\"0.16\"/>\n",
           cx, shadow_cy, shadow_rx, shadow_ry);

    // Sphere outline
    printf("<circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"#d0d8ff\" stroke=\"#26314f\" stroke-width=\"1.2\"/>\n",
           cx, cy, r);

    // Latitude lines
    for (int i = 1; i <= n_lat; ++i) {
        double theta = (PI * i) / (n_lat + 1);
        double z = r * cos(theta);
        double sinth = sin(theta);

        // front
        printf("<path class=\"front\" d=\"");
        int started = 0;
        for (int s = 0; s <= samples; ++s) {
            double phi = (2.0 * PI * s) / samples;
            double x = r * sinth * cos(phi);
            double y = r * sinth * sin(phi);
            double X,Y,Zr;
            project_point(x,y,z,&X,&Y,&Zr,caz,saz,cax,sax,cx,cy);
            if (Zr >= 0) { if (!started){ move_to(X,Y); started=1; } else { line_to(X,Y);} }
        }
        printf("\"/>\n");

        // back
        printf("<path class=\"back\" d=\"");
        started = 0;
        for (int s = 0; s <= samples; ++s) {
            double phi = (2.0 * PI * s) / samples;
            double x = r * sinth * cos(phi);
            double y = r * sinth * sin(phi);
            double X,Y,Zr;
            project_point(x,y,z,&X,&Y,&Zr,caz,saz,cax,sax,cx,cy);
            if (Zr < 0) { if (!started){ move_to(X,Y); started=1; } else { line_to(X,Y);} }
        }
        printf("\"/>\n");
    }

    // Longitude lines
    for (int j = 0; j < n_lon; ++j) {
        double phi = (2.0 * PI * j) / n_lon;
        double cphi = cos(phi), sphi = sin(phi);

        // front
        printf("<path class=\"front\" d=\"");
        int started = 0;
        for (int s = 0; s <= samples; ++s) {
            double theta = (PI * s) / samples;
            double x = r * sin(theta) * cphi;
            double y = r * sin(theta) * sphi;
            double z = r * cos(theta);
            double X,Y,Zr;
            project_point(x,y,z,&X,&Y,&Zr,caz,saz,cax,sax,cx,cy);
            if (Zr >= 0) { if (!started){ move_to(X,Y); started=1; } else { line_to(X,Y);} }
        }
        printf("\"/>\n");

        // back
        printf("<path class=\"back\" d=\"");
        started = 0;
        for (int s = 0; s <= samples; ++s) {
            double theta = (PI * s) / samples;
            double x = r * sin(theta) * cphi;
            double y = r * sin(theta) * sphi;
            double z = r * cos(theta);
            double X,Y,Zr;
            project_point(x,y,z,&X,&Y,&Zr,caz,saz,cax,sax,cx,cy);
            if (Zr < 0) { if (!started){ move_to(X,Y); started=1; } else { line_to(X,Y);} }
        }
        printf("\"/>\n");
    }

    printf("</svg>\n");
    printf("----- COPY ABOVE THIS LINE -----\n");
    return 0;
}