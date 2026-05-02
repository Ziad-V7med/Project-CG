#include <GL/glut.h>
#include <math.h>

float tx = 0.0f;     
float scale = 1.0f; 

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glLoadIdentity();

    glTranslatef(tx, 0, 0);

    glScalef(scale, scale, 1.0f);

    glColor3f(0.0f, 1.0f, 0.5f);

    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.1f);
        glVertex2f( 0.2f, -0.1f);
        glVertex2f( 0.2f,  0.1f);
        glVertex2f(-0.2f,  0.1f);
    glEnd();

    glFlush();
}

void time(int value) {
    
    tx += 0.01f;
    if (tx > 1.2f) tx = -1.2f; 

    scale += 0.005f;
    if (scale > 2.0f) scale = 0.5f; 

    glutPostRedisplay();

    glutTimerFunc(16 , time , 0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutCreateWindow("Rectangle Automation");

    glutDisplayFunc(display);
    
    glutTimerFunc(0, time, 0);

    glutMainLoop();

}