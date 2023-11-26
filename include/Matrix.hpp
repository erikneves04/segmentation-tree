#pragma once

#ifndef MATRIX_HPP
#define MATRIX_HPP

#define MATRIX_SIZE (02)

/**
 * @brief Classe que representa uma matriz quadrada de inteiros.
 * 
 * Esta classe representa uma matriz quadrada de inteiros, com tamanho definido pela macro
 * MATRIX_SIZE. A matriz é representada internamente por um array bidimensional de inteiros(long int).
 */
class Matrix
{
    private:
        long int _matrix[MATRIX_SIZE][MATRIX_SIZE];

    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         * Este é o construtor padrão da classe, que inicializa seus dados com a identidade.
         */
        Matrix();

        /**
         * @brief Destrutor padrão da classe.
         * 
         * Este é o destrutor padrão da classe, que não realiza nenhuma operação.
         */
        ~Matrix();

        /**
         * @brief Obtém o valor de uma posição da matriz.
         * 
         * Este método obtém o valor de uma posição da matriz, verificando se a posição
         * é válida.
         * 
         * @param i Índice da linha da matriz.
         * @param j Índice da coluna da matriz.
         * @return O valor da posição da matriz.
         */
        long int Get(int i, int j);
        
        /**
         * @brief Define o valor de uma posição da matriz.
         * 
         * Este método define o valor de uma posição da matriz, verificando se a posição
         * é válida.
         * 
         * @param i Índice da linha da matriz.
         * @param j Índice da coluna da matriz.
         * @param value Valor a ser definido na posição da matriz.
         */
        void Set(int i, int j, long int value);

        /**
         * @brief Multiplica a matriz por outra matriz.
         *
         * Este método realiza a multiplicação de matrizes, onde o resultado é
         * uma nova matriz obtida pela multiplicação da matriz atual por outra matriz.
         *
         * @param other A matriz a ser multiplicada pela matriz atual.
         * @return Uma nova matriz resultante da multiplicação.
         */
        Matrix* Multiply(Matrix* other);

        /**
         * @brief Cria uma cópia da matriz.
         * 
         * Este método cria uma cópia da matriz, alocando memória para a nova matriz e copiando
         * os valores da matriz original para a nova matriz.
         * 
         * @return A cópia da matriz.
        */
        Matrix* Copy();
};

#endif