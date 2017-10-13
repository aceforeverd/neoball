//
// Created by ace on 10/13/17.
//

#include "Ball.hpp"

Ball::Ball(double r, GLfloat *c, double xx, double zz, double speed) {
    radius = r;
    color = c;
    center_y = r;
    center_x = xx;
    center_z = zz;
    acceleration = ACCELERATION;
    startup_speed = speed;
    timeout = TIMEOUT;
}


void Ball::update() {
    startup_speed -= acceleration;
    center_y += startup_speed * timeout;
    if (center_y <= radius) {
        // touch the ground
        center_y = radius;
        startup_speed = -startup_speed * 0.9;
    }
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
    glTranslated(center_x, center_y, center_z);
    glutSolidSphere(radius, 30, 30);
    glPopMatrix();
}

void Ball::reset() {
    if (center_y != radius) {
        std::cerr << "not ready" << std::endl;
        return;
    }

    startup_speed = 300.0;
    std::cout << "reseted." << std::endl;
}
