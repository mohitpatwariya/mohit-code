#include <GL/glut.h>
#include <vector>
using namespace std;

vector<pair<int,int>> p;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(p.size() > 1)
    {
        glBegin(GL_LINE_LOOP);
        for(int i=0;i<p.size();i++)
        {
            glVertex2i(p[i].first, p[i].second);
        }
        glEnd();
    }

    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        p.push_back({x, 500-y});
        glutPostRedisplay();
    }
}

void init()
{
    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    gluOrtho2D(0,500,0,500);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Closed Shape");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}