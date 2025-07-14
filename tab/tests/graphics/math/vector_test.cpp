//
// Created by mcavazotti on 7/5/25.
//

#include <gtest/gtest.h>
import vector;


TEST(VectorTest, v2DefaultConstructor) {
    const Vector2 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
}

TEST(VectorTest, v2Initialization) {
    const Vector2 v(1,2);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
}

TEST(VectorTest, v2Sum) {
    const Vector2 v1(1,1), v2(2,2);
    const Vector2 v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 3);
}

TEST(VectorTest, v2Sub) {
    const Vector2 v1(1,1), v2(2,2);
    const Vector2 v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, -1);
}

TEST(VectorTest, v2Mul) {
    const Vector2 v1(2,3), v2(2,2);
    const Vector2 v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4);
    EXPECT_EQ(v3.y, 6);
}

TEST(VectorTest, v2Div) {
    const Vector2 v1(4,4);
    const Vector2 v2(2,2);
    const Vector2 v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2);
    EXPECT_EQ(v3.y, 2);
}

TEST(VectorTest, v2Neg) {
    const Vector2 v1(1,1);
    const Vector2 v2 = -v1;
    EXPECT_EQ(v2.x, -1);
    EXPECT_EQ(v2.y, -1);
}

TEST(VectorTest, v2MulSca) {
    const Vector2 v1(1,1);
    const Vector2 v2 = v1 * 2;
    EXPECT_EQ(v2.x, 2);
    EXPECT_EQ(v2.y, 2);
}

TEST(VectorTest, v2DivSca) {
    const Vector2 v1(1,1);
    const Vector2 v2 = v1 / 2;
    EXPECT_EQ(v2.x, 0.5);
    EXPECT_EQ(v2.y, 0.5);
}

TEST(VectorTest, v2Eq) {
    const Vector2 v1(1,1);
    const Vector2 v2(1,1);
    const Vector2 v3(1,2);
    const Vector2 v4(2,1);
    const Vector2 v5(2,2);

    EXPECT_EQ(v1 == v2, true);
    EXPECT_EQ(v1 == v3, false);
    EXPECT_EQ(v1 == v4, false);
    EXPECT_EQ(v1 == v5, false);
}

TEST(VectorTest, v2NEq) {
    const Vector2 v1(1,1);
    const Vector2 v2(1,1);
    const Vector2 v3(1,2);
    const Vector2 v4(2,1);
    const Vector2 v5(2,2);

    EXPECT_EQ(v1 != v2, false);
    EXPECT_EQ(v1 != v3, true);
    EXPECT_EQ(v1 != v4, true);
    EXPECT_EQ(v1 != v5, true);
}

TEST(VectorTest, v2Len) {
    const Vector2 v1(3,4);

    EXPECT_EQ(v1.length(), 5);
}

TEST(VectorTest, v2Norm) {
    const Vector2 v1(0,4);
    const Vector2 v2(0,1);
    const Vector2 v3(3,4);

    EXPECT_EQ(v1.normalize(), v2);
    EXPECT_EQ(v2.normalize(), v2);
    EXPECT_EQ(v3.normalize().length(), 1);
}

TEST(VectorTest, v2Dot) {
    const Vector2 v1(0, 1);
    const Vector2 v2(1, 0);
    const Vector2 v3(2, 3);
    const Vector2 v4(3, 5);

    EXPECT_EQ(v1.dot(v2), 0);
    EXPECT_EQ(v1.dot(v3), 3);
    EXPECT_EQ(v2.dot(v3), 2);
    EXPECT_EQ(v3.dot(v4), 21);
}

TEST(VectorTest, v3DefaultConstructor) {
    const Vector3 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);
}

TEST(VectorTest, v3Initialization) {
    const Vector3 v(1, 2, 3);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 3);
}

TEST(VectorTest, v3Sum) {
    const Vector3 v1(1, 1, 1), v2(2, 2, 2);
    const Vector3 v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 3);
    EXPECT_EQ(v3.z, 3);
}

TEST(VectorTest, v3Sub) {
    const Vector3 v1(1, 1, 1), v2(2, 2, 2);
    const Vector3 v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, -1);
    EXPECT_EQ(v3.z, -1);
}

TEST(VectorTest, v3Mul) {
    const Vector3 v1(2, 3, 5), v2(2, 2, 2);
    const Vector3 v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4);
    EXPECT_EQ(v3.y, 6);
    EXPECT_EQ(v3.z, 10);
}

TEST(VectorTest, v3Div) {
    const Vector3 v1(4, 4, 4);
    const Vector3 v2(2, 2, 2);
    const Vector3 v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2);
    EXPECT_EQ(v3.y, 2);
    EXPECT_EQ(v3.z, 2);
}

TEST(VectorTest, v3Neg) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2 = -v1;
    EXPECT_EQ(v2.x, -1);
    EXPECT_EQ(v2.y, -1);
    EXPECT_EQ(v2.z, -1);
}

