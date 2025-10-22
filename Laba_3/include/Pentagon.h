#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <cmath>

class Pentagon : public Figure {
    friend std::ostream &operator<<(std::ostream &stream, const Pentagon &pentagon);
    friend std::istream &operator>>(std::istream &stream, Pentagon &pentagon);
private:
    Points v_1, v_2, v_3, v_4, v_5;
    bool isValidPentagon(const Points& p1, const Points& p2, const Points& p3, 
                        const Points& p4, const Points& p5) const;
    double distance(const Points& A, const Points& B) const;
    double crossProduct(const Points& A, const Points& B, const Points& C) const;
    bool isConvex(const Points& p1, const Points& p2, const Points& p3, 
                 const Points& p4, const Points& p5) const;
public:
    Pentagon() = default;
    Pentagon(const Points& p1, const Points& p2, const Points& p3, 
             const Points& p4, const Points& p5);
    Pentagon(const Pentagon& other);
    Pentagon(Pentagon&& other) noexcept;

    virtual Points geometricalCenter() const override;
    virtual double area() const override;

    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
    bool operator==(const Pentagon& other) const;

    virtual Figure& operator=(const Figure& other) override;
    virtual Figure& operator=(Figure&& other) noexcept override;
    virtual bool operator==(const Figure& other) const override;
    virtual operator double() const override;

    virtual Pentagon* clone() const override;

    virtual ~Pentagon() = default;
};

#endif