#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
#define ri register int
#define For(i, a, b) for(ri i= a;i<= b;i++)
#define Ford(i, a, b) for(ri i= a;i>= b;i--)

const int N= 1e5;

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

struct BigNum{    //a struct to store big num
	int size;     //size of a[N]
	bool pos;    //if the value is positive
	int a[N];    //store value bit by bit like 0 1 2 3 equal to 3210
	ll e;
	
	BigNum operator* (const BigNum o){  //define * operation
		BigNum ans;
		ans.size= size+ o.size;
		ans.pos= !(pos^ o.pos);
		ans.e= e+ o.e;
		For(i, 0, ans.size- 1){
			ans.a[i]= 0;
		}
		For(i, 0, size- 1){
			For(j, 0, o.size- 1){
				ans.a[i+ j]+= a[i]* o.a[j];
			}
		}
		For(i, 1, ans.size- 1){
			ans.a[i]+= ans.a[i- 1]/ 10;
			ans.a[i- 1]%= 10;
		}
		ans.optimize();
		return ans;
	}
	
	void optimize(){ //adjust size and a[n] to delete the pre and suf zeros
		while(a[size- 1]== 0){
			size--;
			if(size== 0){
				break;
			}
		}
		int num= 0;
		while(a[num]== 0&& num< size){
			num++;
		}
		For(i, num, size- 1){
			a[i- num]= a[i];
		}
		e+= num;
		size-= num;
		
		if(size== 0){   //avoid there is null in a[n]
			pos= 1;
			a[size++]= 0;
			e= 0;
		}
	}
	
	void read(string s){  //intialize BigNum with string s (input must be valid)
		//find the length of s
		int len= s.length();
		//find the 'e''s position
		int ePos= -1;
		int n= s.length();
		For(i, 0, n- 1){
			if(s[i]== 'e'){
				ePos= i;
			}
		}
		//find if it is positive or not
		pos= s[0]!= '-';
		//determine e from give string's suffix if having
		if(ePos== -1){
			e= 0;
		}else {
			e= readString(s.substr(ePos+ 1, len- ePos- 1) );
		}
		//dertermine size a[n], adjust e form string's prefix
		len= (ePos== -1)? len: ePos; //omit the exxx part
		size= 0;
		int dotPos= -1;
		For(i, 0, len- 1){
			if(s[i]== '-'){
				continue;
			}
			if(s[i]== '.'){
				dotPos= i;
				continue;
			}
			a[size++]= (s[i]- '0');
		}
		if(dotPos!= -1){//update e
			e-= len- 1- dotPos;
		}
		For(i, 1, size/ 2){ //reverse a[n]
			swap(a[i- 1], a[size- i]);
		}
		
		optimize();//delete pre and suf zero
	}
	
	void print(){ //print the value
		if(!pos){
			cout<< '-';
		}
		
		if(e>= 0&& e<= 5){           //like 123000
			Ford(i, size- 1, 0){
				cout<< a[i];
			}
			For(i, 1, e){
				cout<< 0;
			}
		}else{
			if(-e>= size&& -e<= size+ 5){ //like 0.0123
				cout<< "0.";
				For(i, 1, -e- size){
					cout<< 0;
				}
				Ford(i, size- 1, 0){
					cout<< a[i];
				}
			}else if(-e< size&& -e> 0){ //like 1.23
				Ford(i, size- 1, -e){
					cout<< a[i];
				}
				cout<< '.';
				Ford(i, -e- 1, 0){
					cout<< a[i];
				}
			}else{                     //like 123e123
				Ford(i, size- 1, 0){
					cout<< a[i];
				}
				cout<< 'e'<< e;
			}
		}
	}
};

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

bool isvalid(string s){  //check if s is valid
	int len= s.length();
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

int main(int argc, char* argv[]) 
{
		string s1, s2;
		if(argc< 3){
			cout<< "please input two string!"<< endl;
			return 0;
		}
		s1= argv[1];
		s2= argv[2];
		if(!isvalid(s1)|| !isvalid(s2) ){  //determine if it is valid num
			cout<< "The input cannot be interpret as numbers!"<< endl;
			return 0;
		}
		BigNum bn1, bn2, bn3;
		bn1.read(s1);
		bn2.read(s2);
		bn3= bn1* bn2;
		cout<< s1;
		cout<< " * ";
		cout<< s2;
		cout<< " = ";
		bn3.print();
		cout<< endl;

    return 0;
}

/*

./mul 2 3
./mul 232 -231
./mul 0 -123

./mul 3.1416 2
./mul 3.1415 2.0e-2
./mul 2e123211 3.123e-123211
./mul 0002e0000000 00.03e123

./mul a 2
./mul 12e 2
./mul -11-2e-1 2
./mul -1.e1 2
./mul 1.-1e1 2
./mul 1.1.1e1 2
./mul 1e1.1 2

./mul 1234567890 1234567890
./mul 12300000000000 234000000000000000

./mul 1.0e200 1.0e200
./mul 2e123211 3.123e-123211
./mul 0002e0000000 00.03e123

*/
