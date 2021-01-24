#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include <cstdio>
#include <iostream>

# define PI           3.14159265358979323846

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display();
void displayRain();
GLfloat rainposition=0.03f ;
GLfloat rainspeed=0.05f;
void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void update(int value) {

    if(rainposition<=-1.06)
    {
        rainposition=0.04;
    }
    rainposition-=rainspeed;
	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void stageUpper() //lower
{
   glBegin(GL_QUADS);
 glColor3ub(181, 207, 250);
glVertex2f(0.85f,0.0f);
glVertex2f(-0.05f,0.0f);
glVertex2f(-0.05f,-0.05f);
glVertex2f(0.85f,-0.05f);
glEnd();

GLfloat x =-0.12 ;
glBegin(GL_LINES);
glColor3ub(165,165,165);

for(int k=0;k<20;k++)
{
x+=0.05;
glVertex2f(x ,0.0f);
glVertex2f(x,-0.05f);
}

glEnd();




}

void upperFrontLine()
{
glBegin(GL_QUADS);
glColor3ub(390,390,390);
glVertex2f(0.8f,0.6f);
glVertex2f(-0.5f,0.6f);   //Full structure first upper
glVertex2f(-0.5f,0.58f);
glVertex2f(0.8f,0.58f);

glEnd();

}


void lowerFrontLine()      //Light gray
{
glBegin(GL_QUADS);
glColor3ub(311,311,311);
glVertex2f(0.9f,-0.65f);
glVertex2f(-0.5f,-0.65f);   //Full structure first upper
glVertex2f(-0.5f,-0.70f);
glVertex2f(0.9f,-0.70f);

glEnd();

}

void blackUpperStage()
{
glBegin(GL_QUADS);
 glColor3ub(31,38,42);
glVertex2f(0.75f,0.56f);
glVertex2f(-0.10f,0.56f);
glVertex2f(-0.10f,0.50f);
glVertex2f(0.75f,0.50f);
glEnd();


GLfloat x =-0.12 ;
glBegin(GL_LINES);
glColor3ub(165,165,165);

for(int k=0;k<18;k++)
{
x+=0.05;
glVertex2f(x ,0.56f);
glVertex2f(x,0.50f);
}

glEnd();

}


void stageLower()
{
   glBegin(GL_QUADS);
 glColor3ub(181, 207, 250);
glVertex2f(0.75f,0.15f);
glVertex2f(-0.10f,0.15f);
glVertex2f(-0.10f,0.05f);
glVertex2f(0.75f,0.05f);
glEnd();


GLfloat x =-0.12 ;
glBegin(GL_LINES);
glColor3ub(165,165,165);

for(int k=0;k<17;k++)
{
x+=0.05;
glVertex2f(x ,0.15f);
glVertex2f(x,-0.05f);
}

glEnd();

}

void rain()
{
    glColor3ub(0, 0, 0);
    GLfloat x= -1.05;
    GLfloat y = 2.05;
    glBegin(GL_LINES);
    for(int i=0;i<=105;i++){

    glVertex2f(x,y);
    glVertex2f(x-.02,y-.04);

    x += .02;
    }
    glEnd();


    for(int j=0;j<=100;j++)
    {
    x = -1.05;
    y= y-.075;
    glBegin(GL_LINES);
    for(int i=0;i<=105;i++){

    glVertex2f(x,y);
    glVertex2f(x-.02,y-.04);

    x += .02;
    }
    glEnd();
    }

}

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {

    case 'n':
        glutDisplayFunc(display);

    break;
    case 'r':
    glutDisplayFunc(displayRain);


    break;





glutPostRedisplay();
	}
}

void scene()
{
    	glBegin(GL_QUADS);
 glColor3ub(165,165,165);
glVertex2f(0.9f,0.05f);
glVertex2f(-0.5f,0.05f);   //Full structure first upper
glVertex2f(-0.5f,-0.7f);
glVertex2f(0.9f,-0.7f);

glEnd();

 glBegin(GL_QUADS);
 glColor3ub(165,165,165);
glVertex2f(0.8f,0.6f);
glVertex2f(-0.5f,0.6f);   //Full structure first down
glVertex2f(-0.5f,0.0f);
glVertex2f(0.8f,0.0f);


 glBegin(GL_QUADS);
 glColor3ub(181, 207, 250);
glVertex2f(-0.3f,0.6f);
glVertex2f(-0.5f,0.6f);
glVertex2f(-0.5f,0.0f);
glVertex2f(-0.3f,0.0f);


 glBegin(GL_QUADS);
 glColor3ub(181, 207, 250);
glVertex2f(-0.15f,0.0f);   //lower water color
glVertex2f(-0.5f,0.0f);
glVertex2f(-0.5f,-0.7f);
glVertex2f(-0.15f,-0.7f);

glEnd();

stageUpper();
glTranslatef(0.0,-0.10,0);
stageUpper();
glTranslatef(0.0,-0.10,0);
stageUpper();
glTranslatef(0.0,-0.10,0);
stageUpper();
glTranslatef(0.0,-0.10,0);
stageUpper();
glTranslatef(0.0,-0.10,0);
stageUpper();
glLoadIdentity();



stageLower();
glTranslatef(0.0,0.15,0);
stageLower();
glTranslatef(0.0,0.15,0);
stageLower();
glLoadIdentity();

blackUpperStage();


upperFrontLine();

lowerFrontLine();

glLoadIdentity();



}

void display() {
	glClearColor(0.53f, 0.81f, 0.66f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    scene();

	glFlush();  // Render now
}
void displayRain() {
	glClearColor(0.53f, 0.61f, 0.47f, 0.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)

    scene();
    glTranslatef(0,rainposition,0);
    rain();
    glLoadIdentity();


	glFlush();  // Render now
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	glutInitWindowSize(320, 320);// Set the window's initial width & height
	glutIdleFunc(Idle);
	glutKeyboardFunc(handleKeypress);
	glutDisplayFunc(display);// Register display callback handler for window re-paint
	glutTimerFunc(100, update, 0);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
