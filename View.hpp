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
    View();
    void init();
    double get_x();
    double get_y();
    double get_z();
    void move_right();
    void move_left();
    void move_up();
    void move_down();
};


#endif //BALL_VIEW_HPP
