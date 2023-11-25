#include "../third_party/doctest.h"
#include "Matrix.hpp"
#include "SegmentationTree.hpp"

TEST_CASE("Propagation - #01")
{
    SegmentationTree* tree = new SegmentationTree(2, 1);

    tree->PerformUpdate(0, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 1, 2 },
        { 3, 4 }
    });

    tree->PerformUpdate(1, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 10, 20 },
        { 30, 40 }
    });

    Matrix* interval = tree->Search(0, 1);
    
    CHECK(interval->Get(0, 0) == 70);
    CHECK(interval->Get(0, 1) == 100);
    CHECK(interval->Get(1, 0) == 150);
    CHECK(interval->Get(1, 1) == 220);

    delete interval;
    delete tree;
}

TEST_CASE("Propagation - #02")
{
    SegmentationTree* tree = new SegmentationTree(2, 1);

    tree->PerformUpdate(0, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 1, 2 },
        { 3, 4 }
    });

    tree->PerformUpdate(1, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 10, 20 },
        { 30, 40 }
    });

    Matrix* interval = tree->Search(0, 0);
    
    CHECK(interval->Get(0, 0) == 1);
    CHECK(interval->Get(0, 1) == 2);
    CHECK(interval->Get(1, 0) == 3);
    CHECK(interval->Get(1, 1) == 4);

    delete interval;
    delete tree;
}

TEST_CASE("Propagation - #03")
{
    SegmentationTree* tree = new SegmentationTree(2, 1);

    tree->PerformUpdate(0, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 1, 2 },
        { 3, 4 }
    });

    tree->PerformUpdate(1, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 10, 20 },
        { 30, 40 }
    });

    Matrix* interval = tree->Search(1, 1);
    
    CHECK(interval->Get(0, 0) == 10);
    CHECK(interval->Get(0, 1) == 20);
    CHECK(interval->Get(1, 0) == 30);
    CHECK(interval->Get(1, 1) == 40);
    
    delete interval;
    delete tree;
}

TEST_CASE("Propagation - #04")
{
    SegmentationTree* tree = new SegmentationTree(3, 1);

    tree->PerformUpdate(0, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 1, 2 },
        { 3, 4 }
    });

    tree->PerformUpdate(1, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 10, 20 },
        { 30, 40 }
    });

    tree->PerformUpdate(2, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 100, 200 },
        { 300, 400 }
    });

    Matrix* interval = tree->Search(0, 1);
    
    CHECK(interval->Get(0, 0) == 70);
    CHECK(interval->Get(0, 1) == 100);
    CHECK(interval->Get(1, 0) == 150);
    CHECK(interval->Get(1, 1) == 220);

    delete interval;
    delete tree;
}

TEST_CASE("Propagation - #05")
{
    SegmentationTree* tree = new SegmentationTree(3, 1);

    tree->PerformUpdate(0, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 1, 2 },
        { 3, 4 }
    });

    tree->PerformUpdate(1, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 10, 20 },
        { 30, 40 }
    });

    tree->PerformUpdate(2, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 100, 200 },
        { 300, 400 }
    });

    Matrix* interval = tree->Search(1, 2);
    
    CHECK(interval->Get(0, 0) == 7000);
    CHECK(interval->Get(0, 1) == 10000);
    CHECK(interval->Get(1, 0) == 15000);
    CHECK(interval->Get(1, 1) == 22000);

    delete interval;
    delete tree;
}

TEST_CASE("Propagation - #06")
{
    SegmentationTree* tree = new SegmentationTree(3, 1);

    tree->PerformUpdate(0, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 1, 2 },
        { 3, 4 }
    });

    tree->PerformUpdate(1, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 10, 20 },
        { 30, 40 }
    });

    tree->PerformUpdate(2, new long int[MATRIX_SIZE][MATRIX_SIZE] 
    {
        { 100, 200 },
        { 300, 400 }
    });

    Matrix* interval = tree->Search(0, 2);

    CHECK(interval->Get(0, 0) == 37000);
    CHECK(interval->Get(0, 1) == 54000);
    CHECK(interval->Get(1, 0) == 81000);
    CHECK(interval->Get(1, 1) == 118000);

    delete interval;
    delete tree;
}