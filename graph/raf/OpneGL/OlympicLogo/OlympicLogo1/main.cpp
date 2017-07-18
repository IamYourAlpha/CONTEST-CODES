#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
float _angle = 0.0;
double z=0,x=0,y=0;
double count = 0.0;

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	//blue
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslatef(-2.4,0.5,-4);
    //glRotated(_angle,0,1,0);
    glutSolidTorus(0.1,0.9,16,30);
    glPopMatrix();



glColor3f(1,1,1);
    glPushMatrix();
    glTranslated(-2.8,0,-9);
    glRotated(_angle,0,1,0);
    glTranslated(1.8,0.5,0);
    glBegin(GL_LINES);
    glVertex3f(.75,0,0);
    glVertex3f(.15,0,0);
    glVertex3f(.75,0,0);
    glVertex3f(.75,.5,0);
    glVertex3f(.15,.5,0);
    glVertex3f(.15,0,0);
    glVertex3f(.75,0.5,0);
    glVertex3f(.15,0.5,0);
    glVertex3f(.15,0.5,0);
    glVertex3f(.35,0.9,0);
    glVertex3f(.75,0.5,0);
    glVertex3f(.95,0.9,0);
    glVertex3f(.35,0.9,0);
    glVertex3f(.95,0.9,0);
    glVertex3f(.95,0.9,0);
    glVertex3f(.95,0.3,0);
    glVertex3f(.95,0.3,0);
    glVertex3f(.75,0,0);


    glEnd();



glPopMatrix();

	glFlush();
}

void update(int value)
{
	_angle += 0.2;
	if (_angle > 360)
	{
	_angle - 0.0;
	count++;
	printf("%lf\n",count/1000);
	}

	glutPostRedisplay();
	glutTimerFunc(1,update,0);
}
static void rotate(int width, int height)
{


    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);    //for viewing volume
    glLoadIdentity();

    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 10.0);   //glFrustum(left,right,bottom,top,nearVal,farVal)

    glMatrixMode(GL_MODELVIEW);     //for various transformation of the model
    glLoadIdentity() ;
}
void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 glutInitWindowSize(640,480);
    glutInitWindowPosition(300,200);
	glutCreateWindow("Rounding Cube through Torus");
    glutReshapeFunc(rotate);
	Initialize();
	glutDisplayFunc(Draw);
	  glutIdleFunc(idle);
	update(0);
	glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();
	return 0;
}
