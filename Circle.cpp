#include <GL/freeglut.h>
#include <math.h>
using namespace std;

int xcenter = 0, ycenter = 0;
float radius = 0;

void circleplotpoints(int xcenter, int ycenter, int x, int y) {
    glVertex2i(xcenter + x, ycenter + y);
    glVertex2i(xcenter - x, ycenter + y);
    glVertex2i(xcenter + x, ycenter - y);
    glVertex2i(xcenter - x, ycenter - y);

    glVertex2i(xcenter + y, ycenter + x);
    glVertex2i(xcenter - y, ycenter + x);
    glVertex2i(xcenter + y, ycenter - x);
    glVertex2i(xcenter - y, ycenter - x);
}

bool inScreen = true;
float r=0; bool r1 = true;
float g=0; bool g1 = false;
float b = 0; bool b1 = false;

void time(int) {
    
    if (inScreen) {
        radius += 0.1;
    if(radius > 300)
        inScreen = false;
    }
    
    if (!inScreen) {
        radius -=0.1 ;
    if(radius < 0.1)
        inScreen = true;
    }

    if(r > 20) {
        r1 = false;
        r = 0;
        g1= true;
    }
    if(g > 20) {
        g1 = false;
        g = 0.5;
        b1 = true;
    }
    if(b > 20) {
        b1 = false;
        b = 0.5;
        r1 = true;
    }
    if(r1) r+=0.1;
    if(g1) g+=0.1;
    if (b1) b += 0.1;
    
    glutPostRedisplay();

    glutTimerFunc(1, time, 0);
}

void display() {

    glClearColor(0.4, 0.4, 0.4, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300 * 1.33, 300 * 1.33, -300, 300);
    
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    glBegin(GL_POLYGON);

    glColor3f(r, g, b);
    while (x < y) {
        x++;
        if (p < 0) p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        circleplotpoints(xcenter, ycenter, x, y);
    }
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 600);

    glutInitWindowPosition(400, 100);

    glutCreateWindow("Circle Automation");

    glutDisplayFunc(display);

    glutTimerFunc(1, time, 0);

    glutMainLoop();

}