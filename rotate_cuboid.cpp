#include <GL/glut.h> 
 
float angle = 45.0; 
 
void drawCuboid() 
{ 
    glPushMatrix(); 
    glScalef(2.0f, 1.0f, 3.0f); 
    glutWireCube(1.0); 
    glPopMatrix(); 
} 
 
void display() 
{ 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity(); 
 
    gluLookAt(4, 4, 8, 0, 0, 0, 0, 1, 0); 
 
    glColor3f(1,1,1); 
    drawCuboid(); 
 
    glPushMatrix(); 
    glRotatef(angle, 1.0, 0.0, 0.0); 
    glColor3f(1,0,0); 
    drawCuboid(); 
    glPopMatrix(); 
 
    glutSwapBuffers(); 
} 
 
void init() 
{ 
    glEnable(GL_DEPTH_TEST); 
 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluPerspective(60, 1.0, 1.0, 100.0); 
 
    glMatrixMode(GL_MODELVIEW); 
} 
 
int main(int argc, char **argv) 
{ 
glutInit(&argc, argv); 
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
glutInitWindowSize(600, 600); 
glutCreateWindow("3D Rotation about X-axis (Cuboid)"); 
init(); 
glutDisplayFunc(display); 
glutMainLoop(); 
return 0;
}
