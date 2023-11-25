#include "TreeNode.hpp"

TreeNode::TreeNode(Matrix* matrix, int startIndex, int endIndex, TreeNode* previous)
{
    _startIndex = startIndex;
    _endIndex = endIndex;
    _previuous = previous;
    _matrix = matrix;
}

TreeNode::~TreeNode()
{ 
    if (_matrix != nullptr)
        delete _matrix;
}

void TreeNode::SetLeft(TreeNode* left)
{
    _left = left;
}

void TreeNode::SetRight(TreeNode* right)
{
    _right = right;
}

void TreeNode::SetPreviuous(TreeNode* previuous)
{
    _previuous = previuous;
}