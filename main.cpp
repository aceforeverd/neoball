#include <GL/glut.h>
#include <cmath>
#include <vector>
#include "Util.cc"
#include "View.hpp"
#include "Ball.hpp"
#include "Ground.hpp"

GLfloat GREEN[] = {0, 1, 0};
GLfloat MAGENTA[] = {1, 0, 1};
GLfloat WHITE[] = {1, 1, 1};
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
const int BALL_NUM = 4;

Ground ground(10, 10);
View view;
Ball balls[BALL_NUM] = {
        Ball(0.7, GREEN, 6.0, 1.0, 250.0),
        Ball(1.0, MAGENTA, 3.0, 4.0, 200.0),
        Ball(0.4, WHITE, 1.0, 7.0, 300.0),
        Ball(0.6, MAGENTA, 7.0, 3.0, 220.0)
};

void init() {
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    ground.create();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(view.get_x(), view.get_y(), view.get_z(),
              ground.center_x(), 0.0, ground.center_z(),
              0.0, 1.0, 0.0);
    ground.draw();
    for (size_t i = 0; i < BALL_NUM; i++) {
        balls[i].update();
    }
    glFlush();
    glutSwapBuffers();
}

void reshape(GLint w, GLint h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int v) {
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, v);
}

void special(int key, int, int) {
    switch (key) {
        case GLUT_KEY_LEFT:
            view.move_left(); break;
        case GLUT_KEY_RIGHT:
            view.move_right(); break;
        case GLUT_KEY_UP:
            view.move_up(); break;
        case GLUT_KEY_DOWN:
            view.move_down(); break;
        case GLUT_KEY_F1:
            for (size_t i = 0; i < BALL_NUM; i++) {
                balls[i].reset();
            }
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Balls");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(special);
    glutTimerFunc(100, timer, 0);
    init();
    glutMainLoop();
}
