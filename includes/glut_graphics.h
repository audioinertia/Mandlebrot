#pragma once
// graphics included for GLUT based braphics projects
#if defined __APPLE__
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#elif defined (__linux__)
    #include <GL/glut.h>
#elif defined (_WIN32)
    #include "gl.h"  //made a shortcut in includes for my file....seems to work
#endif
