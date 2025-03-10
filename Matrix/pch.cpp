//
// pch.cpp
//

#include "pch.h"
#include "Matrix.h"
#include <vector>

// int main()
// {
//     Matrix matrix1;
//     Matrix matrix2;
//     int rows = 3, cols = 4; // 3x4 크기의 벡터 생성
//     std::vector<std::vector<int>> vec1(rows, std::vector<int>(cols));
//     std::vector<std::vector<int>> vec2(rows, std::vector<int>(cols));

//     std::srand(std::time(nullptr)); // 랜덤 시드 설정

//     // 벡터를 랜덤한 값으로 채우기 (예: 1~100 사이의 난수)
//     for (int i = 0; i < rows; ++i)
//     {
//         for (int j = 0; j < cols; ++j)
//         {
//             vec1[i][j] = std::rand() % 100 + 1; // 1~100 사이의 난수
//             vec2[i][j] = std::rand() % 100 + 1;
//         }
//     }

//     matrix1.setMatrix(vec1);
//     matrix2.setMatrix(vec2);

//     Matrix newMat;

//     newMat = matrix1 + matrix2;
// }