#include <GL/glut.h> 
#include <cmath> 
using namespace std; 
 
float x1_start = 1, y1_start = 1; 
float x2_start = 4, y2_start = 1; 
float x3_start = 2.5, y3_start = 4; 
 
float angle = 45.0; 
 
float x_fixed = 2, y_fixed = 2; 
 
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) 
{ 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(x1, y1); 
    glVertex2f(x2, y2); 
    glVertex2f(x3, y3); 
    glEnd(); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
 
    float rad = angle * M_PI / 180.0; 
 
    glColor3f(1,1,1); 
    drawTriangle(x1_start,y1_start,x2_start,y2_start,x3_start,y3_start); 
 
    float x1_rot = x1_start*cos(rad) - y1_start*sin(rad); 
    float y1_rot = x1_start*sin(rad) + y1_start*cos(rad); 
 
    float x2_rot = x2_start*cos(rad) - y2_start*sin(rad); 
    float y2_rot = x2_start*sin(rad) + y2_start*cos(rad); 
 
    float x3_rot = x3_start*cos(rad) - y3_start*sin(rad); 
    float y3_rot = x3_start*sin(rad) + y3_start*cos(rad); 
 
    glColor3f(1,0,0); 
    drawTriangle(x1_rot,y1_rot,x2_rot,y2_rot,x3_rot,y3_rot); 
 
    float x1_temp = x1_start - x_fixed; 
    float y1_temp = y1_start - y_fixed; 
 
    float x2_temp = x2_start - x_fixed;
     float y2_temp = y2_start - y_fixed; 
 
    float x3_temp = x3_start - x_fixed; 
    float y3_temp = y3_start - y_fixed; 
 
    float x1_r = x1_temp*cos(rad) - y1_temp*sin(rad); 
    float y1_r = x1_temp*sin(rad) + y1_temp*cos(rad); 
 
    float x2_r = x2_temp*cos(rad) - y2_temp*sin(rad); 
    float y2_r = x2_temp*sin(rad) + y2_temp*cos(rad); 
 
    float x3_r = x3_temp*cos(rad) - y3_temp*sin(rad); 
    float y3_r = x3_temp*sin(rad) + y3_temp*cos(rad); 
 
    float x1_final = x1_r + x_fixed; 
    float y1_final = y1_r + y_fixed; 
 
    float x2_final = x2_r + x_fixed; 
    float y2_final = y2_r + y_fixed; 
 
    float x3_final = x3_r + x_fixed; 
    float y3_final = y3_r + y_fixed; 
 
    glColor3f(0,1,0); 
    drawTriangle(x1_final,y1_final,x2_final,y2_final,x3_final,y3_final); 
 
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
    glutCreateWindow("Triangle Rotation"); 
 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0; 
} 