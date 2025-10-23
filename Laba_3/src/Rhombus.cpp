#include "../include/Rhombus.h"

Points Rhombus::findFourthVertex(const Points& A, const Points& B, const Points& C) const {
    return Points(A.getX() + C.getX() - B.getX(), A.getY() + C.getY() - B.getY());
}

double Rhombus::distance(const Points& A, const Points& B) const {
    return std::sqrt(std::pow(B.getX() - A.getX(), 2) + std::pow(B.getY() - A.getY(), 2));
}

bool Rhombus::isRhombus(const Points& A, const Points& B, const Points& C) const {
    Points D = findFourthVertex(A, B, C);
    
    double ab = distance(A, B);
    double bc = distance(B, C);
    double cd = distance(C, D);
    double da = distance(D, A);
    
    const double epsilon = 1e-9;
    bool sidesEqual = std::abs(ab - bc) < epsilon && 
                      std::abs(bc - cd) < epsilon && 
                      std::abs(cd - da) < epsilon;
    
    double ac = distance(A, C);
    double bd = distance(B, D);
    
    double dx1 = C.getX() - A.getX();
    double dy1 = C.getY() - A.getY();
    double dx2 = D.getX() - B.getX();
    double dy2 = D.getY() - B.getY();
    
    double dotProduct = dx1 * dx2 + dy1 * dy2;
    bool diagonalsPerpendicular = std::abs(dotProduct) < epsilon;
    
    return sidesEqual && diagonalsPerpendicular;
}

Rhombus::Rhombus(const Points& A, const Points& B, const Points& C) {
    if (!isRhombus(A, B, C)) {
            throw std::invalid_argument("Error: points do not form a rhombus.");
        }

    v_1 = A; v_2 = B; v_3 = C;
    v_4 = findFourthVertex(A, B, C);
}

Rhombus::Rhombus(const Rhombus& other) :
    v_1(other.v_1), 
    v_2(other.v_2), 
    v_3(other.v_3), 
    v_4(other.v_4) 
{}

Rhombus::operator double() const {
    double d1 = distance(v_1, v_3);
    double d2 = distance(v_2, v_4);
    return (d1 * d2) / 2;
}

Rhombus::Rhombus(Rhombus&& other) noexcept :
      v_1(std::move(other.v_1)),
      v_2(std::move(other.v_2)),
      v_3(std::move(other.v_3)),
      v_4(std::move(other.v_4))
{
    other.v_1 = Points();
    other.v_2 = Points();
    other.v_3 = Points();
    other.v_4 = Points();
}


Points Rhombus::geometricalCenter() const {
    double centerX = (v_1.getX() + v_2.getX() + v_3.getX() + v_4.getX()) / 4;
    double centerY = (v_1.getY() + v_2.getY() + v_3.getY() + v_4.getY()) / 4;
    return Points(centerX, centerY);
}

double Rhombus::area() const {
    return static_cast<double>(*this);
}

Figure& Rhombus::operator=(const Figure& other) {
    if (this == &other) return *this;
    
    const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    if (!otherRhombus) {
        throw std::invalid_argument("Cannot assign non-Rhombus to Rhombus");
    }
    
    v_1 = otherRhombus->v_1;
    v_2 = otherRhombus->v_2;
    v_3 = otherRhombus->v_3;
    v_4 = otherRhombus->v_4;
    
    return *this;
}

Figure& Rhombus::operator=(Figure&& other) noexcept {
    if (this == &other) return *this;
    
    Rhombus* otherRhombus = dynamic_cast<Rhombus*>(&other);
    if (otherRhombus) {
        v_1 = std::move(otherRhombus->v_1);
        v_2 = std::move(otherRhombus->v_2);
        v_3 = std::move(otherRhombus->v_3);
        v_4 = std::move(otherRhombus->v_4);
    }
    return *this;
}

bool Rhombus::operator==(const Figure& other) const {
    const Rhombus* otherRhombus = dynamic_cast<const Rhombus*>(&other);
    if (!otherRhombus) return false;
    
    return v_1 == otherRhombus->v_1 && 
           v_2 == otherRhombus->v_2 && 
           v_3 == otherRhombus->v_3 && 
           v_4 == otherRhombus->v_4;
}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this == &other) return *this;
    
    v_1 = other.v_1;
    v_2 = other.v_2;
    v_3 = other.v_3;
    v_4 = other.v_4;
    
    return *this;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this == &other) return *this;
    
    v_1 = std::move(other.v_1);
    v_2 = std::move(other.v_2);
    v_3 = std::move(other.v_3);
    v_4 = std::move(other.v_4);
    
    return *this;
}

bool Rhombus::operator==(const Rhombus& other) const {
    if (this == &other) return true;
    
    return v_1 == other.v_1 && 
           v_2 == other.v_2 && 
           v_3 == other.v_3 && 
           v_4 == other.v_4;
}

Rhombus* Rhombus::clone() const {
    return new Rhombus(*this);
}

std::ostream &operator<<(std::ostream &stream, const Rhombus &rhombus) {
    stream << "Rhombus vertices: ";
    stream << "(" << rhombus.v_1.getX() << ", " << rhombus.v_1.getY() << ") ";
    stream << "(" << rhombus.v_2.getX() << ", " << rhombus.v_2.getY() << ") ";
    stream << "(" << rhombus.v_3.getX() << ", " << rhombus.v_3.getY() << ") ";
    stream << "(" << rhombus.v_4.getX() << ", " << rhombus.v_4.getY() << ")";
    return stream;
}

std::istream &operator>>(std::istream &stream, Rhombus &rhombus) {
    double x_1, y_1, x_2, y_2, x_3, y_3;
    
    std::cout << "Enter three vertices of the rhombus (x1 y1 x2 y2 x3 y3): ";
    stream >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;


    Points A (x_1, y_1);
    Points B (x_2, y_2);
    Points C (x_3, y_3);
    Points D = rhombus.findFourthVertex(Points(x_1, y_1), Points(x_2, y_2), Points(x_3, y_3));
    
    rhombus.v_1 = A;
    rhombus.v_2 = B;
    rhombus.v_3 = C;
    rhombus.v_4 = D;
    
    return stream;
}