TEST(VectorTest, v3MulSca) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2 = v1 * 2;
    EXPECT_EQ(v2.x, 2);
    EXPECT_EQ(v2.y, 2);
    EXPECT_EQ(v2.z, 2);
}

TEST(VectorTest, v3DivSca) {
    const Vector3 v1(1, 1, 1);
    const Vector3 v2 = v1 / 2;
    EXPECT_EQ(v2.x, 0.5);
    EXPECT_EQ(v2.y, 0.5);
    EXPECT_EQ(v2.z, 0.5);
}

TEST(VectorTest, v3Eq) {
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

TEST(VectorTest, v3NEq) {
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

TEST(VectorTest, v3Len) {
    const Vector3 v1(2, 3, 6);

    EXPECT_EQ(v1.length(), 7);
}

TEST(VectorTest, v3Norm) {
    const Vector3 v1(0, 4, 0);
    const Vector3 v2(0, 1, 0);
    const Vector3 v3(2, 3, 6);

    EXPECT_EQ(v1.normalize(), v2);
    EXPECT_EQ(v2.normalize(), v2);
    EXPECT_NEAR(v3.normalize().length(), 1, 0.001);
}

TEST(VectorTest, v3Dot) {
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

TEST(VectorTest, v3Cross) {
    const Vector3 v1(0, 0, 1);
    const Vector3 v2(0, 1, 0);
    const Vector3 v3(1, 0, 0);
    const Vector3 v4(1, 2, 3);
    const Vector3 v5(0, 3, -2);

    EXPECT_EQ(v1.cross(v2), -v3);
    EXPECT_EQ(v4.cross(v3), v5);
}

TEST(VectorTest, v4DefaultConstructor) {
    const Vector4 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
    EXPECT_EQ(v.z, 0);
    EXPECT_EQ(v.w, 0);
}

TEST(VectorTest, v4Initialization) {
    const Vector4 v(1, 2, 3, 4);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
    EXPECT_EQ(v.z, 3);
    EXPECT_EQ(v.w, 4);
}

TEST(VectorTest, v4Sum) {
    const Vector4 v1(1, 1, 1, 1), v2(2, 2, 2, 2);
    const Vector4 v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 3);
    EXPECT_EQ(v3.z, 3);
    EXPECT_EQ(v3.w, 3);
}

TEST(VectorTest, v4Sub) {
    const Vector4 v1(1, 1, 1, 1), v2(2, 2, 2, 2);
    const Vector4 v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, -1);
    EXPECT_EQ(v3.z, -1);
    EXPECT_EQ(v3.w, -1);
}

TEST(VectorTest, v4Mul) {
    const Vector4 v1(2, 3, 5, 7), v2(2, 2, 2, 2);
    const Vector4 v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4);
    EXPECT_EQ(v3.y, 6);
    EXPECT_EQ(v3.z, 10);
    EXPECT_EQ(v3.w, 14);
}

TEST(VectorTest, v4Div) {
    const Vector4 v1(4, 4, 4, 4);
    const Vector4 v2(2, 2, 2, 2);
    const Vector4 v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2);
    EXPECT_EQ(v3.y, 2);
    EXPECT_EQ(v3.z, 2);
    EXPECT_EQ(v3.w, 2);
}

TEST(VectorTest, v4Neg) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2 = -v1;
    EXPECT_EQ(v2.x, -1);
    EXPECT_EQ(v2.y, -1);
    EXPECT_EQ(v2.z, -1);
    EXPECT_EQ(v2.w, -1);
}

TEST(VectorTest, v4MulSca) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2 = v1 * 2;
    EXPECT_EQ(v2.x, 2);
    EXPECT_EQ(v2.y, 2);
    EXPECT_EQ(v2.z, 2);
    EXPECT_EQ(v2.w, 2);
}

TEST(VectorTest, v4DivSca) {
    const Vector4 v1(1, 1, 1, 1);
    const Vector4 v2 = v1 / 2;
    EXPECT_EQ(v2.x, 0.5);
    EXPECT_EQ(v2.y, 0.5);
    EXPECT_EQ(v2.z, 0.5);
    EXPECT_EQ(v2.w, 0.5);
}

TEST(VectorTest, v4Eq) {
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

TEST(VectorTest, v4NEq) {
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

TEST(VectorTest, v4Len) {
    const Vector4 v1(4, 4, 4, 4);

    EXPECT_EQ(v1.length(), 8);
}

TEST(VectorTest, v4Norm) {
    const Vector4 v1(0, 4, 0, 0);
    const Vector4 v2(0, 1, 0, 0);
    const Vector4 v3(4, 4, 4, 4);

    EXPECT_EQ(v1.normalize(), v2);
    EXPECT_EQ(v2.normalize(), v2);
    EXPECT_NEAR(v3.normalize().length(), 1, 0.001);
}

TEST(VectorTest, v4Dot) {
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