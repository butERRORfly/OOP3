#include <gtest/gtest.h>
#include "Hexagon.h"

TEST(HexagonTest, ValidHexagonCreation) {
    Points h1(1, 0), h2(0.5, 0.87), h3(-0.5, 0.87), 
           h4(-1, 0), h5(-0.5, -0.87), h6(0.5, -0.87);
    
    EXPECT_NO_THROW({
        Hexagon hexagon(h1, h2, h3, h4, h5, h6);
    });
}

TEST(HexagonTest, GeometricalCenter) {
    Points h1(1, 0), h2(0.5, 0.87), h3(-0.5, 0.87), 
           h4(-1, 0), h5(-0.5, -0.87), h6(0.5, -0.87);
    Hexagon hexagon(h1, h2, h3, h4, h5, h6);
    
    Points center = hexagon.geometricalCenter();
    EXPECT_NEAR(center.getX(), 0.0, 1e-9);
    EXPECT_NEAR(center.getY(), 0.0, 1e-9);
}

TEST(HexagonTest, CloneMethod) {
    Points h1(1, 0), h2(0.5, 0.87), h3(-0.5, 0.87), 
           h4(-1, 0), h5(-0.5, -0.87), h6(0.5, -0.87);
    Hexagon hexagon(h1, h2, h3, h4, h5, h6);
    
    Hexagon* clone = hexagon.clone();
    EXPECT_EQ(hexagon, *clone);
    
    delete clone;
}