#include<windows.h>
#include <iostream>
#include<gl/freeglut.h>
#include<gl/glut.h>
#include <math.h>

//glColor3f(0.41f, 0.35f, 0.23f);
//glColor3f(0.0, 0.50, 0.0);
//glColor3f(0.75, 0.75, 0.75);

void display() {
glClear(GL_COLOR_BUFFER_BIT);

//BINTANG1
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(40, 420);
glVertex2i(50, 435);
glVertex2i(60, 420);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(40, 430);
glVertex2i(50, 415);
glVertex2i(60, 430);
glEnd();

//BINTANG2
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(80, 460);
glVertex2i(90, 475);
glVertex2i(100, 460);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(80, 470);
glVertex2i(90, 455);
glVertex2i(100, 470);
glEnd();

//BINTANG3
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(100, 420);
glVertex2i(110, 435);
glVertex2i(120, 420);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(100, 430);
glVertex2i(110, 415);
glVertex2i(120, 430);
glEnd();

//BINTANG4
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(150, 460);
glVertex2i(160, 475);
glVertex2i(170, 460);
glEnd();

//BINTANG1
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(350, 420);
glVertex2i(360, 435);
glVertex2i(370, 420);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(350, 430);
glVertex2i(360, 415);
glVertex2i(370, 430);
glEnd();

//BINTANG2
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(400, 460);
glVertex2i(410, 475);
glVertex2i(420, 460);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(400, 470);
glVertex2i(410, 455);
glVertex2i(420, 470);
glEnd();

//BINTANG3
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(450, 420);
glVertex2i(460, 435);
glVertex2i(470, 420);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(450, 430);
glVertex2i(460, 415);
glVertex2i(470, 430);
glEnd();

//BINTANG4
glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(485, 460);
glVertex2i(495, 475);
glVertex2i(500, 460);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(485, 470);
glVertex2i(495, 455);
glVertex2i(500, 470);
glEnd();

glColor3f(1,1,0);
glBegin(GL_POLYGON);
glVertex2i(150, 470);
glVertex2i(160, 455);
glVertex2i(170, 470);
glEnd();

//gunung 
glColor3f(0.16,0.39,0);
glBegin(GL_POLYGON);
glVertex2i(-10, 350);
glVertex2i(255, 480);
glVertex2i(500, 350);
glEnd();
//garis di gunung
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINES); 
glVertex2i(178, 440);
glVertex2f(215.5, 420);
glVertex2i(215.5, 420);
glVertex2f(253, 440);
glVertex2i(253, 440);
glVertex2f(290.5, 420);
glVertex2f(290.5, 420);
glVertex2i(328, 440);
glEnd();

//AIR LAUT
glColor3f(0.0, 0.0f, 1.0f);
glBegin(GL_POLYGON); 
glVertex2i(260, 0);
glVertex2i(180, 350);
glVertex2i(500, 350);
glVertex2i(500, 0);
glEnd();

//--------------------------PASIR---------------------------//
glColor3f(1.0f, 0.89f, 0.70f);
glBegin(GL_POLYGON); 
glVertex2i(0, -5);
glVertex2i(0, 350);
glVertex2i(180, 350);
glVertex2i(260, 0);
glEnd();

//TEMBOK PEMBATAS 
glColor3f(0,0,0);
glBegin(GL_POLYGON); 
glVertex2i(80, 270);
glVertex2i(80, 350);
glVertex2i(85, 350);
glVertex2i(85, 270);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(80, 270);
glVertex2i(0, 220);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(80, 300);
glVertex2i(0, 250);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(80, 330);
glVertex2i(0, 280);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(80, 350);
glVertex2i(0, 310);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(0, 180);
glVertex2i(85, 80);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(0, 150);
glVertex2i(85, 50);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(0, 120);
glVertex2i(85, 20);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(0, 90);
glVertex2i(85, -5);
glEnd();


glColor3f(0,0,0);
glBegin(GL_POLYGON); 
glVertex2i(80, 0);
glVertex2i(80, 80);
glVertex2i(85, 80);
glVertex2i(85, 0);
glEnd();

//ORANG 1
glColor3f(0,0,0);
glBegin(GL_POLYGON); 
glVertex2i(140, 120);
glVertex2i(140, 145);
glVertex2i(165, 145);
glVertex2i(165, 120);
glEnd();

glColor3f(1,1,1);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2i(145, 135);
glEnd();

glColor3f(1,1,1);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2i(160, 135);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2i(145, 125);
glVertex2i(160, 125);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(150, 80);
glVertex2i(150, 120);

