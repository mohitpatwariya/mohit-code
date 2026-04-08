#include <GL/glut.h> 
#include <bits/stdc++.h> 
using namespace std; 
int points[4][2] = {{200, 300},{300, 200},{400, 300},{500, 200}}; 
void init() 
{ 
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-0.0, 500.0, 0.0, 500.0); 
} 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 0.0, 0.0); 
    glLineWidth(3.0); 
    glBegin(GL_LINE_STRIP); 
    for (int i = 0; i < 4; i++) 
    { 
        glVertex2i(points[i][0], points[i][1]); 
    } 
    glEnd(); 
    glFlush(); 
} 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(300, 300); 
    glutCreateWindow("Lines"); 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
  return 0 ;
}