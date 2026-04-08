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
    cout << "Intermediate pixels:\n"; 
    glBegin(GL_POINTS); 
    for (int i = 0; i <= step; i++) 
    { 
        cout << "(" << round(x) << ", " << round(y) << ")\n"; 
        glVertex2i(round(x), round(y)); 
        x += xin; 
        y += yin; 
    } 
    glEnd(); 
} 
void display(){ 
    glClear(GL_COLOR_BUFFER_BIT); 
    dda(2, 3, 10, 8); 
    glFlush(); 
} 
void init(){ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glPointSize(4.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0, 50, 0, 50); 
} 
int main(int argc, char **argv){ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(640, 480); 
    glutCreateWindow("DDA Line DrawingAlgorithm"); 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
return 0; 
}