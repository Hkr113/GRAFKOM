#include<windows.h>
#include<gl/freeglut.h>
#include<gl/glut.h>

void display() {
glClear(GL_COLOR_BUFFER_BIT);

//trapesium
glBegin(GL_POLYGON);
glColor3f(0.0, 0.255f, 0.255f);
glVertex2i(30, 250);
glVertex2i(60, 350);
glVertex2i(190, 350);
glVertex2i(220, 250);
glEnd();


//persegi
glBegin(GL_LINE_LOOP);
glColor3f(0.41f, 0.35f, 0.23f);
glVertex2i(280, 350);
glVertex2i(280, 250);
glVertex2i(380, 250);
glVertex2i(380, 350);
glEnd();


//belah ketupat
glBegin(GL_LINES);
glColor3f(0.16,0.39,0);
glVertex2i(480, 350);
glVertex2i(440, 300);
glVertex2i(440, 300);
glVertex2i(480, 250);

glVertex2i(480, 350);
glVertex2i(520, 300);
glVertex2i(520, 300);
glVertex2i(480, 250);
glEnd();

glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glLineWidth(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 500);
	glutInitWindowPosition(300, 150);
	glutCreateWindow("672017023");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
	return 0;
}