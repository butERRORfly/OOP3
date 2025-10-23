#include "../include/Hexagon.h"

double Hexagon::distance(const Points& A, const Points& B) const {
    return std::sqrt(std::pow(B.getX() - A.getX(), 2) + std::pow(B.getY() - A.getY(), 2));
}

double Hexagon::crossProduct(const Points& A, const Points& B, const Points& C) const {
    return (B.getX() - A.getX()) * (C.getY() - A.getY()) - 
           (B.getY() - A.getY()) * (C.getX() - A.getX());
}

bool Hexagon::isConvex(const Points& p1, const Points& p2, const Points& p3, 
                      const Points& p4, const Points& p5, const Points& p6) const {
    double cp1 = crossProduct(p1, p2, p3);
    double cp2 = crossProduct(p2, p3, p4);
    double cp3 = crossProduct(p3, p4, p5);
    double cp4 = crossProduct(p4, p5, p6);
    double cp5 = crossProduct(p5, p6, p1);
    double cp6 = crossProduct(p6, p1, p2);
    
    return (cp1 >= 0 && cp2 >= 0 && cp3 >= 0 && cp4 >= 0 && cp5 >= 0 && cp6 >= 0) ||
           (cp1 <= 0 && cp2 <= 0 && cp3 <= 0 && cp4 <= 0 && cp5 <= 0 && cp6 <= 0);
}

bool Hexagon::isValidHexagon(const Points& p1, const Points& p2, const Points& p3, 
                            const Points& p4, const Points& p5, const Points& p6) const {
    if (p1 == p2 || p1 == p3 || p1 == p4 || p1 == p5 || p1 == p6 ||
        p2 == p3 || p2 == p4 || p2 == p5 || p2 == p6 ||
        p3 == p4 || p3 == p5 || p3 == p6 ||
        p4 == p5 || p4 == p6 || p5 == p6) {
        return false;
    }
    
    return isConvex(p1, p2, p3, p4, p5, p6);
}

Hexagon::Hexagon(const Points& p1, const Points& p2, const Points& p3, 
                 const Points& p4, const Points& p5, const Points& p6) {
    if (!isValidHexagon(p1, p2, p3, p4, p5, p6)) {
        throw std::invalid_argument("Error: points do not form a valid convex hexagon.");
    }

    v_1 = p1; 
    v_2 = p2; 
    v_3 = p3; 
    v_4 = p4; 
    v_5 = p5;
    v_6 = p6;
}

Hexagon::Hexagon(const Hexagon& other) :
    v_1(other.v_1), 
    v_2(other.v_2), 
    v_3(other.v_3), 
    v_4(other.v_4), 
    v_5(other.v_5),
    v_6(other.v_6) 
{}

Hexagon::operator double() const {
    return area();
}

Hexagon::Hexagon(Hexagon&& other) noexcept :
    v_1(std::move(other.v_1)),
    v_2(std::move(other.v_2)),
    v_3(std::move(other.v_3)),
    v_4(std::move(other.v_4)),
    v_5(std::move(other.v_5)),
    v_6(std::move(other.v_6))
{
    other.v_1 = Points();
    other.v_2 = Points();
    other.v_3 = Points();
    other.v_4 = Points();
    other.v_5 = Points();
    other.v_6 = Points();
}

Points Hexagon::geometricalCenter() const {
    double centerX = (v_1.getX() + v_2.getX() + v_3.getX() + v_4.getX() + v_5.getX() + v_6.getX()) / 6;
    double centerY = (v_1.getY() + v_2.getY() + v_3.getY() + v_4.getY() + v_5.getY() + v_6.getY()) / 6;
    return Points(centerX, centerY);
}

double Hexagon::area() const {
    double sum1 = v_1.getX() * v_2.getY() + 
                  v_2.getX() * v_3.getY() + 
                  v_3.getX() * v_4.getY() + 
                  v_4.getX() * v_5.getY() + 
                  v_5.getX() * v_6.getY() +
                  v_6.getX() * v_1.getY();
    
    double sum2 = v_1.getY() * v_2.getX() + 
                  v_2.getY() * v_3.getX() + 
                  v_3.getY() * v_4.getX() + 
                  v_4.getY() * v_5.getX() + 
                  v_5.getY() * v_6.getX() +
                  v_6.getY() * v_1.getX();
    
    return std::abs(sum1 - sum2) / 2.0;
}

