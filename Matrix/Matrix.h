

/*
 *
 *Author: Habtamu M. and ??
 * Date: 9/22/2023
 *
 */

#pragma once
#include <vector>
using namespace std;

class Matrix
{
	//  A 2D vector
	vector<vector<int>> mat;

public:
	// a setter method
	void setMatrix(vector<vector<int>> m);

	// a getter method
	vector<vector<int>> getMatrix() const;

	// a matrix addition  using operator(+) overloading
	Matrix operator+(Matrix const &other);

	// a matrix subtraction  using operator(-) overloading
	Matrix operator-(Matrix const &other);

	// a matrix multiplication  using operator(*) overloading
	Matrix operator*(Matrix const &other);
	// == operator overloading  to check the eqality of two matrices
	bool operator==(Matrix const &other);

	// a diagonal sum  which adds the diagonal elements of a square matrix
	float digonalSum();

	bool isSameSizeVector(vector<vector<int>>, vector<vector<int>>);
};
