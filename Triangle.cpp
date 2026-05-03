#include <GL/freeglut.h>

float tx = 0.0;
int direction = 1;

void time(int value) {
    
    tx += (0.02f * direction);
    if (tx > 0.6f || tx < -0.6f)
        direction *= -1;

    glutPostRedisplay();
    glutTimerFunc(1000 / 60, time, 0);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0); 

    glLoadIdentity();

    glPushMatrix(); 
        glTranslatef(tx, 0.0f, 0.0f);
        glScalef(1, -1, 1);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5, -0.5);
            glColor3f(0.0, 1.0, 0.0); glVertex2f( 0.5, -0.5);
            glColor3f(0.0, 0.0, 1.0); glVertex2f( 0.0,  0.5);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.5f, 0.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_TRIANGLES);
            glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5, -0.5);
            glColor3f(0.0, 1.0, 0.0); glVertex2f( 0.5, -0.5);
            glColor3f(0.0, 0.0, 1.0); glVertex2f( 0.0,  0.5);
        glEnd();
            
    glPopMatrix();

    glFlush(); 
}

int main (int argc, char** argv) {

    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    
    glutInitWindowPosition(100, 100);

    glutInitWindowSize(600, 400);

    glutCreateWindow("Triangle Animation");

    glutDisplayFunc(display);

    glutTimerFunc(0 , time , 0);

    glutMainLoop();

}