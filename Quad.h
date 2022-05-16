#ifndef CONFETTIFY_QUAD_H
#define CONFETTIFY_QUAD_H

#include "shape.h"

class Quad {
protected:
    color fill;
    point2D center;
    unsigned int width;
    unsigned int height;

public:
    Quad();
    Quad(color fill, point2D center, unsigned int width, unsigned int height);

    int getCenterX() const;
    int getLeftX() const;
    int getRightX() const;
    int getCenterY() const;
    int getTopY() const;
    int getBottomY() const;
    point2D getCenter() const;

    double getRed() const;
    double getGreen() const;
    double getBlue() const;
    color getFill() const;

    unsigned int getWidth() const;
    unsigned int getHeight() const;

    void setColor(double red, double green, double blue);
    void setColor(color fill);
    void move(int deltaX, int deltaY);
    void resize(unsigned int width, unsigned int height);

    virtual void draw() const;
};

#endif //CONFETTIFY_QUAD_H
