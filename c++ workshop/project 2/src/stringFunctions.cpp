#include"head.hpp"
#include"BigNum.hpp"

ll readString(string s){  //turn string into Long Long Integer
	ll n= 0, b= 1;
	int len= s.length();
	int i= 0;
	char c= s[0];
	while(!isdigit(c) ){
		if(c== '-') b= -1;
		c= s[++i];
	}
	while(isdigit(c) ){
		n= n* 10;
		n+= c- 48;
		c= s[++i];
	}
	return n* b;
}

bool isPureNum(string s){ //return ture IFF all char of given string are digits
	int len= s.length();
	//boundary1 length= 0;
	if(len== 0){
		return false;
	}
	//boundary2 all is digit
	int flag= true;
	For(i, 0, len- 1){
		flag&= isdigit(s[i]);
	}
	if(flag){
		return true;
	}else{
		return false;
	}
}

bool isNum(string s){ //return true IFF string is in '-123' or '-1.23'-like format
	if(s[0]== '-'){  //omit the '-' in 0 index;
		s= s.substr(1, s.length()- 1);
	}
	
	int len= s.length();
	For(i, 0, len- 1){  //if there is one '.', then ture IFF two parts are purenum(all is digit)
		if(s[i]== '.'){
			return isPureNum(s.substr(0, i) )&& isPureNum(s.substr(i+ 1, len- i) );
		}
	}
	
	//no '.', then ture IFF this is purenum(all is digit)
	return isPureNum(s);
}

bool isIntNum(string s){//return true IFF string is in '-123'-like Integer format
	if(s[0]== '-'){  //omit the '-' in 0 index;
		s= s.substr(1, s.length()- 1);
	}
	return isPureNum(s);
}

bool isvalid(string s){  //check if s is valid BigNumInput string
	int len= s.length();
	if(len == 0){  //like ""
		return false;
	}
	int eNum= 0;
	int ePos= -1;
	For(i, 0, len- 1){
		if(s[i]== 'e'){     //if number of 'e' >0 return false;
			eNum++;
			ePos= i;
			if(eNum> 1){
				return false;
			}
		}
	}
	
	if(eNum== 0){  //if no 'e' return if s is num, if not return if two parts are nums
		return isNum(s);
	}else{
		return isNum(s.substr(0, ePos) )&& isIntNum(s.substr(ePos+ 1, len- ePos- 1) );
	}
}

string removePreSufSpace(string s){  //return the s' which remove the previous and suffix space from s ; like "  A  " into "A"
    int len = s.length();
    if(len == 0){
        return "";
    }
    int l = 0 , r = len - 1;
    while(s.at(l) == ' '){
    	if(l >= len - 1){
    		break;
		}
        l++;
    }
    while(s.at(r) == ' '){
    	if(r <= 0){
    		break;
		}
        r--;
    }
    if(r < l){
        return "";
    }
    return s.substr(l , r - l + 1);
}

bool isValidVariable(string s){ //return true IIF string is in proper variable form like "ead123" or "_ears123" instead of "123es"
	int len = s.length();
	For(i, 0, len - 1){
		char c = s.at(i);
		if(i == 0){
			if(c == '_' || ('a'<= c && c<= 'z') || ('A'<= c && c<= 'Z')){
				continue;
			}else{
				return false;
			}
		}else{
			if(c == '_' || ('a'<= c && c<= 'z') || ('A'<= c && c<= 'Z') || ('0'<= c && c<= '9')){
				continue;
			}else{
				return false;
			}
		}
	}
	return true;
}
