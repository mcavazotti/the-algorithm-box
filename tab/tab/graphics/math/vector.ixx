//
// Created by mcavazotti on 6/20/25.
//

export module vector;

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
    // end-basic-ops

    double x, y;
};