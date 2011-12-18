/* 
 * File:   NumberToStringConverter.h
 * Author: alex
 *
 * Created on December 17, 2011, 6:23 PM
 */

#ifndef NUMBERTOSTRINGCONVERTER_H
#define	NUMBERTOSTRINGCONVERTER_H

#include <string>
#include <sstream>

using namespace std;

template <class T>
class NumberToStringConverter
{
public:
    static string Convert(T base)
    {
        stringstream ss;

        ss << base;
        return ss.str();
    }

};

#endif	/* NUMBERTOSTRINGCONVERTER_H */

