#include <GL/glut.h> 
#include <bits/stdc++.h> 
using namespace std; 
int sides = 5; 
void init() 
{ 
glClearColor(0, 0, 0, 1); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(-300.0, 300.0, -300.0, 300.0); 
} 
void display() 
{ 
glClear(GL_COLOR_BUFFER_BIT); 
glColor3f(1.0, 0.0, 0.0); 
float radius = 150; 
glBegin(GL_LINE_LOOP); 
for (int i = 0; i < sides; i++) 
{ 
float angle = 2 * M_PI * i / sides; 
glVertex2f(radius * cos(angle), radius * sin(angle)); 
} 
glEnd(); 
glFlush(); 
} 
int main(int argc, char **argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(600, 600); 
glutCreateWindow("Regular Polygon"); 
init(); 
glutDisplayFunc(display); 
glutMainLoop(); 
return 0; 
}