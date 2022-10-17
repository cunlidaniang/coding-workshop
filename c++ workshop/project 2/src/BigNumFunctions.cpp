#include"BigNum.hpp"

BigNum sqrt(BigNum o){ //define sqrt operation
		o.sqrt();
		return o;
	}

BigNum pow(BigNum o, ll n){ //define pow operation for BigNum^(longlong)
	BigNum ans;
	ans.read("0");
	if(o == ans){     //if o == 0 WARNING!
		if(n == 0){
			printf("Warning!! 0^0!!");
		}
		return ans;
	}

	ans.read("1");

	while(n != 0){   //quick pow method
		if(n | 1 == 1){
			ans = ans * o;
		}
		n >>= 1;
		o = o * o;
	}

	return ans;
}

pair<bool , string> takeOffBigNumFromString(string s , BigNum * bn){ //take off the first BigNum from string ; return true and change the string IFF success; bn is the takenoff BigNum
	s = removePreSufSpace(s);
	int len = s.length();
	int pos = len;
	For(i, 0, len - 1){
		char ch = s.at(i);
		if(ch == '-' && i == 0){
			continue;
		}
		if(ch == '-' && i > 0 && s.at(i - 1) == 'e' ){
			continue;
		}
		if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == ','){
			pos = i;
			break;
		}
	}
	
	string bigNumString = s.substr(0, pos - 0);
	bigNumString = removePreSufSpace(bigNumString);

	pair<bool , string> ans;

	if(!isvalid(bigNumString) ){    //if bigNumString not valid
		ans.first = false;
		ans.second = s;
		return ans;
	}

	ans.first = true;
	ans.second = s.substr(pos, len- pos);
	*bn = BigNum(bigNumString);
	return ans;
}

BigNum abs(BigNum o){ //define the abs operation
	o.pos = true;
	return o;
}