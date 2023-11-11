#include "TreeNode.hpp"

TreeNode::TreeNode(int startIndex, int endIndex)
{
    _startIndex = startIndex;
    _endIndex = endIndex;
}

TreeNode::TreeNode(Matrix* matrix, int startIndex, int endIndex)
    : TreeNode(startIndex, endIndex)
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