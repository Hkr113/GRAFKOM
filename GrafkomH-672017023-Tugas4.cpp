
#include <iostream>
#include <Windows.h>
#include <GL/freeglut.h>


float m = 0.0f;
float d = 0.02f;
float x_pos = 0.0f;
float y_pos = 0.0f;
float delta = 0.025f;
bool right = true;
bool top = true;
float i (float a);

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2f(0.0f + x_pos, i (0.0f + y_pos));

	glEnd();

	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-0.1f + m, 0.1f);

	glEnd();

	glutSwapBuffers();
}
float i(float a) {
	float Amplitudo = 2 / 2;
	float Panjang_Gelombang = 2 * 3.14 / 2;
	return Amplitudo * sin(Panjang_Gelombang * a);
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0f, 1.0, -1.0f, 1.0f);
}
void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000/30, timer, 0);
	if (x_pos < 0.8f && right)
		x_pos += delta;
	else
		right = false;
	if (x_pos > -0.8f && !right)
		x_pos -= delta;
	else
		right = true;

	if (i(y_pos) < 0.10f && top)
		y_pos += delta;
	else
		top = false;
	if (i(y_pos) > -0.10f && !top)
		y_pos -= delta;
	else
		top = true;

	if (m < 0.10f && right)
		m += d;
	else 
		right = false;

	if (m > -0.10f && !right)
		m -= d;
	else
		right = true;
	}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(400, 200);
	
	glutCreateWindow("672017023-ANIMASI");
	glutDisplayFunc(display);

	myinit();
	glutTimerFunc(0, timer, 0);
	glutMainLoop();

	return 0;
}