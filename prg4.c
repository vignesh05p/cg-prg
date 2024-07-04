//Lab2: rotate a triangle about the origin and a fixed point
#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
int x=100,y=100; //fixed points
int rFlag=0;
float th=0.0;
void draw_pixel(float x1,float y1)
{
glColor3f(0.0,0.0,1.0);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2f(x1,y1);
glEnd();
}
void triangle()
{
glBegin(GL_POLYGON);
glVertex2f(100,100);
glVertex2f(100,400);
glVertex2f(300,100);
glEnd();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glLoadIdentity();
glColor3f(1.0,1.0,0.0);
triangle(); //original triangle
if(rFlag==1) //Rotate Around origin
{
draw_pixel(0.0,0.0); //draw origin
glRotatef(th,0.0,0.0,1.0);
glColor3f(1.0,0.0,0.0);
triangle(); //rotated triangle
}
if(rFlag==2) //Rotate Around Fixed Point
{
draw_pixel(x,y);//draw fixed point
glTranslatef(x,y,0.0);
glRotatef(th,0.0,0.0,1.0);
glTranslatef(-x,-y,0.0);
glColor3f(0.0,1.0,0.0);
triangle(); //rotated triangle
}
glutPostRedisplay();
glutSwapBuffers();
}
void myInit()
{
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
glMatrixMode(GL_MODELVIEW);
}
void rotateMenu (int option)
{
if(option==1)
rFlag=1;
if(option==2)
rFlag=2;
if(option==3)
rFlag=3;
}
int main(int argc, char **argv)
{
printf("\nEnter the rotation angle\n");
scanf("%f",&th);
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(500, 500);
glutInitWindowPosition(0, 0);
glutCreateWindow("Create and Rotate Triangle");
myInit();
glutDisplayFunc(display);
glutCreateMenu(rotateMenu);
glutAddMenuEntry("Rotate around ORIGIN",1);
glutAddMenuEntry("Rotate around FIXED POINT",2);
glutAddMenuEntry("Stop Rotation",3);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
return 0;
}
