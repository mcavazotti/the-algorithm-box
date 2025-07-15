#include <cmath>
export module vector4;

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