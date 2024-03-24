//
// Created by tally on 17/03/24.
//

#ifndef VECTOR2F_H
#define VECTOR2F_H



class Vector2f {
public:
    Vector2f();
    Vector2f(float x, float y);
    float x;
    float y;

    [[nodiscard]] float length() const;

    Vector2f operator+=(const Vector2f &rhs);
    Vector2f operator+(const Vector2f &rhs) const;
    Vector2f operator-(const Vector2f &rhs) const;
    Vector2f operator*(int x) const;
    Vector2f operator*(float x) const;
};



#endif //VECTOR2F_H
