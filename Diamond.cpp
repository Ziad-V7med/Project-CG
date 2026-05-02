#include <GL/glut.h>

float angle = 0.0;  
float x_move = 0.0;
int direction = 1;  

void display() {

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300); 

    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    glTranslatef(x_move, 0, 0);    
    glRotatef(angle, 0, 0, 1);    

    glBegin(GL_QUADS);
        glColor3f(0.0, 1.0, 1.0);   
        glVertex2f(0, 100);   
        glVertex2f(-70, 0); 
        glVertex2f(0, -100);  
        glVertex2f(70, 0);   
    glEnd();

    glFlush(); 
}

void time(int value) {

    angle += 2.0;
    if (angle > 360) angle = 0;

    x_move += (2.0 * direction);
    if (x_move > 200 || x_move < -200) direction *= -1; 
    
    glutPostRedisplay(); 
    glutTimerFunc(16, time, 0); 
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(500, 200);

    glutCreateWindow("Diamond Automation");

    glutDisplayFunc(display);

    glutTimerFunc(0, time, 0); 

    glutMainLoop();

}