#include <gtest/gtest.h>
#include "Points.h"

TEST(PointsTest, DefaultConstructor) {
    Points p;
    EXPECT_DOUBLE_EQ(p.getX(), 0.0);
    EXPECT_DOUBLE_EQ(p.getY(), 0.0);
}

TEST(PointsTest, ParameterizedConstructor) {
    Points p(3.5, -2.1);
    EXPECT_DOUBLE_EQ(p.getX(), 3.5);
    EXPECT_DOUBLE_EQ(p.getY(), -2.1);
}

TEST(PointsTest, CopyConstructor) {
    Points p1(1.0, 2.0);
    Points p2(p1);
    EXPECT_DOUBLE_EQ(p2.getX(), 1.0);
    EXPECT_DOUBLE_EQ(p2.getY(), 2.0);
}

TEST(PointsTest, AssignmentOperator) {
    Points p1(1.0, 2.0);
    Points p2;
    p2 = p1;
    EXPECT_DOUBLE_EQ(p2.getX(), 1.0);
    EXPECT_DOUBLE_EQ(p2.getY(), 2.0);
}

TEST(PointsTest, MoveConstructor) {
    Points p1(1.0, 2.0);
    Points p2(std::move(p1));
    EXPECT_DOUBLE_EQ(p2.getX(), 1.0);
    EXPECT_DOUBLE_EQ(p2.getY(), 2.0);
}

TEST(PointsTest, EqualityOperator) {
    Points p1(1.0, 2.0);
    Points p2(1.0, 2.0);
    Points p3(1.0, 3.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
}

TEST(PointsTest, AdditionOperator) {
    Points p1(1.0, 2.0);
    Points p2(3.0, 4.0);
    Points result = p1 + p2;
    
    EXPECT_DOUBLE_EQ(result.getX(), 4.0);
    EXPECT_DOUBLE_EQ(result.getY(), 6.0);
}

TEST(PointsTest, SubtractionOperator) {
    Points p1(5.0, 6.0);
    Points p2(2.0, 3.0);
    Points result = p1 - p2;
    
    EXPECT_DOUBLE_EQ(result.getX(), 3.0);
    EXPECT_DOUBLE_EQ(result.getY(), 3.0);
}