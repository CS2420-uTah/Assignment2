/*
 *
 *Author: Katherine Jang
 * Date: Mar 8, 2025
 *
 */

#include "pch.h"
#include "Matrix.h"
#include <stdexcept>

// The setter method definition
void Matrix::setMatrix(vector<vector<int>> m)
{
	this->mat = m;
}
// The getter  method definition
vector<vector<int>> Matrix::getMatrix() const
{
	return this->mat;
}

// Matrix addition using  (+) operator overloading
Matrix Matrix::operator+(Matrix const &other)
{
	Matrix newMatrix = Matrix();
	vector<vector<int>> otherMatrixVec = other.getMatrix();
	vector<vector<int>> newVec;
	vector<int> newRow;
	int matRowSize = this->mat.size();
	int matColumnSize = 0;

	if (!this->isSameSizeVector(this->mat, other.getMatrix()))
	{
		throw invalid_argument("Dimension size not equal");
	}

	for (int i = 0; i < matRowSize; i++)
	{
		matColumnSize = this->mat[i].size();
		for (int j = 0; j < matColumnSize; j++)
		{
			newRow.push_back(this->mat[i][j] + otherMatrixVec[i][j]);
		}
		newVec.push_back(newRow);
		newRow.clear();
	}
	newMatrix.setMatrix(newVec);
	return newMatrix;
}

// Matrix subtraction using  (-) operator overloading
Matrix Matrix::operator-(Matrix const &other)
{
	Matrix newMatrix = Matrix();
	vector<vector<int>> otherMatrixVec = other.getMatrix();
	vector<vector<int>> newVec;
	vector<int> newRow;
	int matRowSize = this->mat.size();
	int matColumnSize = 0;

	if (!this->isSameSizeVector(this->mat, otherMatrixVec))
	{
		throw invalid_argument("Dimension size not equal");
	}

	for (int i = 0; i < matRowSize; i++)
	{
		matColumnSize = this->mat[i].size();
		for (int j = 0; j < matColumnSize; j++)
		{
			newRow.push_back(this->mat[i][j] - otherMatrixVec[i][j]);
		}
		newVec.push_back(newRow);
		newRow.clear();
	}
	newMatrix.setMatrix(newVec);
	return newMatrix;
}

// Matrix multiplication using  * operator overloading
Matrix Matrix::operator*(Matrix const &other)
{

	if (mat[0].size() != other.mat.size())
	{
		throw std::invalid_argument("Matrices dimensions are incompatible for multiplication");
	}
	else
	{
		Matrix result;
		result.mat.resize(mat.size(), vector<int>(other.mat[0].size(), 0));

		for (int i = 0; i < mat.size(); i++)
		{
			for (int j = 0; j < other.mat[0].size(); j++)
			{
				int sum = 0;
				for (int k = 0; k < mat[0].size(); k++)
				{
					sum += mat[i][k] * other.mat[k][j];
				}
				result.mat[i][j] = sum;
			}
		}
		return result;
	}
}

// A  method that adds  a diagonal elements of a square matrix
float Matrix::digonalSum()
{
	// vector<int> newRow;
	int sum = 0;
	int matRowSize = this->mat.size();
	int matColumnSize = 0;

	for (int i = 0; i < matRowSize; i++)
	{
		matColumnSize = this->mat[i].size();
		if (matColumnSize != matRowSize)
		{
			throw invalid_argument("matrix not square");
		}
		sum += this->mat[i][i];
	}
	return sum;
}

// operator(==) overloading method that checks the eqality of two matrices

bool Matrix::operator==(Matrix const &other)

{
	if (mat.size() != other.mat.size() && mat[0].size() != other.mat[0].size())
		return false;

	for (int i = 0; i < mat.size(); i++)
		for (int j = 0; j < mat[0].size(); j++)
			if (mat[i][j] != other.mat[i][j])
				return false;
	return true;
}

bool Matrix::isSameSizeVector(vector<vector<int>> a, vector<vector<int>> b)
{
	if (a.size() != b.size())
	{
		return false;
	}
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i].size() != b[i].size())
		{
			return false;
		}
	}
	return true;
}
