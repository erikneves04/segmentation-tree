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

void BaseTest(std::string testCase, int queries[MATRIX_SIZE])
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