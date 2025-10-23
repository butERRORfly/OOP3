#ifndef HEXAGON_H
#define HEXAGON_H

#include "Figure.h"
#include <cmath>

class Hexagon : public Figure {
    friend std::ostream &operator<<(std::ostream &stream, const Hexagon &hexagon);
    friend std::istream &operator>>(std::istream &stream, Hexagon &hexagon);
private:
    Points v_1, v_2, v_3, v_4, v_5, v_6;
    bool isValidHexagon(const Points& p1, const Points& p2, const Points& p3, 
                       const Points& p4, const Points& p5, const Points& p6) const;
    double distance(const Points& A, const Points& B) const;
    double crossProduct(const Points& A, const Points& B, const Points& C) const;
    bool isConvex(const Points& p1, const Points& p2, const Points& p3, 
                 const Points& p4, const Points& p5, const Points& p6) const;
public:
    Hexagon() = default;
    Hexagon(const Points& p1, const Points& p2, const Points& p3, 
            const Points& p4, const Points& p5, const Points& p6);
    Hexagon(const Hexagon& other);
    Hexagon(Hexagon&& other) noexcept;

    virtual Points geometricalCenter() const override;
    virtual double area() const override;

    Hexagon& operator=(const Hexagon& other);
    Hexagon& operator=(Hexagon&& other) noexcept;
    bool operator==(const Hexagon& other) const;

    virtual Figure& operator=(const Figure& other) override;
    virtual Figure& operator=(Figure&& other) noexcept override;
    virtual bool operator==(const Figure& other) const override;
    virtual operator double() const override;

    virtual Hexagon* clone() const override;

    virtual ~Hexagon() = default;
};

#endif