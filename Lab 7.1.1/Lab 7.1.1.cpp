#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

void CreateMatrix(int** matrix, const int rowCount, const int colCount, const int low, const int high);
void PrintMatrix(int** matrix, const int rowCount, const int colCount);
void SortMatrix(int** matrix, const int rowCount, const int colCount, int* sortingKeys);
void CalculateAndReplace(int** matrix, const int rowCount, const int colCount, int& sum, int& count);

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    const int rowCount = 8;
    const int colCount = 5;
    const int low = 4;
    const int high = 51;

    int** matrix = new int* [rowCount];
    for (int i = 0; i < rowCount; ++i) {
        matrix[i] = new int[colCount];
    }

    CreateMatrix(matrix, rowCount, colCount, low, high);
    cout << "Original Matrix:" << endl;
    PrintMatrix(matrix, rowCount, colCount);

    int sortingKeys[] = { 1, -1, -1 }; 
    SortMatrix(matrix, rowCount, colCount, sortingKeys);

    int sum = 0;
    int count = 0;
    CalculateAndReplace(matrix, rowCount, colCount, sum, count);

    cout << "Modified Matrix:" << endl;
    PrintMatrix(matrix, rowCount, colCount);
    cout << "Sum of elements satisfying the criterion: " << sum << endl;
    cout << "Count of elements satisfying the criterion: " << count << endl;

    for (int i = 0; i < rowCount; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

void CreateMatrix(int** matrix, const int rowCount, const int colCount, const int low, const int high) {
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            matrix[i][j] = low + rand() % (high - low + 1);
        }
    }
}

void PrintMatrix(int** matrix, const int rowCount, const int colCount) {
    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

void SortMatrix(int** matrix, const int rowCount, const int colCount, int* sortingKeys) {
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = 0; j < rowCount - i - 1; j++) {
            bool swap = false;

            if (sortingKeys[0] == 1) {
                if (matrix[j][0] > matrix[j + 1][0]) {
                    swap = true;
                }
            }
            else if (sortingKeys[0] == -1) {
                if (matrix[j][0] < matrix[j + 1][0]) {
                    swap = true;
                }
            }

            if (matrix[j][0] == matrix[j + 1][0]) {
                if (sortingKeys[1] == 1) {
                    if (matrix[j][1] > matrix[j + 1][1]) {
                        swap = true;
                    }
                }
                else if (sortingKeys[1] == -1) {
                    if (matrix[j][1] < matrix[j + 1][1]) {
                        swap = true;
                    }
                }
            }

            if (matrix[j][0] == matrix[j + 1][0] && matrix[j][1] == matrix[j + 1][1]) {
                if (sortingKeys[2] == 1) {
                    if (matrix[j][2] > matrix[j + 1][2]) {
                        swap = true;
                    }
                }
                else if (sortingKeys[2] == -1) {
                    if (matrix[j][2] < matrix[j + 1][2]) {
                        swap = true;
                    }
                }
            }

            if (swap) {
                for (int k = 0; k < colCount; k++) {
                    int temp = matrix[j][k];
                    matrix[j][k] = matrix[j + 1][k];
                    matrix[j + 1][k] = temp;
                }
            }
        }
    }
}

void CalculateAndReplace(int** matrix, const int rowCount, const int colCount, int& sum, int& count) {
    sum = 0;
    count = 0;

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount; ++j) {
            if (matrix[i][j] % 2 != 0 || (i % 3 == 0 && j % 3 == 0)) {
                sum += matrix[i][j];
                count++;
                matrix[i][j] = 0;
            }
        }
    }
}
