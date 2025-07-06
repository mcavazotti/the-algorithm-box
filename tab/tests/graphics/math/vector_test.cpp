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