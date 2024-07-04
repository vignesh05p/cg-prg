// Lab1: Bresenham's Line Drawing
#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
int x1, y1, x2, y2; // line endpoints
void myInit()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(-500, 500, -500, 500);
}
void draw_pixel(int x, int y)
{
glBegin(GL_POINTS);
glVertex2i(x, y); //Plot Pixel
glEnd();
}
void draw_line(int x1, int x2, int y1, int y2)
{
int dx, dy, i, e,m;
int incx, incy, inc1, inc2;
int x,y;
dx = x2-x1; 
dy = y2-y1;
m=dy/dx;
printf("Slope m=%d",m);
if (dx < 0) dx = -dx; 
if (dy < 0) dy = -dy; 
incx = 1;
if (x2 < x1) incx = -1; //for -ve slope
incy = 1;
if (y2 < y1) incy = -1; //for -ve slope
x = x1; y = y1;
if (dx > dy) //For a line with positive slope less than 1.0
{
draw_pixel(x, y); //plot starting point
e = 2 * dy-dx; //Initial decision variable p0=2 Δy - Δx
inc1 = 2*(dy-dx); //Calculate constant 2Δy - 2Δx
inc2 = 2*dy; //Calculate constant 2Δy
for (i=0; i<dx; i++)
{
if (e >= 0) 
{
y += incy;
e += inc1;
}
else //If pk < 0, the next point to plot is (xk+1, yk) and pk+1=pk+2Δy
{
e += inc2;
}
x += incx;
draw_pixel(x, y); //plot new point
} // endfor
} //endif
else //For a line with positive slope greater than 1.0, interchange the roles of the x and y
//directions.
{
draw_pixel(x, y);
e = 2*dx-dy;
inc1 = 2*(dx-dy);
inc2 = 2*dx;
for (i=0; i<dy; i++)
{
if (e >= 0)
{
x += incx;
e += inc1;
}
else
{
e += inc2;
}
y += incy;
draw_pixel(x, y); //plot new point
}//endfor
}//endelse
}//end draw_line
void myDisplay()
{
draw_line(x1, x2, y1, y2);
glFlush();
}
int main(int argc, char **argv)
{
printf( "Enter (x1, y1, x2, y2)\n");
scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Bresenham's Line Drawing");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}