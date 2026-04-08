#include <GL/glut.h>
#include <cmath>

void drawCircle(float xc, float yc, float r)
{
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++)
    {
        float theta = i * 3.1416 / 180;
        float x = r * cos(theta);
        float y = r * sin(theta);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    float xc = 0, yc = 0, r = 50;

    drawCircle(xc, yc, r);

    glBegin(GL_LINES);
    for(int i=0;i<360;i+=30)
    {
        float theta = i * 3.1416 / 180;

        float x1 = xc + r * cos(theta);
        float y1 = yc + r * sin(theta);

        float x2 = xc + (r+50) * cos(theta);
        float y2 = yc + (r+50) * sin(theta);

        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
    }
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-200,200,-200,200);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Sun Shape");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}