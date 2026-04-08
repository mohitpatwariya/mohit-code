#include <GL/glut.h> 
#include <cmath> 
using namespace std; 
 
float x_start = 0, y_start = 0; 
float x_end = 0, y_end = 5; 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
 
    glColor3f(1.0, 1.0, 1.0); 
    glLineWidth(3.0); 
 
    glBegin(GL_LINES); 
    glVertex2f(x_start, y_start); 
    glVertex2f(x_end, y_end); 
    glEnd(); 
 
    float angle = 30.0 * M_PI / 180.0; 
 
    float xr1 = x_start * cos(angle) - y_start * sin(angle); 
    float yr1 = x_start * sin(angle) + y_start * cos(angle); 
 
    float xr2 = x_end * cos(angle) - y_end * sin(angle); 
    float yr2 = x_end * sin(angle) + y_end * cos(angle); 
 
    float xt1 = xr1 + 3; 
    float yt1 = yr1 + 2; 
 
    float xt2 = xr2 + 3; 
        float yt2 = yr2 + 2; 
 
    glColor3f(1.0, 0.0, 0.0); 
 
    glBegin(GL_LINES); 
    glVertex2f(xt1, yt1); 
    glVertex2f(xt2, yt2); 
    glEnd(); 
 
    glFlush(); 
} 
 
void init() 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-10, 10, -10, 10); 
} 
 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600); 
    glutCreateWindow("Ladder Transformation"); 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0; 
} 