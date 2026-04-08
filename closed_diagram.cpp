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

int main(int argc,char** argv)
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        p.push_back({x,y});
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Closed Shape");

    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    gluOrtho2D(0,500,0,500);

    glutDisplayFunc(display);
    glutMainLoop();
}