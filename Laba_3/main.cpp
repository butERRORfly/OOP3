#include <iostream>
#include "include/FigureArray.h"
#include "include/Rhombus.h"
#include "include/Pentagon.h"
#include "include/Hexagon.h"

int main() {
    try {
        FigureArray figures;
        
        std::cout << "=== Демонстрация работы с FigureArray ===\n" << std::endl;

        std::cout << "1. РОМБ:" << std::endl;
        Points r1(0, 0), r2(2, 2), r3(4, 0);
        Rhombus* rhombus = new Rhombus(r1, r2, r3);
        
        figures.pushBack(rhombus);
        std::cout << "Добавлен ромб: " << *rhombus << std::endl;
        std::cout << "Площадь: " << rhombus->area() << std::endl;
        std::cout << "Центр: " << rhombus->geometricalCenter() << std::endl;
        std::cout << "Размер массива: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "2. ПЯТИУГОЛЬНИК:" << std::endl;
        Points p1(0, 0), p2(2, 0), p3(2.5, 1), p4(1, 2), p5(-0.5, 1);
        Pentagon* pentagon = new Pentagon(p1, p2, p3, p4, p5);
        
        figures.pushBack(pentagon);
        std::cout << "Добавлен пятиугольник: " << *pentagon << std::endl;
        std::cout << "Площадь: " << pentagon->area() << std::endl;
        std::cout << "Центр: " << pentagon->geometricalCenter() << std::endl;
        std::cout << "Размер массива: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "3. ШЕСТИУГОЛЬНИК:" << std::endl;
        Points h1(2, 0), h2(1, 1), h3(0, 1), 
               h4(-1, 0), h5(0, -1), h6(1, -1);
        Hexagon* hexagon = new Hexagon(h1, h2, h3, h4, h5, h6);
        
        figures.pushBack(hexagon);
        std::cout << "Добавлен шестиугольник: " << *hexagon << std::endl;
        std::cout << "Площадь: " << hexagon->area() << std::endl;
        std::cout << "Центр: " << hexagon->geometricalCenter() << std::endl;
        std::cout << "Размер массива: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "4. ДЕМОНСТРАЦИЯ PUSHFRONT:" << std::endl;
        Points r4(1, 0), r5(3, 2), r6(5, 0);
        Rhombus* rhombus2 = new Rhombus(r4, r5, r6);
        figures.pushFront(rhombus2);
        std::cout << "Добавлен ромб в начало: " << *rhombus2 << std::endl;
        std::cout << "Размер массива: " << figures.getSize() << std::endl;
        
        std::cout << "Все фигуры в массиве:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << i << ": ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figures[i])) {
                std::cout << *pentagon_ptr;
            } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figures[i])) {
                std::cout << *hexagon_ptr;
            } else {
                std::cout << "Unknown figure type";
            }
            std::cout << " [Area: " << figures[i]->area() << "]" << std::endl;
        }
        std::cout << std::endl;

        std::cout << "5. ДОСТУП ПО ИНДЕКСУ:" << std::endl;
        std::cout << "Фигура с индексом 1: ";
        if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figures[1])) {
            std::cout << *pentagon_ptr;
        } else if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[1])) {
            std::cout << *rhombus_ptr;
        } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figures[1])) {
            std::cout << *hexagon_ptr;
        }
        std::cout << std::endl;
        
        std::cout << "Площадь фигуры с индексом 2: " << figures[2]->area() << std::endl;
        std::cout << std::endl;

        std::cout << "6. УДАЛЕНИЕ С КОНЦА (popBack):" << std::endl;
        std::cout << "Размер до удаления: " << figures.getSize() << std::endl;
        figures.popBack();
        std::cout << "Размер после удаления: " << figures.getSize() << std::endl;
        std::cout << "Оставшиеся фигуры:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << i << ": ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figures[i])) {
                std::cout << *pentagon_ptr;
            } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figures[i])) {
                std::cout << *hexagon_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "7. УДАЛЕНИЕ С НАЧАЛА (popFront):" << std::endl;
        std::cout << "Размер до удаления: " << figures.getSize() << std::endl;
        figures.popFront();
        std::cout << "Размер после удаления: " << figures.getSize() << std::endl;
        std::cout << "Оставшиеся фигуры:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << i << ": ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figures[i])) {
                std::cout << *pentagon_ptr;
            } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figures[i])) {
                std::cout << *hexagon_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "8. ДОБАВЛЕНИЕ ФИГУР ДЛЯ ДЕМОНСТРАЦИИ:" << std::endl;
        Points p6(1, 1), p7(3, 1), p8(3.5, 2), p9(2, 3), p10(0.5, 2);
        Pentagon* pentagon2 = new Pentagon(p6, p7, p8, p9, p10);
        figures.pushBack(pentagon2);
        
        Points h7(3, 0), h8(2, 1), h9(1, 1), 
               h10(0, 0), h11(1, -1), h12(2, -1);
        Hexagon* hexagon2 = new Hexagon(h7, h8, h9, h10, h11, h12);
        figures.pushBack(hexagon2);
        
        std::cout << "Добавлены 2 фигуры, размер массива: " << figures.getSize() << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << i << ": ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figures[i])) {
                std::cout << *pentagon_ptr;
            } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figures[i])) {
                std::cout << *hexagon_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "9. УДАЛЕНИЕ ПО ИНДЕКСУ (popByIndex 1):" << std::endl;
        figures.popByIndex(1);
        std::cout << "Размер после удаления: " << figures.getSize() << std::endl;
        std::cout << "Оставшиеся фигуры:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            std::cout << i << ": ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figures[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figures[i])) {
                std::cout << *pentagon_ptr;
            } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figures[i])) {
                std::cout << *hexagon_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "10. ПРИВЕДЕНИЕ К DOUBLE:" << std::endl;
        for (size_t i = 0; i < figures.getSize(); ++i) {
            double area = static_cast<double>(*figures[i]);
            std::cout << "Фигура " << i << " площадь (через operator double): " << area << std::endl;
        }
        std::cout << std::endl;

        std::cout << "11. СРАВНЕНИЕ ФИГУР:" << std::endl;
        if (figures.getSize() >= 2) {
            bool areEqual = (*figures[0] == *figures[1]);
            std::cout << "Фигура 0 == Фигура 1: " << (areEqual ? "true" : "false") << std::endl;
        }
        std::cout << std::endl;

        std::cout << "12. КОНСТРУКТОР КОПИРОВАНИЯ:" << std::endl;
        FigureArray figuresCopy(figures);
        std::cout << "Размер оригинала: " << figures.getSize() << std::endl;
        std::cout << "Размер копии: " << figuresCopy.getSize() << std::endl;
        std::cout << "Фигуры в копии:" << std::endl;
        for (size_t i = 0; i < figuresCopy.getSize(); ++i) {
            std::cout << i << ": ";
            if (auto* rhombus_ptr = dynamic_cast<Rhombus*>(figuresCopy[i])) {
                std::cout << *rhombus_ptr;
            } else if (auto* pentagon_ptr = dynamic_cast<Pentagon*>(figuresCopy[i])) {
                std::cout << *pentagon_ptr;
            } else if (auto* hexagon_ptr = dynamic_cast<Hexagon*>(figuresCopy[i])) {
                std::cout << *hexagon_ptr;
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "13. РАБОТА С ПУСТЫМ МАССИВОМ:" << std::endl;
        FigureArray emptyArray;
        std::cout << "Размер пустого массива: " << emptyArray.getSize() << std::endl;
        
        emptyArray.popBack();
        emptyArray.popFront();
        emptyArray.popByIndex(0);
        std::cout << "После попыток удаления из пустого массива, размер: " << emptyArray.getSize() << std::endl;

        std::cout << "1. ВСЕ ЦЕНТРЫ МАСС:" << std::endl;
        figures.printAllCenters();
        std::cout << std::endl;

        std::cout << "2. ВСЕ ПЛОЩАДИ:" << std::endl;
        figures.printAllAreas();
        std::cout << std::endl;

        std::cout << "3. ОБЩАЯ ПЛОЩАДЬ:" << std::endl;
        std::cout << "Общая площадь всех фигур: " << figures.getTotalArea() << std::endl;
        std::cout << std::endl;

        std::cout << "6. ПОСЛЕ УДАЛЕНИЯ ФИГУРЫ:" << std::endl;
        figures.popBack();
        std::cout << "Удалена последняя фигура. Обновленная информация:" << std::endl;
        figures.printAllInfo();
        std::cout << std::endl;

        std::cout << "7. ВЫЧИСЛЕНИЯ:" << std::endl;
        double totalArea = figures.getTotalArea();
        double averageArea = totalArea / figures.getSize();
        
        std::cout << "Общая площадь: " << totalArea << std::endl;
        std::cout << "Средняя площадь: " << averageArea << std::endl;
        std::cout << "Количество фигур: " << figures.getSize() << std::endl;
        std::cout << std::endl;

        std::cout << "=== ВСЕ ОПЕРАЦИИ УСПЕШНО ЗАВЕРШЕНЫ ===" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}