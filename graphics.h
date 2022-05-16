//
// Created by MSI-PC on 2021/4/28.
//

#ifndef M4OEP_GRAPHICS1_TLIANG2_GRAPHICS_H
#define M4OEP_GRAPHICS1_TLIANG2_GRAPHICS_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

// Randomly turn the ball to a bomb
void randomBomb();

// The method draws the shapes combining a bomb ina certain order.
void drawBomb();

void initBall();
void initBox();
void init();

// Initialize OpenGL Graphics
void InitGL();

// This function is for keyboard event while playing the game */
// If using the normal function, the game could be restart while playing */
void kbdControl(unsigned char key, int x, int y);

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Callback functions for GLUT
// glutDisplayFunc four screens
void failMessage();
void winningMessage();
void display();
void level();
void welcomeMessage();

// Timer functions
void ballTimer(int dummy);
void backgroundTimer(int dummy);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);
#endif //M4OEP_GRAPHICS1_TLIANG2_GRAPHICS_H
