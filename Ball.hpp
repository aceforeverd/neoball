//
// Created by ace on 10/13/17.
//

#ifndef BALL_BALL_HPP
#define BALL_BALL_HPP

#include <GL/glut.h>
#include <iostream>

const double ACCELERATION = 9.8;
const double TIMEOUT = 0.0005;

class Ball {
    double radius;
    GLfloat* color;
    double center_x;
    double center_y;
    double center_z;
    double acceleration;
    double startup_speed;
    double timeout;

public:
    Ball(double r, GLfloat* c, double xx, double zz, double speed);

    void update();

    void reset();
};

#endif //BALL_BALL_HPP
