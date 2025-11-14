
#include<windows.h>
#include<iostream>
#include<math.h>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

using namespace std;

int X1, Y1, X2, Y2;
double m1;


void DDA()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);

    // Draw axes
    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex2f(-100,0); glVertex2f(100,0);
        glVertex2f(0,-100); glVertex2f(0,100);
    glEnd();

    float x = X1;
    float y = Y1;

    glColor3ub(0,0,255);
    glBegin(GL_POINTS);

    if (X2 == X1) // vertical line
    {
        float dy = (Y2 > Y1) ? 1.0f : -1.0f;
        while ((dy>0 && y <= Y2) || (dy<0 && y >= Y2))
        {
            glVertex2i(round(x), round(y));
            y += dy;
        }
    }
    else
    {
        float m = (float)(Y2 - Y1) / (X2 - X1);
        if (fabs(m) <= 1) // gentle slope
        {
            float dx = (X2 > X1) ? 1.0f : -1.0f;
            while ((dx>0 && x <= X2) || (dx<0 && x >= X2))
            {
                glVertex2i(round(x), round(y));
                x += dx;
                y += m * dx;
            }
        }
        else // steep slope
        {
            float dy = (Y2 > Y1) ? 1.0f : -1.0f;
            while ((dy>0 && y <= Y2) || (dy<0 && y >= Y2))
            {
                glVertex2i(round(x), round(y));
                x += (1.0f / m) * dy;
                y += dy;
            }
        }
    }

    glEnd();
    glFlush();
}


void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3ub(0, 200, 0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
}




int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("DDA LINE");

    cout << "Enter an initial points:\t";
    cin >> X1 >> Y1;
    cout << "Enter the final points:\t";
    cin >> X2 >> Y2;
    glutDisplayFunc(DDA);
    myInit();
    glutMainLoop();

}



