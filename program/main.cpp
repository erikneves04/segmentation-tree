#include <string>
#include <iostream>

#include "Matrix.hpp"
#include "Exceptions.hpp"
#include "SegmentationTree.hpp"

#define SUCCESS (00)
#define FAILURE (01)

int main(int argc, char const *argv[])
{   
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
            char option;
            std::cin >> option;

            if (option == 'u')
                tree->PerformUpdate();
            
            if (option == 'q')
            {
                int start, end;

                std::cin >> start;
                std::cin >> end;

                int coords[MATRIX_SIZE];
                for(int j = 0; j < MATRIX_SIZE; j++)
                    std::cin >> coords[j];
                
                tree->ApplyLinealTransformation(start, end, coords);
            }
        }
        
        // Liberação da memória
        delete tree;
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