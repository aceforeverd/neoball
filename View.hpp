//
// Created by ace on 10/13/17.
//

#ifndef BALL_VIEW_HPP
#define BALL_VIEW_HPP

#include <cmath>

class View {
    double theta;
    double y;
    double dTheta;
    double dy;
public:
    View(): theta(0), y(3), dTheta(0.04), dy(0.2) {}
    double get_x() {return 10 * cos(theta);}
    double get_y() {return y;}
    double get_z() {return 10 * sin(theta);}
    void move_right() {theta += dTheta;}
    void move_left() {theta -= dTheta;}
    void move_up() {y += dy;}
    void move_down() {if (y > dy) y -= dy;}
};


#endif //BALL_VIEW_HPP
