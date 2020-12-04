/*Todo
Draw a window
3d scence
Draw a Grid
Move a Cube
Create Quads
Change Color
*/
#include<iostream>
#include<GL/glut.h>
using namespace std;
void theCube(){
	//mau trang
	glColor3f(1,1,1);
	//ve hinh cube
	glutSolidCube(0.4);
}
void display(){
	// xoay 1 goc 40 do, theo truc x,y gio nguyen
	glRotatef(40,1,1,0);
	theCube();
	glutSwapBuffers();
}

int main(int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutCreateWindow("");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}



