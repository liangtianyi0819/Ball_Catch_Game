#ifndef GRAPHICS_STARTER_BUTTON_H
#define GRAPHICS_STARTER_BUTTON_H

#include "Quad.h"
#include <string>

class Button : public Quad {
private:
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    Button(color fill, point2D center, unsigned int width, unsigned int height, std::string label);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw() const override;

    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Change color of the Button when the user is hovering over it */
    void hover();

    /* Change color of the Button when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();
};


#endif //GRAPHICS_STARTER_BUTTON_H
