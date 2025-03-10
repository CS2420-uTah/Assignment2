// #include "pch.h"
#include "Matrix.h"
#include <vector>
#include <iostream>

int main()
{
    Matrix matrix1;
    Matrix matrix2;
    int rows = 3, cols = 4; // 3x4 크기의 벡터 생성
    std::vector<std::vector<int>> vec1(rows, std::vector<int>(cols));
    std::vector<std::vector<int>> vec2(rows, std::vector<int>(cols));

    std::srand(std::time(nullptr)); // 랜덤 시드 설정

    // 벡터를 랜덤한 값으로 채우기 (예: 1~100 사이의 난수)
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            vec1[i][j] = std::rand() % 100 + 1; // 1~100 사이의 난수
            vec2[i][j] = std::rand() % 100 + 1;
        }
    }

    vec1.push_back({1, 2, 4});
    matrix1.setMatrix(vec1);
    matrix2.setMatrix(vec2);

    Matrix newMat;

    newMat = matrix1 + matrix2;

    std::cout << "ma1t:\n";
    for (const auto &row : matrix1.getMatrix())
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << "ma2t:\n";
    for (const auto &row : matrix2.getMatrix())
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << "mat:\n";
    for (const auto &row : newMat.getMatrix())
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    newMat = matrix1 - matrix2;
    std::cout << "mat:\n";
    for (const auto &row : newMat.getMatrix())
    {
        for (int val : row)
        {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}