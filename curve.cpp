#include <GL/glut.h>
#include <cmath>

// S-shape curve (ONLY ONE S)
float curveY(float x)
{
    return 80 * sin(x * 0.01);  // slow → ek hi S banega
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // FIRST CURVE (S shape)
    glColor3f(0.0, 0.0, 0.0); // black
    glBegin(GL_LINE_STRIP);
    for (float x = -150; x <= 150; x += 1)
    {
        float y = curveY(x);
        glVertex2f(x, y);
    }
    glEnd();

    // SECOND CURVE (parallel)
    glColor3f(1.0, 0.0, 0.0); // red
    glBegin(GL_LINE_STRIP);
    for (float x = -150; x <= 150; x += 1)
    {
        float y = curveY(x) + 30; // gap
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-200, 200, -200, 200);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Single S Curve Parallel");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}