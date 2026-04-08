#include <GL/glut.h> 
using namespace std; 
 
float x_start = 0, y_start = 0; 
float x_end = 6, y_end = 7; 
 
void drawDottedAxes() 
{ 
    glLineWidth(1.5); 
    glEnable(GL_LINE_STIPPLE); 
    glLineStipple(1, 0x00FF); 
 
    glBegin(GL_LINES); 
    glVertex2f(-10, 0); 
    glVertex2f(10, 0); 
 
    glVertex2f(0, -10); 
    glVertex2f(0, 10); 
    glEnd(); 
 
    glDisable(GL_LINE_STIPPLE); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
 
    drawDottedAxes(); 
 
    glLineWidth(3.0); 
 
    glColor3f(1,1,1); 
    glBegin(GL_LINES); 
    glVertex2f(x_start, y_start); 
    glVertex2f(x_end, y_end); 
    glEnd(); 
 
    float x1_x = x_start; 
    float y1_x = -y_start; 
 
    float x2_x = x_end; 
    float y2_x = -y_end; 
 
    glColor3f(1,0,0); 
       glBegin(GL_LINES); 
    glVertex2f(x1_x, y1_x); 
    glVertex2f(x2_x, y2_x); 
    glEnd(); 
 
    float x1_y = -x1_x; 
    float y1_y = y1_x; 
 
    float x2_y = -x2_x; 
    float y2_y = y2_x; 
 
    glColor3f(0,1,0); 
    glBegin(GL_LINES); 
    glVertex2f(x1_y, y1_y); 
    glVertex2f(x2_y, y2_y); 
    glEnd(); 
 
    glFlush(); 
} 
 
void init() 
{ 
    glClearColor(0,0,0,1); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-10,10,-10,10); 
} 
 
int main(int argc,char** argv) 
{ 
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600,600); 
    glutCreateWindow("Reflection with Dotted Axes"); 
 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0; 
} 