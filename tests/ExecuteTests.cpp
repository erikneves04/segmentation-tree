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

TEST_CASE("#01")
{
    RedirectInputStream("01");

    int times, operations;
    std::cin >> times >> operations;

    SegmentationTree* tree = new SegmentationTree(times, operations);

    long int results[5][MATRIX_SIZE][MATRIX_SIZE];

    for(int i = 0; i < operations; i++)
    {
        char option;
        std::cin >> option;

        if (option == 'u')
            tree->PerformUpdate();
        
        if (option == 'q')
        {
            int start, end;

            std::cin >> start;
            std::cin >> end;

            int coords[MATRIX_SIZE];
            for(int j = 0; j < MATRIX_SIZE; j++)
                std::cin >> coords[j];
            
            int* result = tree->ApplyLinealTransformation(start, end, coords);
            

            
            for(int j = 0; j < MATRIX_SIZE; j++)
            {
                if (j == MATRIX_SIZE - 1)
                    std::cout << result[j] << std::endl;
                else
                    std::cout << result[j] << " ";
            }
            delete result;
        }
    }

    RestoreInputStream();
}