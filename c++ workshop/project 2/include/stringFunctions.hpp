#ifndef _STRINGFUNCTIONS_HPP
#define _STRINGFUNCTIONS_HPP

// managing the string
ll readString(string s); //turn string into Long Long Integer

bool isPureNum(string s); //return ture IFF all char of given string are digits

bool isNum(string s); //return true IFF string is in '-123' or '-1.23'-like format

bool isIntNum(string s); //return true IFF string is in '-123'-like Integer format

bool isvalid(string s);  //check if s is valid

#endif