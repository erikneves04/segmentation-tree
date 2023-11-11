#include <iostream>
#include <fstream>
#include <sstream>

#include "../third_party/doctest.h"

#include "Matrix.hpp"
#include "SegmentationTree.hpp"
#include "Exceptions.hpp"

std::streambuf* original_cin = nullptr;
std::ifstream input_file;

void RedirectInputStream(std::string testCase)
{   
    std::string path = "tests//Inputs//" + testCase + ".txt";

    input_file = std::ifstream(path);
    REQUIRE(input_file.is_open());

    original_cin = std::cin.rdbuf();
    std::cin.rdbuf(input_file.rdbuf());
}

void RestoreInputStream()
{
    std::cin.rdbuf(original_cin);
    input_file.close();
}

void BaseTest(std::string testCase, std::string output)
{
    RedirectInputStream(testCase);

    try
    {
        
    }
    catch(element_not_found_exception)
    {
        std::cout << "Houve uma tentativa inválida de acesso a um item da lista encadeada!" << std::endl;
        CHECK(false);
    }
    catch(invalid_matrix_positon_exception)
    {
        std::cout << "A posição da matriz escolhida é inválida!" << std::endl;
        CHECK(false);
    }
    catch(...)
    {
        std::cout << "Houve um erro não identificado!" << std::endl;
        CHECK(false);
    }
    
    RestoreInputStream();
}

TEST_CASE("#01 - Matrix multiplication")
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

    Matrix* result = (*matrix1) * (*matrix2);

    CHECK(result->Get(0, 0) == 9);
    CHECK(result->Get(0, 1) == 13);
    CHECK(result->Get(1, 0) == 24);
    CHECK(result->Get(1, 1) == 43);

    delete matrix1;
    delete matrix2;
    delete result;
}

TEST_CASE("#02 - Matrix multiplication")
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

    Matrix* result = (*matrix1) * (*matrix2);

    CHECK(result->Get(0, 0) == 3775);
    CHECK(result->Get(0, 1) == 4384);
    CHECK(result->Get(1, 0) == 655);
    CHECK(result->Get(1, 1) == 2074);

    delete matrix1;
    delete matrix2;
    delete result;
}