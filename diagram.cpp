#include <GL/glut.h>
#include <cmath>

void drawCircle(float xc, float yc, float r)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < 360; i++)
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

    // Head
    drawCircle(-100, 100, 30);

    // Body
    glBegin(GL_LINES);

    // Neck to body
    glVertex2i(-100, 70);
    glVertex2i(-100, 0);

    // Left hand
    glVertex2i(-100, 50);
    glVertex2i(-140, 20);

    // Right hand
    glVertex2i(-100, 50);
    glVertex2i(-60, 20);

    // Left leg
    glVertex2i(-100, 0);
    glVertex2i(-140, -50);

    // Right leg
    glVertex2i(-100, 0);
    glVertex2i(-60, -50);

    glEnd();

    // Square
    glBegin(GL_LINE_LOOP);
        glVertex2i(50, 100);
        glVertex2i(150, 100);
        glVertex2i(150, 0);
        glVertex2i(50, 0);
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1,1,1,1);
    glColor3f(0,0,0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250,250,-250,250);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Stick Man + Square");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}