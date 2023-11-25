#pragma once

#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "Matrix.hpp"

class TreeNode
{
    public:
        int _startIndex;
        int _endIndex;

        Matrix* _matrix = nullptr;
        
        TreeNode* _left = nullptr;
        TreeNode* _right = nullptr;
        TreeNode* _previuous = nullptr;

        TreeNode(Matrix* matrix, int startIndex, int endIndex, TreeNode* previous);
        ~TreeNode();

        void SetLeft(TreeNode* left);
        void SetRight(TreeNode* right);
        void SetPreviuous(TreeNode* previuous);

        void Print();
};

#endif