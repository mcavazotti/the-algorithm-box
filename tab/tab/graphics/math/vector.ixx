//
// Created by mcavazotti on 6/20/25.
//

export module vector;
#include <cmath>

export class Vector2
{
    public:
    // start-constructors
    Vector2(): x(0), y(0) {};
    Vector2(const double x, const double y): x(x), y(y) {};
    // end-constructors

    // start-basic-ops
    Vector2 operator+(const Vector2 &other) const {return Vector2(x + other.x, y + other.y);}
    Vector2 operator-(const Vector2 &other) const {return Vector2(x - other.x, y - other.y);}
    Vector2 operator*(const Vector2 &other) const {return Vector2(x * other.x, y * other.y);}
    Vector2 operator/(const Vector2 &other) const {return Vector2(x / other.x, y / other.y);}
    Vector2 operator-() const {return Vector2(-x, -y);};
    // end-basic-ops

    // start-scalar-ops
    Vector2 operator*(const double other) const {return Vector2(x * other, y * other);}
    Vector2 operator/(const double other) const {return Vector2(x / other, y / other);}
    //end-scalar-ops

    // start-length-ops
    double length() const {return sqrt(x * x + y * y);};
    Vector2 normalize() const {return *this / length();};
    // end-length-ops


    double x, y;
};
