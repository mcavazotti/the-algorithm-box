//
// Created by mcavazotti on 6/20/25.
//

export module vector2;
#include <cmath>

export class Vector2
{
public:
    // start-constructors
    Vector2(): x(0), y(0){};
    Vector2(const double x, const double y): x(x), y(y) {};
    // end-constructors

    // start-basic-ops
    Vector2 operator+(const Vector2& other) const { return {x + other.x, y + other.y}; }
    Vector2 operator-(const Vector2& other) const { return {x - other.x, y - other.y}; }
    Vector2 operator*(const Vector2& other) const { return {x * other.x, y * other.y}; }
    Vector2 operator/(const Vector2& other) const { return {x / other.x, y / other.y}; }
    Vector2 operator-() const { return {-x, -y}; }
    // end-basic-ops

    // start-scalar-ops
    Vector2 operator*(const double other) const { return {x * other, y * other}; }
    Vector2 operator/(const double other) const { return {x / other, y / other}; }
    // end-scalar-ops

    // start-equality
    bool operator==(const Vector2& other) const {return x == other.x && y == other.y;}
    bool operator!=(const Vector2& other) const {return !(*this == other);}
    // end-equality

    // start-length-ops
    [[nodiscard]] double length() const { return sqrt(x * x + y * y); };
    [[nodiscard]] Vector2 normalize() const { return *this / length(); };
    // end-length-ops

    // start-dot
    [[nodiscard]] double dot(const Vector2& other) const { return x * other.x + y * other.y; }
    // end-dot

    double x, y;
};