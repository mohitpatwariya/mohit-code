  #include <GL/glut.h> 
#include<bits/stdc++.h> 
using namespace std; 
 
vector<pair<int,int>> v; 
 
void init() 
{ 
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0); 
} 
 
void drawPoints(float r, int xc, int yc, float R, float G, float B) 
{ 
    v.clear(); // important 
 
    float p = 1 - r; 
    float x = 0, y = r; 
 
    while (x <= y) 
    { 
        // symmetric points 
        v.push_back({xc + x , yc + y}); 
        v.push_back({xc - x , yc + y}); 
        v.push_back({xc + x , yc - y}); 
        v.push_back({xc - x , yc - y}); 
        v.push_back({xc + y , yc + x}); 
        v.push_back({xc - y , yc + x}); 
        v.push_back({xc + y , yc - x}); 
        v.push_back({xc - y , yc - x}); 
 
        x++; 
        if (p < 0) 
            p = p + 2 * x + 3; 
        else 
        { 
            p = p + 2 * x - 2 * y + 5; 
            y--; 
        } 
    } 
 
    // draw 
    glColor3f(R, G, B); 
    glBegin(GL_POINTS);
    
  for (auto &pt : v) 
        glVertex2i(pt.first, pt.second); 
    glEnd(); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glPointSize(3.0); 
 
    int r = 50; 
 
    //  Top row 
    drawPoints(r, -120, 50, 0.0, 0.0, 1.0); // Blue 
    drawPoints(r, 0, 50, 0.0, 0.0, 0.0);    // Black 
    drawPoints(r, 120, 50, 1.0, 0.0, 0.0);  // Red 
 
    //  Bottom row 
    drawPoints(r, -60, -30, 1.0, 1.0, 0.0); // Yellow 
    drawPoints(r, 60, -30, 0.0, 1.0, 0.0);  // Green 
 
    glFlush(); 
} 
 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutCreateWindow("Olympic Rings"); 
 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0; 
} 