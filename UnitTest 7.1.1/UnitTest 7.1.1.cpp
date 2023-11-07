#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 7.1.1/Lab 7.1.1.cpp"
#include <stdio.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourProjectTests
{
    TEST_CLASS(MatrixFunctionsTest)
    {
    public:

            TEST_METHOD(TestSortMatrix)
        {
            int matrix[8][5] = { { 34,  19,  46,  12,  29 },
                                { 41,  50,  38,  22,  39 },
                                { 28,  25,  13,  35,  43 },
                                { 47,  16,  10,  37,  21 },
                                { 24,  14,  27,  31,  32 },
                                { 48,  44,  18,  15,  11 },
                                { 36,  42,  33,  30,  49 },
                                { 26,  20,  40,  45,  23 }, };

            int* matrixPtr[8];
            for (int i = 0; i < 8; ++i) {
                matrixPtr[i] = matrix[i];
            }
            int sortingKeys[] = { 1, -1, -1 };
            SortMatrix(matrixPtr, 8, 5, sortingKeys);

            int expected[8][5] = { { 24,  14,  27,  31,  32 },
                                { 26,  20,  40,  45,  23 },
                                { 28,  25,  13,  35,  43 },
                                { 34,  19,  46,  12,  29 },
                                { 36,  42,  33,  30,  49 },
                                { 41,  50,  38,  22,  39 },
                                { 47,  16,  10,  37,  21 },
                                { 48,  44,  18,  15,  11 }, };

            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 5; ++j) {
                    Assert::AreEqual(matrix[i][j], expected[i][j]);
                }
            }
        }
        TEST_METHOD(TestCalculateAndReplace)
        {
            int matrix[8][5] = { {34, 19, 46, 12, 29},
                                 {41, 50, 38, 22, 39},
                                 {28, 25, 13, 35, 43},
                                 {47, 16, 10, 37, 21},
                                 {24, 14, 27, 31, 32},
                                 {48, 44, 18, 15, 11},
                                 {36, 42, 33, 30, 49},
                                 {26, 20, 40, 45, 23} };
            int* matrixPtr[8];
            for (int i = 0; i < 8; ++i) {
                matrixPtr[i] = matrix[i];
            }
            int sum = 0;
            int count = 0;
            CalculateAndReplace(matrixPtr, 8, 5, sum, count);
            int expected[8][5] = { { 0, 0, 46, 0, 0 },
                                   { 0, 50, 38, 22, 0 },
                                   { 28, 0, 0, 0, 0 },
                                   { 0, 16, 10, 0, 0 },
                                   { 24, 14, 0, 0, 32 },
                                   { 48, 44, 18, 0, 0 },
                                   { 0, 42, 0, 0, 0 },
                                   { 26, 20, 40, 0, 0 } };
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 5; ++j) {
                    Assert::AreEqual(matrix[i][j], expected[i][j]);
                }
            }
            Assert::AreEqual(sum, 695);
            Assert::AreEqual(count, 23);
        }
    };
}
