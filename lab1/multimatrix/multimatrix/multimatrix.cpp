#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        std::cout << "Enter arguements correctly: multmatrix.exe <matrix file1> <matrix file2>" << std::endl;
        return 1;
    }

    // Открываем файлы с матрицами
    std::ifstream matrix1(argv[1]);
    std::ifstream matrix2(argv[2]);

    if (!matrix1 || !matrix2) {
        std::cout << "Warning: files with matrix cannot be open" << std::endl;
        return 1;
    }

    // Считываем матрицы
    double matrixA[3][3], matrixB[3][3];

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            matrix1 >> matrixA[i][j];
            matrix2 >> matrixB[i][j];
        }
    }

    // Умножаем матрицы
    double result[3][3] = { 0 };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Выводим результат
    std::cout << std::fixed << std::setprecision(3);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}