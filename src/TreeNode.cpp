#include "TreeNode.hpp"

TreeNode::TreeNode(int startIndex, int endIndex, TreeNode* previous = nullptr)
{
    _startIndex = startIndex;
    _endIndex = endIndex;
    _previuous = previous;
}

TreeNode::TreeNode(Matrix* matrix, int startIndex, int endIndex, TreeNode* previous = nullptr)
    : TreeNode(startIndex, endIndex, previous)
{
    _matrix = matrix;
}

TreeNode::~TreeNode()
{ }

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