#include "../include/Pentagon.h"

double Pentagon::distance(const Points& A, const Points& B) const {
    return std::sqrt(std::pow(B.getX() - A.getX(), 2) + std::pow(B.getY() - A.getY(), 2));
}

double Pentagon::crossProduct(const Points& A, const Points& B, const Points& C) const {
    return (B.getX() - A.getX()) * (C.getY() - A.getY()) - 
           (B.getY() - A.getY()) * (C.getX() - A.getX());
}

bool Pentagon::isConvex(const Points& p1, const Points& p2, const Points& p3, 
                       const Points& p4, const Points& p5) const {
    double cp1 = crossProduct(p1, p2, p3);
    double cp2 = crossProduct(p2, p3, p4);
    double cp3 = crossProduct(p3, p4, p5);
    double cp4 = crossProduct(p4, p5, p1);
    double cp5 = crossProduct(p5, p1, p2);
    
    return (cp1 >= 0 && cp2 >= 0 && cp3 >= 0 && cp4 >= 0 && cp5 >= 0) ||
           (cp1 <= 0 && cp2 <= 0 && cp3 <= 0 && cp4 <= 0 && cp5 <= 0);
}

bool Pentagon::isValidPentagon(const Points& p1, const Points& p2, const Points& p3, 
                              const Points& p4, const Points& p5) const {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p1 == p5 ||
        p2 == p3 || p2 == p4 || p2 == p5 ||
        p3 == p4 || p3 == p5 || p4 == p5) {
        return false;
    }
    
    return isConvex(p1, p2, p3, p4, p5);
}

Pentagon::Pentagon(const Points& p1, const Points& p2, const Points& p3, 
                   const Points& p4, const Points& p5) {
    if (!isValidPentagon(p1, p2, p3, p4, p5)) {
        throw std::invalid_argument("Error: points do not form a valid convex pentagon.");
    }

    v_1 = p1; 
    v_2 = p2; 
    v_3 = p3; 
    v_4 = p4; 
    v_5 = p5;
}

Pentagon::Pentagon(const Pentagon& other) :
    v_1(other.v_1), 
    v_2(other.v_2), 
    v_3(other.v_3), 
    v_4(other.v_4), 
    v_5(other.v_5) 
{}

Pentagon::operator double() const {
    return area();
}

Pentagon::Pentagon(Pentagon&& other) noexcept :
    v_1(std::move(other.v_1)),
    v_2(std::move(other.v_2)),
    v_3(std::move(other.v_3)),
    v_4(std::move(other.v_4)),
    v_5(std::move(other.v_5))
{
    other.v_1 = Points();
    other.v_2 = Points();
    other.v_3 = Points();
    other.v_4 = Points();
    other.v_5 = Points();
}

Points Pentagon::geometricalCenter() const {
    double centerX = (v_1.getX() + v_2.getX() + v_3.getX() + v_4.getX() + v_5.getX()) / 5;
    double centerY = (v_1.getY() + v_2.getY() + v_3.getY() + v_4.getY() + v_5.getY()) / 5;
    return Points(centerX, centerY);
}

double Pentagon::area() const {
    double sum1 = v_1.getX() * v_2.getY() + 
                  v_2.getX() * v_3.getY() + 
                  v_3.getX() * v_4.getY() + 
                  v_4.getX() * v_5.getY() + 
                  v_5.getX() * v_1.getY();
    
    double sum2 = v_1.getY() * v_2.getX() + 
                  v_2.getY() * v_3.getX() + 
                  v_3.getY() * v_4.getX() + 
                  v_4.getY() * v_5.getX() + 
                  v_5.getY() * v_1.getX();
    
    return std::abs(sum1 - sum2) / 2.0;
}

Figure& Pentagon::operator=(const Figure& other) {
    if (this == &other) return *this;
    
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (!otherPentagon) {
        throw std::invalid_argument("Cannot assign non-Pentagon to Pentagon");
    }
    
    v_1 = otherPentagon->v_1;
    v_2 = otherPentagon->v_2;
    v_3 = otherPentagon->v_3;
    v_4 = otherPentagon->v_4;
    v_5 = otherPentagon->v_5;
    
    return *this;
}

Figure& Pentagon::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    
    Pentagon* otherPentagon = dynamic_cast<Pentagon*>(&other);
    if (otherPentagon) {
        v_1 = std::move(otherPentagon->v_1);
        v_2 = std::move(otherPentagon->v_2);
        v_3 = std::move(otherPentagon->v_3);
        v_4 = std::move(otherPentagon->v_4);
        v_5 = std::move(otherPentagon->v_5);
    }
    return *this;
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (!otherPentagon) return false;
    
    return v_1 == otherPentagon->v_1 && 
           v_2 == otherPentagon->v_2 && 
           v_3 == otherPentagon->v_3 && 
           v_4 == otherPentagon->v_4 && 
           v_5 == otherPentagon->v_5;
}

Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this == &other) return *this;
    
    v_1 = other.v_1;
    v_2 = other.v_2;
    v_3 = other.v_3;
    v_4 = other.v_4;
    v_5 = other.v_5;
    
    return *this;
}

Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this == &other) return *this;
    
    v_1 = std::move(other.v_1);
    v_2 = std::move(other.v_2);
    v_3 = std::move(other.v_3);
    v_4 = std::move(other.v_4);
    v_5 = std::move(other.v_5);
    
    return *this;
}

bool Pentagon::operator==(const Pentagon& other) const {
    if (this == &other) return true;
    
    return v_1 == other.v_1 && 
           v_2 == other.v_2 && 
           v_3 == other.v_3 && 
           v_4 == other.v_4 && 
           v_5 == other.v_5;
}

Pentagon* Pentagon::clone() const {
    return new Pentagon(*this);
}

std::ostream &operator<<(std::ostream &stream, const Pentagon &pentagon) {
    stream << "Pentagon vertices: ";
    stream << "(" << pentagon.v_1.getX() << ", " << pentagon.v_1.getY() << ") ";
    stream << "(" << pentagon.v_2.getX() << ", " << pentagon.v_2.getY() << ") ";
    stream << "(" << pentagon.v_3.getX() << ", " << pentagon.v_3.getY() << ") ";
    stream << "(" << pentagon.v_4.getX() << ", " << pentagon.v_4.getY() << ") ";
    stream << "(" << pentagon.v_5.getX() << ", " << pentagon.v_5.getY() << ")";
    return stream;
}

std::istream &operator>>(std::istream &stream, Pentagon &pentagon) {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5;
    
    std::cout << "Enter five vertices of the pentagon (x1 y1 x2 y2 x3 y3 x4 y4 x5 y5): ";
    stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5;

    Points p1(x1, y1);
    Points p2(x2, y2);
    Points p3(x3, y3);
    Points p4(x4, y4);
    Points p5(x5, y5);
    
    pentagon = Pentagon(p1, p2, p3, p4, p5);
    
    return stream;
}