glVertex2i(150, 120);
glVertex2i(140, 80);

glVertex2i(150, 120);
glVertex2i(160, 80);

glVertex2i(150, 80);
glVertex2i(140, 40);

glVertex2i(150, 80);
glVertex2i(160, 40);
glEnd();

//ORANG 2
glColor3f(0,0,0);
glBegin(GL_POLYGON); 
glVertex2i(140, 300);
glVertex2i(140, 325);
glVertex2i(165, 325);
glVertex2i(165, 300);
glEnd();

glColor3f(1,1,1);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2i(145, 315);
glEnd();

glColor3f(1,1,1);
glPointSize(5.0);
glBegin(GL_POINTS);
glVertex2i(160, 315);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES);
glVertex2i(145, 305);
glVertex2i(160, 305);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES);
glVertex2i(150, 300);
glVertex2i(150, 260);

glVertex2i(150, 300);
glVertex2i(140, 260);

glVertex2i(150, 300);
glVertex2i(160, 260);



glVertex2i(150, 260);
glVertex2i(140, 220);

glVertex2i(150, 260);
glVertex2i(160, 220);

glEnd();

//------------------kapal besar----------//
//bawah 
glColor3f(0,0,0);
glBegin(GL_POLYGON); 
glVertex2i(295, 150);
glVertex2i(260, 200);
glVertex2i(500, 200);
glVertex2i(464, 150);
glEnd();

glColor3f(1,1,1);
glBegin(GL_LINES); 
glVertex2i(260,200);
glVertex2f(500,200);
glEnd();

//hitam 1
glColor3f(0,0,0);
glBegin(GL_POLYGON); 
glVertex2i(280, 202);
glVertex2i(280, 220);
glVertex2i(290, 220);
glVertex2i(290, 202);
glEnd();

//tengah
glColor3f(0.58, 0.29, 0.0);
glBegin(GL_POLYGON); 
glVertex2i(300, 201);
glVertex2i(340, 235);
glVertex2i(464, 235);
glVertex2i(464, 201);
glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON); 
glVertex2i(454, 202);
glVertex2i(454, 220);
glVertex2i(463, 220);
glVertex2i(463, 202);
glEnd();

glColor3f(0,0,0);
glPointSize(3.0);
glBegin(GL_POINTS);
glVertex2i(460, 210);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES); 
glVertex2i(340,235);
glVertex2f(300,201);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES); 
glVertex2i(340,235);
glVertex2f(464,235);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES); 
glVertex2i(464,235);
glVertex2f(464,201);
glEnd();

//atas
glColor3f(0.58, 0.29, 0.0);
glBegin(GL_POLYGON); 
glVertex2i(365, 236);
glVertex2i(365, 280);
glVertex2i(395, 280);
glVertex2i(395, 236);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES); 
glVertex2i(365,281);
glVertex2f(395,281);
glEnd();

glColor3f(0.58, 0.29, 0.0);
glBegin(GL_POLYGON); 
glVertex2i(410, 236);
glVertex2i(410, 280);
glVertex2i(440, 280);
glVertex2i(440, 236);
glEnd();

glColor3f(0,0,0);
glBegin(GL_LINES); 
glVertex2i(410,281);
glVertex2f(440,281);
glEnd();

//kaca
glColor3f(1,1,1);
glBegin(GL_POLYGON); 
glVertex2i(410, 225);
glVertex2i(410, 230);
glVertex2i(440, 230);
glVertex2i(440, 225);
glEnd();

glColor3f(1,1,1);
glBegin(GL_POLYGON); 
glVertex2i(365, 225);
glVertex2i(365, 230);
glVertex2i(395, 230);
glVertex2i(395, 225);
glEnd();

//-----------------kapal kecil---------//
glColor3f(0.38, 0.29, 0.18);
glBegin(GL_POLYGON); 
glVertex2i(320, 40);
glVertex2i(280, 80);
glVertex2i(455, 80);
glVertex2i(415, 40);
glEnd();

glColor3f(0.0, 0.255f, 0.255f);
glBegin(GL_POLYGON);
glVertex2i(350, 100);
glVertex2i(350, 120);
glVertex2i(380, 100);
glEnd();

glColor3f(0.0, 0.0, 0.0);
glBegin(GL_LINES);
glVertex2i(350, 80);
glVertex2i(350, 120);
glEnd();

glFlush();
}

void myinit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10.0);
	glLineWidth(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("Points");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}