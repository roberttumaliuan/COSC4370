/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>

#include "./freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = { 0,1,4,1 };
int windowWidth = 640, windowHeight = 480;
double yRot = 0;
int curProblem = 4;

float specular[] = { 1.0, 1.0, 1.0, 1.0 };
float shininess[] = { 50.0 };

void problem1() {
    glPushMatrix();

    glTranslatef(1.0f, 0.0f, 0.0f);      //1
    glutSolidTeapot(0.20f);        //Teapot 1

    glRotatef(30.0f, 0.0f, 0.0f, 0.1f);  //2
    glTranslatef(0.10f, 0.45f, 0.0f);    //2
    glutSolidTeapot(0.20f);        //Teapot 2

    glRotatef(45.0f, 0.0f, 0.0f, 0.1f);  //3 
    glTranslatef(0.30f, 0.50f, 0.0f);    //3
    glutSolidTeapot(0.20f);        //Teapot 3

    glRotatef(60.0f, 0.0f, 0.0f, 0.1f);  //4
    glTranslatef(0.55f, 0.62f, 0.0f);    //4
    glutSolidTeapot(0.20f);        //Teapot 4

    glRotatef(30.0f, 0.0f, 0.0f, 0.1f);  //5
    glTranslatef(0.2f, 0.42f, 0.0f);     //5
    glutSolidTeapot(0.20f);        //Teapot 5

    glRotatef(12.0f, 0.0f, 0.0f, 0.1f);  //6
    glTranslatef(0.0f, 0.50f, 0.0f);     //6
    glutSolidTeapot(0.20f);        //Teapot 6

    glRotatef(60.0f, 0.0f, 0.0f, 0.1f);  //7
    glTranslatef(0.29f, 0.47f, 0.0f);    //7
    glutSolidTeapot(0.20f);        //Teapot 7

    glRotatef(50.0f, 0.0f, 0.0f, 0.1f);  //8
    glTranslatef(0.37f, 0.4f, 0.0f);     //8
    glutSolidTeapot(0.20f);        //Teapot 8

    glRotatef(20.0f, 0.0f, 0.0f, 0.1f);  //9
    glTranslatef(0.22f, 0.4f, 0.0f);     //9
    glutSolidTeapot(0.20f);        //Teapot 9

    glRotatef(20.0f, 0.0f, 0.0f, 0.1f); //10
    glTranslatef(0.19f, 0.4f, 0.0f);    //10
    glutSolidTeapot(0.20f);       //Teapot 10

    glPopMatrix();
}

void problem2() {
    glPushMatrix();
    glTranslatef(-4.0f, 0.0f, 0.0f);
    glutSolidCube(0.50f);        //Cube 1    
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 1.2f, 1.0f);
    glTranslatef(-3.50f, 0.035f, 0.0f);
    glutSolidCube(0.50f);       //Cube 2
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 1.4f, 1.0f);
    glTranslatef(-3.0f, 0.060f, 0.0f);
    glutSolidCube(0.50f);       //Cube 3
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 1.6f, 1.0f);
    glTranslatef(-2.5f, 0.079f, 0.0f);
    glutSolidCube(0.50f);       //Cube 4
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 1.8f, 1.0f);
    glTranslatef(-2.0f, 0.093f, 0.0f);
    glutSolidCube(0.50f);       //Cube 5
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 2.0f, 1.0f);
    glTranslatef(-1.50f, 0.107f, 0.0f);
    glutSolidCube(0.50f);      //Cube 6
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 2.2f, 1.0f);
    glTranslatef(-1.0f, 0.121f, 0.0f);
    glutSolidCube(0.50f);      //Cube 7
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 2.4f, 1.0f);
    glTranslatef(-0.50f, 0.132f, 0.0f);
    glutSolidCube(0.50f);      //Cube 8
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 2.6f, 1.0f);
    glTranslatef(0.0f, 0.141, 0.0f);
    glutSolidCube(0.50f);      //Cube 9, starts on axis
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 2.8f, 1.0f);
    glTranslatef(0.50f, 0.15f, 0.0f);
    glutSolidCube(0.50f);      //Cube 10
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 3.0f, 1.0f);
    glTranslatef(1.0f, 0.157f, 0.0f);
    glutSolidCube(0.50f);      //Cube 11
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 3.2f, 1.0f);
    glTranslatef(1.50f, 0.162f, 0.0f);
    glutSolidCube(0.50f);      //Cube 12
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 3.4f, 1.0f);
    glTranslatef(2.0f, 0.169f, 0.0f);
    glutSolidCube(0.50f);      //Cube 13
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 3.6f, 1.0f);
    glTranslatef(2.5f, 0.174f, 0.0f);
    glutSolidCube(0.50f);      //Cube 14
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0f, 3.8f, 1.0f);
    glTranslatef(3.0f, 0.178f, 0.0f);
    glutSolidCube(0.50f);      //Cube 15
    glPopMatrix();
}

