// managing the string
#ifndef _STRINGFUNCTIONS_HPP
#define _STRINGFUNCTIONS_HPP

ll readString(string s); //turn string into Long Long Integer

bool isPureNum(string s); //return ture IFF all char of given string are digits

bool isNum(string s); //return true IFF string is in '-123' or '-1.23'-like format

bool isIntNum(string s); //return true IFF string is in '-123'-like Integer format

bool isvalid(string s);  //check if s is valid BigNumInput string

string removePreSufSpace(string s);  //remove the previous and suffix space like "  A  " into "A"

bool isValidVariable(string s); //return true IIF string is in proper variable form like "ead123" or "_ears123" instead of "123es"

#endif