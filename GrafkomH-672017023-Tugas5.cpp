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

bool mouseDown = false;


void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
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
	glColor3f(0.0, 1.0, 0.0);
	kubus(-500, -27, -500, 1200, 1200, 2);
	//Lantai
	glColor3f(6.0, 6.0, 6.0);
	kubus(-5, 0, -20, 175, 130, 4);
	//=============================================
	//Kaki Pangggung
			//baris ke 1 kiri
	int kz = -20;
	for (int a = 0; a < 6; a++) {
		glColor3f(150, 75, 0);
		kubus(-5, -25, kz, 5, 5, 25);
		kz += 25;
	}
	kz = -20;
	//baris ke 2 kiri
	for (int a = 0; a < 6; a++) {
		glColor3f(150, 75, 0);
		kubus(55, -25, kz, 5, 5, 25);
		kz += 25;
	}
	kz = -20;
	//baris ke 1 kanan
	for (int a = 0; a < 6; a++) {
		glColor3f(150, 75, 0);
		kubus(110, -25, kz, 5, 5, 25);
		kz += 25;
	}
	kz = -20;
	//baris ke 2 kanan
	for (int a = 0; a < 6; a++) {
		glColor3f(150, 75, 0);
		kubus(165, -25, kz, 5, 5, 25);
		kz += 25;
	}
	//=============================================
	//tembok
		//kiri
	glColor3f(0.5, 1.0, 1.0);
	kubus(-6, 4, -20, 2, 130, 50);//kiri
	kubus(170, 4, -20, 2, 130, 50);//kanan
	kubus(170, 4, -20, -175, 2, 50);//tembok belakang
	kubus(170, 4, 110, -175, 2, 50);//tembok depan
//=============================================
// kaki bagian tangga
	//kiri
	glColor3f(150, 75, 0);
	kubus(55, -25, -65, 5, 5, 45);
	kubus(55, -25, -95, 5, 5, 20); //kiri 1.1
	kubus(55, -25, -115, 5, 5, 20); //kiri 1.2
//kanan 
	glColor3f(150, 75, 0);
	kubus(-5, -25, -65, 5, 5, 45);
	kubus(-5, -25, -95, 5, 5, 20); //kanan 1.1
	kubus(-5, -25, -115, 5, 5, 20); //kanan 1.2
//tbk atas dikit
	glColor3f(0, 0, 0);
	kubus(55, 20, -69, 5, 50, 4.5);
	kubus(55, -5, -115, 5, 28, 4); // kiri ats dikit
	kubus(-5, 20, -69, 5, 50, 4.5);
	kubus(-5, -5, -115, 5, 28, 4); // kanan ats dikit

