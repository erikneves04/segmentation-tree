#include <iostream>

#include "Matrix.hpp"
#include "LinkedList.hpp"
#include "ResultParser.hpp"
#include "SegmentationTree.hpp"

#include "memlog.h"

SegmentationTree::SegmentationTree(int times, int operations)
{ 
    _times = times;
    _operations = operations;

    _allTreeNodes = new LinkedList<TreeNode*>();

    FillWithIdentity();
}

SegmentationTree::~SegmentationTree()
{ 
    for(int i = 0; i < _allTreeNodes->Length(); i++)
    {
        auto treeNode = _allTreeNodes->Get(i);        
        delete treeNode;
    }

    delete _allTreeNodes;
}

Matrix* SegmentationTree::GetSheetMatrix(int index)
{
    return GetSheetNode(_root, index)->_matrix;
}

TreeNode* SegmentationTree::GetSheetNode(TreeNode* current, int index)
{
    if (current == nullptr)
        return nullptr;
    
    int bits = sizeof(TreeNode) + sizeof(Matrix);
    LEMEMLOG((long int)(current),bits,2);

    if (current->_startIndex == current->_endIndex && current->_startIndex == index)
        return current;

    if (current->_left->_endIndex < index)
        return GetSheetNode(current->_right, index);
    else
        return GetSheetNode(current->_left, index);
}

void SegmentationTree::PerformUpdate()
{
    int index;
    std::cin >> index;

    long int values[MATRIX_SIZE][MATRIX_SIZE];

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cin >> values[i][j];
        }
    }

    PerformUpdate(index, values);
}

void SegmentationTree::PerformUpdate(int index, long int (*values)[MATRIX_SIZE])
{
    TreeNode* node = GetSheetNode(_root, index);
    Matrix* matrix = node->_matrix;

    if (matrix == nullptr)
        return;

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        for(int j = 0; j < MATRIX_SIZE; j++)
        {
            matrix->Set(i, j, values[i][j]);
        }
    }
    ESCREVEMEMLOG((long int)matrix, sizeof(Matrix), 2);

    UpdatePreviousNodes(node->_previuous);
}

void SegmentationTree::UpdatePreviousNodes(TreeNode* current)
{
    if (current == nullptr)
        return;

    delete current->_matrix;
    
    auto matrix1 = current->_left->_matrix;
    LEMEMLOG((long int)matrix1, sizeof(Matrix), 2);

    auto matrix2 = current->_right->_matrix;
    LEMEMLOG((long int)matrix2, sizeof(Matrix), 2);

    current->_matrix = matrix1->Multiply(matrix2);
    ESCREVEMEMLOG((long int)current->_matrix, sizeof(Matrix), 2);

    UpdatePreviousNodes(current->_previuous);
}

void SegmentationTree::FillWithIdentity()
{
    int startIndex = 0;
    int endIndex = _times - 1;

    _root = new TreeNode(new Matrix(), startIndex, endIndex, nullptr);
    _allTreeNodes->Insert(_root);

    int bits = sizeof(TreeNode) + sizeof(Matrix);
    ESCREVEMEMLOG((long int)(_root),bits,1);

    FillWithIdentity(_root, startIndex, endIndex);
}

void SegmentationTree::FillWithIdentity(TreeNode* current, int startIndex, int endIndex)
{
    if (startIndex == endIndex)
        return;

    int middleIndex = (startIndex + endIndex) / 2;

    Matrix* matrixLeft = new Matrix();
    Matrix* matrixRight = new Matrix();

    TreeNode* left = new TreeNode(matrixLeft, startIndex, middleIndex, current);
    TreeNode* right = new TreeNode(matrixRight, middleIndex + 1, endIndex, current);

    int bits = sizeof(TreeNode) + sizeof(Matrix);

    ESCREVEMEMLOG((long int)(left),bits,1);
    ESCREVEMEMLOG((long int)(right),bits,1);

    _allTreeNodes->Insert(left);
    _allTreeNodes->Insert(right);

    current->SetLeft(left);
    current->SetRight(right);

    FillWithIdentity(left, startIndex, middleIndex);
    FillWithIdentity(right, middleIndex + 1, endIndex);
}

RangeType SegmentationTree::GetRangeType(TreeNode* current, int startIndex, int endIndex)
{
    if (current == nullptr)
        return OUTOFRANGE;

    if (current->_endIndex < startIndex || current->_startIndex > endIndex)
        return OUTOFRANGE;

    if (current->_startIndex >= startIndex && current->_endIndex <= endIndex)
        return INRANGE;

    int middleIndex = (current->_startIndex + current->_endIndex) / 2;

    if (startIndex <= middleIndex && endIndex > middleIndex)
        return INBOTHTREES;

    if (endIndex <= middleIndex)
        return INLEFTTREE;

    if (endIndex > middleIndex)
        return INRIGHTTREE;

    return OUTOFRANGE;
}

Matrix* SegmentationTree::Search(TreeNode* current, int startIndex, int endIndex)
{
    LEMEMLOG((long int)(current), sizeof(TreeNode), 0);

    RangeType rangeType = GetRangeType(current, startIndex, endIndex);

    if (rangeType == OUTOFRANGE)
        return new Matrix();

    if (rangeType == INRANGE)
    {
        auto copy = current->_matrix->Copy();
        ESCREVEMEMLOG((long int)(copy), sizeof(Matrix), 0);
        return copy;
    }

    if (rangeType == INLEFTTREE)
        return Search(current->_left, startIndex, endIndex);

    if (rangeType == INRIGHTTREE)
        return Search(current->_right, startIndex, endIndex);
    
    if (rangeType == INBOTHTREES)
    {
        Matrix* matrix1 = Search(current->_left, startIndex, endIndex);
        Matrix* matrix2 = Search(current->_right, startIndex, endIndex);

        if (matrix1 == nullptr && matrix2 == nullptr)
            return new Matrix();

        if (matrix1 == nullptr)
            return matrix2;

        if (matrix2 == nullptr)
            return matrix1;

        Matrix* result = matrix1->Multiply(matrix2);
        ESCREVEMEMLOG((long int)(result), sizeof(Matrix), 0);

        delete matrix1;
        delete matrix2;

        return result;
    }

    return new Matrix();
}

Matrix* SegmentationTree::Search(int startIndex, int endIndex)
{
    return Search(_root, startIndex, endIndex);
}

int* SegmentationTree::ApplyLinearTransformation(int startIndex, int endIndex, int coords[MATRIX_SIZE])
{
    Matrix* matrix = Search(_root, startIndex, endIndex);
    LEMEMLOG((long int)matrix, sizeof(Matrix), 0);

    if (matrix == nullptr)
        return nullptr;

    int* result = new int[MATRIX_SIZE];

    for(int i = 0; i < MATRIX_SIZE; i++)
    {
        long int sum = 0;
        for(int j = 0; j < MATRIX_SIZE; j++)
            sum += matrix->Get(i, j) * coords[j];
        
        result[i] = ResultParser::GetLast8Digits(sum);
    }

    delete matrix;
    return result;
}