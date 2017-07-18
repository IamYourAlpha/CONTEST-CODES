

#include <stdio.h>
#include <gl/glut.h>


//float _angle = 0.0;
//float rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;

void mydisplay()
{

glClear (GL_COLOR_BUFFER_BIT);
//glColor3f (1.0, 0.0, 0.0); //red
glPushMatrix();
glTranslatef(posX,posY,posZ);
//glRotatef(_angle, 0.0, 0.0, 1.0);
glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.4);//1
    glVertex2f(0.10, 0.30);//r2
    glVertex2f(0.10, 0.10);//r4
    glVertex2f(0.30, -0.05);//r6
    glVertex2f(0.05, -0.05);//r8
    glVertex2f(0.05, -0.13);//r10

//     glVertex2f(0.19, -0.17);//r12
//    glVertex2f(-0.19, -0.17);//l13

    glVertex2f(-0.05, -0.13);//l11
    glVertex2f(-0.05, -0.05);//l9
    glVertex2f(-0.30, -0.05);//l7
    glVertex2f(-0.10, 0.10);//l5
    glVertex2f(-0.10, 0.30);//l3

   glEnd();

   glBegin(GL_POLYGON);
   glVertex2f(0.05, -0.13);//r10
   glVertex2f(0.17, -0.22);//r12
   glVertex2f(-0.17, -0.22);//l13
   glVertex2f(-0.05, -0.13);//l11
   glEnd();
glPopMatrix();

glFlush();
}
void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	 gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}


float move_unit = 0.1;
void keyboardown(int key, int x, int y)
{
    switch (key){
        case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            posY+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;;
        break;

        default:
         break;
    }
    glutPostRedisplay();
}




int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (700,500);
glutCreateWindow("simple");
Initialize();
 glutSpecialFunc(keyboardown);
glutDisplayFunc(mydisplay);
//glutKeyboardFunc(handleKeypress);
//glutTimerFunc(25,update,0);
//update(0);
glutMainLoop();

}
