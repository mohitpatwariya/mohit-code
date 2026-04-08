#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(4.0);

    glBegin(GL_POINTS);
    for (int i = 0; i < v.size(); i++)
        glVertex2i(v[i].first, v[i].second);
    glEnd();

    glFlush();
}

void bresenhamline(int x0, int y0, int x1, int y1)
{
    float dx = x1 - x0;
    float dy = y1 - y0;
    float p = 2 * dy - dx;

    int x = x0, y = y0;
    int count = 0;

    while (x <= x1)
    {
        if (count % 5 == 0)
        {
            cout << "(" << x << " , " << y << ")" << endl;
            v.push_back({x, y});
        }

        if (p < 0)
            p = p + 2 * dy;
        else
        {
            y++;
            p = p + 2 * dy - 2 * dx;
        }

        x++;
        count++;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line");

    init();
    bresenhamline(2, 3, 180, 180);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}