//Lantai 
	glColor3f(1.0, 0.5, 0.5);
	kubus(-5, 0, -65, 65, 45, 4); // tengah depan
	kubus(-5, -19, -115, 65, 25, 4); // paling bawah
	//=================================================
	//PINTU Luar

	glColor3f(1.0, 0.0, 0.24);
	kubus(20, 5, -21, 20, 2, 25);
	//Ganggang Pintu Luar
	glColor3f(0.0, 0.0, 0.0);
	kubus(24, 18, -23, 2, 2, 1);

	//Tangga
	glColor3f(1.0, 0.5, 0.5);
	kubus(0, -15, -91, 55, 10, 5);  // tangga 1 bawah
	kubus(0, -10, -85, 55, 10, 5); // tangga 2 bawah
	kubus(0, -5, -80, 55, 10, 5); // tangga 3 bawah
	kubus(0, 0, -75, 55, 10, 5); // tangga 4 bawah

	//=========ruang menonton besar=====================
	glColor3f(0.95, 0.64, 0.37);
	kubus(87.5, 4, 65, 2.5, 45, 30);
	kubus(-4, 4, 65, 80, 2.5, 30);
	//Tembok 1 Atas
	glColor3f(0.80, 0.52, 0.24);
	kubus(76.5, 24, 65, 11.5, 2.5, 10);
	//rak dinding
	glColor3f(1.0, 0.0, 1.0);
	kubus(-3, 15, 80, 2, 20, 0.5); //bawah
	kubus(-3, 30, 80, 2, 20, 0.5); //atas
	kubus(-3, 15, 90, 2, 12, 15); //kotak
	kubus(-3, 15, 78, 2, 2, 15); //kanan tutup
	kubus(-3, 25, 80, 2, 11, 0.5);//garis tengah

	glColor3f(1.0, 1.0, 0.5);
	kubus(30, 20, 67, 20, 1, 15); //papan
	glColor3f(0, 0, 0);
	kubus(40, 22, 69, 10, 1, 1); // tempat buat penghapus

	//Badan Meja
	glColor3f(0.98, 0.49, 0.31);
	kubus(35, 10, 80, 20, 10, 2);
	//kaki meja
	glColor3f(0.64, 0.16, 0.16);
	kubus(35, 4, 80, 2, 2, 8);
	kubus(53, 4, 80, 2, 2, 8);
	kubus(35, 4, 88, 2, 2, 8);
	kubus(53, 4, 88, 2, 2, 8);

	//kursi1
	glColor3f(0, 0, 0);
	kubus(20, 10, 75, 2, 20, 5);//sandaran
	glColor3f(0.0, 1.0, 1.0);
	kubus(20, 8, 75, 10, 20, 2); //dudukan
	//kaki
	glColor3f(1, 0, 0);
	kubus(20, 4, 75, 2, 2, 6);
	kubus(28, 4, 75, 2, 2, 6);
	kubus(20, 4, 93, 2, 2, 6);
	kubus(28, 4, 93, 2, 2, 6);

	//kursi tengah

	glColor3f(0, 0, 0);
	kubus(35, 10, 103, 20, 2, 5);//sandaran
	glColor3f(0.0, 1.0, 1.0);
	kubus(35, 8, 95, 20, 10, 2); //dudukan
	//kaki 
	glColor3f(0.64, 0.16, 0.16);
	kubus(35, 4, 95, 2, 2, 6);
	kubus(35, 4, 103, 2, 2, 6);
	kubus(53, 4, 95, 2, 2, 6);
	kubus(53, 4, 103, 2, 2, 6);


	//kursi2
	glColor3f(0, 0, 0);
	kubus(70, 10, 75, 2, 20, 5);//sandaran
	glColor3f(0.0, 1.0, 1.0);
	kubus(62, 8, 75, 10, 20, 2); //dudukan
	//kaki
	glColor3f(1, 0, 0);
	kubus(62, 4, 75, 2, 2, 6);
	kubus(70, 4, 75, 2, 2, 6);
	kubus(62, 4, 93, 2, 2, 6);
	kubus(70, 4, 93, 2, 2, 6);

	glColor3f(1, 1, 1);
	kubus(30, 28, 105, 30, 5, 8); //AC

	//======================KASUR=======================
		//Kaki Kasur
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, 4, 53, 2, 2, 2);
	kubus(10, 4, 53, 2, 2, 2);
	kubus(0, 4, 48, 2, 2, 2);
	kubus(10, 4, 48, 2, 2, 2);

	//Badan Kasur
	glColor3f(1, 0.5, 0);
	kubus(0, 5, 48, 12, 7, 2);
	//Bantal
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, 7, 49, 3, 5, 1);
	//=======================Meja==============
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, 4, 40, 2, 2, 2);
	kubus(0, 4, 43, 2, 2, 2);
	kubus(3, 4, 40, 2, 2, 2);
	kubus(3, 4, 43, 2, 2, 2);
	//Badan Meja
	glColor3f(0.98, 0.49, 0.31);
	kubus(0, 6, 40, 5, 5, 2);
	//=======================KASUR=======================
		//Kaki Kasur
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, 4, 15, 2, 2, 2);
	kubus(10, 4, 15, 2, 2, 2);
	kubus(0, 4, 10, 2, 2, 2);
	kubus(10, 4, 10, 2, 2, 2);
	//Badan Kasur
	glColor3f(1, 0.5, 0);
	kubus(0, 5, 10, 12, 7, 2);
	//Bantal
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, 7, 11.5, 3, 5, 1);
	//=======================Meja==============
	glColor3f(0.64, 0.16, 0.16);
	kubus(0, 4, 20, 2, 2, 2);
	kubus(0, 4, 23, 2, 2, 2);
	kubus(3, 4, 20, 2, 2, 2);
	kubus(3, 4, 23, 2, 2, 2);
	//Badan Meja
	glColor3f(0.98, 0.49, 0.31);
	kubus(0, 6, 20, 5, 5, 2);

	//===============tembok===============
	//Tembok Depan Kamar 1
	glColor3f(0.80, 0.52, 0.24);
	kubus(24, 4, 35, 2, 23, 30);
	//Tembok Depan Kamar 1 Atas
	glColor3f(0.80, 0.52, 0.24);
	kubus(24, 24, 58, 2, 7, 10);
	//Pintu Kamar 1
	glColor3f(1.0, 0.0, 0.0);
	kubus(24, 4, 58, 2, 7, 20);
	glColor3f(0.0, 0.0, 0.0);
	kubus(26, 12, 58, 1, 1, 1);
	//tembok penghadang1
	glColor3f(0.95, 0.64, 0.37);
	kubus(-4, 4, 33, 30, 2.5, 30);
	//tembok penghadang2
	glColor3f(0.95, 0.64, 0.37);
	kubus(-4, 4, 1.5, 30, 2.5, 30);
	//Tembok Depan Kamar 2 Atas
	glColor3f(0.80, 0.52, 0.24);
	kubus(24, 24, 3.5, 2, 7, 10);
	//Tembok Depan Kamar 2
	glColor3f(0.80, 0.52, 0.24);
	kubus(24, 4, 10, 2, 23, 30);
	//Pintu Kamar 2
	glColor3f(1.0, 0.0, 0.0);
	kubus(24, 4, 3.5, 2, 7, 20);
	glColor3f(0.0, 0.0, 0.0);
	kubus(26, 12, 3.5, 1, 1, 1);
	//=======================BARANG DILUAR===================
	//tv di tembok
	glColor3f(1, 1, 1);
	kubus(88, 18, 82, 2, 15, 2);
	glColor3f(0, 0, 0);
	kubus(88, 19, 82, 2, 15, 10);
	kubus(88, 6, 88, 2, 2, 12);
	kubus(88, 4, 82, 2, 15, 2);
	kubus(88, 4, 100, 5, 5, 8);
	kubus(88, 4, 74, 5, 5, 8);

	//karpet
	glColor3f(0, 0, 1);
	kubus(105, 4, 74, 20, 30, 1);
	glColor3f(1.0, 1.0, 0.0);
	kubus(138, 4, 70, 30, 40, 2.5);
	kubus(160, 4, 70, 8, 40, 15);

	//Tembok atas
	glColor3f(0.95, 0.64, 0.37);
	kubus(105, 24, 65, 19, 2, 10);
	//Tembok 1
	glColor3f(0.80, 0.52, 0.24);
	kubus(124, 4, 65, 48, 2, 30);
	kubus(89, 4, 65, 17, 2, 30);

	//------------------------------------

	glColor3f(0, 0, 0);
	//atap kanan1
	kubus(-11.5, 54, -24, 5, 139, 5);
	kubus(-6.5, 54, -24, 5, 139, 10);
	kubus(-1.5, 54, -24, 5, 139, 15);
	kubus(4, 54, -24, 5, 139, 20);
	kubus(9, 54, -24, 5, 139, 25);
	kubus(14, 54, -24, 5, 139, 30);
	kubus(19, 54, -24, 5, 139, 35);
	//atap kiri2
	kubus(53, 54, -24, 5, 139, 10);
	kubus(48, 54, -24, 5, 139, 15);
	kubus(43, 54, -24, 5, 139, 20);
	kubus(38, 54, -24, 5, 139, 25);
	kubus(33, 54, -24, 5, 139, 30);
	kubus(28, 54, -24, 5, 139, 35);
	kubus(23, 54, -24, 5, 139, 40);
	//atap kanan
	kubus(58, 54, -24, 5, 139, 5);
	kubus(63, 54, -24, 5, 139, 10);
	kubus(68, 54, -24, 5, 139, 15);
	kubus(73, 54, -24, 5, 139, 20);
	kubus(78, 54, -24, 5, 139, 25);
	kubus(83, 54, -24, 5, 139, 30);
	kubus(88, 54, -24, 5, 139, 35);
	kubus(93, 54, -24, 5, 139, 40);
	kubus(98, 54, -24, 5, 139, 45);
	kubus(103, 54, -24, 5, 139, 50);
	kubus(108, 54, -24, 5, 139, 55);
	kubus(113, 54, -24, 5, 139, 60);
	//atap kiri
	kubus(167, 54, -24, 10, 139, 5);
	kubus(162, 54, -24, 5, 139, 10);
	kubus(157, 54, -24, 5, 139, 15);
	kubus(152, 54, -24, 5, 139, 20);
	kubus(147, 54, -24, 5, 139, 25);
	kubus(142, 54, -24, 5, 139, 30);
	kubus(137, 54, -24, 5, 139, 35);
	kubus(132, 54, -24, 5, 139, 40);
	kubus(127, 54, -24, 5, 139, 45);
	kubus(122, 54, -24, 5, 139, 50);
	kubus(117, 54, -24, 5, 139, 55);

	//papan text
	glColor3f(0, 0, 0);
	kubus(80, -25, -80, 5, 5, 25);//papan kanan
	kubus(80, -5, -80, 90, 5, 40);//papannya buat diisi
	kubus(165, -25, -80, 5, 5, 25);//papan kiri

	glColor3f(1, 1, 1);
	//HURUF S
	kubus(155, 30, -81, 4, 1, 1);
	kubus(158, 27, -81, 1, 2, 4);
	kubus(155, 26, -81, 4, 1, 1);
	kubus(155, 22, -81, 1, 2, 4);
	kubus(155, 21, -81, 4, 1, 1);
	//HURUF U
	kubus(150, 21, -81, 1, 2, 10);
	kubus(147, 21, -81, 4, 1, 1);
	kubus(146, 21, -81, 1, 2, 10);
	//HURUF L
	kubus(140, 21, -81, 1, 2, 10);
	kubus(136, 21, -81, 4, 1, 1);
	//HURUF B
	kubus(131, 21, -81, 1, 2, 10);
	kubus(125, 30, -81, 5, 1, 1);
	kubus(125, 26, -81, 5, 1, 1);
	kubus(125, 21, -81, 5, 1, 1);
	kubus(125, 21, -81, 1, 2, 10);
	//HURUF A
	kubus(120, 21, -81, 1, 2, 10);
	kubus(115, 30, -81, 5, 1, 1);
	kubus(115, 26, -81, 5, 1, 1);
	kubus(115, 21, -81, 1, 2, 10);
	//HURUF R
	kubus(110, 21, -81, 1, 2, 10);
	kubus(106, 30, -81, 4, 1, 1);
	kubus(106, 26, -81, 4, 1, 1);
	kubus(105, 26, -81, 1, 2, 4);
	kubus(107, 21, -81, 1, 2, 5);
	//HURUF B
	kubus(150, 5, -81, 1, 2, 10);
	kubus(145, 14, -81, 4, 1, 1);
	kubus(145, 10, -81, 4, 1, 1);
	kubus(145, 5, -81, 4, 1, 1);
	kubus(145, 5, -81, 1, 2, 10);
	//HURUF O
	kubus(140, 5, -81, 1, 2, 8);
	kubus(136, 12, -81, 5, 1, 1);
	kubus(137, 5, -81, 4, 1, 1);
	kubus(136, 5, -81, 1, 2, 8);
	//HURUF Y
	kubus(132, 10, -81, 1, 2, 5);
	kubus(128, 10, -81, 4, 1, 1);
	kubus(128, 10, -81, 1, 2, 5);
	kubus(130, 5, -81, 1, 2, 6);
	//HURUF A
	kubus(124, 5, -81, 1, 2, 10);
	kubus(120, 14, -81, 5, 1, 1);
	kubus(120, 8, -81, 5, 1, 1);
	kubus(120, 5, -81, 1, 2, 10);
	//HURUF N
	kubus(116, 5, -81, 1, 2, 10);
	kubus(113, 14, -81, 4, 1, 1);
	kubus(112, 5, -81, 1, 2, 10);
	//HURUF G
	kubus(108, 5, -81, 1, 2, 10);
	kubus(105, 14, -81, 4, 1, 1);
	kubus(104, 10, -81, 3, 1, 1);
	kubus(105, 5, -81, 4, 1, 1);
	kubus(105, 5, -81, 1, 3, 5);
	//================================


	//==WADIDAW=====================
	glPushMatrix();
	glTranslatef(0.0, 28.0, -72.0);
	glRotatef(140.0f, -100.0f, 0.0f, 0.1f);
	glColor3f(0.0, 0.0, 0.0);
	kubus(-5, 0, -10, 5, 5, 35); // KANAN
	kubus(55, 0, -10, 5, 5, 35); // KIRI
	glEnd;

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
	glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
		//gerak ke kiri
	case 'a':
	case 'A':
		xtrans -= 1.0;
		break;
		//gerak ke kanan
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
		//gerak ke atas
	case 'q':
	case 'Q':
		ytrans += 1.0;
		glTranslatef(0.0, 1.0, 0.0);
		break;
		//gerak ke bawah
	case 'e':
	case 'E':
		ytrans -= 1.0;
		glTranslatef(0.0, -1.0, 0.0);
		break;
		//rotate ke kiri
	case 'j':
	case 'J':
		yrot -= 1.0;
		glRotatef(1.0, 0.0, -1.0, 0.0);
		break;
		//rotate ke kanan
	case 'k':
	case 'K':
		xrot += 0.3f;
		glRotatef(1.0, 0.0, 0.0, 5.0);
		break;
		//rotate ke atas
	case 'o':
	case 'O':
		glRotatef(1.0, -5.0, 0.0, 0.0);
		break;
		//rotate ke bawah
	case 'u':
	case 'U':
		glRotatef(1.0, 5.0, 0.0, 0.0);
		break;

	case 'm':
		exit(1);
		break;

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
