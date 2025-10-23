#include "../include/FigureArray.h"

Figure** FigureArray::reallocate(Figure** oldData, size_t oldSize, size_t newSize) {
    Figure** newData = new Figure*[newSize];
    size_t minSize = std::min(oldSize, newSize);

    for (size_t i = 0; i < minSize; ++i)
        newData[i] = oldData[i];

    for (size_t i = minSize; i < newSize; ++i)
        newData[i] = nullptr;

    delete[] oldData;
    oldData = nullptr;
    return newData;
}

void FigureArray::setNewCapacity(size_t newCapacity) {
    data = reallocate(data, arraySize, newCapacity);
    capacity = newCapacity;
}

FigureArray::FigureArray() : arraySize(0), capacity(0), data(nullptr) {};

FigureArray::FigureArray(size_t arraysize) : arraySize(arraysize), capacity(arraysize) {
    data = reallocate(nullptr, 0, arraysize);
};

FigureArray::FigureArray(const FigureArray& other) : arraySize(other.getSize()), capacity(other.capacity) {
    data = reallocate(nullptr, 0, other.getSize());

    for (size_t i = 0; i < arraySize; ++i) {
        data[i] = (other.data[i] != nullptr) ? other.data[i]->clone() : nullptr;
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept : arraySize(other.getSize()), capacity(other.capacity), data(other.data) {
    other.data = nullptr;
    other.capacity = 0;
    other.arraySize = 0;
}

Figure* & FigureArray::operator[](size_t index) {
    assert(index < arraySize);
    return data[index];
}

Figure* const & FigureArray::operator[] (size_t index) const {
    assert(index < arraySize);
    return data[index];
}

size_t FigureArray::getSize() const {
    return arraySize;
}

void FigureArray::pushBack(Figure* figure) {
    if (arraySize >= capacity) {
        setNewCapacity(capacity == 0 ? 1 : capacity * 2);
    }
    data[arraySize++] = figure;
}

void FigureArray::pushFront(Figure* figure) {
    if (arraySize >= capacity) {
        setNewCapacity(capacity == 0 ? 1 : capacity * 2);
    }

    for (size_t i = arraySize; i > 0; --i) {
        data[i] = data[i - 1];
    }

    data[0] = figure;
    ++arraySize;
}

void FigureArray::popBack() {
    if (arraySize == 0) return;
    delete data[arraySize - 1];
    data[arraySize - 1] = nullptr;
    --arraySize;
}

void FigureArray::popFront() {
    if (arraySize == 0) return;

    delete data[0];
    data[0] = nullptr;

    for (size_t i = 1; i < arraySize; ++i) {
        data[i - 1] = data[i];
    }

    data[arraySize - 1] = nullptr;
    --arraySize;
}

void FigureArray::popByIndex(size_t index) {
    if (index >= arraySize) return;

    delete data[index];
    data[index] = nullptr;

    for (size_t i = index + 1; i < arraySize; ++i) {
        data[i - 1] = data[i];
    }

    data[arraySize - 1] = nullptr;
    --arraySize;
}

void FigureArray::printAllCenters() const {
    std::cout << "=== ЦЕНТРЫ МАСС ВСЕХ ФИГУР ===" << std::endl;
    for (size_t i = 0; i < arraySize; ++i) {
        std::cout << "Фигура " << i << ": " << data[i]->geometricalCenter() << std::endl;
    }
    std::cout << "==============================" << std::endl;
}

void FigureArray::printAllAreas() const {
    std::cout << "=== ПЛОЩАДИ ВСЕХ ФИГУР ===" << std::endl;
    for (size_t i = 0; i < arraySize; ++i) {
        std::cout << "Фигура " << i << ": " << data[i]->area() << std::endl;
    }
    std::cout << "===========================" << std::endl;
}

double FigureArray::getTotalArea() const {
    double total = 0.0;
    for (size_t i = 0; i < arraySize; ++i) {
        total += data[i]->area();
    }
    return total;
}

void FigureArray::printAllInfo() const {
    std::cout << "=== ПОЛНАЯ ИНФОРМАЦИЯ О ВСЕХ ФИГУРАХ ===" << std::endl;
    for (size_t i = 0; i < arraySize; ++i) {
        std::cout << "--- Фигура " << i << " ---" << std::endl;
        
        if (auto* rhombus = dynamic_cast<Rhombus*>(data[i])) {
            std::cout << "Тип: Ромб" << std::endl;
            std::cout << "Вершины: " << *rhombus << std::endl;
        } else if (auto* pentagon = dynamic_cast<Pentagon*>(data[i])) {
            std::cout << "Тип: Пятиугольник" << std::endl;
            std::cout << "Вершины: " << *pentagon << std::endl;
        } else if (auto* hexagon = dynamic_cast<Hexagon*>(data[i])) {
            std::cout << "Тип: Шестиугольник" << std::endl;
            std::cout << "Вершины: " << *hexagon << std::endl;
        } else {
            std::cout << "Тип: Неизвестная фигура" << std::endl;
        }
        
        std::cout << "Центр масс: " << data[i]->geometricalCenter() << std::endl;
        std::cout << "Площадь: " << data[i]->area() << std::endl;
        std::cout << std::endl;
    }
    std::cout << "ОБЩАЯ ПЛОЩАДЬ: " << getTotalArea() << std::endl;
    std::cout << "========================================" << std::endl;
}

FigureArray::~FigureArray() noexcept {
    for (size_t i = 0; i < arraySize; ++i) {
        delete data[i];
        data[i] = nullptr;
    }

    delete[] data;
    data = nullptr;
    arraySize = 0;
    capacity = 0;
}