/*
 * solar.c
 *
 *  Created on: 11 de abr de 2017
 *      Author: Erik
 */

#include <GL/glut.h>
#include <GL/glu.h>
#define planeta 1

float R=1.0,G=0.0,B=0.0;
float a=0,b=0,d=0;
float aspect;
GLfloat eyeX=0, eyeY=0, eyeZ=150, centerX=0, centerY=0, centerZ=0, upX=0, upY=1, upZ=0;
int marelea=0;

void planet(float r,float g,float b,float radius,float slices,float stacks){
	glNewList(planeta, GL_COMPILE);
	glColor3f(r, g, b);
	glutWireSphere(radius, slices, stacks);
	glEndList();

}

void idle(){
	d=(d+0.009);
	glutPostRedisplay();
}

void reshape (int w,int h){
	glViewport(0, 0, w, h);
	aspect = (GLfloat)w/(GLfloat)h;
}


void init(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, aspect, 0.1, 1000);
	gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);
}

void display(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);


	//sol
	glPushMatrix();
	glRotatef(d,0,0,1);
	planet(1, 1, 0, 4, 15, 15);
	glCallList(1);

	if(marelea==0){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	//mercurio
	glPushMatrix();

	glRotatef(d*8,0,0,1);
	glTranslatef(5,0,0);
	glRotatef(d*6,0,0,1);
	planet(1, 1, 0, 0.5, 10, 10);
	glCallList(1);

	if(marelea==1){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	//venus
	glPushMatrix();

	glRotatef(d*7,0,0,1);
	glTranslatef(7,0,0);
	glRotatef(d*6,0,0,1);
	planet(1, 0, 0, 1, 10, 10);
	glCallList(1);

	if(marelea==2){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}
	glPopMatrix();

	//terra
	glPushMatrix();

	glRotatef(d*6,0,0,1);
	glTranslatef(10,0,0);
	glRotatef(d*10,0,0,1);
	planet(0, 0, 1, 1, 10, 10);
	glCallList(1);

	if(marelea==3){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	//lua
	glRotatef(0,0,0,1);
	glTranslatef(2,0,0);
	glRotatef(0,0,0,1);
	planet(1, 1, 1, 0.5, 10, 10);
	glCallList(1);

	if(marelea==9){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	//marte

	glPushMatrix();
	glRotatef(d*5,0,0,1);
	glTranslatef(15,0,0);
	glRotatef(d*6,0,0,1);
	planet(1, 0, 0, 0.7, 10, 10);
	glCallList(1);

	if(marelea==4){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	//jupter
	glPushMatrix();

	glRotatef(d*4,0,0,1);
	glTranslatef(20,0,0);
	glRotatef(d*6,0,0,1);
	planet(0.5, 0.2, 0, 3, 10, 10);
	glCallList(1);

	if(marelea==5){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}
	glPopMatrix();

	//saturno
	glPushMatrix();


	glRotatef(d*3,0,0,1);
	glTranslatef(28,0,0);
	glRotatef(d*6,0,0,1);
	planet(1, 0.5, 0, 2.5, 10, 10);
	glCallList(1);
	glutWireTorus(0, 4, 3, 50);

	if(marelea==6){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	//urano
	glPushMatrix();

	glRotatef(d*2,0,0,1);
	glTranslatef(35,0,0);
	glRotatef(d*6,0,0,1);
	planet(0, 1, 1, 2, 10, 10);
	glCallList(1);

	if(marelea==7){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	//netuno
	glPushMatrix();

	glRotatef(d,0,0,1);
	glTranslatef(40,0,0);
	glRotatef(d*6,0,0,1);
	planet(0, 0, 1, 2, 10, 10);
	glCallList(1);

	if(marelea==8){

		GLfloat a[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, a);

		eyeX=a[12];
		centerX=a[12];
		eyeY=a[13];
		centerY=a[13];
	}

	glPopMatrix();

	init();
	glutSwapBuffers();
}

void teclado(unsigned char key,int x,int y){
	switch(key){
	case '0':
		marelea=0;
		break;
	case '1':
		marelea=1;
		break;
	case '2':
		marelea=2;
		break;
	case '3':
		marelea=3;
		break;
	case '4':
		marelea=4;
		break;
	case '5':
		marelea=5;
		break;
	case '6':
		marelea=6;
		break;
	case '7':
		marelea=7;
		break;
	case '8':
		marelea=8;
		break;
	case '9':
		marelea=9;
		break;
	}

	glutPostRedisplay();

}


int main(int argc, char **argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(700, 40);
	glutCreateWindow("Solar");
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(teclado);
	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}
