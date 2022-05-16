#include "graphics.h"
#include "rect.h"
#include <iostream>
using namespace std;

/********************* Dimensions Struct ********************/

dimensions::dimensions() : width(0), height(0) {}

dimensions::dimensions(double w, double h) : width(w), height(h) {}

ostream& operator << (ostream& outs, const dimensions &d) {
    outs << "[" << d.width << ", " << d.height << "]";
    return outs;
}


Rect::Rect() : Shape(), size({0, 0}) {
}

Rect::Rect(dimensions size) : Shape() {
    setSize(size);
}

Rect::Rect(color fill) : Shape(fill), size({0, 0}) {
}

Rect::Rect(point2D center) : Shape(center), size({0, 0}) {
}

Rect::Rect(color fill, point2D center) : Shape(fill, center), size({0, 0}) {
}

Rect::Rect(double red, double green, double blue, double alpha) : Shape(red, green, blue, alpha), size({0, 0}) {
}

Rect::Rect(double x, double y) : Shape(x, y), size({0, 0}) {
}

Rect::Rect(double red, double green, double blue, double alpha, double x, double y) : Shape(red, green, blue, alpha, x, y), size({0, 0}) {
}

Rect::Rect(color fill, double x, double y) : Shape(fill, x, y), size({0, 0}) {
}

Rect::Rect(double red, double green, double blue, double alpha, point2D center) : Shape(red, green, blue, alpha, center), size({0, 0}) {
}

Rect::Rect(color fill, dimensions size) : Shape(fill) {
    setSize(size);
}

Rect::Rect(point2D center, dimensions size) : Shape(center) {
    setSize(size);
}

Rect::Rect(color fill, point2D center, dimensions size) : Shape(fill, center) {
    setSize(size);
}

Rect::Rect(double red, double green, double blue, double alpha, dimensions size) : Shape(red, green, blue, alpha) {
    setSize(size);
}

Rect::Rect(double x, double y, dimensions size) : Shape(x, y) {
    setSize(size);
}

Rect::Rect(double red, double green, double blue, double alpha, double x, double y, dimensions size) : Shape(red, green, blue, alpha, x, y) {
    setSize(size);
}

Rect::Rect(color fill, double x, double y, dimensions size) : Shape(fill, x, y) {
    setSize(size);
}

Rect::Rect(double red, double green, double blue, double alpha, point2D center, dimensions size) : Shape(red, green, blue, alpha, center) {
    setSize(size);
}

dimensions Rect::getSize() const {
    return size;
}

double Rect::getWidth() const {
    return size.width;
}

double Rect::getHeight() const {
    return size.height;
}

double Rect::getLeftX() const {
    return center.x - (size.width / 2.0);
}

double Rect::getRightX() const {
    return center.x + (size.width / 2.0);
}

double Rect::getTopY() const {
    return center.y - (size.height / 2.0);
}

double Rect::getBottomY() const {
    return center.y + (size.height / 2.0);
}

void Rect::setSize(dimensions size) {
    if (size.width >= 0 && size.height >= 0) {
        this->size = size;
    }
}

void Rect::setSize(double width, double height) {
    setSize({width, height});
}

void Rect::setWidth(double width) {
    setSize({width, size.height});
}

void Rect::setHeight(double height) {
    setSize({size.width, height});
}

void Rect::changeSize(double deltaWidth, double deltaHeight) {
    setSize({size.width + deltaWidth, size.height + deltaHeight});
}

void Rect::changeWidth(double delta) {
    setSize({size.width + delta, size.height});
}

void Rect::changeHeight(double delta) {
    setSize({size.width, size.height + delta});
}

bool Rect::isOverlapping(double x, double y) const {
    if ((this->getRightX() <= x) || (x <= this->getLeftX())) {
        return false;
    }
    if ((this->getTopY() >= y) || (y >= this->getBottomY())) {
        return false;
    }
    return true;
}

void Rect::shrinking() {
    this->size.width -= 15;
}

void Rect::draw() const {
    // Set drawing color to fill color
    glColor3d(fill.red, fill.green, fill.blue);
    // Draw circle as Triangle Fan
    glBegin(GL_POLYGON);

    glVertex2d(this->getLeftX(), this->getTopY());
    glVertex2d(this->getRightX(), this->getTopY());
    glVertex2d(this->getRightX(), this->getBottomY());
    glVertex2d(this->getLeftX(), this->getBottomY());

    glEnd();
}

point2D Rect::pointRotate(double x1, double y1, double angle) {
    point2D result;
    result.x = (x1 - center.x)* cos(angle) - (y1- center.y)* sin(angle) + center.x;
    result.y = (y1 - center.y)* cos(angle) + (x1 - center.x)* sin(angle) + center.y;
    return result;
}

void Rect::alterDraw(double angle) {
    point2D p1; point2D p2; point2D p3; point2D p4;

    // Get rotated vertexes
    p1 = pointRotate(this->getLeftX(), this->getTopY(), angle);
    p2 = pointRotate(this->getRightX(), this->getTopY(), angle);
    p3 = pointRotate(this->getRightX(), this->getBottomY(), angle);
    p4 = pointRotate(this->getLeftX(), this->getBottomY(), angle);

    // Set drawing color to fill color
    glColor3d(fill.red, fill.green, fill.blue);
    // Draw as polygon
    glBegin(GL_POLYGON);

    // Draw the four vertexes by order.
    glVertex2d(p1.x, p1.y);
    glVertex2d(p2.x, p2.y);
    glVertex2d(p3.x, p3.y);
    glVertex2d(p4.x, p4.y);

    glEnd();
}