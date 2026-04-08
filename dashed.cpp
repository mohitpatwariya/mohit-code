#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> p;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i=0;i<p.size()-1;i++)
    {
        int x1=p[i].first, y1=p[i].second;
        int x2=p[i+1].first, y2=p[i+1].second;

        int dx=x2-x1, dy=y2-y1;
        int step=max(abs(dx),abs(dy));

        float x=x1, y=y1;
        float xin=dx/(float)step, yin=dy/(float)step;

        glBegin(GL_POINTS);
        for(int j=0;j<=step;j++)
        {
            if(j%10 < 6)
                glVertex2i(round(x),round(y));
            x+=xin; y+=yin;
        }
        glEnd();
    }

    glFlush();
}

int main(int argc,char** argv)
{
    int n; cin>>n;
    while(n--)
    {
        int x,y; cin>>x>>y;
        p.push_back({x,y});
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Dashed");

    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    glPointSize(3);
    gluOrtho2D(0,500,0,500);

    glutDisplayFunc(display);
    glutMainLoop();
}
/*
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    glBegin(GL_LINES);
        glVertex2i(50,100);
        glVertex2i(450,100);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Dashed Line");

    glClearColor(0,0,0,1);
    glColor3f(1,1,1);
    gluOrtho2D(0,500,0,500);

    glutDisplayFunc(display);
    glutMainLoop();
} */