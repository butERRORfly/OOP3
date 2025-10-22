#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "Points.h"

class Figure {
protected:
    Figure() = default;
public:
    virtual Points geometricalCenter() const = 0;
    virtual double area() const = 0;

    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) noexcept = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual operator double() const = 0;   

    virtual Figure* clone() const = 0;

    virtual ~Figure() noexcept = default;
};

#endif