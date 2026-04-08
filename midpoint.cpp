#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;


    
    vector<pair<int,int>>v;
void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	 glPointSize(3.0);
    glBegin(GL_POINTS);
    for(int i =0;i<v.size();i++){
        glVertex2i(v[i].first,v[i].second);
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<" size "<<v.size();
    glEnd();

 glFlush();
}

void symmetric(int x,int y , int xc ,int yc){
     v.push_back({xc + x , yc + y});
     v.push_back({xc - x , yc + y});
     v.push_back({xc + x , yc - y});
     v.push_back({xc - x , yc - y});
     v.push_back({xc + y , yc + x});
     v.push_back({xc - y , yc + x});
     v.push_back({xc + y , yc - x});
     v.push_back({xc - y , yc - x});
}

void circle(float r,int xc ,int yc){
    float p = 1 - r;
    float x = 0 , y = r ;
    while(x<y){
         symmetric(x,y,xc,yc);
         x++;
        if(p<0){
            p = p + 2 * x + 3;
        }else{
            p = p + 2*x - 2 * y +5;
            y--; 
        }
    }
}

int main(int argc, char **argv)
{  

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("DDA");
	init();
    circle(75,10,20);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}