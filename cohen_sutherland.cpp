#include <GL/glut.h> 
using namespace std; 
 
float xmin = 100, ymin = 100, xmax = 400, ymax = 400; 
float x_start = 50, y_start = 50; 
float x2 = 450, y_end = 450; 
const int INSIDE = 0; 
const int LEFT = 1; 
const int RIGHT = 2; 
const int BOTTOM = 4; 
const int TOP = 8; 
int computeCode(float x, float y) 
{ 
    int code = INSIDE; 
    if (x < xmin) code |= LEFT; 
    else if (x > xmax) code |= RIGHT; 
    if (y < ymin) code |= BOTTOM; 
    else if (y > ymax) code |= TOP; 
    return code; 
} 
void cohenSutherland() 
{ 
    float x, y; 
    int code1 = computeCode(x_start, y_start); 
    int code2 = computeCode(x2, y_end); 
    bool accept = false; 
    while (true) 
    { 
        if ((code1 == 0) && (code2 == 0)) 
        { 
            accept = true; 
            break; 
        } 
        else if (code1 & code2) 
        { 
            break; 
        } 
        else 
        { 
            int codeOut = code1 ? code1 : code2; 
 
            if (codeOut & TOP)
              { 
                x = x_start + (x2 - x_start) * (ymax - y_start) / (y_end - 
y_start); 
                y = ymax; 
            } 
            else if (codeOut & BOTTOM) 
            { 
                x = x_start + (x2 - x_start) * (ymin - y_start) / (y_end - 
y_start); 
                y = ymin; 
            } 
            else if (codeOut & RIGHT) 
            { 
                y = y_start + (y_end - y_start) * (xmax - x_start) / (x2 - 
x_start); 
                x = xmax; 
            } 
            else if (codeOut & LEFT) 
            { 
                y = y_start + (y_end - y_start) * (xmin - x_start) / (x2 - 
x_start); 
                x = xmin; 
            } 
 
            if (codeOut == code1) 
            { 
                x_start = x; 
                y_start = y; 
                code1 = computeCode(x_start, y_start); 
            } 
            else 
            { 
                x2 = x; 
                y_end = y; 
                code2 = computeCode(x2, y_end); 
            } 
        } 
    } 
    if (accept) 
    { 
        glColor3f(1,0,0); 
        glBegin(GL_LINES); 
        glVertex2f(x_start, y_start); 
        glVertex2f(x2, y_end); 
        glEnd(); 
    } 
} 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
 
    glColor3f(1,1,1); 
    glBegin(GL_LINE_LOOP); 
    glVertex2f(xmin, ymin); 
    glVertex2f(xmax, ymin); 
    glVertex2f(xmax, ymax); 
    glVertex2f(xmin, ymax); 
    glEnd(); 
 
    glColor3f(0,1,0); 
    glBegin(GL_LINES); 
    glVertex2f(50,50); 
    glVertex2f(450,450); 
    glEnd(); 
 
    cohenSutherland(); 
 
    glFlush(); 
} 
 
void init() 
{ 
    glClearColor(0,0,0,1); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(0,500,0,500); 
} 
 
int main(int argc,char** argv) 
{ 
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500,500); 
    glutCreateWindow("Cohen-Sutherland Clipping"); 
 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0; 
} 