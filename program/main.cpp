#include <string>
#include <iostream>

#include "memlog.h"

#include "Matrix.hpp"
#include "Exceptions.hpp"
#include "SegmentationTree.hpp"

#define SUCCESS (00)
#define FAILURE (01)

/**
 * @brief Imprime o vetor de resultados da transformação linear, após isso o vetor é
 * apagado da memória.
 *
 * Este método imprime os valores contidos no vetor resultante.
 *
 * @param result Um vetor de inteiros contendo os resultados a serem impressos.
 */
void PrintAndCleanVector(int result[])
{
    for(int j = 0; j < MATRIX_SIZE; j++)
    {
        if (j == MATRIX_SIZE - 1)
            std::cout << result[j] << std::endl;
        else
            std::cout << result[j] << " ";
    }
    
    // Liberação do vetor já impresso
    delete[] result;
}

char logName[100] = "data.out";

int main(int argc, char const *argv[])
{   
    // Inicialização do log de memória
    iniciaMemLog(logName);
    ativaMemLog();

    try
    {
        // Leitura da informações iniciais
        int times, operations;
        std::cin >> times >> operations;

        // Criação da árvore de segmentação preenchida com a matriz identidade
        SegmentationTree* tree = new SegmentationTree(times, operations);

        // Aplicação das operações
        for(int i = 0; i < operations; i++)
        {
            // Leitura da operação
            char option;
            std::cin >> option;

            // Execução de atualização
            if (option == 'u')
                tree->PerformUpdate();
            
            // Execução de consulta
            if (option == 'q')
            {
                // Leitura do intervalo
                int start, end;
                std::cin >> start;
                std::cin >> end;

                // Leitura das coordenadas
                int coords[MATRIX_SIZE];
                for(int j = 0; j < MATRIX_SIZE; j++)
                    std::cin >> coords[j];
                
                // Aplicação e impressão da transformação linear
                int* result = tree->ApplyLinearTransformation(start, end, coords);
                PrintAndCleanVector(result);
            }
        }

        // Liberação da memória
        delete tree;

        finalizaMemLog();
    }
    catch(element_not_found_exception)
    {
        std::cout << "Houve uma tentativa inválida de acesso a um item da lista encadeada!" << std::endl;
        return FAILURE;
    }
    catch(invalid_matrix_positon_exception)
    {
        std::cout << "A posição da matriz escolhida é inválida!" << std::endl;
        return FAILURE;
    }
    catch(...)
    {
        std::cout << "Houve um erro não identificado!" << std::endl;
        return FAILURE;
    }

    // Encerramento do código com sucesso
    return SUCCESS;
}