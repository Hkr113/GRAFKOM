#include <stdlib.h>
#include<windows.h>
#include <gl\gl.h>
#include <gl\glut.h>
#include <gl\glu.h>

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

bool mouseDown = false;

void init(void)
{
	glClearColor(0,0,0,0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
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

	//atap belakang
	glColor3f(0.58, 0.29, 0);
	glBegin(GL_TRIANGLES);
	glVertex3d(-120, 178, -100); //A
	glVertex3d(-55, 178,-100); //B
	glVertex3d(-85, 250,-50); //C
	//atap depan
	glVertex3d(-120, 178, 180); //A
	glVertex3d(-55, 178, 180); //B
	glVertex3d(-85, 250, 130); //C
	glEnd();
	//Kiri
	glBegin(GL_POLYGON);
	glVertex3d(-120, 178, -100); //A
	glVertex3d(-85, 250, -50); //C
	glVertex3d(-85, 250, 130);
	glVertex3d(-120, 178, 180);
	glEnd();
	//Kanan
	glBegin(GL_POLYGON);
	glVertex3d(-85, 250, -50); //C
	glVertex3d(-55, 178, -100); //B
	glVertex3d(-55, 178, 180); //B
	glVertex3d(-85, 250, 130); //C
	glEnd();

	//==========TANAH==========
	glColor3f(0.99, 0.90, 0.65);
	kubus(-500, -30, -500, 1000, 1000, 2);

	//==========TEMBOK==========
	glColor3f(0, 1, 0);
	kubus(-120, -25, -100, 2, 280, 200); //tembok kiri
	kubus(-120, -25, -100, 250, 2, 200); //tembok belakang
	kubus(131, -25, -100, 2, 280, 200); //tembok kanan

	//==========DASAR==========
	glColor3f(0.99, 0.90, 0.65);
	kubus(-107, -25, -100, 238, 300, 1); 

	//==========LANTAI DASAR ==========
	glColor3f(1,1,1);
	kubus(-120, -25, -20, 40, 30, 10); //TANGGA 1
	kubus(-120, -15, -30, 40, 15, 10); //TANGGA 2
	kubus(-120, -5, -40, 40, 15, 10); //TANGGA 3
	kubus(-120, 5, -50, 40, 15, 10); //TANGGA 4
	kubus(-120, 15, -60, 40, 15, 10); //TANGGA 5
	kubus(-105, 25, -100, 40, 40, 10); //tangga 6
	kubus(-75, 35, -100, 20, 40, 10); //TANGGA 7
	kubus(-65, 45, -100, 20, 40, 10); //TANGGA 8
	kubus(-55, 55, -100, 20, 40, 10); //TANGGA 9
	kubus(-55, 65, -70, 20, 230, 10); //TANGGA 10 + lantai depan
	kubus(-120, 65, -65, 80, 240, 10); // tutup tangga sekalian lt kmr atas

	//==========KAMAR SEDIKIT ==========
	glColor3f(0,1,0);
	kubus(-35, -25, -98, 2, 72, 200); //SEKAT1
	kubus(47, -25, -98, 2, 72, 200); //SEKAT2
	kubus(129, -25, -98, 2, 72, 200); //SEKAT3

	glColor3f(1, 1, 1);
	kubus(-33, -25, -100, 80, 75, 10); //bawah KAMAR 1
	kubus(-33, 65, -100, 80, 75, 10); //atas KAMAR 1
	
	kubus(49, 65, -100, 80, 75, 10); //atas KAMAR 1
	kubus(49, -25, -100, 80, 75, 10); //KAMAR 2

	kubus(-35, 65,-28, 168, 30, 10); //lt kamar atas

	glColor3f(0.74, 0.56, 0.46);
	kubus(-35, 65, 2, 168, 2, 30); //pembatas atas 1

	kubus(-35, 65, 2, 2, 160, 30); //pembatas atas 2

	kubus(-20, -25, 2, 150, 10, 20); //pembatas bawah 1

	kubus(-35, -25, 20, 10, 50, 20); //pembatas bawah 2
	kubus(-35, -25, 100, 10, 50, 20); //pembatas bawah 2


	glColor3f(0.58, 0.29 , 0); //atap kamar
	kubus(-118, 168, -100, 250, 75, 10); //1
	glColor3f(1, 1, 1);
	kubus(-120, 168, -100, 65, 280, 10); //2

	//==========KAMAR BANYAK ==========
	glColor3f(0, 1, 0);
	kubus(-120, -25, 10, 65, 2, 200); //SEKAT1
	kubus(-120, -25, 60, 65, 2, 200); //SEKAT2
	kubus(-120, -25, 110, 65, 2, 200); //SEKAT3
	kubus(-120, -25, 160, 65, 2, 200); //SEKAT4

	//---------------------------------------------------
	glColor3f(0.752941, 0.752941, 0.752941);
	kubus(-55, -25, 160, 20, 17, 200); //tembok 1
	kubus(20, -25, 160, 20, 20, 100); //tembok 2
	kubus(110, -25, 160, 20, 20, 100); //tembok 3

	glColor3f(0, 0, 0);
	kubus(-38, -25, 165, 58, 2, 100); //pager1
	kubus(40, -25, 165, 70, 2, 40); //pager2 bawah
	kubus(40,30, 165, 70, 2, 5); //pager2 atas 1
	kubus(40, 50, 165, 70, 2, 5); //pager2 atas 2
	kubus(40, 70, 165, 70, 2, 5); //pager2 atas 3
	glColor3f(1, 1, 1);
	kubus(-25, 30, 163.5, 30, 5, 20); //pager1

	//======================KASUR bawah=======================
	//Kaki Kasur

	glColor3f(0.64, 0.16, 0.16);
	kubus(-118, -25, 20, 5, 5, 5); //1
	kubus(-118, -25, 40, 5, 5, 5); //1
	kubus(-80, -25, 20, 5, 5, 5); //1
	kubus(-80, -25, 40, 5, 5, 5); //1

	kubus(-118, -25, 63, 5, 5, 5); //2
	kubus(-118, -25, 83, 5, 5, 5); //2
	kubus(-80, -25, 63, 5, 5, 5); //2
	kubus(-80, -25, 83, 5, 5, 5); //2

	//Badan Kasur
	glColor3f(1, 1, 1);
	kubus(-118, -20, 20, 45, 25, 5); // 1
	kubus(-118, -20, 63, 45, 25, 5); // 2

	//Bantal
	glColor3f(0, 0, 0);
	kubus(-118, -18, 22, 10, 20, 5); //1
	kubus(-118, -18, 65, 10, 20, 5); //2

	//=======================Meja==============
	glColor3f(0.64, 0.16, 0.16);
	kubus(-118, -25, 90, 2,2,5); //2
	kubus(-118, -25, 105, 2,2, 5); //2
	kubus(-110, -25, 90, 2,2, 5); //2
	kubus(-110, -25, 105, 2,2, 5); //2
	//Badan Meja
	glColor3f(0.98, 0.49, 0.31);
	kubus(-118, -20, 90, 10, 17, 5); // 2
	//=============================================
		//======================KASUR atas=======================
	//Kaki Kasur

	glColor3f(0.64, 0.16, 0.16);
	kubus(-118, 75, 20, 5, 5, 5); //1
	kubus(-118, 75, 40, 5, 5, 5); //1
	kubus(-80, 75, 20, 5, 5, 5); //1
	kubus(-80, 75, 40, 5, 5, 5); //1

	kubus(-118, 75, 63, 5, 5, 5); //2
	kubus(-118, 75, 83, 5, 5, 5); //2
	kubus(-80, 75, 63, 5, 5, 5); //2
	kubus(-80, 75, 83, 5, 5, 5); //2

	//Badan Kasur
	glColor3f(1, 1, 1);
	kubus(-118, 80, 20, 45, 25, 5); // 1
	kubus(-118, 80, 63, 45, 25, 5); // 2

	//Bantal
	glColor3f(0, 0, 0);
	kubus(-118, 82, 22, 10, 20, 5); //1
	kubus(-118, 82, 65, 10, 20, 5); //2

	//=======================Meja==============
	glColor3f(0.64, 0.16, 0.16);
	kubus(-118, 75, 90, 2, 2, 5); //2
	kubus(-118, 75, 105, 2, 2, 5); //2
	kubus(-110, 75, 90, 2, 2, 5); //2
	kubus(-110, 75, 105, 2, 2, 5); //2
	//Badan Meja
	glColor3f(0.98, 0.49, 0.31);
	kubus(-118, 80, 90, 10, 17, 5); // 2

	glColor3f(1, 1, 1);
	kubus(0, 40, -98, 30, 5, 8); //AC1
	glColor3f(0, 0, 0);
	kubus(0, 10, -98, 100, 10, 5); //tempat barang" pajang
	kubus(-33, 0, -80, 2, 20, 20); //tv
	glColor3f(1, 1, 1);
	kubus(-33, -5, -80, 2, 20, 5); //tv tombol

	//Kaki Kasur
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, -15, -80, 5, 5, 5); 
	kubus(40, -15, -80, 14, 5, 5); 
	kubus(40, -15, -50, 14, 5, 5);
	kubus(0, -15, -50, 5, 5, 5);
	kubus(90, -15, -80, 5, 5, 5);
	kubus(90, -15, -50, 5, 5, 5);

	//Badan Kasur
	glColor3f(1, 1, 1);
	kubus(0, -10, -80, 100, 35, 5); 

	//Bantal
	glColor3f(0, 0, 0);
	kubus(40, -5, -70, 20, 10, 2); //tv

	glColor3f(0, 1, 0);
	kubus(-35, -25, -25, 168, 2, 200); //pembatas kamar dikit

	kubus(-58, -25, 10, 2, 100, 198);  //pembatas kamar banyak
	
	kubus(-58, -25, 10, 2, 100, 198);  //pembatas kamar banyak
	kubus(-58, 65, 90, 2, 70, 80); //pembatas bawah 2

	//PINTU
	glColor3f(0.23, 0.18, 0.17);
	//glColor3f(0.36, 0.26, 0.17);
	kubus(-57, 65, 130, 2, 20, 40); //pintu3
	kubus(-57, 65, 70, 2, 20, 40); //pintu2
	kubus(-57, 65, 30, 2, 20, 40); //pintu1

	kubus(-57, -25, 70, 2, 20, 40); //pintu2
	kubus(-57, -25, 30, 2, 20, 40); //pintu1

	//gagang
	glColor3f(0,0,1);
	kubus(-55, 90, 130, 1, 2, 5); //pintu3
	kubus(-55, 90, 70, 1, 2, 5); //pintu2
	kubus(-55, 90, 30, 1, 2, 5); //pintu1

	kubus(-55, -5, 70, 1, 2, 5); //pintu2
	kubus(-55, -5, 30, 1, 2, 5); //pintu1

		//PINTU
	glColor3f(0.23, 0.18, 0.17);
	//glColor3f(0.36, 0.26, 0.17);
	
	kubus(70, 65, -23, 20, 2, 40); //pintu2
	kubus(0, 65, -23, 20, 2, 40); //pintu1

	kubus(70, -25, -23, 20, 2, 40); //pintu2
	kubus(0, -25, -23, 20, 2, 40); //pintu1

	//gagang
	glColor3f(0, 0, 1);

	kubus(70, 90, -21, 2, 1, 5); //pintu2
	kubus(0, 90, -21, 2, 1, 5); //pintu1

	kubus(70, -5, -21, 2, 1, 5); //pintu2
	kubus(0, -5, -21, 2, 1, 5); //pintu1

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

	case 'd':
	case 'D':
		xtrans -= 1.0;
		break;
		//gerak ke kiri
	case 'a':
	case 'A':
		xtrans += 1.0;
		glTranslatef(1.0, 0.0, 0.0);
		break;
		//gerak ke belakang
	case 'w':
	case 'W':
		ztrans += 1.0;
		glTranslatef(0.0, 0.0, 1.0);
		break;
		//gerak ke depan
	case 's':
	case 'S':
		ztrans -= 1.0;
		glTranslatef(0.0, 0.0, -1.0);
		break;
		//gerak ke bawah
	
	case 'e':
	case 'E':
		ytrans += 1.0;
		glTranslatef(0.0, 1.0, 0.0);
		break;
		//gerak ke atas
	case 'q':
	case 'Q':
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

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
	glutPostRedisplay();
}

void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		glutPostRedisplay();
	}
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
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}

