#include "../include/Points.h"

Points::Points(double x, double y) : p_x(x), p_y(y) {};

Points::Points(const Points& other) : p_x(other.p_x), p_y(other.p_y) {};

Points::Points(Points&& other) noexcept : p_x(other.p_x), p_y(other.p_y) {
    other.p_x = 0.0;
    other.p_y = 0.0;
}

Points& Points::operator=(const Points& other) {
    if (this != &other) {
        p_x = other.p_x;
        p_y = other.p_y;
    }

    return *this;
}

Points& Points::operator=(Points&& other) noexcept {
    if (this != &other) {
        p_x = other.p_x;
        p_y = other.p_y;
        other.p_x = 0.0;
        other.p_y = 0.0;
    }

    return *this;
}

Points operator+(const Points& left, const Points& right) {
    return Points(left.p_x + right.p_x, left.p_y + right.p_y);
}

Points operator-(const Points& left, const Points& right) {
    return Points(left.p_x - right.p_x, left.p_y - right.p_y);
}

bool operator<(const Points& left, const Points& right) {
    if (left.p_x < right.p_x)
        return true;
    if (left.p_x == right.p_x && left.p_y < right.p_y)
        return true;
    return false;
}

bool operator>(const Points& left, const Points& right) {
    if (left.p_x > right.p_x)
        return true;
    if (left.p_x == right.p_x && left.p_y > right.p_y)
        return true;
    return false;
}

bool operator==(const Points& left, const Points& right) {
    return (left.p_x == right.p_x) && (left.p_y == right.p_y);
}

std::ostream& operator<<(std::ostream& os, const Points& p) {
    os << "Point [ x: " << p.p_x << ", y: " << p.p_y << "]";
    return os;
}

std::istream& operator>>(std::istream& is, Points& p) {
    double x_coordinate;
    double y_coordinate;

    std::cout << "Please type in the coordinates for the point" << std::endl;
    std::cout << "order [x,y], separated by spaces: ";

    is >> x_coordinate >> y_coordinate;
    
    p.p_x = x_coordinate;
    p.p_y = y_coordinate;

    return is;
}

double Points::getX() const {
    return p_x;
}

double Points::getY() const {
    return p_y;
}