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
#include <cstdio>

GLuint LoadTexture(const char* filename) {
    GLuint texture_id;
    int width, height;
    unsigned char * data;
    FILE * file;

    file = fopen( filename, "rb" );

    if ( file == NULL ) return 0;

    width = 1024;
    height = 512;
    data = (unsigned char *)malloc( width * height * 3 );
    fread( data, width * height * 3, 1, file );
    fclose( file );

    for(int i = 0; i < width * height ; ++i)
    {
        int index = i*3;
        unsigned char B,R;
        B = data[index];
        R = data[index+2];

        data[index] = R;
        data[index+2] = B;

    }

    glGenTextures( 1, &texture_id );
    glBindTexture( GL_TEXTURE_2D, texture_id );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE,GL_MODULATE );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST );

    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT );
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT );
    gluBuild2DMipmaps( GL_TEXTURE_2D, 3, width, height,GL_RGB, GL_UNSIGNED_BYTE, data );
    free( data );

    return texture_id;
}


#endif //GLU_UTIL_H
