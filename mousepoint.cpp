#include <GL/glut.h> 
#include <bits/stdc++.h> 
using namespace std; 
vector<pair<int, int>> v; 
void init(){ 
    glClearColor(0.0, 0.0, 0.0, 0.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0, 500.0, 0, 500.0); 
} 
void display(){ 
    glClear(GL_COLOR_BUFFER_BIT); 
    glColor3f(1.0, 0.0, 0.0); 
    glPointSize(6.0); 
    glBegin(GL_POINTS); 
    for (int i = 0; i < v.size(); i++){ 
        glVertex2i(v[i].first, v[i].second); 
    } 
    glEnd(); 
    glFlush(); 
} 
void mouse(int button, int state, int x, int y){ 
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){ 
        int opengl = 500 - y; 
        v.push_back({x, opengl}); 
        glutPostRedisplay(); 
    } 
} 
int main(int argc, char **argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500); 
    glutCreateWindow("Mouse Function"); 
    init(); 
    glutDisplayFunc(display); 
    glutMouseFunc(mouse); 
    glutMainLoop(); 
    return 0; 
} 
 