#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iostream>
#include <conio.h>
#include <string>

#pragma comment (lib, "OpenGL32.lib")
#pragma comment (lib, "GLU32.lib")

#define WINDOW_TITLE "OpenGL Window"

GLfloat Va[] = { 0.4,0.4,0.4,1 };           //光源环境光强度数组  
GLfloat Vd[] = { 0.6,0.6,0.6,1 };           //光源散射光强度数组  
GLfloat Vs[] = { 0.6,0.6,0.6,1 };           //光源镜面反射光强度数组  
GLfloat Vp[] = { 1,1,1,1 };             //光源位置数组 

bool lightOn = false;
char objCode = 'O';
float rotateDeg = 0;

LRESULT WINAPI WindowProcedure(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CHAR:
		switch (wParam)
		{
		case 0x4F:
			objCode = 'O';
			break;
		case 0x50:
			objCode = 'P';
			break;
		case 0x57: // W
			Vp[1] += 0.1f;
			break;
		case 0x53: // S
			Vp[1] -= 0.1f;
			break;
		case 0x41: // A
			Vp[0] -= 0.1f;
			break;
		case 0x44: // D
			Vp[0] += 0.1f;
			break;
		case 0x45: // E
			Vp[2] -= 0.1f;
			break;
		case 0x51: // Q
			Vp[2] += 0.1f;
			break;
		}
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			if (lightOn == false)
			{
				lightOn = true;
			}
			else
			{
				lightOn = false;
			}
			break;
		case VK_LEFT:
			rotateDeg -= 1.0f;
			break;
		case VK_RIGHT:
			rotateDeg += 1.0f;
			break;
		}
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

void myPyramid()
{
	glPushMatrix();
	glColor3ub(180, 255, 145);
	glTranslatef(0, -0.5f, 0);
	glRotatef(rotateDeg, 1, 1, 1);
	glBegin(GL_POLYGON);

	glColor3f(0, 1, 0);
	glVertex3f(0, 1, -0.5);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(0.5, 0, 0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 1, -0.5);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(-0.5, 0, -1.0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 1, -0.5);
	glVertex3f(0.5, 0, 0);
	glVertex3f(0.5, 0, -1.0);

	glColor3f(0, 1, 0);
	glVertex3f(0, 1, -0.5);
	glVertex3f(0.5, 0, -1.0);
	glVertex3f(-0.5, 0, -1.0);

	glColor3f(0, 1, 0);
	glVertex3f(-0.5, 0, 0);
	glVertex3f(0.5, 0, 0);
	glVertex3f(0.5, 0, -1.0);
	glVertex3f(-0.5, 0, -1.0);

	glEnd();
	glPopMatrix();
}

void mySphere()
{
	GLUquadricObj* var = NULL;
	var = gluNewQuadric();

	glPushMatrix();
	glColor3ub(180, 255, 145);
	glRotatef(rotateDeg, 1, 1, 1);
	//gluQuadricDrawStyle(var, GLU_LINE);
	gluSphere(var, 0.5f, 32, 32);
	glPopMatrix();
}

void drawObject(char currObjCode)
{
	switch (currObjCode)
	{
	case 0x4F:
		mySphere();
		break;
	case 0x50:
		myPyramid();
		break;
	}
}

void lighting()
{
	glLightfv(GL_LIGHT0, GL_AMBIENT, Va); //设置0号光源的环境光属性  
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Vd); //设置0号光源的散射光属性  
	glLightfv(GL_LIGHT0, GL_SPECULAR, Vs);    //设置0号光源的镜面反射光属性  
	glLightfv(GL_LIGHT0, GL_POSITION, Vp);    //设置0号光源的位置属性
	glEnable(GL_LIGHT0);

	if (lightOn == false)
	{
		glDisable(GL_LIGHTING);
	}
	else
	{
		glEnable(GL_LIGHTING);
	}

	glEnable(GL_COLOR_MATERIAL);//启用颜色追踪  
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void display()
{
	glClearColor(0.18f, 0.04f, 0.14f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	lighting();
	drawObject(objCode);

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