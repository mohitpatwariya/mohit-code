#include <GL/glut.h> 
#include <bits/stdc++.h> 
using namespace std; 
void dda(int x1, int y1, int x2, int y2) 
{ 
    int dx = x2 - x1; 
    int dy = y2 - y1; 
    int step = max(abs(dx), abs(dy)); 
    float xin = (float)dx / step; 
    float yin = (float)dy / step; 
    float x = x1; 
    float y = y1; 
    glBegin(GL_POINTS); 
    for (int i = 0; i <= step; i++) 
    { 
        glVertex2i(round(x), round(y)); 
        x += xin; 
        y += yin; 
    } 
    glEnd(); 
} 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glPointSize(1); 
    // H 
    dda(70, 50, 70, 150); 
    dda(70, 100, 150, 100); 
    dda(150, 50, 150, 150); 
    // E 
    dda(160, 50, 160, 150); 
    dda(160, 150, 200, 150); 
    dda(160, 100, 190, 100); 
    dda(160, 50, 200, 50); 
    // L 
    dda(210, 50, 210, 150); 
    dda(210, 50, 240, 50); 
    // L 
    dda(250, 50, 250, 150); 
    dda(250, 50, 290, 50); 
    // O 
    dda(300, 50, 300, 150); 
    dda(300, 150, 350, 150); 
    dda(350, 50, 350, 150); 
    dda(300, 50, 350, 50); 
    glFlush();
    } 
void init() 
{ 
glClearColor(0.0, 0.0, 0.0, 1.0); 
glColor3f(1.0, 1.0, 1.0); 
glPointSize(4.0); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0, 500, 0, 500); 
} 
int main(int argc, char **argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(2000, 2000); 
glutCreateWindow("DDA Line DrawingAlgorithm"); 
init(); 
glutDisplayFunc(display); 
glutMainLoop(); 
return 0; 
} 
