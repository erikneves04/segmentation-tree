#include "../third_party/doctest.h"
#include "Matrix.hpp"

TEST_CASE("Matrix multiplication - #01")
{
    Matrix* matrix1 = new Matrix();
    Matrix* matrix2 = new Matrix();

    matrix1->Set(0, 0, 1);
    matrix1->Set(0, 1, 2);
    matrix1->Set(1, 0, 4);
    matrix1->Set(1, 1, 5);

    matrix2->Set(0, 0, 1);
    matrix2->Set(0, 1, 7);
    matrix2->Set(1, 0, 4);
    matrix2->Set(1, 1, 3);

    Matrix* result = matrix1->Multiply(matrix2);

    CHECK(result->Get(0, 0) == 9);
    CHECK(result->Get(0, 1) == 13);
    CHECK(result->Get(1, 0) == 24);
    CHECK(result->Get(1, 1) == 43);

    delete matrix1;
    delete matrix2;
    delete result;
}

TEST_CASE("Matrix multiplication - #02")
{
    Matrix* matrix1 = new Matrix();
    Matrix* matrix2 = new Matrix();

    matrix1->Set(0, 0, 22);
    matrix1->Set(0, 1, 79);
    matrix1->Set(1, 0, 25);
    matrix1->Set(1, 1, 9);

    matrix2->Set(0, 0, 10);
    matrix2->Set(0, 1, 70);
    matrix2->Set(1, 0, 45);
    matrix2->Set(1, 1, 36);

    Matrix* result = matrix1->Multiply(matrix2);

    CHECK(result->Get(0, 0) == 3775);
    CHECK(result->Get(0, 1) == 4384);
    CHECK(result->Get(1, 0) == 655);
    CHECK(result->Get(1, 1) == 2074);

    delete matrix1;
    delete matrix2;
    delete result;
}