#pragma once

#ifndef SEGMENTATIONTREE_HPP
#define SEGMENTATIONTREE_HPP

#include "Matrix.hpp"
#include "TreeNode.hpp"
#include "LinkedList.hpp"

#define OUTOFRANGE  (00) // Intervalo completamente fora da árvore.
#define INRANGE     (01) // Intervalo completamente dentro de um nó.
#define INLEFTTREE  (02) // Intervalo dentro da subárvore à esquerda.
#define INRIGHTTREE (03) // Intervalo dentro da subárvore à direita.
#define INBOTHTREES (04) // Intervalo dentro de ambas as subárvores.

/**
 * @brief Tipos de intervalo para uma árvore de segmentação.
 */
typedef int RangeType;

/**
 * @brief Representa uma árvore de segmentação.
 *
 * A classe SegmentationTree implementa uma árvore de segmentação
 * utilizada para operações em matrizes.
 */
class SegmentationTree
{
    private:
        LinkedList<TreeNode*>* _allTreeNodes;

        TreeNode* _root = nullptr;
        
        int _times;
        int _operations;

        /**
         * @brief Obtém a matriz associada a uma folha da árvore.
         *
         * @param index O índice da folha.
         * @return A matriz associada à folha.
         */
        Matrix* GetSheetMatrix(int index);

        /**
         * @brief Obtém o nó folha associado a um índice.
         *
         * @param current O nó atual.
         * @param index O índice a ser procurado.
         * @return O nó folha associado ao índice.
         */
        TreeNode* GetSheetNode(TreeNode* current, int index);

        /**
         * @brief Atualiza os nós anteriores na árvore após uma atualização.
         *
         * @param current O nó atual.
         */
        void UpdatePreviousNodes(TreeNode* current);

        /**
         * @brief Preenche a árvore com matrizes de identidade.
         */
        void FillWithIdentity();

        /**
         * @brief Preenche a subárvore com matrizes de identidade.
         *
         * @param current O nó atual.
         * @param startIndex O índice de início do intervalo.
         * @param endIndex O índice de fim do intervalo.
         */
        void FillWithIdentity(TreeNode* current, int startIndex, int endIndex);

        /**
         * @brief Obtém o tipo de intervalo de um nó em relação a um índice.
         *
         * @param current O nó atual.
         * @param startIndex O índice de início do intervalo.
         * @param endIndex O índice de fim do intervalo.
         * @return O tipo de intervalo.
         */
        RangeType GetRangeType(TreeNode* current, int startIndex, int endIndex);

        /**
         * @brief Busca na árvore uma matriz associada a um intervalo.
         *
         * @param current O nó atual.
         * @param startIndex O índice de início do intervalo.
         * @param endIndex O índice de fim do intervalo.
         * @return A matriz associada ao intervalo.
         */
        Matrix* Search(TreeNode* current, int startIndex, int endIndex);
    public:
        /**
         * @brief Construtor da classe SegmentationTree.
         *
         * @param times Número de folhas(ou faixa temporal).
         * @param operations Número de operações.
         */
        SegmentationTree(int times, int operations);

        /**
         * @brief Destrutor da classe SegmentationTree.
         */
        ~SegmentationTree();

        /**
         * @brief Executa uma operação de atualização na árvore.
         */
        void PerformUpdate();

        /**
         * @brief Executa uma operação de atualização na árvore.
         *
         * @param index O índice da folha a ser atualizada.
         * @param values Os valores a serem atualizados na folha.
         */
        void PerformUpdate(int index, long int (*values)[MATRIX_SIZE]);
        
        /**
         * @brief Aplica uma transformação linear a um intervalo da árvore.
         *
         * @param startIndex O índice de início do intervalo.
         * @param endIndex O índice de fim do intervalo.
         * @param coords Um vetor de coordenadas para a transformação linear.
         * @return Um vetor resultante da transformação linear.
         */
        int* ApplyLinearTransformation(int startIndex, int endIndex, int coords[]);

        /**
         * @brief Busca na árvore uma matriz associada a um intervalo.
         *
         * @param startIndex O índice de início do intervalo.
         * @param endIndex O índice de fim do intervalo.
         * @return A matriz associada ao intervalo.
         */
        Matrix* Search(int startIndex, int endIndex);
};

#endif