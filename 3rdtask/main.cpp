#include <windows.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

int X1, Y1, X2, Y2;

void midpoint(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(-320, 0);
    glVertex2i(320, 0);
    glVertex2i(0, -240);
    glVertex2i(0, 240);
    glEnd();

    glColor3f(0.0, 1.0, 0.0); // Green line
    glBegin(GL_POINTS);

    int dx = X2 - X1;
    int dy = Y2 - Y1;
    int d = 2 * dy - dx;
    int dE = 2*dy;
    int dNE= 2*(dy-dx);
    int x = X1;
    int y = Y1;

    glVertex2i(x, y);
    for(int i=X1; i<X2; i++)
    {
        while (x < X2)
      {
        if (d <= 0)
            d += dE;
        else
        {
            d += 2*dNE;
            y++;
        }
        x++;
        glVertex2i(x, y);
      }
    }

    glEnd();
    glFlush();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Algorithm");

    cout << "Enter initial point (X1, Y1): ";
    cin >> X1 >> Y1;
    cout << "Enter final point (X2, Y2): ";
    cin >> X2 >> Y2;

    glutDisplayFunc(midpoint);
    myInit();
    glutMainLoop();
}
