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

	GLfloat Va[] = { 0.4,0.4,0.4,1 };           //光源环境光强度数组  
	GLfloat Vd[] = { 0.6,0.6,0.6,1 };           //光源散射光强度数组  
	GLfloat Vs[] = { 0.6,0.6,0.6,1 };           //光源镜面反射光强度数组  
	GLfloat Vp[] = { 1,1,1,1 };             //光源位置数组  
	glLightfv(GL_LIGHT0, GL_AMBIENT, Va); //设置0号光源的环境光属性  
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Vd); //设置0号光源的散射光属性  
	glLightfv(GL_LIGHT0, GL_SPECULAR, Vs);    //设置0号光源的镜面反射光属性  
	glLightfv(GL_LIGHT0, GL_POSITION, Vp);    //设置0号光源的位置属性
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);//启用颜色追踪  
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	myCone();
	myIceCream();
	myCherry();
	myRoll();
	myUnknownObject();

	glDisable(GL_LIGHTING);//关闭光照  
	glDisable(GL_LIGHT0);//关闭０号光源
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