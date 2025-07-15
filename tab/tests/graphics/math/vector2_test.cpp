#include <gtest/gtest.h>
import vector2;


TEST(Vector2Test, defaultConstructor) {
    const Vector2 v;
    EXPECT_EQ(v.x, 0);
    EXPECT_EQ(v.y, 0);
}

TEST(Vector2Test, initialization) {
    const Vector2 v(1,2);
    EXPECT_EQ(v.x, 1);
    EXPECT_EQ(v.y, 2);
}

TEST(Vector2Test, sum) {
    const Vector2 v1(1,1), v2(2,2);
    const Vector2 v3 = v1 + v2;
    EXPECT_EQ(v3.x, 3);
    EXPECT_EQ(v3.y, 3);
}

TEST(Vector2Test, sub) {
    const Vector2 v1(1,1), v2(2,2);
    const Vector2 v3 = v1 - v2;
    EXPECT_EQ(v3.x, -1);
    EXPECT_EQ(v3.y, -1);
}

TEST(Vector2Test, mul) {
    const Vector2 v1(2,3), v2(2,2);
    const Vector2 v3 = v1 * v2;
    EXPECT_EQ(v3.x, 4);
    EXPECT_EQ(v3.y, 6);
}

TEST(Vector2Test, div) {
    const Vector2 v1(4,4);
    const Vector2 v2(2,2);
    const Vector2 v3 = v1 / v2;
    EXPECT_EQ(v3.x, 2);
    EXPECT_EQ(v3.y, 2);
}

TEST(Vector2Test, neg) {
    const Vector2 v1(1,1);
    const Vector2 v2 = -v1;
    EXPECT_EQ(v2.x, -1);
    EXPECT_EQ(v2.y, -1);
}

TEST(Vector2Test, mulSca) {
    const Vector2 v1(1,1);
    const Vector2 v2 = v1 * 2;
    EXPECT_EQ(v2.x, 2);
    EXPECT_EQ(v2.y, 2);
}

TEST(Vector2Test, divSca) {
    const Vector2 v1(1,1);
    const Vector2 v2 = v1 / 2;
    EXPECT_EQ(v2.x, 0.5);
    EXPECT_EQ(v2.y, 0.5);
}

TEST(Vector2Test, eq) {
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

TEST(Vector2Test, nEq) {
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

TEST(Vector2Test, len) {
    const Vector2 v1(3,4);

    EXPECT_EQ(v1.length(), 5);
}

TEST(Vector2Test, norm) {
    const Vector2 v1(0,4);
    const Vector2 v2(0,1);
    const Vector2 v3(3,4);

    EXPECT_EQ(v1.normalize(), v2);
    EXPECT_EQ(v2.normalize(), v2);
    EXPECT_EQ(v3.normalize().length(), 1);
}

TEST(Vector2Test, dot) {
    const Vector2 v1(0, 1);
    const Vector2 v2(1, 0);
    const Vector2 v3(2, 3);
    const Vector2 v4(3, 5);

    EXPECT_EQ(v1.dot(v2), 0);
    EXPECT_EQ(v1.dot(v3), 3);
    EXPECT_EQ(v2.dot(v3), 2);
    EXPECT_EQ(v3.dot(v4), 21);
}