#include<windows.h>
#include<gl/freeglut.h>
#include<gl/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(5.0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	glLineWidth(2.0f);
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void Display(void)
{
	float	mx1 = 50, my1 = 50, lx1 = 150, ly1 = 200, cx1 = 50, cy1 = 200, hx1 = 150, hy1 = 50, 
			mx2 = 100, my2 = 50, lx2 = 200, ly2 = 200, cx2 = 100, cy2 = 200, hx2 = 200, hy2 = 50,
			A, B, C, D, Ba1, Ba2, Ba3, Ba4, Ch1, Ch2, Ch3, Ch4, Ch5, Ch6, Ch7, Ch8;
	
	glClear(GL_COLOR_BUFFER_BIT);

//garis kuning
	glBegin(GL_LINES);
		glColor3f(1,1,0);
		glVertex2f(mx1, my1);
		glVertex2f(lx1, ly1);
	glEnd();

//garis biru
	glBegin(GL_LINES);
		glColor3f(0,0,1);
		glVertex2f(cx1, cy1);
		glVertex2f(hx1, hy1);
	glEnd();

//garis hijau
	glBegin(GL_LINES);
		glColor3f(0,1,0);
		glVertex2f(mx2, my2);
		glVertex2f(lx2, ly2);
	glEnd();

//garishitam	
	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(cx2, cy2);
		glVertex2f(hx2, hy2);
	glEnd();
	
//kotak diluar
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(50, 50);
		glVertex2i(200, 50);
		glVertex2f(200,200);
		glVertex2i(50, 200);

	glEnd();

//----------------------------------------Rumus-----------------------------------------------

	A=(ly1-my1)/(lx1-mx1);
	B=(hy1-cy1)/(hx1-cx1);
	C=(ly2-my2)/(lx2-mx2);
	D=(hy2-cy2)/(hx2-cx2);
	Ba1=my1-(mx1*A);
	Ba2=cy1-(cx1*B);
	Ba3=my2-(mx2*C);
	Ba4=cy2-(cx2*D);

//-----------------------------------------Titik Potong-----------------------------------------

	Ch1=(Ba2-Ba1)/(A-B);
	Ch2=(A*Ch1)+Ba1;
	Ch3=(Ba4-Ba1)/(A-D);
	Ch4=(A*Ch3)+Ba1;
	Ch5=(Ba3-Ba2)/(B-C);
	Ch6=(B*Ch5)+Ba2;
	Ch7=(Ba4-Ba3)/(C-D);
	Ch8=(C*Ch7)+Ba3;

//-----------------------------------------Hasil------------------------------------------------
	glBegin(GL_POINTS);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(Ch1, Ch2);
	glVertex2f(Ch3, Ch4);
	glVertex2f(Ch5, Ch6);
	glVertex2f(Ch7, Ch8);
	glEnd();
	
	glFlush(); 
}
 
int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

	glutInitWindowSize (640, 480);
	glutInitWindowPosition (400, 250);

	glutCreateWindow("Tugas3-Perpotongan-672017023"); 
	glutDisplayFunc(Display); 
	myInit();
	glutMainLoop(); 
}