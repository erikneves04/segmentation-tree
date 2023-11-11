#pragma once

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

/**
 * @brief Exceção lançada quando uma operação é executada em uma lista vazia, ou acesso
 * inválido a algum item.
 *
 * Esta classe representa uma exceção personalizada que é lançada quando uma operação
 * é realizada em uma lista vazia, onde a operação não é válida em tal contexto.
 */
class element_not_found_exception
{   };

/**
 * @brief Exceção lançada quando uma operação é executada em uma posição inválida da matriz.
 *
 * Esta classe representa uma exceção personalizada que é lançada quando uma operação
 * é realizada em uma posição inválida da matriz, onde a operação não é válida em tal contexto.
 */
class invalid_matrix_positon_exception
{   };

#endif