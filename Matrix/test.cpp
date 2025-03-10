
/*
*
*Author: Habtamu M. and ??
* Date: 9/22/2023
*
*/

#include "pch.h"
#include "Matrix.h"


struct MatrixTest :testing::Test
{


	//Test case 1 object
	Matrix* matrix11 = new Matrix();
	Matrix* matrix12 = new Matrix();


	//Test case 2 object
	Matrix* matrix21 = new Matrix();
	Matrix* matrix22 = new Matrix();


	//Test case 3 object
	Matrix* matrix31 = new Matrix();
	Matrix* matrix32 = new Matrix();

	//Test case 4 object
	Matrix* matrix41 = new Matrix();
	Matrix* matrix42 = new Matrix();

	//Test case 5 object
	Matrix* matrix51 = new Matrix();




	void SetUp()
	{
		//Arrange
		//Test Case 1 matrix data

		matrix11->setMatrix({ {1,2,3},
							   {2,4,5},
							   {3,6,8}

			});

		matrix12->setMatrix({ {-1,2,-3},
							   {2,-4,5},
							   {-3,6,-8}
			});

		//Test Case 2


		matrix21->setMatrix({
								{2,1},
								{4,1}
			});
		matrix22->setMatrix({
								{2,1},
								{3,0},
								{5,2}
			});


		matrix31->setMatrix({
								{0,0,0,0,0},
								{0,0,0,0,0},
								{0,0,0,0,0}
			});
		matrix32->setMatrix({
								{-1,-1,-1,-1,-1},
								{-1,-1,-1,-1,-1},
								{-1,-1,-1,-1,-1}
			});

		//row and column matrix 
		matrix41->setMatrix({
								{10,10,10,10,10}
			});
		matrix42->setMatrix({
								{2},
								{2},
								{1},
								{1},
								{3}
			});
		matrix51->setMatrix({
										{-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1}
			});

	}
	void TearDown()
	{
		delete matrix11;
		delete matrix12;

		delete matrix21;
		delete matrix22;

		delete matrix31;
		delete matrix32;

		delete matrix41;
		delete matrix42;


	}

};

// Adding square matrix 

TEST_F(MatrixTest, addition_test1)
{
	//Act
	Matrix actual = *matrix11 + *matrix12;
	vector<vector<int>> expected = {
										{0,4,0},
										{4,0,10},
										{0,12,0}
	};

	//Assert
	EXPECT_TRUE(expected == actual.getMatrix());
}

//  Addition operation on Matrices of different dimension

TEST_F(MatrixTest, Addition_Test2)
{
	//EXPECT_ANY_THROW(*matrix21+ *matrix22);
	EXPECT_THROW(*matrix21 + *matrix22, invalid_argument);
}

TEST_F(MatrixTest, addition_test3)
{
	//Act
	Matrix actual = *matrix31 + *matrix32;
	vector<vector<int>> expected = {

										{-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1},
										{-1,-1,-1,-1,-1}

	};

	//Assert
	EXPECT_TRUE(expected == actual.getMatrix());
}

TEST_F(MatrixTest, addition_test4)
{
	//Assert
	EXPECT_THROW(*matrix41 + *matrix42, invalid_argument);
}
// subtraction operation on Matrices of different dimension
TEST_F(MatrixTest, subtraction_Test1)
{

	Matrix actual = *matrix11 - *matrix12;
	vector<vector<int>> expected = { {2,0,6},
									{0,8,0},
									{6,0,16}
	};

	EXPECT_TRUE(expected == actual.getMatrix());
}
TEST_F(MatrixTest, subtraction_Test2)
{
	EXPECT_THROW(*matrix21 - *matrix22, invalid_argument);
}

TEST_F(MatrixTest, subtraction_test3)
{
	//Act
	Matrix actual = *matrix31 - *matrix32;
	vector<vector<int>> expected = {

										{1,1,1,1,1},
										{1,1,1,1,1},
										{1,1,1,1,1}

	};

	//Assert
	EXPECT_TRUE(expected == actual.getMatrix());
}
TEST_F(MatrixTest, subtraction_test4)
{
	//Assert
	EXPECT_THROW(*matrix41 - *matrix42, invalid_argument);
}


TEST_F(MatrixTest, multiplication_test1)
{

	Matrix actual = *matrix11 * *matrix12;
	vector<vector<int>> expected = {
									{-6,12,-17},
									{-9,18,-26},
									{-15,30,-43}
	};


	EXPECT_TRUE(expected == actual.getMatrix());
}


TEST_F(MatrixTest, Multiplication_Test2)
{

	EXPECT_THROW(*matrix21 * *matrix22, invalid_argument);
}


TEST_F(MatrixTest, Multiplication_Test3)
{
	EXPECT_THROW(*matrix31 * *matrix32, invalid_argument);
}

//Dot product matrix test
TEST_F(MatrixTest, multiplication_test4)
{

	Matrix actual = *matrix41 * *matrix42;
	vector<vector<int>> expected = { {90} };


	EXPECT_TRUE(expected == actual.getMatrix());
}

TEST_F(MatrixTest, digonalSum_test1)
{

	float diagSum = matrix11->digonalSum();
	EXPECT_EQ(diagSum, 13);

}

TEST_F(MatrixTest, Diagonalsum_Test2)
{
	EXPECT_THROW(matrix32->digonalSum(), invalid_argument);
}

TEST_F(MatrixTest, Diagonalsum_Test3)
{
	EXPECT_THROW(matrix41->digonalSum(), invalid_argument);
}


TEST_F(MatrixTest, digonalSum_test4)
{

	float diagSum = matrix51->digonalSum();
	EXPECT_EQ(diagSum, -5);

}


//TODO: Add at least two more test cases for each function
	//STUDENT

