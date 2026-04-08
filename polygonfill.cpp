#include <GL/glut.h> 
#include <iostream> 
using namespace std; 
int ww = 600, wh = 600; 
 
float boundaryColor[3] = {1, 0, 0}; 
 
float fillColor[3] = {0, 1, 0}; 
 
void getPixel(int x, int y, float color[3]) { 
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color); 
} 
void setPixel(int x, int y, float color[3]) { 
    glColor3fv(color); 
    glBegin(GL_POINTS); 
        glVertex2i(x, y); 
    glEnd(); 
    glFlush(); 
} 
bool sameColor(float c1[3], float c2[3]) { 
    return (c1[0]==c2[0] && c1[1]==c2[1] && c1[2]==c2[2]); 
} 
void boundaryFill(int x, int y) { 
    float current[3]; 
    getPixel(x, y, current); 
    if (!sameColor(current, boundaryColor) && !sameColor(current, fillColor)) 
{ 
        setPixel(x, y, fillColor); 
        boundaryFill(x+1, y); 
        boundaryFill(x-1, y); 
        boundaryFill(x, y+1); 
        boundaryFill(x, y-1); 
    } 
} 
void drawPolygon() { 
    glColor3f(1, 0, 0);  
    glBegin(GL_LINE_LOOP); 
        glVertex2i(200, 200); 
        glVertex2i(400, 200); 
        glVertex2i(450, 350); 
        glVertex2i(300, 450); 
        glVertex2i(150, 350); 
    glEnd(); 
} 
void mouse(int btn, int state, int x, int y) {
     if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { 
        int xi = x; 
        int yi = wh - y;   
        boundaryFill(xi, yi); 
    } 
} 
void display() { 
    glClear(GL_COLOR_BUFFER_BIT); 
    drawPolygon(); 
    glFlush(); 
} 
void init() { 
    glClearColor(0, 0, 0, 0); 
    glColor3f(1, 1, 1); 
    gluOrtho2D(0, ww, 0, wh); 
} 
// Main 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitWindowSize(ww, wh); 
    glutCreateWindow("Boundary Fill with Mouse"); 
    init(); 
    glutDisplayFunc(display); 
    glutMouseFunc(mouse); 
    glutMainLoop(); 
    return 0; 
} 