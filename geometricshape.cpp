#include <GL/glut.h> 
using namespace std; 
 
void drawRectangle(float x1,float y1,float x2,float y2){ 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(x1,y1); 
    glVertex2f(x2,y1); 
    glVertex2f(x2,y2); 
    glVertex2f(x1,y2); 
    glEnd(); 
} 
void drawTriangle(float x1,float y1,float x2,float y2,float x3,float y3){ 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(x1,y1); 
    glVertex2f(x2,y2); 
    glVertex2f(x3,y3); 
    glEnd(); 
} 
void display(){ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glLineWidth(2.5); 
    glColor3f(1,1,1); 
    drawRectangle(0,0,6,9); 
    drawTriangle(0,0,2,0,1,1); 
    glColor3f(1,0,0); 
    drawRectangle(5,0,11,9);
    glColor3f(0,0,1); 
drawTriangle(0,0,6,0,3,3); 
glColor3f(0,1,0); 
drawTriangle(5,9,11,9,8,12); 
glFlush(); 
} 
void init(){ 
glClearColor(0,0,0,1); 
glMatrixMode(GL_PROJECTION); 
gluOrtho2D(-5,20,-5,20); 
} 
int main(int argc,char** argv){ 
glutInit(&argc,argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(600,600); 
glutCreateWindow("Perfect Roof Cover"); 
init(); 
glutDisplayFunc(display); 
glutMainLoop(); 
return 0; 
} 