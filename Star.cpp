#include <GL/freeglut.h> 
#include <math.h>

float translateX = 0.0f;
bool movingRight = true;
bool reflected = false;

void lins()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0, 0, 0, 1);

    glLoadIdentity();

    glTranslatef(translateX, 0, 0);

    if (reflected) {
        glTranslatef(0, 1200, 0);
        glScalef(1.0, -1.0, 1.0);
    }

    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(200, 750);
    glVertex2f(150, 650);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(250, 650);

    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(50, 680);
    glVertex2f(150, 650);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(120, 580);

    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(350, 680);
    glVertex2f(250, 650);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(270, 580);

    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(200, 540);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(120, 580);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(80, 500);

    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(200, 540);
    glColor3f(0, 0.0, 0.92f);
    glVertex2f(270, 580);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(320, 500);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.0, 0.92f);
    glVertex2f(200, 540);
    glVertex2d(150, 650);
    glVertex2f(250, 650);
    glVertex2f(270, 580);
    glVertex2f(250, 650);
    glVertex2f(120, 580);
    glVertex2f(150, 650);
    glEnd();

    glFlush();
}

void timer(int value)
{
    if (movingRight) {
        translateX += 5.0f;
        if (translateX > 250.0f) movingRight = false;
    }
    else {
        translateX -= 5.0f;
        if (translateX < -50.0f) movingRight = true;
    }

    static int counter = 0;
    counter += 20;
    if (counter >= 3000) {
        reflected = !reflected;
        counter = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(20, timer, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1200, 800);
    glutCreateWindow("Movement and 3s Reflection");

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 400, 800);

    glMatrixMode(GL_MODELVIEW);
    glutDisplayFunc(lins);
    glutTimerFunc(20, timer, 0);

    glutMainLoop();
    return 0;
}
