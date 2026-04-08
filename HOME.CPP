#include <GL/glut.h>
#include <cmath>
void init()
{
    glClearColor(1, 1, 1, 1);        // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);      // 2D coordinate system
}

void display()
{
    float xc = 250, yc = 250, r = 100; //circle 1
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0);              // black lines
    glLineWidth(2);

    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; i++)
    {
        float theta = i * 3.1416 / 180;
        float x = r * cos(theta);
        float y = r * sin(theta);

        glVertex2f(xc + x, yc + y);
    }
    glEnd();

      xc = 300, yc = 300, r = 100;   //circle 2
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < 360; i++)
    {
        float theta = i * 3.1416 / 180;
        float x = r * cos(theta);
        float y = r * sin(theta);

        glVertex2f(xc + x, yc + y);
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2i(100,300);
     glVertex2i(200,360);
      glVertex2i(300,300);
     
       glEnd();
    //BOUNDARY
    glBegin(GL_LINE_LOOP);
    glVertex2i(100,100);
     glVertex2i(300,100);
      glVertex2i(300,300);
       glVertex2i(100,300);
       glEnd();

       glFlush();
}
int main (int argc,char** argv)
{
    glutInit(&argc ,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
     glutInitWindowPosition(100,100);
     glutCreateWindow("simple scence");
     init();
     glutDisplayFunc(display);
     glutMainLoop();
     return 0;
}
     

