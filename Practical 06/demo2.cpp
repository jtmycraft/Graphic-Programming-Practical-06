#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <conio.h>
#include <string>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "OpenGL Window"


LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CHAR:
		break;

	case WM_KEYDOWN:
		break;

	default:
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
//--------------------------------------------------------------------

bool initPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd;
	ZeroMemory(&pfd, sizeof(PIXELFORMATDESCRIPTOR));

	pfd.cAlphaBits = 8;
	pfd.cColorBits = 32;
	pfd.cDepthBits = 24;
	pfd.cStencilBits = 0;

	pfd.dwFlags = PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW;

	pfd.iLayerType = PFD_MAIN_PLANE;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;

	// choose pixel format returns the number most similar pixel format available
	int n = ChoosePixelFormat(hdc, &pfd);

	// set pixel format returns whether it sucessfully set the pixel format
	if (SetPixelFormat(hdc, n, &pfd))
	{
		return true;
	}
	else
	{
		return false;
	}
}
//--------------------------------------------------------------------

void myCone()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(171, 124, 44);
	glRotatef(70, 1, 0, 0);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluCylinder(var, 0.25f, 0.005f, 0.9f, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(209, 164, 88);
	glRotatef(70, 1, 0, 0);
	gluQuadricDrawStyle(var, GLU_LINE);
	gluCylinder(var, 0.25f, 0.005f, 0.9f, 32, 32);
	glPopMatrix();
}

void myIceCream()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(180, 255, 145);
	glRotatef(70, 1, 0, 0);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluSphere(var, 0.235f, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(227, 227, 227);
	glTranslatef(0, 0.25f, -0.05f);
	glRotatef(70, 1, 0, 0);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluSphere(var, 0.22f, 32, 32);
	glPopMatrix();
}

void myCherry()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(255, 31, 31);
	glTranslatef(0.15f, 0.4f, -0.15f);
	glRotatef(70, 1, 0, 0);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluSphere(var, 0.05f, 32, 32);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.15f, 0.4f, -0.15f);
	glRotatef(70, 1, 1, 0);
	glBegin(GL_LINE_STRIP);
	glColor3ub(255, 31, 31);
	glVertex3f(0.1f, 0.15f, 0);
	glVertex3f(0, 0.15f, 0);
	glVertex3f(0, 0, 0);
	glEnd();
	glPopMatrix();
}

void myRoll()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(87, 48, 0);
	glTranslatef(0, 0.35f, -0.21f);
	glRotatef(-70, 1, 0, 1);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluCylinder(var, 0.03f, 0.03f, 0.5f, 32, 32);
	glPopMatrix();
}

void myUnknownObject()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(255, 247, 135);
	glTranslatef(-0.15f, 0.45f, -0.13f);
	glRotatef(90, 0, 0, 1);
	gluQuadricDrawStyle(var, GLU_LINE);
	gluCylinder(var, 0.069f, 0.07f, 0.1f, 32, 32);
	glPopMatrix();
}

void display()
{
	glClearColor(0.18f, 0.04f, 0.14f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	GLfloat Va[] = { 0.4,0.4,0.4,1 };           //��Դ������ǿ������  
	GLfloat Vd[] = { 0.6,0.6,0.6,1 };           //��Դɢ���ǿ������  
	GLfloat Vs[] = { 0.6,0.6,0.6,1 };           //��Դ���淴���ǿ������  
	GLfloat Vp[] = { 1,1,1,1 };             //��Դλ������  
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 5.0 };
	GLfloat hig_shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.3,0.8, 0.0, 1.0 };

	GLfloat light_diffuse[] = { 0.0, 0.0, 1.0, 1.0 };//��ɫ        //�еƹ�������ֲ��ʵ�Ч�������ĵƹ��ǿ������Ĺ�ϵ��ò�����������ʲô�ġ�(0-1)��Χ��
	GLfloat light_position[] = { 0, 3, 2.0, 0.0 };        //���õ��Դ�ľ����������Ҳ߯����ˣ�1�����ű䣬0���ű䣬����Ϊ͸��֮������1���ű䣬0�����ű䡣
	GLfloat light_specular[] = { 1.0, 1.0, 0.0, 1.0 };        //�����
	GLfloat light_ambient[] = { 0.5, 0.5, 0.5, 1.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);        //����������������Ч���͸߹��Ч��
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);    //���Դû��������Ч������һֱ�Ǻ�ɫ�ġ������и߹ⷴ���Ч����
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);        //��������û��Ч�����������Ҳ�֪����

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);    //���ʲô�������ã�GL_LIGHT��Ĭ�ϵ�ֵ��
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);

	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	//��һ�еڶ��е������������Ⱦ���⣬�͸߹⣬���޻�����
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glColor3f(1.0, 1.0, 1.0);
	gluSphere(var, 0.5f, 32, 32);//���ÿ⺯������һ���뾶Ϊ1�����塣
	glPopMatrix();

	glDisable(GL_LIGHTING);//�رչ���  
	glDisable(GL_LIGHT0);//�رգ��Ź�Դ
}

//--------------------------------------------------------------------

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance,
	_In_ LPSTR cmdLine, _In_ int nCmdShow) // FIXED
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.hInstance = GetModuleHandle(NULL);
	wc.lpfnWndProc = WindowProcedure;
	wc.lpszClassName = WINDOW_TITLE;
	wc.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wc)) return false;

	HWND hWnd = CreateWindow(WINDOW_TITLE, WINDOW_TITLE, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, wc.hInstance, NULL);

	//--------------------------------
	//	Initialize window for OpenGL
	//--------------------------------

	HDC hdc = GetDC(hWnd);

	//	initialize pixel format for the window
	initPixelFormat(hdc);

	//	get an openGL context
	HGLRC hglrc = wglCreateContext(hdc);

	//	make context current
	if (!wglMakeCurrent(hdc, hglrc)) return false;

	//--------------------------------
	//	End initialization
	//--------------------------------

	ShowWindow(hWnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		display();

		SwapBuffers(hdc);
	}

	UnregisterClass(WINDOW_TITLE, wc.hInstance);

	return true;
}
//--------------------------------------------------------------------