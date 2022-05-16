//
// Created by MSI-PC on 2021/4/28.
//
#include "graphics.h"
#include "circle.h"
#include "rect.h"
#include "Button.h"
#include <ctime>

using namespace std;

// Initiate windows data
GLdouble width = 500;
GLdouble height = 500;
int wd;
int score;
int winningScore;
float growingSpeed;

// The four circle objects are for drawing a 3D sphere in a 2D plane
Circle ball;
Circle dark;
Circle hide;
Circle highlight;

// The shapes used to draw a bomb
Rect bone1;
Rect bone2;
Rect fuse;
Circle joint1;
Circle joint2;
Circle joint3;
Circle joint4;
Circle joint5;
Circle joint6;
Circle joint7;
Circle joint8;

Circle head;
Rect teeth;
Circle eyeLeft;
Circle eyeRight;

// Button colors
color colorA(84/255.0f, 94/255.0f, 255/255.0f);
color colorB(45/255.0f, 56/255.0f, 255/255.0f);
color colorC(0/255.0f, 15/255.0f, 255/255.0f);

// Button locations
int deltaY = 96;
point2D pointA(int(width / 2), 182);
point2D pointB(pointA.x, pointA.y + deltaY);
point2D pointC(pointA.x, pointB.y + deltaY);

Button beginner(colorA, pointA, int(width/3), 57, "Beginner");
Button intermediate(colorB, pointB, int(width/3), 57, "Intermediate");
Button expert(colorC, pointC, int(width/3), 57, "Expert");

// These variables control the breathing light effect on background
float change = 0.0f;
bool turn = true;
float osculate;

Rect box;
Rect back;
bool isBomb = false;

// This value decides the frequency to see a bomb
int bombLevel;

void randomBomb() {
    if (rand()%bombLevel == bombLevel -1) {
        isBomb = true;
    }else {
        isBomb = false;
    }
}

void drawBomb() {

    // Have to follow this order.
    ball.draw();
    bone1.alterDraw(2.68);
    bone2.alterDraw(0.46);

    fuse.draw();
    joint1.draw();
    joint2.draw();
    joint3.draw();
    joint4.draw();
    joint5.draw();
    joint6.draw();
    joint7.draw();
    joint8.draw();
    head.draw();
    teeth.draw();
    eyeLeft.draw();
    eyeRight.draw();

}

void initBall() {
    if (!(isBomb)) {
        // Draw the 3D-like ball
        ball.setColor(rand() % 11 / 10.0f, rand() % 11 / 10.0f, rand() % 11 / 10.0f, 1.0);
        ball.setRadius(20);
        ball.setCenter(rand() % 461 + ball.getRadius(), 0);

        dark.setColor(ball.getRed() * 0.75f, ball.getGreen() * 0.75f, ball.getBlue() * 0.75f, 1.0);
        dark.setRadius(16);
        dark.setCenter(ball.getCenter());

        hide.setColor(ball.getColor());
        hide.setRadius(14);
        hide.setCenter(ball.getCenterX() - 2.8, ball.getCenterY() - 2.8);

        highlight.setRadius(6);
        highlight.setColor((ball.getRed() + .6) / 1.6f, (ball.getGreen() + .6) / 1.6f, (ball.getBlue() + .6) / 1.6f,
                           1.0);
        highlight.setCenter(ball.getCenterX() - 8.5, ball.getCenterY() - 8.5);
    } else {
        // Draw a bomb
        ball.setColor(0.0f, 0.0f, 0.0f, 1.0);
        ball.setRadius(20);
        ball.setCenter(rand() % 461 + ball.getRadius(), 0);

        fuse.setColor(0.0f, 0.0f, 0.0f, 1.0);
        fuse.setSize(10,10);
        fuse.setCenter(ball.getCenterX(), ball.getCenterY() - ball.getRadius());

        bone1.setColor(1.0,1.0,1.0,1.0);
        bone1.setSize(29.07, 4.47);
        bone1.setCenter(ball.getCenterX(), ball.getCenterY() + 2);
        bone2.setColor(1.0,1.0,1.0,1.0);
        bone2.setSize(29.07, 4.47);
        bone2.setCenter(ball.getCenterX(), ball.getCenterY() + 2);;

        teeth.setColor(1.0f, 1.0f, 1.0f, 1.0);
        teeth.setSize(4, 4);
        teeth.setCenter(ball.getCenterX(), ball.getCenterY() - 4);

        head.setColor(1.0f, 1.0f, 1.0f, 1.0);
        head.setRadius(7);
        head.setCenter(ball.getCenterX(), ball.getCenterY() - 11);

        eyeLeft.setColor(0.0f, 0.0f, 0.0f, 1.0);
        eyeLeft.setRadius(2);
        eyeLeft.setCenter(ball.getCenterX() - 3, ball.getCenterY() - 11);

        eyeRight.setColor(0.0f, 0.0f, 0.0f, 0.0);
        eyeRight.setRadius(2);
        eyeRight.setCenter(ball.getCenterX() + 3, ball.getCenterY() - 11);;

        joint1.setCenter(ball.getCenterX()-12, ball.getCenterY()-6);
        joint2.setCenter(ball.getCenterX()-14, ball.getCenterY()-2);
        joint3.setCenter(ball.getCenterX()+12, ball.getCenterY()-6);
        joint4.setCenter(ball.getCenterX()+14, ball.getCenterY()-2);
        joint5.setCenter(ball.getCenterX()-12, ball.getCenterY()+11);
        joint6.setCenter(ball.getCenterX()-14, ball.getCenterY()+7);
        joint7.setCenter(ball.getCenterX()+12, ball.getCenterY()+11);
        joint8.setCenter(ball.getCenterX()+14, ball.getCenterY()+7);

        joint1.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint2.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint3.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint4.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint5.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint6.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint7.setColor(1.0f, 1.0f, 1.0f, 1.0);
        joint8.setColor(1.0f, 1.0f, 1.0f, 1.0);

        joint1.setRadius(2.24);
        joint2.setRadius(2.24);
        joint3.setRadius(2.24);
        joint4.setRadius(2.24);
        joint5.setRadius(2.24);
        joint6.setRadius(2.24);
        joint7.setRadius(2.24);
        joint8.setRadius(2.24);
    }
}

