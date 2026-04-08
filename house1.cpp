#include <GL/glut.h> 
#include <cmath> 
using namespace std; 
 
// 🔹 Rectangle (outline) 
void drawRect(float x1, float y1, float x2, float y2) 
{ 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(x1, y1); 
    glVertex2f(x2, y1); 
    glVertex2f(x2, y2); 
    glVertex2f(x1, y2); 
    glEnd(); 
} 
 
// 🔹 Triangle (outline) 
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) 
{ 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(x1, y1); 
    glVertex2f(x2, y2); 
    glVertex2f(x3, y3); 
    glEnd(); 
} 
 
// 🔹 Circle (sun outline) 
void drawCircle(float xc, float yc, float r) 
{ 
    glBegin(GL_LINE_LOOP); 
    for (int i = 0; i < 360; i++) 
    { 
        float theta = i * 3.1416 / 180; 
        float x = r * cos(theta); 
        float y = r * sin(theta); 
        glVertex2f(x + xc, y + yc); 
    } 
    glEnd(); 
} 
 
// 🔹 House (outline) 
void drawHouse(float x, float y) 
{ 
    drawRect(x, y, x + 80, y + 60);                      // base 
    drawTriangle(x, y + 60, x + 40, y + 100, x + 80, y + 60); // roof 
    drawRect(x + 30, y, x + 50, y + 30);  
    } 
 
// 🔹 Fence (outline) 
void drawFence() 
{ 
    for (int i = -400; i <= 400; i += 40) 
    { 
        drawRect(i, -150, i + 10, -50); // vertical bars 
    } 
 
    drawRect(-400, -120, 400, -110); // horizontal 
    drawRect(-400, -80, 400, -70); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
 
    glColor3f(1.0, 1.0, 1.0); // white lines 
    glLineWidth(2.0); 
 
    // 🌞 Sun 
    drawCircle(250, 250, 40); 
 
    // 🏡 Houses 
    drawHouse(-300, -50); 
    drawHouse(-50, -50); 
    drawHouse(200, -50); 
 
    // 🚧 Fence 
    drawFence(); 
 
    glFlush(); 
} 
 
void init() 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); // black background 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-500, 500, -500, 500); 
} 
 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600); 
    glutCreateWindow("Black & White Scene"); 
    init(); 
glutDisplayFunc(display); 
glutMainLoop(); 
return 0; 
} 