Figure& Hexagon::operator=(const Figure& other) {
    if (this == &other) return *this;
    
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    if (!otherHexagon) {
        throw std::invalid_argument("Cannot assign non-Hexagon to Hexagon");
    }
    
    v_1 = otherHexagon->v_1;
    v_2 = otherHexagon->v_2;
    v_3 = otherHexagon->v_3;
    v_4 = otherHexagon->v_4;
    v_5 = otherHexagon->v_5;
    v_6 = otherHexagon->v_6;
    
    return *this;
}

Figure& Hexagon::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    
    Hexagon* otherHexagon = dynamic_cast<Hexagon*>(&other);
    if (otherHexagon) {
        v_1 = std::move(otherHexagon->v_1);
        v_2 = std::move(otherHexagon->v_2);
        v_3 = std::move(otherHexagon->v_3);
        v_4 = std::move(otherHexagon->v_4);
        v_5 = std::move(otherHexagon->v_5);
        v_6 = std::move(otherHexagon->v_6);
    }
    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    if (!otherHexagon) return false;
    
    return v_1 == otherHexagon->v_1 && 
           v_2 == otherHexagon->v_2 && 
           v_3 == otherHexagon->v_3 && 
           v_4 == otherHexagon->v_4 && 
           v_5 == otherHexagon->v_5 &&
           v_6 == otherHexagon->v_6;
}

Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this == &other) return *this;
    
    v_1 = other.v_1;
    v_2 = other.v_2;
    v_3 = other.v_3;
    v_4 = other.v_4;
    v_5 = other.v_5;
    v_6 = other.v_6;
    
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this == &other) return *this;
    
    v_1 = std::move(other.v_1);
    v_2 = std::move(other.v_2);
    v_3 = std::move(other.v_3);
    v_4 = std::move(other.v_4);
    v_5 = std::move(other.v_5);
    v_6 = std::move(other.v_6);
    
    return *this;
}

bool Hexagon::operator==(const Hexagon& other) const {
    if (this == &other) return true;
    
    return v_1 == other.v_1 && 
           v_2 == other.v_2 && 
           v_3 == other.v_3 && 
           v_4 == other.v_4 && 
           v_5 == other.v_5 &&
           v_6 == other.v_6;
}

Hexagon* Hexagon::clone() const {
    return new Hexagon(*this);
}

std::ostream &operator<<(std::ostream &stream, const Hexagon &hexagon) {
    stream << "Hexagon vertices: ";
    stream << "(" << hexagon.v_1.getX() << ", " << hexagon.v_1.getY() << ") ";
    stream << "(" << hexagon.v_2.getX() << ", " << hexagon.v_2.getY() << ") ";
    stream << "(" << hexagon.v_3.getX() << ", " << hexagon.v_3.getY() << ") ";
    stream << "(" << hexagon.v_4.getX() << ", " << hexagon.v_4.getY() << ") ";
    stream << "(" << hexagon.v_5.getX() << ", " << hexagon.v_5.getY() << ") ";
    stream << "(" << hexagon.v_6.getX() << ", " << hexagon.v_6.getY() << ")";
    return stream;
}

std::istream &operator>>(std::istream &stream, Hexagon &hexagon) {
    double x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;
    
    std::cout << "Enter six vertices of the hexagon (x1 y1 x2 y2 x3 y3 x4 y4 x5 y5 x6 y6): ";
    stream >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    Points p1(x1, y1);
    Points p2(x2, y2);
    Points p3(x3, y3);
    Points p4(x4, y4);
    Points p5(x5, y5);
    Points p6(x6, y6);
    
    hexagon = Hexagon(p1, p2, p3, p4, p5, p6);
    
    return stream;
}