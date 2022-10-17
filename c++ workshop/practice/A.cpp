#include<iostream>
#include<string>
#include<map>
using namespace std;
typedef long long ll;
#define ri register int
#define For(i, a, b) for(ri i= a;i<= b;i++)
#define Ford(i, a, b) for(ri i= a;i>= b;i--)
#define N 100000      //maximum size of BigNum a[N]
#define DivisionPrecision -4  //the precison of '/' operation
#define SqrtPrecision -4  //the precison of sqrt operation
#define ApproximationPrecision -1 //approximationPrecision
using namespace std;

typedef int myint;

typedef unsigned char vec3b[3];

typedef struct _rgb_struct{//name _rgb_struct can be omit
    unsigned char r;
    unsigned char g;
    unsigned char b;
} rgb_struct;

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

int main(){
	string s = "ABC";
	cout<< "!!" << s.substr(3, 2)<< "!!" << endl;
}


