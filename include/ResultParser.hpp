#pragma once

#ifndef RESULTPARSER_HPP
#define RESULTPARSER_HPP

class ResultParser
{
    public:
        static long int GetLastNDigits(long int value, int nDigits);
        static long int GetLast8Digits(long int value); 
};

#endif