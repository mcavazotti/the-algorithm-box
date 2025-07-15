#include <gtest/gtest.h>
import vector4;

TEST(Vector4Test, defaultConstructor) {
    const Vector4 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);
    EXPECT_EQ(v.w, 0);
}

TEST(Vector4Test, initialization) {
    const Vector4 v(1, 2, 3, 4);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 3);
    EXPECT_EQ(v.w, 4);
}

TEST(Vector4Test, sum) {
    const Vector4 v1(1, 1, 1, 1), v2(2, 2, 2, 2);
    const Vector4 v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 3);
    EXPECT_EQ(v3.z, 3);
    EXPECT_EQ(v3.w, 3);
}

TEST(Vector4Test, sub) {
    const Vector4 v1(1, 1, 1, 1), v2(2, 2, 2, 2);
    const Vector4 v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, -1);
    EXPECT_EQ(v3.z, -1);
    EXPECT_EQ(v3.w, -1);
}

TEST(Vector4Test, mul) {
    const Vector4 v1(2, 3, 5, 7), v2(2, 2, 2, 2);
    const Vector4 v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4);
    EXPECT_EQ(v3.y, 6);
    EXPECT_EQ(v3.z, 10);
    EXPECT_EQ(v3.w, 14);
}

TEST(Vector4Test, div) {
    const Vector4 v1(4, 4, 4, 4);
    const Vector4 v2(2, 2, 2, 2);
    const Vector4 v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2);
    EXPECT_EQ(v3.y, 2);
    EXPECT_EQ(v3.z, 2);
    EXPECT_EQ(v3.w, 2);
}

TEST(Vector4Test, neg) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2 = -v1;
    EXPECT_EQ(v2.x, -1);
    EXPECT_EQ(v2.y, -1);
    EXPECT_EQ(v2.z, -1);
    EXPECT_EQ(v2.w, -1);
}

TEST(Vector4Test, mulSca) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2 = v1 * 2;
    EXPECT_EQ(v2.x, 2);
    EXPECT_EQ(v2.y, 2);
    EXPECT_EQ(v2.z, 2);
    EXPECT_EQ(v2.w, 2);
}

TEST(Vector4Test, divSca) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2 = v1 / 2;
    EXPECT_EQ(v2.x, 0.5);
    EXPECT_EQ(v2.y, 0.5);
    EXPECT_EQ(v2.z, 0.5);
    EXPECT_EQ(v2.w, 0.5);
}

TEST(Vector4Test, eq) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2(1, 1, 1, 1);
    const Vector4 v3(1, 2, 2, 2);
    const Vector4 v4(2, 1, 2, 2);
    const Vector4 v5(2, 2, 1, 2);
    const Vector4 v6(2, 2, 2, 1);

    EXPECT_EQ(v1 == v2, true);
    EXPECT_EQ(v1 == v3, false);
    EXPECT_EQ(v1 == v4, false);
    EXPECT_EQ(v1 == v5, false);
    EXPECT_EQ(v1 == v6, false);
}

TEST(Vector4Test, nEq) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2(1, 1, 1, 1);
    const Vector4 v3(1, 2, 2, 2);
    const Vector4 v4(2, 1, 2, 2);
    const Vector4 v5(2, 2, 1, 2);
    const Vector4 v6(2, 2, 2, 1);

    EXPECT_EQ(v1 != v2, false);
    EXPECT_EQ(v1 != v3, true);
    EXPECT_EQ(v1 != v4, true);
    EXPECT_EQ(v1 != v5, true);
    EXPECT_EQ(v1 != v6, true);
}

TEST(Vector4Test, v4Len) {
    const Vector4 v1(4, 4, 4, 4);

    EXPECT_EQ(v1.length(), 8);
}

TEST(Vector4Test, norm) {
    const Vector4 v1(0, 4, 0, 0);
    const Vector4 v2(0, 1, 0, 0);
    const Vector4 v3(4, 4, 4, 4);

    EXPECT_EQ(v1.normalize(), v2);
    EXPECT_EQ(v2.normalize(), v2);
    EXPECT_NEAR(v3.normalize().length(), 1, 0.001);
}

TEST(Vector4Test, dot) {
    const Vector4 v1(0, 0, 0, 1);
    const Vector4 v2(0, 0, 1, 0);
    const Vector4 v3(0, 1, 0, 0);
    const Vector4 v4(1, 0, 0, 0);
    const Vector4 v5(2, 3, 5, 7);
    const Vector4 v6(7, 5, 3, 2);

    EXPECT_EQ(v1.dot(v2), 0);
    EXPECT_EQ(v1.dot(v3), 0);
    EXPECT_EQ(v1.dot(v4), 0);
    EXPECT_EQ(v2.dot(v3), 0);
    EXPECT_EQ(v2.dot(v4), 0);
    EXPECT_EQ(v3.dot(v4), 0);
    EXPECT_EQ(v5.dot(v6), 58);
}