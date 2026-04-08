#include <bits/stdc++.h> 
using namespace std; 
#include <GL/glut.h> 
void init() 
{ 
    glClearColor(0, 0, 0, 1); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0, 500, 0, 500); 
} 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1, 1, 1); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(150, 150); 
    glVertex2i(350, 150); 
    glVertex2i(350, 300); 
    glVertex2i(150, 300); 
    glEnd(); 
    glBegin(GL_LINES); 
    glVertex2i(150, 300); 
    glVertex2i(250, 400); 
    glVertex2i(250, 400); 
    glVertex2i(350, 300); 
    glEnd(); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(220, 150); 
    glVertex2i(280, 150); 
    glVertex2i(280, 230); 
    glVertex2i(220, 230); 
    glEnd(); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(170, 220); 
    glVertex2i(210, 220); 
    glVertex2i(210, 260); 
    glVertex2i(170, 260); 
    glEnd(); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(290, 220); 
    glVertex2i(330, 220); 
    glVertex2i(330, 260); 
    glVertex2i(290, 260); 
    glEnd(); 
    glFlush();
    } 
int main(int argc, char **argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(500, 500); 
glutCreateWindow("Simple House Scene"); 
init(); 
glutDisplayFunc(display); 
glutMainLoop(); 
return 0; 
} 