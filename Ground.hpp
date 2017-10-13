#ifndef BALL_GROUND_HPP
#define BALL_GROUND_HPP

#include <cmath>
#include <GL/glut.h>

class Ground {
private:
    GLuint display_list_id;
    int width;
    int depth;

public:
    Ground(int w, int d);
    void init(int w, int d);
    double center_x() {return width / 2;}
    double center_z() {return depth / 2;}
    void create();

    void draw();
};
#endif //BALL_GROUND_HPP
