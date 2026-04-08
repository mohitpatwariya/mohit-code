#include <GL/glut.h>
#include <vector>
using namespace std;

vector<pair<int,int>> p;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
    for(int i=0;i+1<p.size();i+=2)
    {
        glVertex2i(p[i].first, p[i].second);
        glVertex2i(p[i+1].first, p[i+1].second);
    }
    glEnd();

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
    glutCreateWindow("Multi Line");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
