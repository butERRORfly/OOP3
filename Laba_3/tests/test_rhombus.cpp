#include <gtest/gtest.h>
#include "Rhombus.h"

TEST(RhombusTest, ValidRhombusCreation) {
    Points A(0, 0), B(2, 2), C(4, 0);
    
    EXPECT_NO_THROW({
        Rhombus rhombus(A, B, C);
    });
}

TEST(RhombusTest, InvalidRhombusCreation) {
    Points A(0, 0), B(1, 1), C(3, 0);
    
    EXPECT_THROW({
        Rhombus rhombus(A, B, C);
    }, std::invalid_argument);
}

TEST(RhombusTest, AreaCalculation) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus(A, B, C);
    
    double area = rhombus.area();
    EXPECT_NEAR(area, 8.0, 1e-9);
}

TEST(RhombusTest, GeometricalCenter) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus(A, B, C);
    
    Points center = rhombus.geometricalCenter();
    EXPECT_NEAR(center.getX(), 2.0, 1e-9);
    EXPECT_NEAR(center.getY(), 0.0, 1e-9);
}

TEST(RhombusTest, CopyConstructor) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus1(A, B, C);
    Rhombus rhombus2(rhombus1);
    
    EXPECT_EQ(rhombus1, rhombus2);
}

TEST(RhombusTest, AssignmentOperator) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus1(A, B, C);
    Rhombus rhombus2 = rhombus1;
    
    EXPECT_EQ(rhombus1, rhombus2);
}

TEST(RhombusTest, MoveConstructor) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus1(A, B, C);
    Rhombus rhombus2(std::move(rhombus1));
    
    EXPECT_NEAR(rhombus2.area(), 8.0, 1e-9);
}

TEST(RhombusTest, DoubleConversion) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus(A, B, C);
    
    double area = static_cast<double>(rhombus);
    EXPECT_NEAR(area, 8.0, 1e-9);
}

TEST(RhombusTest, EqualityOperator) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus1(A, B, C);
    Rhombus rhombus2(A, B, C);
    
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(RhombusTest, CloneMethod) {
    Points A(0, 0), B(2, 2), C(4, 0);
    Rhombus rhombus(A, B, C);
    
    Rhombus* clone = rhombus.clone();
    EXPECT_EQ(rhombus, *clone);
    
    delete clone;
}