void problem3() {

    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glutSolidTeapot(0.25);         //1st Row
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f, 0.5f, 0.0f);
    glutSolidTeapot(0.25);         //2nd Row, 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.0f);
    glutSolidTeapot(0.25);         //2nd Row, 2
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glutSolidTeapot(0.25);         //3rd Row, 1
    glPopMatrix();

    glPushMatrix();
    glutSolidTeapot(0.25);         //3rd Row, 2 (axis)
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glutSolidTeapot(0.25);         //3rd Row, 3
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glutSolidTeapot(0.25);         //3rd Row, 3
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5f, -0.5f, 0.0f);
    glutSolidTeapot(0.25);         //4th Row, 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f, -0.5f, 0.0f);
    glutSolidTeapot(0.25);         //4th Row, 2
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, -0.5f, 0.0f);
    glutSolidTeapot(0.25);         //4th Row, 3
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, -0.5f, 0.0f);
    glutSolidTeapot(0.25);         //4th Row, 4
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.0f, -1.0f, 0.0f);
    glutSolidTeapot(0.25);         //5th Row, 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.0f, -1.0f, 0.0f);
    glutSolidTeapot(0.25);         //5th Row, 2
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, -1.0f, 0.0f);
    glutSolidTeapot(0.25);         //5th Row, 3
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.0f, -1.0f, 0.0f);
    glutSolidTeapot(0.25);         //5th Row, 4
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.0f, -1.0f, 0.0f);
    glutSolidTeapot(0.25);         //5th Row, 5
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2.5f, -1.5f, 0.0f);
    glutSolidTeapot(0.25);         //6th Row, 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.5f, -1.5f, 0.0f);
    glutSolidTeapot(0.25);         //6th Row, 2
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5f, -1.5f, 0.0f);
    glutSolidTeapot(0.25);         //6th Row, 3
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5f, -1.5f, 0.0f);
    glutSolidTeapot(0.25);         //6th Row, 4
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, -1.5f, 0.0f);
    glutSolidTeapot(0.25);         //6th Row, 5
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2.5f, -1.5f, 0.0f);
    glutSolidTeapot(0.25);         //6th Row, 6
    glPopMatrix();
}