void initBox() {

    // Initiate the board
    box.setSize(50, 20);
    box.setColor(rand()%11/ 10.0f, rand()%11/ 10.0f, rand()%11/ 10.0f, 1.0);
    box.setCenter(250,475);
    back.setSize(box.getSize());
    back.setColor((box.getRed() + .4)/1.4f, (box.getGreen()+ .4)/1.4f, (box.getBlue()+ .4)/1.4f, 1.0);
    back.setCenter(box.getCenterX() + 3, box.getCenterY() + 5);
}

void init() {
    srand(time(NULL));
    initBall();
    initBox();
}

void backgroundDraw() {
    glBegin(GL_POLYGON);

    glColor3d((-osculate*change +233)/255.0f, (osculate*change +185)/255.0f, (-osculate*change +243)/255.0f);
    glVertex2d(0, 0);

    glColor3d((osculate*change +166)/255.0f, (osculate*change +161)/255.0f, (-osculate*change +243)/255.0f);
    glVertex2d(500, 0);

    glColor3d((osculate*change +191)/255.0f, (-osculate*change +230)/255.0f, (-osculate*change +247)/255.0f);
    glVertex2d(500, 500);

    glColor3d((-osculate*change +233)/255.0f, (-osculate*change +233)/255.0f, (-osculate*change +243)/255.0f);
    glVertex2d(0, 500);

    glEnd();
}

void initGL() {

    // Set "clearing" or background color
    backgroundDraw();
}

/* This function is for keyboard event while playing the game */
/* If using the normal function, the game could be restart while playing */
void kbdControl(unsigned char key, int x, int y) {

    // ESC
    if (key == 27) {
        glutDestroyWindow(wd);
    }
    switch(key) {
        case 'a':
            box.move(-15, 0);
            back.move(-15, 0);
            break;
        case 'd':
            box.move(15, 0);
            back.move(15, 0);
            break;
    }

}

void kbd(unsigned char key, int x, int y) {

    // ESC
    if (key == 27) {
        glutDestroyWindow(wd);
    }
    switch(key) {
        case 'x':
            initBall();
            glutDisplayFunc(level);
            break;
        case 'a':
            box.move(-15, 0);
            back.move(-15, 0);
            break;
        case 'd':
            box.move(15, 0);
            back.move(15, 0);
            break;
    }
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            break;
        case GLUT_KEY_LEFT:
            box.move(-15, 0);
            back.move(-15, 0);
            break;
        case GLUT_KEY_RIGHT:
            box.move(15, 0);
            back.move(15, 0);
            break;
        case GLUT_KEY_UP:
            break;
    }
    glutPostRedisplay();
}

/* For the screen when game over */
void failMessage() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the background
    backgroundDraw();
    string message = "Game Over!";
    glColor3f(0, 0, 0.2);

    glRasterPos3f(195, 180,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
    }

    glColor3f(.1, .1, 1);
    message = "Press x to restart.";
    glRasterPos3f(175, 400,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    glutSwapBuffers();
}

