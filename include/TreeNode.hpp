#pragma once

#ifndef TREENODE_HPP
#define TREENODE_HPP

#include "Matrix.hpp"

/**
 * @brief Representa um nó em uma árvore de segmentação.
 *
 * Esta classe armazena informações sobre um nó em uma árvore de segmentação,
 * incluindo índices de início e fim, uma matriz associada, ponteiros para
 * os nós à esquerda, à direita e ao nó pai.
 */
class TreeNode
{
    public:
        int _startIndex;
        int _endIndex;

        Matrix* _matrix = nullptr;
        
        TreeNode* _left = nullptr;
        TreeNode* _right = nullptr;
        TreeNode* _previuous = nullptr;

        /**
         * @brief Construtor da classe TreeNode.
         *
         * @param matrix A matriz associada ao nó.
         * @param startIndex O índice de início do intervalo representado pelo nó.
         * @param endIndex O índice de fim do intervalo representado pelo nó.
         * @param previous O nó pai na árvore.
         */
        TreeNode(Matrix* matrix, int startIndex, int endIndex, TreeNode* previous);

        /**
         * @brief Destrutor da classe TreeNode.
         */
        ~TreeNode();
        
        /**
         * @brief Define o nó à esquerda do nó atual.
         *
         * @param left O nó à esquerda.
         */
        void SetLeft(TreeNode* left);

        /**
         * @brief Define o nó à direita do nó atual.
         *
         * @param right O nó à direita.
         */
        void SetRight(TreeNode* right);

        /**
         * @brief Define o nó pai do nó atual.
         *
         * @param previous O nó pai.
         */
        void SetPreviuous(TreeNode* previuous);
};

#endif