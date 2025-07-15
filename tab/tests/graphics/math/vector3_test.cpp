#include <gtest/gtest.h>
import vector3;

TEST(Vector3Test, defaultConstructor) {
    const Vector3 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);
}

TEST(Vector3Test, initialization) {
    const Vector3 v(1, 2, 3);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 3);
}

TEST(Vector3Test, sum) {
    const Vector3 v1(1, 1, 1), v2(2, 2, 2);
    const Vector3 v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 3);
    EXPECT_EQ(v3.z, 3);
}

TEST(Vector3Test, sub) {
    const Vector3 v1(1, 1, 1), v2(2, 2, 2);
    const Vector3 v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, -1);
    EXPECT_EQ(v3.z, -1);
}

TEST(Vector3Test, mul) {
    const Vector3 v1(2, 3, 5), v2(2, 2, 2);
    const Vector3 v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4);
    EXPECT_EQ(v3.y, 6);
    EXPECT_EQ(v3.z, 10);
}

TEST(Vector3Test, div) {
    const Vector3 v1(4, 4, 4);
    const Vector3 v2(2, 2, 2);
    const Vector3 v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2);
    EXPECT_EQ(v3.y, 2);
    EXPECT_EQ(v3.z, 2);
}

TEST(Vector3Test, neg) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2 = -v1;
    EXPECT_EQ(v2.x, -1);
    EXPECT_EQ(v2.y, -1);
    EXPECT_EQ(v2.z, -1);
}

TEST(Vector3Test, mulSca) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2 = v1 * 2;
    EXPECT_EQ(v2.x, 2);
    EXPECT_EQ(v2.y, 2);
    EXPECT_EQ(v2.z, 2);
}

TEST(Vector3Test, divSca) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2 = v1 / 2;
    EXPECT_EQ(v2.x, 0.5);
    EXPECT_EQ(v2.y, 0.5);
    EXPECT_EQ(v2.z, 0.5);
}

TEST(Vector3Test, eq) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2(1, 1, 1);
    const Vector3 v3(1, 2, 2);
    const Vector3 v4(2, 1, 2);
    const Vector3 v5(2, 2, 1);

    EXPECT_EQ(v1 == v2, true);
    EXPECT_EQ(v1 == v3, false);
    EXPECT_EQ(v1 == v4, false);
    EXPECT_EQ(v1 == v5, false);
}

TEST(Vector3Test, nEq) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2(1, 1, 1);
    const Vector3 v3(1, 2, 2);
    const Vector3 v4(2, 1, 2);
    const Vector3 v5(2, 2, 1);

    EXPECT_EQ(v1 != v2, false);
    EXPECT_EQ(v1 != v3, true);
    EXPECT_EQ(v1 != v4, true);
    EXPECT_EQ(v1 != v5, true);
}

TEST(Vector3Test, len) {
    const Vector3 v1(2, 3, 6);

    EXPECT_EQ(v1.length(), 7);
}

TEST(Vector3Test, norm) {
    const Vector3 v1(0, 4, 0);
    const Vector3 v2(0, 1, 0);
    const Vector3 v3(2, 3, 6);

    EXPECT_EQ(v1.normalize(), v2);
    EXPECT_EQ(v2.normalize(), v2);
    EXPECT_NEAR(v3.normalize().length(), 1, 0.001);
}

TEST(Vector3Test, dot) {
    const Vector3 v1(0, 0, 1);
    const Vector3 v2(0, 1, 0);
    const Vector3 v3(1, 0, 0);
    const Vector3 v4(2, 3, 5);
    const Vector3 v5(7, 5, 3);

    EXPECT_EQ(v1.dot(v2), 0);
    EXPECT_EQ(v1.dot(v3), 0);
    EXPECT_EQ(v2.dot(v3), 0);
    EXPECT_EQ(v4.dot(v5), 44);
}

TEST(Vector3Test, cross) {
    const Vector3 v1(0, 0, 1);
    const Vector3 v2(0, 1, 0);
    const Vector3 v3(1, 0, 0);
    const Vector3 v4(1, 2, 3);
    const Vector3 v5(0, 3, -2);

    EXPECT_EQ(v1.cross(v2), -v3);
    EXPECT_EQ(v4.cross(v3), v5);
}