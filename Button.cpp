#include "Button.h"
#include "graphics.h"
using namespace std;

Button::Button(color fill, point2D center, unsigned int width, unsigned int height, std::string label) : Quad(fill, center, width, height) {
    this->label = label;
    originalFill = fill;
    hoverFill = {fill.red + 0.5, fill.green + 0.5, fill.blue + 0.5};
    pressFill = {fill.red - 0.5, fill.green - 0.5, fill.blue - 0.5};
}

void Button::draw() const {
    Quad::draw();
    glColor3f(.8, .8, 1);
    glRasterPos2i(center.x - (4 * label.length()) -2, center.y + 7);
    for (const char &letter : label) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, letter);
    }
}

/* Returns true if the coordinate is inside the box */
bool Button::isOverlapping(int x, int y) const {
    if ((x < this->getRightX()) && (x > this->getLeftX()) && (y < this->getBottomY()) && (y > this->getTopY())) {
        return true;
    }
    return false; // Placeholder for compilation
}

/* Change color of the box when the user is hovering over it */
void Button::hover() {
    setColor(hoverFill);
}

/* Change color of the box when the user is clicking on it */
void Button::pressDown() {
    setColor(pressFill);
}

/* Change the color back when the user is not clicking/hovering */
void Button::release() {
    setColor(originalFill);
}
