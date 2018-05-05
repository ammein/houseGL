#include <stdlib.h>
#include <glut.h>
#include <iostream>

using namespace std;

GLsizei windowWidth = 800, windowHeight = 500;

void initGL()
{
	glClearColor(0.239, 0.239, 0.239, 1); // RGBA Window Color
}
/***************************************************

1			GRAPH DISPLAY
y											1
^
|
|
|
|0
|
|
|
|__________________________________________> x
-1					0						1


***************************************************/

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
								  // Big Box
	// House Base
	glBegin(GL_QUADS);
	glColor3f(0.490, 0.372, 1);
	glVertex2d(213, 245);
	glVertex2d(213, 500);
	glVertex2d(584, 500);
	glVertex2d(584, 245);
	glVertex2d(0, 0);
	glEnd();

	// Roof
	glBegin(GL_TRIANGLES);
	glColor3f(0.490, 0.372, 1);
	glVertex2d(155,245);
	glVertex2d(645,245);
	glVertex2d(400,0);
	glEnd();

	// Tree Branch
	glBegin(GL_QUADS);
	glColor3f(1, 0.623, 0.101);
	glVertex2d(686, 500);
	glVertex2d(720, 500);
	glVertex2d(720, 342);
	glVertex2d(686, 342);
	glEnd();

	// Tree Bottom
	glBegin(GL_TRIANGLES);
	glColor3f(0.196, 1, 0.494);
	glVertex2d(639 , 342);
	glVertex2d(762 , 342);
	glVertex2d(703 , 182);
	glEnd();

	// Tree Upper
	glBegin(GL_TRIANGLES);
	glColor3f(0.196, 1, 0.494);
	glVertex2d(608.25 , 267);
	glVertex2d(792.75, 267);
	glVertex2d(704.25, 27);
	glEnd();

	// Second Tree Lefts
	// Tree Branch
	glBegin(GL_QUADS);
	glColor3f(1, 0.623, 0.101);
	glVertex2d(91, 500);
	glVertex2d(125, 500);
	glVertex2d(125, 342);
	glVertex2d(91, 342);
	glEnd();

	// Tree Bottom
	glBegin(GL_TRIANGLES);
	glColor3f(0.196, 1, 0.494);
	glVertex2d(44 , 342);
	glVertex2d(167 , 342);
	glVertex2d(108 , 182);
	glEnd();

	// Tree Upper
	glBegin(GL_TRIANGLES);
	glColor3f(0.196, 1, 0.494);
	glVertex2d(13.25, 267);
	glVertex2d(197.75, 267);
	glVertex2d(109.25, 27);
	glEnd();

	// Door
	glBegin(GL_QUADS);
	glColor3f(0.976, 0.976, 0.976);
	glVertex2d(349 , 500);
	glVertex2d(448 , 500);
	glVertex2d(448 , 342);
	glVertex2d(349, 342);
	glEnd();

	// Window Right
	glPointSize(81);
	glBegin(GL_POINTS);
	glVertex2d(515.5, 309.5);
	glEnd();

	// Window Left
	glPointSize(81);
	glBegin(GL_POINTS);
	glVertex2d(284.5, 309.5);
	glEnd();

	// Line Window
	glLineWidth(1);
	glColor3f(0.490, 0.372, 1);
	glBegin(GL_LINES);
	glVertex3d(515, 269,0);
	glVertex3d(515, 350,0);
	glEnd();

	// Line Window
	glLineWidth(1);
	glColor3f(0.490, 0.372, 1);
	glBegin(GL_LINES);
	glVertex2d(474.891, 309.5);
	glVertex2d(556, 309.5);
	glEnd();

	// Line Window
	glLineWidth(1);
	glColor3f(0.490, 0.372, 1);
	glBegin(GL_LINES);
	glVertex2d(284.5, 269);
	glVertex2d(284.5, 350);
	glEnd();

	// Line Window
	glLineWidth(1);
	glColor3f(0.490, 0.372, 1);
	glBegin(GL_LINES);
	glVertex2d(244, 309.5);
	glVertex2d(325, 309.5);
	glEnd();

	glFlush(); // Render Now
}
/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {
	// References 
	/*aspectRatio = (oldWidth / oldHeight)
	newHeight = (newWidth / aspectRatio)
	newWidth = ( newHeight * aspectRatio )*/

	windowWidth = width;
	windowHeight = height;
	if (height == (height / 2)) height = windowHeight;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	// Set the viewport to cover the new window
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Calculate The Aspect Ratio Of The Window
	//gluPerspective(30.0f, width / height, 0.3f, 200.0f);
	if (width <= height) {
		gluOrtho2D(0, GLdouble(width) * aspect, GLdouble(height) / aspect, 0);
	}
	else
	{
		gluOrtho2D(0, GLdouble(width), GLdouble(height), 0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	displayFunc();
	cout << "Random Value = " << rand() % 300 << endl;
}

/*
SEQUENCE MAIN GL:

1) Initialize GLUT First								-> glutInit(&argc , argv)
2) Set the window size									-> glutInitWindowSize(x , y)
3) Set the Initial Starting Window on your screen		-> glutInitWindowPosition(x , y)
4) Create Window with Title								-> glutCreateWindow("String here")
5) Make Display function to repaint the window			-> glutDisplayFunc(yourFunctionName)
6) Make reshape if have animation						-> glutReshapeFunc(yourFunctionName)
7) Looping to create GL (Running Processor)				-> glutMainLoop()

reference : http://www3.ntu.edu.sg/home/ehchua/programming/opengl/cg_introduction.html#zz-1.1
*/

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitWindowSize(windowWidth, windowHeight); // Set the window's initial width & height
	glutInitWindowPosition(100, 100); // Position the window's initial top-left corner
	glutCreateWindow("My Name"); // Create a window with the given title
	glutDisplayFunc(displayFunc); // Register display callback handler for window re-paint
	glutReshapeFunc(reshape);
	initGL();
	cout << "Window Width : " << windowWidth << " , Window Height : " << windowHeight << endl;
	cout << "Window Height in half : " << windowHeight / float(1000) << endl;
	cout << "Window Height in calculations : " << float(1 - (390 / float(windowHeight))) << endl;
	cout << "Calculate : " << float(1 - ((600 / 2) / float(640 / 2))) << endl;
	cout << "Calculate : " << float(1 - ((600 / 2) / float(640 / 2))) << endl;
	glutMainLoop(); // Enter the event-processing loop
	return 0;
}