#include <GL/glut.h>

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10.0);   // Point size
    glBegin(GL_LINES );  // Start drawing points

    glColor3f(1.0, 1.0, 0.0); // Red color
    glVertex2f(2,3
    );     // Point at center

    glEnd();

    glFlush(); // Render now
}

// Initialize settings
void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Point");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}