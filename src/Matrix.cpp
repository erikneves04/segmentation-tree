#include <iostream>

#include "Matrix.hpp"
#include "Exceptions.hpp"
#include "ResultParser.hpp"

Matrix::Matrix()
{
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
            _matrix[i][j] = (i == j ? 1 : 0);
        }       
    }
}

Matrix::~Matrix()
{ }

void ThrowExceptionIfIsInvalidPosition(int i, int j)
{
    if (i < 0 || i >= MATRIX_SIZE || j < 0 || j >= MATRIX_SIZE)
        throw invalid_matrix_positon_exception();
}

long int Matrix::Get(int i, int j)
{
    ThrowExceptionIfIsInvalidPosition(i, j);
    return _matrix[i][j];
}

void Matrix::Set(int i, int j, long int value)
{
    ThrowExceptionIfIsInvalidPosition(i, j);
    _matrix[i][j] = value;
}

Matrix* Matrix::Multiply(Matrix* other)
{
    Matrix* result = new Matrix();

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
            long int sum = 0;

            for(int k = 0; k < MATRIX_SIZE; k++)
                sum += ResultParser::GetLast8Digits(_matrix[i][k]) * ResultParser::GetLast8Digits(other->_matrix[k][j]);

            result->_matrix[i][j] = ResultParser::GetLast8Digits(sum);
        }
    }

    return result;
}

Matrix* Matrix::Copy()
{
    Matrix* result = new Matrix();

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
            result->_matrix[i][j] = _matrix[i][j];
        }
    }

    return result;
}