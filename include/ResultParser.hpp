#pragma once

#ifndef RESULTPARSER_HPP
#define RESULTPARSER_HPP

/**
 * @brief Classe utilitária para análise de resultados.
 *
 * A classe ResultParser fornece métodos estáticos para analisar e extrair
 * dígitos específicos de valores numéricos.
 */
class ResultParser
{
public:
    /**
     * @brief Obtém os últimos N dígitos de um valor.
     *
     * @param value O valor do qual extrair os dígitos.
     * @param nDigits O número de dígitos a serem extraídos.
     * @return Os últimos N dígitos do valor.
     */
    static long int GetLastNDigits(long int value, int nDigits);

    /**
     * @brief Obtém os últimos 8 dígitos de um valor.
     *
     * @param value O valor do qual extrair os dígitos.
     * @return Os últimos 8 dígitos do valor.
     */
    static long int GetLast8Digits(long int value);
};

#endif