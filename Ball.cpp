#include "Ball.hpp"
#include <cstdio>

GLfloat default_color[] = {0.0, 0.0, 0.0};

Ball::Ball() = default;

Ball::Ball(double r, GLfloat *c, double xx, double zz, double speed) {
    radius = r;
    color = c;
    center_y = r;
    center_x = xx;
    center_z = zz;
    acceleration = ACCELERATION;
    startup_speed = speed;
    timeout = TIMEOUT;

    obj = 1;
}

Ball::Ball(double r, const char *filename, double xx, double zz, double speed) {
    radius = r;
    center_y = r;
    center_x = xx;
    center_z = zz;
    acceleration = ACCELERATION;
    startup_speed = speed;
    timeout = TIMEOUT;

    color = default_color;

    read_obj(filename);
}


void Ball::update() {
    startup_speed -= acceleration;
    glPushMatrix();
    if (obj == 1) {
        center_y += startup_speed * timeout;
        if (center_y <= radius) {
            // touch the ground
            center_y = radius;
            startup_speed = -startup_speed * 0.9;
        }
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        glTranslated(center_x, center_y, center_z);
        glutSolidSphere(radius, 30, 30);
    } else {
        center_y += startup_speed * timeout;
        if (center_y <= radius) {
            // touch the ground
            center_y = radius;
            startup_speed = -startup_speed * 0.9;
        }
        glTranslated(center_x, center_y, center_z);
        glScaled(0.04, 0.04, 0.04);
        glCallList(obj);
    }
    glPopMatrix();
}

void Ball::reset() {
    if (center_y != radius) {
        std::cerr << "not ready" << std::endl;
        return;
    }

    startup_speed = 300.0;
}

void Ball::read_obj(const char *filename) {
        FILE *fp;
        int read;
        GLfloat x, y, z;
        char ch;
        obj = glGenLists(1);
        if (obj == 0) {
            std::cout << "error gen list: " << glGetError() << std::endl;
            return;
        }
        fp=fopen(filename,"r");
        if (!fp) {
            printf("can't open file %s\n", filename);
            return;
        }

        glPointSize(2.0);
        glNewList(obj, GL_COMPILE);
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            read = fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
            if(read == 4 && ch == 'v')
            {
                glVertex3d(x, y, z);
                glColor3d(0.2, 0.3, 1.0);
            }
        }
        glEnd();
        glPopMatrix();
        glEndList();
        fclose(fp);
}
