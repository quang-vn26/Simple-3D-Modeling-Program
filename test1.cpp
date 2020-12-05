// ve cua so
//ve hinh 3d
// ve luoi
//di chuyen hinh
//Create Quads
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;

int cx=0,cy=0,cz=0; //toa do x, y,z cua hinh_3ds
int number;// dung de dem so luong

struct tu_giac{
	int x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4;
	float r,g,b;
	int state;
	int total;
}; tu_giac Q[100];
void them_toa_do_cho_tu_giac(){
	Q[0].state++;
	if(Q[0].state>4){Q[0].state = 1;}
	int st = Q[0].state;
	
	if(st == 1){Q[0].total++;number=Q[0].total;}
	
	if(st == 1							){Q[number].x1 = cx; Q[number].y1 = cy; Q[number].z1=cz;}
	if(st == 1|| st==2					){Q[number].x2 = cx; Q[number].y2 = cy; Q[number].z2=cz;}
	if(st == 1|| st ==2 || st ==3		){Q[number].x3 = cx; Q[number].y3 = cy; Q[number].z3=cz;}
	if(st == 1|| st ==2 || st ==3||st ==4){Q[number].x4 = cx; Q[number].y4 = cy;Q[number].z4=cz;}
}
void ve_tu_giac(){
	int i;
	for(i=1;i<Q[0].total+1;i++){
		glBegin(GL_QUADS);
		glColor3f(Q[i].r,Q[i].g,Q[i].b);
		glVertex3f(Q[i].x1,Q[i].y1,Q[i].z1);
		glVertex3f(Q[i].x2,Q[i].y2,Q[i].z2);
		glVertex3f(Q[i].x3,Q[i].y3,Q[i].z3);
		glVertex3f(Q[i].x4,Q[i].y4,Q[i].z4);
		glEnd();
	}
}

void diem_ve()
{	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(cx,cy,cz);
	glutSolidCube(0.4);
	glPopMatrix();
}
void luoi(){
	int i;
	for(i=0;i<40;i++){
		glPushMatrix();
		if(i<20){glTranslatef(0,0,i);}
		if(i>=20){glTranslatef(i-20,0,0);glRotatef(-90,0,1,0);printf("\n %i",i);}
		glBegin(GL_LINES);
		glColor3f(1,1,1);glLineWidth(1);
		glVertex3f(0,-0.1,0);glVertex3f(19,-0.1,0);
		glEnd();
		glPopMatrix();
	}
}
void hien_thi(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(-13,0,-45);
	glRotatef(40,1,1,0);
	
	luoi();
	ve_tu_giac();
	diem_ve();
	glutSwapBuffers();
}
void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(35,1.0f,0.1f,1000);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.1,0.1,0.1,0.1);
}
void ban_phim(unsigned char key, int x,int y ){
	if(key =='w'){cz-=1;}if(key =='s'){cz+=1;}
	if(key =='a'){cx-=1;}if(key =='d'){cx+=1;}
	if(key =='q'){cy+=1;} if(key =='z'){cy-=1;}
	
	if(key ==32) {them_toa_do_cho_tu_giac();} //space
	
	if(key == 'r') {Q[number].r=1;Q[number].g=0;Q[number].b=0;}
	if(key == 'g') {Q[number].r=0.221;Q[number].g=0.65;Q[number].b=0.36;}
	if(key == 'b') {Q[number].r=0;Q[number].g=0;Q[number].b=1;}
	if(key == 'y') {Q[number].r=1;Q[number].g=1;Q[number].b=0;}
	glutPostRedisplay();
}
int main(int argc, char ** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800,600);
	glutCreateWindow("Ve Hinh 3D");
	glutDisplayFunc(hien_thi);
	glutKeyboardFunc(ban_phim);
	init();
	glutMainLoop();
	return 0;
}




