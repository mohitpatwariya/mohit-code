#include <GL/glut.h> 
#include <iostream> 
using namespace std; 
 
int xc, yc, a, b; 
 
// 🔹 Print intermediate + symmetric points 
void displaypoints(int x, int y) 
{ 
    // Intermediate point 
    cout << "Intermediate: (" << x << "," << y << ")" << endl; 
 
    // Symmetric plotted points 
    cout << "Plot: (" << xc + x << "," << yc + y << ")" << endl; 
    cout << "Plot: (" << xc - x << "," << yc + y << ")" << endl; 
    cout << "Plot: (" << xc + x << "," << yc - y << ")" << endl; 
    cout << "Plot: (" << xc - x << "," << yc - y << ")" << endl; 
 
    cout << "------------------------" << endl; 
} 
 
// 🔹 Plot points on screen 
void plotpoint(int x, int y) 
{ 
    glBegin(GL_POINTS); 
    glVertex2i(xc + x, yc + y); 
    glVertex2i(xc - x, yc + y); 
    glVertex2i(xc + x, yc - y); 
    glVertex2i(xc - x, yc - y); 
    glEnd(); 
} 
 
void midpointellipse() 
{ 
    int x = 0; 
    int y = b; 
 
    long a2 = a * a; 
    long b2 = b * b; 
 
    long dx = 2 * b2 * x; 
    long dy = 2 * a2 * y;
     // 🔴 Region 1 
    long p1 = b2 - (a2 * b) + (a2 / 4); 
 
    while (dx < dy) 
    { 
        plotpoint(x, y); 
        displaypoints(x, y);   // 🔥 print intermediate + plot 
 
        x++; 
        dx = 2 * b2 * x; 
 
        if (p1 < 0) 
        { 
            p1 = p1 + dx + b2; 
        } 
        else 
        { 
            y--; 
            dy = 2 * a2 * y; 
            p1 = p1 + dx - dy + b2; 
        } 
    } 
 
    // 🔴 Region 2 
    long p2 = (b2 * (x + 0.5) * (x + 0.5)) + 
              (a2 * (y - 1) * (y - 1)) - 
              (a2 * b2); 
 
    while (y >= 0) 
    { 
        plotpoint(x, y); 
        displaypoints(x, y);   // 🔥 print intermediate + plot 
 
        y--; 
        dy = 2 * a2 * y; 
 
        if (p2 > 0) 
        { 
            p2 = p2 + a2 - dy; 
        } 
        else 
        { 
            x++; 
            dx = 2 * b2 * x; 
            p2 = p2 + dx - dy + a2; 
        } 
    } 
}
void init() 
{ 
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glColor3f(1.0, 1.0, 1.0); 
    glPointSize(3.0); 
 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-500, 500, -500, 500); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    midpointellipse(); 
    glFlush(); 
} 
 
int main(int argc, char **argv) 
{ 
    cout << "Enter center (xc yc) and major(a) and minor(b): "; 
    cin >> xc >> yc >> a >> b; 
 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(600, 600); 
    glutCreateWindow("Midpoint Ellipse (With Intermediate Points)"); 
 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
 
    return 0; 
} 
