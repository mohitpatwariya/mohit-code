#include <GL/glut.h> 
using namespace std; 
int fillColor[3] = {1,0,0}; 
int boundaryColor[3] = {1,1,1}; 
void setPixel(int x,int y){ 
    glBegin(GL_POINTS); 
    glVertex2i(x,y); 
    glEnd(); 
    glFlush(); 
} 
void getPixel(int x,int y,float color[3]){ 
    glReadPixels(x,y,1,1,GL_RGB,GL_FLOAT,color); 
} 
void boundaryFill(int x,int y) 
{ 
    float color[3]; 
    getPixel(x,y,color); 
 
    if((color[0]!=boundaryColor[0] || color[1]!=boundaryColor[1] || 
color[2]!=boundaryColor[2]) && 
       (color[0]!=fillColor[0] || color[1]!=fillColor[1] || 
color[2]!=fillColor[2])){ 
        glColor3f(fillColor[0],fillColor[1],fillColor[2]); 
        setPixel(x,y); 
        boundaryFill(x+1,y); 
        boundaryFill(x-1,y); 
        boundaryFill(x,y+1); 
        boundaryFill(x,y-1); 
        boundaryFill(x+1,y+1); 
        boundaryFill(x-1,y+1); 
        boundaryFill(x+1,y-1); 
        boundaryFill(x-1,y-1); 
    } 
} 
void drawPolygon(){ 
    glColor3f(1,1,1); 
    glBegin(GL_LINE_LOOP); 
    glVertex2i(100,100); 
    glVertex2i(300,100); 
    glVertex2i(300,300); 
    glVertex2i(100,300); 
    glEnd(); 
} 
void display(){
       glClear(GL_COLOR_BUFFER_BIT); 
    drawPolygon(); 
    glFlush(); 
} 
void mouse(int button,int state,int x,int y){ 
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){ 
        y = 500 - y; 
        boundaryFill(x,y); 
    } 
} 
void init(){ 
    glClearColor(0,0,0,1); 
    glColor3f(1,1,1); 
    glPointSize(2.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(0,500,0,500); 
} 
int main(int argc,char** argv){ 
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500,500); 
    glutCreateWindow("Boundary Fill 8-Connected"); 
    init(); 
    glutDisplayFunc(display); 
    glutMouseFunc(mouse); 
    glutMainLoop(); 
    return 0; 
} 