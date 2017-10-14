#include "Ground.hpp"

Ground::Ground(int w, int d) {
    init(w, d);
}

void Ground::init(int w, int d) {
    display_list_id = 0;
    width = w;
    depth = d;
}

void Ground::create() {
    GLfloat COLOR_W[] = {1, 1, 1};
    GLfloat COLOR_R[] = {0, 0, 0};

    display_list_id = glGenLists(1);
    glNewList(display_list_id, GL_COMPILE);
    GLfloat position[] = {4, 3, 7, 1};
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glBegin(GL_QUADS);
    glNormal3d(0, 1, 0);
    for (int x = 0; x < width - 1; x++) {
        for (int z = 0; z < depth - 1; z++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                         (x + z) % 2 == 0 ? COLOR_R : COLOR_W);
            glVertex3d(x, 0, z);
            glVertex3d(x+1, 0, z);
            glVertex3d(x+1, 0, z+1);
            glVertex3d(x, 0, z+1);
        }
    }
    glEnd();
    glEndList();
}

void Ground::draw() {
    glCallList(display_list_id);
}
