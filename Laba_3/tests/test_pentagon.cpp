#include <gtest/gtest.h>
#include "Pentagon.h"

TEST(PentagonTest, ValidPentagonCreation) {
    Points p1(0, 1), p2(0.95, 0.31), p3(0.59, -0.81), p4(-0.59, -0.81), p5(-0.95, 0.31);
    
    EXPECT_NO_THROW({
        Pentagon pentagon(p1, p2, p3, p4, p5);
    });
}

TEST(PentagonTest, AreaCalculation) {
    Points p1(0, 1), p2(0.95, 0.31), p3(0.59, -0.81), p4(-0.59, -0.81), p5(-0.95, 0.31);
    Pentagon pentagon(p1, p2, p3, p4, p5);
    
    double area = pentagon.area();
    EXPECT_GT(area, 0.0);
}

TEST(PentagonTest, GeometricalCenter) {
    Points p1(0, 1), p2(1, 0), p3(1, -1), p4(-1, -1), p5(-1, 0);
    Pentagon pentagon(p1, p2, p3, p4, p5);
    
    Points center = pentagon.geometricalCenter();
    EXPECT_NEAR(center.getX(), 0.0, 1e-9);
    EXPECT_NEAR(center.getY(), -0.2, 1e-9);
}

TEST(PentagonTest, CloneMethod) {
    Points p1(0, 1), p2(0.95, 0.31), p3(0.59, -0.81), p4(-0.59, -0.81), p5(-0.95, 0.31);
    Pentagon pentagon(p1, p2, p3, p4, p5);
    
    Pentagon* clone = pentagon.clone();
    EXPECT_EQ(pentagon, *clone);
    
    delete clone;
}