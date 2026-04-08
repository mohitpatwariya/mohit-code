#include <GL/glut.h> 
#include <cmath> 
using namespace std; 
 
float fillColor[3] = {1,0,0}; 
 
bool sameColor(float c1[3], float c2[3]) 
{ 
    float tol = 0.01; 
    return (fabs(c1[0]-c2[0])<tol && 
            fabs(c1[1]-c2[1])<tol && 
            fabs(c1[2]-c2[2])<tol); 
} 
 
void setPixel(int x,int y) 
{ 
    glBegin(GL_POINTS); 
    glVertex2i(x,y); 
    glEnd(); 
    glFlush(); 
} 
 
void getPixel(int x,int y,float color[3]) 
{ 
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color); 
} 
 
void floodFill(int x,int y,float oldColor[3]) 
{ 
    float color[3]; 
    getPixel(x,y,color); 
 
    if(sameColor(color,oldColor) && !sameColor(color,fillColor)) 
    { 
        glColor3f(fillColor[0],fillColor[1],fillColor[2]); 
        setPixel(x,y); 
 
        floodFill(x+1,y,oldColor); 
        floodFill(x-1,y,oldColor); 
        floodFill(x,y+1,oldColor); 
        floodFill(x,y-1,oldColor); 
    } 
} 
 
void drawPolygon() 
{ 
       glColor3f(1,1,1); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(100,100); 
    glVertex2i(300,100); 
    glVertex2i(300,300); 
    glVertex2i(100,300); 
    glEnd(); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    drawPolygon(); 
    glFlush(); 
} 
 
void mouse(int button,int state,int x,int y) 
{ 
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN) 
    { 
        y = 500 - y; 
 
        float oldColor[3]; 
        getPixel(x,y,oldColor); 
 
        floodFill(x,y,oldColor); 
    } 
} 
 
void init() 
{ 
    glClearColor(0,0,0,1); 
    glColor3f(1,1,1); 
    glPointSize(2.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(0,500,0,500); 
} 
 
int main(int argc,char** argv) 
{ 
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500,500); 
    glutCreateWindow("Flood Fill Fixed"); 
 
    init(); 
    glutDisplayFunc(display); 
    glutMouseFunc(mouse);
    glutMainLoop(); 
return 0; 
}