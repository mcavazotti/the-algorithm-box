//
// Created by mcavazotti on 6/20/25.
//

export module vector;
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

export class Vector3 {
public:
    Vector3(): x(0),y(0),z(0) {}
    Vector3(const double x, const double y, const double z): x(x),y(y),z(z) {}

    Vector3 operator+(const Vector3& other) const { return { x + other.x, y + other.y, z + other.z }; }
    Vector3 operator-(const Vector3& other) const { return { x - other.x, y - other.y, z - other.z }; }
    Vector3 operator*(const Vector3& other) const { return { x * other.x, y * other.y, z * other.z }; }
    Vector3 operator/(const Vector3& other) const { return { x / other.x, y / other.y, z / other.z }; }
    Vector3 operator-() const { return { -x, -y, -z }; }
    Vector3 operator*(const double other) const { return { x * other, y * other, z * other }; }
    Vector3 operator/(const double other) const { return { x / other, y / other, z / other }; }
    bool operator==(const Vector3& other) const { return x == other.x && y == other.y && z == other.z; }
    bool operator!=(const Vector3& other) const { return !(*this == other); }

    [[nodiscard]] double length() const { return sqrt(x * x + y * y + z * z); };
    [[nodiscard]] Vector3 normalize() const { return *this / length(); };
    [[nodiscard]] double dot(const Vector3& other) const { return x * other.x + y * other.y + z * other.z; }
    
    // start-cross
    [[nodiscard]] Vector3 cross(const Vector3& other) const { return {y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x }; }
    // end-cross

    double x, y, z;
};

export class Vector4 {
public:
    Vector4() : x(0), y(0), z(0), w(0) {}
    Vector4(const double x, const double y, const double z, const double w) : x(x), y(y), z(z), w(w) {}

    Vector4 operator+(const Vector4& other) const { return { x + other.x, y + other.y, z + other.z, w + other.w }; }
    Vector4 operator-(const Vector4& other) const { return { x - other.x, y - other.y, z - other.z, w - other.w }; }
    Vector4 operator*(const Vector4& other) const { return { x * other.x, y * other.y, z * other.z, w * other.w }; }
    Vector4 operator/(const Vector4& other) const { return { x / other.x, y / other.y, z / other.z, w / other.w }; }
    Vector4 operator-() const { return { -x, -y, -z, -w }; }
    Vector4 operator*(const double other) const { return { x * other, y * other, z * other, w * other }; }
    Vector4 operator/(const double other) const { return { x / other, y / other, z / other, w / other }; }
    bool operator==(const Vector4& other) const { return x == other.x && y == other.y && z == other.z && w == other.w; }
    bool operator!=(const Vector4& other) const { return !(*this == other); }

    [[nodiscard]] double length() const { return sqrt(x * x + y * y + z * z + w * w); };
    [[nodiscard]] Vector4 normalize() const { return *this / length(); };
    [[nodiscard]] double dot(const Vector4& other) const { return x * other.x + y * other.y + z * other.z + w * other.w; }

    double x, y, z, w;
};