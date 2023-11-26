#include "ResultParser.hpp"

long int ResultParser::GetLastNDigits(long int value, int nDigits)
{
    long int minToParse = 1;
    for(int i = 0; i < nDigits; i++)
    {
        minToParse *= 10;
    }

    if (value < minToParse)
        return value;

    return (value % minToParse);
}

long int ResultParser::GetLast8Digits(long int value)
{
    return value % 100000000;
}