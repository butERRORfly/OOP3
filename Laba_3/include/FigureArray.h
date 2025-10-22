#ifndef FIGUREARRAY_H
#define FIGUREARRAY_H
#include "Figure.h"
#include "Rhombus.h"
#include "Pentagon.h"
#include "Hexagon.h"
#include <cassert>

class FigureArray {
private:
    size_t arraySize, capacity;
    Figure** data;

    void setNewCapacity(size_t capacity);
    static Figure** reallocate(Figure** oldData, size_t oldSize, size_t newSize);
public:
    FigureArray();

    FigureArray(size_t arraySize);
    FigureArray(const FigureArray& other);
    FigureArray(FigureArray&& other) noexcept;

    Figure* & operator[](size_t index);
    Figure* const & operator[] (size_t index) const;

    size_t getSize() const;
    void pushBack(Figure* figure);
    void pushFront(Figure* figure);
    void popBack();
    void popFront();
    void popByIndex(size_t index);

    void printAllCenters() const;
    void printAllAreas() const;
    double getTotalArea() const;
    void printAllInfo() const;

    virtual ~FigureArray() noexcept;
};

#endif