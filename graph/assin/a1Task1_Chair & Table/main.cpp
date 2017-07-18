# include <windows.h>
#include <GL/glut.h>


float _angle = 0.0;

void mydisplay()
{
glClear (GL_COLOR_BUFFER_BIT);
//glColor3f (1.0, 0.0, 0.0); //red


//Chair
glPushMatrix();
glRotatef(_angle, 0.0, 1.0, 0.0);
//glTranslatef(0.1,-0.2,0.0);
//glScalef(-0.8,-0.5,-0.8);
glBegin(GL_QUADS);

//part1
glColor3f (0.0, 1.0, 1.0);
glVertex3f (0.35, 0.65, 0.0);
glVertex3f (0.65, 0.65, 0.0);
//glColor3f (0.0, 1.0, 1.0); //blue
glVertex3f (0.65, 0.25, 0.0);
glVertex3f (0.35, 0.25, 0.0);

//part2
glColor3f (1.0, 1.0, 1.0);

glVertex3f (0.35, 0.25, 0.0);
glVertex3f (0.65, 0.25, 0.0);
//glVertex3f (0.25, 0.35, 0.0);
glColor3f (0.0, 1.0, 1.0);
//glVertex3f (0.35, 0.25, 0.0);
glVertex3f (0.86, 0.12, 0.0);
glVertex3f (0.52, 0.12, 0.0);


glEnd();

//glPointSize(20.0);
//
glColor3f (1.0, 1.0, 1.0);
glBegin(GL_LINES);
glVertex3f (0.35, 0.25, 0.0);
glVertex3f (0.35, -0.10, 0.0);



glVertex3f (0.52, 0.12, 0.0);
glVertex3f (0.52, -0.10, 0.0);


glVertex3f (0.86, 0.12, 0.0);
glVertex3f (0.86, -0.10, 0.0);



glEnd();


//LSIDE
glBegin(GL_QUADS);
glColor3f (1.0, 1.0, 1.0);
glVertex3f (0.35, 0.25, 0.0);
glVertex3f (0.35, 0.23, 0.0);
glVertex3f (0.52, 0.10, 0.0);
glVertex3f (0.52, 0.12, 0.0);
glEnd();


//FSIDE
glBegin(GL_QUADS);
glColor3f (1.0, 1.0, 1.0);
glVertex3f (0.52, 0.10, 0.0);
glVertex3f (0.52, 0.12, 0.0);
glVertex3f (0.86, 0.12, 0.0);
glVertex3f (0.86, 0.10, 0.0);
glEnd();

glPopMatrix();

glFlush();



////TABLE

glPushMatrix();

glTranslatef(0.0,-0.8,0.0);
glBegin(GL_QUADS);

//part1
glColor3f (0.0, 1.0, 1.0);

glVertex3f (-0.15, 0.35, 0.0);//RT
glVertex3f (-0.05, 0.20, 0.0);//RB
//glColor3f (0.0, 1.0, 1.0); //blue
glVertex3f (-0.70, 0.20, 0.0);//LB

glVertex3f (-0.55, 0.35, 0.0);//LT

glEnd();

glBegin(GL_QUADS);

//FSIDE
glColor3f (1.0, 1.0, 1.0);

glVertex3f (-0.05, 0.20, 0.0);//RT
glVertex3f (-0.05, 0.17, 0.0);//RB
glVertex3f (-0.70, 0.17, 0.0);//LB
glVertex3f (-0.70, 0.20, 0.0);//LT
glEnd();


//LFront
glBegin(GL_QUADS);

glColor3f (1.0, 1.0, 1.0);

glVertex3f (-0.68, 0.20, 0.0);//RT
glVertex3f (-0.68, -0.10, 0.0);//RB
glVertex3f (-0.70, -0.10, 0.0);//LB
glVertex3f (-0.70, 0.20, 0.0);//LT



glEnd();


//LBack
glBegin(GL_QUADS);

glColor3f (1.0, 1.0, 1.0);

glVertex3f (-0.58, 0.20, 0.0);//RT
glVertex3f (-0.58, -0.05, 0.0);//RB
glVertex3f (-0.60, -0.05, 0.0);//LB
glVertex3f (-0.60, 0.20, 0.0);//LT



glEnd();


//RFront
glBegin(GL_QUADS);

glColor3f (1.0, 1.0, 1.0);

glVertex3f (-0.05, 0.20, 0.0);//RT
glVertex3f (-0.05, -0.10, 0.0);//RB
glVertex3f (-0.07, -0.10, 0.0);//LB
glVertex3f (-0.07, 0.20, 0.0);//LT



glEnd();


//RBack
glBegin(GL_QUADS);

glColor3f (1.0, 1.0, 1.0);

glVertex3f (-0.15, 0.20, 0.0);//RT
glVertex3f (-0.15, -0.05, 0.0);//RB
glVertex3f (-0.17, -0.05, 0.0);//LB
glVertex3f (-0.17, 0.20, 0.0);//LT



glEnd();

glPopMatrix();


glFlush();


}


void update(int value)
{
	_angle += 0.05;
	if (_angle > 360)
	{
	_angle - 0.0;
	}

	glutPostRedisplay();
	glutTimerFunc(1,update,0);
}





void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

}

int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700,500);
glutCreateWindow("simple");
Initialize();
glutDisplayFunc(mydisplay);
glutTimerFunc(15,update,0);
//update(0);
glutMainLoop();
return 0;
}
