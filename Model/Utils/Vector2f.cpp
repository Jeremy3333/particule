//
// Created by tally on 17/03/24.
//

#include "Vector2f.h"

Vector2f::Vector2f(): x(0), y(0) {}

Vector2f::Vector2f(const float x, const float y): x(x), y(y) {}

Vector2f Vector2f::operator+=(const Vector2f &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2f Vector2f::operator*(const int x) const {
    return {this->x * static_cast<float>(x), this->y * static_cast<float>(x)};
}

Vector2f Vector2f::operator*(float x) const {
    return {this->x * x, this->y * x};
}
