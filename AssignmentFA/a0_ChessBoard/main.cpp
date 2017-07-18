
#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "math.h"

int rows = 6;





//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27: //Escape key
            exit(0);
            break;

    }

}


//Initializes 3D rendering
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_LIGHT2); //Enable light #2
    glEnable(GL_NORMALIZE); //Automatically normalize normals
    glShadeModel(GL_SMOOTH); //Enable smooth shading

}


//Called when the window is resized
void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}



//void showLights(){
//
//    //Add ambient light
//    GLfloat ambientColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
//

//}



void drawGround(double x, double y ){
    glBegin(GL_QUADS);

    //Top
    glVertex3f(x, y, 0.0);
    glVertex3f(x+1.0, y, 0.0);
    glVertex3f(x+1.0, y+1.0, 0.0);
    glVertex3f(x, y+1.0, 0.0);

    /*
    glVertex3f(x,y,0);
    glVertex3f(x,y-.33334,0);
    glVertex3f(x+.33334,y,0);
    glVertex3f(x+.33334,y-.33334,0);
    */

    glEnd();
}


//Draws the 3D scene
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //showLights();

    glTranslatef(-5.0f, -5.0f, -15.0f);     //origin translated to -5,-5 point
    //base

    int color = -1;
    double i,j;

    for(i=0.0;i<=rows-1;i+=1.0){
        if(rows%2==0){
            color*=-1;
        }

        //for(j=(rows-1)*-1.0;j<=0.0;j+=1.0)
        for(j=0.0;j<=rows-1;j+=1.0){
            glPushMatrix();

            if(color==1){
                //brown
                glColor3f(0.7f, 0.3f, 0.0f);
            }else{
                //cyan
                glColor3f(0.0f, 0.6f, 0.6f);
            }

            color*=-1;
            drawGround(j,i);

            glPopMatrix();
        }
    }



    glutSwapBuffers();
}





int main(int argc, char** argv) {
    //user input
    printf("Enter an Row*Column (Sq. Matrix) number: ");
    scanf("%d",&rows);

    //Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);  //width x height

    //Create the window
    glutCreateWindow("Checker Box");
    initRendering();

    //Set handler functions
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);


    glutMainLoop();
    return 0;
}

