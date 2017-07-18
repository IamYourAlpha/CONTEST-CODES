/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

/* GLUT callback Handlers */

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);//3D

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



    glLineWidth(1);


    //SolidTorus
    glPushMatrix();
        glColor3f(1,0,0);
        glTranslated(2.4,1.2,-6);
        glRotated(0,1,0,0);
        glutSolidTorus(0.2,0.8,16,100);
    glPopMatrix();

    //SolidTeapot
    glPushMatrix();
        glColor3f(1,1,0);
        glTranslated(-.2,1.2,-6);
        glRotated(0,1,0,0);
        glutSolidTeapot(0.8);
    glPopMatrix();

    //SolidTetrahedron
     glPushMatrix();
        glColor3f(0,1,0);
        glTranslated(-2.6,1.2,-6);
        glRotated(0,1,0,0);
        glutSolidTetrahedron();
    glPopMatrix();

    //WireCone
    glPushMatrix();
        glColor3f(0,0,1);
        glTranslated(2.4,-.5,-6);
        glRotated(60,1,0,0);
        glutWireCone(1.0,0.8,16,16);
    glPopMatrix();

    //SolidOctahedron
    glPushMatrix();
        glColor3f(0,1,1);
        glTranslated(-.2,-.5,-6);
        glRotated(60,1,0,0);
        glutSolidOctahedron();
    glPopMatrix();

    //SolidDodecahedron
    glPushMatrix();
        glColor3f(1,.7,1);
        glTranslated(-4.9,-.5,-12);
        glRotated(60,1,0,0);
        glutSolidDodecahedron();
    glPopMatrix();

    //SolidIcosahedron
    glPushMatrix();
        glColor3f(.5,1,.7);
        glTranslated(3.2,-3.2,-9);
        glRotated(60,1,0,0);
        glutSolidIcosahedron();
    glPopMatrix();

    //SolidSphere
    glPushMatrix();
        glColor3f(.4,.3,1);
        glTranslated(-.2,-3.6,-10);
        glRotated(60,1,0,0);
        glutSolidSphere(1,16,16);
    glPopMatrix();

    //wire teapot
    glPushMatrix();
        glColor3f(.2,.3,.9);
        glTranslated(-2.6,-2,-6);
        glRotated(0,1,0,0);
        glutWireTeapot(.8);
    glPopMatrix();


    //roll no 77
    /*glPushMatrix();
    glLineWidth(6);
    glTranslated(.60,0,-2);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(.72,-.7,0);
        glVertex3f(.8,-.7,0);
        glVertex3f(.8,-.7,0);
        glVertex3f(.72,-.9,0);

        glVertex3f(.82,-.7,0);
        glVertex3f(.9,-.7,0);
        glVertex3f(.9,-.7,0);
        glVertex3f(.82,-.9,0);*/
    glEnd();
    glPopMatrix();



    glutSwapBuffers();
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

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(100,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
//    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

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

    return EXIT_SUCCESS;
}
