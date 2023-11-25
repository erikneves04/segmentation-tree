#pragma once

#ifndef SEGMENTATIONTREE_HPP
#define SEGMENTATIONTREE_HPP

#include "Matrix.hpp"
#include "TreeNode.hpp"
#include "LinkedList.hpp"

#define OUTOFRANGE  (00)
#define INRANGE     (01)
#define INLEFTTREE  (02)
#define INRIGHTTREE (03)
#define INBOTHTREES (04)

typedef int RangeType;

class SegmentationTree
{
    private:
        LinkedList<TreeNode*>* _allTreeNodes;

        TreeNode* _root = nullptr;
        
        int _times;
        int _operations;

        Matrix* GetSheetMatrix(int index);
        TreeNode* GetSheetNode(TreeNode* current, int index);

        void UpdatePreviousNodes(TreeNode* current);

        void FillWithIdentity();
        void FillWithIdentity(TreeNode* current, int startIndex, int endIndex);

        RangeType GetRangeType(TreeNode* current, int startIndex, int endIndex);

        Matrix* Search(TreeNode* current, int startIndex, int endIndex);
    public:
        SegmentationTree(int times, int operations);
        ~SegmentationTree();

        void PerformUpdate();
        void PerformUpdate(int index, long int (*values)[MATRIX_SIZE]);
        int* ApplyLinearTransformation(int startIndex, int endIndex, int coords[]);

        Matrix* Search(int startIndex, int endIndex);

        void Print();
};

#endif