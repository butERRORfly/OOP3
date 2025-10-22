#include <gtest/gtest.h>
#include "FigureArray.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"

class FigureArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        Points r1(0, 0), r2(2, 2), r3(4, 0);
        rhombus = new Rhombus(r1, r2, r3);
        
        Points p1(0, 1), p2(0.95, 0.31), p3(0.59, -0.81), p4(-0.59, -0.81), p5(-0.95, 0.31);
        pentagon = new Pentagon(p1, p2, p3, p4, p5);
        
        Points h1(1, 0), h2(0.5, 0.87), h3(-0.5, 0.87), 
               h4(-1, 0), h5(-0.5, -0.87), h6(0.5, -0.87);
        hexagon = new Hexagon(h1, h2, h3, h4, h5, h6);
    }
    
    void TearDown() override {
        delete rhombus;
        delete pentagon;
        delete hexagon;
    }
    
    Rhombus* rhombus;
    Pentagon* pentagon;
    Hexagon* hexagon;
};

TEST_F(FigureArrayTest, DefaultConstructor) {
    FigureArray array;
    EXPECT_EQ(array.getSize(), 0);
}

TEST_F(FigureArrayTest, PushBack) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    
    EXPECT_EQ(array.getSize(), 1);
    EXPECT_NE(array[0], nullptr);
}

TEST_F(FigureArrayTest, PushFront) {
    FigureArray array;
    array.pushBack(pentagon->clone());
    array.pushFront(rhombus->clone());
    
    EXPECT_EQ(array.getSize(), 2);
    EXPECT_TRUE(dynamic_cast<Rhombus*>(array[0]) != nullptr);
}

TEST_F(FigureArrayTest, PopBack) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(pentagon->clone());
    
    EXPECT_EQ(array.getSize(), 2);
    array.popBack();
    EXPECT_EQ(array.getSize(), 1);
}

TEST_F(FigureArrayTest, PopFront) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(pentagon->clone());
    
    EXPECT_EQ(array.getSize(), 2);
    array.popFront();
    EXPECT_EQ(array.getSize(), 1);
}

TEST_F(FigureArrayTest, PopByIndex) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(pentagon->clone());
    array.pushBack(hexagon->clone());
    
    EXPECT_EQ(array.getSize(), 3);
    array.popByIndex(1);
    EXPECT_EQ(array.getSize(), 2);
}

TEST_F(FigureArrayTest, TotalAreaCalculation) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(pentagon->clone());
    array.pushBack(hexagon->clone());
    
    double totalArea = array.getTotalArea();
    EXPECT_GT(totalArea, 0.0);
    
    double expectedTotal = rhombus->area() + pentagon->area() + hexagon->area();
    EXPECT_NEAR(totalArea, expectedTotal, 1e-9);
}

TEST_F(FigureArrayTest, CopyConstructor) {
    FigureArray array1;
    array1.pushBack(rhombus->clone());
    array1.pushBack(pentagon->clone());
    
    FigureArray array2(array1);
    EXPECT_EQ(array1.getSize(), array2.getSize());
    
    EXPECT_NE(array1[0], array2[0]);
}


TEST_F(FigureArrayTest, EmptyArrayOperations) {
    FigureArray array;
    
    EXPECT_NO_THROW(array.popBack());
    EXPECT_NO_THROW(array.popFront());
    EXPECT_NO_THROW(array.popByIndex(0));
    
    EXPECT_EQ(array.getTotalArea(), 0.0);
}

TEST_F(FigureArrayTest, AccessOperator) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    
    EXPECT_NO_THROW({
        Figure* figure = array[0];
        EXPECT_NE(figure, nullptr);
    });
    
}

TEST_F(FigureArrayTest, PolymorphicBehavior) {
    FigureArray array;
    array.pushBack(rhombus->clone());
    array.pushBack(pentagon->clone());
    array.pushBack(hexagon->clone());
    
    for (size_t i = 0; i < array.getSize(); ++i) {
        Figure* figure = array[i];
        EXPECT_NE(figure, nullptr);
        
        EXPECT_GT(figure->area(), 0.0);
        
        Points center = figure->geometricalCenter();
        EXPECT_TRUE(center.getX() == center.getX());
        EXPECT_TRUE(center.getY() == center.getY());
    }
}