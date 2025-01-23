#include <gtest/gtest.h>
#include "../include/matrix.hpp"

TEST(MatrixTest, AdditionWorks) {
    Matrix<int> mat1{{1, 2}, {3, 4}};
    Matrix<int> mat2{{5, 6}, {7, 8}};
    Matrix<int> result = mat1 + mat2;

    EXPECT_EQ(result(0, 0), 6);
    EXPECT_EQ(result(1, 1), 12);
}

TEST(MatrixTest, MultiplicationWorks) {
    Matrix<int> mat1{{1, 2}, {3, 4}};
    Matrix<int> mat2{{2, 0}, {1, 2}};
    Matrix<int> result = mat1 * mat2;

    EXPECT_EQ(result(0, 0), 4);
    EXPECT_EQ(result(0, 1), 4);
    EXPECT_EQ(result(1, 0), 10);
    EXPECT_EQ(result(1, 1), 8);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}