#ifndef POINTS_H
#define POINTS_H

#include <iostream>

class Points {
    friend std::ostream& operator<<(std::ostream& os, const Points& p);
    friend std::istream& operator>>(std::istream& is, Points& p);
    friend Points operator+(const Points& left, const Points& right);
    friend Points operator-(const Points& left, const Points& right);
    friend bool operator<(const Points& left, const Points& right);
    friend bool operator>(const Points& left, const Points& right);
    friend bool operator==(const Points& left, const Points& right);
public:
    Points() = default;

    Points(double x, double y);
    Points(const Points& other);
    Points(Points&& other) noexcept;
    Points& operator=(const Points& other);
    Points& operator=(Points&& other) noexcept;

    double getX() const;
    double getY() const;

    virtual ~Points() noexcept = default;
protected:
    double p_x {};
    double p_y {};
};

#endif