/* when the user reaches 20 combo */
void winningMessage() {

    // Clear the canvas
    glClear(GL_COLOR_BUFFER_BIT);
    backgroundDraw();

    string message = "You've reached " + to_string(winningScore) + " Combo!";
    glColor3f(1, 0, 1);
    glRasterPos3f(160, 150,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    message = "Congratulations!";
    glColor3f(1, 0, 1);
    glRasterPos3f(190, 180,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
    }

    glColor3f(.1, .1, 1);
    message = "Press x to restart.";
    glRasterPos3f(180, 400,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }

    glutSwapBuffers();
}

void display() {

    // Change the normal keyboard function to a trivial one
    // which does not have a restart game option.
    glutKeyboardFunc(kbdControl);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the background
    backgroundDraw();

    string message = to_string(score) + " Combo!";
    glColor3f( (score/20.0f), fmod(1.0f - 3 * (score/20.0f),1), fmod(1.0f - 2 * (score/20.0f), 1) );
    glRasterPos3f(400, 100,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    // If the ball is caught
    if ((box.isOverlapping(ball.getCenterX(), ball.getCenterY()))&&(!isBomb)) {

        // Change the color of the board to the ball's color
        box.setColor(ball.getColor());
        back.setColor((box.getRed() + .4)/1.4f, (box.getGreen()+ .4)/1.4f, (box.getBlue()+ .4)/1.4f, 1.0);

        // Move the ball to the top
        randomBomb();
        initBall();
        score ++;

        // Extend the board as a reward
        box.setWidth(box.getWidth()+6);
        back.setWidth(back.getWidth()+6);

    } else if ((box.isOverlapping(ball.getCenterX(), ball.getCenterY()))&&(isBomb)) {

        // Initiate combo and box in case the player
        // wants to restart the game.
        score = 0;
        initBox();
        randomBomb();
        glutKeyboardFunc(kbd);
        glutDisplayFunc(failMessage);
    }

    // if the ball is not caught, and it's not a bomb
    if ((ball.getTopY() >= 500) && (!isBomb)) {

        // and the board still have length
        if ((box.getWidth() > 10)){

            // move the ball to the top and decrease the length
            randomBomb();
            initBall();

            // If it's greater than the default board
            // set it to the default dimension
            if (box.getWidth() > 50) {
                box.setWidth(50);
                back.setWidth(50);

            // If it's shorter than the default.
            // shrink 10 %
            } else {
                box.shrinking();
                back.shrinking();
            }

            // Whatever the case is, set combo back to 0
            score = 0;

        // If the board is currently too short,
        // that's game over
        } else {

            // Initiate combo and box in case the player
            // wants to restart the game.
            score = 0;
            initBox();
            glutKeyboardFunc(kbd);
            glutDisplayFunc(failMessage);
        }
    } else if ((ball.getTopY() >= 500) && (isBomb)) {
        randomBomb();
        initBall();
    }

    // After all these, if combo exceeds 20,
    // call winner page.
    if (score >= winningScore) {
        score = 0;
        initBox();
        glutKeyboardFunc(kbd);
        glutDisplayFunc(winningMessage);
    }

    // Draw the 3D-like circle

    if (!(isBomb)) {
        ball.draw();
        dark.draw();
        hide.draw();
        highlight.draw();
    } else {
        drawBomb();
    }

    // Draw the board
    back.draw();
    box.draw();

    // Clear buffers and flush.
    glFlush();
    glutSwapBuffers();
}

void level() {
    // which does not have a restart game option.
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the background
    backgroundDraw();

    string message = "Beginner: 15 Combos";
    glColor3f(1, 0, 1);
    glRasterPos3f(170, 145,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }

    message = "Intermediate: 25 Combos";
    glColor3f(1, 0, 1);
    glRasterPos3f(170, 235,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    message = "Expert: 35 Combos";
    glColor3f(1, 0, 1);
    glRasterPos3f(170, 330,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    message = "Dropping speed will also grow faster.";
    glColor3f(1, 0, 1);
    glRasterPos3f(90, 110,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }

    beginner.draw();
    intermediate.draw();
    expert.draw();

    glFlush();
    glutSwapBuffers();
}

/* This is the welcome screen */
void welcomeMessage() {
    // Tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height); // DO NOT CHANGE THIS LINE

    // Do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION); // DO NOT CHANGE THIS LINE
    glLoadIdentity(); // DO NOT CHANGE THIS LINE
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f); // DO NOT CHANGE THIS LINE

    // Clear the color buffer with current clearing color
    glClear(GL_COLOR_BUFFER_BIT); // DO NOT CHANGE THIS LINE
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // DO NOT CHANGE THIS LINE

    backgroundDraw();
    string message = "Catch the Ball!";
    glColor3f(1, 0, 1);
    glRasterPos3f(195, 180,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }

    message = " Use LEFT key and RIGHT key ";
    glColor3f(.1, .1, 1);
    glRasterPos3f(135, 320,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    message = "or A and D to move the board. ";
    glRasterPos3f(133, 340,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    message = "Your goal is to reach the Combo required.";
    glRasterPos3f(85, 360,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    message = "Press x to start select level.";
    glRasterPos3f(130, 400,0);
    for (const char &letter : message) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, letter);
    }
    glutSwapBuffers();
}

void ballTimer(int dummy) {
    if (!isBomb) {
        // ball move speed depends on the current combo number
        ball.move(0, 2.5 + score * growingSpeed);
        dark.move(0, 2.5 + score * growingSpeed);
        hide.move(0, 2.5 + score * growingSpeed);
        highlight.move(0, 2.5 + score * growingSpeed);
    } else {
        // bomb drop
        ball.move(0, 2.5 + score * growingSpeed);
        bone1.move(0, 2.5 + score * growingSpeed);
        bone2.move(0, 2.5 + score * growingSpeed);
        teeth.move(0, 2.5 + score * growingSpeed);
        fuse.move(0, 2.5 + score * growingSpeed);
        eyeLeft.move(0, 2.5 + score * growingSpeed);
        eyeRight.move(0, 2.5 + score * growingSpeed);
        head.move(0, 2.5 + score * growingSpeed);
        joint1.move(0, 2.5 + score * growingSpeed);
        joint2.move(0, 2.5 + score * growingSpeed);
        joint3.move(0, 2.5 + score * growingSpeed);
        joint4.move(0, 2.5 + score * growingSpeed);
        joint5.move(0, 2.5 + score * growingSpeed);
        joint6.move(0, 2.5 + score * growingSpeed);
        joint7.move(0, 2.5 + score * growingSpeed);
        joint8.move(0, 2.5 + score * growingSpeed);
    }
    glutPostRedisplay();

    // Use 10 for a smoother FPS
    glutTimerFunc(10, ballTimer, dummy);
}

/* This part controls the random breath light of the background */
void backgroundTimer(int dummy) {
    // Only when color returns to default, we can randomly change the
    // osculation's direction.
    if (change == 0) {
        if (rand() % 2 == 0) {
            osculate = 1;
        } else {
            osculate = -1;
        }
    }

    // After knowing the direction, need to figure out if the osculation
    // moved across the spike.
    if (!turn) {
        change += 3;
        if (change >= 39) {

            // if passed the spike, turn back
            turn = true;
        }
    } else {
        change -= 3 ;
        if (change <= -39) {

            // if passed the lowest point, turn back
            turn = false;
        }
    }

    // Use 60, a relatively large number to slow the speed
    glutTimerFunc(80, backgroundTimer, dummy);
}

void cursor(int x, int y) {
    if (beginner.isOverlapping(x, y)) {
        beginner.hover();
    } else {
        beginner.release();
    }

    if (intermediate.isOverlapping(x, y)) {
        intermediate.hover();
    } else {
        intermediate.release();
    }

    if (expert.isOverlapping(x, y)) {
        expert.hover();
    } else {
        expert.release();
    }

    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && beginner.isOverlapping(x, y)) {
        beginner.pressDown();
    } else {
        beginner.release();
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && intermediate.isOverlapping(x, y)) {
        intermediate.pressDown();
    } else {
        intermediate.release();
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && expert.isOverlapping(x, y)) {
        expert.pressDown();
    } else {
        expert.release();
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && beginner.isOverlapping(x, y)) {
        growingSpeed = .09;
        winningScore = 15;
        bombLevel = 5;
        initBall();
        glutDisplayFunc(display);
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && intermediate.isOverlapping(x, y)) {
        growingSpeed = .11;
        winningScore = 25;
        bombLevel = 4;
        initBall();
        glutDisplayFunc(display);
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && expert.isOverlapping(x, y)) {
        growingSpeed = .12;
        winningScore = 35;
        bombLevel = 3;
        initBall();
        glutDisplayFunc(display);
    }
    glutPostRedisplay();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    init();
    glutInit(&argc, argv);          // Initialize GLUT
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(200, 200); // Position the window's initial top-left corner

    /* create the window and store the handle to it */
    wd = glutCreateWindow("Catch the Ball!" /* title */ );

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // mouse movement
    glutPassiveMotionFunc(cursor);

    // mouse click
    glutMouseFunc(mouse);

    // Register callback handler for window re-paint event
    glutDisplayFunc(welcomeMessage);

    // handles timer
    glutTimerFunc(0, ballTimer, 0);

    glutTimerFunc(0, backgroundTimer, 0);
    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}
