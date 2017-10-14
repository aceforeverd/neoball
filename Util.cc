//
// Created by ace on 10/13/17.
//

#ifndef GLU_UTIL_H
#define GLU_UTIL_H

#include <GL/glut.h>
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

void load_obj(const char *filename, GLuint &obj)
{
    FILE *fp;
    int read;
    GLfloat x, y, z;
    char ch;
    obj=glGenLists(2);
    fp=fopen(filename,"r");
    if (!fp) {
        printf("can't open file %s\n", filename);
        exit(1);
    }
    glPointSize(2.0);
    glNewList(obj, GL_COMPILE);
    glPushMatrix();
    glBegin(GL_POINTS);
    while(!(feof(fp)))
    {
        read=fscanf(fp,"%c %f %f %f",&ch,&x,&y,&z);
        if(read==4&&ch=='v')
        {
            glVertex3f(x,y,z);
        }
    }
    glEnd();
    glPopMatrix();
    glEndList();
    fclose(fp);
    std::cout << "obj: " << obj << std::endl;
}


#endif //GLU_UTIL_H
