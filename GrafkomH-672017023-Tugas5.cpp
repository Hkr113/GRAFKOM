#include <iostream>
#include <GL/freeglut.h>
#include <Windows.h>
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);

int is_depth;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
float xtrans = 0.0f;
float ytrans = 0.0f;
float ztrans = 0.0f;


void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	/*glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);*/
	glEnable(GL_DEPTH_TEST);
	glPointSize(9.0);
	glLineWidth(2.0f);
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, lebar, tinggi);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

void kubus(int ex, int ey, int ez, int p, int l, int t) {
	glBegin(GL_QUADS);
	//Depan
	glVertex3d(ex, ey, ez);  //TITIK KIRI BAWAH
	glVertex3d(ex, ey + t, ez);  //TITIK KIRI ATAS
	glVertex3d(ex + p, ey + t, ez);  //TITIK KANAN ATAS
	glVertex3d(ex + p, ey, ez);  //TITIK KANAN BAWAH

	//Belakang
	glVertex3d(ex, ey, ez + l);  //TITIK KIRI BAWAH
	glVertex3d(ex, ey + t, ez + l);  //TITIK KIRI ATAS
	glVertex3d(ex + p, ey + t, ez + l);  //TITIK KANAN ATAS
	glVertex3d(ex + p, ey, ez + l);  //TITIK KANAN BAWAH

	//Kiri
	glVertex3d(ex, ey, ez);  //TITIK DEPAN BAWAH
	glVertex3d(ex, ey + t, ez);  //TITIK DEPAN ATAS
	glVertex3d(ex, ey + t, ez + l);  //TITIK BELAKANG ATAS
	glVertex3d(ex, ey, ez + l);  //TITIK BELAKANG BAWAH

	//Kanan
	glVertex3d(ex + p, ey, ez);  //TITIK DEPAN BAWAH
	glVertex3d(ex + p, ey + t, ez);  //TITIK DEPAN ATAS
	glVertex3d(ex + p, ey + t, ez + l);  //TITIK BELAKANG ATAS
	glVertex3d(ex + p, ey, ez + l);  //TITIK BELAKANG BAWAH

	//Atas
	glVertex3d(ex, ey + t, ez);  //TITIK DEPAN KIRI
	glVertex3d(ex + p, ey + t, ez);  //TITIK DEPAN KANAN
	glVertex3d(ex + p, ey + t, ez + l);  //TITIK BELAKANG KANAN
	glVertex3d(ex, ey + t, ez + l);  //TITIK BELAKANG KIRI

	//Bawah
	glVertex3d(ex, ey, ez);  //TITIK DEPAN KIRI
	glVertex3d(ex + p, ey, ez);  //TITIK DEPAN KANAN
	glVertex3d(ex + p, ey, ez + l);  //TITIK BELAKANG KANAN
	glVertex3d(ex, ey, ez + l);  //TITIK BELAKANG KIRI
	glEnd();
}

void bangunan(void) {
	//=============================================
	// tanah
	glColor3f(0.99, 0.90, 0.65);
	kubus(-500, -27, -500, 1000, 1000, 2);

	//Lantai
	glColor3f(0.752941, 0.752941, 0.752941);
	kubus(-20, -25,-150, 300, 100, 2); //lantai 1 kiri

	kubus(-20, -25, -50, 300, 150, 2); //lantai 1 kanan
	
//------------------------------------------------------------------KOSTKU-------------------------------------------------------------------------
	glColor3f(0.58, 0.29, 0);
	kubus(60, -24, -150, 2, 105, 105);      //sekat 1	
	kubus(133, -24, -150, 2, 105, 100);      //sekat 2
	kubus(206, -24, -150, 2, 105, 100);      //sekat 3


	//atap
	glColor3f(0, 0, 0);
	kubus(61, 75, -150, 222, 100, 15);
	glColor3f(1,1,1);
	kubus(81, 90, -135, 182, 70, 15);
	glColor3f(0, 0, 0);
	kubus(101, 105, -120, 142, 40, 15);
	glColor3f(1,1,1);
	kubus(121, 120, -105, 102, 10, 15);

//tembok
	glColor3f(0, 1, 0);
	kubus(-20, -24,	-50, 70,2, 50);      //depan 1

	kubus(280, -24, -150, 2, 250, 100);    //belakang
	kubus(-20, -24, -150, 300, 2, 100);   //kiri

	kubus(-20, -24, 98, 300, 2, 100);   //kanan 

	
	kubus(-16.5, -24, 10, 2, 90,50);      //tengah diantar tembok tengah dan kanan

	//tiang tembok
	kubus(-20, -24, -50, 10, 10, 75);      //kiri
	kubus(50, -24, -50, 10, 10, 75);      //kiri dalam
	kubus(-20, -24, 0, 10,10, 75);      //tengah


	kubus(-20, -24, 88, 10,10, 75);      //kanan

	glColor3f(0, 0, 0);
	kubus(-12, 20, -49, 68, 2, 30);      //depan ketas

	kubus(-16.5, 30, 10, 2, 85, 20);      //tengah diantar tembok tengah dan kanan

	//pagar
	kubus(-16.5, -24, -40, 2, 40, 75);      //kiri
	//gembok
	glColor3f(1, 1, 1);
	kubus(-17, 30, -30, 2, 20, 5);      //kiri

	glPopMatrix();
}

void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glTranslatef(xtrans, ytrans, ztrans);
	glPushMatrix();
	bangunan();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		//gerak ke kanan
	case 'a':
	case 'A':
		xtrans -= 1.0;
		break;
		//gerak ke kiri
	case 'd':
	case 'D':
		xtrans += 1.0;
		glTranslatef(1.0, 0.0, 0.0);
		break;
		//gerak ke depan
	case 'w':
	case 'W':
		ztrans += 1.0;
		glTranslatef(0.0, 0.0, 1.0);
		break;
		//gerak ke belakang
	case 's':
	case 'S':
		ztrans -= 1.0;
		glTranslatef(0.0, 0.0, -1.0);
		break;
		//gerak ke bawah
	case 'q':
	case 'Q':
		ytrans += 1.0;
		glTranslatef(0.0, 1.0, 0.0);
		break;
		//gerak ke atas
	case 'e':
	case 'E':
		ytrans -= 1.0;
		glTranslatef(0.0, -1.0, 0.0);
		break;

// putar
	case 'j':
	case 'J':
		yrot -= 1.0;
		glRotatef(1.0, 0.0, -1.0, 0.0);
		break;
	case 'i':
	case 'I':
		xrot -= 1.0;
		glRotatef(1.0, 0.0, 0.0, -1.0);
		break;
	case 'k':
	case 'K':
		xrot += 1.0;
		glRotatef(1.0, 0.0, 0.0, -1.0);
		break;
	case 'o':
	case 'O':
		yrot += 1.0;
		glRotatef(1.0, 0.0, -1.0, 0.0);
		break;
//buka tutup
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
		break;
//keluar
	case 'm':
		exit(1);
		break;

	}
	glutPostRedisplay();
}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("Michael Christian Halim - 672017023");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}
