#include <gtest/gtest.h>
#include <stdexcept>
import matrix2;
import vector2;

TEST(Mat2Test, defaultConstructor) {
    const Matrix2 m;
    EXPECT_EQ(m(0,0), 0);
    EXPECT_EQ(m(0,1), 0);
    EXPECT_EQ(m(1,0), 0);
    EXPECT_EQ(m(1,1), 0);
}

TEST(Mat2Test, initialization1) {
    const Matrix2 m( 1,2,
                     3,4);

    EXPECT_EQ(m(0,0), 1);
    EXPECT_EQ(m(0,1), 2);
    EXPECT_EQ(m(1,0), 3);
    EXPECT_EQ(m(1,1), 4);
}

TEST(Mat2Test, initialization2) {
    const Matrix2 m({1,2,
                     3,4});

    EXPECT_EQ(m(0,0), 1);
    EXPECT_EQ(m(0,1), 2);
    EXPECT_EQ(m(1,0), 3);
    EXPECT_EQ(m(1,1), 4);
}

TEST(Mat2Test, invalidAccess) {
    const Matrix2 m;

    EXPECT_THROW(m(-1,0), std::out_of_range);
    EXPECT_THROW(m(0,-1), std::out_of_range);
    EXPECT_THROW(m(2,0), std::out_of_range);
    EXPECT_THROW(m(0,2), std::out_of_range);
}

TEST(Mat2Test, elemAssignment) {
    Matrix2 m({1,2,
               3,4});

    m(0, 0) = 0;
    m(0, 1) = 0;
    m(1, 0) = 0;
    m(1, 1) = 0;

    EXPECT_EQ(m(0,0), 0);
    EXPECT_EQ(m(0,1), 0);
    EXPECT_EQ(m(1,0), 0);
    EXPECT_EQ(m(1,1), 0);
}

TEST(Mat2Test, sum) {
    const Matrix2 m1({ 1,1,
                       1,1 });
    const Matrix2 m2({ 2,2,
                       2,2 });

    const Matrix2 m3 = m1 + m2;

    EXPECT_EQ(m3(0, 0), 3);
    EXPECT_EQ(m3(0, 1), 3);
    EXPECT_EQ(m3(1, 0), 3);
    EXPECT_EQ(m3(1, 1), 3);
}

TEST(Mat2Test, sub) {
    const Matrix2 m1({ 1,1,
                       1,1 });
    const Matrix2 m2({ 2,2,
                       2,2 });

    const Matrix2 m3 = m1 - m2;

    EXPECT_EQ(m3(0, 0), -1);
    EXPECT_EQ(m3(0, 1), -1);
    EXPECT_EQ(m3(1, 0), -1);
    EXPECT_EQ(m3(1, 1), -1);
}

TEST(Mat2Test, mul) {
    const Matrix2 m1({ 1,0,
                       0,1 });
    const Matrix2 m2({ 2,2,
                       2,2 });

    const Matrix2 m3 = m1 * m2;

    EXPECT_EQ(m3(0, 0), 2);
    EXPECT_EQ(m3(0, 1), 2);
    EXPECT_EQ(m3(1, 0), 2);
    EXPECT_EQ(m3(1, 1), 2);
}

TEST(Mat2Test, mul2) {
    const Matrix2 m1({ 1,2,
                       3,4 });
    const Matrix2 m2({ 4,3,
                       2,1 });

    const Matrix2 m3 = m1 * m2;

    EXPECT_EQ(m3(0, 0), 8);
    EXPECT_EQ(m3(0, 1), 5);
    EXPECT_EQ(m3(1, 0), 20);
    EXPECT_EQ(m3(1, 1), 13);
}

TEST(Mat2Test, mulVec) {
    const Matrix2 m1({ 1,0,
                       0,1 });
    const Vector2 v1(2,3);

    const Vector2 v2 = m1 * v1;

    EXPECT_EQ(v2, v1);
}

TEST(Mat2Test, mulVec2) {
    const Matrix2 m1({ 1,2,
                       3,4 });
    const Vector2 v1(2,3);

    const Vector2 v2 = m1 * v1;

    EXPECT_EQ(v2.x, 8);
    EXPECT_EQ(v2.y, 18);
}

TEST(Mat2Test, mulVecScale) {
    const Matrix2 m1({ 2,0,
                       0,2 });
    const Vector2 v1(2,3);

    const Vector2 v2 = m1 * v1;

    EXPECT_EQ(v2, v1*2);
}


TEST(Mat2Test, eq) {
    const Matrix2 m1({ 1,1,
                       1,1 });
    const Matrix2 m2({ 1,1,
                       1,1 });
    const Matrix2 m3({ 2,1,
                       1,1 });
    const Matrix2 m4({ 1,2,
                       1,1 });
    const Matrix2 m5({ 1,1,
                       2,1 });
    const Matrix2 m6({ 1,1,
                       1,2 });

    EXPECT_EQ(m1, m2);
    EXPECT_EQ(m1 == m3, false);
    EXPECT_EQ(m1 == m4, false);
    EXPECT_EQ(m1 == m5, false);
    EXPECT_EQ(m1 == m6, false);
}

TEST(Mat2Test, nEq) {
    const Matrix2 m1({ 1,1,
                       1,1 });
    const Matrix2 m2({ 1,1,
                       1,1 });
    const Matrix2 m3({ 2,1,
                       1,1 });
    const Matrix2 m4({ 1,2,
                       1,1 });
    const Matrix2 m5({ 1,1,
                       2,1 });
    const Matrix2 m6({ 1,1,
                       1,2 });

    EXPECT_EQ(m1 != m2, false);
    EXPECT_EQ(m1 != m3, true);
    EXPECT_EQ(m1 != m4, true);
    EXPECT_EQ(m1 != m5, true);
    EXPECT_EQ(m1 != m6, true);
}

TEST(Mat2Test, det) {
    const Matrix2 m({ 1,2,
                       3,4 });

    EXPECT_EQ(m.det(), -2);
}

TEST(Mat2Test, transpose) {
    const Matrix2 m({ 1,2,
                       3,4 });

    EXPECT_EQ(m.det(), -2);
}
