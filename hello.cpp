#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(3.0);
  // H
    glBegin(GL_LINE_LOOP);
    glVertex2i(20 ,20);
    glVertex2i(220, 20);
    glVertex2i(220 ,220);
    glVertex2i(20, 220);
    
glEnd();
lBegin(GL_LINE_LOOP);
    glVertex2i(20 ,20);
    glVertex2i(220, 20);
    glVertex2i(220 ,220);
    glVertex2i(20, 220);
    
glEnd();
 glBegin(GL_LINES);
  // E
    glVertex2i(80 ,20);
    glVertex2i(80, 60);
    glVertex2i(80 ,20);
    glVertex2i(100, 20);
    glVertex2i(80 ,40);
    glVertex2i(100, 40);
    glVertex2i(80 ,20);
    glVertex2i(100, 20);
    glVertex2i(80 ,60);
    glVertex2i(100, 60);
    glVertex2i(20 ,20);
    glVertex2i(20, 60);
    glVertex2i(60 ,20);
    glVertex2i(60, 60);
    glVertex2i(20 ,40);
    glVertex2i(60, 40);

    // l
     glVertex2i(120, 20);
     glVertex2i(120, 60);
     glVertex2i(120, 20);
     glVertex2i(140, 20);
     // L
     glVertex2i(160, 20);
     glVertex2i(160, 60);
     glVertex2i(160, 20);
     glVertex2i(180, 20);
    
     glEnd();
// O 
     
     glBegin(GL_LINE_LOOP);
     glVertex2i(220, 20);
     glVertex2i(220, 60);
      glVertex2i(260, 60);
     glVertex2i(260, 20);
    
    glEnd();
    glFlush();
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Hello ");

    init();
   

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}