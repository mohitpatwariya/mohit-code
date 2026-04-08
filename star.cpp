#include <GL/glut.h> 
#include <bits/stdc++.h> 
using namespace std; 
vector<pair<int, int>> points = {{250, 400}, {290, 300}, {400, 300}, {310, 
240},  
{350, 140}, {250, 200}, {150, 140}, {190, 240}, {100, 300}, {210, 300}}; 
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
    glLineWidth(3.0); 
    glBegin(GL_LINE_LOOP); 
    for (int i = 0; i < points.size(); i++) 
    { 
        glVertex2i(points[i].first, points[i].second); 
    } 
    glEnd(); 
    glFlush(); 
} 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(300, 300); 
    glutCreateWindow("Star"); 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0;
}
