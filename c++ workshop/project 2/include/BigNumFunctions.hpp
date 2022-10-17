#ifndef _BIGNUMFUNCTIONS_HPP
#define _BIGNUMFUNCTIONS_HPP

#include"BigNum.hpp"

BigNum sqrt(BigNum o); //define sqrt operation

BigNum pow(BigNum o, ll n); //define pow operation for BigNum^(longlong)

BigNum abs(BigNum o); //define the abs operation

pair<bool , string> takeOffBigNumFromString(string s , BigNum * bn); //take of the first BigNum from string ; return true and change the string IFF success; bn is the takenoff BigNum

#endif