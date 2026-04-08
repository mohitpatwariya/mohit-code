#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(4,4,8, 0,0,0, 0,1,0);

    glColor3f(0,1,1);

    glBegin(GL_LINE_LOOP);
        glVertex3f(-2,-1,1);
        glVertex3f(2,-1,1);
        glVertex3f(2,1,1);
        glVertex3f(-2,1,1);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(-2,-1,-1);
        glVertex3f(2,-1,-1);
        glVertex3f(2,1,-1);
        glVertex3f(-2,1,-1);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-2,-1,1); glVertex3f(-2,-1,-1);
        glVertex3f(2,-1,1);  glVertex3f(2,-1,-1);
        glVertex3f(2,1,1);   glVertex3f(2,1,-1);
        glVertex3f(-2,1,1);  glVertex3f(-2,1,-1);
    glEnd();

    glutSwapBuffers();
}

void init()
{
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,1,100);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Cuboid");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}