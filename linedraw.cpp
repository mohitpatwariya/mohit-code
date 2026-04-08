 #include <GL/glut.h> 
 #include <bits/stdc++.h> 
 using namespace std; 
void init() 
 { 
     glClearColor(1.0, 1.0, 1.0, 0.0); 
     glMatrixMode(GL_PROJECTION); 
          gluOrtho2D(-300.0, 300.0, -300.0, 300.0); 
 }  void display() 
 { 
     int points[3][2] = {{0, 0}, {75, 150}, {100, 200}}; 
     glClear(GL_COLOR_BUFFER_BIT); 
          glColor3f(1.0, 0.0, 0.0); 
   glPointSize(3.0); 
     glBegin(GL_LINES); 
     for (int i = 0; i < 3; i++){ 
         glVertex2i(points[i][0], points[i][1]); 
     } 
     glEnd(); 
     glFlush(); 
 } 
 int main(int argc, char **argv) 
 { 
    glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
     glutInitWindowSize(300, 300); 
     glutCreateWindow("Lines"); 
     init(); 
          glutDisplayFunc(display); 
     glutMainLoop(); 
   return 0; 
 } 