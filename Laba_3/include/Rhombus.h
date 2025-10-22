#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <cmath>

class Rhombus : public Figure {
    friend std::ostream &operator<<(std::ostream &stream, const Rhombus &rhombus);
    friend std::istream &operator>>(std::istream &stream, Rhombus &rhombus);
private:
    Points v_1, v_2, v_3, v_4;
    Points findFourthVertex(const Points& A, const Points& B, const Points& C) const;
    bool isRhombus(const Points& A, const Points& B, const Points& C) const;
    double distance(const Points& A, const Points& B) const;
public:
    Rhombus() = default;
    Rhombus(const Points& A, const Points& B, const Points& C);
    Rhombus(const Rhombus& other);
    Rhombus(Rhombus&& other) noexcept;

    virtual Points geometricalCenter() const override;
    virtual double area() const override;

    Rhombus& operator=(const Rhombus& other);
    Rhombus& operator=(Rhombus&& other) noexcept;
    bool operator==(const Rhombus& other) const;

    virtual Figure& operator=(const Figure& other) override;
    virtual Figure& operator=(Figure&& other) noexcept override;
    virtual bool operator==(const Figure& other) const override;
    virtual operator double() const override;

    virtual Rhombus* clone() const override;

    virtual ~Rhombus() = default;
};

#endif