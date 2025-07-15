export module vector3;
#include <cmath>

export class Vector3 {
public:
    Vector3() : x(0), y(0), z(0) {}
    Vector3(const double x, const double y, const double z) : x(x), y(y), z(z) {}

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
    [[nodiscard]] Vector3 cross(const Vector3& other) const { return { y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x }; }
    // end-cross

    double x, y, z;
};