void problem4() {

    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0);
    glVertex2f(2, 0);
    glVertex2f(2.4, 2);
    glVertex2f(0.0, 2);//back of hand
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0, 0.5);
    glVertex3f(1, 0, 0.3);
    glVertex3f(2.5, 2.5, 0.3);
    glVertex3f(-0.1, 3, 0.4); //front palm 1
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1, 0, 0.3);
    glVertex3f(2, 0, 0.5);
    glVertex3f(2.4, 2, 0.5);
    glVertex3f(1, 2.5, 0.3); //front palm 2
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0, 0);
    glVertex3f(0.5, 0, 0.5);
    glVertex3f(-0.1, 3, 0.4);
    glVertex3f(-0.1, 3, 0.0);//left side palm
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(2, 0, 0);
    glVertex3f(2, 0, 0.5);
    glVertex3f(2.4, 2, 0.5);
    glVertex3f(2.4, 2, 0);//right side palm
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(2.4, 2, 0.0);
    glVertex3f(0, 2, 0.0);
    glVertex3f(-0.1, 2.8, 0.4);
    glVertex3f(2.4, 2, 0.5);//upper palm front
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.9, 2, 0.3);
    glVertex3f(2.4, 2, 0.5);
    glVertex3f(2.7, 4, 0.2);
    glVertex3f(2.5, 4, 0.2); //pinky front
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.9, 2, 0);
    glVertex3f(1.9, 2, 0.3);
    glVertex3f(2.5, 4, 0.3);
    glVertex3f(2.5, 4, 0); //pinky side left
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(2.4, 2, 0.0);
    glVertex3f(2.4, 2, 0.5);
    glVertex3f(2.7, 4, 0.2);
    glVertex3f(2.7, 4, 0.0); //pinky side right
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.1, 2.8, 0.4);
    glVertex3f(0.5, 2.8, 0.4);
    glVertex3f(0.3, 5.2, 0.3);
    glVertex3f(-0.06, 5.2, 0.3);// forefinger front
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.1, 2.8, 0);
    glVertex3f(-0.1, 2.8, 0.4);
    glVertex3f(-0.06, 5.2, 0.3);
    glVertex3f(-0.06, 5.2, 0);// forefinger side left
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.5, 1.8, 0.4);
    glVertex3f(0.5, 2.8, 0);
    glVertex3f(0.3, 5.2, 0);
    glVertex3f(0.3, 5.2, 0.4);// forefinger side right
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.1, 2.8, 0);
    glVertex3f(0, 2, 0);
    glVertex3f(0, 2.6, 0.4);
    glVertex3f(-0.1, 2.8, 0.4);// forefinger/palm
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.7, 2.7, 0.5);
    glVertex3f(1.2, 2.6, 0.5);
    glVertex3f(1, 5.5, 0.4);
    glVertex3f(0.65, 5.5, 0.4);// middle finger front
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.7, 2.7, 0);
    glVertex3f(0.7, 2.7, 0.5);
    glVertex3f(0.65, 5.5, 0.5);
    glVertex3f(0.65, 5.5, 0);// middle finger side left
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.2, 2.6, 0.5);
    glVertex3f(1.2, 2.6, 0);
    glVertex3f(1, 5.5, 0);
    glVertex3f(1, 5.5, 0.5);// middle finger side right
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.1, 2, 2);
    glVertex3f(1.6, 2, 2);
    glVertex3f(1.8, 3.4, 0.4);
    glVertex3f(1.3, 3.4, 0.4);//bent ring finger front
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.1, 2, 2);
    glVertex3f(1.1, 1.7, 1.5);
    glVertex3f(1.6, 1.7, 1.5);
    glVertex3f(1.8, 3.4, 0.4);//bent ring tip
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.3, 2.8, 0.4);
    glVertex3f(1.1, 1.7, 1.5);
    glVertex3f(1.1, 2, 2);
    glVertex3f(1.3, 3.4, 0.4);//bent ring side left
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.6, 2, 2);
    glVertex3f(1.1, 1.7, 1.5);
    glVertex3f(1.8, 3, 0.4);
    glVertex3f(1.8, 3.4, 0.4);//bent ring side right
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.8, 2.8, 0.65);
    glVertex3f(1.8, 1.3, 0.5);
    glVertex3f(1.8, 1.3, 0);
    glVertex3f(1.8, 3.4, 0.4);//ring finger right side
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.1, 2.8, 0.65);
    glVertex3f(1.1, 2.3, 0.65);
    glVertex3f(1.8, 2.2, 0.4);
    glVertex3f(1.8, 2.9, 0.65);//ring finger underside
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.9, 0.9, 1.9);
    glVertex3f(1.5, 1.8, 2.4);
    glVertex3f(1.3, 2.2, 2.4);
    glVertex3f(0.8, 1.9, 1.9);//thumb front
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1, 0, 0.3);
    glVertex3f(1.3, 1, 0.3);
    glVertex3f(1.2, 1.35, 2.15);
    glVertex3f(0.9, 0.9, 1.9);//thumb bottom
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(1.2, 1.35, 2.15);
    glVertex3f(1.3, 1, 0.3);
    glVertex3f(0.0, 2.6, 0.4);//thumb/forefinger
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0, 0.5);
    glVertex3f(1, 0, 0.3);
    glVertex3f(0.9, 0.9, 1.9);//palm/thumb bottom
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.8, 1.9, 1.4);
    glVertex3f(0.8, 1.9, 1.9);
    glVertex3f(1.3, 2.2, 2.4);
    glVertex3f(1.3, 2.2, 2);//thumb top
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0, 0.5);
    glVertex3f(0.9, 0.9, 1.9);
    glVertex3f(0.8, 1.9, 1.9);
    glVertex3f(0.1, 2.6, 0.4);//thumb side
    glEnd();

    glPopMatrix();
}

void display() {
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(1, 0, 0); // x axis
    glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 1, 0); // y axis
    glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 1); // z axis
    glEnd(/*GL_LINES*/);

    glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glEnable(GL_LIGHT0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, windowWidth, windowHeight);

    float ratio = (float)windowWidth / (float)windowHeight;
    gluPerspective(50, ratio, 1, 1000);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

    glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

    glRotatef(yRot, 0, 1, 0);

    if (curProblem == 1) problem1();
    if (curProblem == 2) problem2();
    if (curProblem == 3) problem3();
    if (curProblem == 4) problem4();

    glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) leftDown = (state == GLUT_DOWN);
    else if (button == GLUT_RIGHT_BUTTON) rightDown = (state == GLUT_DOWN);

    lastPos[0] = x;
    lastPos[1] = y;
}

void mouseMoved(int x, int y) {
    if (leftDown) yRot += (x - lastPos[0]) * .1;
    if (rightDown) {
        for (int i = 0; i < 3; i++)
            cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
    }


    lastPos[0] = x;
    lastPos[1] = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    curProblem = key - '0';
    if (key == 'q' || key == 'Q' || key == 27) {
        exit(0);
    }
    glutPostRedisplay();
}

void reshape(int width, int height) {
    windowWidth = width;
    windowHeight = height;
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("HW2");

    glutDisplayFunc(display);
    glutMotionFunc(mouseMoved);
    glutMouseFunc(mouse);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
