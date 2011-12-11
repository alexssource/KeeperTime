#include "../header/Exception.h"

Exception::Exception(int c, string msg): code(c), message(msg) { }
Exception::Exception(int c, string t, string msg): code(c), message(msg), type(t) { }

const char* what() const throw()
{
    return "_" + code + ". " + type + ": " + message;
}