// the help list
#include"head.hpp"

void printHelpList(){ // print help list
    cout<< "---------------------------------------------------------------------"<< endl;
    cout<< "Variable declaration format : variableName = expression ; like \" a = 3 + (3 * 4) \" , \" a = 3 * b \""<< endl;
    cout<< "'+' '-' '*' '-' '(' ')' can be used"<< endl;
    cout<< "you can declare a number like \"12e-123\""<< endl;
    cout<< "Input \"help\" to check help list"<<endl;
    cout<< "Input \"exit\" to exit calculator"<<endl;
    cout<< "---------------------------------------------------------------------"<< endl;
    cout<< "Fllowing functions can be used"<< endl;
    cout<< "sqrt(x)      ------- the sqrt of x     ; x must be positive number, or warning!"<< endl;
    cout<< "pow(a, b)    ------- the power : a ^ b ; a must NOT be 0, or Warning!"<< endl;
    cout<< "abs(a)       ------- the absolute value of a"<< endl;
    cout<< "---------------------------------------------------------------------"<< endl;
}