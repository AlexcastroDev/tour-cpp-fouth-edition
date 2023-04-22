// Square.cpp
#include "square.h"

Square::Square(double value)  {
    square = value;
}

int Square::getArea() {
    return square * square;
}