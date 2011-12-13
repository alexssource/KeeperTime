#include "../header/Exception.h"

Exception::Exception(int c, string msg) { this->Initialize(c, msg); }

Exception::Exception(int c, string t, string msg) { this->Initialize(c, msg, t); }

const char* Exception::what() const throw()
{
    string result = "_";

    result += this->Code() + ". " + this->Type() + ": " + this->Message();
    return result.c_str();
}