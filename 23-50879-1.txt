#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);

     glBegin(GL_POINTS);
        glColor3f(0,0,1);
        glVertex2f(0.5 ,0.5);
    glEnd();

    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex2f(-1,0);
        glVertex2f(1,0);
        glVertex2f(0,-1);
        glVertex2f(0,1);
    glEnd();

    glBegin(GL_TRIANGLES);
        glColor3f(0,1,0);
        glVertex2f(-0.6, -0.2);
        glColor3f(1,0,0);
        glVertex2f(-0.6, -0.5);
        glVertex2f(-0.3, -0.5);
    glEnd();

    glBegin(GL_QUADS);
       glColor3f(1,1,0);
       glVertex2f(-0.2, 0.8);
        glVertex2f(-0.4, 0.8);
        glVertex2f(-0.4, 0.2);
        glVertex2f(-0.2, 0.2);
    glEnd();

     glBegin(GL_QUADS);
       glColor3f(1,0,0);
       glVertex2f(-0.5, 0.9);
        glVertex2f(-0.8, 0.9);
        glVertex2f(-0.8, 0.6);
        glVertex2f(-0.5, 0.6);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0,1,0);
        glVertex2f(0.65, -0.3);
        glVertex2f(0.4, -0.5);
        glVertex2f(0.5, -0.7);
        glVertex2f(0.8, -0.7);
        glVertex2f(0.9, -0.5);
    glEnd();


	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);                 // Initialize GLUT
	glutCreateWindow("Welcome to TUTUL'S Workplace"); // Create a window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
