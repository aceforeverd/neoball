#include "View.hpp"

View::View() {
    init();
}

void View::init() {
    theta = 3;
    y = 3;
    dTheta = 0.04;
    dy = 0.3;
}


double View::get_x() {
    return 10 * cos(theta);
}

double View::get_y() {
    return y;
}

double View::get_z() {
    return 10 * sin(theta);
}

void View::move_right() {
    theta += dTheta;
}

void View::move_left() {
    theta -= dTheta;
}

void View::move_up() {
    y += dy;
}

void View::move_down() {
    if (y > dy) y -= dy;
}
